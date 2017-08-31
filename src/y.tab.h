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
    GOTO = 260,
    FOR = 261,
    WHILELOOP = 262,
    PRINT = 263,
    PRINTLN = 264,
    READVAR = 265,
    EXIT_COMMAND = 266,
    CODE_BLOCK = 267,
    DECL_BLOCK = 268,
    DATATYPE = 269,
    EQUATE = 270,
    PLUS = 271,
    MINUS = 272,
    MULTIPLY = 273,
    DIVIDE = 274,
    MODULO = 275,
    RGTSHFT = 276,
    LFTSHFT = 277,
    LT = 278,
    GT = 279,
    LE = 280,
    GE = 281,
    EQL = 282,
    NTEQL = 283,
    AND = 284,
    OR = 285,
    ARRAY_INDEX = 286,
    NUMBER = 287,
    ARRAY_SIZE = 288,
    IDENTIFIER = 289,
    TEXT = 290
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define GOTO 260
#define FOR 261
#define WHILELOOP 262
#define PRINT 263
#define PRINTLN 264
#define READVAR 265
#define EXIT_COMMAND 266
#define CODE_BLOCK 267
#define DECL_BLOCK 268
#define DATATYPE 269
#define EQUATE 270
#define PLUS 271
#define MINUS 272
#define MULTIPLY 273
#define DIVIDE 274
#define MODULO 275
#define RGTSHFT 276
#define LFTSHFT 277
#define LT 278
#define GT 279
#define LE 280
#define GE 281
#define EQL 282
#define NTEQL 283
#define AND 284
#define OR 285
#define ARRAY_INDEX 286
#define NUMBER 287
#define ARRAY_SIZE 288
#define IDENTIFIER 289
#define TEXT 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "parser.y" /* yacc.c:1909  */
int num; char* id; char* str; char* size; char* index

#line 127 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
