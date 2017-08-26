/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILELOOP = 261,
    PRINT = 262,
    PRINTLN = 263,
    READVAR = 264,
    EXIT_COMMAND = 265,
    CODE_BLOCK = 266,
    DECL_BLOCK = 267,
    DATATYPE = 268,
    EQUATE = 269,
    PLUS = 270,
    MINUS = 271,
    MULTIPLY = 272,
    DIVIDE = 273,
    MODULO = 274,
    RGTSHFT = 275,
    LFTSHFT = 276,
    LT = 277,
    GT = 278,
    LE = 279,
    GE = 280,
    EQL = 281,
    NTEQL = 282,
    AND = 283,
    OR = 284,
    NUMBER = 285,
    ARRAY_SIZE = 286,
    IDENTIFIER = 287,
    TEXT = 288
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILELOOP 261
#define PRINT 262
#define PRINTLN 263
#define READVAR 264
#define EXIT_COMMAND 265
#define CODE_BLOCK 266
#define DECL_BLOCK 267
#define DATATYPE 268
#define EQUATE 269
#define PLUS 270
#define MINUS 271
#define MULTIPLY 272
#define DIVIDE 273
#define MODULO 274
#define RGTSHFT 275
#define LFTSHFT 276
#define LT 277
#define GT 278
#define LE 279
#define GE 280
#define EQL 281
#define NTEQL 282
#define AND 283
#define OR 284
#define NUMBER 285
#define ARRAY_SIZE 286
#define IDENTIFIER 287
#define TEXT 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "parser.y" /* yacc.c:1909  */
int num; char id; char* str; char* size

#line 123 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
