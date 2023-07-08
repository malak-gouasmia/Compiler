%{ 
// partie declaratin des variables, fonction et procedure, et les bibliotèques

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "syntaxe.tab.h" 

#include "SymboleTable.c"
#include "SymboleTable.h"

#include "shared.h"

extern YYSTYPE yylval;

int lignenum = 1;

int nb_cara = 0;

char* Nom_prog ;


%}
/* partie decalaration FLEX  
A revoir declaration d'un caractère  */

chiffre     [0-9] 

lettre      [a-zA-Z]

quq         [a-ZA-Z0-9]

t_car         [']{lettre}[']

ID          [a-zA-Z_][a-zA-Z0-9_]* 

t_int         {chiffre}+

t_flt        {t_int}+"."+{t_int} 

t_cons        {t_flt}|{t_int}

blancs      [ \t]+

t_str         \"(\\.|[^"\\])*\"

type        [“t_int”|”t_flt”|”t_str”|”t_bln”]

Nomprogramme   @.{ID}


%x   COMM   

%%


"#/"    { BEGIN  COMM;  }
<COMM>.        ; 
<COMM>\n    ;  
<COMM>"/#" { BEGIN  INITIAL; }  /* jusqua arriver fin commentaire */


{t_car}        {     nb_cara = nb_cara +yyleng ; yylval.str = strdup(yytext);  return CARACTERE ;  }

{t_str}         {    nb_cara = nb_cara +yyleng  ; yylval.str = strdup(yytext); return CHAINE; }

{t_int}        {    nb_cara = nb_cara +yyleng  ; yylval.entier = atoi(yytext); return ENTIER; }


{t_flt}       {    nb_cara = nb_cara +yyleng  ; yylval.flt = atof(yytext); return FLOTTANT;  } 

{Nomprogramme}    {  nb_cara = nb_cara +yyleng ;   return NOMPROGR;  } 

"vrai"      {     nb_cara = nb_cara +yyleng ;   return BOOLEAN_VRAI;  } 

"faux"      {     nb_cara = nb_cara +yyleng ;   return BOOLEAN_FAUX;  } 

"main"      {     nb_cara = nb_cara +yyleng ;   return MAIN;  }  

"proc"       {     nb_cara = nb_cara +yyleng ;  return PROCEDURE;   } 


"t_cons"     {     nb_cara = nb_cara +yyleng ;  return TYPE_CONS;   } 

"t_int"       {     nb_cara = nb_cara +yyleng ; yylval.str = strdup(yytext); return TYPE_INT;   } 

"t_flt"      {     nb_cara = nb_cara +yyleng ;  yylval.str = strdup(yytext);  return TYPE_FLT;  } 

"t_car"       {     nb_cara = nb_cara +yyleng ;  yylval.str = strdup(yytext); return TYPE_CAR;   } 

"t_str"        {     nb_cara = nb_cara +yyleng ; yylval.str = strdup(yytext); return TYPE_STR;    } 

"t_bln"        {     nb_cara = nb_cara +yyleng ; yylval.str = strdup(yytext); return TYPE_BLN;    }


"return"    {     nb_cara = nb_cara +yyleng ;  return RETURN;   } 

"read"      {     nb_cara = nb_cara +yyleng ;  return READ;   } 

"write"    {     nb_cara = nb_cara +yyleng ;  return WRITE;   } 

"repeat"        {     nb_cara = nb_cara +yyleng ;  return REPEAT;   } 

"iterator"      {     nb_cara = nb_cara +yyleng ;  return ITERATOR;   } 


"?"        {     nb_cara = nb_cara +yyleng ;  return IF;   } 

":"    {     nb_cara = nb_cara +yyleng ;  return ELSE;   }  

":?"     {     nb_cara = nb_cara +yyleng ;   return ELSEIF;   }

"case"   {     nb_cara = nb_cara +yyleng ; return CASE;    }  

"default"   {     nb_cara = nb_cara +yyleng ; return DEFAULT;    }  


"$"      {     nb_cara = nb_cara +yyleng ;  return CASE_NUM;   } 

"break"   {     nb_cara = nb_cara +yyleng ;  return FIN_CASE;   } 

"struct"    {     nb_cara = nb_cara +yyleng ;  return STRUCT;   }  

"FIN"       {     nb_cara = nb_cara +yyleng ;  return FIN_PROG;   } 


{ID}           {     nb_cara = nb_cara +yyleng ;  yylval.str = strdup(yytext);  return ID;   } 

{blancs}    {     nb_cara = nb_cara +yyleng ;      } 


";"         {     nb_cara = nb_cara +yyleng ;    return FIN_INSTRUCTION;  } 

"+"          {     nb_cara = nb_cara +yyleng ;    return PLUS;  } 

"/"          {     nb_cara = nb_cara +yyleng ;    return DIV;  } 

"-"          {     nb_cara = nb_cara +yyleng ;    return MOINS;  } 

"*"          {     nb_cara = nb_cara +yyleng ;    return MUL;  } 

"%"          {     nb_cara = nb_cara +yyleng ;    return MOD; }

"("           {     nb_cara = nb_cara +yyleng ;   return PAR_OUV;  }

")"          {     nb_cara = nb_cara +yyleng ;  return PAR_FERM;  }

"<="       {     nb_cara = nb_cara +yyleng ;  return INF_EGAL; }

"<"         {     nb_cara = nb_cara +yyleng ;  return INF; }

">"         {     nb_cara = nb_cara +yyleng ;  return SUPP; }

">="       {     nb_cara = nb_cara +yyleng ;  return SUPP_EGAL; }


"="        {     nb_cara = nb_cara +yyleng ;  return EGALE;  }

"!="        {     nb_cara = nb_cara +yyleng ;  return PASEGALE; }

"!"          {     nb_cara = nb_cara +yyleng ;  return NEGATION; }

"&"          {     nb_cara = nb_cara +yyleng ;  return ET; }

"|"          {     nb_cara = nb_cara +yyleng ;  return OU; }

"["          {     nb_cara = nb_cara +yyleng ;  return DEB_TABLEAU; }

"]"          {     nb_cara = nb_cara +yyleng ;   return FIN_TABLEAU; }

"<-"         {     nb_cara = nb_cara +yyleng ;   return AFFECTATION; }

"{"           {     nb_cara = nb_cara +yyleng ;   return DEB_CORPS;  }

"}"           {     nb_cara = nb_cara +yyleng ;   return FIN_CORPS; }

","           {     nb_cara = nb_cara +yyleng ;   return SEPARATEUR; }

"."           {     nb_cara = nb_cara +yyleng ;   return ACCES_STRUCT; }


\n         { nb_cara  = 1 ; lignenum = lignenum +1; }


.   {  

    printf("Dans line %d, character %d: lexique error, dans le mot %s, debut de %c ",  lignenum, nb_cara , yytext , yytext[0] ); 
    nb_cara+=strlen(yytext);
}





