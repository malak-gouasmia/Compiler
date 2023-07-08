/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "syntaxe.y"
  
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




#line 152 "syntaxe.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntaxe.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NOMPROGR = 3,                   /* NOMPROGR  */
  YYSYMBOL_TYPE_CONS = 4,                  /* TYPE_CONS  */
  YYSYMBOL_TYPE_INT = 5,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_FLT = 6,                   /* TYPE_FLT  */
  YYSYMBOL_TYPE_CAR = 7,                   /* TYPE_CAR  */
  YYSYMBOL_TYPE_STR = 8,                   /* TYPE_STR  */
  YYSYMBOL_TYPE_BLN = 9,                   /* TYPE_BLN  */
  YYSYMBOL_STRUCT = 10,                    /* STRUCT  */
  YYSYMBOL_DEB_CORPS = 11,                 /* DEB_CORPS  */
  YYSYMBOL_FIN_CORPS = 12,                 /* FIN_CORPS  */
  YYSYMBOL_PAR_OUV = 13,                   /* PAR_OUV  */
  YYSYMBOL_PAR_FERM = 14,                  /* PAR_FERM  */
  YYSYMBOL_SEPARATEUR = 15,                /* SEPARATEUR  */
  YYSYMBOL_FIN_INSTRUCTION = 16,           /* FIN_INSTRUCTION  */
  YYSYMBOL_DEB_TABLEAU = 17,               /* DEB_TABLEAU  */
  YYSYMBOL_FIN_TABLEAU = 18,               /* FIN_TABLEAU  */
  YYSYMBOL_ACCES_STRUCT = 19,              /* ACCES_STRUCT  */
  YYSYMBOL_MAIN = 20,                      /* MAIN  */
  YYSYMBOL_PROCEDURE = 21,                 /* PROCEDURE  */
  YYSYMBOL_AFFECTATION = 22,               /* AFFECTATION  */
  YYSYMBOL_FIN_PROG = 23,                  /* FIN_PROG  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_WRITE = 25,                     /* WRITE  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_ELSEIF = 29,                    /* ELSEIF  */
  YYSYMBOL_REPEAT = 30,                    /* REPEAT  */
  YYSYMBOL_ITERATOR = 31,                  /* ITERATOR  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_CASE_NUM = 33,                  /* CASE_NUM  */
  YYSYMBOL_FIN_CASE = 34,                  /* FIN_CASE  */
  YYSYMBOL_DEFAULT = 35,                   /* DEFAULT  */
  YYSYMBOL_PLUS = 36,                      /* PLUS  */
  YYSYMBOL_MOINS = 37,                     /* MOINS  */
  YYSYMBOL_DIV = 38,                       /* DIV  */
  YYSYMBOL_MUL = 39,                       /* MUL  */
  YYSYMBOL_MOD = 40,                       /* MOD  */
  YYSYMBOL_INF_EGAL = 41,                  /* INF_EGAL  */
  YYSYMBOL_INF = 42,                       /* INF  */
  YYSYMBOL_SUPP = 43,                      /* SUPP  */
  YYSYMBOL_SUPP_EGAL = 44,                 /* SUPP_EGAL  */
  YYSYMBOL_EGALE = 45,                     /* EGALE  */
  YYSYMBOL_PASEGALE = 46,                  /* PASEGALE  */
  YYSYMBOL_NEGATION = 47,                  /* NEGATION  */
  YYSYMBOL_ET = 48,                        /* ET  */
  YYSYMBOL_OU = 49,                        /* OU  */
  YYSYMBOL_ENTIER = 50,                    /* ENTIER  */
  YYSYMBOL_CARACTERE = 51,                 /* CARACTERE  */
  YYSYMBOL_FLOTTANT = 52,                  /* FLOTTANT  */
  YYSYMBOL_CHAINE = 53,                    /* CHAINE  */
  YYSYMBOL_ID = 54,                        /* ID  */
  YYSYMBOL_BOOLEAN_FAUX = 55,              /* BOOLEAN_FAUX  */
  YYSYMBOL_BOOLEAN_VRAI = 56,              /* BOOLEAN_VRAI  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_debut_acolade = 58,             /* debut_acolade  */
  YYSYMBOL_fin_acolade = 59,               /* fin_acolade  */
  YYSYMBOL_debut_paren = 60,               /* debut_paren  */
  YYSYMBOL_fin_paren = 61,                 /* fin_paren  */
  YYSYMBOL_fin_inst = 62,                  /* fin_inst  */
  YYSYMBOL_separ = 63,                     /* separ  */
  YYSYMBOL_debut_tab = 64,                 /* debut_tab  */
  YYSYMBOL_fin_tab = 65,                   /* fin_tab  */
  YYSYMBOL_faut_id = 66,                   /* faut_id  */
  YYSYMBOL_faut_nomprog = 67,              /* faut_nomprog  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_programme = 69,                 /* programme  */
  YYSYMBOL_def_structs = 70,               /* def_structs  */
  YYSYMBOL_def_struct = 71,                /* def_struct  */
  YYSYMBOL_struct_corp = 72,               /* struct_corp  */
  YYSYMBOL_plus_declarations = 73,         /* plus_declarations  */
  YYSYMBOL_Fn_Pro = 74,                    /* Fn_Pro  */
  YYSYMBOL_Fn = 75,                        /* Fn  */
  YYSYMBOL_PR = 76,                        /* PR  */
  YYSYMBOL_Params = 77,                    /* Params  */
  YYSYMBOL_plus_Params = 78,               /* plus_Params  */
  YYSYMBOL_decalaration_para = 79,         /* decalaration_para  */
  YYSYMBOL_prog_principale = 80,           /* prog_principale  */
  YYSYMBOL_corp = 81,                      /* corp  */
  YYSYMBOL_corp_main = 82,                 /* corp_main  */
  YYSYMBOL_corp_fnc = 83,                  /* corp_fnc  */
  YYSYMBOL_retour = 84,                    /* retour  */
  YYSYMBOL_au_moin_inst = 85,              /* au_moin_inst  */
  YYSYMBOL_if_struct = 86,                 /* if_struct  */
  YYSYMBOL_87_1 = 87,                      /* $@1  */
  YYSYMBOL_88_2 = 88,                      /* $@2  */
  YYSYMBOL_suite = 89,                     /* suite  */
  YYSYMBOL_case_struct = 90,               /* case_struct  */
  YYSYMBOL_corp_case = 91,                 /* corp_case  */
  YYSYMBOL_plus_case = 92,                 /* plus_case  */
  YYSYMBOL_une_case = 93,                  /* une_case  */
  YYSYMBOL_default = 94,                   /* default  */
  YYSYMBOL_while_struct = 95,              /* while_struct  */
  YYSYMBOL_for_struct = 96,                /* for_struct  */
  YYSYMBOL_97_3 = 97,                      /* $@3  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_99_5 = 99,                      /* $@5  */
  YYSYMBOL_100_6 = 100,                    /* $@6  */
  YYSYMBOL_101_7 = 101,                    /* $@7  */
  YYSYMBOL_init_index = 102,               /* init_index  */
  YYSYMBOL_incrementation = 103,           /* incrementation  */
  YYSYMBOL_Condition_For = 104,            /* Condition_For  */
  YYSYMBOL_Appel_Methode = 105,            /* Appel_Methode  */
  YYSYMBOL_write_Proc = 106,               /* write_Proc  */
  YYSYMBOL_read_Proc = 107,                /* read_Proc  */
  YYSYMBOL_valeur_param = 108,             /* valeur_param  */
  YYSYMBOL_plus_valeur = 109,              /* plus_valeur  */
  YYSYMBOL_parametre_read = 110,           /* parametre_read  */
  YYSYMBOL_decalaration = 111,             /* decalaration  */
  YYSYMBOL_affec = 112,                    /* affec  */
  YYSYMBOL_valeur = 113,                   /* valeur  */
  YYSYMBOL_constant = 114,                 /* constant  */
  YYSYMBOL_condition = 115,                /* condition  */
  YYSYMBOL_comparaison = 116,              /* comparaison  */
  YYSYMBOL_expression = 117,               /* expression  */
  YYSYMBOL_terme = 118                     /* terme  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   126,   128,   129,   132,   133,   135,   136,
     139,   140,   142,   143,   147,   149,   150,   152,   153,   155,
     156,   159,   160,   161,   162,   163,   167,   171,   172,   177,
     181,   182,   185,   186,   190,   191,   192,   196,   217,   236,
     237,   241,   242,   245,   246,   247,   248,   252,   253,   256,
     260,   261,   264,   267,   268,   271,   272,   273,   274,   275,
     276,   278,   279,   280,   282,   283,   284,   285,   286,   287,
     289,   290,   291,   296,   309,   295,   327,   340,   354,   358,
     360,   361,   363,   364,   365,   367,   370,   374,   379,   390,
     410,   416,   430,   378,   458,   459,   499,   502,   503,   506,
     507,   511,   516,   521,   530,   554,   557,   560,   561,   563,
     564,   567,   592,   620,   639,   663,   684,   732,   789,   790,
     791,   792,   794,   795,   800,   801,   802,   803,   804,   805,
     806,   812,   813,   814,   815,   816,   817,   821,   822,   823,
     824,   825,   826,   829,   830,   831,   832,   833,   834,   835,
     836,   839,   878,   879,   881,   933,   936,   937,   938,   939
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NOMPROGR",
  "TYPE_CONS", "TYPE_INT", "TYPE_FLT", "TYPE_CAR", "TYPE_STR", "TYPE_BLN",
  "STRUCT", "DEB_CORPS", "FIN_CORPS", "PAR_OUV", "PAR_FERM", "SEPARATEUR",
  "FIN_INSTRUCTION", "DEB_TABLEAU", "FIN_TABLEAU", "ACCES_STRUCT", "MAIN",
  "PROCEDURE", "AFFECTATION", "FIN_PROG", "READ", "WRITE", "RETURN", "IF",
  "ELSE", "ELSEIF", "REPEAT", "ITERATOR", "CASE", "CASE_NUM", "FIN_CASE",
  "DEFAULT", "PLUS", "MOINS", "DIV", "MUL", "MOD", "INF_EGAL", "INF",
  "SUPP", "SUPP_EGAL", "EGALE", "PASEGALE", "NEGATION", "ET", "OU",
  "ENTIER", "CARACTERE", "FLOTTANT", "CHAINE", "ID", "BOOLEAN_FAUX",
  "BOOLEAN_VRAI", "$accept", "debut_acolade", "fin_acolade", "debut_paren",
  "fin_paren", "fin_inst", "separ", "debut_tab", "fin_tab", "faut_id",
  "faut_nomprog", "type", "programme", "def_structs", "def_struct",
  "struct_corp", "plus_declarations", "Fn_Pro", "Fn", "PR", "Params",
  "plus_Params", "decalaration_para", "prog_principale", "corp",
  "corp_main", "corp_fnc", "retour", "au_moin_inst", "if_struct", "$@1",
  "$@2", "suite", "case_struct", "corp_case", "plus_case", "une_case",
  "default", "while_struct", "for_struct", "$@3", "$@4", "$@5", "$@6",
  "$@7", "init_index", "incrementation", "Condition_For", "Appel_Methode",
  "write_Proc", "read_Proc", "valeur_param", "plus_valeur",
  "parametre_read", "decalaration", "affec", "valeur", "constant",
  "condition", "comparaison", "expression", "terme", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-152)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,  -143,  -143,    13,    60,  -143,  -143,    16,  -143,    18,
     368,    16,  -143,  -143,   109,  -143,  -143,  -143,  -143,  -143,
      54,    93,   108,   368,   368,  -143,  -143,  -143,   287,    98,
      98,    98,   127,  -143,  -143,   430,    33,    74,  -143,   287,
    -143,  -143,   419,   419,    78,  -143,   113,  -143,    13,    91,
    -143,  -143,  -143,  -143,   430,    37,    78,  -143,   121,    78,
    -143,  -143,   109,    13,  -143,    12,    39,  -143,   115,   109,
    -143,  -143,   419,   109,   324,  -143,  -143,  -143,  -143,   119,
    -143,   125,    12,  -143,  -143,   324,  -143,    98,    98,    22,
      22,    98,    98,    96,    74,  -143,   324,   324,   324,   324,
     324,   324,   324,   324,   324,    13,    12,   122,    26,   123,
     205,   135,  -143,    48,  -143,   109,    20,   231,   129,   231,
     205,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,   126,  -143,  -143,   231,    74,   166,    78,   261,
       3,   114,  -143,  -143,  -143,  -143,   233,  -143,  -143,   264,
    -143,    78,  -143,   130,  -143,   404,   373,    22,   321,    48,
      32,    78,   388,   109,  -143,  -143,    61,    58,    78,   167,
      13,    78,  -143,    13,  -143,   134,    13,  -143,  -143,  -143,
    -143,   136,   138,   367,    78,    13,   231,   264,   264,   264,
     264,   264,    78,   111,    22,    22,  -143,   264,   264,   264,
     264,   264,   264,  -143,   140,   231,  -143,   109,   169,  -143,
      13,  -143,    12,  -143,   174,    12,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,    78,    78,  -143,  -143,  -143,
    -143,  -143,  -143,    87,   175,  -143,    23,   154,   231,  -143,
    -143,  -143,  -143,  -143,  -143,   109,    22,  -143,   173,  -143,
     118,  -143,   165,  -143,  -143,  -143,   166,  -143,  -143,    74,
    -143,   154,  -143,   168,    13,  -143,   109,   231,   264,   264,
     264,   264,    58,   324,   152,  -143,  -143,   324,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   177,    12,   179,   289,
      13,  -143,    13,   200,  -143,  -143,  -143,  -143,    78,  -143,
     109,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    19,     0,     0,    10,    11,    27,     1,     0,
      34,    27,    18,    17,     0,    21,    22,    24,    25,    23,
       0,     0,    47,    34,    34,    28,     2,     3,    31,     0,
       0,     0,     0,    35,    36,     0,     0,     0,    30,    32,
       6,     7,    39,    39,     0,    26,     0,    14,     0,     0,
       4,     5,    29,    33,     0,     0,     0,    40,     0,     0,
       8,     9,     0,     0,   113,     0,     0,    43,     0,     0,
      12,    13,     0,     0,    50,    48,   115,    15,    16,     0,
      44,     0,     0,    38,    42,    50,    37,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    57,    58,    59,    60,
      63,    62,    61,    55,    56,     0,     0,     0,     0,     0,
       0,     6,   136,     0,    73,     0,     0,     0,     0,     0,
       0,    49,    66,    67,    68,    69,    72,    71,    70,    64,
      65,   114,     0,    45,    53,     0,     0,   111,     0,   143,
       0,     0,   152,   119,   153,   118,     0,   120,   121,     0,
     155,     0,   108,     0,   122,   145,     6,     0,     0,     0,
       0,     0,     0,     0,    87,    94,     0,     0,     0,     0,
       0,     0,    46,     0,    52,     0,     0,   156,   158,   157,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    88,     0,     0,   116,
       0,    54,     0,   106,     0,     0,   144,   105,   110,   146,
     147,   149,   148,   150,   133,     0,     0,   142,   141,   139,
     140,   137,   138,    76,     0,    95,     0,    80,     0,   104,
     112,   123,   154,   134,   135,     0,     0,    75,     0,    99,
       0,    89,     0,   126,   125,   124,   127,   129,   130,     0,
      81,    82,    84,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,    50,     0,    79,    83,    50,   117,    78,
      96,   103,   102,   100,   101,    90,     0,     0,     0,     0,
       0,   128,     0,     6,    91,    98,    86,    85,     0,    92,
       0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,    -4,   -85,   -25,   -44,   -47,  -142,   -33,   -75,  -143,
    -143,    47,  -143,   204,  -143,  -143,   183,   148,  -143,  -143,
     181,   158,  -143,  -143,   -67,   -77,  -143,  -143,   294,  -143,
    -143,  -143,  -143,  -143,  -143,   -30,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   -57,  -143,
    -143,   131,    66,  -143,    75,  -143,   -99,  -143,   -52,  -143,
      38,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    74,    52,   149,   216,     7,    72,   182,    79,    14,
       3,    36,     4,    10,    11,    37,    38,    22,    23,    24,
      56,    57,    58,    32,    75,    94,    86,   136,    95,    96,
     163,   233,   247,    97,   259,   260,   261,   262,    98,    99,
     236,   272,   289,   298,   300,   167,   294,   251,   150,   101,
     102,   151,   152,   138,   103,   104,   153,   263,   160,   161,
     154,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    64,    83,    49,    42,    43,    44,   107,   108,   121,
      28,   186,    69,    77,     5,    73,    76,   100,   168,    12,
     170,   165,    68,   111,   249,   206,     9,   134,   100,     6,
      78,   132,     1,    81,     2,    41,   173,   114,   115,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   164,   156,
      47,   174,   135,   177,    47,   178,    47,    21,   131,    70,
       8,    41,   109,   110,   113,   113,   116,   117,   120,    85,
      21,    21,    13,    71,   166,    50,   112,   250,   204,    60,
     194,   195,    46,   205,   140,   141,    51,    48,   159,    55,
      55,    67,    61,    80,   176,   157,   203,    40,   142,    40,
     144,    66,   158,    39,   175,   192,   235,   185,    29,    41,
      26,    41,    60,   118,    39,   245,   246,   196,   119,    55,
      27,   120,    70,   209,   207,    61,   211,   210,    31,   213,
     285,    70,   113,   120,   159,   -41,    71,   240,   217,   264,
     242,    65,   225,   226,  -109,    71,  -131,    30,   224,  -131,
      45,   162,   197,   198,   199,   200,   201,   202,   120,   268,
     269,   270,   271,   239,   179,    82,   180,    63,   280,   113,
     113,    33,    34,   105,   275,   106,   133,   137,   265,   169,
     172,   243,   244,    47,   212,   208,   214,   184,   215,   252,
     234,   238,   241,   248,   266,   267,   286,   193,   273,   279,
     288,   277,   287,   237,   253,   254,   139,   255,   256,   257,
     258,   290,   291,   292,   -97,    25,   100,   278,    41,  -107,
     100,   113,    53,   274,    59,   219,   220,   221,   222,   223,
      84,   276,   139,   301,    40,   227,   228,   229,   230,   231,
     232,   140,   141,   296,    41,   297,    41,  -151,  -151,  -151,
     181,   171,   218,     0,   299,   142,   143,   144,   145,   146,
     147,   148,    -6,     0,     0,   139,     0,   140,   141,  -151,
    -151,  -151,  -151,  -151,    -6,     0,     0,    41,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     293,    35,    15,    16,    17,    18,    19,    -6,    -6,     0,
     140,   141,    41,     0,     0,     0,   281,   282,   283,   284,
       0,    -6,     0,    -6,   142,    -6,   144,     0,   183,     0,
       0,     0,    40,     0,     0,   140,   141,   295,    35,    15,
      16,    17,    18,    19,    41,  -151,     0,     0,    47,   142,
       0,   144,     0,   183,     0,     0,     0,     0,    87,    88,
       0,    89,     0,     0,    90,    91,    92,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,    40,  -136,
    -136,     0,     0,    15,    16,    17,    18,    19,    93,     0,
      41,  -151,  -151,  -151,    47,     0,     0,  -143,     0,    20,
     122,   123,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -143,  -143,  -143,  -143,  -143,  -143,
       0,  -131,  -131,    54,    15,    16,    17,    18,    19,   197,
     198,   199,   200,   201,   202,    15,    16,    17,    18,    19,
     187,   188,   189,   190,   191
};

static const yytype_int16 yycheck[] =
{
      44,    48,    69,    36,    29,    30,    31,    82,    85,    94,
      14,   153,    56,     1,     1,    59,    63,    74,   117,     1,
     119,     1,    55,     1,     1,   167,    10,     1,    85,    16,
      18,   106,     1,    66,     3,    13,   135,    89,    90,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   115,     1,
      17,   136,    26,    50,    17,    52,    17,    10,   105,     1,
       0,    13,    87,    88,    89,    90,    91,    92,    93,    73,
      23,    24,    54,    15,    54,     1,    54,    54,    17,     1,
      48,    49,    35,    22,    36,    37,    12,    54,   113,    42,
      43,    54,    14,    54,   138,    47,   163,     1,    50,     1,
      52,    54,    54,    28,   137,   157,   205,   151,    54,    13,
       1,    13,     1,    17,    39,    28,    29,   161,    22,    72,
      11,   146,     1,   170,   168,    14,   173,   171,    20,   176,
     272,     1,   157,   158,   159,    14,    15,   212,   185,   238,
     215,    50,   194,   195,    14,    15,    11,    54,   192,    14,
      23,   113,    41,    42,    43,    44,    45,    46,   183,    41,
      42,    43,    44,   210,    50,    50,    52,    54,   267,   194,
     195,    23,    24,    54,   259,    50,    54,    54,   245,    50,
      54,   225,   226,    17,    50,    18,    50,   149,    50,    35,
      50,    22,    18,    18,   246,    22,   273,   159,    33,   266,
     277,    33,    50,   207,    50,    51,     1,    53,    54,    55,
      56,    34,   287,    34,    14,    11,   273,   264,    13,    14,
     277,   246,    39,   256,    43,   187,   188,   189,   190,   191,
      72,   261,     1,   300,     1,   197,   198,   199,   200,   201,
     202,    36,    37,   290,    13,   292,    13,    14,    15,    16,
      17,   120,   186,    -1,   298,    50,    51,    52,    53,    54,
      55,    56,     1,    -1,    -1,     1,    -1,    36,    37,    36,
      37,    38,    39,    40,    13,    -1,    -1,    13,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
       1,     4,     5,     6,     7,     8,     9,    36,    37,    -1,
      36,    37,    13,    -1,    -1,    -1,   268,   269,   270,   271,
      -1,    50,    -1,    52,    50,    54,    52,    -1,    54,    -1,
      -1,    -1,     1,    -1,    -1,    36,    37,   289,     4,     5,
       6,     7,     8,     9,    13,    14,    -1,    -1,    17,    50,
      -1,    52,    -1,    54,    -1,    -1,    -1,    -1,    24,    25,
      -1,    27,    -1,    -1,    30,    31,    32,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     1,    48,
      49,    -1,    -1,     5,     6,     7,     8,     9,    54,    -1,
      13,    14,    15,    16,    17,    -1,    -1,    14,    -1,    21,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,     4,     5,     6,     7,     8,     9,    41,
      42,    43,    44,    45,    46,     5,     6,     7,     8,     9,
      36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    67,    69,     1,    16,    62,     0,    10,
      70,    71,     1,    54,    66,     5,     6,     7,     8,     9,
      21,    68,    74,    75,    76,    70,     1,    11,    58,    54,
      54,    20,    80,    74,    74,     4,    68,    72,    73,   111,
       1,    13,    60,    60,    60,    23,    68,    17,    54,    64,
       1,    12,    59,    73,     4,    68,    77,    78,    79,    77,
       1,    14,    61,    54,    62,    50,    68,    54,    64,    61,
       1,    15,    63,    61,    58,    81,    62,     1,    18,    65,
      54,    64,    50,    81,    78,    58,    83,    24,    25,    27,
      30,    31,    32,    54,    82,    85,    86,    90,    95,    96,
     105,   106,   107,   111,   112,    54,    50,    65,    82,    60,
      60,     1,    54,    60,   115,   115,    60,    60,    17,    22,
      60,    59,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    62,    65,    54,     1,    26,    84,    54,   110,     1,
      36,    37,    50,    51,    52,    53,    54,    55,    56,    60,
     105,   108,   109,   113,   117,   118,     1,    47,    54,    60,
     115,   116,   117,    87,    81,     1,    54,   102,   113,    50,
     113,   108,    54,   113,    59,    64,    61,    50,    52,    50,
      52,    17,    64,    54,   117,    61,    63,    36,    37,    38,
      39,    40,   115,   117,    48,    49,    61,    41,    42,    43,
      44,    45,    46,    81,    17,    22,    63,    61,    18,    62,
      61,    62,    50,    62,    50,    50,    61,    62,   109,   117,
     117,   117,   117,   117,    61,   115,   115,   117,   117,   117,
     117,   117,   117,    88,    50,   113,    97,    58,    22,    62,
      65,    18,    65,    61,    61,    28,    29,    89,    18,     1,
      54,   104,    35,    50,    51,    53,    54,    55,    56,    91,
      92,    93,    94,   114,   113,    81,   115,    22,    41,    42,
      43,    44,    98,    33,    64,    59,    92,    33,    62,    81,
     113,   117,   117,   117,   117,    63,    82,    50,    82,    99,
      34,    65,    34,     1,   103,   117,    62,    62,   100,    61,
     101,    81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    69,    70,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    75,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    81,
      82,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    87,    88,    86,    89,    89,    89,    90,
      91,    91,    92,    92,    92,    93,    94,    95,    97,    98,
      99,   100,   101,    96,   102,   102,   102,   103,   103,   104,
     104,   104,   104,   104,   105,   106,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   115,   115,   115,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     0,     2,     5,
       1,     0,     1,     2,     0,     2,     2,     6,     6,     0,
       1,     1,     3,     2,     3,     5,     6,     0,     4,     3,
       0,     1,     4,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     0,     0,     6,     0,     2,     3,     7,
       0,     1,     1,     2,     1,     5,     5,     3,     0,     0,
       0,     0,     0,    14,     1,     3,     6,     1,     1,     1,
       3,     3,     3,     3,     5,     5,     5,     0,     1,     1,
       3,     1,     4,     3,     6,     4,     4,     7,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     4,     5,     5,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     4,     1,     2,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* debut_acolade: error  */
#line 125 "syntaxe.y"
                       { printf("Acolade debut manquante\n"); err++; return -1;   }
#line 1503 "syntaxe.tab.c"
    break;

  case 4: /* fin_acolade: error  */
#line 128 "syntaxe.y"
                     { printf("Acolade Fin manquante\n");  err++; return -1;  }
#line 1509 "syntaxe.tab.c"
    break;

  case 6: /* debut_paren: error  */
#line 132 "syntaxe.y"
                     { printf("Parenthese Ouvrante manquante\n"); err++; return -1; }
#line 1515 "syntaxe.tab.c"
    break;

  case 8: /* fin_paren: error  */
#line 135 "syntaxe.y"
                    { printf("Parenthese Fermante manquante\n");  err++; return -1; }
#line 1521 "syntaxe.tab.c"
    break;

  case 10: /* fin_inst: error  */
#line 139 "syntaxe.y"
                  { printf("Symbole Fin d'intruction manquant\n");  err++; return -1; }
#line 1527 "syntaxe.tab.c"
    break;

  case 12: /* separ: error  */
#line 142 "syntaxe.y"
                { printf("Symbole de separateur des parametres manaquant\n");  err++; return -1; }
#line 1533 "syntaxe.tab.c"
    break;

  case 15: /* fin_tab: error  */
#line 149 "syntaxe.y"
                    { printf("pas de ]\n"); err++; return -1;}
#line 1539 "syntaxe.tab.c"
    break;

  case 18: /* faut_id: error  */
#line 153 "syntaxe.y"
                         { printf("faut declarer un ID \n"); err++; return -1;}
#line 1545 "syntaxe.tab.c"
    break;

  case 20: /* faut_nomprog: error  */
#line 156 "syntaxe.y"
                         { printf("faut redifinie nom de programme \n"); err++; return -1;}
#line 1551 "syntaxe.tab.c"
    break;

  case 21: /* type: TYPE_INT  */
#line 159 "syntaxe.y"
                     {(yyval.str)=(yyvsp[0].str);}
#line 1557 "syntaxe.tab.c"
    break;

  case 22: /* type: TYPE_FLT  */
#line 160 "syntaxe.y"
                       {(yyval.str)=(yyvsp[0].str);}
#line 1563 "syntaxe.tab.c"
    break;

  case 23: /* type: TYPE_BLN  */
#line 161 "syntaxe.y"
                       {(yyval.str)=(yyvsp[0].str);}
#line 1569 "syntaxe.tab.c"
    break;

  case 24: /* type: TYPE_CAR  */
#line 162 "syntaxe.y"
                       {(yyval.str)=(yyvsp[0].str);}
#line 1575 "syntaxe.tab.c"
    break;

  case 25: /* type: TYPE_STR  */
#line 163 "syntaxe.y"
                       {(yyval.str)=(yyvsp[0].str);}
#line 1581 "syntaxe.tab.c"
    break;

  case 26: /* programme: faut_nomprog fin_inst def_structs Fn_Pro prog_principale FIN_PROG  */
#line 168 "syntaxe.y"
                            {  printf("Le programme est syntaxiquement correct\n");  YYACCEPT; }
#line 1587 "syntaxe.tab.c"
    break;

  case 29: /* def_struct: STRUCT faut_id debut_acolade struct_corp fin_acolade  */
#line 178 "syntaxe.y"
            { }
#line 1593 "syntaxe.tab.c"
    break;

  case 31: /* struct_corp: %empty  */
#line 182 "syntaxe.y"
                            { printf("Warning, corp vide lors definition structure\n");  }
#line 1599 "syntaxe.tab.c"
    break;

  case 37: /* Fn: type ID debut_paren Params fin_paren corp_fnc  */
#line 196 "syntaxe.y"
                                                             {
            NodeSymbole *x;
            x=search(ts, (yyvsp[-4].str));
            
            if(x == NULL)
            {      
                    x = insertSymbole(ts,(yyvsp[-4].str));
                    setAttribut(x, "Etat", "FCT");
                    setAttribut(x, "Type", (yyvsp[-5].str));
                    printf("Definition de fonction est correcte\n"); 
                    Afficher(ts);
            }

            else  
                { 
                        printf("erreur Semantique: double declaration de la fonction %s,  a la ligne %d, le caractere %d\n", (yyvsp[-4].str), lignenum, nb_cara); }
                }
#line 1621 "syntaxe.tab.c"
    break;

  case 38: /* PR: PROCEDURE ID debut_paren Params fin_paren corp  */
#line 217 "syntaxe.y"
                                                             { 

        NodeSymbole *x;
        x=search(ts, (yyvsp[-4].str));
        
        if(x == NULL)
		{      
            x = insertSymbole(ts,(yyvsp[-4].str));
            setAttribut(x, "Etat", "PROC");
            printf("Definition de procedure est correcte\n");
            Afficher(ts);
		}

        else  printf("erreur Semantique: double declaration de la procedure %s,  a la ligne %d, le caractere %d\n", (yyvsp[-4].str), lignenum, nb_cara); 
                }
#line 1641 "syntaxe.tab.c"
    break;

  case 43: /* decalaration_para: type ID  */
#line 245 "syntaxe.y"
                                     { }
#line 1647 "syntaxe.tab.c"
    break;

  case 44: /* decalaration_para: TYPE_CONS type ID  */
#line 246 "syntaxe.y"
                                        {}
#line 1653 "syntaxe.tab.c"
    break;

  case 45: /* decalaration_para: type debut_tab ENTIER fin_tab ID  */
#line 247 "syntaxe.y"
                                                        {}
#line 1659 "syntaxe.tab.c"
    break;

  case 46: /* decalaration_para: TYPE_CONS type debut_tab ENTIER fin_tab ID  */
#line 248 "syntaxe.y"
                                                                   { }
#line 1665 "syntaxe.tab.c"
    break;

  case 48: /* prog_principale: MAIN debut_paren fin_paren corp  */
#line 253 "syntaxe.y"
                                                        { printf("Definition de Main(programme principale) est correcte\n");  }
#line 1671 "syntaxe.tab.c"
    break;

  case 49: /* corp: debut_acolade corp_main fin_acolade  */
#line 256 "syntaxe.y"
                                                           { printf("Definition de corp est correcte\n");  }
#line 1677 "syntaxe.tab.c"
    break;

  case 53: /* retour: error  */
#line 267 "syntaxe.y"
                             { printf("Return attendue\n"); return -1; }
#line 1683 "syntaxe.tab.c"
    break;

  case 73: /* $@1: %empty  */
#line 296 "syntaxe.y"
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
#line 1699 "syntaxe.tab.c"
    break;

  case 74: /* $@2: %empty  */
#line 309 "syntaxe.y"
             {
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
#line 1720 "syntaxe.tab.c"
    break;

  case 76: /* suite: %empty  */
#line 327 "syntaxe.y"
                { 
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
#line 1738 "syntaxe.tab.c"
    break;

  case 77: /* suite: ELSE corp  */
#line 340 "syntaxe.y"
                           { 
                        
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
#line 1757 "syntaxe.tab.c"
    break;

  case 78: /* suite: ELSEIF condition corp  */
#line 354 "syntaxe.y"
                                         { printf("Definition de ELSEIF est correcte\n");  }
#line 1763 "syntaxe.tab.c"
    break;

  case 79: /* case_struct: CASE debut_paren valeur fin_paren debut_acolade corp_case fin_acolade  */
#line 358 "syntaxe.y"
                                                                                            { printf("Definition de Switch est correcte\n");  }
#line 1769 "syntaxe.tab.c"
    break;

  case 87: /* while_struct: REPEAT condition corp  */
#line 374 "syntaxe.y"
                                             { printf("Definition de boucle repeat est correcte\n");  }
#line 1775 "syntaxe.tab.c"
    break;

  case 88: /* $@3: %empty  */
#line 379 "syntaxe.y"
        {              
                        fprintf(fp, "Debut condition FOR - R1\n");
                        fprintf(fp, "debut-cnd-for := Qc \n"); //stocke debut-cnd
                        //stocke("debut-cnd-for", QC);
                        fprintf(fp, "******\n\n");
                        //QC++;
        }
#line 1787 "syntaxe.tab.c"
    break;

  case 89: /* $@4: %empty  */
#line 390 "syntaxe.y"
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
#line 1811 "syntaxe.tab.c"
    break;

  case 90: /* $@5: %empty  */
#line 410 "syntaxe.y"
                 {
                        fprintf(fp,"FOR-R2: Stocker debut d'incrementation\n");
                        fprintf(fp,"debut-inc := Qc \n"); // on stock debut_inc
                        //stocke("debut-inc", QC);
                }
#line 1821 "syntaxe.tab.c"
    break;

  case 91: /* $@6: %empty  */
#line 416 "syntaxe.y"
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
#line 1838 "syntaxe.tab.c"
    break;

  case 92: /* $@7: %empty  */
#line 430 "syntaxe.y"
        {      
                        fprintf(fp,"QUAD(sauv-debut-blok-for, 2) := Qc\n");  // on met à jour ce qui il pointe vers debut block
                                /*sprintf(c, "%d", QC);
                                char inter4[100] = "sauv-debut-blok-for:"; 
                                strcat( inter4,strdup(c) );
                                Quadreplets[restaure("sauv-debut-blok-for")][1] = strdup(inter4);
                                QC++; */
        }
#line 1851 "syntaxe.tab.c"
    break;

  case 93: /* for_struct: ITERATOR debut_paren init_index separ $@3 Condition_For $@4 separ $@5 incrementation $@6 fin_paren $@7 corp  */
#line 439 "syntaxe.y"
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
#line 1873 "syntaxe.tab.c"
    break;

  case 94: /* init_index: error  */
#line 458 "syntaxe.y"
                             { printf("Err, d'intilisation de boucle\n"); err++; return -1; }
#line 1879 "syntaxe.tab.c"
    break;

  case 95: /* init_index: ID AFFECTATION valeur  */
#line 460 "syntaxe.y"
                {
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[-2].str));
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");

                            if( strcmp(etat, "CONS") == 0 )  
                            {
                                printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);
                            }
                            if( strcmp(etat, "FCT") == 0 )  
                            {
                                printf("erreur Semantique: %s ne doit pas etre une fonction,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);
                            }
                            if( strcmp(etat, "PROC") == 0 )  
                            {
                                printf("erreur Semantique: %s ne doit pas etre une procedure,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);
                            } 
                            if( strcmp(etat, "VAR") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                strcpy(ID_for, (yyvsp[-2].str)); // on la recupere pour la verfication apres 
                                            }
                            } 
                        
                    }
                }
#line 1922 "syntaxe.tab.c"
    break;

  case 97: /* incrementation: error  */
#line 502 "syntaxe.y"
                                   { printf("Err, manque d'incrementation dans boucle iterator\n");  err++; return -1; }
#line 1928 "syntaxe.tab.c"
    break;

  case 99: /* Condition_For: error  */
#line 506 "syntaxe.y"
                                  { printf("Err, manque de condition de boucle iterator\n");  err++; return -1; }
#line 1934 "syntaxe.tab.c"
    break;

  case 100: /* Condition_For: ID SUPP expression  */
#line 508 "syntaxe.y"
                                {
                                    if(strcmp((yyvsp[-2].str), ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);  }
                                }
#line 1942 "syntaxe.tab.c"
    break;

  case 101: /* Condition_For: ID SUPP_EGAL expression  */
#line 512 "syntaxe.y"
                                {
                                    if(strcmp((yyvsp[-2].str), ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);  }
                                }
#line 1950 "syntaxe.tab.c"
    break;

  case 102: /* Condition_For: ID INF expression  */
#line 517 "syntaxe.y"
                                {
                                    if(strcmp((yyvsp[-2].str), ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);  }
                                }
#line 1958 "syntaxe.tab.c"
    break;

  case 103: /* Condition_For: ID INF_EGAL expression  */
#line 522 "syntaxe.y"
                                {
                                    if(strcmp((yyvsp[-2].str), ID_for) != 0 ){ printf("erreur Semantique: %s doit etre le meme que tu initaliser dans cette boucle,  a la ligne %d, le caractere %d\n", (yyvsp[-2].str), lignenum, nb_cara);  }
                                }
#line 1966 "syntaxe.tab.c"
    break;

  case 104: /* Appel_Methode: ID debut_paren valeur_param fin_paren fin_inst  */
#line 530 "syntaxe.y"
                                                                      { 
                
        NodeSymbole *x;
        x=search(ts, (yyvsp[-4].str));
        if(x == NULL) 
        {
            printf("erreur Semantique: %s methode non declare, a la ligne %d, a la colonne %d\n", (yyvsp[-4].str),  lignenum, nb_cara); 
        }
        else
        {
            char *etat= getAttribut(x,"Etat");
                        if( (strcmp(etat, "FCT") != 0 ) && (strcmp(etat, "PROC") != 0 ) )
                        {
                            printf("erreur Semantique: %s doit etre nom d'une methode (fonction ou procedure), a la ligne %d, a la colonne %d\n", (yyvsp[-4].str),  lignenum, nb_cara); 
                        }
                        else
                        {
                            printf("Appel methode effectuer\n");  
                        }
        }
        }
#line 1992 "syntaxe.tab.c"
    break;

  case 105: /* write_Proc: WRITE debut_paren valeur_param fin_paren fin_inst  */
#line 554 "syntaxe.y"
                                                                       { printf("Appel Write effectuer\n");  }
#line 1998 "syntaxe.tab.c"
    break;

  case 106: /* read_Proc: READ debut_paren parametre_read fin_paren fin_inst  */
#line 557 "syntaxe.y"
                                                                       { printf("Appel read effectuer\n");  }
#line 2004 "syntaxe.tab.c"
    break;

  case 111: /* parametre_read: ID  */
#line 568 "syntaxe.y"
        {
            NodeSymbole *x;
            x=search(ts, (yyvsp[0].str));
            if(x == NULL) {printf("erreur Semantique: %s non declare, a la ligne %d, a la colonne %d\n", (yyvsp[0].str),  lignenum, nb_cara);} 
            else
            {
                char *etat= getAttribut(x,"Etat");
                if(strcmp(etat, "VAR") == 0 )
                {
                    char *type= getAttribut(x,"Type");
                    if( strcmp(type, "t_str") != 0 )
                    { 
                        printf("erreur: %s ce variable qui va stocker valeur de read doit etre de type chaine de caractere, a la ligne %d, a la colonne %d\n", (yyvsp[0].str),  lignenum, nb_cara);
                    }
                }
                else
                {
                        printf("erreur semantique : %s ce variable doit etre des case memoires pour stocker valeur lue, a la ligne %d, a la colonne %d\n", (yyvsp[0].str),  lignenum, nb_cara);
                }
            
            }

        }
#line 2032 "syntaxe.tab.c"
    break;

  case 112: /* parametre_read: ID debut_tab ENTIER fin_tab  */
#line 593 "syntaxe.y"
        {
            NodeSymbole *x;
            x=search(ts, (yyvsp[-3].str));
            if(x == NULL) {printf("erreur Semantique: %s non declare, a la ligne %d, a la colonne %d\n", (yyvsp[-3].str),  lignenum, nb_cara);} 
            else
            {
                char *etat= getAttribut(x,"Etat");
                if(strcmp(etat, "TAB") == 0 )
                {
                    char *type= getAttribut(x,"Type");
                    if( strcmp(type, "t_str") != 0 )
                    { 
                        printf("erreur: %s ce variable qui va stocker valeur de read doit etre de type chaine de caractere, a la ligne %d, a la colonne %d\n", (yyvsp[-3].str),  lignenum, nb_cara);
                    }
                }
                else
                {
                        printf("erreur semantique : %s ce variable doit etre des case memoires pour stocker valeur lue, a la ligne %d, a la colonne %d\n", (yyvsp[-3].str),  lignenum, nb_cara);
                }
            
            }

        }
#line 2060 "syntaxe.tab.c"
    break;

  case 113: /* decalaration: type ID fin_inst  */
#line 621 "syntaxe.y"
{ 
          NodeSymbole *x;
           x=search(ts, (yyvsp[-1].str));
        
           if(x == NULL)
                {      
                    x=  insertSymbole(ts,(yyvsp[-1].str));
                    setAttribut(x, "Type", strdup((yyvsp[-2].str)) );
                    setAttribut(x, "Etat", "VAR");
                    printf("Declaration de variable est juste\n"); 
                    Afficher(ts);
                }
	        else  
            { 
                printf("erreur Semantique: double declaration d'un id  %s,  a la ligne %d, le caractere %d\n", (yyvsp[-1].str), lignenum, nb_cara);
            }
}
#line 2082 "syntaxe.tab.c"
    break;

  case 114: /* decalaration: type debut_tab ENTIER fin_tab ID fin_inst  */
#line 640 "syntaxe.y"
                { 
                 NodeSymbole *x;
                    x=search(ts, (yyvsp[-1].str));
                    
                    if(x == NULL)
                    {      
                        x =  insertSymbole(ts,(yyvsp[-1].str));
                            setAttribut(x, "Etat", "TAB");
                            setAttribut(x, "Type", (yyvsp[-5].str));
                        Afficher(ts); 

                            char size[50];
                            sprintf(size, "%d", (yyvsp[-3].entier));
                            setAttribut(x, "Size",size );
                            printf("Declaration de tableau est juste\n"); 
                            Afficher(ts); 
                    }

                    else  
                    { printf("erreur Semantique: double declaration d'un tableau  %s,  a la ligne %d, le caractere %d\n", (yyvsp[-1].str), lignenum, nb_cara);}
                
                }
#line 2109 "syntaxe.tab.c"
    break;

  case 115: /* decalaration: TYPE_CONS type ID fin_inst  */
#line 664 "syntaxe.y"
                { 
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[-1].str));
                    if(x == NULL)
                    {      
                        x =  insertSymbole(ts,(yyvsp[-1].str));
                            strcpy(t,"TAB");
                            setAttribut(x, "Type", (yyvsp[-2].str));
                            setAttribut(x, "Etat", "CONS");
                            printf("Declaration de constante est juste\n");  
                                    Afficher(ts);

                    }

                    else  
                    { printf("erreur Semantique: double declaration d'un tableau  %s,  a la ligne %d, le caractere %d\n", (yyvsp[-1].str), lignenum, nb_cara);}
                
                }
#line 2132 "syntaxe.tab.c"
    break;

  case 116: /* affec: ID AFFECTATION valeur fin_inst  */
#line 685 "syntaxe.y"
{ 
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[-3].str));
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");

                        if( strcmp(etat, "CONS") == 0 )  
                            {
                                printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            }

                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            } 

                        if( strcmp(etat, "PROC") == 0 )  
                            {
                            printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            }

                        if( strcmp(etat, "TAB") == 0 )  
                            {
                             printf("erreur Semantique: %s  est un nom de tableau faut sepecfie indice à acceder tu peut pas affcter valeur au tableau complet,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                printf("Affecation d'un variable  est juste\n"); 
                                                        Afficher(ts);

                                            }
                            } 
                }
}
#line 2183 "syntaxe.tab.c"
    break;

  case 117: /* affec: ID DEB_TABLEAU ENTIER FIN_TABLEAU AFFECTATION valeur fin_inst  */
#line 733 "syntaxe.y"
            { 
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[-6].str));
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                        if( strcmp(etat, "CONS") == 0 )  
                            {
                            printf("erreur Semantique: %s est une constante(tu peut changer sa valeur),  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                            } 
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                                printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                                     char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //acess a size
                                                int taille;
                                                taille = atoi(getAttribut(x,"Size"));
                                                printf(" taile == %d et val 3 = %d", taille, (yyvsp[-4].entier));
                                                if( (0<= (yyvsp[-4].entier)) &&((yyvsp[-4].entier) < taille) )
                                                {printf("Affecation d'un tableau juste\n"); }
                                                else
                                                {
                                                    printf("erreur Semantique: t'essaye d'acces a indice hors taille de tableau %s,  a la ligne %d, le caractere %d\n", (yyvsp[-6].str), lignenum, nb_cara);
                                                }
                                            }
                            } 

                        
                    }
            }
#line 2239 "syntaxe.tab.c"
    break;

  case 118: /* valeur: CHAINE  */
#line 789 "syntaxe.y"
                     {      strcpy(sonType , "t_str");  }
#line 2245 "syntaxe.tab.c"
    break;

  case 119: /* valeur: CARACTERE  */
#line 790 "syntaxe.y"
                         { strcpy(sonType , "t_car"); }
#line 2251 "syntaxe.tab.c"
    break;

  case 120: /* valeur: BOOLEAN_FAUX  */
#line 791 "syntaxe.y"
                            {strcpy(sonType , "t_bln");}
#line 2257 "syntaxe.tab.c"
    break;

  case 121: /* valeur: BOOLEAN_VRAI  */
#line 792 "syntaxe.y"
                            {strcpy(sonType , "t_bln");}
#line 2263 "syntaxe.tab.c"
    break;

  case 131: /* condition: error  */
#line 812 "syntaxe.y"
                    { printf("Err, condition est vide\n"); err++; return -1;}
#line 2269 "syntaxe.tab.c"
    break;

  case 143: /* expression: error  */
#line 829 "syntaxe.y"
                     { printf("Err, expression est vide\n"); err++; return -1; }
#line 2275 "syntaxe.tab.c"
    break;

  case 151: /* terme: ID  */
#line 840 "syntaxe.y"
                { 
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[0].str));
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: le variable %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", (yyvsp[0].str), lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                         if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est une fonction donc vous devez effecter un appel,  a la ligne %d, le caractere %d\n", (yyvsp[0].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est une procedure donc vous devez effecter un appel,  a la ligne %d, le caractere %d\n", (yyvsp[0].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                             printf("erreur Semantique: %s  est un nom de tableau faut sepecfie indice à acceder,  a la ligne %d, le caractere %d\n", (yyvsp[0].str), lignenum, nb_cara);
                            }
                        
                        if( (strcmp(etat, "CONS") == 0 )|| (  strcmp(etat, "VAR") == 0  ) )
                        {
                              char *type= getAttribut(x,"Type");
                                            if( (strcmp(type,"t_int")!=0) && (strcmp(type,"t_flt")!=0) )
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", (yyvsp[0].str), lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //printf("acces a un variable  est juste\n"); 
                                            }
                        }
                    }
                }
#line 2317 "syntaxe.tab.c"
    break;

  case 152: /* terme: ENTIER  */
#line 878 "syntaxe.y"
                 {strcpy(sonType , "t_int"); }
#line 2323 "syntaxe.tab.c"
    break;

  case 153: /* terme: FLOTTANT  */
#line 879 "syntaxe.y"
                   {strcpy(sonType , "t_flt");}
#line 2329 "syntaxe.tab.c"
    break;

  case 154: /* terme: ID debut_tab ENTIER fin_tab  */
#line 882 "syntaxe.y"
                {
                    { 
                    NodeSymbole *x;
                    x=search(ts, (yyvsp[-3].str));
                    
                    if(x == NULL)
                    {    
                        printf("erreur Semantique: le tableau %s non declare(il doit etre decalare),  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                    }
                    else{  
                        char *etat= getAttribut(x,"Etat");
                        if( strcmp(etat, "FCT") == 0 )  
                            {
                             printf("erreur Semantique: %s est declare comme une fonction tu peut l'affecter une valeur,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "PROC") == 0 )  
                            {
                             printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "VAR") == 0 )  
                            {
                            printf("erreur Semantique: %s  est declare comme une procedure tu peut l'affecter une valeu,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                            }
                        if( strcmp(etat, "TAB") == 0 )  
                            {
                                    char *type= getAttribut(x,"Type");
                                            if(strcmp(type,sonType)!=0)
                                            {
                                                printf("erreur Semantique: type de %s est incompatible : a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                                            }
                                            else
                                            {
                                                //acess a size
                                                int taille;
                                                taille = atoi(getAttribut(x,"Size"));
                                                if( 0<= (yyvsp[-1].entier) < taille )
                                                {printf("Affecation d'un tableau juste\n"); }
                                                else
                                                {
                                                    printf("erreur Semantique: t'essaye d'acces à indice hors taille de tableau %s,  a la ligne %d, le caractere %d\n", (yyvsp[-3].str), lignenum, nb_cara);
                                                }
                                            }
                            }

                        

                        
                    }
                }
            }
#line 2384 "syntaxe.tab.c"
    break;


#line 2388 "syntaxe.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 942 "syntaxe.y"


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



