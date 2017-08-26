%{
void yyerror(char *s);  //C declarations used in actions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
char* print_text(char* str);
%}

%union {int num; char id; char* str; char* size}    /*YACC definitions*/
%start declblock
// %start code_statement
/* %token quotes */
%token IF
%token ELSE
%token FOR
%token WHILELOOP
%token PRINT
%token PRINTLN
%token READVAR
%token EXIT_COMMAND
%token CODE_BLOCK
%token DECL_BLOCK
%token DATATYPE
%token <num> NUMBER 
%token <size> ARRAY_SIZE
%token <id> IDENTIFIER
%token <str> TEXT
%type <num> codeblock exp term variable identifiers
%type <id> assignment
// %type <str> final_print_statement

%%

/* descriptions of expected inputs 			corresponding actions(in C) */
codeblock 				: CODE_BLOCK '{' code_statement '}'					{;}
						;
declblock 				: DECL_BLOCK '{' decl_statement '}'	codeblock		{;}
						;
decl_statement 			: DATATYPE decl_params ';'							{;}
						| decl_statement decl_statement						{;}
						| ';'												{;}
						;
decl_params				: assignment										{;}
						| identifiers										{;}
						| decl_params ',' decl_params						{;}
						;
code_statement			: EXIT_COMMAND ';'									{exit(EXIT_SUCCESS);}
						| assignment ';'									{;}
						| code_statement assignment ';'						{;}
						| PRINT print_statement ';'							{;}
						| PRINTLN print_statement ';'						{printf("\n");}
						| READVAR IDENTIFIER ';'							{scan_var($2);}
						| if_statement else_statement						{;}
						| for_statement										{printf("entered for loop\n");}
						| while_statement									{;}
						| code_statement PRINT print_statement ';'			{;}
						| code_statement PRINTLN print_statement ';'		{printf("\n");}
						| code_statement READVAR IDENTIFIER ';'				{scan_var($3);}
						| code_statement EXIT_COMMAND ';' 					{exit(EXIT_SUCCESS);}
						| code_statement if_statement else_statement		{;}
						| code_statement for_statement						{;}
						| code_statement while_statement					{;}
						;
print_statement			: print_statement ',' final_print_statement 		{;}
						| final_print_statement								{;}
						;
final_print_statement	: exp 												{printf("%d",$1);}
						| TEXT												{printf("%s",print_text($1));}
						;
if_statement			: IF '{' code_statement '}'							{printf("found if loop \n");}
						;
else_statement			: ELSE '{' code_statement '}'						{printf("found else loop \n");}
						;
for_statement			: FOR '{' code_statement '}'						{printf("found for loop\n"); }
						;
while_statement			: WHILELOOP '{' code_statement '}'					{printf("found while loop");}
						;
assignment				: IDENTIFIER '=' exp								{updateSymbolVal($1,$3);}
						;
exp						: term												{$$ = $1;}
						| exp '+' term										{$$ = $1 + $3;}
						| exp '-' term										{$$ = $1 - $3;}
						;
term 					: NUMBER											{$$=$1;}
						| identifiers										{;}
						;
variable				: variable ',' variable								{;}
						| identifiers										{;}
						;
identifiers				: IDENTIFIER										{printf("%c",$1);$$ = symbolVal($1);}	
						| IDENTIFIER ARRAY_SIZE								{printf("array :: %c with size :: %s found\n",$1,$2);}

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
char* print_text(char* str)
{
	// char tempstr;
	int i;
	int size = strlen(str);
	char* tempstr = (char*)malloc(sizeof(char)*(size-1));
	// printf("size:: %d",strlen(str));
	for(i=1;i<strlen(str)-1;i++)
	{
		tempstr[i-1]=str[i];
	}
	tempstr[i]='\0';
	return tempstr;
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

