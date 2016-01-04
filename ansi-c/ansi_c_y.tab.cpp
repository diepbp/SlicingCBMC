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

/* Substitute the variable and function names.  */
#define yyparse yyansi_cparse
#define yylex   yyansi_clex
#define yyerror yyansi_cerror
#define yylval  yyansi_clval
#define yychar  yyansi_cchar
#define yydebug yyansi_cdebug
#define yynerrs yyansi_cnerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_AUTO = 258,
     TOK_BOOL = 259,
     TOK_COMPLEX = 260,
     TOK_BREAK = 261,
     TOK_CASE = 262,
     TOK_CHAR = 263,
     TOK_CONST = 264,
     TOK_CONTINUE = 265,
     TOK_DEFAULT = 266,
     TOK_DO = 267,
     TOK_DOUBLE = 268,
     TOK_ELSE = 269,
     TOK_ENUM = 270,
     TOK_EXTERN = 271,
     TOK_FLOAT = 272,
     TOK_FOR = 273,
     TOK_GOTO = 274,
     TOK_IF = 275,
     TOK_INLINE = 276,
     TOK_INT = 277,
     TOK_LONG = 278,
     TOK_REGISTER = 279,
     TOK_RESTRICT = 280,
     TOK_RETURN = 281,
     TOK_SHORT = 282,
     TOK_SIGNED = 283,
     TOK_SIZEOF = 284,
     TOK_STATIC = 285,
     TOK_STRUCT = 286,
     TOK_SWITCH = 287,
     TOK_TYPEDEF = 288,
     TOK_UNION = 289,
     TOK_UNSIGNED = 290,
     TOK_VOID = 291,
     TOK_VOLATILE = 292,
     TOK_WCHAR_T = 293,
     TOK_WHILE = 294,
     TOK_ARROW = 295,
     TOK_INCR = 296,
     TOK_DECR = 297,
     TOK_SHIFTLEFT = 298,
     TOK_SHIFTRIGHT = 299,
     TOK_LE = 300,
     TOK_GE = 301,
     TOK_EQ = 302,
     TOK_NE = 303,
     TOK_ANDAND = 304,
     TOK_OROR = 305,
     TOK_ELLIPSIS = 306,
     TOK_MULTASSIGN = 307,
     TOK_DIVASSIGN = 308,
     TOK_MODASSIGN = 309,
     TOK_PLUSASSIGN = 310,
     TOK_MINUSASSIGN = 311,
     TOK_SHLASSIGN = 312,
     TOK_SHRASSIGN = 313,
     TOK_ANDASSIGN = 314,
     TOK_XORASSIGN = 315,
     TOK_ORASSIGN = 316,
     TOK_IDENTIFIER = 317,
     TOK_TYPEDEFNAME = 318,
     TOK_INTEGER = 319,
     TOK_FLOATING = 320,
     TOK_CHARACTER = 321,
     TOK_STRING = 322,
     TOK_ASM_STRING = 323,
     TOK_INT8 = 324,
     TOK_INT16 = 325,
     TOK_INT32 = 326,
     TOK_INT64 = 327,
     TOK_PTR32 = 328,
     TOK_PTR64 = 329,
     TOK_TYPEOF = 330,
     TOK_GCC_AUTO_TYPE = 331,
     TOK_GCC_FLOAT80 = 332,
     TOK_GCC_FLOAT128 = 333,
     TOK_GCC_INT128 = 334,
     TOK_GCC_DECIMAL32 = 335,
     TOK_GCC_DECIMAL64 = 336,
     TOK_GCC_DECIMAL128 = 337,
     TOK_GCC_ASM = 338,
     TOK_GCC_ASM_PAREN = 339,
     TOK_GCC_ATTRIBUTE = 340,
     TOK_GCC_ATTRIBUTE_ALIGNED = 341,
     TOK_GCC_ATTRIBUTE_TRANSPARENT_UNION = 342,
     TOK_GCC_ATTRIBUTE_PACKED = 343,
     TOK_GCC_ATTRIBUTE_VECTOR_SIZE = 344,
     TOK_GCC_ATTRIBUTE_MODE = 345,
     TOK_GCC_ATTRIBUTE_GNU_INLINE = 346,
     TOK_GCC_ATTRIBUTE_END = 347,
     TOK_GCC_LABEL = 348,
     TOK_MSC_ASM = 349,
     TOK_MSC_BASED = 350,
     TOK_CW_VAR_ARG_TYPEOF = 351,
     TOK_BUILTIN_VA_ARG = 352,
     TOK_GCC_BUILTIN_TYPES_COMPATIBLE_P = 353,
     TOK_OFFSETOF = 354,
     TOK_ALIGNOF = 355,
     TOK_MSC_TRY = 356,
     TOK_MSC_FINALLY = 357,
     TOK_MSC_EXCEPT = 358,
     TOK_MSC_LEAVE = 359,
     TOK_MSC_DECLSPEC = 360,
     TOK_INTERFACE = 361,
     TOK_CDECL = 362,
     TOK_STDCALL = 363,
     TOK_FASTCALL = 364,
     TOK_CLRCALL = 365,
     TOK_FORALL = 366,
     TOK_EXISTS = 367,
     TOK_ACSL_FORALL = 368,
     TOK_ACSL_EXISTS = 369,
     TOK_ARRAY_OF = 370,
     TOK_CPROVER_BITVECTOR = 371,
     TOK_CPROVER_FLOATBV = 372,
     TOK_CPROVER_FIXEDBV = 373,
     TOK_CPROVER_ATOMIC = 374,
     TOK_CPROVER_BOOL = 375,
     TOK_CPROVER_THROW = 376,
     TOK_CPROVER_CATCH = 377,
     TOK_CPROVER_TRY = 378,
     TOK_CPROVER_FINALLY = 379,
     TOK_IMPLIES = 380,
     TOK_EQUIVALENT = 381,
     TOK_TRUE = 382,
     TOK_FALSE = 383,
     TOK_REAL = 384,
     TOK_IMAG = 385,
     TOK_ALIGNAS = 386,
     TOK_ATOMIC_TYPE_QUALIFIER = 387,
     TOK_ATOMIC_TYPE_SPECIFIER = 388,
     TOK_GENERIC = 389,
     TOK_IMAGINARY = 390,
     TOK_NORETURN = 391,
     TOK_STATIC_ASSERT = 392,
     TOK_THREAD_LOCAL = 393,
     TOK_NULLPTR = 394,
     TOK_CONSTEXPR = 395,
     TOK_SCANNER_ERROR = 396,
     TOK_SCANNER_EOF = 397,
     TOK_CATCH = 398,
     TOK_CHAR16_T = 399,
     TOK_CHAR32_T = 400,
     TOK_CLASS = 401,
     TOK_DELETE = 402,
     TOK_DECLTYPE = 403,
     TOK_EXPLICIT = 404,
     TOK_FRIEND = 405,
     TOK_MUTABLE = 406,
     TOK_NAMESPACE = 407,
     TOK_NEW = 408,
     TOK_NOEXCEPT = 409,
     TOK_OPERATOR = 410,
     TOK_PRIVATE = 411,
     TOK_PROTECTED = 412,
     TOK_PUBLIC = 413,
     TOK_TEMPLATE = 414,
     TOK_THIS = 415,
     TOK_THROW = 416,
     TOK_TYPEID = 417,
     TOK_TYPENAME = 418,
     TOK_TRY = 419,
     TOK_USING = 420,
     TOK_VIRTUAL = 421,
     TOK_SCOPE = 422,
     TOK_DOTPM = 423,
     TOK_ARROWPM = 424,
     TOK_MSC_UNARY_TYPE_PREDICATE = 425,
     TOK_MSC_BINARY_TYPE_PREDICATE = 426,
     TOK_MSC_UUIDOF = 427,
     TOK_MSC_IF_EXISTS = 428,
     TOK_MSC_IF_NOT_EXISTS = 429,
     TOK_MSC_UNDERLYING_TYPE = 430
   };
#endif
/* Tokens.  */
#define TOK_AUTO 258
#define TOK_BOOL 259
#define TOK_COMPLEX 260
#define TOK_BREAK 261
#define TOK_CASE 262
#define TOK_CHAR 263
#define TOK_CONST 264
#define TOK_CONTINUE 265
#define TOK_DEFAULT 266
#define TOK_DO 267
#define TOK_DOUBLE 268
#define TOK_ELSE 269
#define TOK_ENUM 270
#define TOK_EXTERN 271
#define TOK_FLOAT 272
#define TOK_FOR 273
#define TOK_GOTO 274
#define TOK_IF 275
#define TOK_INLINE 276
#define TOK_INT 277
#define TOK_LONG 278
#define TOK_REGISTER 279
#define TOK_RESTRICT 280
#define TOK_RETURN 281
#define TOK_SHORT 282
#define TOK_SIGNED 283
#define TOK_SIZEOF 284
#define TOK_STATIC 285
#define TOK_STRUCT 286
#define TOK_SWITCH 287
#define TOK_TYPEDEF 288
#define TOK_UNION 289
#define TOK_UNSIGNED 290
#define TOK_VOID 291
#define TOK_VOLATILE 292
#define TOK_WCHAR_T 293
#define TOK_WHILE 294
#define TOK_ARROW 295
#define TOK_INCR 296
#define TOK_DECR 297
#define TOK_SHIFTLEFT 298
#define TOK_SHIFTRIGHT 299
#define TOK_LE 300
#define TOK_GE 301
#define TOK_EQ 302
#define TOK_NE 303
#define TOK_ANDAND 304
#define TOK_OROR 305
#define TOK_ELLIPSIS 306
#define TOK_MULTASSIGN 307
#define TOK_DIVASSIGN 308
#define TOK_MODASSIGN 309
#define TOK_PLUSASSIGN 310
#define TOK_MINUSASSIGN 311
#define TOK_SHLASSIGN 312
#define TOK_SHRASSIGN 313
#define TOK_ANDASSIGN 314
#define TOK_XORASSIGN 315
#define TOK_ORASSIGN 316
#define TOK_IDENTIFIER 317
#define TOK_TYPEDEFNAME 318
#define TOK_INTEGER 319
#define TOK_FLOATING 320
#define TOK_CHARACTER 321
#define TOK_STRING 322
#define TOK_ASM_STRING 323
#define TOK_INT8 324
#define TOK_INT16 325
#define TOK_INT32 326
#define TOK_INT64 327
#define TOK_PTR32 328
#define TOK_PTR64 329
#define TOK_TYPEOF 330
#define TOK_GCC_AUTO_TYPE 331
#define TOK_GCC_FLOAT80 332
#define TOK_GCC_FLOAT128 333
#define TOK_GCC_INT128 334
#define TOK_GCC_DECIMAL32 335
#define TOK_GCC_DECIMAL64 336
#define TOK_GCC_DECIMAL128 337
#define TOK_GCC_ASM 338
#define TOK_GCC_ASM_PAREN 339
#define TOK_GCC_ATTRIBUTE 340
#define TOK_GCC_ATTRIBUTE_ALIGNED 341
#define TOK_GCC_ATTRIBUTE_TRANSPARENT_UNION 342
#define TOK_GCC_ATTRIBUTE_PACKED 343
#define TOK_GCC_ATTRIBUTE_VECTOR_SIZE 344
#define TOK_GCC_ATTRIBUTE_MODE 345
#define TOK_GCC_ATTRIBUTE_GNU_INLINE 346
#define TOK_GCC_ATTRIBUTE_END 347
#define TOK_GCC_LABEL 348
#define TOK_MSC_ASM 349
#define TOK_MSC_BASED 350
#define TOK_CW_VAR_ARG_TYPEOF 351
#define TOK_BUILTIN_VA_ARG 352
#define TOK_GCC_BUILTIN_TYPES_COMPATIBLE_P 353
#define TOK_OFFSETOF 354
#define TOK_ALIGNOF 355
#define TOK_MSC_TRY 356
#define TOK_MSC_FINALLY 357
#define TOK_MSC_EXCEPT 358
#define TOK_MSC_LEAVE 359
#define TOK_MSC_DECLSPEC 360
#define TOK_INTERFACE 361
#define TOK_CDECL 362
#define TOK_STDCALL 363
#define TOK_FASTCALL 364
#define TOK_CLRCALL 365
#define TOK_FORALL 366
#define TOK_EXISTS 367
#define TOK_ACSL_FORALL 368
#define TOK_ACSL_EXISTS 369
#define TOK_ARRAY_OF 370
#define TOK_CPROVER_BITVECTOR 371
#define TOK_CPROVER_FLOATBV 372
#define TOK_CPROVER_FIXEDBV 373
#define TOK_CPROVER_ATOMIC 374
#define TOK_CPROVER_BOOL 375
#define TOK_CPROVER_THROW 376
#define TOK_CPROVER_CATCH 377
#define TOK_CPROVER_TRY 378
#define TOK_CPROVER_FINALLY 379
#define TOK_IMPLIES 380
#define TOK_EQUIVALENT 381
#define TOK_TRUE 382
#define TOK_FALSE 383
#define TOK_REAL 384
#define TOK_IMAG 385
#define TOK_ALIGNAS 386
#define TOK_ATOMIC_TYPE_QUALIFIER 387
#define TOK_ATOMIC_TYPE_SPECIFIER 388
#define TOK_GENERIC 389
#define TOK_IMAGINARY 390
#define TOK_NORETURN 391
#define TOK_STATIC_ASSERT 392
#define TOK_THREAD_LOCAL 393
#define TOK_NULLPTR 394
#define TOK_CONSTEXPR 395
#define TOK_SCANNER_ERROR 396
#define TOK_SCANNER_EOF 397
#define TOK_CATCH 398
#define TOK_CHAR16_T 399
#define TOK_CHAR32_T 400
#define TOK_CLASS 401
#define TOK_DELETE 402
#define TOK_DECLTYPE 403
#define TOK_EXPLICIT 404
#define TOK_FRIEND 405
#define TOK_MUTABLE 406
#define TOK_NAMESPACE 407
#define TOK_NEW 408
#define TOK_NOEXCEPT 409
#define TOK_OPERATOR 410
#define TOK_PRIVATE 411
#define TOK_PROTECTED 412
#define TOK_PUBLIC 413
#define TOK_TEMPLATE 414
#define TOK_THIS 415
#define TOK_THROW 416
#define TOK_TYPEID 417
#define TOK_TYPENAME 418
#define TOK_TRY 419
#define TOK_USING 420
#define TOK_VIRTUAL 421
#define TOK_SCOPE 422
#define TOK_DOTPM 423
#define TOK_ARROWPM 424
#define TOK_MSC_UNARY_TYPE_PREDICATE 425
#define TOK_MSC_BINARY_TYPE_PREDICATE 426
#define TOK_MSC_UUIDOF 427
#define TOK_MSC_IF_EXISTS 428
#define TOK_MSC_IF_NOT_EXISTS 429
#define TOK_MSC_UNDERLYING_TYPE 430




/* Copy the first part of user declarations.  */
#line 1 "parser.y"


/*
 * This parser is based on:
 *
 * c5.y, a ANSI-C grammar written by James A. Roskind.
 * "Portions Copyright (c) 1989, 1990 James A. Roskind".
 * (http://www.idiom.com/free-compilers/,
 * ftp://ftp.infoseek.com/ftp/pub/c++grammar/,
 * ftp://ftp.sra.co.jp/.a/pub/cmd/c++grammar2.0.tar.gz)
 */

#define PARSER ansi_c_parser

#include "ansi_c_parser.h"

int yyansi_clex();
extern char *yyansi_ctext;

#include "parser_static.inc"

#include "ansi_c_y.tab.h"

// statements have right recursion, deep nesting of statements thus
// requires more stack space
#define YYMAXDEPTH 25600

/*** token declaration **************************************************/
#line 233 "parser.y"

/************************************************************************/
/*** rules **************************************************************/
/************************************************************************/


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
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
#line 499 "ansi_c_y.tab.cpp"

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
#define YYFINAL  136
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  200
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  202
/* YYNRULES -- Number of rules.  */
#define YYNRULES  582
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1040

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   430

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   190,     2,     2,     2,   192,   185,     2,
     176,   177,   186,   187,   178,   188,   180,   191,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   179,   199,
     193,   198,   194,   197,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   181,     2,   182,   195,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   183,   196,   184,   189,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    33,    35,    37,    39,
      41,    43,    45,    52,    54,    58,    62,    66,    73,    80,
      85,    92,    94,    98,   103,   110,   115,   122,   127,   131,
     133,   138,   142,   147,   151,   155,   158,   161,   168,   176,
     178,   180,   182,   186,   188,   191,   194,   197,   200,   203,
     206,   209,   212,   215,   218,   223,   226,   231,   233,   238,
     241,   244,   246,   250,   254,   258,   260,   264,   268,   270,
     274,   278,   280,   284,   288,   292,   296,   298,   302,   306,
     308,   312,   314,   318,   320,   324,   326,   330,   332,   336,
     338,   342,   344,   348,   350,   356,   361,   363,   367,   371,
     375,   379,   383,   387,   391,   395,   399,   403,   407,   409,
     413,   415,   416,   418,   421,   424,   427,   430,   433,   440,
     441,   446,   447,   452,   453,   459,   465,   467,   470,   472,
     473,   475,   476,   482,   483,   489,   490,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   515,   517,   519,   522,
     524,   527,   530,   532,   535,   538,   540,   543,   545,   547,
     549,   551,   553,   555,   557,   559,   561,   566,   568,   570,
     572,   574,   576,   578,   581,   585,   589,   593,   597,   600,
     604,   607,   611,   614,   617,   620,   622,   625,   628,   632,
     636,   640,   644,   648,   652,   656,   660,   664,   667,   671,
     675,   680,   685,   687,   690,   694,   697,   702,   704,   707,
     711,   714,   716,   718,   720,   722,   727,   732,   739,   750,
     752,   754,   757,   762,   766,   767,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   789,   791,   793,   795,
     797,   799,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   819,   821,   823,   825,   827,   829,   834,   842,   850,
     852,   854,   856,   858,   863,   864,   865,   875,   876,   887,
     888,   895,   897,   899,   901,   905,   906,   908,   909,   911,
     913,   918,   920,   924,   931,   932,   934,   936,   939,   942,
     945,   951,   954,   960,   966,   969,   971,   972,   974,   976,
     979,   982,   985,   987,   990,   994,   998,  1002,  1006,  1010,
    1011,  1014,  1018,  1021,  1022,  1024,  1027,  1028,  1036,  1037,
    1046,  1051,  1053,  1054,  1056,  1058,  1062,  1065,  1069,  1070,
    1073,  1075,  1079,  1081,  1085,  1087,  1089,  1093,  1095,  1098,
    1102,  1105,  1107,  1110,  1114,  1116,  1119,  1123,  1126,  1128,
    1131,  1135,  1137,  1139,  1142,  1146,  1149,  1153,  1154,  1157,
    1159,  1163,  1168,  1170,  1174,  1176,  1177,  1179,  1183,  1186,
    1190,  1193,  1197,  1203,  1208,  1215,  1219,  1221,  1223,  1225,
    1227,  1229,  1231,  1233,  1235,  1237,  1239,  1241,  1243,  1245,
    1249,  1254,  1261,  1265,  1269,  1274,  1279,  1280,  1282,  1285,
    1288,  1294,  1302,  1308,  1310,  1312,  1318,  1326,  1327,  1337,
    1341,  1345,  1348,  1351,  1354,  1358,  1362,  1364,  1368,  1370,
    1377,  1383,  1388,  1391,  1399,  1404,  1406,  1409,  1414,  1419,
    1420,  1422,  1424,  1427,  1430,  1432,  1435,  1439,  1444,  1450,
    1452,  1455,  1457,  1462,  1470,  1472,  1476,  1479,  1481,  1486,
    1494,  1496,  1500,  1503,  1505,  1507,  1509,  1513,  1516,  1518,
    1520,  1524,  1526,  1527,  1529,  1531,  1534,  1536,  1538,  1540,
    1542,  1548,  1551,  1553,  1554,  1556,  1558,  1561,  1564,  1566,
    1569,  1572,  1576,  1580,  1584,  1588,  1592,  1596,  1600,  1605,
    1610,  1612,  1614,  1616,  1619,  1622,  1626,  1628,  1631,  1634,
    1637,  1640,  1642,  1644,  1646,  1648,  1650,  1653,  1655,  1657,
    1660,  1664,  1668,  1673,  1675,  1680,  1686,  1689,  1693,  1697,
    1702,  1707,  1709,  1713,  1715,  1717,  1719,  1722,  1725,  1729,
    1732,  1736,  1741,  1743,  1747,  1749,  1751,  1753,  1755,  1757,
    1759,  1763,  1764,  1770,  1772,  1775,  1776,  1781,  1784,  1788,
    1792,  1796,  1801,  1806,  1811,  1813,  1816,  1819,  1823,  1825,
    1827,  1830,  1833,  1837,  1839,  1843,  1847,  1851,  1856,  1861,
    1865,  1869,  1871
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     201,     0,    -1,   363,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,   204,    -1,   205,
      -1,   206,    -1,   207,    -1,   202,    -1,   208,    -1,   176,
     238,   177,    -1,   218,    -1,   213,    -1,   214,    -1,   215,
      -1,   217,    -1,   210,    -1,   134,   176,   237,   178,   211,
     177,    -1,   212,    -1,   211,   178,   212,    -1,   322,   179,
     237,    -1,    11,   179,   237,    -1,    97,   176,   237,   178,
     322,   177,    -1,    98,   176,   322,   178,   322,   177,    -1,
      96,   176,   322,   177,    -1,    99,   176,   322,   178,   216,
     177,    -1,   220,    -1,   216,   180,   220,    -1,   216,   181,
     238,   182,    -1,   111,   333,   183,   241,   238,   184,    -1,
     113,   333,   241,   209,    -1,   112,   333,   183,   241,   238,
     184,    -1,   114,   333,   241,   209,    -1,   176,   332,   177,
      -1,   209,    -1,   219,   181,   238,   182,    -1,   219,   176,
     177,    -1,   219,   176,   221,   177,    -1,   219,   180,   220,
      -1,   219,    40,   220,    -1,   219,    41,    -1,   219,    42,
      -1,   176,   322,   177,   183,   326,   184,    -1,   176,   322,
     177,   183,   325,   178,   184,    -1,   202,    -1,   203,    -1,
     237,    -1,   221,   178,   237,    -1,   219,    -1,    41,   222,
      -1,    42,   222,    -1,   185,   223,    -1,    49,   343,    -1,
     186,   223,    -1,   187,   223,    -1,   188,   223,    -1,   189,
     223,    -1,   190,   223,    -1,    29,   222,    -1,    29,   176,
     322,   177,    -1,   100,   222,    -1,   100,   176,   322,   177,
      -1,   222,    -1,   176,   322,   177,   223,    -1,   129,   223,
      -1,   130,   223,    -1,   223,    -1,   224,   186,   223,    -1,
     224,   191,   223,    -1,   224,   192,   223,    -1,   224,    -1,
     225,   187,   224,    -1,   225,   188,   224,    -1,   225,    -1,
     226,    43,   225,    -1,   226,    44,   225,    -1,   226,    -1,
     227,   193,   226,    -1,   227,   194,   226,    -1,   227,    45,
     226,    -1,   227,    46,   226,    -1,   227,    -1,   228,    47,
     227,    -1,   228,    48,   227,    -1,   228,    -1,   229,   185,
     228,    -1,   229,    -1,   230,   195,   229,    -1,   230,    -1,
     231,   196,   230,    -1,   231,    -1,   232,    49,   231,    -1,
     232,    -1,   233,    50,   232,    -1,   233,    -1,   233,   125,
     234,    -1,   234,    -1,   235,   126,   234,    -1,   235,    -1,
     235,   197,   238,   179,   236,    -1,   235,   197,   179,   236,
      -1,   236,    -1,   223,   198,   237,    -1,   223,    52,   237,
      -1,   223,    53,   237,    -1,   223,    54,   237,    -1,   223,
      55,   237,    -1,   223,    56,   237,    -1,   223,    57,   237,
      -1,   223,    58,   237,    -1,   223,    59,   237,    -1,   223,
      60,   237,    -1,   223,    61,   237,    -1,   237,    -1,   238,
     178,   237,    -1,   237,    -1,    -1,   238,    -1,   254,   199,
      -1,   255,   199,    -1,   242,   199,    -1,   250,   199,    -1,
     243,   199,    -1,   137,   176,   237,   178,   237,   177,    -1,
      -1,   256,   387,   244,   323,    -1,    -1,   257,   387,   245,
     323,    -1,    -1,   243,   178,   387,   246,   323,    -1,    84,
     348,   176,   349,   177,    -1,   298,    -1,   248,   247,    -1,
     247,    -1,    -1,   248,    -1,    -1,   254,   379,   249,   251,
     323,    -1,    -1,   255,   379,   249,   252,   323,    -1,    -1,
     250,   178,   379,   249,   253,   323,    -1,   264,    -1,   266,
      -1,   268,    -1,   269,    -1,   270,    -1,   265,    -1,   267,
      -1,   271,    -1,   273,    -1,   275,    -1,   281,    -1,   257,
     281,    -1,   298,    -1,   256,   298,    -1,   256,   259,    -1,
     260,    -1,   257,   260,    -1,   257,   298,    -1,   261,    -1,
     257,   261,    -1,   281,    -1,   260,    -1,   132,    -1,     9,
      -1,    25,    -1,    37,    -1,   119,    -1,    73,    -1,    74,
      -1,    95,   176,   238,   177,    -1,   260,    -1,   298,    -1,
     260,    -1,   298,    -1,   281,    -1,   262,    -1,   263,   262,
      -1,   256,   282,   296,    -1,   265,   281,   296,    -1,   264,
     259,   296,    -1,   264,   282,   296,    -1,   282,   296,    -1,
     257,   282,   296,    -1,   265,   260,    -1,   265,   282,   296,
      -1,   256,   283,    -1,   267,   281,    -1,   266,   259,    -1,
     283,    -1,   257,   283,    -1,   267,   260,    -1,   271,   281,
     296,    -1,   256,   203,   296,    -1,   268,   259,   296,    -1,
     273,   281,   296,    -1,   256,   272,   296,    -1,   269,   259,
     296,    -1,   275,   281,   296,    -1,   256,   274,   296,    -1,
     270,   259,   296,    -1,   203,   296,    -1,   257,   203,   296,
      -1,   271,   260,   296,    -1,    75,   176,   238,   177,    -1,
      75,   176,   322,   177,    -1,   272,    -1,   257,   272,    -1,
     257,   272,   257,    -1,   272,   257,    -1,   133,   176,   322,
     177,    -1,   274,    -1,   257,   274,    -1,   257,   274,   257,
      -1,   274,   257,    -1,    62,    -1,    63,    -1,    25,    -1,
     276,    -1,   276,   176,    67,   177,    -1,   276,   176,    64,
     177,    -1,   276,   176,   276,   198,   276,   177,    -1,   276,
     176,   276,   198,   276,   178,   276,   198,   276,   177,    -1,
     178,    -1,   277,    -1,   278,   277,    -1,   105,   176,   278,
     177,    -1,   105,   176,   177,    -1,    -1,   279,    -1,    33,
      -1,    16,    -1,    30,    -1,     3,    -1,    24,    -1,    21,
      -1,   138,    -1,    83,    -1,   279,    -1,    22,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,     8,    -1,    27,
      -1,    23,    -1,    17,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,    82,    -1,    13,    -1,    28,
      -1,    35,    -1,    36,    -1,     4,    -1,     5,    -1,   116,
     181,   238,   182,    -1,   117,   181,   238,   182,   181,   238,
     182,    -1,   118,   181,   238,   182,   181,   238,   182,    -1,
     120,    -1,   286,    -1,   308,    -1,   284,    -1,   115,   193,
     322,   194,    -1,    -1,    -1,   290,   296,   280,   287,   183,
     299,   184,   296,   285,    -1,    -1,   290,   296,   280,   321,
     288,   183,   299,   184,   296,   285,    -1,    -1,   290,   296,
     280,   321,   289,   296,    -1,    31,    -1,    34,    -1,   237,
      -1,   291,   178,   237,    -1,    -1,   291,    -1,    -1,     9,
      -1,   202,    -1,   202,   176,   292,   177,    -1,   293,    -1,
     294,   178,   293,    -1,    85,   176,   176,   294,   177,   177,
      -1,    -1,   297,    -1,   298,    -1,   297,   298,    -1,    88,
      92,    -1,    87,    92,    -1,    89,   176,   238,   177,    92,
      -1,    86,    92,    -1,    86,   176,   238,   177,    92,    -1,
      90,   176,   202,   177,    92,    -1,    91,    92,    -1,   295,
      -1,    -1,   300,    -1,   301,    -1,   300,   301,    -1,   303,
     199,    -1,   302,   199,    -1,   199,    -1,   242,   199,    -1,
     296,   257,   305,    -1,   302,   178,   305,    -1,   296,   255,
     304,    -1,   303,   178,   304,    -1,   379,   306,   296,    -1,
      -1,   307,   296,    -1,   387,   306,   296,    -1,   307,   296,
      -1,    -1,   307,    -1,   179,   239,    -1,    -1,   311,   296,
     309,   183,   312,   184,   296,    -1,    -1,   311,   296,   321,
     310,   183,   312,   184,   296,    -1,   311,   296,   321,   296,
      -1,    15,    -1,    -1,   313,    -1,   314,    -1,   313,   178,
     314,    -1,   313,   178,    -1,   321,   296,   315,    -1,    -1,
     198,   239,    -1,   319,    -1,   319,   178,    51,    -1,   318,
      -1,   317,   178,   318,    -1,   202,    -1,   320,    -1,   319,
     178,   320,    -1,   254,    -1,   254,   392,    -1,   254,   387,
     296,    -1,   254,   381,    -1,   256,    -1,   256,   392,    -1,
     256,   387,   296,    -1,   255,    -1,   255,   392,    -1,   255,
     387,   296,    -1,   255,   381,    -1,   257,    -1,   257,   392,
      -1,   257,   387,   296,    -1,   202,    -1,   203,    -1,   296,
     255,    -1,   296,   255,   391,    -1,   296,   257,    -1,   296,
     257,   391,    -1,    -1,   198,   324,    -1,   239,    -1,   183,
     326,   184,    -1,   183,   325,   178,   184,    -1,   327,    -1,
     325,   178,   327,    -1,   325,    -1,    -1,   324,    -1,   328,
     198,   324,    -1,   328,   324,    -1,   220,   179,   324,    -1,
     180,   220,    -1,   181,   238,   182,    -1,   181,   238,    51,
     238,   182,    -1,   328,   181,   238,   182,    -1,   328,   181,
     238,    51,   238,   182,    -1,   328,   180,   220,    -1,   331,
      -1,   332,    -1,   330,    -1,   335,    -1,   336,    -1,   338,
      -1,   340,    -1,   344,    -1,   341,    -1,   345,    -1,   346,
      -1,   347,    -1,   241,    -1,   321,   179,   329,    -1,     7,
     239,   179,   329,    -1,     7,   239,    51,   239,   179,   329,
      -1,    11,   179,   329,    -1,   333,   183,   184,    -1,   333,
     183,   334,   184,    -1,   333,   183,    68,   184,    -1,    -1,
     329,    -1,   334,   329,    -1,   240,   199,    -1,    20,   176,
     238,   177,   329,    -1,    20,   176,   238,   177,   329,    14,
     329,    -1,    32,   176,   238,   177,   329,    -1,   330,    -1,
     335,    -1,    39,   176,   240,   177,   329,    -1,    12,   329,
      39,   176,   238,   177,   199,    -1,    -1,    18,   339,   176,
     337,   240,   199,   240,   177,   329,    -1,    19,   238,   199,
      -1,    19,   203,   199,    -1,    10,   199,    -1,     6,   199,
      -1,    26,   199,    -1,    26,   238,   199,    -1,    93,   342,
     199,    -1,   343,    -1,   342,   178,   343,    -1,   321,    -1,
      84,   348,   176,   349,   177,   199,    -1,    84,   348,   183,
      68,   184,    -1,    94,   183,    68,   184,    -1,    94,    68,
      -1,   101,   332,   103,   176,   238,   177,   332,    -1,   101,
     332,   102,   332,    -1,   104,    -1,   121,   199,    -1,   123,
     332,   122,   332,    -1,   123,   332,   124,   332,    -1,    -1,
      37,    -1,    19,    -1,    19,    37,    -1,    37,    19,    -1,
     350,    -1,   350,   351,    -1,   350,   351,   354,    -1,   350,
     351,   354,   357,    -1,   350,   351,   354,   357,   360,    -1,
     207,    -1,   179,   353,    -1,   179,    -1,   207,   176,   238,
     177,    -1,   181,   321,   182,   207,   176,   238,   177,    -1,
     352,    -1,   353,   178,   352,    -1,   179,   356,    -1,   179,
      -1,   207,   176,   238,   177,    -1,   181,   321,   182,   207,
     176,   238,   177,    -1,   355,    -1,   356,   178,   355,    -1,
     179,   359,    -1,   179,    -1,   207,    -1,   358,    -1,   359,
     178,   358,    -1,   179,   361,    -1,   179,    -1,   362,    -1,
     361,   178,   362,    -1,   343,    -1,    -1,   364,    -1,   365,
      -1,   364,   365,    -1,   367,    -1,   241,    -1,   366,    -1,
     199,    -1,    84,   176,   207,   177,   199,    -1,   378,   368,
      -1,   332,    -1,    -1,   370,    -1,   371,    -1,   370,   371,
      -1,   377,   199,    -1,   281,    -1,   260,   281,    -1,   372,
     259,    -1,   372,   282,   296,    -1,   265,   281,   296,    -1,
     373,   259,   296,    -1,   373,   282,   296,    -1,   271,   281,
     296,    -1,   372,   203,   296,    -1,   374,   259,   296,    -1,
     372,   290,   321,   296,    -1,   372,   311,   321,   296,    -1,
     373,    -1,   374,    -1,   375,    -1,   376,   379,    -1,   255,
     379,    -1,   377,   178,   379,    -1,   387,    -1,   254,   379,
      -1,   255,   379,    -1,   256,   387,    -1,   257,   387,    -1,
     387,    -1,   380,    -1,   384,    -1,   381,    -1,   203,    -1,
     203,   393,    -1,   382,    -1,   383,    -1,   186,   381,    -1,
     186,   258,   381,    -1,   176,   382,   177,    -1,   176,   382,
     177,   393,    -1,   385,    -1,   186,   176,   386,   177,    -1,
     186,   258,   176,   386,   177,    -1,   186,   384,    -1,   186,
     258,   384,    -1,   176,   384,   177,    -1,   176,   386,   393,
     177,    -1,   176,   384,   177,   393,    -1,   203,    -1,   176,
     386,   177,    -1,   388,    -1,   390,    -1,   389,    -1,   186,
     387,    -1,   195,   387,    -1,   186,   258,   387,    -1,   390,
     393,    -1,   176,   388,   177,    -1,   176,   388,   177,   393,
      -1,   202,    -1,   176,   390,   177,    -1,   398,    -1,   400,
      -1,   393,    -1,   399,    -1,   401,    -1,   395,    -1,   176,
     177,   370,    -1,    -1,   176,   394,   317,   177,   369,    -1,
     397,    -1,   176,   177,    -1,    -1,   176,   396,   316,   177,
      -1,   181,   182,    -1,   181,   263,   182,    -1,   181,   186,
     182,    -1,   181,   239,   182,    -1,   181,   263,   239,   182,
      -1,   397,   181,   239,   182,    -1,   397,   181,   186,   182,
      -1,   186,    -1,   186,   258,    -1,   186,   391,    -1,   186,
     258,   391,    -1,   195,    -1,   186,    -1,   186,   258,    -1,
     186,   392,    -1,   186,   258,   392,    -1,   195,    -1,   176,
     398,   177,    -1,   176,   400,   177,    -1,   176,   393,   177,
      -1,   176,   400,   177,   393,    -1,   176,   398,   177,   393,
      -1,   176,   399,   177,    -1,   176,   401,   177,    -1,   395,
      -1,   176,   399,   177,   395,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   241,   241,   247,   251,   255,   259,   263,   267,   272,
     273,   274,   275,   281,   282,   283,   285,   286,   287,   288,
     289,   290,   294,   304,   308,   315,   322,   332,   339,   353,
     362,   372,   380,   387,   397,   405,   415,   423,   435,   445,
     446,   448,   457,   466,   472,   478,   484,   491,   501,   515,
     516,   520,   525,   533,   534,   540,   546,   551,   561,   566,
     571,   576,   581,   586,   591,   596,   602,   611,   612,   619,
     624,   632,   633,   635,   637,   642,   643,   645,   650,   651,
     653,   658,   659,   661,   663,   665,   670,   671,   673,   678,
     679,   684,   685,   690,   691,   696,   697,   702,   703,   711,
     712,   720,   721,   726,   727,   734,   744,   745,   747,   749,
     751,   753,   755,   757,   759,   761,   763,   765,   770,   771,
     776,   781,   782,   788,   794,   800,   801,   802,   806,   818,
     817,   830,   829,   842,   841,   857,   864,   868,   872,   877,
     880,   886,   884,   902,   900,   918,   916,   932,   933,   934,
     935,   936,   940,   941,   942,   943,   944,   948,   949,   953,
     954,   958,   965,   966,   973,   980,   981,   988,   989,   993,
     994,   995,   996,   997,   998,   999,  1000,  1004,  1005,  1009,
    1010,  1011,  1015,  1016,  1023,  1027,  1031,  1035,  1042,  1046,
    1050,  1054,  1062,  1066,  1070,  1078,  1079,  1083,  1090,  1094,
    1098,  1105,  1109,  1113,  1120,  1124,  1128,  1135,  1139,  1143,
    1150,  1155,  1163,  1164,  1168,  1172,  1179,  1188,  1189,  1193,
    1197,  1204,  1208,  1212,  1219,  1220,  1224,  1228,  1232,  1236,
    1240,  1244,  1251,  1256,  1264,  1267,  1271,  1272,  1273,  1274,
    1275,  1276,  1277,  1278,  1279,  1283,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1310,  1317,  1324,
    1328,  1329,  1330,  1334,  1339,  1351,  1348,  1369,  1365,  1389,
    1385,  1402,  1404,  1409,  1414,  1423,  1426,  1431,  1434,  1440,
    1445,  1454,  1455,  1462,  1468,  1471,  1475,  1476,  1483,  1485,
    1487,  1489,  1491,  1493,  1495,  1497,  1502,  1505,  1509,  1514,
    1522,  1523,  1524,  1528,  1535,  1546,  1554,  1569,  1577,  1588,
    1591,  1602,  1611,  1623,  1626,  1630,  1642,  1640,  1654,  1651,
    1664,  1675,  1684,  1687,  1691,  1696,  1701,  1708,  1719,  1723,
    1730,  1731,  1740,  1745,  1752,  1761,  1766,  1774,  1782,  1789,
    1797,  1806,  1814,  1821,  1829,  1837,  1844,  1852,  1860,  1868,
    1875,  1886,  1887,  1891,  1895,  1900,  1904,  1913,  1917,  1927,
    1928,  1934,  1943,  1951,  1959,  1961,  1969,  1970,  1978,  1984,
    1999,  2006,  2013,  2021,  2028,  2036,  2048,  2049,  2050,  2051,
    2052,  2053,  2054,  2055,  2056,  2057,  2058,  2059,  2063,  2072,
    2080,  2087,  2096,  2107,  2114,  2122,  2134,  2141,  2146,  2153,
    2168,  2177,  2186,  2197,  2198,  2202,  2210,  2219,  2218,  2246,
    2263,  2270,  2272,  2274,  2276,  2281,  2302,  2307,  2314,  2318,
    2324,  2335,  2341,  2350,  2359,  2367,  2375,  2380,  2388,  2398,
    2400,  2401,  2402,  2403,  2415,  2421,  2428,  2436,  2445,  2457,
    2461,  2465,  2469,  2475,  2485,  2490,  2498,  2502,  2506,  2512,
    2522,  2527,  2535,  2539,  2543,  2551,  2556,  2564,  2568,  2572,
    2577,  2585,  2593,  2595,  2599,  2600,  2604,  2609,  2613,  2614,
    2618,  2625,  2646,  2651,  2654,  2658,  2663,  2671,  2676,  2677,
    2681,  2688,  2692,  2696,  2700,  2708,  2712,  2716,  2724,  2729,
    2739,  2740,  2741,  2745,  2751,  2757,  2765,  2773,  2780,  2787,
    2794,  2804,  2805,  2809,  2810,  2814,  2815,  2820,  2824,  2825,
    2830,  2838,  2840,  2850,  2851,  2856,  2862,  2867,  2875,  2877,
    2882,  2892,  2893,  2898,  2899,  2903,  2904,  2909,  2916,  2929,
    2935,  2937,  2947,  2954,  2959,  2960,  2961,  2965,  2966,  2970,
    2972,  2983,  2982,  3005,  3006,  3014,  3013,  3033,  3040,  3050,
    3058,  3065,  3074,  3083,  3096,  3102,  3110,  3115,  3125,  3136,
    3142,  3150,  3155,  3165,  3176,  3178,  3180,  3182,  3188,  3197,
    3199,  3201,  3202
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"auto\"", "\"bool\"", "\"complex\"",
  "\"break\"", "\"case\"", "\"char\"", "\"const\"", "\"continue\"",
  "\"default\"", "\"do\"", "\"double\"", "\"else\"", "\"enum\"",
  "\"extern\"", "\"float\"", "\"for\"", "\"goto\"", "\"if\"", "\"inline\"",
  "\"int\"", "\"long\"", "\"register\"", "\"restrict\"", "\"return\"",
  "\"short\"", "\"signed\"", "\"sizeof\"", "\"static\"", "\"struct\"",
  "\"switch\"", "\"typedef\"", "\"union\"", "\"unsigned\"", "\"void\"",
  "\"volatile\"", "\"wchar_t\"", "\"while\"", "\"->\"", "\"++\"", "\"--\"",
  "\"<<\"", "\">>\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\"&&\"",
  "\"||\"", "\"...\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"+=\"", "\"-=\"",
  "\"<<=\"", "\">>=\"", "\"&=\"", "\"^=\"", "\"|=\"", "TOK_IDENTIFIER",
  "TOK_TYPEDEFNAME", "TOK_INTEGER", "TOK_FLOATING", "TOK_CHARACTER",
  "TOK_STRING", "TOK_ASM_STRING", "\"__int8\"", "\"__int16\"",
  "\"__int32\"", "\"__int64\"", "\"__ptr32\"", "\"__ptr64\"", "\"typeof\"",
  "\"__auto_type\"", "\"__float80\"", "\"__float128\"", "\"__int128\"",
  "\"_Decimal32\"", "\"_Decimal64\"", "\"_Decimal128\"", "\"__asm__\"",
  "\"__asm__ (with parentheses)\"", "\"__attribute__\"", "\"aligned\"",
  "\"transparent_union\"", "\"packed\"", "\"vector_size\"", "\"mode\"",
  "\"__gnu_inline__\"", "\")\"", "\"__label__\"", "\"__asm\"",
  "\"__based\"", "\"_var_arg_typeof\"", "\"__builtin_va_arg\"",
  "\"__builtin_types_compatible_p\"", "\"__offsetof\"", "\"__alignof__\"",
  "\"__try\"", "\"__finally\"", "\"__except\"", "\"__leave\"",
  "\"__declspec\"", "\"__interface\"", "\"__cdecl\"", "\"__stdcall\"",
  "\"__fastcall\"", "\"__clrcall\"", "\"forall\"", "\"exists\"",
  "\"\\\\forall\"", "\"\\\\exists\"", "\"array_of\"",
  "\"__CPROVER_bitvector\"", "\"__CPROVER_floatbv\"",
  "\"__CPROVER_fixedbv\"", "\"__CPROVER_atomic\"", "\"__CPROVER_bool\"",
  "\"__CPROVER_throw\"", "\"__CPROVER_catch\"", "\"__CPROVER_try\"",
  "\"__CPROVER_finally\"", "\"==>\"", "\"<==>\"", "\"TRUE\"", "\"FALSE\"",
  "\"__real__\"", "\"__imag__\"", "\"_Alignas\"", "\"_Atomic\"",
  "\"_Atomic()\"", "\"_Generic\"", "\"_Imaginary\"", "\"_Noreturn\"",
  "\"_Static_assert\"", "\"_Thread_local\"", "\"nullptr\"",
  "\"constexpr\"", "TOK_SCANNER_ERROR", "TOK_SCANNER_EOF", "\"catch\"",
  "\"char16_t\"", "\"char32_t\"", "\"class\"", "\"delete\"",
  "\"decltype\"", "\"explicit\"", "\"friend\"", "\"mutable\"",
  "\"namespace\"", "\"new\"", "\"noexcept\"", "\"operator\"",
  "\"private\"", "\"protected\"", "\"public\"", "\"template\"", "\"this\"",
  "\"throw\"", "\"typeid\"", "\"typename\"", "\"try\"", "\"using\"",
  "\"virtual\"", "\"::\"", "\".*\"", "\"->*\"",
  "TOK_MSC_UNARY_TYPE_PREDICATE", "TOK_MSC_BINARY_TYPE_PREDICATE",
  "\"__uuidof\"", "\"__if_exists\"", "\"__if_not_exists\"",
  "\"__underlying_type\"", "'('", "')'", "','", "':'", "'.'", "'['", "']'",
  "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept", "grammar",
  "identifier", "typedef_name", "integer", "floating", "character",
  "string", "constant", "primary_expression", "generic_selection",
  "generic_assoc_list", "generic_association", "gcc_builtin_expressions",
  "cw_builtin_expressions", "offsetof", "offsetof_member_designator",
  "quantifier_expression", "statement_expression", "postfix_expression",
  "member_name", "argument_expression_list", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "logical_implication_expression", "logical_equivalence_expression",
  "conditional_expression", "assignment_expression", "comma_expression",
  "constant_expression", "comma_expression_opt", "declaration",
  "static_assert_declaration", "default_declaring_list", "@1", "@2", "@3",
  "post_declarator_attribute", "post_declarator_attributes",
  "post_declarator_attributes_opt", "declaring_list", "@4", "@5", "@6",
  "declaration_specifier", "type_specifier", "declaration_qualifier_list",
  "type_qualifier_list", "attribute_type_qualifier_list",
  "declaration_qualifier", "type_qualifier", "attribute_or_type_qualifier",
  "attribute_or_type_qualifier_or_storage_class",
  "attribute_type_qualifier_storage_class_list",
  "basic_declaration_specifier", "basic_type_specifier",
  "sue_declaration_specifier", "sue_type_specifier",
  "typedef_declaration_specifier", "typeof_declaration_specifier",
  "atomic_declaration_specifier", "typedef_type_specifier",
  "typeof_specifier", "typeof_type_specifier", "atomic_specifier",
  "atomic_type_specifier", "msc_decl_identifier", "msc_decl_modifier",
  "msc_declspec_seq", "msc_declspec", "msc_declspec_opt", "storage_class",
  "basic_type_name", "elaborated_type_name", "array_of_construct",
  "pragma_packed", "aggregate_name", "@7", "@8", "@9", "aggregate_key",
  "gcc_attribute_expression_list", "gcc_attribute_expression_list_opt",
  "gcc_attribute", "gcc_attribute_list", "gcc_attribute_specifier",
  "gcc_type_attribute_opt", "gcc_type_attribute_list",
  "gcc_type_attribute", "member_declaration_list_opt",
  "member_declaration_list", "member_declaration",
  "member_default_declaring_list", "member_declaring_list",
  "member_declarator", "member_identifier_declarator",
  "bit_field_size_opt", "bit_field_size", "enum_name", "@10", "@11",
  "enum_key", "enumerator_list_opt", "enumerator_list",
  "enumerator_declaration", "enumerator_value_opt", "parameter_type_list",
  "KnR_parameter_list", "KnR_parameter", "parameter_list",
  "parameter_declaration", "identifier_or_typedef_name", "type_name",
  "initializer_opt", "initializer", "initializer_list",
  "initializer_list_opt", "designated_initializer", "designator",
  "statement", "declaration_statement", "labeled_statement",
  "compound_statement", "compound_scope", "statement_list",
  "expression_statement", "selection_statement",
  "declaration_or_expression_statement", "iteration_statement", "@12",
  "jump_statement", "gcc_local_label_statement", "gcc_local_label_list",
  "gcc_local_label", "gcc_asm_statement", "msc_asm_statement",
  "msc_seh_statement", "cprover_exception_statement",
  "volatile_or_goto_opt", "gcc_asm_commands", "gcc_asm_assembler_template",
  "gcc_asm_outputs", "gcc_asm_output", "gcc_asm_output_list",
  "gcc_asm_inputs", "gcc_asm_input", "gcc_asm_input_list",
  "gcc_asm_clobbered_registers", "gcc_asm_clobbered_register",
  "gcc_asm_clobbered_registers_list", "gcc_asm_labels",
  "gcc_asm_labels_list", "gcc_asm_label", "translation_unit",
  "external_definition_list", "external_definition", "asm_definition",
  "function_definition", "function_body", "KnR_parameter_header_opt",
  "KnR_parameter_header", "KnR_parameter_declaration",
  "KnR_declaration_qualifier_list", "KnR_basic_declaration_specifier",
  "KnR_typedef_declaration_specifier", "KnR_sue_declaration_specifier",
  "KnR_declaration_specifier", "KnR_parameter_declaring_list",
  "function_head", "declarator", "typedef_declarator",
  "parameter_typedef_declarator", "clean_typedef_declarator",
  "clean_postfix_typedef_declarator", "paren_typedef_declarator",
  "paren_postfix_typedef_declarator", "simple_paren_typedef_declarator",
  "identifier_declarator", "unary_identifier_declarator",
  "postfix_identifier_declarator", "paren_identifier_declarator",
  "abstract_declarator", "parameter_abstract_declarator",
  "postfixing_abstract_declarator", "@13",
  "parameter_postfixing_abstract_declarator", "@14",
  "array_abstract_declarator", "unary_abstract_declarator",
  "parameter_unary_abstract_declarator", "postfix_abstract_declarator",
  "parameter_postfix_abstract_declarator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,    40,    41,    44,    58,
      46,    91,    93,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     208,   208,   208,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   210,   211,   211,   212,   212,   213,   213,   214,
     215,   216,   216,   216,   217,   217,   217,   217,   218,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   221,   221,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   223,   223,   223,
     223,   224,   224,   224,   224,   225,   225,   225,   226,   226,
     226,   227,   227,   227,   227,   227,   228,   228,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   240,   240,   241,   241,   241,   241,   241,   242,   244,
     243,   245,   243,   246,   243,   247,   247,   248,   248,   249,
     249,   251,   250,   252,   250,   253,   250,   254,   254,   254,
     254,   254,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   256,   257,   257,   257,   258,   258,   259,   259,   260,
     260,   260,   260,   260,   260,   260,   260,   261,   261,   262,
     262,   262,   263,   263,   264,   264,   264,   264,   265,   265,
     265,   265,   266,   266,   266,   267,   267,   267,   268,   268,
     268,   269,   269,   269,   270,   270,   270,   271,   271,   271,
     272,   272,   273,   273,   273,   273,   274,   275,   275,   275,
     275,   276,   276,   276,   277,   277,   277,   277,   277,   277,
     278,   278,   279,   279,   280,   280,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     283,   283,   283,   284,   285,   287,   286,   288,   286,   289,
     286,   290,   290,   291,   291,   292,   292,   293,   293,   293,
     293,   294,   294,   295,   296,   296,   297,   297,   298,   298,
     298,   298,   298,   298,   298,   298,   299,   299,   300,   300,
     301,   301,   301,   301,   302,   302,   303,   303,   304,   304,
     304,   305,   305,   306,   306,   307,   309,   308,   310,   308,
     308,   311,   312,   312,   313,   313,   313,   314,   315,   315,
     316,   316,   317,   317,   318,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   321,   321,   322,   322,   322,   322,   323,   323,   324,
     324,   324,   325,   325,   326,   326,   327,   327,   327,   327,
     328,   328,   328,   328,   328,   328,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   330,   331,
     331,   331,   331,   332,   332,   332,   333,   334,   334,   335,
     336,   336,   336,   337,   337,   338,   338,   339,   338,   340,
     340,   340,   340,   340,   340,   341,   342,   342,   343,   344,
     344,   345,   345,   346,   346,   346,   347,   347,   347,   348,
     348,   348,   348,   348,   349,   349,   349,   349,   349,   350,
     351,   351,   352,   352,   353,   353,   354,   354,   355,   355,
     356,   356,   357,   357,   358,   359,   359,   360,   360,   361,
     361,   362,   363,   363,   364,   364,   365,   365,   365,   365,
     366,   367,   368,   369,   369,   370,   370,   371,   372,   372,
     372,   373,   373,   373,   373,   374,   374,   374,   375,   375,
     376,   376,   376,   377,   377,   377,   378,   378,   378,   378,
     378,   379,   379,   380,   380,   381,   381,   381,   382,   382,
     382,   383,   383,   384,   384,   384,   384,   384,   385,   385,
     385,   386,   386,   387,   387,   388,   388,   388,   388,   389,
     389,   389,   390,   390,   391,   391,   391,   392,   392,   393,
     393,   394,   393,   395,   395,   396,   395,   397,   397,   397,
     397,   397,   397,   397,   398,   398,   398,   398,   398,   399,
     399,   399,   399,   399,   400,   400,   400,   400,   400,   401,
     401,   401,   401
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     6,     1,     3,     3,     3,     6,     6,     4,
       6,     1,     3,     4,     6,     4,     6,     4,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     6,     7,     1,
       1,     1,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     4,     1,     4,     2,
       2,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       1,     0,     1,     2,     2,     2,     2,     2,     6,     0,
       4,     0,     4,     0,     5,     5,     1,     2,     1,     0,
       1,     0,     5,     0,     5,     0,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     2,     3,
       2,     3,     2,     2,     2,     1,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       4,     4,     1,     2,     3,     2,     4,     1,     2,     3,
       2,     1,     1,     1,     1,     4,     4,     6,    10,     1,
       1,     2,     4,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     7,     1,
       1,     1,     1,     4,     0,     0,     9,     0,    10,     0,
       6,     1,     1,     1,     3,     0,     1,     0,     1,     1,
       4,     1,     3,     6,     0,     1,     1,     2,     2,     2,
       5,     2,     5,     5,     2,     1,     0,     1,     1,     2,
       2,     2,     1,     2,     3,     3,     3,     3,     3,     0,
       2,     3,     2,     0,     1,     2,     0,     7,     0,     8,
       4,     1,     0,     1,     1,     3,     2,     3,     0,     2,
       1,     3,     1,     3,     1,     1,     3,     1,     2,     3,
       2,     1,     2,     3,     1,     2,     3,     2,     1,     2,
       3,     1,     1,     2,     3,     2,     3,     0,     2,     1,
       3,     4,     1,     3,     1,     0,     1,     3,     2,     3,
       2,     3,     5,     4,     6,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     6,     3,     3,     4,     4,     0,     1,     2,     2,
       5,     7,     5,     1,     1,     5,     7,     0,     9,     3,
       3,     2,     2,     2,     3,     3,     1,     3,     1,     6,
       5,     4,     2,     7,     4,     1,     2,     4,     4,     0,
       1,     1,     2,     2,     1,     2,     3,     4,     5,     1,
       2,     1,     4,     7,     1,     3,     2,     1,     4,     7,
       1,     3,     2,     1,     1,     1,     3,     2,     1,     1,
       3,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       5,     2,     1,     0,     1,     1,     2,     2,     1,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     4,
       1,     1,     1,     2,     2,     3,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       3,     3,     4,     1,     4,     5,     2,     3,     3,     4,
       4,     1,     3,     1,     1,     1,     2,     2,     3,     2,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     0,     5,     1,     2,     0,     4,     2,     3,     3,
       3,     4,     4,     4,     1,     2,     2,     3,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     4,     4,     3,
       3,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     472,   239,   264,   265,   250,   170,   260,   331,   237,   253,
     241,   245,   252,   240,   171,   251,   261,   238,   281,   236,
     282,   262,   263,   172,     3,     4,   246,   247,   248,   249,
     174,   175,     0,   254,   255,   256,   257,   258,   259,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   269,   169,     0,     0,   242,
       0,     0,     0,   479,     0,   542,   294,   477,     0,     0,
       0,     0,     0,     0,     0,   162,   147,   152,   148,   153,
     149,   150,   151,   154,   212,   155,   217,   156,   244,   157,
     294,   195,   272,   270,   294,   305,   159,   271,   294,     2,
     473,   474,   478,   476,   406,   506,   533,   535,   534,   294,
       0,     0,   301,     0,   299,   298,     0,     0,   304,     0,
       0,   294,     0,     0,     0,   294,     0,     0,     0,     0,
       0,   162,   165,   178,   536,   537,     1,   207,   295,   296,
     125,     0,   127,     0,   126,     0,     0,   123,   515,   139,
     512,   514,   517,   518,   513,   523,   511,   124,   139,   294,
     161,   168,   294,   294,   167,   294,   192,   160,   129,   294,
     163,   213,   218,   158,   294,   196,   164,   131,   294,   294,
     190,   294,   294,   194,   197,   193,   294,   294,   294,   294,
     294,   215,   294,   220,   294,   188,   234,   326,   475,   482,
       0,   481,   555,     0,   539,   549,   553,     0,     0,     0,
       0,     5,     6,     7,     8,     0,     0,     0,     0,     0,
     406,   406,   406,   406,     0,     0,     0,   294,     0,     0,
       0,     0,     0,     0,    13,     9,    10,    11,    12,    14,
      39,    21,    17,    18,    19,    20,    16,    53,    67,    71,
      75,    78,    81,    86,    89,    91,    93,    95,    97,    99,
     101,   103,   106,   118,     0,     0,     0,     0,   287,     0,
       0,     0,     0,   223,   221,   222,   233,   229,   224,   230,
       0,     0,     0,     0,     0,     0,     0,   540,   543,   163,
     166,   164,   538,   297,   133,   139,     0,   531,     0,     0,
       0,     0,     0,   519,   526,   516,   439,   138,   140,   141,
     136,   143,   199,   202,   205,   184,   367,   208,   214,   219,
     189,   367,   186,   187,   185,   191,   200,   203,   206,   209,
     198,   201,   204,   235,   275,   361,   362,     0,   294,   121,
     554,     0,     0,   557,     0,   120,     0,   179,   182,     0,
     181,   180,     0,   294,    63,   294,    54,    55,   428,    57,
     294,     0,   294,   294,   294,    65,     0,     0,     0,     0,
      69,    70,     0,     0,     0,     0,    56,    58,    59,    60,
      61,    62,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     210,     0,   363,   365,   152,   153,   154,   155,   156,   211,
       0,   288,   289,   291,     0,     0,     0,     0,   176,     0,
     232,   231,   273,   266,     0,     0,   216,     0,   541,   367,
     145,     0,   521,   528,     0,     0,     0,   520,   527,   441,
     440,     0,   137,   367,   367,     0,   130,   132,     0,   279,
     332,   330,     0,     0,     0,     0,     0,   121,   417,     0,
       0,     0,     0,     0,     0,   439,     0,     0,   406,   435,
       0,   406,   403,    13,   294,   122,     0,   398,     0,     0,
       0,     0,     0,   407,   388,   386,   387,   121,   389,   390,
     391,   392,   394,   393,   395,   396,   397,     0,     0,   162,
     152,   154,   488,   550,   485,     0,   500,   501,   502,     0,
       0,   344,     0,   342,   347,   354,   351,   358,     0,   340,
     345,   559,   560,   558,     0,   183,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,    38,    49,    50,    44,    41,     0,    51,    43,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   107,    72,    73,    74,    71,    76,    77,    79,    80,
      84,    85,    82,    83,    87,    88,    90,    92,    94,    96,
      98,   100,   102,     0,     0,   119,   555,   564,   568,   364,
     546,   544,   545,   366,   480,   285,     0,   287,   302,   300,
     303,     0,     0,     0,     0,     0,     0,   134,   367,   532,
     522,   530,   529,   524,     0,   442,   443,     0,   142,   144,
     375,   369,   368,   294,     0,   294,     0,   333,   334,   294,
     332,   422,     0,   421,   121,     0,     0,     0,     0,     0,
     423,     0,     0,   121,   405,     0,     0,   426,   432,     0,
       0,   436,     0,   409,   139,   139,   129,   131,   121,   404,
     408,   504,   489,   294,   294,   486,   294,   490,   294,     0,
       0,   294,   294,   294,   503,     0,   487,   483,     0,   555,
     569,   573,   350,   294,   348,   581,   547,   548,   357,   294,
     355,   555,   569,   294,   352,   294,   359,   556,     0,   561,
     563,   562,    64,     0,    29,   294,   294,     0,    66,     0,
       0,   406,    35,    37,   294,   375,    68,    42,     0,    40,
     105,     0,     0,     0,     0,   565,   566,   283,   286,     0,
     293,   292,   226,   225,     0,     0,     0,   128,   146,   525,
     449,     0,   444,     0,     0,    13,     0,   376,   374,     0,
     372,     0,   312,     0,     0,     0,   294,   308,     0,     0,
     294,   280,   294,   336,   338,     0,     0,   121,   402,     0,
     121,   420,   419,     0,   424,     0,     0,     0,     0,     0,
     425,     0,   406,     0,   406,   406,   399,   492,   495,   496,
     491,   294,   294,   493,   494,   497,   505,   552,   484,   343,
     554,     0,     0,   570,   571,   349,   356,   570,   353,   360,
     341,   346,     0,     0,     0,    31,     0,     0,     0,     0,
      23,     0,   374,     0,    52,   104,   576,   574,   575,   567,
       0,   290,     0,   267,   268,   135,   451,   445,   380,     0,
       0,     0,   370,     0,     0,     0,   378,   313,   319,     0,
     294,   309,     0,   311,   319,   310,     0,   327,   335,     0,
     337,   294,     0,   400,     0,   413,   414,   121,   121,   121,
     121,     0,     0,   427,   431,   434,     0,   437,   438,   498,
     499,   579,   580,   572,    27,    28,    30,     0,     0,    34,
      36,     0,    22,   294,     0,     0,    47,   578,   577,   284,
     227,     0,     0,     0,   454,   450,   457,   446,     0,   381,
     379,   371,   373,   385,     0,   377,     0,   316,   294,   323,
     314,   294,   323,   274,   315,   317,   294,   339,   329,   121,
       0,     0,   410,   412,   415,     0,   430,     0,   555,   582,
      32,     0,    26,    24,    25,    48,     0,     0,     0,     0,
       0,     0,   460,   456,   463,   447,     0,     0,   383,   325,
     320,   294,   324,   322,   294,   276,   274,   401,     0,   121,
     121,   429,   406,    33,     0,     0,     0,   455,     0,     0,
       0,   464,   465,   462,   468,   448,   382,     0,   318,   321,
     278,   416,     0,   411,   433,     0,     0,   452,     0,     0,
     461,     0,   471,   467,   469,   384,   121,   228,     0,     0,
     458,   466,     0,   418,     0,     0,   470,   453,     0,   459
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,   234,   148,   235,   236,   237,   238,   239,   240,
     241,   839,   840,   242,   243,   244,   834,   245,   246,   247,
     766,   567,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   495,   641,
     496,   497,    68,    69,   316,   321,   449,   307,   308,   309,
      70,   463,   464,   628,   498,   499,   500,   501,   130,   160,
      75,   132,   348,   349,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   278,   279,   280,    88,
     334,    89,    90,    91,    92,   985,    93,   468,   644,   645,
      94,   748,   749,   433,   434,    95,   265,   138,   139,   775,
     776,   777,   778,   779,   937,   940,   981,   938,    97,   337,
     472,    98,   646,   647,   648,   880,   538,   532,   533,   539,
     540,   502,   841,   466,   767,   768,   769,   770,   771,   503,
     504,   505,   506,   200,   507,   508,   509,   887,   510,   656,
     511,   512,   666,  1022,   513,   514,   515,   516,   461,   761,
     762,   857,   924,   925,   927,   972,   973,   975,  1002,  1003,
    1005,  1023,  1024,    99,   100,   101,   102,   103,   201,   817,
     523,   524,   525,   526,   527,   528,   529,   530,   104,   939,
     150,   151,   152,   153,   154,   155,   300,   156,   106,   107,
     108,   609,   824,   454,   341,   205,   342,   206,   611,   706,
     612,   707
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -792
static const yytype_int16 yypact[] =
{
    1781,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -121,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     -47,   -41,   -40,    58,   109,    15,    51,   129,    73,    76,
      50,    74,    98,   108,  -792,  -792,  -792,   119,   123,  -792,
      91,  3391,    91,  -792,   330,  -792,  1090,  -792,   136,  -110,
     -84,    33,    49,  2050,  2050,  -792,  5874,  5874,  1351,  1351,
    1351,  1351,  1351,  1351,   857,   895,   857,   895,  -792,  -792,
    1090,  -792,  -792,  -792,  1090,  -792,  -792,  -792,  1090,  -792,
    1781,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   -44,  3782,
     271,   169,  -792,  4827,  -792,  -792,  4827,   288,  -792,  4827,
      56,  1090,  4827,  4827,  4827,  1090,  4827,   192,   189,  3431,
      91,   864,  -792,  -792,  -792,  -792,  -792,  -792,  1090,  -792,
    -792,    91,  -792,   124,  -792,   440,  1643,  -792,   -44,  1029,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  1190,  1090,
    -792,  -792,  1090,  1090,  -792,  1090,  -792,  -792,   172,  1090,
    -792,   857,   857,  -792,  1090,  -792,  -792,   179,  1090,  1090,
    -792,  1090,  1090,  -792,  -792,  -792,  1090,  1090,  1090,  1090,
    1090,  3431,  1090,  3431,  1090,  -792,   311,    89,  -792,  -792,
     204,  -792,   -28,  3143,  -792,  -792,   212,  4982,  5021,  5021,
      89,  -792,  -792,  -792,  -792,   223,   257,   262,   270,  5124,
    -792,  -792,  -792,  -792,  4827,  4827,   292,  3676,  4827,  4827,
    4827,  4827,  4827,  4827,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,    42,  -792,   366,
      -9,  -124,   281,    -1,   300,   286,   290,   280,   429,    17,
    -792,   -87,  -792,  -792,   198,  6113,   306,   313,    44,   233,
     266,   319,   283,  -792,  -792,  -792,  -792,  -792,   335,  -792,
      60,   327,   -80,    48,   310,   355,   352,   -44,  -792,   864,
    -792,   965,  -792,  -792,  -792,  1378,   440,  -792,   370,   381,
     -44,   440,   443,  -792,  -792,  -792,    28,  -792,  1378,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,   365,  -792,  3431,  3431,
    -792,   365,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,    89,  -792,  -792,   377,   920,  2447,
    5630,   288,  5504,  -792,  4162,  -792,   390,  -792,  -792,  3273,
    -792,  -792,  4922,  3676,  -792,  3676,  -792,  -792,  -792,  -792,
    1090,  4827,  1090,  1090,  3676,  -792,   395,   406,  5252,  5252,
    -792,  -792,  4827,   332,   414,   421,  -792,  -792,  -792,  -792,
    -792,  -792,    89,  -792,  -792,  4257,    89,  4827,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,
    4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4827,  4352,
    -792,  4827,   156,  2311,  6230,   857,   857,  -792,  -792,  -792,
     416,  -792,   444,  -792,   368,   533,   535,   545,  -792,   666,
    -792,  -792,  -792,  -792,   462,   472,  -792,  4827,  -792,   365,
    -792,   214,   -44,   -44,   478,   264,   440,  -792,  -792,   620,
     645,   492,  -792,   365,   365,  4447,  -792,  -792,   494,   496,
      89,  -792,   513,   476,  4827,   509,   531,  2823,  -792,  4542,
     540,  3504,   542,   555,   537,    28,    89,   -20,  -792,  -792,
     548,  -792,  -792,   570,  1228,   561,   552,  -792,    33,    49,
    2050,  2050,   574,  -792,  -792,  -792,  -792,  2635,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,   124,  5992,   895,
    5874,  1351,  -792,  5630,  -792,  5756,  5874,  1351,  -792,   124,
     -65,  -792,   393,  -792,   117,   117,  1919,  1919,   583,   584,
    -792,  -792,  -792,  -792,   579,  -792,  4637,   585,   588,   591,
     593,   594,   599,   601,   604,  5252,  5252,  1547,  1547,   608,
    -792,  4732,  -792,  -792,  -792,  -792,  -792,   398,  -792,  -792,
     340,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,    -9,    -9,  -124,  -124,
     281,   281,   281,   281,    -1,    -1,   300,   286,   290,   280,
     429,  -792,  -792,  4827,   407,  -792,    97,  3411,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  4827,   614,    44,  -792,  -792,
    -792,   623,   625,   605,  4827,  4827,   627,  -792,   365,  -792,
    -792,  -792,  -792,  -792,   274,  -792,  -792,   271,  -792,  -792,
    4067,  -792,  -792,  1408,   624,  1090,   622,   630,  -792,  1090,
      89,  -792,   -22,  -792,  2823,   771,   635,   615,   -52,  4827,
    -792,    67,  4827,  4827,  -792,    20,    85,  -792,  -792,   745,
     350,  -792,   183,  -792,  1378,  1378,  -792,  -792,  2823,  -792,
    -792,  -792,  -792,  1090,  1090,  -792,  1090,  -792,  1090,    89,
      89,  1090,  1090,  1090,  -792,   124,  -792,  5630,   288,   132,
    1532,    91,  -792,  1090,  -792,  -792,  -792,  -792,  -792,  1090,
    -792,   145,  3356,  1090,  -792,  1090,  -792,  -792,  5378,  -792,
    -792,  -792,   632,   632,  -792,  1090,  1090,    89,   632,  4827,
    4827,  4827,  -792,  -792,  1350,  4067,  -792,  -792,  4827,  -792,
    -792,  4827,   643,   644,   647,   156,  -792,  -792,   650,   648,
    -792,  -792,  -792,  -792,    29,   341,   349,  -792,  -792,  -792,
    -792,   652,   654,    89,  4827,   656,   659,  -792,   661,   660,
    -792,  3547,  -792,   641,  6113,   663,  1487,  -792,   107,   112,
    1408,  -792,  1090,    89,   653,   664,  4827,  2823,  -792,   676,
    3011,  -792,  -792,   436,  -792,   453,   677,   271,   787,    89,
    -792,   680,  -792,   691,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  1090,  1090,  -792,  -792,  -792,  -792,  -792,  5630,  -792,
    -792,   694,   696,   117,  -792,  -792,  -792,   463,  -792,  -792,
    -792,  -792,   700,   702,   282,  -792,    24,    36,   701,   464,
    -792,   705,   703,   708,  -792,  -792,  -792,   -44,   -44,  -792,
    4827,  -792,   469,  -792,  -792,  -792,   -16,   706,  -792,     7,
    4447,  3877,  -792,    89,  4827,  4447,  -792,  -792,   178,  2181,
    1090,  -792,   202,  -792,   178,  -792,   711,  -792,  -792,  4827,
    -792,  1090,   718,  -792,  4827,  -792,  -792,  4827,  2823,  2823,
    2823,   710,   715,  -792,  -792,  -792,  4827,  -792,  -792,  -792,
    -792,    99,  -792,  -792,  -792,  -792,  -792,    89,  4827,  -792,
    -792,  4827,  -792,  1350,  4827,  3972,  -792,  -792,  -792,  -792,
    -792,    29,    89,   724,  -792,   723,    -8,   726,  4827,  -792,
    -792,  -792,  -792,  -792,    35,  -792,  4827,  -792,  1090,   729,
    -792,  1090,   729,  -792,  -792,  -792,  1090,  -792,  -792,  2823,
     474,   714,   896,  -792,  -792,   719,  -792,   482,   743,  -792,
    -792,   360,  -792,  -792,  -792,  -792,   725,   739,  4827,   -16,
      89,   748,  -792,   754,   271,   757,   362,  4827,  -792,  -792,
    -792,  1090,  -792,  -792,  1090,  -792,  -792,  -792,   734,  4827,
    2823,  -792,  -792,  -792,    29,   271,   489,  -792,   755,  4827,
      -8,  -792,  -792,   760,    89,  -792,  -792,   383,  -792,  -792,
    -792,  -792,   762,  -792,  -792,   763,   766,  -792,   271,   510,
    -792,   271,  -792,   765,  -792,  -792,  2823,  -792,  4827,   774,
    -792,  -792,    89,  -792,   546,  4827,  -792,  -792,   559,  -792
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -792,  -792,     0,   294,  -792,  -792,  -792,  -104,  -792,   185,
    -792,  -792,    32,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -350,  -792,  -129,  1116,   343,   353,   275,   344,   539,   534,
     543,   556,   544,  -792,   371,  -792,  -579,   776,    45,  -177,
    -645,    38,  -606,  -792,  -792,  -792,  -792,   667,  -792,  -147,
    -792,  -792,  -792,  -792,     1,    16,     4,   732,  -138,    27,
     885,   845,   628,  -792,  -792,  -109,  -792,   -49,  -792,  -792,
    -792,   -36,   -71,   -26,   -64,    88,  -426,   707,  -792,   784,
    -792,  1251,   769,   -43,  -792,    -5,  -792,  -792,  -792,  -792,
     457,  -792,  -792,   369,  -792,  -792,   418,  -792,    66,   208,
    -792,   216,  -792,  -792,   120,   121,    53,  -622,  -792,  -792,
    -792,   471,   348,  -792,   218,  -792,  -792,  -792,   301,  -792,
     284,   186,  -102,  -265,  -448,   268,   285,  -791,  -792,  -408,
     226,  -792,   -99,   637,  -792,   227,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -198,  -792,  -792,  -792,  -792,   538,   221,
    -792,  -792,    55,  -792,  -792,    19,  -792,  -792,     9,  -792,
    -792,  -792,    -7,  -792,  -792,   934,  -792,  -792,  -792,  -792,
     338,  -503,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   -50,
    -792,  -131,  -120,  -792,   -96,  -792,  -268,    14,   -25,  -792,
     -14,  -396,  -494,   -51,  -792,   560,  -792,  -792,   430,  -578,
     431,  -521
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -552
static const yytype_int16 yytable[] =
{
      65,    71,   162,   171,    73,   199,   267,   266,   302,   163,
     172,   311,   359,   623,   105,   303,    72,   642,   796,   281,
     685,   149,   158,   285,   740,   298,   346,   613,   451,   786,
     166,   175,   565,   455,  -551,   127,   569,   773,    67,   418,
     704,   710,   714,   716,   406,   407,   128,   459,   668,   299,
     304,   214,   112,   431,   273,   109,   467,   204,   928,   214,
      65,    65,    65,   402,   403,   460,    96,   416,   141,   655,
     932,    65,    65,    65,    65,   134,   135,   204,   354,   356,
     357,   273,   382,   383,   384,   273,   977,   168,   177,   142,
     365,   274,   275,   295,   143,    24,    25,   305,   421,   680,
      65,    71,   443,   178,    73,   183,    24,   186,   187,   188,
     419,    24,    25,   695,   105,   144,    72,   271,   274,   275,
     127,   821,   274,   275,   932,   374,   421,   133,   375,   110,
      65,   128,   202,   821,   696,   111,   113,   203,    67,   167,
     176,    65,   417,    65,   292,    65,    65,   792,   450,   340,
     114,    24,    25,    24,   264,   294,   424,   787,   269,  -551,
     134,   270,   845,   669,   272,   922,    96,   282,   283,   284,
     773,   457,   544,   970,   773,   547,   298,   399,   822,    24,
      25,   298,   400,   401,   627,   421,    24,    25,   634,   929,
     822,   116,   408,   409,    24,   291,   797,   335,   638,   639,
     299,   115,   421,   798,   293,   299,   458,    24,   909,   145,
     335,   746,   133,   421,   421,   310,   425,   978,   385,   146,
     910,   118,   386,   387,   310,   145,   421,   117,    62,   426,
     444,   520,   147,   276,   277,   146,   448,   440,   277,   427,
      24,    25,   951,   121,    62,   421,   788,   941,   157,   119,
     941,   548,   120,   549,   375,   122,   375,   176,   550,   176,
     552,   553,   554,   799,    24,   375,   794,    60,   432,   351,
     806,   127,   373,   606,   340,   958,   127,    61,   203,   123,
     203,   422,   128,   607,   800,   872,    62,   128,   667,   124,
     874,   425,   608,   699,    66,   125,    65,   652,   203,   126,
     145,    65,    65,   700,   521,   804,   873,   805,   699,   820,
     146,   875,   701,   203,   427,   685,   292,   982,   700,    62,
     982,   711,   820,   866,   404,   405,   203,   701,   852,   903,
     136,   712,   606,   903,   335,   140,   298,   203,   214,   493,
     701,   531,   607,   534,  1012,   268,   536,   410,   411,   849,
      24,   608,   171,   428,   145,  -509,   517,   936,   535,   172,
     299,   310,  -510,   758,   146,   202,   288,   159,   169,   287,
     203,   610,   610,    62,   310,   420,   421,   835,    60,   883,
     175,   936,   563,   338,   176,   176,   563,   339,    61,   670,
     202,   629,   672,   352,    66,   203,   358,    62,   373,   360,
     373,   630,   631,   702,   708,    96,   557,   558,    96,   373,
     435,   421,   930,   858,   520,   351,    49,   935,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   428,   162,
     171,   127,   570,   361,    96,    96,   163,   172,   362,   297,
     202,   633,   128,   436,   421,   203,   363,   171,   674,   675,
     202,   759,   802,   803,   172,   203,    65,   166,   175,   906,
     438,   421,   907,   908,   604,   162,   171,   681,   372,   745,
     335,   412,   163,   172,   425,   175,   414,   493,   415,   694,
     952,   953,   954,   429,   137,   413,   335,   521,   421,   176,
     430,   336,   445,   166,   175,   966,   437,   427,    65,    65,
      65,    65,    24,    25,   336,    24,    25,   493,   195,   560,
     421,   439,   196,   933,   676,   677,   197,    65,   421,   421,
     469,   442,   739,   853,   658,    24,   661,   421,   311,    65,
     447,   854,   446,   760,    65,    65,    65,    65,   421,   517,
     421,   987,   993,    96,  1006,   616,   617,   452,   703,   709,
     713,   715,   687,   691,   693,   742,   610,   960,   453,    66,
     470,   421,   823,   465,   398,  1025,   167,   176,  1015,   303,
     697,   698,   542,    96,   827,   737,   738,   312,   555,   298,
     313,   314,  1013,   315,   176,   421,   741,   317,   520,   556,
     297,   561,   320,   729,   730,   297,   322,   323,   562,   324,
     325,   893,   167,   176,   326,   327,   328,   329,   330,   882,
     331,   428,   332,   888,   421,   614,   296,   432,  1033,   456,
     615,    96,    96,   832,   833,   618,   146,   619,   336,   146,
     889,   421,   375,   494,    66,    62,    66,   620,    62,   711,
     765,   912,   913,   624,   203,   816,   920,   921,   425,   712,
     335,   988,   421,   625,   493,   632,   649,   635,   701,   992,
     421,   521,    66,    66,   636,   424,  1017,   421,   637,   755,
     756,   427,   358,   133,   127,   651,   564,   643,   493,  -277,
     564,   590,   591,   592,   593,   128,   127,  1030,   421,   335,
     335,   273,   457,   760,   610,    65,   650,   128,   531,    65,
      65,    65,   947,   895,   793,   897,   898,   795,   653,   520,
     654,    65,    65,   517,   134,   135,   659,   169,   662,   534,
      96,   664,   536,  1037,   421,   425,   134,   563,   274,   275,
     621,   663,    74,   622,   535,   765,  1039,   421,   426,   421,
     310,   310,   732,   733,    96,   586,   587,   671,   427,  -361,
     297,   673,   923,   678,   594,   595,   471,   588,   589,   979,
     717,   719,   718,   563,   336,   722,   133,   721,   723,   425,
     724,   494,   725,   657,   836,   837,   373,   726,   133,   727,
     336,   728,   521,   335,    96,   428,   734,   493,   601,   602,
     868,   750,   427,   129,   159,   169,   917,   918,   171,   335,
     752,   494,   753,   754,   757,   172,   782,   780,   783,   859,
     789,   790,   169,   801,   791,   735,   191,    66,   193,   686,
     846,   847,   971,    65,   848,   851,   175,    65,   850,   855,
     159,   169,    74,   856,   517,   -49,   649,   292,   860,   861,
     867,   292,   165,   174,   862,   179,   182,   870,   881,    66,
      66,   879,   884,    96,   890,   892,    96,   366,   367,   368,
     369,   765,   428,   563,   894,   923,     5,   896,    65,    65,
    1001,   901,    65,   902,    65,   811,   812,   904,   129,   905,
     911,   915,    14,   942,   914,   926,   942,   955,   493,   493,
     493,  1016,   916,  1014,    23,   946,   971,   949,     1,   956,
     968,   969,   286,   318,   319,   974,   428,   563,   936,   934,
     990,     8,   137,   989,  1029,   765,    10,  1001,   991,    13,
     820,   995,   335,   994,   999,    17,  -177,  -177,    19,   950,
      30,    31,  1000,  1011,   564,   176,  1004,  1018,  1021,  1026,
    1027,   957,  1028,  1032,   336,   963,   131,   597,   494,   493,
    1035,   596,    48,   961,    96,    96,    96,   598,   161,   170,
     600,   161,   180,   161,   184,   161,   161,   161,   189,   649,
     335,   599,   494,   976,   290,   462,    54,   545,    39,   345,
     333,  1010,   689,   336,   336,   358,   751,   441,   876,    56,
     493,    66,   871,   944,   945,   984,   690,   423,   785,   819,
      49,   878,   831,   842,   335,    41,    42,    43,    44,    45,
      46,    47,    66,   996,   289,    96,   885,   886,   891,  1020,
     843,   564,  1007,   665,   997,  1036,   493,  -178,  -178,   564,
    1031,   131,   335,    59,   198,   818,   743,   744,     0,     0,
    -177,  -177,  -177,  -177,  1019,  -177,     0,     0,     0,     0,
    -177,     0,     0,     0,     0,     0,    96,   564,  -177,  -177,
       0,   774,     0,   781,     0,     0,     0,   784,    66,     0,
       0,     0,   518,  1034,   537,     0,   170,   336,   170,     0,
    1038,   494,     0,     0,    66,     0,     0,     0,   347,     0,
       0,     0,    96,   336,   705,   705,   705,   705,     0,     0,
       0,   807,   808,  -328,   809,     0,   810,     0,   967,   813,
     814,   815,    66,   306,    41,    42,    43,    44,    45,    46,
      47,   825,     0,     0,     0,   345,     0,   826,   345,     0,
       0,   828,     0,   829,     0,     0,     0,   551,     0,     0,
       0,  -178,  -178,  -178,  -178,     0,  -178,     0,   559,     0,
       0,  -178,     0,     0,     0,   564,   998,   564,     0,  -178,
    -178,   568,     0,   169,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,    41,    42,    43,    44,    45,
      46,    47,   494,   494,   494,     0,     0,     0,     0,     0,
     358,     0,   174,   182,   774,     0,     0,   605,   774,     0,
     877,   564,     0,   170,   170,     0,     0,     0,     0,   564,
       0,     0,  -507,     0,     0,     0,   336,     0,   358,     0,
       0,     0,     0,   626,     0,   519,     0,     0,     0,   899,
     900,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,   345,     0,   494,     0,     0,     0,     0,     0,     0,
     345,     0,     0,     0,     0,   518,     0,     0,     0,   705,
     705,     0,     0,     0,   336,     0,     0,     0,     0,   165,
     174,   705,   705,     0,   306,    41,    42,    43,    44,    45,
      46,    47,     0,     0,   494,     0,     0,   174,   943,   182,
       0,     0,     0,     0,   688,   692,     0,     0,   336,   948,
       0,     0,     0,     0,     0,   165,   174,     0,   170,   180,
     184,   189,     0,    41,    42,    43,    44,    45,    46,    47,
     494,     0,     0,     0,   164,   173,   336,   164,   181,   164,
     185,   164,   164,   164,   190,     0,   192,     0,   194,   129,
     370,   371,     0,     0,   376,   377,   378,   379,   380,   381,
       0,     0,     0,     0,     1,     0,   980,     0,     0,   983,
       5,   838,     0,     0,   986,     0,     0,     8,     0,     0,
       0,     0,    10,  -508,     0,    13,    14,     0,     0,     0,
       0,    17,     0,   705,    19,   161,   170,   705,    23,     0,
       0,   747,     0,     0,     0,     0,     0,     0,     0,  1008,
       0,     0,  1009,   170,     0,   180,   189,  -362,   519,     0,
     161,   161,   161,     0,     0,     0,   345,     0,     0,     0,
       0,   161,   170,     0,    30,    31,     0,     0,     0,   518,
       0,     0,   129,     0,    39,    41,    42,    43,    44,    45,
      46,    47,     0,     0,   129,     0,    48,     0,     0,     0,
     537,     0,     0,     0,   350,     0,    49,     0,     0,     0,
     377,   959,   306,    41,    42,    43,    44,    45,    46,    47,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     0,     0,     0,    59,
       0,     0,   131,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,   869,     0,     0,     0,
       0,   345,     0,     0,   844,   582,   583,   584,   585,   585,
     585,   585,   585,   585,   585,   585,   585,   585,   585,   585,
     585,   585,   585,   585,   585,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,    58,     0,   345,     0,     0,
     518,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,   345,     0,     0,     0,     0,     0,     0,    23,
       0,     0,    41,    42,    43,    44,    45,    46,    47,     0,
       0,     0,   519,     0,     0,   131,     0,     0,     0,     0,
       0,   522,  -306,     0,    24,    25,     0,   131,     0,     0,
     350,     0,     0,     0,     0,    30,    31,   772,     0,    24,
       0,   211,   212,   213,   214,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    58,     0,   919,    48,     0,     0,
       0,     0,     0,     0,     0,     0,   345,   345,   174,     0,
       0,   345,     0,   215,   216,   217,   218,     0,     0,     0,
       0,    54,     5,     0,     0,   345,     0,     0,   220,   221,
     222,   223,   377,     0,    56,     0,     0,     0,    14,     0,
       0,  -307,     0,     0,     0,     0,     0,   736,     0,     0,
      23,   226,     0,     0,     0,     0,   772,   962,     0,     0,
     964,   345,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,     0,    24,    25,     0,   699,     0,
       0,     0,   345,   203,     0,     0,    30,    31,   700,   585,
       0,     0,     0,   731,     0,     0,     0,   701,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   164,   173,     0,   170,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
     682,   683,   684,     0,   522,    56,   164,   164,   164,     0,
       0,     0,     0,     0,     1,     2,     3,   164,   173,     4,
       5,     0,     0,     0,     6,     0,     7,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    15,    16,
       0,    17,    18,     0,    19,    20,    21,    22,    23,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
       0,     0,     0,    24,    25,     0,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,   585,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     0,     0,     0,    58,    59,
       0,     0,     1,     2,     3,     0,     0,     4,     5,     0,
       0,     0,     6,     0,     7,     8,     9,     0,     0,     0,
      10,    11,    12,    13,    14,     0,    15,    16,   522,    17,
      18,     0,    19,    20,    21,    22,    23,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
      63,    24,    25,     0,     0,     0,     0,     0,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
      37,    38,    39,     0,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,     1,     2,     3,     0,    59,     4,     5,
       0,     0,     0,     6,     0,     7,     8,     9,     0,   522,
       0,    10,    11,    12,    13,    14,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,   711,     0,     0,     0,     0,
     203,     0,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,    24,    25,   701,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,     0,    41,    42,    43,    44,    45,
      46,    47,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,     0,     2,     3,     0,    59,     4,
       5,     0,     0,     0,     6,     0,     7,     0,     9,     0,
       0,     0,     0,    11,    12,     0,    14,     0,    15,    16,
       0,     0,    18,     0,     0,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,     0,    24,    25,    62,     0,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,     0,     0,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     2,     3,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     7,     0,     9,     0,
       0,     0,     0,    11,    12,     0,    14,     0,    15,    16,
       0,     0,    18,     0,     0,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
     936,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,    25,     0,    62,     0,     0,     0,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,     0,     0,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,     0,     0,     0,     0,     0,
       1,     2,     3,   473,   474,     4,     5,   475,   476,   477,
       6,     0,     7,     8,     9,   478,   479,   480,    10,    11,
      12,    13,    14,   481,    15,    16,   207,    17,    18,   482,
      19,    20,    21,    22,    23,     0,   483,   606,   208,   209,
       0,     0,   203,     0,     0,     0,   210,   607,     0,     0,
       0,     0,     0,     0,     0,     0,   608,     0,     0,    24,
      25,   211,   212,   213,   214,   484,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,    37,    38,
      39,   485,    41,    42,    43,    44,    45,    46,    47,     0,
     486,   487,    48,   215,   216,   217,   218,   219,   488,     0,
       0,   489,    49,     0,     0,     0,     0,     0,   220,   221,
     222,   223,    50,    51,    52,    53,    54,    55,   490,     0,
     491,     0,     0,     0,     0,     0,   224,   225,     0,    56,
      57,   226,     0,     0,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
    -406,   492,   228,   229,   230,   231,   232,   233,     1,     2,
       3,   473,   474,     4,     5,   475,   476,   477,     6,     0,
       7,     8,     9,   478,   479,   480,    10,    11,    12,    13,
      14,   481,    15,    16,   207,    17,    18,   482,    19,    20,
      21,    22,    23,     0,   483,     0,   208,   209,     0,     0,
       0,     0,     0,     0,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,   211,
     212,   213,   214,     0,    26,    27,    28,    29,    30,    31,
      32,     0,    33,    34,    35,    36,    37,    38,    39,   485,
      41,    42,    43,    44,    45,    46,    47,     0,   486,   487,
      48,   215,   216,   217,   218,   219,   488,     0,     0,   489,
      49,     0,     0,     0,     0,     0,   220,   221,   222,   223,
      50,    51,    52,    53,    54,    55,   490,     0,   491,     0,
       0,     0,     0,     0,   224,   225,     0,    56,    57,   226,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   227,     0,     0,     0,     0,     0,     0,  -406,   679,
     228,   229,   230,   231,   232,   233,     1,     2,     3,   473,
     474,     4,     5,   475,   476,   477,     6,     0,     7,     8,
       9,   478,   479,   480,    10,    11,    12,    13,    14,   481,
      15,    16,   207,    17,    18,   482,    19,    20,    21,    22,
      23,     0,   483,     0,   208,   209,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,   211,   212,   213,
     214,     0,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,    39,   485,    41,    42,
      43,    44,    45,    46,    47,     0,   486,   487,    48,   215,
     216,   217,   218,   219,   488,     0,     0,   489,    49,     0,
       0,     0,     0,     0,   220,   221,   222,   223,    50,    51,
      52,    53,    54,    55,   490,     0,   491,     0,     0,     0,
       0,     0,   224,   225,     0,    56,    57,   226,     0,     0,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,     0,  -406,     0,   228,   229,
     230,   231,   232,   233,     1,     2,     3,     0,     0,     4,
       5,     0,     0,     0,     6,     0,     7,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    15,    16,
     207,    17,    18,     0,    19,    20,    21,    22,    23,     0,
       0,     0,   208,   209,     0,     0,     0,     0,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,   211,   212,   213,   214,     0,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,    37,    38,    39,     0,    41,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,   215,   216,   217,
     218,   219,     0,     0,     0,     0,    49,     0,     0,     0,
       0,     0,   220,   221,   222,   223,    50,    51,    52,    53,
      54,    55,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   225,     0,    56,    57,   226,     1,     0,    58,    59,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,    10,     0,     0,    13,    14,     0,
       0,     0,   207,    17,     0,     0,    19,     0,     0,     0,
      23,     0,     0,     0,   208,   209,     0,   227,     0,     0,
       0,     0,   210,     0,     0,     0,   228,   229,   230,   231,
     232,   233,     0,     0,     0,    24,     0,   211,   212,   213,
     214,     0,     0,     0,     0,     0,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    41,    42,
      43,    44,    45,    46,    47,     0,     0,     0,    48,   215,
     216,   217,   218,   219,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   224,   225,     0,    56,     1,   226,     0,     0,
       0,    59,     5,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,    10,     0,     0,    13,    14,     0,
       0,     0,   207,    17,     0,     0,    19,     0,     0,     0,
      23,     0,     0,     0,   208,   209,     0,     0,     0,   227,
       0,     0,   210,     0,     0,   343,     0,     0,   228,   344,
     230,   231,   232,   233,     0,    24,     0,   211,   212,   213,
     214,     0,     0,     0,     0,     0,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    41,    42,
      43,    44,    45,    46,    47,     5,     0,     0,    48,   215,
     216,   217,   218,   219,     0,     0,     0,     0,    49,     0,
       0,    14,     0,     0,   220,   221,   222,   223,     0,     0,
       0,     0,    54,    23,     0,     0,     0,     0,     0,     0,
       5,     0,   224,   225,     0,    56,     0,   226,     0,     0,
       0,    59,     0,     0,     0,     0,    14,     0,    24,     0,
       5,     0,     0,     0,     0,     0,     0,     0,    23,    30,
      31,     0,     0,     0,     0,     0,    14,     0,     0,     0,
       5,    41,    42,    43,    44,    45,    46,    47,    23,   227,
       0,    48,     0,    24,     0,   543,    14,     0,   228,   229,
     230,   231,   232,   233,    30,    31,     0,     0,    23,     0,
       0,     0,     0,     0,     0,    54,    41,    42,    43,    44,
      45,    46,    47,     0,    30,    31,    48,     0,    56,     0,
       0,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,     0,    30,    31,    48,     0,     0,     0,
      54,     0,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    56,     0,     0,    48,     0,     0,     0,
      54,     0,   711,   207,     0,     0,     0,   203,     0,     0,
       0,     0,   712,    56,     0,   208,   209,     0,     0,     0,
      54,   701,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,     0,     0,    24,    60,   211,   212,
     213,   214,     0,     0,     0,     0,   207,    61,     0,     0,
       0,     0,     0,     0,     0,     0,    62,   606,   208,   209,
       0,     0,   203,     0,     0,     0,   210,   607,     0,     0,
     215,   216,   217,   218,   219,     0,   608,     0,     0,    24,
       0,   211,   212,   213,   214,   220,   221,   222,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   224,   225,     0,     0,     0,   226,     0,
       0,     0,     0,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   224,   225,     0,     0,
     227,   226,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,   660,     0,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   208,   209,     0,
       0,     0,     0,   227,     0,   210,     0,   863,   864,     0,
     640,     0,   228,   229,   230,   231,   232,   233,    24,     0,
     211,   212,   213,   214,     0,   865,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,    47,     0,     0,
       0,     0,   215,   216,   217,   218,   219,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   221,   222,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   224,   225,     0,     0,     0,
     226,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
       0,     0,   227,     0,     0,     0,     0,     0,     0,  -406,
       0,   228,   229,   230,   231,   232,   233,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,     0,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,   763,   764,     0,
     640,   931,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,   763,   764,     0,   640,   965,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,   763,   764,     0,
     640,     0,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,   541,     0,     0,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   566,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,   603,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
     640,     0,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,   720,
       0,     0,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
       0,   224,   225,     0,     0,     0,   226,     0,   208,   209,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
       0,   211,   212,   213,   214,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
       0,     0,     0,     0,     0,   735,     0,   228,   229,   230,
     231,   232,   233,   215,   216,   217,   218,   219,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   221,
     222,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,   224,   225,     0,     0,
       0,   226,     0,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,   207,   228,   229,   230,   231,   232,   233,   215,   216,
     217,   218,   219,   208,   209,     0,     0,     0,     0,     0,
       0,   210,     0,   220,   221,   222,   223,     0,     0,     0,
       0,     0,     0,     0,    24,     0,   211,   212,   213,   214,
     207,   224,   225,     0,     0,     0,   226,     0,     0,     0,
       0,     0,   208,   209,     0,     0,     0,     0,     0,     0,
     210,     0,     0,     0,     0,     0,     0,     0,   215,   216,
     217,   218,   219,    24,     0,   211,   212,   213,   214,     0,
       0,     0,     0,   220,   221,   222,   223,     0,   227,     0,
       0,     0,     0,     0,     0,     0,     0,   228,   546,   230,
     231,   232,   233,     0,     0,     0,   226,   215,   216,   217,
     218,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,     0,   226,     0,     0,   353,     0,
       0,     0,     0,     0,     0,   208,   209,   228,   229,   230,
     231,   232,   233,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,     0,   211,   212,
     213,   214,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   216,   217,   218,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,   226,     0,
       4,     5,     0,     0,     0,     6,     0,     7,     8,     9,
       0,     0,     0,    10,    11,    12,    13,    14,     0,    15,
      16,     0,    17,    18,     0,    19,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     364,     0,     0,     0,     0,     0,     0,     0,     0,   228,
     229,   230,   231,   232,   233,    25,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,    39,     0,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,    56,    57,     4,     5,     0,    58,
      59,     6,     0,     7,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,     0,    15,    16,     0,    17,    18,
       0,    19,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   830,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    26,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,    39,     0,    41,    42,    43,    44,    45,    46,    47,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    51,    52,    53,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
      56,    57,     4,     5,     0,     0,    59,     6,     0,     7,
       8,     9,     0,     0,     0,    10,    11,    12,    13,    14,
       0,    15,    16,     0,    17,    18,     0,    19,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,    39,     0,    41,
      42,    43,    44,    45,    46,    47,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,    56,    57,     4,     5,
       0,     0,    59,     6,     0,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,     0,    15,    16,     0,
      17,    18,     0,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    51,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,    56,    57,     4,     5,     0,     0,    59,     6,
       0,     7,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,     0,    15,    16,     0,    17,    18,     0,    19,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,     0,     0,    33,    34,    35,    36,    37,    38,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,    54,    55,     1,     2,     3,
       0,     0,     4,     5,     0,     0,     0,     6,    56,     0,
       8,     9,     0,     0,    59,    10,    11,    12,    13,    14,
       0,    15,    16,     0,    17,     0,     0,    19,     0,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    29,    30,    31,     0,
       0,    33,    34,    35,    36,    37,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,    52,    53,    54,    55,     0,     2,     3,     0,     0,
       4,     5,     0,     0,     0,     6,    56,     7,     0,     9,
       0,     0,    59,     0,    11,    12,     0,    14,     0,    15,
      16,     0,     0,    18,     0,     0,    20,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,     0,    41,    42,    43,
      44,    45,    46,    47,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     2,     3,     0,
       0,     4,     5,     0,    56,    57,     6,     0,     7,     0,
       9,     0,     0,     0,     0,    11,    12,     0,    14,     0,
      15,    16,     0,     0,    18,     0,     0,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    51,
      52,    53,    54,    55,     2,     3,     0,     0,     4,     5,
       0,     0,     0,     6,     0,    56,    57,     9,     0,     0,
       0,     0,    11,    12,     0,    14,     0,    15,    16,     0,
       0,     0,     0,     0,     0,    21,    22,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
      27,    28,    29,    30,    31,     0,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56
};

static const yytype_int16 yycheck[] =
{
       0,     0,    73,    74,     0,   104,   110,   109,   146,    73,
      74,   158,   210,   439,     0,   146,     0,   465,   663,   121,
     523,    71,    72,   125,   603,   145,   203,   423,   296,    51,
      73,    74,   382,   301,    62,    60,   386,   643,     0,   126,
     534,   535,   536,   537,    45,    46,    60,    19,    68,   145,
     146,    67,    92,     9,    25,   176,   321,   108,    51,    67,
      60,    61,    62,   187,   188,    37,     0,    50,   178,   477,
     861,    71,    72,    73,    74,    61,    62,   128,   207,   208,
     209,    25,    40,    41,    42,    25,    51,    73,    74,   199,
     219,    62,    63,   143,   178,    62,    63,   148,   178,   507,
     100,   100,   182,    76,   100,    78,    62,    80,    81,    82,
     197,    62,    63,   178,   100,   199,   100,   117,    62,    63,
     145,   699,    62,    63,   915,   227,   178,    61,   227,   176,
     130,   145,   176,   711,   199,   176,   176,   181,   100,    73,
      74,   141,   125,   143,   130,   145,   146,   199,   295,   177,
      92,    62,    63,    62,   109,   141,   265,   179,   113,    62,
     146,   116,   741,   183,   119,   181,   100,   122,   123,   124,
     776,   302,   349,   181,   780,   352,   296,   186,   699,    62,
      63,   301,   191,   192,   449,   178,    62,    63,   456,   182,
     711,   176,   193,   194,    62,   129,   176,   197,   463,   464,
     296,    92,   178,   183,   138,   301,   302,    62,   184,   176,
     210,   607,   146,   178,   178,   149,   265,   182,   176,   186,
     184,    92,   180,   181,   158,   176,   178,   176,   195,   265,
     182,   340,   199,   177,   178,   186,   287,   177,   178,   265,
      62,    63,   887,   193,   195,   178,   654,   869,   199,   176,
     872,   353,   176,   355,   353,   181,   355,   191,   360,   193,
     362,   363,   364,   178,    62,   364,   199,   176,   268,   203,
     678,   296,   227,   176,   177,   176,   301,   186,   181,   181,
     181,   265,   296,   186,   199,   178,   195,   301,   486,   181,
     178,   340,   195,   176,     0,   176,   296,   474,   181,   176,
     176,   301,   302,   186,   340,   122,   199,   124,   176,   177,
     186,   199,   195,   181,   340,   818,   302,   939,   186,   195,
     942,   176,   177,   771,    43,    44,   181,   195,   754,   823,
       0,   186,   176,   827,   334,   199,   456,   181,    67,   339,
     195,   341,   186,   342,   989,   176,   342,    47,    48,   745,
      62,   195,   423,   265,   176,   183,   340,   179,   342,   423,
     456,   295,   183,   628,   186,   176,   177,    73,    74,   177,
     181,   422,   423,   195,   308,   177,   178,   727,   176,   787,
     423,   179,   382,   197,   318,   319,   386,   183,   186,   488,
     176,   177,   491,   181,   100,   181,   210,   195,   353,   176,
     355,   452,   453,   534,   535,   339,   368,   369,   342,   364,
     177,   178,   860,   763,   523,   349,   105,   865,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   340,   500,
     501,   456,   387,   176,   368,   369,   500,   501,   176,   145,
     176,   177,   456,   177,   178,   181,   176,   518,   498,   499,
     176,   177,   102,   103,   518,   181,   456,   500,   501,   177,
     177,   178,   180,   181,   419,   536,   537,   517,   176,   607,
     470,   185,   536,   537,   523,   518,   196,   477,    49,   529,
     888,   889,   890,   177,    66,   195,   486,   523,   178,   423,
     177,   197,   182,   536,   537,   921,   177,   523,   498,   499,
     500,   501,    62,    63,   210,    62,    63,   507,    90,   177,
     178,   176,    94,   863,   500,   501,    98,   517,   178,   178,
     334,   194,   182,   182,   479,    62,   481,   178,   675,   529,
     178,   182,   177,   637,   534,   535,   536,   537,   178,   523,
     178,   949,   182,   477,   182,   177,   178,   177,   534,   535,
     536,   537,   525,   526,   527,   606,   607,   907,   177,   265,
     183,   178,   700,   198,   198,   182,   500,   501,   994,   700,
     177,   178,   182,   507,   712,   177,   178,   159,   183,   699,
     162,   163,   990,   165,   518,   178,   179,   169,   697,   183,
     296,   177,   174,   555,   556,   301,   178,   179,   177,   181,
     182,   799,   536,   537,   186,   187,   188,   189,   190,   786,
     192,   523,   194,   177,   178,   199,   176,   617,  1026,   176,
     176,   555,   556,   725,   726,    92,   186,    92,   334,   186,
     177,   178,   731,   339,   340,   195,   342,    92,   195,   176,
     640,   177,   178,   181,   181,   695,   177,   178,   697,   186,
     650,   177,   178,   181,   654,   177,   470,    37,   195,   177,
     178,   697,   368,   369,    19,   774,   177,   178,   176,   624,
     625,   697,   486,   607,   699,   199,   382,   183,   678,   183,
     386,   406,   407,   408,   409,   699,   711,   177,   178,   689,
     690,    25,   823,   797,   745,   695,   183,   711,   698,   699,
     700,   701,   879,   802,   659,   804,   805,   662,   199,   818,
     179,   711,   712,   697,   700,   701,   176,   423,   176,   718,
     654,   184,   718,   177,   178,   774,   712,   727,    62,    63,
      64,   176,     0,    67,   718,   735,   177,   178,   774,   178,
     674,   675,   557,   558,   678,   402,   403,   199,   774,   179,
     456,   199,   856,   179,   410,   411,   338,   404,   405,   936,
     177,   182,   178,   763,   470,   177,   700,   182,   177,   818,
     177,   477,   178,   479,   729,   730,   731,   178,   712,   178,
     486,   177,   818,   783,   718,   697,   178,   787,   417,   418,
     774,   177,   818,    61,   500,   501,   847,   848,   869,   799,
     177,   507,   177,   198,   177,   869,   184,   183,   178,   764,
      39,   176,   518,    68,   199,   183,    84,   523,    86,   525,
     177,   177,   926,   823,   177,   177,   869,   827,   178,   177,
     536,   537,   100,   179,   818,   179,   650,   823,   179,   178,
     199,   827,    73,    74,   184,    76,    77,   184,   184,   555,
     556,   198,   176,   787,   177,    68,   790,   220,   221,   222,
     223,   861,   774,   863,   184,   969,     9,   176,   868,   869,
     974,   177,   872,   177,   874,   689,   690,   177,   146,   177,
     179,   178,    25,   869,   179,   179,   872,   177,   888,   889,
     890,   995,   184,   992,    37,   184,  1000,   179,     3,   184,
     176,   178,   126,   171,   172,   179,   818,   907,   179,   864,
      14,    16,   494,   199,  1018,   915,    21,  1021,   199,    24,
     177,   182,   922,   198,   176,    30,    62,    63,    33,   884,
      73,    74,   178,   199,   640,   869,   179,   182,   178,   177,
     177,   896,   176,   178,   650,   913,    61,   413,   654,   949,
     176,   412,    95,   908,   888,   889,   890,   414,    73,    74,
     416,    76,    77,    78,    79,    80,    81,    82,    83,   783,
     970,   415,   678,   928,   129,   308,   119,   349,    83,   203,
     196,   986,   525,   689,   690,   799,   617,   280,   780,   132,
     990,   697,   776,   872,   874,   942,   525,   265,   650,   698,
     105,   783,   718,   735,  1004,    85,    86,    87,    88,    89,
      90,    91,   718,   968,   129,   949,   790,   790,   797,  1000,
     735,   727,   977,   485,   969,  1032,  1026,    62,    63,   735,
    1021,   146,  1032,   138,   100,   697,   606,   606,    -1,    -1,
     176,   177,   178,   179,   999,   181,    -1,    -1,    -1,    -1,
     186,    -1,    -1,    -1,    -1,    -1,   990,   763,   194,   195,
      -1,   643,    -1,   645,    -1,    -1,    -1,   649,   774,    -1,
      -1,    -1,   340,  1028,   342,    -1,   191,   783,   193,    -1,
    1035,   787,    -1,    -1,   790,    -1,    -1,    -1,   203,    -1,
      -1,    -1,  1026,   799,   534,   535,   536,   537,    -1,    -1,
      -1,   683,   684,   183,   686,    -1,   688,    -1,   922,   691,
     692,   693,   818,    84,    85,    86,    87,    88,    89,    90,
      91,   703,    -1,    -1,    -1,   349,    -1,   709,   352,    -1,
      -1,   713,    -1,   715,    -1,    -1,    -1,   361,    -1,    -1,
      -1,   176,   177,   178,   179,    -1,   181,    -1,   372,    -1,
      -1,   186,    -1,    -1,    -1,   861,   970,   863,    -1,   194,
     195,   385,    -1,   869,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,    85,    86,    87,    88,    89,
      90,    91,   888,   889,   890,    -1,    -1,    -1,    -1,    -1,
    1004,    -1,   423,   424,   776,    -1,    -1,   421,   780,    -1,
     782,   907,    -1,   318,   319,    -1,    -1,    -1,    -1,   915,
      -1,    -1,   183,    -1,    -1,    -1,   922,    -1,  1032,    -1,
      -1,    -1,    -1,   447,    -1,   340,    -1,    -1,    -1,   811,
     812,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
      -1,   465,    -1,   949,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,   699,
     700,    -1,    -1,    -1,   970,    -1,    -1,    -1,    -1,   500,
     501,   711,   712,    -1,    84,    85,    86,    87,    88,    89,
      90,    91,    -1,    -1,   990,    -1,    -1,   518,   870,   520,
      -1,    -1,    -1,    -1,   525,   526,    -1,    -1,  1004,   881,
      -1,    -1,    -1,    -1,    -1,   536,   537,    -1,   423,   424,
     425,   426,    -1,    85,    86,    87,    88,    89,    90,    91,
    1026,    -1,    -1,    -1,    73,    74,  1032,    76,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    -1,    87,   607,
     224,   225,    -1,    -1,   228,   229,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,     3,    -1,   938,    -1,    -1,   941,
       9,    11,    -1,    -1,   946,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    21,   183,    -1,    24,    25,    -1,    -1,    -1,
      -1,    30,    -1,   823,    33,   500,   501,   827,    37,    -1,
      -1,   615,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   981,
      -1,    -1,   984,   518,    -1,   520,   521,   179,   523,    -1,
     525,   526,   527,    -1,    -1,    -1,   640,    -1,    -1,    -1,
      -1,   536,   537,    -1,    73,    74,    -1,    -1,    -1,   697,
      -1,    -1,   700,    -1,    83,    85,    86,    87,    88,    89,
      90,    91,    -1,    -1,   712,    -1,    95,    -1,    -1,    -1,
     718,    -1,    -1,    -1,   203,    -1,   105,    -1,    -1,    -1,
     344,   901,    84,    85,    86,    87,    88,    89,    90,    91,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,   138,
      -1,    -1,   607,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,   774,    -1,    -1,    -1,
      -1,   735,    -1,    -1,   738,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,   137,    -1,   771,    -1,    -1,
     818,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,   786,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    -1,
      -1,    -1,   697,    -1,    -1,   700,    -1,    -1,    -1,    -1,
      -1,   340,   184,    -1,    62,    63,    -1,   712,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    73,    74,   199,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,   137,    -1,   850,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   860,   861,   869,    -1,
      -1,   865,    -1,    96,    97,    98,    99,    -1,    -1,    -1,
      -1,   119,     9,    -1,    -1,   879,    -1,    -1,   111,   112,
     113,   114,   546,    -1,   132,    -1,    -1,    -1,    25,    -1,
      -1,   184,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,
      37,   134,    -1,    -1,    -1,    -1,   199,   911,    -1,    -1,
     914,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   818,    -1,    62,    63,    -1,   176,    -1,
      -1,    -1,   936,   181,    -1,    -1,    73,    74,   186,   603,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   195,    85,    86,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   500,   501,    -1,   869,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     519,   520,   521,    -1,   523,   132,   525,   526,   527,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,   536,   537,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      -1,    30,    31,    -1,    33,    34,    35,    36,    37,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,   741,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,    -1,    -1,    -1,   137,   138,
      -1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    -1,    27,    28,   697,    30,
      31,    -1,    33,    34,    35,    36,    37,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,
     199,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   132,   133,     3,     4,     5,    -1,   138,     8,     9,
      -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,   818,
      -1,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      30,    31,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,   195,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132,   133,    -1,     4,     5,    -1,   138,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,   195,    -1,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,     4,     5,    -1,    -1,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,   195,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   133,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    39,   176,    41,    42,
      -1,    -1,   181,    -1,    -1,    -1,    49,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    -1,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    -1,
      93,    94,    95,    96,    97,    98,    99,   100,   101,    -1,
      -1,   104,   105,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,   132,
     133,   134,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    39,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    -1,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    -1,    -1,   104,
     105,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,    -1,
      -1,    -1,    -1,    -1,   129,   130,    -1,   132,   133,   134,
      -1,    -1,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,
     185,   186,   187,   188,   189,   190,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    -1,    93,    94,    95,    96,
      97,    98,    99,   100,   101,    -1,    -1,   104,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,   133,   134,    -1,    -1,
     137,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,   185,   186,
     187,   188,   189,   190,     3,     4,     5,    -1,    -1,     8,
       9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,    -1,   132,   133,   134,     3,    -1,   137,   138,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    -1,   176,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    62,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,   130,    -1,   132,     3,   134,    -1,    -1,
      -1,   138,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    24,    25,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,
      37,    -1,    -1,    -1,    41,    42,    -1,    -1,    -1,   176,
      -1,    -1,    49,    -1,    -1,   182,    -1,    -1,   185,   186,
     187,   188,   189,   190,    -1,    62,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,     9,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,   105,    -1,
      -1,    25,    -1,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,   119,    37,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,   129,   130,    -1,   132,    -1,   134,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    25,    -1,    62,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    73,
      74,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
       9,    85,    86,    87,    88,    89,    90,    91,    37,   176,
      -1,    95,    -1,    62,    -1,   182,    25,    -1,   185,   186,
     187,   188,   189,   190,    73,    74,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    85,    86,    87,    88,
      89,    90,    91,    -1,    73,    74,    95,    -1,   132,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    -1,    73,    74,    95,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,   132,    -1,    -1,    95,    -1,    -1,    -1,
     119,    -1,   176,    29,    -1,    -1,    -1,   181,    -1,    -1,
      -1,    -1,   186,   132,    -1,    41,    42,    -1,    -1,    -1,
     119,   195,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    62,   176,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    29,   186,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   176,    41,    42,
      -1,    -1,   181,    -1,    -1,    -1,    49,   186,    -1,    -1,
      96,    97,    98,    99,   100,    -1,   195,    -1,    -1,    62,
      -1,    64,    65,    66,    67,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
     176,   134,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,   188,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,
      -1,    -1,    -1,   176,    -1,    49,    -1,   180,   181,    -1,
     183,    -1,   185,   186,   187,   188,   189,   190,    62,    -1,
      64,    65,    66,    67,    -1,   198,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    91,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,    -1,
     134,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,   183,
      -1,   185,   186,   187,   188,   189,   190,    85,    86,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,   181,    -1,
     183,   184,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,   180,   181,    -1,   183,   184,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,   181,    -1,
     183,    -1,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,    -1,    -1,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,   179,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,
      -1,    -1,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,   129,   130,    -1,    -1,    -1,   134,    -1,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,   183,    -1,   185,   186,   187,
     188,   189,   190,    96,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,   134,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,   185,   186,   187,   188,   189,   190,    96,    97,
      98,    99,   100,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    64,    65,    66,    67,
      29,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   100,    62,    -1,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,
     188,   189,   190,    -1,    -1,    -1,   134,    96,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,   134,    -1,    -1,   176,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,   185,   186,   187,
     188,   189,   190,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,   188,
     189,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,   134,    -1,
       8,     9,    -1,    -1,    -1,    13,    -1,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    30,    31,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,   188,   189,   190,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,   132,   133,     8,     9,    -1,   137,
     138,    13,    -1,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    27,    28,    -1,    30,    31,
      -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
     132,   133,     8,     9,    -1,    -1,   138,    13,    -1,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    31,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,    79,    80,    81,    82,    83,    -1,    85,
      86,    87,    88,    89,    90,    91,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,   132,   133,     8,     9,
      -1,    -1,   138,    13,    -1,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    27,    28,    -1,
      30,    31,    -1,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    75,    -1,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,   132,   133,     8,     9,    -1,    -1,   138,    13,
      -1,    15,    16,    17,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    31,    -1,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,
      74,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,   120,     3,     4,     5,
      -1,    -1,     8,     9,    -1,    -1,    -1,    13,   132,    -1,
      16,    17,    -1,    -1,   138,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    30,    -1,    -1,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,    -1,     4,     5,    -1,    -1,
       8,     9,    -1,    -1,    -1,    13,   132,    15,    -1,    17,
      -1,    -1,   138,    -1,    22,    23,    -1,    25,    -1,    27,
      28,    -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,     4,     5,    -1,
      -1,     8,     9,    -1,   132,   133,    13,    -1,    15,    -1,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      27,    28,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    74,    75,    -1,
      77,    78,    79,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,
     117,   118,   119,   120,     4,     5,    -1,    -1,     8,     9,
      -1,    -1,    -1,    13,    -1,   132,   133,    17,    -1,    -1,
      -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    79,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   132
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     4,     5,     8,     9,    13,    15,    16,    17,
      21,    22,    23,    24,    25,    27,    28,    30,    31,    33,
      34,    35,    36,    37,    62,    63,    69,    70,    71,    72,
      73,    74,    75,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    95,   105,
     115,   116,   117,   118,   119,   120,   132,   133,   137,   138,
     176,   186,   195,   199,   201,   202,   203,   241,   242,   243,
     250,   254,   255,   256,   257,   260,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   279,   281,
     282,   283,   284,   286,   290,   295,   298,   308,   311,   363,
     364,   365,   366,   367,   378,   387,   388,   389,   390,   176,
     176,   176,    92,   176,    92,    92,   176,   176,    92,   176,
     176,   193,   181,   181,   181,   176,   176,   388,   390,   257,
     258,   260,   261,   298,   387,   387,     0,   296,   297,   298,
     199,   178,   199,   178,   199,   176,   186,   199,   203,   379,
     380,   381,   382,   383,   384,   385,   387,   199,   379,   203,
     259,   260,   272,   274,   281,   282,   283,   298,   387,   203,
     260,   272,   274,   281,   282,   283,   298,   387,   259,   282,
     260,   281,   282,   259,   260,   281,   259,   259,   259,   260,
     281,   257,   281,   257,   281,   296,   296,   296,   365,   332,
     333,   368,   176,   181,   393,   395,   397,    29,    41,    42,
      49,    64,    65,    66,    67,    96,    97,    98,    99,   100,
     111,   112,   113,   114,   129,   130,   134,   176,   185,   186,
     187,   188,   189,   190,   202,   204,   205,   206,   207,   208,
     209,   210,   213,   214,   215,   217,   218,   219,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   296,   322,   207,   176,   238,
     238,   202,   238,    25,    62,    63,   177,   178,   276,   277,
     278,   322,   238,   238,   238,   322,   237,   177,   177,   260,
     261,   298,   387,   298,   387,   379,   176,   203,   382,   384,
     386,   176,   258,   381,   384,   393,    84,   247,   248,   249,
     298,   249,   296,   296,   296,   296,   244,   296,   257,   257,
     296,   245,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   279,   280,   202,   203,   309,   321,   183,
     177,   394,   396,   182,   186,   237,   239,   260,   262,   263,
     281,   298,   181,   176,   222,   176,   222,   222,   321,   343,
     176,   176,   176,   176,   176,   222,   333,   333,   333,   333,
     223,   223,   176,   238,   322,   332,   223,   223,   223,   223,
     223,   223,    40,    41,    42,   176,   180,   181,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,   198,   186,
     191,   192,   187,   188,    43,    44,    45,    46,   193,   194,
      47,    48,   185,   195,   196,    49,    50,   125,   126,   197,
     177,   178,   255,   257,   265,   267,   271,   273,   275,   177,
     177,     9,   202,   293,   294,   177,   177,   177,   177,   176,
     177,   277,   194,   182,   182,   182,   177,   178,   393,   246,
     249,   386,   177,   177,   393,   386,   176,   381,   384,    19,
      37,   348,   247,   251,   252,   198,   323,   323,   287,   321,
     183,   296,   310,     6,     7,    10,    11,    12,    18,    19,
      20,    26,    32,    39,    68,    84,    93,    94,   101,   104,
     121,   123,   184,   202,   203,   238,   240,   241,   254,   255,
     256,   257,   321,   329,   330,   331,   332,   334,   335,   336,
     338,   340,   341,   344,   345,   346,   347,   255,   257,   260,
     265,   271,   281,   370,   371,   372,   373,   374,   375,   376,
     377,   202,   317,   318,   254,   255,   256,   257,   316,   319,
     320,   182,   182,   182,   239,   262,   186,   239,   322,   322,
     322,   237,   322,   322,   322,   183,   183,   241,   241,   237,
     177,   177,   177,   202,   203,   220,   177,   221,   237,   220,
     238,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   223,   223,   223,   223,   224,   224,   225,   225,
     226,   226,   226,   226,   227,   227,   228,   229,   230,   231,
     232,   234,   234,   179,   238,   237,   176,   186,   195,   391,
     393,   398,   400,   391,   199,   176,   177,   178,    92,    92,
      92,    64,    67,   276,   181,   181,   237,   323,   253,   177,
     393,   393,   177,   177,   386,    37,    19,   176,   323,   323,
     183,   239,   324,   183,   288,   289,   312,   313,   314,   321,
     183,   199,   239,   199,   179,   329,   339,   203,   238,   176,
     199,   238,   176,   176,   184,   348,   342,   343,    68,   183,
     332,   199,   332,   199,   379,   379,   387,   387,   179,   184,
     329,   379,   281,   281,   281,   371,   203,   259,   282,   290,
     311,   259,   282,   259,   379,   178,   199,   177,   178,   176,
     186,   195,   381,   387,   392,   395,   399,   401,   381,   387,
     392,   176,   186,   387,   392,   387,   392,   177,   178,   182,
     182,   182,   177,   177,   177,   178,   178,   178,   177,   241,
     241,   176,   209,   209,   178,   183,   223,   177,   178,   182,
     236,   179,   393,   398,   400,   258,   391,   237,   291,   292,
     177,   293,   177,   177,   198,   238,   238,   177,   323,   177,
     207,   349,   350,   180,   181,   202,   220,   324,   325,   326,
     327,   328,   199,   242,   296,   299,   300,   301,   302,   303,
     183,   296,   184,   178,   296,   312,    51,   179,   329,    39,
     176,   199,   199,   238,   199,   238,   240,   176,   183,   178,
     199,    68,   102,   103,   122,   124,   329,   296,   296,   296,
     296,   321,   321,   296,   296,   296,   379,   369,   370,   318,
     177,   399,   401,   258,   392,   296,   296,   258,   296,   296,
      51,   320,   322,   322,   216,   220,   238,   238,    11,   211,
     212,   322,   325,   326,   237,   236,   177,   177,   177,   391,
     178,   177,   276,   182,   182,   177,   179,   351,   220,   238,
     179,   178,   184,   180,   181,   198,   324,   199,   255,   257,
     184,   301,   178,   199,   178,   199,   299,   296,   314,   198,
     315,   184,   239,   329,   176,   330,   335,   337,   177,   177,
     177,   349,    68,   343,   184,   332,   176,   332,   332,   296,
     296,   177,   177,   392,   177,   177,   177,   180,   181,   184,
     184,   179,   177,   178,   179,   178,   184,   393,   393,   237,
     177,   178,   181,   207,   352,   353,   179,   354,    51,   182,
     324,   184,   327,   220,   238,   324,   179,   304,   307,   379,
     305,   307,   387,   296,   305,   304,   184,   239,   296,   179,
     238,   240,   329,   329,   329,   177,   184,   238,   176,   395,
     220,   238,   237,   212,   237,   184,   276,   321,   176,   178,
     181,   207,   355,   356,   179,   357,   238,    51,   182,   239,
     296,   306,   307,   296,   306,   285,   296,   329,   177,   199,
      14,   199,   177,   182,   198,   182,   238,   352,   321,   176,
     178,   207,   358,   359,   179,   360,   182,   238,   296,   296,
     285,   199,   240,   329,   332,   276,   207,   177,   182,   238,
     355,   178,   343,   361,   362,   182,   177,   177,   176,   207,
     177,   358,   178,   329,   238,   176,   362,   177,   238,   177
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
        case 15:
#line 284 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 22:
#line 295 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          set((yyval), ID_generic_selection);
          mto((yyval), (yyvsp[(3) - (6)]));
          stack((yyval)).add(ID_generic_associations).get_sub().swap((irept::subt&)stack((yyvsp[(5) - (6)])).operands());
        }
    break;

  case 23:
#line 305 "parser.y"
    {
          init((yyval)); mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 24:
#line 309 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]); mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 25:
#line 316 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (3)]);
          stack((yyval)).id(ID_generic_association);
          stack((yyval)).set(ID_type_arg, stack((yyvsp[(1) - (3)])));
          stack((yyval)).set(ID_value, stack((yyvsp[(3) - (3)])));
        }
    break;

  case 26:
#line 323 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (3)]);
          stack((yyval)).id(ID_generic_association);
          stack((yyval)).set(ID_type_arg, irept(ID_default));
          stack((yyval)).set(ID_value, stack((yyvsp[(3) - (3)])));
        }
    break;

  case 27:
#line 333 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          stack((yyval)).id(ID_gcc_builtin_va_arg);
          mto((yyval), (yyvsp[(3) - (6)]));
          stack((yyval)).type().swap(stack((yyvsp[(5) - (6)])));
        }
    break;

  case 28:
#line 341 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          stack((yyval)).id(ID_gcc_builtin_types_compatible_p);
          typet &type_arg=(typet &)(stack((yyval)).add(ID_type_arg));
          typet::subtypest &subtypes=type_arg.subtypes();
          subtypes.resize(2);
          subtypes[0].swap(stack((yyvsp[(3) - (6)])));
          subtypes[1].swap(stack((yyvsp[(5) - (6)])));
        }
    break;

  case 29:
#line 354 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_cw_va_arg_typeof);
          stack((yyval)).add(ID_type_arg).swap(stack((yyvsp[(3) - (4)])));
        }
    break;

  case 30:
#line 363 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          stack((yyval)).id(ID_builtin_offsetof);
          stack((yyval)).add(ID_type_arg).swap(stack((yyvsp[(3) - (6)])));
          stack((yyval)).add(ID_designator).swap(stack((yyvsp[(5) - (6)])));
        }
    break;

  case 31:
#line 373 "parser.y"
    {
          init((yyval), ID_designated_initializer);
          stack((yyval)).operands().resize(1);
          stack((yyval)).op0().id(ID_member);
          stack((yyval)).op0().add_source_location()=stack((yyvsp[(1) - (1)])).source_location();
          stack((yyval)).op0().set(ID_component_name, stack((yyvsp[(1) - (1)])).get(ID_C_base_name));
        }
    break;

  case 32:
#line 381 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyvsp[(2) - (3)]), ID_member);
          stack((yyvsp[(2) - (3)])).set(ID_component_name, stack((yyvsp[(3) - (3)])).get(ID_C_base_name));
          mto((yyval), (yyvsp[(2) - (3)]));
        }
    break;

  case 33:
#line 388 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyvsp[(2) - (4)]), ID_index);
          mto((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
          mto((yyval), (yyvsp[(2) - (4)]));
        }
    break;

  case 34:
#line 398 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          set((yyval), ID_forall);
          mto((yyval), (yyvsp[(4) - (6)]));
          mto((yyval), (yyvsp[(5) - (6)]));
          PARSER.pop_scope();
        }
    break;

  case 35:
#line 406 "parser.y"
    {
          // The precedence of this operator is too high; it is meant
          // to bind only very weakly.
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_forall);
          mto((yyval), (yyvsp[(3) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
          PARSER.pop_scope();
        }
    break;

  case 36:
#line 416 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          set((yyval), ID_exists);
          mto((yyval), (yyvsp[(4) - (6)]));
          mto((yyval), (yyvsp[(5) - (6)]));
          PARSER.pop_scope();
        }
    break;

  case 37:
#line 424 "parser.y"
    {
          // The precedence of this operator is too high; it is meant
          // to bind only very weakly.
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_exists);
          mto((yyval), (yyvsp[(3) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
          PARSER.pop_scope();
        }
    break;

  case 38:
#line 436 "parser.y"
    { 
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_statement_expression);
          mto((yyval), (yyvsp[(2) - (3)]));
        }
    break;

  case 40:
#line 447 "parser.y"
    { binary((yyval), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), ID_index, (yyvsp[(3) - (4)])); }
    break;

  case 41:
#line 449 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_function_call);
          stack((yyval)).operands().resize(2);
          stack((yyval)).op0().swap(stack((yyvsp[(1) - (3)])));
          stack((yyval)).op1().clear();
          stack((yyval)).op1().id(ID_arguments);
        }
    break;

  case 42:
#line 458 "parser.y"
    { (yyval)=(yyvsp[(2) - (4)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_function_call);
          stack((yyval)).operands().resize(2);
          stack((yyval)).op0().swap(stack((yyvsp[(1) - (4)])));
          stack((yyval)).op1().swap(stack((yyvsp[(3) - (4)])));
          stack((yyval)).op1().id(ID_arguments);
        }
    break;

  case 43:
#line 467 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)]);
          set((yyval), ID_member);
          mto((yyval), (yyvsp[(1) - (3)]));
          stack((yyval)).set(ID_component_name, stack((yyvsp[(3) - (3)])).get(ID_C_base_name));
        }
    break;

  case 44:
#line 473 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)]);
          set((yyval), ID_ptrmember);
          mto((yyval), (yyvsp[(1) - (3)]));
          stack((yyval)).set(ID_component_name, stack((yyvsp[(3) - (3)])).get(ID_C_base_name));
        }
    break;

  case 45:
#line 479 "parser.y"
    { (yyval)=(yyvsp[(2) - (2)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_postincrement);
          mto((yyval), (yyvsp[(1) - (2)]));
        }
    break;

  case 46:
#line 485 "parser.y"
    { (yyval)=(yyvsp[(2) - (2)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_postdecrement);
          mto((yyval), (yyvsp[(1) - (2)]));
        }
    break;

  case 47:
#line 492 "parser.y"
    {
          exprt tmp(ID_initializer_list);
          tmp.add_source_location()=stack((yyvsp[(4) - (6)])).source_location();
          tmp.operands().swap(stack((yyvsp[(5) - (6)])).operands());
          (yyval)=(yyvsp[(1) - (6)]);
          set((yyval), ID_typecast);
          stack((yyval)).move_to_operands(tmp);
          stack((yyval)).type().swap(stack((yyvsp[(2) - (6)])));
        }
    break;

  case 48:
#line 502 "parser.y"
    {
          // same as above
          exprt tmp(ID_initializer_list);
          tmp.add_source_location()=stack((yyvsp[(4) - (7)])).source_location();
          tmp.operands().swap(stack((yyvsp[(5) - (7)])).operands());
          (yyval)=(yyvsp[(1) - (7)]);
          set((yyval), ID_typecast);
          stack((yyval)).move_to_operands(tmp);
          stack((yyval)).type().swap(stack((yyvsp[(2) - (7)])));
        }
    break;

  case 51:
#line 521 "parser.y"
    {
          init((yyval), ID_expression_list);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 52:
#line 526 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 54:
#line 535 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_preincrement);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 55:
#line 541 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_side_effect);
          stack((yyval)).set(ID_statement, ID_predecrement);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 56:
#line 547 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_address_of);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 57:
#line 552 "parser.y"
    { // this takes the address of a label (a gcc extension)
          (yyval)=(yyvsp[(1) - (2)]);
          irep_idt identifier=PARSER.lookup_label(stack((yyvsp[(2) - (2)])).get(ID_C_base_name));
          set((yyval), ID_address_of);
          stack((yyval)).operands().resize(1);
          stack((yyval)).op0()=stack((yyvsp[(2) - (2)]));
          stack((yyval)).op0().id(ID_label);
          stack((yyval)).op0().set(ID_identifier, identifier);
        }
    break;

  case 58:
#line 562 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_dereference);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 59:
#line 567 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_unary_plus);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 60:
#line 572 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_unary_minus);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 61:
#line 577 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_bitnot);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 62:
#line 582 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_not);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 63:
#line 587 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_sizeof);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 64:
#line 592 "parser.y"
    { (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_sizeof);
          stack((yyval)).add(ID_type_arg).swap(stack((yyvsp[(3) - (4)])));
        }
    break;

  case 65:
#line 597 "parser.y"
    { // note no parentheses for expressions, just like sizeof
          (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_alignof);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 66:
#line 603 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_alignof);
          stack((yyval)).add(ID_type_arg).swap(stack((yyvsp[(3) - (4)])));
        }
    break;

  case 68:
#line 613 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_typecast);
          mto((yyval), (yyvsp[(4) - (4)]));
          stack((yyval)).type().swap(stack((yyvsp[(2) - (4)])));
        }
    break;

  case 69:
#line 620 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_complex_real);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 70:
#line 625 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_complex_imag);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 72:
#line 634 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_mult, (yyvsp[(3) - (3)])); }
    break;

  case 73:
#line 636 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_div, (yyvsp[(3) - (3)])); }
    break;

  case 74:
#line 638 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_mod, (yyvsp[(3) - (3)])); }
    break;

  case 76:
#line 644 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_plus, (yyvsp[(3) - (3)])); }
    break;

  case 77:
#line 646 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_minus, (yyvsp[(3) - (3)])); }
    break;

  case 79:
#line 652 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_shl, (yyvsp[(3) - (3)])); }
    break;

  case 80:
#line 654 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_shr, (yyvsp[(3) - (3)])); }
    break;

  case 82:
#line 660 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_lt, (yyvsp[(3) - (3)])); }
    break;

  case 83:
#line 662 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_gt, (yyvsp[(3) - (3)])); }
    break;

  case 84:
#line 664 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_le, (yyvsp[(3) - (3)])); }
    break;

  case 85:
#line 666 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_ge, (yyvsp[(3) - (3)])); }
    break;

  case 87:
#line 672 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_equal, (yyvsp[(3) - (3)])); }
    break;

  case 88:
#line 674 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_notequal, (yyvsp[(3) - (3)])); }
    break;

  case 90:
#line 680 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_bitand, (yyvsp[(3) - (3)])); }
    break;

  case 92:
#line 686 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_bitxor, (yyvsp[(3) - (3)])); }
    break;

  case 94:
#line 692 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_bitor, (yyvsp[(3) - (3)])); }
    break;

  case 96:
#line 698 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_and, (yyvsp[(3) - (3)])); }
    break;

  case 98:
#line 704 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_or, (yyvsp[(3) - (3)])); }
    break;

  case 100:
#line 713 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_implies, (yyvsp[(3) - (3)])); }
    break;

  case 102:
#line 722 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_equal, (yyvsp[(3) - (3)])); }
    break;

  case 104:
#line 728 "parser.y"
    { (yyval)=(yyvsp[(2) - (5)]);
          stack((yyval)).id(ID_if);
          mto((yyval), (yyvsp[(1) - (5)]));
          mto((yyval), (yyvsp[(3) - (5)]));
          mto((yyval), (yyvsp[(5) - (5)]));
        }
    break;

  case 105:
#line 735 "parser.y"
    { (yyval)=(yyvsp[(2) - (4)]);
          stack((yyval)).id(ID_side_effect);
          stack((yyval)).set(ID_statement, ID_gcc_conditional_expression);
          mto((yyval), (yyvsp[(1) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 107:
#line 746 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign); }
    break;

  case 108:
#line 748 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_mult); }
    break;

  case 109:
#line 750 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_div); }
    break;

  case 110:
#line 752 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_mod); }
    break;

  case 111:
#line 754 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_plus); }
    break;

  case 112:
#line 756 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_minus); }
    break;

  case 113:
#line 758 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_shl); }
    break;

  case 114:
#line 760 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_shr); }
    break;

  case 115:
#line 762 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_bitand); }
    break;

  case 116:
#line 764 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_bitxor); }
    break;

  case 117:
#line 766 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_side_effect, (yyvsp[(3) - (3)])); stack((yyval)).set(ID_statement, ID_assign_bitor); }
    break;

  case 119:
#line 772 "parser.y"
    { binary((yyval), (yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), ID_comma, (yyvsp[(3) - (3)])); }
    break;

  case 121:
#line 781 "parser.y"
    { init((yyval)); stack((yyval)).make_nil(); }
    break;

  case 123:
#line 789 "parser.y"
    {
          // type only, no declarator!
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
        }
    break;

  case 124:
#line 795 "parser.y"
    {
          // type only, no identifier!
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
        }
    break;

  case 128:
#line 807 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]);
          set((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_static_assert(true);
          mto((yyval), (yyvsp[(3) - (6)]));
          mto((yyval), (yyvsp[(5) - (6)]));
        }
    break;

  case 129:
#line 818 "parser.y"
    {
            init((yyval), ID_declaration);
            stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
            PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          }
    break;

  case 130:
#line 824 "parser.y"
    {
          // patch on the initializer
          (yyval)=(yyvsp[(3) - (4)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(4) - (4)])));
        }
    break;

  case 131:
#line 830 "parser.y"
    {
            init((yyval), ID_declaration);
            stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
            PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          }
    break;

  case 132:
#line 836 "parser.y"
    {
          // patch on the initializer
          (yyval)=(yyvsp[(3) - (4)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(4) - (4)])));
        }
    break;

  case 133:
#line 842 "parser.y"
    {
            // just add the declarator
            PARSER.add_declarator(stack((yyvsp[(1) - (3)])), stack((yyvsp[(3) - (3)])));
            // Needs to be done before initializer, as we want to see that identifier
            // already there!
          }
    break;

  case 134:
#line 849 "parser.y"
    {
          // patch on the initializer
          (yyval)=(yyvsp[(1) - (5)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(5) - (5)])));
        }
    break;

  case 135:
#line 858 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          stack((yyval)).id(ID_asm);
          stack((yyval)).set(ID_flavor, ID_gcc);
          stack((yyval)).operands().swap(stack((yyvsp[(4) - (5)])).operands());
        }
    break;

  case 137:
#line 869 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 139:
#line 877 "parser.y"
    {
          init((yyval));
        }
    break;

  case 141:
#line 886 "parser.y"
    {
            (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // type attribute
            
            // the symbol has to be visible during initialization
            init((yyval), ID_declaration);
            stack((yyval)).type().swap(stack((yyvsp[(1) - (3)])));
            PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
          }
    break;

  case 142:
#line 895 "parser.y"
    {
          // add the initializer
          (yyval)=(yyvsp[(4) - (5)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(5) - (5)])));
        }
    break;

  case 143:
#line 902 "parser.y"
    {
            (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)]));
            
            // the symbol has to be visible during initialization
            init((yyval), ID_declaration);
            stack((yyval)).type().swap(stack((yyvsp[(1) - (3)])));
            PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
          }
    break;

  case 144:
#line 911 "parser.y"
    {
          // add the initializer
          (yyval)=(yyvsp[(4) - (5)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(5) - (5)])));
        }
    break;

  case 145:
#line 918 "parser.y"
    {
            // type attribute goes into declarator
            (yyvsp[(3) - (4)])=merge((yyvsp[(4) - (4)]), (yyvsp[(3) - (4)]));
            PARSER.add_declarator(stack((yyvsp[(1) - (4)])), stack((yyvsp[(3) - (4)])));
          }
    break;

  case 146:
#line 924 "parser.y"
    {
          // add in the initializer
          (yyval)=(yyvsp[(1) - (6)]);
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(6) - (6)])));
        }
    break;

  case 158:
#line 950 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 160:
#line 955 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 161:
#line 959 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 163:
#line 967 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 164:
#line 974 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 166:
#line 982 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 169:
#line 993 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_atomic); }
    break;

  case 170:
#line 994 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_const); }
    break;

  case 171:
#line 995 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_restrict); }
    break;

  case 172:
#line 996 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_volatile); }
    break;

  case 173:
#line 997 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_cprover_atomic); }
    break;

  case 174:
#line 998 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_ptr32); }
    break;

  case 175:
#line 999 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_ptr64); }
    break;

  case 176:
#line 1000 "parser.y"
    { (yyval)=(yyvsp[(1) - (4)]); set((yyval), ID_msc_based); mto((yyval), (yyvsp[(3) - (4)])); }
    break;

  case 183:
#line 1017 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 184:
#line 1024 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 185:
#line 1028 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 186:
#line 1032 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 187:
#line 1036 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 188:
#line 1043 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); // type attribute
        }
    break;

  case 189:
#line 1047 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 190:
#line 1051 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 191:
#line 1055 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 192:
#line 1063 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 193:
#line 1067 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 194:
#line 1071 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 196:
#line 1080 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 197:
#line 1084 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 198:
#line 1091 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 199:
#line 1095 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 200:
#line 1099 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 201:
#line 1106 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 202:
#line 1110 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 203:
#line 1114 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 204:
#line 1121 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 205:
#line 1125 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 206:
#line 1129 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 207:
#line 1136 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 208:
#line 1140 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 209:
#line 1144 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 210:
#line 1151 "parser.y"
    { (yyval) = (yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_typeof);
          mto((yyval), (yyvsp[(3) - (4)]));
        }
    break;

  case 211:
#line 1156 "parser.y"
    { (yyval) = (yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_typeof);
          stack((yyval)).set(ID_type_arg, stack((yyvsp[(3) - (4)])));
        }
    break;

  case 213:
#line 1165 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 214:
#line 1169 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 215:
#line 1173 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 216:
#line 1180 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_atomic_type_specifier);
          stack_type((yyval)).subtype()=stack_type((yyvsp[(3) - (4)]));
        }
    break;

  case 218:
#line 1190 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 219:
#line 1194 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 220:
#line 1198 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 221:
#line 1205 "parser.y"
    {
          stack((yyval)).id(stack((yyval)).get(ID_identifier));
        }
    break;

  case 222:
#line 1209 "parser.y"
    {
          stack((yyval)).id(stack((yyval)).get(ID_identifier));
        }
    break;

  case 223:
#line 1213 "parser.y"
    {
          stack((yyval)).id(ID_restrict);
        }
    break;

  case 225:
#line 1221 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]); mto((yyval), (yyvsp[(3) - (4)]));
        }
    break;

  case 226:
#line 1225 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]); mto((yyval), (yyvsp[(3) - (4)]));
        }
    break;

  case 227:
#line 1229 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (6)]); mto((yyval), (yyvsp[(3) - (6)])); mto((yyval), (yyvsp[(5) - (6)]));
        }
    break;

  case 228:
#line 1233 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (10)]); mto((yyval), (yyvsp[(3) - (10)])); mto((yyval), (yyvsp[(5) - (10)])); mto((yyval), (yyvsp[(7) - (10)])); mto((yyval), (yyvsp[(9) - (10)]));
        }
    break;

  case 229:
#line 1236 "parser.y"
    { init((yyval), ID_nil); }
    break;

  case 230:
#line 1241 "parser.y"
    {
          init((yyval)); mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 231:
#line 1245 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]); mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 232:
#line 1252 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]); set((yyval), ID_msc_declspec);
          stack((yyval)).operands().swap(stack((yyvsp[(3) - (4)])).operands());
        }
    break;

  case 233:
#line 1257 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]); set((yyval), ID_msc_declspec);
        }
    break;

  case 234:
#line 1264 "parser.y"
    {
          init((yyval), ID_nil);
        }
    break;

  case 236:
#line 1271 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_typedef); }
    break;

  case 237:
#line 1272 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_extern); }
    break;

  case 238:
#line 1273 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_static); }
    break;

  case 239:
#line 1274 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_auto); }
    break;

  case 240:
#line 1275 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_register); }
    break;

  case 241:
#line 1276 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_inline); }
    break;

  case 242:
#line 1277 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_thread_local); }
    break;

  case 243:
#line 1278 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_asm); }
    break;

  case 244:
#line 1279 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 245:
#line 1283 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_int); }
    break;

  case 246:
#line 1284 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_int8); }
    break;

  case 247:
#line 1285 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_int16); }
    break;

  case 248:
#line 1286 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_int32); }
    break;

  case 249:
#line 1287 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_int64); }
    break;

  case 250:
#line 1288 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_char); }
    break;

  case 251:
#line 1289 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_short); }
    break;

  case 252:
#line 1290 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_long); }
    break;

  case 253:
#line 1291 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_float); }
    break;

  case 254:
#line 1292 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_float80); }
    break;

  case 255:
#line 1293 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_float128); }
    break;

  case 256:
#line 1294 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_int128); }
    break;

  case 257:
#line 1295 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_decimal32); }
    break;

  case 258:
#line 1296 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_decimal64); }
    break;

  case 259:
#line 1297 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_gcc_decimal128); }
    break;

  case 260:
#line 1298 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_double); }
    break;

  case 261:
#line 1299 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_signed); }
    break;

  case 262:
#line 1300 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_unsigned); }
    break;

  case 263:
#line 1301 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_void); }
    break;

  case 264:
#line 1302 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_c_bool); }
    break;

  case 265:
#line 1303 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_complex); }
    break;

  case 266:
#line 1305 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_custom_bv);
          stack((yyval)).add(ID_size).swap(stack((yyvsp[(3) - (4)])));
        }
    break;

  case 267:
#line 1311 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (7)]);
          set((yyval), ID_custom_floatbv);
          stack((yyval)).add(ID_size).swap(stack((yyvsp[(3) - (7)])));
          stack((yyval)).add(ID_f).swap(stack((yyvsp[(6) - (7)])));
        }
    break;

  case 268:
#line 1318 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (7)]);
          set((yyval), ID_custom_fixedbv);
          stack((yyval)).add(ID_size).swap(stack((yyvsp[(3) - (7)])));
          stack((yyval)).add(ID_f).swap(stack((yyvsp[(6) - (7)])));
        }
    break;

  case 269:
#line 1324 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_proper_bool); }
    break;

  case 273:
#line 1335 "parser.y"
    { (yyval)=(yyvsp[(1) - (4)]); stack_type((yyval)).subtype().swap(stack((yyvsp[(2) - (4)]))); }
    break;

  case 274:
#line 1339 "parser.y"
    {
          init((yyval));
          if(!PARSER.pragma_pack.empty() &&
             PARSER.pragma_pack.back().is_one())
            set((yyval), ID_packed);
        }
    break;

  case 275:
#line 1351 "parser.y"
    {
            // an anon struct/union with body
          }
    break;

  case 276:
#line 1357 "parser.y"
    {
          // save the members
          stack((yyvsp[(1) - (9)])).add(ID_components).get_sub().swap(
            (irept::subt &)stack((yyvsp[(6) - (9)])).operands());

          // throw in the gcc attributes
          (yyval)=merge((yyvsp[(1) - (9)]), merge((yyvsp[(2) - (9)]), merge((yyvsp[(8) - (9)]), (yyvsp[(9) - (9)]))));
        }
    break;

  case 277:
#line 1369 "parser.y"
    {
            // A struct/union with tag and body.
            PARSER.add_tag_with_body(stack((yyvsp[(4) - (4)])));
            stack((yyvsp[(1) - (4)])).set(ID_tag, stack((yyvsp[(4) - (4)])));
          }
    break;

  case 278:
#line 1377 "parser.y"
    {
          // save the members
          stack((yyvsp[(1) - (10)])).add(ID_components).get_sub().swap(
            (irept::subt &)stack((yyvsp[(7) - (10)])).operands());

          // throw in the gcc attributes
          (yyval)=merge((yyvsp[(1) - (10)]), merge((yyvsp[(2) - (10)]), merge((yyvsp[(9) - (10)]), (yyvsp[(10) - (10)]))));
        }
    break;

  case 279:
#line 1389 "parser.y"
    {
            // a struct/union with tag but without body
            stack((yyvsp[(1) - (4)])).set(ID_tag, stack((yyvsp[(4) - (4)])));
          }
    break;

  case 280:
#line 1394 "parser.y"
    {
          stack((yyvsp[(1) - (6)])).set(ID_components, ID_nil);
          // type attributes
          (yyval)=merge((yyvsp[(1) - (6)]), merge((yyvsp[(2) - (6)]), (yyvsp[(6) - (6)])));
        }
    break;

  case 281:
#line 1403 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_struct); }
    break;

  case 282:
#line 1405 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); set((yyval), ID_union); }
    break;

  case 283:
#line 1410 "parser.y"
    {
          init((yyval), ID_expression_list);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 284:
#line 1415 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 285:
#line 1423 "parser.y"
    {
          init((yyval), ID_expression_list);
        }
    break;

  case 287:
#line 1431 "parser.y"
    {
          init((yyval));
        }
    break;

  case 288:
#line 1435 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          stack((yyval)).id(ID_gcc_attribute);
          stack((yyval)).set(ID_identifier, ID_const);
        }
    break;

  case 289:
#line 1441 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          stack((yyval)).id(ID_gcc_attribute);
        }
    break;

  case 290:
#line 1446 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          stack((yyval)).id(ID_gcc_attribute);
          stack((yyval)).operands().swap(stack((yyvsp[(3) - (4)])).operands());
        }
    break;

  case 292:
#line 1456 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
        }
    break;

  case 293:
#line 1463 "parser.y"
    { (yyval)=(yyvsp[(4) - (6)]); }
    break;

  case 294:
#line 1468 "parser.y"
    {
          init((yyval));
        }
    break;

  case 297:
#line 1477 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 298:
#line 1484 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); set((yyval), ID_packed); }
    break;

  case 299:
#line 1486 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); set((yyval), ID_transparent_union); }
    break;

  case 300:
#line 1488 "parser.y"
    { (yyval)=(yyvsp[(1) - (5)]); set((yyval), ID_vector); stack((yyval)).add(ID_size)=stack((yyvsp[(3) - (5)])); }
    break;

  case 301:
#line 1490 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); set((yyval), ID_aligned); }
    break;

  case 302:
#line 1492 "parser.y"
    { (yyval)=(yyvsp[(1) - (5)]); set((yyval), ID_aligned); stack((yyval)).set(ID_size, stack((yyvsp[(3) - (5)]))); }
    break;

  case 303:
#line 1494 "parser.y"
    { (yyval)=(yyvsp[(1) - (5)]); set((yyval), ID_gcc_attribute_mode); stack((yyval)).set(ID_size, stack((yyvsp[(3) - (5)])).get(ID_identifier)); }
    break;

  case 304:
#line 1496 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); set((yyval), ID_static); }
    break;

  case 306:
#line 1502 "parser.y"
    {
          init((yyval), ID_declaration_list);
        }
    break;

  case 308:
#line 1510 "parser.y"
    {
          init((yyval), ID_declaration_list);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 309:
#line 1515 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 312:
#line 1525 "parser.y"
    {
          init((yyval), ID_declaration);
        }
    break;

  case 314:
#line 1538 "parser.y"
    {
          (yyvsp[(2) - (3)])=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));

          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_member(true);
          stack((yyval)).type().swap(stack((yyvsp[(2) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(3) - (3)])));
        }
    break;

  case 315:
#line 1547 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(3) - (3)])));
        }
    break;

  case 316:
#line 1557 "parser.y"
    {
          if(!PARSER.pragma_pack.empty() &&
             !PARSER.pragma_pack.back().is_zero())
            stack((yyvsp[(2) - (3)])).set(ID_C_alignment, PARSER.pragma_pack.back());

          (yyvsp[(2) - (3)])=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));

          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_member(true);
          stack((yyval)).type().swap(stack((yyvsp[(2) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(3) - (3)])));
        }
    break;

  case 317:
#line 1570 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(3) - (3)])));
        }
    break;

  case 318:
#line 1578 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);

          if(stack((yyvsp[(2) - (3)])).is_not_nil())
            make_subtype((yyval), (yyvsp[(2) - (3)]));

          if(stack((yyvsp[(3) - (3)])).is_not_nil()) // type attribute
            (yyval)=merge((yyvsp[(3) - (3)]), (yyval));
        }
    break;

  case 319:
#line 1588 "parser.y"
    {
          init((yyval), ID_abstract);
        }
    break;

  case 320:
#line 1592 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          stack_type((yyval)).subtype()=typet(ID_abstract);

          if(stack((yyvsp[(2) - (2)])).is_not_nil()) // type attribute
            (yyval)=merge((yyvsp[(2) - (2)]), (yyval));
        }
    break;

  case 321:
#line 1603 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          if(stack((yyvsp[(2) - (3)])).is_not_nil())
            make_subtype((yyval), (yyvsp[(2) - (3)]));
          
          if(stack((yyvsp[(3) - (3)])).is_not_nil()) // type attribute
            (yyval)=merge((yyvsp[(3) - (3)]), (yyval));
        }
    break;

  case 322:
#line 1612 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          stack_type((yyval)).subtype()=typet(ID_abstract);

          if(stack((yyvsp[(2) - (2)])).is_not_nil()) // type attribute
            (yyval)=merge((yyvsp[(2) - (2)]), (yyval));
        }
    break;

  case 323:
#line 1623 "parser.y"
    {
          init((yyval), ID_nil);
        }
    break;

  case 325:
#line 1631 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_c_bit_field);
          stack_type((yyval)).set(ID_size, stack((yyvsp[(2) - (2)])));
          stack_type((yyval)).subtype().id(ID_abstract);
        }
    break;

  case 326:
#line 1642 "parser.y"
    {
            // an anon enum
          }
    break;

  case 327:
#line 1647 "parser.y"
    {
          stack((yyvsp[(1) - (7)])).operands().swap(stack((yyvsp[(5) - (7)])).operands());
          (yyval)=merge((yyvsp[(1) - (7)]), merge((yyvsp[(2) - (7)]), (yyvsp[(7) - (7)]))); // throw in the gcc attributes
        }
    break;

  case 328:
#line 1654 "parser.y"
    {
            // an enum with tag
            stack((yyvsp[(1) - (3)])).set(ID_tag, stack((yyvsp[(3) - (3)])));
          }
    break;

  case 329:
#line 1660 "parser.y"
    {
          stack((yyvsp[(1) - (8)])).operands().swap(stack((yyvsp[(6) - (8)])).operands());
          (yyval)=merge((yyvsp[(1) - (8)]), merge((yyvsp[(2) - (8)]), (yyvsp[(8) - (8)]))); // throw in the gcc attributes
        }
    break;

  case 330:
#line 1668 "parser.y"
    {
          stack((yyvsp[(1) - (4)])).id(ID_c_enum_tag); // tag only
          stack((yyvsp[(1) - (4)])).set(ID_tag, stack((yyvsp[(3) - (4)])));
          (yyval)=merge((yyvsp[(1) - (4)]), merge((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]))); // throw in the gcc attributes
        }
    break;

  case 331:
#line 1676 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          set((yyval), ID_c_enum);
        }
    break;

  case 332:
#line 1684 "parser.y"
    {
          init((yyval), ID_declaration_list);
        }
    break;

  case 334:
#line 1692 "parser.y"
    {
          init((yyval), ID_declaration_list);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 335:
#line 1697 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 336:
#line 1702 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
        }
    break;

  case 337:
#line 1709 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_enum_constant(true);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(1) - (3)])));
          to_ansi_c_declaration(stack((yyval))).add_initializer(stack((yyvsp[(3) - (3)])));
        }
    break;

  case 338:
#line 1719 "parser.y"
    {
          init((yyval));
          stack((yyval)).make_nil();
        }
    break;

  case 339:
#line 1724 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
        }
    break;

  case 341:
#line 1732 "parser.y"
    {
          typet tmp(ID_ellipsis);
          (yyval)=(yyvsp[(1) - (3)]);
          stack_type((yyval)).move_to_subtypes(tmp);
        }
    break;

  case 342:
#line 1741 "parser.y"
    {
          init((yyval), ID_parameters);
          mts((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 343:
#line 1746 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mts((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 344:
#line 1753 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type()=typet(ID_KnR);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(1) - (1)])));
        }
    break;

  case 345:
#line 1762 "parser.y"
    {
          init((yyval), ID_parameters);
          mts((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 346:
#line 1767 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mts((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 347:
#line 1775 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (1)])));
          exprt declarator=exprt(ID_abstract);
          PARSER.add_declarator(stack((yyval)), declarator);
        }
    break;

  case 348:
#line 1783 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 349:
#line 1790 "parser.y"
    {
          (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // type attribute to go into declarator
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
        }
    break;

  case 350:
#line 1798 "parser.y"
    {
          // the second tree is really the declarator -- not part
          // of the type!
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 351:
#line 1807 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (1)])));
          exprt declarator=exprt(ID_abstract);
          PARSER.add_declarator(stack((yyval)), declarator);
        }
    break;

  case 352:
#line 1815 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 353:
#line 1822 "parser.y"
    {
          (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // type attribute to go into declarator
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
        }
    break;

  case 354:
#line 1830 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (1)])));
          exprt declarator=exprt(ID_abstract);
          PARSER.add_declarator(stack((yyval)), declarator);
        }
    break;

  case 355:
#line 1838 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 356:
#line 1845 "parser.y"
    {
          (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // type attribute to go into declarator
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
        }
    break;

  case 357:
#line 1853 "parser.y"
    {
          // the second tree is really the declarator -- not part of the type!
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 358:
#line 1861 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (1)])));
          exprt declarator=exprt(ID_abstract);
          PARSER.add_declarator(stack((yyval)), declarator);
        }
    break;

  case 359:
#line 1869 "parser.y"
    {
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 360:
#line 1876 "parser.y"
    {
          (yyvsp[(2) - (3)])=merge((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // type attribute to go into declarator
          init((yyval), ID_declaration);
          to_ansi_c_declaration(stack((yyval))).set_is_parameter(true);
          to_ansi_c_declaration(stack((yyval))).type().swap(stack((yyvsp[(1) - (3)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (3)])));
        }
    break;

  case 363:
#line 1892 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 364:
#line 1896 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
          make_subtype((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 365:
#line 1901 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 366:
#line 1905 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
          make_subtype((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 367:
#line 1913 "parser.y"
    {
          newstack((yyval));
          stack((yyval)).make_nil();
        }
    break;

  case 368:
#line 1918 "parser.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 370:
#line 1929 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyval), ID_initializer_list);
          stack((yyval)).operands().swap(stack((yyvsp[(2) - (3)])).operands());
        }
    break;

  case 371:
#line 1935 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_initializer_list);
          stack((yyval)).operands().swap(stack((yyvsp[(2) - (4)])).operands());
        }
    break;

  case 372:
#line 1944 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          exprt tmp;
          tmp.swap(stack((yyval)));
          stack((yyval)).clear();
          stack((yyval)).move_to_operands(tmp);
        }
    break;

  case 373:
#line 1952 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 375:
#line 1961 "parser.y"
    {
          init((yyval));
          set((yyval), ID_initializer_list);
          stack((yyval)).operands().clear();
        }
    break;

  case 377:
#line 1971 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (3)]);
          stack((yyval)).id(ID_designated_initializer);
          stack((yyval)).add(ID_designator).swap(stack((yyvsp[(1) - (3)])));
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 378:
#line 1979 "parser.y"
    {
          init((yyval), ID_designated_initializer);
          stack((yyval)).add(ID_designator).swap(stack((yyvsp[(1) - (2)])));
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 379:
#line 1985 "parser.y"
    {
          // yet another GCC speciality
          (yyval)=(yyvsp[(2) - (3)]);
          stack((yyval)).id(ID_designated_initializer);
          exprt designator;
          exprt member(ID_member);
          member.set(ID_component_name, stack((yyvsp[(1) - (3)])).get(ID_C_base_name));
          designator.move_to_operands(member);
          stack((yyval)).add(ID_designator).swap(designator);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 380:
#line 2000 "parser.y"
    {
          init((yyval));
          stack((yyvsp[(1) - (2)])).id(ID_member);
          stack((yyvsp[(1) - (2)])).set(ID_component_name, stack((yyvsp[(2) - (2)])).get(ID_C_base_name));
          mto((yyval), (yyvsp[(1) - (2)]));
        }
    break;

  case 381:
#line 2007 "parser.y"
    {
          init((yyval));
          stack((yyvsp[(1) - (3)])).id(ID_index);
          mto((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
          mto((yyval), (yyvsp[(1) - (3)]));
        }
    break;

  case 382:
#line 2014 "parser.y"
    {
          // TODO
          init((yyval));
          stack((yyvsp[(1) - (5)])).id(ID_index);
          mto((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]));
          mto((yyval), (yyvsp[(1) - (5)]));
        }
    break;

  case 383:
#line 2022 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          stack((yyvsp[(2) - (4)])).id(ID_index);
          mto((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));
          mto((yyval), (yyvsp[(2) - (4)]));
        }
    break;

  case 384:
#line 2029 "parser.y"
    {
          // TODO
          (yyval)=(yyvsp[(1) - (6)]);
          stack((yyvsp[(2) - (6)])).id(ID_index);
          mto((yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]));
          mto((yyval), (yyvsp[(2) - (6)]));
        }
    break;

  case 385:
#line 2037 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          stack((yyvsp[(2) - (3)])).id(ID_member);
          stack((yyvsp[(2) - (3)])).set(ID_component_name, stack((yyvsp[(3) - (3)])).get(ID_C_base_name));
          mto((yyval), (yyvsp[(2) - (3)]));
        }
    break;

  case 398:
#line 2064 "parser.y"
    {
          init((yyval));
          statement((yyval), ID_decl);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 399:
#line 2073 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (3)]);
          statement((yyval), ID_label);
          irep_idt identifier=PARSER.lookup_label(stack((yyvsp[(1) - (3)])).get(ID_C_base_name));
          stack((yyval)).set(ID_label, identifier);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 400:
#line 2081 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          statement((yyval), ID_switch_case);
          mto((yyval), (yyvsp[(2) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 401:
#line 2088 "parser.y"
    {
          // this is a GCC extension
          (yyval)=(yyvsp[(1) - (6)]);
          statement((yyval), ID_gcc_switch_case_range);
          mto((yyval), (yyvsp[(2) - (6)]));
          mto((yyval), (yyvsp[(4) - (6)]));
          mto((yyval), (yyvsp[(6) - (6)]));
        }
    break;

  case 402:
#line 2097 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          statement((yyval), ID_switch_case);
          stack((yyval)).operands().push_back(nil_exprt());
          mto((yyval), (yyvsp[(3) - (3)]));
          stack((yyval)).set(ID_default, true);
        }
    break;

  case 403:
#line 2108 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (3)]);
          statement((yyval), ID_block);
          stack((yyval)).set(ID_C_end_location, stack((yyvsp[(3) - (3)])).source_location());
          PARSER.pop_scope();
        }
    break;

  case 404:
#line 2115 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (4)]);
          statement((yyval), ID_block);
          stack((yyval)).set(ID_C_end_location, stack((yyvsp[(4) - (4)])).source_location());
          stack((yyval)).operands().swap(stack((yyvsp[(3) - (4)])).operands());
          PARSER.pop_scope();
        }
    break;

  case 405:
#line 2123 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (4)]);
          statement((yyval), ID_asm);
          stack((yyval)).set(ID_C_end_location, stack((yyvsp[(4) - (4)])).source_location());
          mto((yyval), (yyvsp[(3) - (4)]));
          PARSER.pop_scope();
        }
    break;

  case 406:
#line 2134 "parser.y"
    {
          unsigned prefix=++PARSER.current_scope().compound_counter;
          PARSER.new_scope(i2string(prefix)+"::");
        }
    break;

  case 407:
#line 2142 "parser.y"
    {
          init((yyval));
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 408:
#line 2147 "parser.y"
    {
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 409:
#line 2154 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);

          if(stack((yyvsp[(1) - (2)])).is_nil())
            statement((yyval), ID_skip);
          else
          {
            statement((yyval), ID_expression);
            mto((yyval), (yyvsp[(1) - (2)]));
          }
        }
    break;

  case 410:
#line 2169 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          statement((yyval), ID_ifthenelse);
          stack((yyval)).operands().reserve(3);
          mto((yyval), (yyvsp[(3) - (5)]));
          mto((yyval), (yyvsp[(5) - (5)]));
          stack((yyval)).copy_to_operands(nil_exprt());
        }
    break;

  case 411:
#line 2178 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (7)]);
          statement((yyval), ID_ifthenelse);
          stack((yyval)).operands().reserve(3);
          mto((yyval), (yyvsp[(3) - (7)]));
          mto((yyval), (yyvsp[(5) - (7)]));
          mto((yyval), (yyvsp[(7) - (7)]));
        }
    break;

  case 412:
#line 2187 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          statement((yyval), ID_switch);
          stack((yyval)).operands().reserve(2);
          mto((yyval), (yyvsp[(3) - (5)]));
          mto((yyval), (yyvsp[(5) - (5)]));
        }
    break;

  case 415:
#line 2203 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          statement((yyval), ID_while);
          stack((yyval)).operands().reserve(2);
          mto((yyval), (yyvsp[(3) - (5)]));
          mto((yyval), (yyvsp[(5) - (5)]));
        }
    break;

  case 416:
#line 2211 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (7)]);
          statement((yyval), ID_dowhile);
          stack((yyval)).operands().reserve(2);
          mto((yyval), (yyvsp[(5) - (7)]));
          mto((yyval), (yyvsp[(2) - (7)]));
        }
    break;

  case 417:
#line 2219 "parser.y"
    {
            // In C99 and upwards, for(;;) has a scope
            if(PARSER.for_has_scope)
            {
              unsigned prefix=++PARSER.current_scope().compound_counter;
              PARSER.new_scope(i2string(prefix)+"::");
            }
          }
    break;

  case 418:
#line 2231 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (9)]);
          statement((yyval), ID_for);
          stack((yyval)).operands().reserve(4);
          mto((yyval), (yyvsp[(4) - (9)]));
          mto((yyval), (yyvsp[(5) - (9)]));
          mto((yyval), (yyvsp[(7) - (9)]));
          mto((yyval), (yyvsp[(9) - (9)]));

          if(PARSER.for_has_scope)
            PARSER.pop_scope(); // remove the C99 for-scope
        }
    break;

  case 419:
#line 2247 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          if(stack((yyvsp[(2) - (3)])).id()==ID_symbol)
          {
            statement((yyval), ID_goto);
            irep_idt identifier=PARSER.lookup_label(stack((yyvsp[(2) - (3)])).get(ID_C_base_name));
            stack((yyval)).set(ID_destination, identifier);
          }
          else
          {
            // this is a gcc extension.
            // the original grammar uses identifier_or_typedef_name
            statement((yyval), ID_gcc_computed_goto);
            mto((yyval), (yyvsp[(2) - (3)]));
          }
        }
    break;

  case 420:
#line 2264 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          statement((yyval), ID_goto);
          irep_idt identifier=PARSER.lookup_label(stack((yyvsp[(2) - (3)])).get(ID_C_base_name));
          stack((yyval)).set(ID_destination, identifier);
        }
    break;

  case 421:
#line 2271 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); statement((yyval), ID_continue); }
    break;

  case 422:
#line 2273 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); statement((yyval), ID_break); }
    break;

  case 423:
#line 2275 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); statement((yyval), ID_return); }
    break;

  case 424:
#line 2277 "parser.y"
    { (yyval)=(yyvsp[(1) - (3)]); statement((yyval), ID_return); mto((yyval), (yyvsp[(2) - (3)])); }
    break;

  case 425:
#line 2282 "parser.y"
    { 
          (yyval)=(yyvsp[(1) - (3)]);
          statement((yyval), ID_gcc_local_label);
          
          // put these into the scope
          forall_operands(it, stack((yyvsp[(2) - (3)])))
          {
            // labels have a separate name space
            irep_idt base_name=it->get(ID_identifier);
            irep_idt id="label-"+id2string(base_name);
            ansi_c_parsert::identifiert &i=PARSER.current_scope().name_map[id];
            i.id_class=ANSI_C_LOCAL_LABEL;
            i.base_name=base_name;
          }

          stack((yyval)).add(ID_label).get_sub().swap((irept::subt&)stack((yyvsp[(2) - (3)])).operands());
        }
    break;

  case 426:
#line 2303 "parser.y"
    {
          init((yyval));
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 427:
#line 2308 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 429:
#line 2319 "parser.y"
    { (yyval)=(yyvsp[(1) - (6)]);
          statement((yyval), ID_asm);
          stack((yyval)).set(ID_flavor, ID_gcc);
          stack((yyval)).operands().swap(stack((yyvsp[(4) - (6)])).operands());
        }
    break;

  case 430:
#line 2325 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          statement((yyval), ID_asm);
          stack((yyval)).set(ID_flavor, ID_gcc);
          stack((yyval)).operands().resize(5);
          stack((yyval)).op0()=stack((yyvsp[(4) - (5)]));
        }
    break;

  case 431:
#line 2336 "parser.y"
    { (yyval)=(yyvsp[(1) - (4)]);
          statement((yyval), ID_asm);
          stack((yyval)).set(ID_flavor, ID_msc);
          mto((yyval), (yyvsp[(3) - (4)]));
        }
    break;

  case 432:
#line 2342 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]);
          statement((yyval), ID_asm);
          stack((yyval)).set(ID_flavor, ID_msc);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 433:
#line 2352 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (7)]);
          statement((yyval), ID_msc_try_except);
          mto((yyval), (yyvsp[(2) - (7)]));
          mto((yyval), (yyvsp[(5) - (7)]));
          mto((yyval), (yyvsp[(7) - (7)]));
        }
    break;

  case 434:
#line 2361 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          statement((yyval), ID_msc_try_finally);
          mto((yyval), (yyvsp[(2) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 435:
#line 2368 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          statement((yyval), ID_msc_leave);
        }
    break;

  case 436:
#line 2376 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          statement((yyval), ID_CPROVER_throw);
        }
    break;

  case 437:
#line 2382 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          statement((yyval), ID_CPROVER_try_catch);
          mto((yyval), (yyvsp[(2) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 438:
#line 2390 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          statement((yyval), ID_CPROVER_try_finally);
          mto((yyval), (yyvsp[(2) - (4)]));
          mto((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 444:
#line 2416 "parser.y"
    {
          init((yyval));
          stack((yyval)).operands().resize(5);
          stack((yyval)).operands()[0]=stack((yyvsp[(1) - (1)]));
        }
    break;

  case 445:
#line 2422 "parser.y"
    {
          init((yyval));
          stack((yyval)).operands().resize(5);
          stack((yyval)).operands()[0]=stack((yyvsp[(1) - (2)]));
          stack((yyval)).operands()[1]=stack((yyvsp[(2) - (2)]));
        }
    break;

  case 446:
#line 2429 "parser.y"
    {
          init((yyval));
          stack((yyval)).operands().resize(5);
          stack((yyval)).operands()[0]=stack((yyvsp[(1) - (3)]));
          stack((yyval)).operands()[1]=stack((yyvsp[(2) - (3)]));
          stack((yyval)).operands()[2]=stack((yyvsp[(3) - (3)]));
        }
    break;

  case 447:
#line 2437 "parser.y"
    {
          init((yyval));
          stack((yyval)).operands().resize(5);
          stack((yyval)).operands()[0]=stack((yyvsp[(1) - (4)]));
          stack((yyval)).operands()[1]=stack((yyvsp[(2) - (4)]));
          stack((yyval)).operands()[2]=stack((yyvsp[(3) - (4)]));
          stack((yyval)).operands()[3]=stack((yyvsp[(4) - (4)]));
        }
    break;

  case 448:
#line 2446 "parser.y"
    {
          init((yyval));
          stack((yyval)).operands().resize(5);
          stack((yyval)).operands()[0]=stack((yyvsp[(1) - (5)]));
          stack((yyval)).operands()[1]=stack((yyvsp[(2) - (5)]));
          stack((yyval)).operands()[2]=stack((yyvsp[(3) - (5)]));
          stack((yyval)).operands()[3]=stack((yyvsp[(4) - (5)]));
          stack((yyval)).operands()[4]=stack((yyvsp[(5) - (5)]));
        }
    break;

  case 450:
#line 2462 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
        }
    break;

  case 452:
#line 2470 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (4)]);
          stack((yyval)).id(ID_gcc_asm_output);
          stack((yyval)).move_to_operands(stack((yyvsp[(1) - (4)])), stack((yyvsp[(3) - (4)]))); 
        }
    break;

  case 453:
#line 2477 "parser.y"
    {
          (yyval)=(yyvsp[(5) - (7)]);
          stack((yyval)).id(ID_gcc_asm_output);
          stack((yyval)).move_to_operands(stack((yyvsp[(4) - (7)])), stack((yyvsp[(6) - (7)]))); 
        }
    break;

  case 454:
#line 2486 "parser.y"
    {
          init((yyval), irep_idt());
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 455:
#line 2491 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 456:
#line 2499 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
        }
    break;

  case 458:
#line 2507 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (4)]);
          stack((yyval)).id(ID_gcc_asm_input);
          stack((yyval)).move_to_operands(stack((yyvsp[(1) - (4)])), stack((yyvsp[(3) - (4)]))); 
        }
    break;

  case 459:
#line 2514 "parser.y"
    {
          (yyval)=(yyvsp[(5) - (7)]);
          stack((yyval)).id(ID_gcc_asm_input);
          stack((yyval)).move_to_operands(stack((yyvsp[(4) - (7)])), stack((yyvsp[(6) - (7)]))); 
        }
    break;

  case 460:
#line 2523 "parser.y"
    {
          init((yyval), irep_idt());
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 461:
#line 2528 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 462:
#line 2536 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
        }
    break;

  case 464:
#line 2544 "parser.y"
    {
          init((yyval), ID_gcc_asm_clobbered_register);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 465:
#line 2552 "parser.y"
    {
          init((yyval), irep_idt());
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 466:
#line 2557 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 467:
#line 2565 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
        }
    break;

  case 469:
#line 2573 "parser.y"
    {
          init((yyval));
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 470:
#line 2578 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          mto((yyval), (yyvsp[(3) - (3)]));
        }
    break;

  case 471:
#line 2586 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          irep_idt identifier=PARSER.lookup_label(stack((yyval)).get(ID_C_base_name));
          stack((yyval)).id(ID_label);
          stack((yyval)).set(ID_identifier, identifier);
        }
    break;

  case 476:
#line 2605 "parser.y"
    {
          // put into global list of items
          PARSER.copy_item(to_ansi_c_declaration(stack((yyvsp[(1) - (1)]))));
        }
    break;

  case 477:
#line 2610 "parser.y"
    {
          PARSER.copy_item(to_ansi_c_declaration(stack((yyvsp[(1) - (1)]))));
        }
    break;

  case 480:
#line 2619 "parser.y"
    {
          // Not obvious what to do with this.
        }
    break;

  case 481:
#line 2627 "parser.y"
    {
          // The head is a declaration with one declarator,
          // and the body becomes the 'value'.
          (yyval)=(yyvsp[(1) - (2)]);
          ansi_c_declarationt &ansi_c_declaration=
            to_ansi_c_declaration(stack((yyval)));
            
          assert(ansi_c_declaration.declarators().size()==1);
          ansi_c_declaration.add_initializer(stack((yyvsp[(2) - (2)])));
          
          // Kill the scope that 'function_head' creates.
          PARSER.pop_scope();
          
          // We are no longer in any function.
          PARSER.set_function(irep_idt());
        }
    break;

  case 483:
#line 2651 "parser.y"
    {
          init((yyval));
        }
    break;

  case 485:
#line 2659 "parser.y"
    {
          init((yyval), ID_decl_block);
          mto((yyval), (yyvsp[(1) - (1)]));
        }
    break;

  case 486:
#line 2664 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          mto((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 489:
#line 2678 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 490:
#line 2682 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 491:
#line 2689 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 492:
#line 2693 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 493:
#line 2697 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 494:
#line 2701 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 495:
#line 2709 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 496:
#line 2713 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 497:
#line 2717 "parser.y"
    {
          (yyval)=merge((yyvsp[(1) - (3)]), merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])));
        }
    break;

  case 498:
#line 2725 "parser.y"
    {
          stack((yyvsp[(2) - (4)])).set(ID_tag, stack((yyvsp[(3) - (4)])));
          (yyval)=merge((yyvsp[(1) - (4)]), merge((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])));
        }
    break;

  case 499:
#line 2730 "parser.y"
    {
          stack((yyvsp[(2) - (4)])).id(ID_c_enum_tag);
          stack((yyvsp[(2) - (4)])).set(ID_tag, stack((yyvsp[(3) - (4)])));
          (yyval)=merge((yyvsp[(1) - (4)]), merge((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])));
        }
    break;

  case 503:
#line 2746 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 504:
#line 2752 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
        }
    break;

  case 505:
#line 2758 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(3) - (3)])));
        }
    break;

  case 506:
#line 2766 "parser.y"
    {
          init((yyval), ID_declaration);
          irept return_type(ID_int);
          stack((yyval)).type().swap(return_type);
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(1) - (1)])));
          create_function_scope((yyval));
        }
    break;

  case 507:
#line 2774 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          create_function_scope((yyval));
        }
    break;

  case 508:
#line 2781 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          create_function_scope((yyval));
        }
    break;

  case 509:
#line 2788 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          create_function_scope((yyval));
        }
    break;

  case 510:
#line 2795 "parser.y"
    {
          init((yyval), ID_declaration);
          stack((yyval)).type().swap(stack((yyvsp[(1) - (2)])));
          PARSER.add_declarator(stack((yyval)), stack((yyvsp[(2) - (2)])));
          create_function_scope((yyval));
        }
    break;

  case 516:
#line 2816 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          make_subtype((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 519:
#line 2826 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 520:
#line 2831 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
          do_pointer((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
        }
    break;

  case 521:
#line 2839 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 522:
#line 2841 "parser.y"
    {
          /* note: this is a pointer ($2) to a function ($4) */
          /* or an array ($4)! */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 524:
#line 2852 "parser.y"
    {
          (yyval)=(yyvsp[(3) - (4)]);
          do_pointer((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
        }
    break;

  case 525:
#line 2857 "parser.y"
    {
          // not sure where the type qualifiers belong
          (yyval)=merge((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
          do_pointer((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]));
        }
    break;

  case 526:
#line 2863 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 527:
#line 2868 "parser.y"
    {
          (yyval)=merge((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]));
          do_pointer((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
        }
    break;

  case 528:
#line 2876 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 529:
#line 2878 "parser.y"
    {        /* note: this is a function ($3) with a typedef name ($2) */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(3) - (4)]));
        }
    break;

  case 530:
#line 2883 "parser.y"
    {
          /* note: this is a pointer ($2) to a function ($4) */
          /* or an array ($4)! */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 532:
#line 2894 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 536:
#line 2905 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 537:
#line 2910 "parser.y"
    {
          // This is an Apple extension to C/C++/Objective C.
          // http://en.wikipedia.org/wiki/Blocks_(C_language_extension)
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 538:
#line 2917 "parser.y"
    {
          // the type_qualifier_list is for the pointer,
          // and not the identifier_declarator
          stack_type((yyvsp[(1) - (3)])).id(ID_pointer);
          stack_type((yyvsp[(1) - (3)])).subtype()=typet(ID_abstract);
          (yyvsp[(2) - (3)])=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)])); // dest=$2
          make_subtype((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // dest=$3
          (yyval)=(yyvsp[(3) - (3)]);
        }
    break;

  case 539:
#line 2930 "parser.y"
    {
          /* note: this is a function or array ($2) with name ($1) */
          (yyval)=(yyvsp[(1) - (2)]);
          make_subtype((yyval), (yyvsp[(2) - (2)]));
        }
    break;

  case 540:
#line 2936 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 541:
#line 2938 "parser.y"
    {
          /* note: this is a pointer ($2) to a function ($4) */
          /* or an array ($4)! */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 542:
#line 2948 "parser.y"
    {
          // We remember the last declarator for the benefit
          // of function argument scoping.
          PARSER.current_scope().last_declarator=
            stack((yyvsp[(1) - (1)])).get(ID_identifier);
        }
    break;

  case 543:
#line 2955 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)]); }
    break;

  case 550:
#line 2975 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyval), ID_code);
          stack_type((yyval)).subtype()=typet(ID_abstract);
          stack_type((yyval)).add(ID_parameters);
          stack_type((yyval)).set(ID_C_KnR, true);
        }
    break;

  case 551:
#line 2983 "parser.y"
    {
            // Use last declarator (i.e., function name) to name
            // the scope.
            PARSER.new_scope(
              id2string(PARSER.current_scope().last_declarator)+"::");
          }
    break;

  case 552:
#line 2992 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (5)]);
          set((yyval), ID_code);
          stack_type((yyval)).subtype()=typet(ID_abstract);
          stack_type((yyval)).add(ID_parameters).get_sub().
            swap((irept::subt &)(stack_type((yyvsp[(3) - (5)])).subtypes()));
          PARSER.pop_scope();
          adjust_KnR_parameters(stack((yyval)).add(ID_parameters), stack((yyvsp[(5) - (5)])));
          stack((yyval)).set(ID_C_KnR, true);
        }
    break;

  case 554:
#line 3007 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_code);
          stack_type((yyval)).add(ID_parameters);
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 555:
#line 3014 "parser.y"
    {
            // Use last declarator (i.e., function name) to name
            // the scope.
            PARSER.new_scope(
              id2string(PARSER.current_scope().last_declarator)+"::");
          }
    break;

  case 556:
#line 3022 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyval), ID_code);
          stack_type((yyval)).subtype()=typet(ID_abstract);
          stack_type((yyval)).add(ID_parameters).get_sub().
            swap((irept::subt &)(stack_type((yyvsp[(3) - (4)])).subtypes()));
          PARSER.pop_scope();
        }
    break;

  case 557:
#line 3034 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (2)]);
          set((yyval), ID_array);
          stack_type((yyval)).subtype()=typet(ID_abstract);
          stack_type((yyval)).add(ID_size).make_nil();
        }
    break;

  case 558:
#line 3041 "parser.y"
    {
          // this is C99: e.g., restrict, const, etc
          // The type qualifier belongs to the array, not the
          // contents of the array, nor the size.
          set((yyvsp[(1) - (3)]), ID_array);
          stack_type((yyvsp[(1) - (3)])).subtype()=typet(ID_abstract);
          stack_type((yyvsp[(1) - (3)])).add(ID_size).make_nil();
          (yyval)=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]));
        }
    break;

  case 559:
#line 3051 "parser.y"
    {
          // these should be allowed in prototypes only
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyval), ID_array);
          stack_type((yyval)).subtype()=typet(ID_abstract);
          stack_type((yyval)).add(ID_size).make_nil();
        }
    break;

  case 560:
#line 3059 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (3)]);
          set((yyval), ID_array);
          stack_type((yyval)).add(ID_size).swap(stack((yyvsp[(2) - (3)])));
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 561:
#line 3066 "parser.y"
    {
          // The type qualifier belongs to the array, not the
          // contents of the array, nor the size.
          set((yyvsp[(1) - (4)]), ID_array);
          stack_type((yyvsp[(1) - (4)])).add(ID_size).swap(stack((yyvsp[(3) - (4)])));
          stack_type((yyvsp[(1) - (4)])).subtype()=typet(ID_abstract);
          (yyval)=merge((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)])); // dest=$2
        }
    break;

  case 562:
#line 3075 "parser.y"
    {
          // we need to push this down
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyvsp[(2) - (4)]), ID_array);
          stack_type((yyvsp[(2) - (4)])).add(ID_size).swap(stack((yyvsp[(3) - (4)])));
          stack_type((yyvsp[(2) - (4)])).subtype()=typet(ID_abstract);
          make_subtype((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
        }
    break;

  case 563:
#line 3084 "parser.y"
    {
          // these should be allowed in prototypes only
          // we need to push this down
          (yyval)=(yyvsp[(1) - (4)]);
          set((yyvsp[(2) - (4)]), ID_array);
          stack_type((yyvsp[(2) - (4)])).add(ID_size).make_nil();
          stack_type((yyvsp[(2) - (4)])).subtype()=typet(ID_abstract);
          make_subtype((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
        }
    break;

  case 564:
#line 3097 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          set((yyval), ID_pointer);
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 565:
#line 3103 "parser.y"
    {
          // The type_qualifier_list belongs to the pointer,
          // not to the (missing) abstract declarator.
          set((yyvsp[(1) - (2)]), ID_pointer);
          stack_type((yyvsp[(1) - (2)])).subtype()=typet(ID_abstract);
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 566:
#line 3111 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 567:
#line 3116 "parser.y"
    {
          // The type_qualifier_list belongs to the pointer,
          // not to the abstract declarator.
          stack_type((yyvsp[(1) - (3)])).id(ID_pointer);
          stack_type((yyvsp[(1) - (3)])).subtype()=typet(ID_abstract);
          (yyvsp[(2) - (3)])=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)])); // dest=$2
          make_subtype((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // dest=$3
          (yyval)=(yyvsp[(3) - (3)]);
        }
    break;

  case 568:
#line 3126 "parser.y"
    {
          // This is an Apple extension to C/C++/Objective C.
          // http://en.wikipedia.org/wiki/Blocks_(C_language_extension)
          (yyval)=(yyvsp[(1) - (1)]);
          set((yyval), ID_block_pointer);
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 569:
#line 3137 "parser.y"
    {
          (yyval)=(yyvsp[(1) - (1)]);
          set((yyval), ID_pointer);
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 570:
#line 3143 "parser.y"
    {
          // The type_qualifier_list belongs to the pointer,
          // not to the (missing) abstract declarator.
          set((yyvsp[(1) - (2)]), ID_pointer);
          stack_type((yyvsp[(1) - (2)])).subtype()=typet(ID_abstract);
          (yyval)=merge((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)]));
        }
    break;

  case 571:
#line 3151 "parser.y"
    {
          (yyval)=(yyvsp[(2) - (2)]);
          do_pointer((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
        }
    break;

  case 572:
#line 3156 "parser.y"
    {
          // The type_qualifier_list belongs to the pointer,
          // not to the (missing) abstract declarator.
          stack((yyvsp[(1) - (3)])).id(ID_pointer);
          stack_type((yyvsp[(1) - (3)])).subtype()=typet(ID_abstract);
          (yyvsp[(2) - (3)])=merge((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)])); // dest=$2
          make_subtype((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])); // dest=$3
          (yyval)=(yyvsp[(3) - (3)]);
        }
    break;

  case 573:
#line 3166 "parser.y"
    {
          // This is an Apple extension to C/C++/Objective C.
          // http://en.wikipedia.org/wiki/Blocks_(C_language_extension)
          (yyval)=(yyvsp[(1) - (1)]);
          set((yyval), ID_block_pointer);
          stack_type((yyval)).subtype()=typet(ID_abstract);
        }
    break;

  case 574:
#line 3177 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 575:
#line 3179 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 576:
#line 3181 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 577:
#line 3183 "parser.y"
    {
          /* note: this is a pointer ($2) to a function or array ($4) */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 578:
#line 3189 "parser.y"
    {
          /* note: this is a pointer ($2) to a function or array ($4) */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;

  case 579:
#line 3198 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 580:
#line 3200 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 582:
#line 3203 "parser.y"
    {
          /* note: this is a pointer ($2) to a function ($4) */
          (yyval)=(yyvsp[(2) - (4)]);
          make_subtype((yyval), (yyvsp[(4) - (4)]));
        }
    break;


/* Line 1267 of yacc.c.  */
#line 7377 "ansi_c_y.tab.cpp"
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


#line 3210 "parser.y"


