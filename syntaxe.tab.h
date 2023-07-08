/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAXE_TAB_H_INCLUDED
# define YY_YY_SYNTAXE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NOMPROGR = 258,                /* NOMPROGR  */
    TYPE_CONS = 259,               /* TYPE_CONS  */
    TYPE_INT = 260,                /* TYPE_INT  */
    TYPE_FLT = 261,                /* TYPE_FLT  */
    TYPE_CAR = 262,                /* TYPE_CAR  */
    TYPE_STR = 263,                /* TYPE_STR  */
    TYPE_BLN = 264,                /* TYPE_BLN  */
    STRUCT = 265,                  /* STRUCT  */
    DEB_CORPS = 266,               /* DEB_CORPS  */
    FIN_CORPS = 267,               /* FIN_CORPS  */
    PAR_OUV = 268,                 /* PAR_OUV  */
    PAR_FERM = 269,                /* PAR_FERM  */
    SEPARATEUR = 270,              /* SEPARATEUR  */
    FIN_INSTRUCTION = 271,         /* FIN_INSTRUCTION  */
    DEB_TABLEAU = 272,             /* DEB_TABLEAU  */
    FIN_TABLEAU = 273,             /* FIN_TABLEAU  */
    ACCES_STRUCT = 274,            /* ACCES_STRUCT  */
    MAIN = 275,                    /* MAIN  */
    PROCEDURE = 276,               /* PROCEDURE  */
    AFFECTATION = 277,             /* AFFECTATION  */
    FIN_PROG = 278,                /* FIN_PROG  */
    READ = 279,                    /* READ  */
    WRITE = 280,                   /* WRITE  */
    RETURN = 281,                  /* RETURN  */
    IF = 282,                      /* IF  */
    ELSE = 283,                    /* ELSE  */
    ELSEIF = 284,                  /* ELSEIF  */
    REPEAT = 285,                  /* REPEAT  */
    ITERATOR = 286,                /* ITERATOR  */
    CASE = 287,                    /* CASE  */
    CASE_NUM = 288,                /* CASE_NUM  */
    FIN_CASE = 289,                /* FIN_CASE  */
    DEFAULT = 290,                 /* DEFAULT  */
    PLUS = 291,                    /* PLUS  */
    MOINS = 292,                   /* MOINS  */
    DIV = 293,                     /* DIV  */
    MUL = 294,                     /* MUL  */
    MOD = 295,                     /* MOD  */
    INF_EGAL = 296,                /* INF_EGAL  */
    INF = 297,                     /* INF  */
    SUPP = 298,                    /* SUPP  */
    SUPP_EGAL = 299,               /* SUPP_EGAL  */
    EGALE = 300,                   /* EGALE  */
    PASEGALE = 301,                /* PASEGALE  */
    NEGATION = 302,                /* NEGATION  */
    ET = 303,                      /* ET  */
    OU = 304,                      /* OU  */
    ENTIER = 305,                  /* ENTIER  */
    CARACTERE = 306,               /* CARACTERE  */
    FLOTTANT = 307,                /* FLOTTANT  */
    CHAINE = 308,                  /* CHAINE  */
    ID = 309,                      /* ID  */
    BOOLEAN_FAUX = 310,            /* BOOLEAN_FAUX  */
    BOOLEAN_VRAI = 311             /* BOOLEAN_VRAI  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 86 "syntaxe.y"

    int entier;
    float flt;
    char* str;
    char c;

#line 127 "syntaxe.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAXE_TAB_H_INCLUDED  */
