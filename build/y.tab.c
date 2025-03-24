/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Identifier = 258,
     T_IntConstant = 259,
     T_std_function = 260,
     T_keyword = 261,
     T_operator = 262,
     T_int = 263,
     T_void = 264,
     T_return = 265,
     T_assign = 266,
     T_semicolon = 267,
     T_main = 268,
     T_Le = 269,
     T_Ge = 270,
     T_Eq = 271,
     T_Ne = 272,
     T_And = 273,
     T_Or = 274,
     T_if = 275,
     T_else = 276,
     T_while = 277,
     T_continue = 278,
     T_break = 279
   };
#endif
/* Tokens.  */
#define T_Identifier 258
#define T_IntConstant 259
#define T_std_function 260
#define T_keyword 261
#define T_operator 262
#define T_int 263
#define T_void 264
#define T_return 265
#define T_assign 266
#define T_semicolon 267
#define T_main 268
#define T_Le 269
#define T_Ge 270
#define T_Eq 271
#define T_Ne 272
#define T_And 273
#define T_Or 274
#define T_if 275
#define T_else 276
#define T_while 277
#define T_continue 278
#define T_break 279




/* Copy the first part of user declarations.  */
#line 1 "../src/parser.y"

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <set>
#include <stack>
#include <algorithm>
#include "../src/MIPS.h"
#include "../src/sign_table.hpp"
void yyerror(const char*);
int yylex(void);
#define YYSTYPE char *
std::string asm_src; //生成的汇编码
int searchAndCalculateOffset(const char* symbol,std::vector<std::string> sign_table);
extern "C" FILE* yyin;
std::set<SignTable *> functions;
SignTable* sign_table;
std::stack<int> loop_stack;
int loop_counter = 0;
int if_counter = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 176 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   365

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  147

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    35,    29,     2,
      39,    40,    33,    31,    41,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      26,    25,    27,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    28,    38,    42,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    14,    21,    23,    25,    28,
      32,    35,    40,    41,    44,    46,    48,    50,    52,    54,
      56,    58,    60,    62,    66,    68,    72,    76,    82,    87,
      91,    95,    98,   101,   104,   108,   110,   114,   124,   125,
     128,   138,   145,   146,   148,   149,   153,   154,   156,   163,
     166,   169,   173,   177,   181,   185,   189,   193,   197,   201,
     205,   209,   213,   217,   221,   225,   228,   231,   234,   236,
     238,   240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    44,    45,    -1,     8,    46,    47,
      37,    49,    38,    -1,     9,    46,    47,    37,    49,    38,
      -1,     3,    -1,    13,    -1,    39,    40,    -1,    39,    48,
      40,    -1,     8,     3,    -1,    48,    41,     8,     3,    -1,
      -1,    49,    50,    -1,    51,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    60,    -1,    66,    -1,    70,    -1,
      71,    -1,     8,    52,    12,    -1,     3,    -1,     3,    11,
      72,    -1,    52,    41,     3,    -1,    52,    41,     3,    11,
      72,    -1,     3,    11,    72,    12,    -1,    10,    72,    12,
      -1,     5,    58,    12,    -1,    57,    12,    -1,     3,    58,
      -1,    39,    40,    -1,    39,    59,    40,    -1,    72,    -1,
      72,    41,    59,    -1,    20,    39,    64,    40,    37,    49,
      38,    61,    62,    -1,    -1,    65,    63,    -1,    21,    20,
      39,    64,    40,    37,    49,    38,    62,    -1,    21,    65,
      37,    49,    38,    63,    -1,    -1,    72,    -1,    -1,    22,
      67,    69,    -1,    -1,    72,    -1,    39,    68,    40,    37,
      49,    38,    -1,    24,    12,    -1,    23,    12,    -1,    72,
      31,    72,    -1,    72,    32,    72,    -1,    72,    33,    72,
      -1,    72,    34,    72,    -1,    72,    35,    72,    -1,    72,
      27,    72,    -1,    72,    26,    72,    -1,    72,    15,    72,
      -1,    72,    14,    72,    -1,    72,    16,    72,    -1,    72,
      17,    72,    -1,    72,    19,    72,    -1,    72,    18,    72,
      -1,    72,    30,    72,    -1,    32,    72,    -1,    36,    72,
      -1,    42,    72,    -1,     4,    -1,     3,    -1,    57,    -1,
      39,    72,    40,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    57,    62,    63,    67,    79,    90,    91,
      95,   100,   109,   110,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   126,   135,   144,   154,   162,   174,   184,
     187,   196,   211,   243,   244,   248,   255,   268,   273,   275,
     276,   277,   281,   287,   296,   301,   305,   313,   320,   329,
     340,   353,   359,   365,   371,   377,   383,   389,   395,   402,
     409,   415,   421,   427,   433,   439,   447,   455,   462,   465,
     469,   470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Identifier", "T_IntConstant",
  "T_std_function", "T_keyword", "T_operator", "T_int", "T_void",
  "T_return", "T_assign", "T_semicolon", "T_main", "T_Le", "T_Ge", "T_Eq",
  "T_Ne", "T_And", "T_Or", "T_if", "T_else", "T_while", "T_continue",
  "T_break", "'='", "'<'", "'>'", "'|'", "'&'", "'^'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'!'", "'{'", "'}'", "'('", "')'", "','", "'~'", "$accept",
  "Program", "FuncDef", "FuncName", "Args", "_Args", "Stmts", "Stmt",
  "DeclStmt", "DeclList", "AssignStmt", "ReturnStmt", "StdFuncStmt",
  "FuncCallStmt", "FuncCallExpr", "Actuals", "_Actuals", "BranchStmt",
  "EndIf", "ElseStmts", "EndElseStmt", "TrueFalseExpressionIF", "ElseDO",
  "LoopStmt", "Cond", "TrueFalseExpressionLOOP", "WhileBody", "BreakStmt",
  "ContStmt", "E", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    61,    60,    62,   124,    38,
      94,    43,    45,    42,    47,    37,    33,   123,   125,    40,
      41,    44,   126
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    51,    52,    52,    52,    52,    53,    54,
      55,    56,    57,    58,    58,    59,    59,    60,    61,    62,
      62,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     6,     6,     1,     1,     2,     3,
       2,     4,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     3,     5,     4,     3,
       3,     2,     2,     2,     3,     1,     3,     9,     0,     2,
       9,     6,     0,     1,     0,     3,     0,     1,     6,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     1,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     3,     6,     7,     0,     0,
       0,     0,     0,     0,     8,     0,    12,    12,    10,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     4,    13,    14,    15,    16,    17,    18,     0,
      19,    20,    21,    22,     5,    11,     0,     0,    32,     0,
      24,     0,    69,    68,     0,     0,     0,     0,    70,     0,
       0,     0,    50,    49,    31,     0,    33,     0,    35,    30,
       0,    23,     0,    65,    66,     0,    67,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,    45,    28,    34,     0,    25,
      26,    71,    59,    58,    60,    61,    63,    62,    57,    56,
      64,    51,    52,    53,    54,    55,     0,     0,    47,    36,
       0,    12,     0,    27,     0,    12,    38,     0,    44,    48,
      44,    37,    42,     0,     0,    39,     0,    12,     0,     0,
       0,    42,    12,    41,     0,    44,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     5,     8,    11,    15,    21,    33,    34,    51,
      35,    36,    37,    38,    58,    48,    67,    40,   128,   131,
     135,    92,   132,    41,    61,   117,    95,    42,    43,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -31
static const yytype_int16 yypact[] =
{
     -31,    10,   -31,    -1,    -1,   -31,   -31,   -31,   -30,   -30,
       0,   -21,   -10,     8,   -31,    41,   -31,   -31,   -31,   -31,
      24,    64,    75,    33,    -6,     2,    68,    34,    36,   -31,
      65,    67,   -31,   -31,   -31,   -31,   -31,   -31,   -31,    77,
     -31,   -31,   -31,   -31,   -31,   -31,    34,     3,   -31,    78,
      80,     5,     2,   -31,    34,    34,    34,    34,   -31,   230,
      34,    53,   -31,   -31,   -31,   254,   -31,    56,   175,   -31,
      34,   -31,    90,   -20,   -31,   203,   276,   -31,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    60,   276,    34,   -31,   -31,   -31,    34,   276,
      92,   -31,    -9,    -9,   330,   330,   320,   298,    -9,    -9,
      16,   -20,   -20,   -31,   -31,   -31,    70,    61,   276,   -31,
      34,   -31,    74,   276,   109,   -31,   -31,   131,    84,   -31,
      95,   -31,   -31,    79,    85,   -31,    34,   -31,    76,   140,
      86,   -31,   -31,   -31,   162,    84,   -31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   120,   118,   -31,   -17,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,   -18,   103,    32,   -31,   -31,    -8,
      -3,     4,    12,   -31,   -31,   -31,   -31,   -31,   -31,   -26
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,    59,     6,    39,    39,    46,    52,    53,    13,    10,
       2,    18,     7,    89,    90,    91,    16,    71,     3,     4,
      65,    86,    87,    88,    89,    90,    91,    17,    73,    74,
      75,    76,    23,    47,    93,    54,    45,    52,    53,    55,
      14,    47,    56,    66,    99,    57,    72,    87,    88,    89,
      90,    91,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    54,    24,   118,    25,
      55,    50,    26,    56,    27,    60,    57,    62,    24,    63,
      25,    19,    20,    26,    28,    27,    29,    30,    31,    64,
      69,    70,    94,   100,   123,    28,    97,    29,    30,    31,
     116,   122,    32,   120,   124,   130,    39,   121,   127,    39,
      93,   125,    24,    44,    25,   133,   140,    26,   136,    27,
     139,    39,   137,   142,     9,   144,    39,    12,    49,    28,
     119,    29,    30,    31,    24,     0,    25,   146,   143,    26,
     138,    27,   134,    24,     0,    25,     0,   126,    26,     0,
      27,    28,     0,    29,    30,    31,     0,     0,     0,     0,
      28,     0,    29,    30,    31,    24,     0,    25,     0,   129,
      26,     0,    27,     0,     0,     0,     0,     0,   141,     0,
       0,     0,    28,     0,    29,    30,    31,     0,     0,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,     0,
     145,    84,    85,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,    98,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,    84,
      85,     0,     0,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    77,   101,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91,    96,     0,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    91,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
       0,     0,    84,    85,     0,     0,    86,    87,    88,    89,
      90,    91,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,    86,    87,
      88,    89,    90,    91,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    78,    79,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91,    84,    85,     0,     0,
      86,    87,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      17,    27,     3,    21,    22,    11,     3,     4,     8,    39,
       0,     3,    13,    33,    34,    35,    37,    12,     8,     9,
      46,    30,    31,    32,    33,    34,    35,    37,    54,    55,
      56,    57,     8,    39,    60,    32,     3,     3,     4,    36,
      40,    39,    39,    40,    70,    42,    41,    31,    32,    33,
      34,    35,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    32,     3,    94,     5,
      36,     3,     8,    39,    10,    39,    42,    12,     3,    12,
       5,    40,    41,     8,    20,    10,    22,    23,    24,    12,
      12,    11,    39,     3,   120,    20,    40,    22,    23,    24,
      40,    40,    38,    11,   121,    21,   124,    37,   125,   127,
     136,    37,     3,    38,     5,    20,    40,     8,    39,    10,
     137,   139,    37,    37,     4,   142,   144,     9,    25,    20,
      98,    22,    23,    24,     3,    -1,     5,   145,   141,     8,
     136,    10,   130,     3,    -1,     5,    -1,    38,     8,    -1,
      10,    20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      20,    -1,    22,    23,    24,     3,    -1,     5,    -1,    38,
       8,    -1,    10,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    20,    -1,    22,    23,    24,    -1,    -1,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      38,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    12,    40,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    35,    12,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    32,    33,    34,    35,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,
      32,    33,    34,    35,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    35,    26,    27,    -1,    -1,
      30,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,     0,     8,     9,    45,     3,    13,    46,    46,
      39,    47,    47,     8,    40,    48,    37,    37,     3,    40,
      41,    49,    49,     8,     3,     5,     8,    10,    20,    22,
      23,    24,    38,    50,    51,    53,    54,    55,    56,    57,
      60,    66,    70,    71,    38,     3,    11,    39,    58,    58,
       3,    52,     3,     4,    32,    36,    39,    42,    57,    72,
      39,    67,    12,    12,    12,    72,    40,    59,    72,    12,
      11,    12,    41,    72,    72,    72,    72,    12,    14,    15,
      16,    17,    18,    19,    26,    27,    30,    31,    32,    33,
      34,    35,    64,    72,    39,    69,    12,    40,    41,    72,
       3,    40,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    40,    68,    72,    59,
      11,    37,    40,    72,    49,    37,    38,    49,    61,    38,
      21,    62,    65,    20,    65,    63,    39,    37,    64,    49,
      40,    38,    37,    63,    49,    38,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 56 "../src/parser.y"
    { /*end of program?*/ }
    break;

  case 3:
#line 57 "../src/parser.y"
    { /* empty */ }
    break;

  case 4:
#line 62 "../src/parser.y"
    { FUNC_RETURN();}
    break;

  case 5:
#line 63 "../src/parser.y"
    { FUNC_RETURN(); }
    break;

  case 6:
#line 67 "../src/parser.y"
    { 
        intermediate_code+= std::string((yyvsp[(1) - (1)]))+":\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        intermediate_code += "sw $ra, 0($sp)\n";
        intermediate_code += "sw $fp, 4($sp)\n";
        intermediate_code += "move $fp, $sp\n";
        intermediate_code += "addiu $sp, $sp, -0x100\n"; //这里是多少其实不重要🤔，只要大于local var的数目就好
        sign_table = new SignTable(std::string((yyvsp[(1) - (1)])));
        intermediate_code+=sign_table->printSignTable();
        functions.insert(sign_table);
        debug_log<<"FUNC @"<<std::string((yyvsp[(1) - (1)]))<<":\n";
        }
    break;

  case 7:
#line 79 "../src/parser.y"
    {
        MAIN(); 
        sign_table = new SignTable(std::string("main"));
        intermediate_code+=sign_table->printSignTable();
        functions.insert(sign_table);
    }
    break;

  case 8:
#line 90 "../src/parser.y"
    { /*printf("args empty");*/ }
    break;

  case 9:
#line 91 "../src/parser.y"
    { debug_log<<"ARGLIST:"<<" \n";}
    break;

  case 10:
#line 95 "../src/parser.y"
    {
        sign_table->addSymbol(Symbol(SymbolType::FUNC_ARG,std::string((yyvsp[(2) - (2)]))));
        intermediate_code+=sign_table->printSignTable();
        debug_log<<" "<<std::string((yyvsp[(2) - (2)]))<<" \n";
    }
    break;

  case 11:
#line 100 "../src/parser.y"
    { 
        sign_table->addSymbol(Symbol(SymbolType::FUNC_ARG,std::string((yyvsp[(4) - (4)]))));
        intermediate_code+=sign_table->printSignTable();
        debug_log<<" "<<std::string((yyvsp[(4) - (4)]))<<" \n";
    }
    break;

  case 12:
#line 109 "../src/parser.y"
    { /* empty */ }
    break;

  case 13:
#line 110 "../src/parser.y"
    { /* empty */ }
    break;

  case 23:
#line 126 "../src/parser.y"
    { 
    intermediate_code += "# this is a DeclStmt\n";
    //sign_table.push_back($2);//todo char* 2 std::string，但是好像发现打印出来是正常的，先不管了
    //printf("sw $zero,%d($fp)\n",(sign_table.size()*-4)); //这里不能按warning操作，否则有问题
    //printSignTable(sign_table);
    //交给DeclList处理
    intermediate_code += "\n";
}
    break;

  case 24:
#line 135 "../src/parser.y"
    { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string((yyvsp[(1) - (1)]))));
    intermediate_code+=sign_table->printSignTable();
    //通过类型转换避免错误😠
    intermediate_code += "sw $zero, " + std::to_string(-(static_cast<int64_t>(sign_table->size()) * 4)) + "($fp)\n";
    intermediate_code += "# end of DeclList\n\n";
    debug_log<<"var "<<std::string((yyvsp[(1) - (1)]))<<"\n";
}
    break;

  case 25:
#line 144 "../src/parser.y"
    { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string((yyvsp[(1) - (3)]))));
    intermediate_code+=sign_table->printSignTable();
    int offset=sign_table->searchAndCalculateOffset(std::string((yyvsp[(1) - (3)])));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    intermediate_code += "# end of DeclList\n\n";
    debug_log<<"assign "<<std::string((yyvsp[(1) - (3)]))<<"=\n";
}
    break;

  case 26:
#line 154 "../src/parser.y"
    { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string((yyvsp[(3) - (3)]))));
    intermediate_code+=sign_table->printSignTable();
    intermediate_code += "sw $zero, " + std::to_string(-(static_cast<int64_t>(sign_table->size()) * 4)) + "($fp)\n";
    debug_log<<"var "<<std::string((yyvsp[(3) - (3)]))<<"\n";
    intermediate_code += "# end of DeclList\n\n";
}
    break;

  case 27:
#line 162 "../src/parser.y"
    { 
    intermediate_code += "# this is a DeclStmt\n";
    sign_table->addSymbol(Symbol(SymbolType::LOCAL_VAR,std::string((yyvsp[(3) - (5)]))));
    intermediate_code+=sign_table->printSignTable();
    int offset=sign_table->searchAndCalculateOffset(std::string((yyvsp[(3) - (5)])));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    debug_log<<"assign "<<std::string((yyvsp[(3) - (5)]))<<"=\n";
    intermediate_code += "# end of DeclList\n\n";
}
    break;

  case 28:
#line 174 "../src/parser.y"
    { 
    intermediate_code += "# start of assign stmt\n";
    int offset=sign_table->searchAndCalculateOffset(std::string((yyvsp[(2) - (4)])));
    MIPS_POP("$v0");
    intermediate_code += "sw $v0," + std::to_string(offset) + "($fp)\n";
    intermediate_code += "\n";
    intermediate_code += "# end of assign stmt\n";
    debug_log<<"assign "<<std::string((yyvsp[(1) - (4)]))<<"=\n";
}
    break;

  case 29:
#line 184 "../src/parser.y"
    {MIPS_POP("$v0");}
    break;

  case 30:
#line 187 "../src/parser.y"
    { 
    /*从栈中获取参数*/
    MIPS_POP("$a0");
    PRINT();
    debug_log<<"print"<<"\n";
}
    break;

  case 31:
#line 196 "../src/parser.y"
    { 
        //printf("jal %s\n",$1); ->这里是不是$1是空的😨
        //std::vector<std::pair<SymbolType, std::string>> sign_table_main; //不确定
        //FUNC_RETURN();  这是函数定义里的return，而不是实际的return
        
        //std::string identifier = std::string("sign_table_") + $1;
        //sign_table = frames[identifier];
        //frame_stack.push(sign_table);
        //std::cout<<"# "<<identifier<<std::endl;
        intermediate_code+=sign_table->printSignTable();
        debug_log<<"call";
    }
    break;

  case 32:
#line 211 "../src/parser.y"
    { 
        debug_log << "function " << std::string((yyvsp[(1) - (2)])) << "\n";
        intermediate_code += "jal " + std::string((yyvsp[(1) - (2)])) + "\n";
        intermediate_code += sign_table->printSignTable();

        // 计算被调用者参数的数目,计算 return 需要清理的 stack 空间
        int calleeParamCount = sign_table->get_nums_func_arg();
        
        // 查找上一个函数的 SignTable
        std::string prevFunctionName = std::string((yyvsp[(1) - (2)]));
        bool found = false;
        SignTable* prev_sign_table = nullptr;
        for (auto it = functions.begin(); it != functions.end(); ++it) {
            if ((*it)->getIdentifier() == prevFunctionName) {
                prev_sign_table = *it;
                found = true;
                break;
            }
        }
        if (found) {
            int prevParamCount = prev_sign_table->get_nums_func_arg();
            
            intermediate_code += "# 生成清理 stack 的指令\n";
            intermediate_code += "addiu $sp, $sp, " + std::to_string(prevParamCount * 4) + "\n";
            //push ?
            intermediate_code += "sw $v0, 0($sp)\n";
            intermediate_code += "addiu $sp, $sp, -4\n";
        }
    }
    break;

  case 33:
#line 243 "../src/parser.y"
    {  }
    break;

  case 34:
#line 244 "../src/parser.y"
    { }
    break;

  case 35:
#line 248 "../src/parser.y"
    {
        intermediate_code += "### Passing the arguments " + std::string((yyvsp[(1) - (1)])) + "\n\n";
        MIPS_POP("$v0");
        intermediate_code += "sw $v0, 0($sp)\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        debug_log<<std::string((yyvsp[(1) - (1)]))<<"\n";
    }
    break;

  case 36:
#line 255 "../src/parser.y"
    {
        intermediate_code += "### Passing the arguments " + std::string((yyvsp[(1) - (3)])) + "\n";
        MIPS_POP("$v0");
        intermediate_code += "sw $v0, 0($sp)\n";
        intermediate_code += "addiu $sp, $sp, -4\n";
        intermediate_code += "### End of passing the arguments \n";
        debug_log<<std::string((yyvsp[(1) - (3)]))<<"\n";
    }
    break;

  case 37:
#line 268 "../src/parser.y"
    { 
        debug_log<<"if stmt"<<"\n"; 
    }
    break;

  case 38:
#line 273 "../src/parser.y"
    { intermediate_code+="j $if_end_"+ std::to_string(if_counter) + ";\n";}
    break;

  case 39:
#line 275 "../src/parser.y"
    {/*else有可能为空，但是打tag的两个空推导不能删除🤔*/}
    break;

  case 40:
#line 276 "../src/parser.y"
    {/*理论上分支语句的中间可以叠加无限的else if，但是先暂时不写这部分*/}
    break;

  case 41:
#line 277 "../src/parser.y"
    { }
    break;

  case 42:
#line 281 "../src/parser.y"
    {
    intermediate_code+="#tag\n";
    intermediate_code += "$if_end_"+ std::to_string(if_counter) + ":\n";  
}
    break;

  case 43:
#line 287 "../src/parser.y"
    {
    //用栈顶数值判断if语句是否成立
    MIPS_POP("$t0");
    if_counter++;
    //if t0==0，即上面seq不相等，goto $if_else_1 else continue
    intermediate_code+="beq $t0, $zero, $if_else_"+ std::to_string(if_counter) + ";\n";
}
    break;

  case 44:
#line 296 "../src/parser.y"
    { 
    intermediate_code+="#tag\n";
    intermediate_code += "$if_else_"+ std::to_string(if_counter) + ":\n"; 
}
    break;

  case 45:
#line 301 "../src/parser.y"
    {
    debug_log<<"LoopCond"<<"\n"; 
}
    break;

  case 46:
#line 305 "../src/parser.y"
    { 
    loop_counter++;
    loop_stack.push(loop_counter);
    intermediate_code+="#tag\n";
    intermediate_code+="$while_cond_" + std::to_string(loop_counter) + ":\n"; 
}
    break;

  case 47:
#line 313 "../src/parser.y"
    {
    //用栈顶数值判断if语句是否成立
    MIPS_POP("$t0");
    //if t0==0，即上面seq不相等，goto $if_else_loop_counter else continue
    intermediate_code+="beq $t0, $zero, $while_end_" + std::to_string(loop_counter) + "\n";
}
    break;

  case 48:
#line 320 "../src/parser.y"
    { 
    debug_log<<"EndLoopBody"<<"\n"; 
    intermediate_code += "j $while_cond_" + std::to_string(loop_stack.top()) + "\n";
    
    intermediate_code+="#tag\n";
    intermediate_code += "$while_end_" + std::to_string(loop_stack.top()) + ":\n";
    loop_stack.pop();
}
    break;

  case 49:
#line 329 "../src/parser.y"
    {
    //check if is in loop
    if(loop_stack.empty()){
        intermediate_code +="Break error";
        std::exit(1);
    }else{
        intermediate_code+="# break stmt\n";
        intermediate_code += "j $while_end_" + std::to_string(loop_stack.top()) + ";\n";
    }
}
    break;

  case 50:
#line 340 "../src/parser.y"
    {
        //check if is in loop
    if(loop_stack.empty()){
        intermediate_code +="Continue error";
        std::exit(1);
    }else{
        intermediate_code+="# Continue stmt\n";
        intermediate_code += "j $while_cond_" + std::to_string(loop_stack.top()) + ";\n";
    }
}
    break;

  case 51:
#line 353 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "add $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tadd\n";
}
    break;

  case 52:
#line 359 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "sub $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tsub\n";
}
    break;

  case 53:
#line 365 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "mul $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tmul\n";
}
    break;

  case 54:
#line 371 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "div $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tdiv\n";
}
    break;

  case 55:
#line 377 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "rem $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\trem\n";
}
    break;

  case 56:
#line 383 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t1, $t0\n";
    EVAL_AFTER();
    debug_log << "\tgt\n";
}
    break;

  case 57:
#line 389 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tlt\n";
}
    break;

  case 58:
#line 395 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t0, $t1\n";
    intermediate_code += "xori $t0, $t0, 1\n";
    EVAL_AFTER();
    debug_log << "\tge\n";
}
    break;

  case 59:
#line 402 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "slt $t0, $t1, $t0\n";
    intermediate_code += "xori $t0, $t0, 1\n";
    EVAL_AFTER();
    debug_log << "\tle\n";
}
    break;

  case 60:
#line 409 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "seq $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\teq\n";
}
    break;

  case 61:
#line 415 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "sne $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tne\n";
}
    break;

  case 62:
#line 421 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "or $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tor\n";
}
    break;

  case 63:
#line 427 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "and $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\tand\n";
}
    break;

  case 64:
#line 433 "../src/parser.y"
    {
    EVAL_PRE();
    intermediate_code += "xor $t0, $t0, $t1\n";
    EVAL_AFTER();
    debug_log << "\txor\n";
}
    break;

  case 65:
#line 439 "../src/parser.y"
    {
    MIPS_POP("$t0");
    intermediate_code += "sub $t0, $zero, $t0\n";
    //push t0 into stack
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tnegation\n";
}
    break;

  case 66:
#line 447 "../src/parser.y"
    {
    MIPS_POP("$t0");
    intermediate_code += "beq $t0, $zero, is_zero\nli $t0, 0  # 操作数不为 0,则结果为 0\nj end_not\nis_zero:\nli $t0, 1  # 操作数为 0,则结果为 1\nend_not:\n";
    //push t0 into stack
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tlogical not\n";
}
    break;

  case 67:
#line 455 "../src/parser.y"
    {
    MIPS_POP("$t0");
    intermediate_code += "nor $t0, $t0, $zero\n";
    intermediate_code += "sw $t0, 0($sp)\n";
    intermediate_code += "addiu $sp, $sp, -4\n";
    debug_log << "\tbitwise not\n";
}
    break;

  case 68:
#line 462 "../src/parser.y"
    { 
    MIPS_PUSH_CONST((yyvsp[(1) - (1)]));
}
    break;

  case 69:
#line 465 "../src/parser.y"
    { 
    int offset = sign_table->searchAndCalculateOffset(std::string((yyvsp[(1) - (1)]))); 
    MIPS_PUSH_VARS(offset);
}
    break;

  case 71:
#line 470 "../src/parser.y"
    { /* empty */ }
    break;


/* Line 1267 of yacc.c.  */
#line 2118 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 473 "../src/parser.y"



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "未提供源代码文件名." << std::endl;
        return 0;
    }
    std::string filename = argv[1];  // 获取文件名
    yyin = fopen(filename.c_str(), "r");
    // 缓存yyparse的结果
    
    yyparse();

    // 打印符号表
    for (const auto& signTable : functions) {
        std::cout << ".globl " << signTable->getIdentifier() << std::endl;
    }
    //打印data字段
    std::cout<<".data\nnewline: .asciiz \"\\n\"\n.text\n";
    //删除最后五行，即main不使用和其他函数一样的return🤔 -> 所以return最好不要有注释？
    // 1. 找到最后 5 行的起始位置
    size_t start_pos = intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n", intermediate_code.find_last_of("\n") - 1) - 1) - 1);
    // 2. 删除最后 5 行
    intermediate_code.erase(start_pos);
    std::cout<<intermediate_code;
    //退出程序
    std::cout<<"\nli $v0, 10\nsyscall\n";
    return 0;
}
