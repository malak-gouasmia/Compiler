
%{  
    //*************************Partie 1 : declarations pour le compilateur C
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "syntaxe.tab.h" // biliotèque contient token et d'autre decalaration de bison et etre utlise par flex
#include "shared.h"
#include "SymboleTable.h"



//--------------------------pour tables de symboles

void Afficher(SymboleTable *symboleTable);

NodeSymbole *insertSymbole(SymboleTable *symboleTable,char *tokenId);
NodeSymbole *searchByName(SymboleTable *symboleTable, char* name);
NodeSymbole *insertSymbole(SymboleTable *symboleTable, char *tokenId);
SymboleTable *allocateSymboleTable();

char sonType [20];
FILE *fp ;
char t[50];

SymboleTable *ts;



//---------------concerne les routines
struct sauve{
    char* nom;
    int valeur;
};

struct sauve tab_sauv[50];
char* Quadreplets[50][4];

int indice_courant = 0;
int QC = 0;
char c[10];
//methode pour manipuler vecetur des sauvs
void stocke( char* nom, int valeur);
int restaure(  char* nom );

//methode de manipulation de matrcie des Quadreplets
void initQ( );
int insertQ( char* tab[4]);
void afficheQ();
void afficheV();
//------------------------Fin routines







//-----------------variable utlise pour la verfication
char ID_for[200] = "";

// variables partages par flex et bison: lignenum, nb_cara


// variable globale pour vefier etat et emplacement en cas d'err
char* emplacement ;
int err = 0;



// les entetes des methodes à utliser
int yylex();

int yyerror(char* msg);



%}

//**************************Partie 2 : Appel "difinitions Regulières" c'est declarations pour bison, typages des symboles

// structure a utlise 
%union{
    int entier;
    float flt;
    char* str;
    char c;
}

// les tokens 
%type <str>type 
%type <str>decalaration_para
%token <str> NOMPROGR  TYPE_CONS TYPE_INT TYPE_FLT TYPE_CAR TYPE_STR TYPE_BLN   STRUCT      //mot cle de declaration des type variables et constantes
%token <str> DEB_CORPS FIN_CORPS      PAR_OUV PAR_FERM         SEPARATEUR      FIN_INSTRUCTION     DEB_TABLEAU FIN_TABLEAU   ACCES_STRUCT//seprateurs  ou delimteurs
%token <str> MAIN PROCEDURE  AFFECTATION FIN_PROG      //mot cle globale de programmes
%token <str> READ  WRITE RETURN         //fonctions et procedures
%token <str> IF ELSE ELSEIF  REPEAT ITERATOR  CASE CASE_NUM FIN_CASE  DEFAULT   // mot cle des structure conditionel et repetitives
%token <str> PLUS MOINS DIV MUL MOD  INF_EGAL INF SUPP SUPP_EGAL EGALE PASEGALE NEGATION ET OU  //operateurs

%token <entier> ENTIER <c> CARACTERE <flt> FLOTTANT <str> CHAINE <str> ID       // type des valeurs
%token <str> BOOLEAN_FAUX BOOLEAN_VRAI   



// ------------------------------Regles d'assoctativite et priorite
%left OU ET //logique
%left INF_EGAL INF SUPP SUPP_EGAL EGALE PASEGALE //comparaison
%left PLUS MOINS //arithmetique
%left  DIV MUL MOD
%nonassoc NEGATION
%right PAR_OUV PAR_FERM
%right DEB_CORPS FIN_CORPS

%start programme //notre axiome 



//******************************************Partie 3 : Règles syntaxique 
%%

// extendre tokens à des non terminaux pour traiter cas d'err
debut_acolade: error   { printf("Acolade debut manquante\n"); err++; return -1;   }
            | DEB_CORPS
            ;
fin_acolade : error  { printf("Acolade Fin manquante\n");  err++; return -1;  }
            | FIN_CORPS
            ;

debut_paren:  error  { printf("Parenthese Ouvrante manquante\n"); err++; return -1; }
            | PAR_OUV
            ;
fin_paren :  error  { printf("Parenthese Fermante manquante\n");  err++; return -1; }
            | PAR_FERM
            ;   

fin_inst:   error { printf("Symbole Fin d'intruction manquant\n");  err++; return -1; }
            | FIN_INSTRUCTION
            ;
separ :   error { printf("Symbole de separateur des parametres manaquant\n");  err++; return -1; }
            | SEPARATEUR
            ; 

debut_tab : 
            DEB_TABLEAU 
            ;
fin_tab :    error  { printf("pas de ]\n"); err++; return -1;}
            |FIN_TABLEAU  
            ;
faut_id : ID
                | error  { printf("faut declarer un ID \n"); err++; return -1;}
                ;
faut_nomprog : NOMPROGR
                | error  { printf("faut redifinie nom de programme \n"); err++; return -1;}
                ;
//--------------------Type englobe
type:       TYPE_INT {$$=$1;}
            | TYPE_FLT {$$=$1;}
            | TYPE_BLN {$$=$1;}
            | TYPE_CAR {$$=$1;}
            | TYPE_STR {$$=$1;}
            ;

//*********************** structure generale de notre languages
programme: faut_nomprog fin_inst def_structs Fn_Pro prog_principale FIN_PROG 
                            {  printf("Le programme est syntaxiquement correct\n");  YYACCEPT; } ;

//------------------Structure
def_structs :      /* epsilon */
            |def_struct def_structs 
            ;

//----------------------- les Definition des nouveau structures
def_struct:   
            STRUCT faut_id debut_acolade struct_corp fin_acolade  
            { }
            ;
        
        struct_corp:  plus_declarations  
                    |       { printf("Warning, corp vide lors definition structure\n");  }
                    ;  
                    
        plus_declarations:  decalaration 
                    |decalaration plus_declarations 
                    ;

//------------------------ Les fonctions & procedures
Fn_Pro :   
        | Fn Fn_Pro
        | PR Fn_Pro
        ;

//------------------------ Les Fonctions
        Fn : type ID  debut_paren Params fin_paren  corp_fnc {
            NodeSymbole *x;
            x=search(ts, $2);
            
            if(x == NULL)
            {      
                    x = insertSymbole(ts,$2);
                    setAttribut(x, "Etat", "FCT");
                    setAttribut(x, "Type", $1);
                    printf("Definition de fonction est correcte\n"); 
                    Afficher(ts);
            }

            else  
                { 
                        printf("erreur Semantique: double declaration de la fonction %s,  a la ligne %d, le caractere %d\n", $2, lignenum, nb_cara); }
                }
                ;


//------------------------ Les procedures
        PR : PROCEDURE ID debut_paren Params fin_paren  corp { 

        NodeSymbole *x;
        x=search(ts, $2);
        
        if(x == NULL)
		{      
            x = insertSymbole(ts,$2);
            setAttribut(x, "Etat", "PROC");
            printf("Definition de procedure est correcte\n");
            Afficher(ts);
		}

        else  printf("erreur Semantique: double declaration de la procedure %s,  a la ligne %d, le caractere %d\n", $2, lignenum, nb_cara); 
                } 
                ; 
        

//------------------------- Paramètres d'entres             
        Params:    /* vide */   
                    |plus_Params
                    ; 

        plus_Params: 
                    decalaration_para 
                    |decalaration_para separ plus_Params 
                    ;   

        decalaration_para : type ID  { }
                    | TYPE_CONS type ID {}  
                    | type debut_tab ENTIER fin_tab ID  {}
                    | TYPE_CONS type debut_tab ENTIER fin_tab ID   { }
                    ;
                    
//--------------------------Programme principale
prog_principale :   
                    | MAIN debut_paren fin_paren  corp  { printf("Definition de Main(programme principale) est correcte\n");  }
                    ;

        corp        : debut_acolade  corp_main fin_acolade { printf("Definition de corp est correcte\n");  }
                    ;

        
        corp_main :    
                    |au_moin_inst 
                    ; 

        corp_fnc    : debut_acolade  corp_main retour fin_acolade
                    ;

        retour      :  error { printf("Return attendue\n"); return -1; }
                    | RETURN valeur fin_inst
                    ;

        au_moin_inst: decalaration 
                    | affec 
                    | if_struct 
                    | case_struct 
                    | while_struct
                    | for_struct

                    | read_Proc
                    | write_Proc
                    | Appel_Methode     

                    | decalaration    au_moin_inst  
                    | affec    au_moin_inst  
                    | if_struct    au_moin_inst  
                    | case_struct    au_moin_inst  
                    | while_struct    au_moin_inst 
                    | for_struct    au_moin_inst 

                    | read_Proc     au_moin_inst
                    | write_Proc    au_moin_inst
                    | Appel_Methode     au_moin_inst
                    ;

        // if struct
        if_struct : IF condition
                {               QC++;
                        fprintf(fp, "***Les routines semantiques pour l'instruction Si-Sinon***\n");
                        fprintf(fp, "Si - R1: Verifie_Condition\n");
                        fprintf(fp, "QUAD (Qc) := (BZ,sauv-debut-else , <condition>, ) \n"); // on stock qudreplet
                                char* tab[4] = {"BZ", "", "<condition>",""}; 
                                insertQ( tab );
                        fprintf(fp, "sauv-debut-else := Qc \n"); // besion de debut else
                                stocke( "sauv-debut-else", QC);
                                fprintf(fp, "Qc := Qc+1 \n");
                                QC++;
                }
        
        
        corp {
                        fprintf(fp, "Si - R2: bloc d'intruction de IF\n");
                        fprintf(fp, "QUAD (Qc) := (BR,sauv-fin-si , , ) \n"); //on stock 
                                char* tab2[4] = {"BR", "", "",""}; 
                                insertQ( tab2 );
                        fprintf(fp, "sauv-fin-si := Qc \n"); // besion de fin-si
                                stocke( "sauv-fin-si", QC);
                        fprintf(fp, "Qc := Qc + 1 \n");
                                QC++;
                                fprintf(fp, "QUAD (sauv-debut-else, 2) := Qc (position courant debut else) \n"); // met à jour poieur vers debut else
                                
                                sprintf(c, "%d", QC);
                                char inter[100] = "sauv-debut-else:"; 
                                strcat( inter,strdup(c) );
                                Quadreplets[restaure("sauv-debut-else")][1] = strdup(inter);
                }
                suite;

        suite : { 
                            // recuper adress fin else pour la mettre en cas de if
                printf("Definition de Conditionnle IF est correcte\n");
                        fprintf(fp,  "FSI - R3: Fin IF\n");
                        fprintf(fp,  "QUAD (sauv-fin-si, 2) := Qc \n"); //on met a jour pointeur fin

                        sprintf(c, "%d", QC);
                        char inter2[100] = "sauv-fin-si:"; 
                        strcat( inter2,strdup(c) );
                        Quadreplets[restaure("sauv-fin-si")][1] = strdup(inter2);
                        fprintf(fp,  "******\n\n");
                        QC++;
                }   
                |ELSE corp { 
                        
                        QC++;
                        fprintf(fp, "Definition de ELSE est correcte\n");
                        
                        fprintf(fp,  "FSI - R3: : Fin IF apres ELSE\n");
                        fprintf(fp,  "QUAD (sauv-fin-si, 2) := Qc \n"); //on met a jour pointeur fin
                        
                        sprintf(c, "%d", QC);
                        char inter3[100] = "sauv-fin-si:"; 
                        strcat( inter3,strdup(c) );
                        Quadreplets[restaure("sauv-fin-si")][1] = strdup(inter3);
                        fprintf(fp,  "******\n\n"); 
                        QC++; }
                | ELSEIF condition corp  { printf("Definition de ELSEIF est correcte\n");  }
                ;

        //case struct
        case_struct: CASE debut_paren valeur fin_paren debut_acolade corp_case fin_acolade  { printf("Definition de Switch est correcte\n");  }
                    ;
        corp_case:  
                |   plus_case
                ;
        plus_case: une_case    
                | une_case  plus_case
                | default
                ;
        une_case: constant CASE_NUM corp_main FIN_CASE fin_inst
                ; 

        default: DEFAULT CASE_NUM corp_main FIN_CASE fin_inst
                ;

        //while struct
        while_struct: REPEAT condition  corp { printf("Definition de boucle repeat est correcte\n");  }
                    ; 

        //for struct
        for_struct: ITERATOR debut_paren init_index separ 
        {              
                        fprintf(fp, "Debut condition FOR - R1\n");
                        fprintf(fp, "debut-cnd-for := Qc \n"); //stocke debut-cnd
                        //stocke("debut-cnd-for", QC);
                        fprintf(fp, "******\n\n");
                        //QC++;
        }
        
        
        
        Condition_For 
        {
                        fprintf(fp, "***Les routines semantiques pour l'instruction For***\n");
                        fprintf(fp, "For - R1: Verifie_Condition et branchement debut block\n");
                        fprintf(fp, "QUAD (Qc) := (BZ, fin-for ,<condition> , ) \n"); // on stocke le quadreplet:
                                /* char* tab3[4] = {"BZ", "fin-for", "<condition>",""}; 
                                insertQ( tab3 );*/
                        fprintf(fp, "sauv-fin-for := Qc \n"); // stock position pour le metrre à jour
                                //stocke("sauv-fin-for", QC);

                        fprintf(fp, "Qc := Qc+1 \n"); 
                                //QC++;
                        fprintf(fp, "QUAD (Qc) :=(BR, debut-block-for, , ) \n"); // on branche vers block, on stock quarplet
                                /*char* tab4[4] = {"BR", "debut-block-for", "",""}; 
                                insertQ( tab4 ); */
                        fprintf(fp, "sauv-debut-blok-for := Qc \n");
                                //stocke("sauv-debut-blok-for", QC);
                        fprintf(fp, "Qc := Qc+1 \n"); 
                                //QC++;
                        } 
        
            separ{
                        fprintf(fp,"FOR-R2: Stocker debut d'incrementation\n");
                        fprintf(fp,"debut-inc := Qc \n"); // on stock debut_inc
                        //stocke("debut-inc", QC);
                }
            incrementation
            {               //QC++;
                        fprintf(fp, "FOR-R3: apres incremnetation Routine branchement vers condition\n");
                        fprintf(fp, "QUAD (Qc) := (BR, debut-cnd-for , , )\n"); // on stock quadreplet

                                /*int i1 = restaure("debut-cnd-for");
                                sprintf(c, "%d", i1);

                                char* tab5[4] = {"BR", c, "",""}; 
                                insertQ( tab5 ); */
                        fprintf(fp, "Qc := Qc+1 \n"); 
                        //QC++;
        }
        
        fin_paren 
        {      
                        fprintf(fp,"QUAD(sauv-debut-blok-for, 2) := Qc\n");  // on met à jour ce qui il pointe vers debut block
                                /*sprintf(c, "%d", QC);
                                char inter4[100] = "sauv-debut-blok-for:"; 
                                strcat( inter4,strdup(c) );
                                Quadreplets[restaure("sauv-debut-blok-for")][1] = strdup(inter4);
                                QC++; */
        } 
        corp 
        { printf("Definition de iterator est correcte\n"); 

                        fprintf(fp, "FOR-R4: de block vers branchent incrementation\n");
                        fprintf(fp, "QUAD (Qc) := (BR, debut-inc , , ) \n"); // on retoure et stock quadreplet
                                /*int i2 = restaure("debut-inc");
                                sprintf(c, "%d", i2);

                                char* tab6[4] = {"BR", c, "",""}; 
                                insertQ( tab6 );*/
                        fprintf(fp, "Qc := Qc+1 \n"); 
                                //QC++;
                        fprintf(fp, "QUAD (sauv-fin-for, 2) := Qc \n"); // on met à jour ce qui pointe vers la fin

                                /*char inter5[100] = "sauv-fin-for:"; 
                                strcat( inter5,strdup(c) );
                                Quadreplets[restaure("sauv-fin-for")][1] = strdup(inter5); */
                        } 
                ; 

        init_index :   error { printf("Err, d'intilisation de boucle\n"); err++; return -1; }
                | ID AFFECTATION valeur 
                {
                    NodeSymbole *x;
                    x=search(ts, $1);
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");

                            if( strcmp(etat, "CONS") == 0 )  
                            {
                                printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                            if( strcmp(etat, "FCT") == 0 )  
                            {
                                printf("erreur Semantique: %s ne doit pas etre une fonction,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                            if( strcmp(etat, "PROC") == 0 )  
                            {
                                printf("erreur Semantique: %s ne doit pas etre une procedure,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 
                            if( strcmp(etat, "VAR") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                strcpy(ID_for, $1); // on la recupere pour la verfication apres 
                                            }
                            } 
                        
                    }
                }

                | ID DEB_TABLEAU ENTIER FIN_TABLEAU AFFECTATION valeur 
                ; 

            incrementation : error { printf("Err, manque d'incrementation dans boucle iterator\n");  err++; return -1; }
                        | expression 
                        ;

            Condition_For : error { printf("Err, manque de condition de boucle iterator\n");  err++; return -1; }
                            | ID SUPP expression
                                {
                                    if(strcmp($1, ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);  }
                                }
                            | ID SUPP_EGAL expression
                                {
                                    if(strcmp($1, ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);  }
                                }

                            | ID INF expression
                                {
                                    if(strcmp($1, ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);  }
                                }

                            | ID INF_EGAL expression
                                {
                                    if(strcmp($1, ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);  }
                                }

                            ;

//--------------- Appel fonction et procedure
        //--Appel procedure & fonction
        Appel_Methode: ID debut_paren valeur_param fin_paren fin_inst { 
                
        NodeSymbole *x;
        x=search(ts, $1);
        if(x == NULL) 
        {
            printf("erreur Semantique: %s methode non declare, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara); 
        }
        else
        {
            char *etat= getAttribut(x,"Etat");
                        if( (strcmp(etat, "FCT") != 0 ) && (strcmp(etat, "PROC") != 0 ) )
                        {
                            printf("erreur Semantique: %s doit etre nom d'une methode (fonction ou procedure), a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara); 
                        }
                        else
                        {
                            printf("Appel methode effectuer\n");  
                        }
        }
        }
        ;

        //-- Appel procedure predefinie: read , write
        write_Proc : WRITE debut_paren valeur_param fin_paren fin_inst { printf("Appel Write effectuer\n");  }
                    ;

        read_Proc : READ debut_paren parametre_read fin_paren fin_inst { printf("Appel read effectuer\n");  }
                    ;

        valeur_param : 
                    | plus_valeur
                    ;
        plus_valeur : valeur
                    | valeur separ plus_valeur
                    ;

        parametre_read : ID 
        {
            NodeSymbole *x;
            x=search(ts, $1);
            if(x == NULL) {printf("erreur Semantique: %s non declare, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);} 
            else
            {
                char *etat= getAttribut(x,"Etat");
                if(strcmp(etat, "VAR") == 0 )
                {
                    char *type= getAttribut(x,"Type");
                    if( strcmp(type, "t_str") != 0 )
                    { 
                        printf("erreur: %s ce variable qui va stocker valeur de read doit etre de type chaine de caractere, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);
                    }
                }
                else
                {
                        printf("erreur semantique : %s ce variable doit etre des case memoires pour stocker valeur lue, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);
                }
            
            }

        }
        
        | ID debut_tab ENTIER fin_tab  
        {
            NodeSymbole *x;
            x=search(ts, $1);
            if(x == NULL) {printf("erreur Semantique: %s non declare, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);} 
            else
            {
                char *etat= getAttribut(x,"Etat");
                if(strcmp(etat, "TAB") == 0 )
                {
                    char *type= getAttribut(x,"Type");
                    if( strcmp(type, "t_str") != 0 )
                    { 
                        printf("erreur: %s ce variable qui va stocker valeur de read doit etre de type chaine de caractere, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);
                    }
                }
                else
                {
                        printf("erreur semantique : %s ce variable doit etre des case memoires pour stocker valeur lue, a la ligne %d, a la colonne %d\n", $1,  lignenum, nb_cara);
                }
            
            }

        }
        ;

//-------------------instruction qui peut change tableau de symbole c'est à dire changer valeur  : valeur expresion et condition

decalaration: type ID fin_inst 
{ 
          NodeSymbole *x;
           x=search(ts, $2);
        
           if(x == NULL)
                {      
                    x=  insertSymbole(ts,$2);
                    setAttribut(x, "Type", strdup($1) );
                    setAttribut(x, "Etat", "VAR");
                    printf("Declaration de variable est juste\n"); 
                    Afficher(ts);
                }
	        else  
            { 
                printf("erreur Semantique: double declaration d'un id  %s,  a la ligne %d, le caractere %d\n", $2, lignenum, nb_cara);
            }
}

            | type debut_tab ENTIER fin_tab ID fin_inst  
                { 
                 NodeSymbole *x;
                    x=search(ts, $5);
                    
                    if(x == NULL)
                    {      
                        x =  insertSymbole(ts,$5);
                            setAttribut(x, "Etat", "TAB");
                            setAttribut(x, "Type", $1);
                        Afficher(ts); 

                            char size[50];
                            sprintf(size, "%d", $3);
                            setAttribut(x, "Size",size );
                            printf("Declaration de tableau est juste\n"); 
                            Afficher(ts); 
                    }

                    else  
                    { printf("erreur Semantique: double declaration d'un tableau  %s,  a la ligne %d, le caractere %d\n", $5, lignenum, nb_cara);}
                
                }

            | TYPE_CONS type ID fin_inst
                { 
                    NodeSymbole *x;
                    x=search(ts, $3);
                    if(x == NULL)
                    {      
                        x =  insertSymbole(ts,$3);
                            strcpy(t,"TAB");
                            setAttribut(x, "Type", $2);
                            setAttribut(x, "Etat", "CONS");
                            printf("Declaration de constante est juste\n");  
                                    Afficher(ts);

                    }

                    else  
                    { printf("erreur Semantique: double declaration d'un tableau  %s,  a la ligne %d, le caractere %d\n", $3, lignenum, nb_cara);}
                
                }
                ;

affec : ID AFFECTATION valeur fin_inst 
{ 
                    NodeSymbole *x;
                    x=search(ts, $1);
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");

                        if( strcmp(etat, "CONS") == 0 )  
                            {
                                printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }

                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 

                        if( strcmp(etat, "PROC") == 0 )  
                            {
                            printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }

                        if( strcmp(etat, "TAB") == 0 )  
                            {
                             printf("erreur Semantique: %s  est un nom de tableau faut sepecfie indice à acceder tu peut pas affcter valeur au tableau complet,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                printf("Affecation d'un variable  est juste\n"); 
                                                        Afficher(ts);

                                            }
                            } 
                }
}

            | ID DEB_TABLEAU ENTIER  FIN_TABLEAU AFFECTATION valeur fin_inst 
            { 
                    NodeSymbole *x;
                    x=search(ts, $1);
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                        if( strcmp(etat, "CONS") == 0 )  
                            {
                            printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                                printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                                     char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //acess a size
                                                int taille;
                                                taille = atoi(getAttribut(x,"Size"));
                                                printf(" taile == %d et val 3 = %d", taille, $3);
                                                if( (0<= $3) &&($3 < taille) )
                                                {printf("Affecation d'un tableau juste\n"); }
                                                else
                                                {
                                                    printf("erreur Semantique: t'essaye d'acces a indice hors taille de tableau %s,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                                }
                                            }
                            } 

                        
                    }
            }

            ; 



valeur:       CHAINE {      strcpy(sonType , "t_str");  }
            | CARACTERE  { strcpy(sonType , "t_car"); }
            | BOOLEAN_FAUX  {strcpy(sonType , "t_bln");}
            | BOOLEAN_VRAI  {strcpy(sonType , "t_bln");}

            | expression
            | ID DEB_TABLEAU ENTIER FIN_TABLEAU 
            //| Appel_Methode 
            // les appel des fonctions et ID et ID [tableau] car depand de type 
            ;

constant : CHAINE 
        | CARACTERE
        | ENTIER
        | ID // faut constant
        | ID debut_tab ENTIER fin_tab
        | BOOLEAN_FAUX
        | BOOLEAN_VRAI
        ;
            /*| ID DEB_TABLEAU indice_tab FIN_TABLEAU ;  //valeur tableau en string , on fait trancation indice car peut etre int ou float */


//----------------------------------Recursion d'evaluation
condition:   error  { printf("Err, condition est vide\n"); err++; return -1;} 
            | debut_paren comparaison fin_paren 
            | debut_paren NEGATION condition  fin_paren     
            | debut_paren condition  ET condition fin_paren  
            | debut_paren condition  OU condition fin_paren 
            | ID // de type boolen 
            ; 

comparaison :  
            expression EGALE  expression    
            | expression PASEGALE  expression   
            | expression SUPP  expression   
            | expression SUPP_EGAL  expression   
            | expression INF  expression    
            | expression INF_EGAL  expression  
            ;

expression:    error { printf("Err, expression est vide\n"); err++; return -1; } 
            | debut_paren expression fin_paren
            | terme  
            | terme PLUS expression  
            | terme MOINS expression  
            | terme MUL expression
            | terme DIV expression 
            | terme MOD expression 
            ; 

terme:       ID 
                { 
                    NodeSymbole *x;
                    x=search(ts, $1);
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: le variable %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                         if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est une fonction donc vous devez effecter un appel,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est une procedure donc vous devez effecter un appel,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                             printf("erreur Semantique: %s  est un nom de tableau faut sepecfie indice à acceder,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        
                        if( (strcmp(etat, "CONS") == 0 )|| (  strcmp(etat, "VAR") == 0  ) )
                        {
                              char *type= getAttribut(x,"Type");
                                            if( (strcmp(type,"t_int")!=0) && (strcmp(type,"t_flt")!=0) )
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //printf("acces a un variable  est juste\n"); 
                                            }
                        }
                    }
                }

        | ENTIER {strcpy(sonType , "t_int"); }
        | FLOTTANT {strcpy(sonType , "t_flt");}

        | ID debut_tab ENTIER fin_tab  
                {
                    { 
                    NodeSymbole *x;
                    x=search(ts, $1);
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: le tableau %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                            printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //acess a size
                                                int taille;
                                                taille = atoi(getAttribut(x,"Size"));
                                                if( 0<= $3 < taille )
                                                {printf("Affecation d'un tableau juste\n"); }
                                                else
                                                {
                                                    printf("erreur Semantique: t'essaye d'acces à indice hors taille de tableau %s,  a la ligne %d, le caractere %d\n", $1, lignenum, nb_cara);
                                                }
                                            }
                            }

                        

                        
                    }
                }
            }

            | Appel_Methode 
            
            // le plus et moins unitaire
            | PLUS ENTIER 
            | MOINS ENTIER 
            | PLUS FLOTTANT 
            | MOINS FLOTTANT 
            ;

%%

//*************Partie 4 : Fonction C et programme de lancement et definition de quesmuqe fonctions

// implemntation des fonction utlises
int yywrap()
{
    return 1 ;
}
int yyerror(char* msg)

{ 
        printf("Dans ce Fichier, Dans line %d, character %d: syntax error,  ",lignenum, nb_cara); 

}

// fonction principale
int main()
{ 
        ts=allocateSymboleTable();
        fp = fopen("Output.txt", "w");
        fseek(fp, 0, SEEK_SET);
        yyparse(); 
        afficheQ();
        afficheV();
        Afficher(ts);
}


//-----------------implementaion des methodes
void initQ( )
{ int i, j;
    for ( i = 0; i < 50; i++) 
    {
       for ( j = 0; j < 4; j++) 
       {
           Quadreplets[i][j] = strdup("");
       }
    }
}

void afficheV()
{
 printf("\nLe vecteurs des sauvs: \n");
    for (int i = 0; i < indice_courant; i++) 
    {       printf("sauv[ %d ]: ", i);
            printf("%s = %d, ", tab_sauv[i].nom,tab_sauv[i].valeur );
        
    }   
}

int insertQ( char* tab[4])
{
    for (int i = 0; i < 4; i++) 
    { 
        Quadreplets[QC][i] =  strdup (tab[i]) ;
    }
    return (QC );
}

void stocke( char* nom, int valeur)
{
    struct sauve a = { strdup(nom), valeur };
    tab_sauv[indice_courant] = a;
    indice_courant++;
}

int restaure(  char* nom )
{  
    int i;
    for (i = 0; i <= indice_courant; i++) {
       if(strcmp(tab_sauv[i].nom, nom) == 0){  return (tab_sauv[i].valeur); }
    }
    return (-1);
} 

void afficheQ()
{
 printf("\nLes quadreplets: \n");
    for (int i = 0; i < QC; i++) 
    {       printf("Quadreplet[ %d ]: ", i);
            for (int j = 0; j < 4; j++) 
            {
                printf("%s, ", Quadreplets[i][j]);
            }
            printf("\n");
        
    }   
}



