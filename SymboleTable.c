#include "symboleTable.h"




/********************************************************************************/



/** Allocation de la table de symbole  **/
SymboleTable *allocateSymboleTable()
{
  SymboleTable *symboleTable = (SymboleTable *)malloc(sizeof(SymboleTable));
  symboleTable->first = NULL;
  symboleTable->last = NULL;
  symboleTable->size = 0;
 return symboleTable;
}
/*******************************************************************************/


/********************************************/
/** inserer un nouveau noeud   **/
NodeSymbole *insertSymbole(SymboleTable *symboleTable, char *tokenId)
{
    if (symboleTable->size == 0)
    {
        // 1 er cas : table completement vide

       NodeSymbole *R= (NodeSymbole*)malloc(sizeof(NodeSymbole));// R est  la racine de la table de symb
       NodeSymbole *Q= R; // Q est queue de la table de symb

     // strcpy( R->tokenId ,tokenId);
      R->tokenId = tokenId;
       R->next = NULL;
       R->nbAttribut = 0;
       R->first= NULL;
       R->last = NULL;
       symboleTable->first = R;
       symboleTable->last = Q;
       symboleTable->size++;
       return R;
    }
    else
    {
        // 2 eme cas : table non  vide

        NodeSymbole *Q = symboleTable->last; // Q le dernier noeud de la table de symb

        NodeSymbole *newSymbole = (NodeSymbole *)malloc(sizeof(NodeSymbole)); // creation d un nouveau noeud qu on veut l'inserer newSymbole->tokenId = tokenId;
       newSymbole->tokenId = tokenId;
        newSymbole->next = NULL;
        newSymbole->nbAttribut = 0;
        newSymbole->first = NULL;
        newSymbole->last = NULL;
        Q->next = newSymbole; //chainage entre le dernier noeud de la table et le nouveau
        symboleTable->last =newSymbole; // change de la queue: le noued ajoute sera la queue
        symboleTable->size++; // mettre a jourt le nb de noueds de la table de symb
        return newSymbole;
    }
}
/*******************************************************************************/




NodeSymbole *insertSymboleByIndex(SymboleTable *symboleTable, int index, char *tokenId)

{
   NodeSymbole *R = symboleTable->first;

   NodeSymbole *Q = symboleTable->last;

   NodeSymbole *newSymbole;

    // index negative
    if (index < 0)
    {
        printf("\nERREUR : Indice negatif  ​​\n");
        return NULL;
    }
    // depassement de capacite
    if (index > symboleTable->size)
    {
        printf("\nERREUR : Indice depasse la capacite de la table  !\n");
        return NULL;
    }
    // inserer dans la racine
    else if (index == 0)
    {
        newSymbole = (NodeSymbole*)malloc(sizeof(NodeSymbole));
        newSymbole->tokenId = tokenId;
        newSymbole->first = NULL;
        newSymbole->last = NULL;
        newSymbole->nbAttribut = 0;
        symboleTable->size++;

        newSymbole->next = R;
        symboleTable->first = newSymbole;

        return newSymbole;
    }
    // inserer dans la queue
    else if (index == symboleTable->size )
    {
       newSymbole =insertSymbole(symboleTable, tokenId);
        return newSymbole;
    }

    else
    {
        newSymbole = (NodeSymbole*)malloc(sizeof(NodeSymbole));
        newSymbole->tokenId = tokenId;
        newSymbole->nbAttribut = 0;
        newSymbole->first = NULL;
        newSymbole->last = NULL;
        symboleTable->size++;

        NodeSymbole *p = getSymboleByIndex(symboleTable, index -1 );
        NodeSymbole *s = getSymboleByIndex(symboleTable, index );
        p->next =newSymbole;
        newSymbole->next = s;

        return newSymbole;
    }
}

/**************/


NodeSymbole *getSymboleByIndex(SymboleTable *symboleTable, int index)
{
    NodeSymbole *p = symboleTable->first;
    int cpt = 0;
    while (cpt != index)
    {

        if (p != symboleTable->last)
        {
         p= p->next;
        }
        else
        {
            p = NULL;
            break;
        }
        cpt++;
    }

    return p;
}

/*******************************************/
char * getAttribut(NodeSymbole *nodeSymbole, char *name)
{
    if (nodeSymbole != NULL)
    {
        if (nodeSymbole->nbAttribut > 0)
        {

            NodeAttribut *R = nodeSymbole->first;
            NodeAttribut *P = R;
            while (P!= NULL)
            {
                if (strcmp(P->name, name) == 0)
                {
                    return P->value;
                }
                P = P->next;
            }
            return P->value;
        }
    }
}


/*******************************************/
char * getAttributByIndex(SymboleTable *symboleTable, int Index ,char *name)
{
   NodeSymbole *symbole = getSymboleByIndex(symboleTable, Index);
    if (symbole != NULL)
    {
        if (symbole->nbAttribut > 0)
        {

           NodeAttribut *R= symbole->first;
           NodeAttribut *p = R;
            while (p != NULL)
            {
                if (strcmp(p->name, name) == 0)
                {
                    return p->value;
                }
                p = p->next;
            }
            return p->value;
        }
    }
}

/*******************************************/

void setAttribut(NodeSymbole *symbole, char *name, char *val)
{
    if (symbole != NULL)
    {
        if (symbole->nbAttribut == 0)
        {
           NodeAttribut *R = (NodeAttribut *)malloc(sizeof(NodeAttribut));
            R->name = name;
            R->value = val;
            R->next = NULL;
            symbole->first = R;
            symbole->last = R;
            symbole->nbAttribut++;
        }
        else
        {
            NodeAttribut  *Q = symbole->last;

            NodeAttribut  *newAttribut = (NodeAttribut  *)malloc(sizeof(NodeAttribut ));
            newAttribut->name = name;
            newAttribut->value = val;
            newAttribut->next = NULL;
            symbole->nbAttribut++;
            Q->next = newAttribut;
            symbole->last = newAttribut;
        }
    }
}
/******************************/

void setAttributByIndex( SymboleTable * symboleTable, int index, char *name, char *val)
{
    NodeSymbole *symbole = getSymboleByIndex( symboleTable, index);
    if (symbole != NULL)
    {
        if (symbole->nbAttribut == 0)
        {
            NodeAttribut *R = (NodeAttribut *)malloc(sizeof(NodeAttribut));
            R->name = name;
           R->value = val;
           R->next = NULL;
           symbole->first = R;
           symbole->last = R;
            symbole->nbAttribut ++;
        }
        else
        {
           NodeAttribut *Q= symbole->last;

            NodeAttribut *newAttribut = (NodeAttribut *)malloc(sizeof(NodeAttribut));
           newAttribut->name = name;
         newAttribut->value = val;
           newAttribut->next = NULL;
          symbole->nbAttribut ++;
            // setup chaining
            Q->next = newAttribut;
        }
    }
}



/************************/


void DeleteAttributs(NodeSymbole *node)
{
    NodeAttribut *R= node->first;
    NodeAttribut *s =R;
    NodeAttribut *p =R;
    NodeAttribut *Q = node->last;

    while (s != Q)
    {
        s = s->next;
        free(p);
        node->nbAttribut--;
        p = s;
    }
    free(s);
    node->nbAttribut--;
}
/*******************************************/
void DeleteTable(SymboleTable *symboleTable)
{
     NodeSymbole *R = symboleTable->first;
     NodeSymbole *s = R;
     NodeSymbole *p = R;
     NodeSymbole *Q = symboleTable->last;
    while (s!= Q)
    {
        s = s->next;
        DeleteAttributs(p);
        free(p);
       symboleTable->size--;
        p = s;
    }
    free(s);
    symboleTable->size--;
}
/*******************************************/


/*******************************************/

/** Recherche**/

NodeSymbole *search(SymboleTable *symboleTable, char *tokenId )
{
   NodeSymbole *R= symboleTable->first;
   NodeSymbole *p = R;
    while (p != NULL)
    {
        if (strcmp(p->tokenId, tokenId ) == 0 )
        {
            return p;
        }
        p = p->next;
    }
    return p;
}
/*******************************************************************************/




NodeSymbole *searchByName(SymboleTable *symboleTable, char* name)
{

     NodeSymbole *R = symboleTable->first;
     NodeSymbole *p = R;

while (p != NULL)
{
NodeAttribut *q = p->first;
while (q != NULL)
{
if (strcmp(q->name, name) == 0)
{
return p;
}
q = q->next;
}
p = p->next;
}
return NULL;
}



char *searchByNameAttribut(NodeSymbole *nodeSymbole, char* name)
{


     NodeSymbole *p = nodeSymbole;



NodeAttribut *q = p->first;
while (q != NULL)
{
if (strcmp(q->name, name) == 0)
{
return q->value;
}
q = q->next;
}
p = p->next;

return NULL;
}






/***********************************/

/** afficher   **/
void Afficher(SymboleTable *symboleTable)
{ NodeSymbole *p= symboleTable->first;
printf("\n ------------------------------------------------------------------ \n");
if( p== NULL){
        printf("  Table vide \n");

}
    while ( p!= NULL)


    {
        printf("NoeudSymbole tokenId :%s\n",p->tokenId);
         NodeAttribut *s= p->first;
        while ( s!= NULL)
        {

          printf("NoeudAttribut |Name: %s | Value: %s \n",s->name,s->value);


        s = s->next;
    }
   printf(" ________________\n");
     printf("NbAttribut  :%hd\n",p->nbAttribut);
    printf(" ________________\n");
 p = p->next;
}
 printf(" ________________\n");
 printf(" NbSymbole %hd\n",symboleTable->size);
 printf(" ________________\n");
printf("\n ------------------------------------------------------------------ \n");

}





