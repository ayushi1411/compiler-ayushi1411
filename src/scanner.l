%{
#include "y.tab.h"
%}
%%
"int"           {return DATATYPE;}
"goto"          {return GOTO;}
"if"			{return IF;}
"else"			{return ELSE;}
"for"           {return FOR;}
"while"         {return WHILELOOP;}
"print"			{return PRINT;}
"println"		{return PRINTLN;}
"read"			{return READVAR;}
"declblock"		{return DECL_BLOCK;}
"codeblock"		{return CODE_BLOCK;}
"exit"			{return EXIT_COMMAND;}
\"[^\"]*\"      {yylval.str = yytext; return TEXT;}
[a-zA-Z]*		{yylval.id = yytext; return IDENTIFIER;}
\[[1-9][0-9]*\] {yylval.size = yytext; return ARRAY_SIZE;}
[0-9]+			{yylval.num = atoi(yytext); return NUMBER;}
[ \t\n]			;
=               {return EQUATE;}
\+               {return PLUS;}
-               {return MINUS;}
\*               {return MULTIPLY;}
\/               {return DIVIDE;}
%               {return MODULO;}
"<<"              {return RGTSHFT;}
">>"              {return LFTSHFT;}
"<"               {return LT;}
">"               {return GT;}
"<="              {return LE;}
">="              {return GE;}
"=="              {return EQL;}
"!="              {return NTEQL;}
"&&"              {return AND;}
"||"              {return OR;}
[;{},()]		{return yytext[0];}
.			    {printf("the char is %c",yytext[0]);ECHO;  yyerror("unexpected character");}

%%
int yywrap (void) {return 1;}
