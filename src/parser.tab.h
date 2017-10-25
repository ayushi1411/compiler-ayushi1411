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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ELSE = 258,
    GOTO = 259,
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
    IF = 271,
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:1909  */

	int num; char* id; char* str; char* size; char* index;
	class ASTIdNode* ASTIdNode ; 
	class ASTVariable* ASTVariable ;
	class ASTTerm* ASTTerm;
	class ASTExp* ASTExp;
	class ASTAssignment* ASTAssignment;
	class ASTPrintStmt* ASTPrintStmt;
	class ASTFinalPrintStmt* ASTFinalPrintStmt;
	class ASTCodeStmt* ASTCodeStmt;
	class ASTIfStmt* ASTIfStmt;
	class ASTElseStmt* ASTElseStmt;
	class ASTForStmt* ASTForStmt;
	class ASTWhileStmt* ASTWhileStmt;
	class ASTGotoStmt* ASTGotoStmt;
	class ASTForExp* ASTForExp;
	class ASTCodeBlockNode* ASTCodeBlockNode;
	class ASTDeclStmt* ASTDeclStmt;
	class ASTDeclParams* ASTDeclParams;
	class ASTDeclBlockNode* ASTDeclBlockNode;

#line 112 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
