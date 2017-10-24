%{
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include<bits/stdc++.h>
#include "ASTDefinitions.h"
using namespace std;
void yyerror(char *s);  //C declarations used in actions
int yylex(void);
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
char* print_text(char* str);
%}

%union 
{
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
}    /*YACC definitions*/
%start declblock
// %start for_exp
// %start code_statement
/* %token quotes */

%type <ASTIdNode> identifiers
%type <ASTVariable> variable 
%type <ASTTerm> term
%type <ASTExp> exp
%type <ASTAssignment> assignment
%type <ASTPrintStmt> print_statement
%type <ASTFinalPrintStmt> final_print_statement
%type <ASTCodeStmt> code_statement
%type <ASTIfStmt> if_statement
%type <ASTElseStmt> else_statement
%type <ASTForStmt> for_statement
%type <ASTWhileStmt> while_statement
%type <ASTGotoStmt> goto_statement
%type<ASTForExp> for_exp
%type <ASTCodeBlockNode> codeblock
%type <ASTDeclStmt> decl_statement
%type <ASTDeclParams> decl_params
%type <ASTDeclBlockNode> declblock
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
%token IF
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
%type <id> binop arithop condop relop eqop

%%

/* descriptions of expected inputs 			corresponding actions(in C) */
declblock 				: DECL_BLOCK '{' decl_statement '}'	codeblock		{$$ = new ASTDeclBlockNode($3, $5);}
						;
codeblock 				: CODE_BLOCK '{' code_statement '}'					{$$ = new ASTCodeBlockNode($3);}
						;
decl_statement 			: DATATYPE decl_params ';'							{ASTParamsDeclStmt* declstmt = new ASTParamsDeclStmt($2); $$ = new ASTDeclStmt(); $$->ParamsDeclStmt = declstmt;}
						| decl_statement decl_statement						{ASTMultiDeclStmt* declstmt = new ASTMultiDeclStmt($1, $2); $$ = new ASTDeclStmt(); $$->MultiDeclStmt = declstmt;}
						| ';'												{;}
						;
decl_params				: identifiers										{ASTDeclIdParams* declparam = new ASTDeclIdParams($1); $$ = new ASTDeclParams(); $$->DeclIdParams = declparam;}
						| decl_params ',' decl_params						{ASTDeclMultiParams* declparam = new ASTDeclMultiParams($1, $3); $$ = new ASTDeclParams(); $$->DeclMultiParams = declparam;}
						;
code_statement			: EXIT_COMMAND ';'									{exit(EXIT_SUCCESS);}
						| assignment ';'									{ASTCodeAssignment* codeassign = new ASTCodeAssignment($1); $$ = new ASTCodeStmt(); $$->CodeAssignment = codeassign; }
						| code_statement assignment ';'						{ASTMultiCodeAssignment* codeassign = new ASTMultiCodeAssignment($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeAssignment = codeassign;}
						| PRINT print_statement ';'							{ASTCodePrint* codeprint = new ASTCodePrint($2, false); $$ = new ASTCodeStmt(); $$->CodePrint = codeprint;}
						| PRINTLN print_statement ';'						{ASTCodePrint* codeprint = new ASTCodePrint($2, true); $$ = new ASTCodeStmt(); $$->CodePrint = codeprint;}
						| READVAR identifiers ';'							{ASTCodeRead* coderead = new ASTCodeRead($2); $$ = new ASTCodeStmt(); $$->CodeRead = coderead;}
						| if_statement else_statement						{ASTCodeIfElse* codeifelse = new ASTCodeIfElse($1, $2); $$ = new ASTCodeStmt(); $$->CodeIfElse = codeifelse;}
						| if_statement										{ASTCodeIfStmt* codeif = new ASTCodeIfStmt($1); $$ = new ASTCodeStmt(); $$->CodeIfStmt = codeif;}
						| for_statement										{ASTCodeFor* codefor = new ASTCodeFor($1); $$ = new ASTCodeStmt(); $$->CodeFor = codefor;}
						| while_statement									{ASTCodeWhile* codewhile = new ASTCodeWhile($1); $$ = new ASTCodeStmt(); $$->CodeWhile = codewhile;}
						| goto_statement									{ASTCodeGoto* codegoto = new ASTCodeGoto($1); $$ = new ASTCodeStmt(); $$->CodeGoto = codegoto;}
						| IDENTIFIER ':'									{ASTCodeLabel* codelabel = new ASTCodeLabel($1); $$ = new ASTCodeStmt(); $$->CodeLabel = codelabel;}
						| code_statement PRINT print_statement ';'			{ASTMultiCodePrint* codeprint = new ASTMultiCodePrint($1, $3, false); $$ = new ASTCodeStmt(); $$->MultiCodePrint = codeprint;}
						| code_statement PRINTLN print_statement ';'		{ASTMultiCodePrint* codeprint = new ASTMultiCodePrint($1, $3, true); $$ = new ASTCodeStmt(); $$->MultiCodePrint = codeprint;}
						| code_statement READVAR identifiers ';'			{ASTMultiCodeRead* coderead = new ASTMultiCodeRead($1, $3); $$ = new ASTCodeStmt(); $$->MultiCodeRead = coderead;}
						| code_statement EXIT_COMMAND ';' 					{exit(EXIT_SUCCESS);}
						| code_statement if_statement else_statement		{ASTMultiCodeIfElse* codeifelse = new ASTMultiCodeIfElse($1, $2, $3); $$ = new ASTCodeStmt(); $$->MultiCodeIfElse = codeifelse;}
						| code_statement if_statement						{ASTMultiCodeIfStmt* codeif = new ASTMultiCodeIfStmt($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeIfStmt = codeif;}
						| code_statement for_statement						{ASTMultiCodeFor* codefor = new ASTMultiCodeFor($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeFor = codefor;}
						| code_statement while_statement					{ASTMultiCodeWhile* codewhile = new ASTMultiCodeWhile($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeWhile = codewhile;}
						| code_statement goto_statement						{ASTMultiCodeGoto* codegoto = new ASTMultiCodeGoto($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeGoto = codegoto;}
						| code_statement IDENTIFIER ':'						{ASTMultiCodeLabel* codelabel = new ASTMultiCodeLabel($1, $2); $$ = new ASTCodeStmt(); $$->MultiCodeLabel = codelabel;}
						;
print_statement			: print_statement ',' final_print_statement 		{ASTMultiPrintStmt* mulprint = new ASTMultiPrintStmt($1, $3); $$ = new ASTPrintStmt(); $$->MulPrintStmt = mulprint;}
						| final_print_statement								{ASTFinPrintStmt* finprint = new ASTFinPrintStmt($1); $$ = new ASTPrintStmt(); $$->FinPrintStmt = finprint; }
						;
final_print_statement	: identifiers 										{ASTFinalPrintStmtId* finalidprint = new ASTFinalPrintStmtId($1); $$ = new ASTFinalPrintStmt(); $$->FinalPrintStmtId = finalidprint;}
						| TEXT												{ASTFinalPrintStmtText* textprint = new ASTFinalPrintStmtText($1); $$  = new ASTFinalPrintStmt(); $$->FinalPrintStmtText = textprint;}
						;
if_statement			: IF exp '{' code_statement '}'						{$$ = new ASTIfStmt($2, $4);}
						;
else_statement			: ELSE '{' code_statement '}'						{ASTElse* elsestmt = new ASTElse($3); $$ = new ASTElseStmt(); $$-> ElseStmt = elsestmt;}
						| ELSE if_statement									{ASTElseIf* elseif = new ASTElseIf($2); $$ = new ASTElseStmt(); $$->ElseIf = elseif;}
						;
for_statement			: FOR for_exp '{' code_statement '}'				{$$ = new ASTForStmt($2,$4);}
						;
for_exp					: IDENTIFIER EQUATE NUMBER ',' NUMBER				{$$ = new ASTForExp($1, $3, $5);}					
						| IDENTIFIER EQUATE NUMBER ',' NUMBER ',' NUMBER	{$$ = new ASTForExp($1, $3, $5, $7);}
						;
while_statement			: WHILELOOP exp '{' code_statement '}'				{$$ = new ASTWhileStmt($2,$4);}
						;
assignment				: identifiers EQUATE exp							{$$ = new ASTAssignment($1, $3); }
						;
exp						: term												{ASTExpTerm* expterm = new ASTExpTerm($1); $$ = new ASTExp(); $$->ExpTerm = expterm;}
						| exp binop exp										{ASTExpOps* expops = new ASTExpOps($1, $2, $3); $$ = new ASTExp(); $$->ExpOps = expops;}
						| '(' exp ')' 										{ASTExpParan* expparan = new ASTExpParan($2); $$  = new ASTExp(); $$->ExpParan = expparan; }
						;
term 					: NUMBER											{ASTTermNum* numterm = new ASTTermNum($1); $$=new ASTTerm(); $$->NumTerm = numterm; cout<<"term created"<<$$->NumTerm->num<<endl;}
						| identifiers										{ASTTermId* idterm = new ASTTermId($1); $$=new ASTTerm(); $$->IdTerm = idterm; cout<<"term id created"<<$$->IdTerm->id<<" "<<idterm->id<<endl;}
						;
variable				: variable ',' variable								{ ASTMultiVariable *mulvar = new ASTMultiVariable($1,$3); $$=new ASTVariable() ; $$->MulVar=mulvar; cout<<$$<<endl;}
						| identifiers										{ ASTIdVariable *idvar = new ASTIdVariable($1);$$=new ASTVariable() ; $$->IdVar=idvar; cout<<$$<<endl;}
						;
						
identifiers				: IDENTIFIER										{$$=new ASTIdNode($1); cout<<$$->id<<"instace created"<<endl; }	
						| IDENTIFIER ARRAY_SIZE								{$$=new ASTIdNode($1,$2, "NULL");cout<<$$->id_index<<"array num accessed"<<endl;}
						| IDENTIFIER ARRAY_INDEX							{$$=new ASTIdNode($1,"-1",$2);cout<<$$->id_index<<"array accessed"<<endl;}
						;
arithop					: PLUS												{$$="+";}
						| MINUS												{$$="-";}
						| MULTIPLY											{$$="*";}
						| DIVIDE											{$$="/";}
						| MODULO											{$$="%";}
						| RGTSHFT											{$$=">>";}
						| LFTSHFT											{$$="<<";}
						;


relop					: LT												{$$="<";}
						| GT												{$$=">";}
						| LE												{$$="<=";}
						| GE												{$$=">=";}
						;
eqop					: EQL												{$$="==";}
						| NTEQL												{$$="!=";}
						;
condop					: AND												{$$="&&";}
						| OR												{$$="||";}
						;
binop					: arithop											{$$=$1;}
						| relop												{$$=$1;}
						| eqop												{$$=$1;}
						| condop											{$$=$1;}
						;
goto_statement			: GOTO IDENTIFIER IF exp ';'						{ASTGotoExp* gotostmt = new ASTGotoExp($2, $4); $$ = new ASTGotoStmt(); $$->GotoExp = gotostmt;}	
						| GOTO IDENTIFIER ';'								{ASTGoto* gotostmt = new ASTGoto($2); $$ = new ASTGotoStmt(); $$->Goto = gotostmt;}
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
void yyerror (char *s) { fprintf(stderr, "%s\n",s);}

int main(void){
	/* init symbol table*/
	int i;
	for(i=0;i<52;i++){
		symbols[i] = 0;
	}
	return yyparse();
}

