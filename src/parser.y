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

%union {int num; char* id; char* str; char* size; char* index}    /*YACC definitions*/
%start declblock
// %start for_exp
// %start code_statement
/* %token quotes */
%token IF
%token ELSE
%token GOTO
%token FOR
%token WHILELOOP
%token PRINT
%token PRINTLN
%token READVAR
%token EXIT_COMMAND
%token CODE_BLOCK
%token DECL_BLOCK
%token DATATYPE
%token EQUATE
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token MODULO
%token RGTSHFT
%token LFTSHFT
%token LT
%token GT
%token LE
%token GE
%token EQL
%token NTEQL
%token AND
%token OR
%left EQL NTEQL
%left AND OR
%left LT GT LE GE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%token <index> ARRAY_INDEX 
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
decl_params				: identifiers										{;}
						| decl_params ',' decl_params						{;}
						;
code_statement			: EXIT_COMMAND ';'									{exit(EXIT_SUCCESS);}
						| assignment ';'									{;}
						| code_statement assignment ';'						{;}
						| PRINT print_statement ';'							{;}
						| PRINTLN print_statement ';'						{printf("\n");}
						| READVAR identifiers ';'							{printf("reading the identifier\n");}//{scan_var($2);}
						| if_statement else_statement						{;}
						| if_statement										{;}
						| for_statement										{printf("entered for loop\n");}
						| while_statement									{;}
						| goto_statement									{;}
						| IDENTIFIER ':'									{;}
						| code_statement PRINT print_statement ';'			{;}
						| code_statement PRINTLN print_statement ';'		{printf("\n");}
						| code_statement READVAR IDENTIFIER ';'				{printf("reading the identifier\n");}//{scan_var($3);}
						| code_statement EXIT_COMMAND ';' 					{exit(EXIT_SUCCESS);}
						| code_statement if_statement else_statement		{;}
						| code_statement if_statement						{;}
						| code_statement for_statement						{;}
						| code_statement while_statement					{;}
						| code_statement goto_statement						{;}
						| code_statement IDENTIFIER ':'						{;}
						;
print_statement			: print_statement ',' final_print_statement 		{;}
						| final_print_statement								{;}
						;
final_print_statement	: identifiers 										{;}
						| TEXT												{printf("%s",print_text($1));}
						;
if_statement			: IF exp '{' code_statement '}'						{printf("found if loop \n");}
						;
else_statement			: ELSE '{' code_statement '}'						{printf("found else loop \n");}
						| ELSE if_statement									{printf("found if-elseif statements\n");}
						;
for_statement			: FOR for_exp '{' code_statement '}'				{printf("found for loop\n"); }
						;
for_exp					: IDENTIFIER EQUATE NUMBER ',' NUMBER									
						| IDENTIFIER EQUATE NUMBER ',' NUMBER ',' NUMBER
						;
while_statement			: WHILELOOP exp '{' code_statement '}'				{printf("found while loop");}
						;
assignment				: identifiers EQUATE exp								//{updateSymbolVal($1,$3);}
						;
exp						: term												//{$$ = $1;}
						| exp binop exp										//{$$ = $1 + $3;}
						// | exp MINUS exp
						// | exp MULTIPLY exp
						| '(' exp ')' 										//{$$ = $1 - $3;}
						;
term 					: NUMBER											{$$=$1;}
						| identifiers										{;}
						;
variable				: variable ',' variable								{;}
						| identifiers										{;}
						;
identifiers				: IDENTIFIER										{printf("identifier is :: %s\n",$1);}//$$ = symbolVal($1);}	
						| IDENTIFIER ARRAY_SIZE								{printf("array :: %s with size :: %s found\n",$1,$2);}
						| IDENTIFIER ARRAY_INDEX							{;}
						;
arithop					: PLUS												{printf("found +\n");}
						| MINUS												{printf("found -\n");}
						| MULTIPLY											{printf("found *\n");}
						| DIVIDE											{printf("found /\n");}
						| MODULO											{printf("found %\n");}
						| RGTSHFT											{printf("found >>\n");}
						| LFTSHFT											{printf("found <<\n");}
						;
relop					: LT												{printf("found <\n");}
						| GT												{printf("found >\n");}
						| LE												{printf("found <=\n");}
						| GE												{printf("found >=\n");}
						;
eqop					: EQL												{printf("found ==\n");}
						| NTEQL												{printf("found !=\n");}
						;
condop					: AND												{printf("found &&\n");}
						| OR												{printf("found ||\n");}
						;
binop					: arithop
						| relop
						| eqop
						| condop
						;
goto_statement			: GOTO IDENTIFIER IF exp ';'							{printf("found goto statement with if condition\n");}
						| GOTO IDENTIFIER ';'								{printf("found goto statement\n");}
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

