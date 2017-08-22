%{
#include "y.tab.h"
%}
%%
"print"			{return print;}
"println"		{return println;}
"read"			{return readvar;}
"declblock"		{return decl_block;}
"codeblock"		{return code_block;}
"exit"			{return exit_command;}
\".*\"			{yylval.str = yytext; printf("text is %s\n",yytext); return text;}
[a-zA-Z]		{yylval.id = yytext[0]; return identifier;}
[0-9]+			{yylval.num = atoi(yytext); return number;}
[ \t\n]			;
[-+=;{}]			{return yytext[0];}
.			{ECHO; yyerror("unexpected character");}

%%
int yywrap (void) {return 1;}
