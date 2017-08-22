%{
void yyerror(char *s);  //C declarations used in actions
#include <stdio.h>
#include <stdlib.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

%union {int num; char id;}    /*YACC definitions*/
%start declblock
%token print
%token println
%token readvar
%token exit_command
%token code_block
%token decl_block
%token <num> number
%token <id> identifier
/* %type <num> line exp term */
%type <num> codeblock exp term
%type <id> assignment

%%

/* descriptions of expected inputs 			corresponding actions(in C) */
codeblock 	: code_block '{' code_statement '}'		{;}
declblock 	: decl_block '{' decl_statement '}'	codeblock	{;}
decl_statement 	: assignment ';'					{;}
				| decl_statement assignment ';'		{;}
				| ';'								{;}
				;
code_statement	:exit_command ';'			{exit(EXIT_SUCCESS);}
			| print exp ';'				{printf("Printing %d", $2);}
			| println exp ';'			{printf("Printing %d\n", $2);}
			| readvar identifier ';'			{scan_var($2);}
			| code_statement print exp ';'			{printf("Printing %d", $3);}
			| code_statement println exp ';'			{printf("Printing %d\n", $3);}
			| code_statement exit_command ';' 		{exit(EXIT_SUCCESS);}
			;

assignment	: identifier '=' exp			{updateSymbolVal($1,$3);}
		;
exp		: term					{$$ = $1;}
		| exp '+' term				{$$ = $1 + $3;}
		| exp '-' term				{$$ = $1 - $3;}
		;
term 		: number				{$$=$1;}
		| identifier				{$$ = symbolVal($1);}
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

