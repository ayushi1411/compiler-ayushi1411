#include "ASTDefinitions.h"

class Interpreter : public Visitor 
{

public :
    map<pair<string,int>,int > symbol_table;

public:
    void visit (class ASTNode* );
    void visit (class ASTDeclBlockNode* );
    void visit (class ASTParamsDeclStmt* );
    void visit (class ASTMultiDeclStmt* ) ;
    void visit (class ASTDeclStmt* );
    void visit (class ASTDeclParams*);
    void visit (class ASTDeclMultiParams*);
    void visit (class ASTDeclIdParams*);
    void visit (class ASTCodeBlockNode*);
    void visit (class ASTCodeStmt*);
    void visit (class ASTCodePrint*);
    void visit (class ASTPrintStmt*);
    void visit(class ASTFinalPrintStmt*);
    void visit(class ASTMultiPrintStmt*);
    void visit(class ASTFinPrintStmt*);
    void visit(class ASTFinalPrintStmtId*);
    void visit(class ASTFinalPrintStmtText*);
    void visit(class ASTIdNode*);
    void visit(class ASTMultiCodePrint*);
    void visit(class ASTCodeAssignment*);
    void visit(class ASTAssignment*);
    void visit(class ASTMultiCodeAssignment*);
    int evaluateExp(class ASTExp*);
    bool checkIdExist(string id);
};

void Interpreter::visit(ASTNode* astNode)
{
    cout<<"Root node visited"<<endl;
    ASTDeclBlockNode* astDeclBlockNode = dynamic_cast<ASTDeclBlockNode*>(astNode);
    astDeclBlockNode->accept(this); 
}

void Interpreter::visit(ASTDeclBlockNode* astDeclBlockNode)
{
    // class ASTParamsDeclStmt* astParamDeclStmt = dynamic_cast<ASTParamsDeclStmt*> (astDeclBlockNode->decl_stmt);
    // if (astParamDeclStmt!=NULL)
    //     cout<<"not null "<<endl; 
    // class ASTMultiDeclStmt* astMultiDeclStmt = dynamic_cast<ASTMultiDeclStmt*> (astDeclBlockNode->decl_stmt);
    // if (astMultiDeclStmt!=NULL)
    // cout<<"atl eat this not null"<<endl;
    astDeclBlockNode->decl_stmt->accept(this);
    astDeclBlockNode->code_block->accept(this);
};

void Interpreter::visit(ASTCodeBlockNode* astCodeBlockNode)
{
    cout<<"entered code block "<<endl;
    astCodeBlockNode->code_stmt->accept(this);
    return;
}

void Interpreter::visit(ASTCodeStmt* astCodeStmt)
{
    cout<<"executing code statement"<<endl;
    if(astCodeStmt->CodePrint!=NULL)
        astCodeStmt->CodePrint->accept(this);
    if(astCodeStmt->MultiCodePrint!=NULL)
        astCodeStmt->MultiCodePrint->accept(this);
    if(astCodeStmt->CodeAssignment!=NULL)
        astCodeStmt->CodeAssignment->accept(this);
    if(astCodeStmt->MultiCodeAssignment!=NULL)
        astCodeStmt->MultiCodeAssignment->accept(this);
    return;
}

void Interpreter::visit(ASTCodeAssignment* astCodeAssignment)
{
    cout<<"code assignment"<<endl;
    astCodeAssignment->assign->accept(this);
}
void Interpreter::visit(ASTMultiCodeAssignment* astMultiCodeAssignment)
{
    cout<<"multi code assignment"<<endl;
    astMultiCodeAssignment->assign->accept(this);
}
void Interpreter::visit(ASTAssignment* astAssignment)
{
    string id = astAssignment->id->id;
    int index;
    if(symbol_table.find(make_pair(id,-1)) == symbol_table.end() && symbol_table.find(make_pair(id,0)) == symbol_table.end())
    {
        cout<<"variable not declared"<<endl;
        exit(0);
    }
    if(astAssignment->id->num_index!=-1)
    {
        if(symbol_table.find(make_pair(id, astAssignment->id->num_index))!=symbol_table.end())
        {
        }
        else
        {
            cout<<"array index out of bounds"<<endl;
            exit(0);
        }
    }
    if(astAssignment->id->id_index!="\0")
    {
        if(symbol_table.find(make_pair(astAssignment->id->id_index,-1))!=symbol_table.end() && symbol_table.find(make_pair(astAssignment->id->id_index,0))==symbol_table.end() )
        {
            index = symbol_table[make_pair(astAssignment->id->id_index,-1)];
            if(symbol_table.find(make_pair(id,index))==symbol_table.end())
            {
                cout<<"array index out of bounds"<<endl;
                exit(0);
            }
        }
        else{
            cout<<"array index not declared or array index is an array variable"<<endl;
        }
    }
    // astAssignemt->exp->accept(this);
    int result = evaluateExp(astAssignment->exp);
    if(astAssignment->id->num_index==-1 && astAssignment->id->id_index=="\0")
    {
        symbol_table[make_pair(id, -1)]=result;
    }
    else if(astAssignment->id->num_index!=-1)
    {
        symbol_table[make_pair(id,astAssignment->id->num_index)]=result;
    }
    else{
        symbol_table[make_pair(id, index)]=result;
    }
    cout<<id<<" assigned value "<<result<<endl;
}

int Interpreter::evaluateExp(ASTExp* exp)
{
    return 10;
}

void Interpreter::visit(ASTCodePrint* astCodePrint)
{
    // astCodePrint->stmt->accept(this);
    cout<<"print code"<<endl;
    astCodePrint->stmt->accept(this);
    if(astCodePrint->newline==true)
        cout<<"\n";
}

void Interpreter::visit(ASTMultiCodePrint* astMultiCodePrint)
{
    cout<<"print multi code"<<endl;
    astMultiCodePrint->stmt1->accept(this);
    astMultiCodePrint->stmt2->accept(this);
    if(astMultiCodePrint->newline==true)
        cout<<"\n";
}

void Interpreter::visit(ASTPrintStmt* astPrintStmt)
{
    cout<<"print statement"<<endl;
    if(astPrintStmt->MulPrintStmt!=NULL)
    {
        astPrintStmt->MulPrintStmt->accept(this);
    }
    if(astPrintStmt->FinPrintStmt!=NULL)
    {
        astPrintStmt->FinPrintStmt->accept(this);
    }
}

void Interpreter::visit(ASTMultiPrintStmt* astMultiPrintStmt)
{
    astMultiPrintStmt->stmt1->accept(this);
    astMultiPrintStmt->stmt2->accept(this);
}

void Interpreter::visit(ASTFinPrintStmt* astFinPrintStmt)
{
    astFinPrintStmt->stmt->accept(this);
}

void Interpreter::visit(ASTFinalPrintStmt* astFinalPrintStmt)
{
    if(astFinalPrintStmt->FinalPrintStmtId!=NULL)
        astFinalPrintStmt->FinalPrintStmtId->accept(this);
    if(astFinalPrintStmt->FinalPrintStmtText!=NULL)
        astFinalPrintStmt->FinalPrintStmtText->accept(this);
}

void Interpreter::visit(ASTFinalPrintStmtId* astFinalPrintStmtId)
{
    cout<<"printing id "<<endl;
    astFinalPrintStmtId->id->accept(this);
    return;
}

bool Interpreter::checkIdExist(string id)
{
    if (symbol_table.find(make_pair(id,-1))!=symbol_table.end() && symbol_table.find(make_pair(id,0))!=symbol_table.end())
    {
        return false;
    }
    return true;
        
}
void Interpreter::visit(ASTIdNode* astIdNode)
{
    cout<<"decoding the identifier"<<endl;
    bool existId = this->checkIdExist(astIdNode->id);
    if(existId==false)
    {
        cout<<"Identifier not declared"<<endl;
        exit(0);
    }
    if (astIdNode->num_index==-1 && astIdNode->id_index=="\0") // not an array 
    {
        cout<<symbol_table[make_pair(astIdNode->id, -1)];
        return;
    }
    if(astIdNode->num_index!=-1)
    {
        if(symbol_table.find(make_pair(astIdNode->id,astIdNode->num_index))!=symbol_table.end())
        {
            cout<<symbol_table[make_pair(astIdNode->id, astIdNode->num_index)];
        }
        else
        {
            cout<<"array limit out of bounds "<<endl;
            exit(0);
        }
    }
    if(astIdNode->id_index!="\0")
    {
        if(symbol_table.find(make_pair(astIdNode->id_index,-1))!=symbol_table.end() && symbol_table.find(make_pair(astIdNode->id_index,0))==symbol_table.end() )
        {
            int index = symbol_table[make_pair(astIdNode->id_index,-1)];
            if(symbol_table.find(make_pair(astIdNode->id, index))!=symbol_table.end())
            {
                cout<<symbol_table[make_pair(astIdNode->id, index)];
            }
            else
            {
                cout<<"array limit out of bounds"<<endl;
            }

        }
        else{
            cout<<"array index not declared or array index is an array variable"<<endl;
            exit(0);
        }
    }


}

void Interpreter::visit(ASTFinalPrintStmtText* astFinalPrintStmtText)
{
    string text = astFinalPrintStmtText->text.substr(1,astFinalPrintStmtText->text.length()-2);
    cout<<text;
    return;
}

void Interpreter::visit(ASTDeclStmt* astDeclStmt)
{
    if (astDeclStmt->ParamsDeclStmt!=NULL)
        astDeclStmt->ParamsDeclStmt->accept(this);
    if (astDeclStmt->MultiDeclStmt!=NULL)
        astDeclStmt->MultiDeclStmt->accept(this);
    return ;
}


void Interpreter::visit(ASTParamsDeclStmt* astParamsDeclStmt)
{
    cout<<"visiting here"<<endl;
    astParamsDeclStmt->params->accept(this);
    return ;
}

void Interpreter::visit(ASTMultiDeclStmt* astMultiDeclStmt)
{
    cout<<"visiting herer"<<endl;
    astMultiDeclStmt->stmt1->accept(this);
    astMultiDeclStmt->stmt2->accept(this);
    return;
}


void Interpreter::visit(ASTDeclParams* astDeclParams)
{
    if (astDeclParams->DeclMultiParams!=NULL)
        astDeclParams->DeclMultiParams->accept(this);
    if (astDeclParams->DeclIdParams!=NULL)
        astDeclParams->DeclIdParams->accept(this);
}

void Interpreter::visit(ASTDeclMultiParams* astDeclMultiParams)
{
    cout<<"visiting astdeclmultiparams"<<endl;
    astDeclMultiParams->param1->accept(this);
    astDeclMultiParams->param2->accept(this);
    return ;   
}

void Interpreter::visit(ASTDeclIdParams* astDeclIdparams)
{
    cout<<"visiring Declidparams"<<endl;
    ASTIdNode* id = astDeclIdparams->id;
    cout<<id->id<<' '<<id->num_index<<' '<<id->id_index<<endl;;
    
    if (id->num_index==-1 && id->id_index=="\0") // not an array 
    {
        if (symbol_table.find(make_pair(id->id,-1))==symbol_table.end() && symbol_table.find(make_pair(id->id,0))==symbol_table.end()     )
        {
            symbol_table[make_pair(id->id,-1)] = 0;
            cout<<"created variable :: "<<id->id<<endl;
        }
        else 
        {
            cout<<id->id<<" variable already declared"<<endl;
            exit(0);
        }
    }

    else if (id->num_index==-1 && id->id_index!="\0")
    {
        cout<<id->id<<" cannot declare an array with an identifier index "<<endl;
        exit(0);
    }

    else if (id->num_index!=-1 && id->id_index=="\0")
    {
        if (symbol_table.find(make_pair(id->id,-1))==symbol_table.end() && symbol_table.find(make_pair(id->id,0))==symbol_table.end() )
        {
            for (int i=0;i<id->num_index;i++)
            {
                symbol_table[make_pair(id->id,i)] = 0;
                cout<<"created variable :: "<<id->id<<endl;
            
            }
        }
        else 
        {
            cout<<id->id<<" variable already declared"<<endl;
            exit(0);
        }
    }

    map<pair<string,int>,int>::iterator it;
    for (it=symbol_table.begin();it!=symbol_table.end();it++)
    {
        pair<string,int> s = it->first;
        cout<<s.first<<' '<<s.second<<endl;
        cout<<it->second<<endl;
    }

    return ;
}

