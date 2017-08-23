%{
void yyerror(char *s);  //C declarations used in actions
#include <stdio.h>
#include <stdlib.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {int num; char id; char* str}    /*YACC definitions*/
%start declblock
/* %token quotes */
%token IF
%token ELSE
%token PRINT
%token PRINTLN
%token READVAR
%token EXIT_COMMAND
%token CODE_BLOCK
%token DECL_BLOCK
%token <num> NUMBER
%token <id> IDENTIFIER
%token <str> TEXT
/* %type <num> line exp term */
%type <num> codeblock exp term
%type <id> assignment

%%

/* descriptions of expected inputs 			corresponding actions(in C) */
codeblock 				: CODE_BLOCK '{' code_statement '}'					{;}
//declblock 			: TEXT 												{printf("hel %s\n",$1);}
declblock 				: DECL_BLOCK '{' decl_statement '}'	codeblock		{;}
decl_statement 			: assignment ';'									{;}
						| decl_statement assignment ';'						{;}
						| ';'												{;}
						;
code_statement			: EXIT_COMMAND ';'									{exit(EXIT_SUCCESS);}
						| PRINT exp ';'										{printf("Printing %d", $2);}
						| PRINTLN exp ';'									{printf("Printing %d\n", $2);}
						| PRINT TEXT ';'									{printf("Printing %s", $2);}
						| PRINTLN TEXT ';'									{printf("Printing %s\n", $2);}
						| READVAR IDENTIFIER ';'							{scan_var($2);}
						| if_statement else_statement						{;}
						| code_statement PRINT exp ';'						{printf("Printing %d", $3);}
						| code_statement PRINTLN exp ';'					{printf("Printing %d\n", $3);}
						| code_statement PRINT TEXT ';'						{printf("Printing %s", $3);}
						| code_statement PRINTLN TEXT ';'					{printf("Printing %s\n", $3);}
						| code_statement READVAR IDENTIFIER ';'				{scan_var($3);}
						| code_statement EXIT_COMMAND ';' 					{exit(EXIT_SUCCESS);}
						| code_statement if_statement else_statement		{;}
						;
if_statement			: IF '{' code_statement '}'							{printf("found if loop \n");}
						;
else_statement			: ELSE '{' code_statement '}'						{printf("found else loop \n");}
						;
assignment				: IDENTIFIER '=' exp								{updateSymbolVal($1,$3);}
						;
exp						: term												{$$ = $1;}
						| exp '+' term										{$$ = $1 + $3;}
						| exp '-' term										{$$ = $1 - $3;}
						;
term 					: NUMBER											{$$=$1;}
						| IDENTIFIER										{$$ = symbolVal($1);}
						;

%% /* C code */
int computeSymbolIndex(char token)
{
	int idx  = -1;
	if(islower(token)){
		idx = token - 'a' + 26;
	} else if(isupper(token)){
		idx = token - 'A';
	}
	return idx;
}
/* returns the value of the given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}
void scan_var(char var)
{
	int val;
	scanf("%d",&val);
	updateSymbolVal(var,val);

}
/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket  = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main(void){
	/* init symbol table*/
	int i;
	for(i=0;i<52;i++){
		symbols[i] = 0;
	}
	return yyparse();
}
void yyerror (char *s) { fprintf(stderr, "%s\n",s);}

