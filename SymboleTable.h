#ifndef SymboleTable_H
#define SymboleTable_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Structure*/
/*************************************************************************************/
typedef struct NodeAttribut
{
    char *name;
    char *value;
    struct NodeAttribut *next;

} NodeAttribut;
typedef struct NodeSymbole
{
  char *tokenId;
    int nbAttribut;
    struct NodeSymbole *next;
    NodeAttribut *first;
    NodeAttribut *last;

} NodeSymbole;

typedef struct SymboleTable
{
    NodeSymbole *first;
    NodeSymbole *last;
    int size;

} SymboleTable;

/*****************************************************************************************/
/** Allocation d'une table de symboles **/
SymboleTable *allocateSymboleTable();
/** Insertion D'un nouveau noeud  nodedSymbole   **/
NodeSymbole *insertSymbole(SymboleTable *symboleTable,char *tokenId);
/** Insertion D'un nouveau noeud  nodedSymbole avec un index d'insertion **/
NodeSymbole *insertSymboleByIndex(SymboleTable *symboleTable, int index, char *tokenId);
/** Avoir un symbole en donnant son index  **/
NodeSymbole *getSymboleByIndex(SymboleTable *symboleTable, int index);
/** Ajout d'un attribut a la liste d'un symbole donn�  **/
void setAttribut(NodeSymbole *symbole, char *name, char *val);
/** Ajout d'un attribut a la liste d'un symbole en donnant l'indice de ce dernier **/
void setAttributByIndex( SymboleTable * symboleTable, int index, char *name, char *val);
/** Avoir  un attribut d'un symbole en donnant son nom  **/
char * getAttribut(NodeSymbole *nodeSymbole, char *name);
/** Avoir  un attribut d'un symbole en donnant l'index du symbole et le nom d'attribut  **/
char * getAttributByIndex(SymboleTable *symboleTable, int Index ,char *name);
/** Suppression des attributs d'un noeud NodeAttribut d'un symbole **/
void DeleteAttributs(NodeSymbole *node);
/** Suppression d'une table de symbole   **/
void DeleteTable(SymboleTable *symboleTable);
/** Recherche d'un symbole avec le tokenId  **/
NodeSymbole *search(SymboleTable *symboleTable, char *tokenId);
void Afficher(SymboleTable *symboleTable);

/*****************************************************************************************/
#endif


