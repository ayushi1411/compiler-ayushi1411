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
};

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

