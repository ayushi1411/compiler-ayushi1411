%{
#include "y.tab.h"
%}
%%
"if"			{return IF;}
"else"			{return ELSE;}
"for"           {return FOR;}
"print"			{return PRINT;}
"println"		{return PRINTLN;}
"read"			{return READVAR;}
"declblock"		{return DECL_BLOCK;}
"codeblock"		{return CODE_BLOCK;}
"exit"			{return EXIT_COMMAND;}
\".*\"			{yylval.str = yytext; printf("text is %s\n",yytext); return TEXT;}
[a-zA-Z]		{yylval.id = yytext[0]; return IDENTIFIER;}
[0-9]+			{yylval.num = atoi(yytext); return NUMBER;}
[ \t\n]			;
[-+=;{}]		{return yytext[0];}
.			    {ECHO; yyerror("unexpected character");}

%%
int yywrap (void) {return 1;}
