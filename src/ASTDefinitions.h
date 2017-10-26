#include<bits/stdc++.h>
using namespace std;
class ASTDeclBlockNode;
class ASTDeclIdParams;
class ASTAssignment;
class ASTCodeBlockNode;
class ASTCodeStmt;
class ASTPrintStmt;
class ASTFinalPrintStmt;
class ASTIfStmt;
class ASTElseStmt;
class ASTForStmt;
class ASTWhileStmt;
class ASTForExp;
class ASTVariable;
class ASTExp;
class ASTIdNode;
class ASTDeclParams;
class ASTVariable;
class ASTTerm;
class ASTGotoStmt;
class ASTDeclStmt;
class ASTTermNum;
class ASTTermId;
class ASTExpTerm;
class ASTExpParan;
class ASTExpOps;
class ASTMultiVariable;
class ASTIdVariable;
class ASTMultiPrintStmt;
class ASTFinPrintStmt;
class ASTFinalPrintStmtId;
class ASTFinalPrintStmtText;
class ASTCodeAssignment;
class ASTMultiCodeAssignment;
class ASTCodePrint;
class ASTCodeRead;
class ASTCodeIfElse;
class ASTCodeIfStmt;
class ASTCodeFor;
class ASTCodeWhile;
class ASTCodeGoto;
class ASTCodeLabel;
class ASTMultiCodePrint;
class ASTMultiCodeRead;
class ASTMultiCodeIfElse;
class ASTMultiCodeIfStmt;
class ASTMultiCodeFor;
class ASTMultiCodeWhile;
class ASTMultiCodeGoto;
class ASTMultiCodeLabel; 
class ASTElse;
class ASTElseIf;
class ASTForStmt;
class ASTCodeStmt;
class ASTParamsDeclStmt;
class ASTMultiDeclStmt;
class ASTDeclIdParams;
class ASTDeclMultiParams;
class ASTGotoExp;
class ASTGoto;
class ASTGotoStmt;

class Visitor 
{
    public:

    virtual void visit(class ASTNode* )=0;
    virtual void visit(class ASTDeclBlockNode*)=0;
    virtual void visit (class ASTParamsDeclStmt* )=0;    
    virtual void visit (class ASTMultiDeclStmt*)=0 ;
    virtual void visit (class ASTDeclStmt*)=0;
    virtual void visit (class ASTDeclParams*)=0;
    virtual void visit(class ASTDeclMultiParams*)=0;
    virtual void visit(class ASTDeclIdParams*)=0;
    virtual void visit(class ASTCodeBlockNode*)=0;
    virtual void visit(class ASTCodeStmt*)=0;
    virtual void visit(class ASTCodePrint*)=0;
    virtual void visit(class ASTPrintStmt*)=0;
    virtual void visit(class ASTFinalPrintStmt*)=0;
    virtual void visit(class ASTMultiPrintStmt*)=0;
    virtual void visit(class ASTFinPrintStmt*)=0;
    virtual void visit(class ASTFinalPrintStmtId*)=0;
    virtual void visit(class ASTFinalPrintStmtText*)=0;
    virtual void visit(class ASTIdNode*)=0;
    virtual void visit(class ASTMultiCodePrint*)=0;
    virtual void visit(class ASTCodeAssignment*)=0;
    virtual void visit(class ASTAssignment*)=0;
    virtual void visit(class ASTMultiCodeAssignment*)=0;
    virtual void visit(class ASTCodeRead*)=0;
    virtual void visit(class ASTMultiCodeRead*)=0;
    virtual void visit(class ASTIfStmt*)=0;
    virtual void visit(class ASTMultiCodeIfStmt*)=0;
    virtual void visit(class ASTCodeIfStmt*)=0;
    virtual void visit(class ASTCodeIfElse*)=0;
    virtual void visit(class ASTMultiCodeIfElse*)=0;
    virtual void visit(class ASTElseStmt*)=0;
    virtual void visit(class ASTElse*)=0;
    virtual void visit(class ASTElseIf*)=0;
    virtual void visit(class ASTCodeFor*)=0;
    virtual void visit(class ASTMultiCodeFor*)=0;
    virtual void visit(class ASTForStmt*)=0;
    virtual void visit(class ASTCodeWhile*)=0;
    virtual void visit(class ASTMultiCodeWhile*)=0;
    virtual void visit(class ASTWhileStmt*)=0;
};


class ASTNode
{
     public:
         virtual void accept(Visitor * v)=0;
};
    
//declaration block
class ASTDeclBlockNode : public ASTNode{
public:
    ASTDeclStmt * decl_stmt;
    ASTCodeBlockNode  *code_block;
    ASTDeclBlockNode(ASTDeclStmt* decl_stmt, ASTCodeBlockNode* code_block)
    {
        this->decl_stmt = decl_stmt;
        this->code_block = code_block;
    }
    void accept(Visitor* v)
    {
        cout<<"visiting accept of declblock "<<endl;  
        v->visit(this);
    }
};

//declaration statement
class ASTDeclStmt{
public:
        ASTParamsDeclStmt* ParamsDeclStmt;
        ASTMultiDeclStmt* MultiDeclStmt;
     void accept(Visitor* v)
    {
         v->visit(this);
    }
    ASTDeclStmt()
    {
        this->ParamsDeclStmt = NULL;
        this->MultiDeclStmt = NULL;
    }
};
class ASTParamsDeclStmt:public ASTDeclStmt{
public:
    ASTDeclParams *params;
    ASTParamsDeclStmt(ASTDeclParams* params)
    {
        this->params = params;
    }
     void accept(Visitor* v)
     {
         v->visit(this);
     }
};
class ASTMultiDeclStmt:public ASTDeclStmt{
public:
    ASTDeclStmt *stmt1;
    ASTDeclStmt *stmt2;
    ASTMultiDeclStmt(ASTDeclStmt* stmt1, ASTDeclStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
    }
     void accept(Visitor *v)
     {
         v->visit(this);
     }
};

//code block
class ASTCodeBlockNode{ 
    public:
        ASTCodeStmt * code_stmt;
        ASTCodeBlockNode(ASTCodeStmt* code_stmt)
        {
            this->code_stmt = code_stmt;
        }
        void accept(Visitor *v)
        {
            v->visit(this);
        }
    // public:
        // void accept(Visitor *);
};

//code statements
class ASTCodeStmt{
public:
        ASTCodeAssignment* CodeAssignment;
        ASTMultiCodeAssignment* MultiCodeAssignment;
        ASTCodePrint* CodePrint;
        ASTCodeRead* CodeRead;
        ASTCodeIfElse* CodeIfElse;
        ASTCodeIfStmt* CodeIfStmt;
        ASTCodeFor* CodeFor;
        ASTCodeWhile* CodeWhile;
        ASTCodeGoto* CodeGoto;
        ASTCodeLabel* CodeLabel;
        ASTMultiCodePrint* MultiCodePrint;
        ASTMultiCodeRead* MultiCodeRead;
        ASTMultiCodeIfElse* MultiCodeIfElse;
        ASTMultiCodeIfStmt* MultiCodeIfStmt;
        ASTMultiCodeFor* MultiCodeFor;
        ASTMultiCodeWhile* MultiCodeWhile;
        ASTMultiCodeGoto* MultiCodeGoto;
        ASTMultiCodeLabel* MultiCodeLabel; 
        ASTCodeStmt()
        {
            this->CodeAssignment=NULL;
            this->MultiCodeAssignment=NULL;
            this->CodePrint=NULL;
            this->CodeRead=NULL;
            this->CodeIfElse=NULL;
            this->CodeIfStmt=NULL;
            this->CodeFor=NULL;
            this->CodeWhile=NULL;
            this->CodeGoto=NULL;
            this->CodeLabel=NULL;
            this->MultiCodePrint=NULL;
            this->MultiCodeRead=NULL;
            this->MultiCodeIfElse=NULL;
            this->MultiCodeIfStmt=NULL;
            this->MultiCodeFor=NULL;
            this->MultiCodeWhile=NULL;
            this->MultiCodeGoto=NULL;
            this->MultiCodeLabel=NULL; 
        }
        void accept(Visitor *v)
        {
            v->visit(this);
        }
};
class ASTCodeAssignment:public ASTCodeStmt{
public:
    ASTAssignment *assign;
    ASTCodeAssignment(ASTAssignment* assign)
    {
        this->assign = assign;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeAssignment: public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    ASTAssignment *assign;
    ASTMultiCodeAssignment(ASTCodeStmt* stmt, ASTAssignment* assign)
    {
        this->stmt = stmt;
        this->assign = assign;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodePrint:public ASTCodeStmt{
public:
    ASTPrintStmt *stmt;
    bool newline;
    ASTCodePrint(ASTPrintStmt* stmt, bool newline)
    {
        this->stmt = stmt;
        this->newline = newline;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodeRead:public ASTCodeStmt{
public:
    ASTIdNode *id;
    ASTCodeRead(ASTIdNode* id)
    {
        this->id = id;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodeIfElse:public ASTCodeStmt{
public:
    ASTIfStmt *ifstmt;
    ASTElseStmt *elsestmt;
    ASTCodeIfElse(ASTIfStmt* ifstmt, ASTElseStmt* elsestmt)
    {
        this->ifstmt = ifstmt;
        this->elsestmt = elsestmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTCodeIfStmt:public ASTCodeStmt{
public:
    ASTIfStmt *ifstmt;
    ASTCodeIfStmt(ASTIfStmt* ifstmt)
    {
        this->ifstmt = ifstmt;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodeFor:public ASTCodeStmt{
public:
    ASTForStmt *stmt;
    ASTCodeFor(ASTForStmt *stmt)
    {
        this->stmt = stmt;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodeWhile:public ASTCodeStmt{
public:
    ASTWhileStmt *stmt;
    ASTCodeWhile(ASTWhileStmt *stmt)
    {
        this->stmt = stmt;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTCodeGoto:public ASTCodeStmt{
public:
    ASTGotoStmt *stmt;
    ASTCodeGoto(ASTGotoStmt* stmt)
    {
        this->stmt = stmt;
    }
};
class ASTCodeLabel:public ASTCodeStmt{
public:
    string id;
    ASTCodeLabel(string id)
    {
        this->id = id;
    }
};
class ASTMultiCodePrint:public ASTCodeStmt{
public:
    bool newline;
    ASTCodeStmt *stmt1;
    ASTPrintStmt *stmt2;
    ASTMultiCodePrint(ASTCodeStmt* stmt1, ASTPrintStmt* stmt2, bool newline)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
        this->newline = newline;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeRead:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    ASTIdNode *id;
    ASTMultiCodeRead(ASTCodeStmt* stmt, ASTIdNode* id)
    {
        this->stmt = stmt;
        this->id = id;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeIfElse:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    ASTIfStmt *ifstmt;
    ASTElseStmt *elsestmt;
    ASTMultiCodeIfElse(ASTCodeStmt* stmt, ASTIfStmt* ifstmt, ASTElseStmt* elsestmt)
    {
        this->stmt = stmt;
        this->ifstmt = ifstmt;
        this->elsestmt = elsestmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeIfStmt:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    ASTIfStmt *ifstmt;
    ASTMultiCodeIfStmt(ASTCodeStmt *stmt, ASTIfStmt *ifstmt)
    {
        this->stmt = stmt;
        this->ifstmt = ifstmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeFor:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt1;
    ASTForStmt *stmt2;
    ASTMultiCodeFor(ASTCodeStmt* stmt1, ASTForStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeWhile:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt1;
    ASTWhileStmt *stmt2;
    ASTMultiCodeWhile(ASTCodeStmt* stmt1, ASTWhileStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTMultiCodeGoto:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt1;
    ASTGotoStmt *stmt2;
    ASTMultiCodeGoto(ASTCodeStmt* stmt1, ASTGotoStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
    }
};
class ASTMultiCodeLabel:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    string id;
    ASTMultiCodeLabel(ASTCodeStmt* stmt, string id)
    {
        this->stmt = stmt;
        this->id = id;
    }
};


//print statement
class ASTPrintStmt:public ASTCodeStmt{
public:
    // bool newline;    
        ASTMultiPrintStmt* MulPrintStmt;
        ASTFinPrintStmt* FinPrintStmt;  
        ASTPrintStmt()
        {
            this->MulPrintStmt=NULL;
            this->FinPrintStmt=NULL;
        }
    void accept(Visitor* v)
    {
        v->visit(this);
    }

};
class ASTMultiPrintStmt:public ASTPrintStmt{
public:
    ASTPrintStmt *stmt1;
    ASTFinalPrintStmt *stmt2;
    ASTMultiPrintStmt(ASTPrintStmt* stmt1, ASTFinalPrintStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTFinPrintStmt: public ASTPrintStmt{
public:
    ASTFinalPrintStmt *stmt;
    ASTFinPrintStmt(ASTFinalPrintStmt* stmt)
    {
        this->stmt = stmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//final print statement
class ASTFinalPrintStmt{
public:   
    ASTFinalPrintStmtId* FinalPrintStmtId;
    ASTFinalPrintStmtText* FinalPrintStmtText;
    void accept(Visitor* v)
    {
        v->visit(this);
    }
    ASTFinalPrintStmt()
    {
        this->FinalPrintStmtId=NULL;
        this->FinalPrintStmtText=NULL;
    }

};
class ASTFinalPrintStmtId:public ASTFinalPrintStmt{
public:
    ASTIdNode *id;
    ASTFinalPrintStmtId(ASTIdNode* id)
    {
        this->id = id;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTFinalPrintStmtText:public ASTFinalPrintStmt{
public:
    string text;
    ASTFinalPrintStmtText(string text)
    {
        this->text = text;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//if statement
class ASTIfStmt:public ASTCodeStmt{
public:
    ASTExp *exp;
    ASTCodeStmt *stmt;
    ASTIfStmt(ASTExp* exp, ASTCodeStmt* stmt)
    {
        this->exp = exp;
        this->stmt = stmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//else statement
class ASTElseStmt:public ASTCodeStmt{
public:
        ASTElse* ElseStmt;
        ASTElseIf* ElseIf;
        ASTElseStmt()
        {
            this->ElseStmt=NULL;
            this->ElseIf=NULL;
        }
        void accept(Visitor* v)
        {
            v->visit(this);
        }
};
class ASTElse:public ASTElseStmt{
public:
    ASTCodeStmt *stmt;
    ASTElse(ASTCodeStmt* stmt)
    {
        this->stmt = stmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};
class ASTElseIf:public ASTElseStmt{
public:
    ASTIfStmt *if_stmt;
    ASTElseIf(ASTIfStmt* if_stmt)
    {
        this->if_stmt = if_stmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//for statement
class ASTForStmt:public ASTCodeStmt{
public:
    ASTForExp *exp;
    ASTCodeStmt *stmt;
    ASTForStmt(ASTForExp* exp, ASTCodeStmt* stmt)
    {
        this->exp = exp;
        this->stmt = stmt;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//for expression
class ASTForExp{
public:
    string id;
    int num1;
    int num2;
    int num3;
    ASTForExp(string id, int num1, int num2, int num3=1)
    {
        string newid = "";
        for(int i=0;i<id.size();i++)
        {
            if((id[i]>='a' && id[i]<='z') || (id[i]>='A' && id[i]<='Z') || (id[i]>='0' && id[i]<='9') )
            {
                newid+=id[i];
            }
            else
                break;
        }
        this->id = newid;
        this->num1 = num1;
        this->num2 = num2;
        this->num3 = num3;
    }
};

//while statement
class ASTWhileStmt:public ASTCodeStmt{
public:
    ASTExp *exp;
    ASTCodeStmt *stmt;
    ASTWhileStmt(ASTExp* exp, ASTCodeStmt* stmt)
    {
        this->exp = exp;
        this->stmt = stmt;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};

//Expression
class ASTExp:public ASTCodeStmt{
public:
        ASTExpTerm* ExpTerm;
        ASTExpParan* ExpParan;
        ASTExpOps* ExpOps;
        ASTExp()
        {
            this->ExpTerm=NULL;
            this->ExpParan=NULL;
            this->ExpOps=NULL;
        }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTExpTerm:public ASTExp{
public:
    ASTTerm *term;
    ASTExpTerm(ASTTerm *term)
    {
        this->term = term;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTExpParan:public ASTExp{
public:
    ASTExp *exp;
    ASTExpParan(ASTExp *exp)
    {
        this->exp = exp;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};
class ASTExpOps:public ASTExp{
public:
    ASTExp *left_exp;
    string op_type;
    ASTExp *right_exp;
    ASTExpOps(ASTExp *left_exp, string op_type, ASTExp *right_exp)
    {
        this->left_exp = left_exp;
        this->op_type = op_type;
        this->right_exp = right_exp;
    }
    void accept(Visitor *v)
    {
        v->visit(this);
    }
};


// Term
class ASTTerm:public ASTExp{
public:
        ASTTermNum* NumTerm;
        ASTTermId* IdTerm;
    ASTTerm()
    {
        this->NumTerm=NULL;
        this->IdTerm=NULL;
    }
};
class ASTTermNum : public ASTTerm{
public:
    int num;
    ASTTermNum(int num)
    {
        this->num = num;
    }
};
class ASTTermId : public ASTTerm{
public:
    ASTIdNode *id;
    ASTTermId(ASTIdNode* id)
    {
        this->id = id;
    }
};


//variable
class ASTVariable:public ASTTerm{
public:
    union{
        ASTMultiVariable *MulVar;
        ASTIdVariable *IdVar;
    };
};
class ASTMultiVariable:public ASTVariable{
public:
    ASTVariable* var1;
    ASTVariable* var2;
    ASTMultiVariable(ASTVariable * var1,ASTVariable * var2)
    {
        this->var1 = var1;
        this->var2 = var2;
    }
};
class ASTIdVariable:public ASTVariable{
public:
    ASTIdNode *id_var;
    ASTIdVariable(ASTIdNode* id_var )
    {
        this->id_var = id_var;
    }
};


//Identifiers
class ASTIdNode: public ASTTerm
{
public:
    string id;
    int num_index;
    string id_index;
    ASTIdNode(string id)
    {
        string newid = "";
        for (int i=0;i<id.size();i++)
        {
            if ((id[i]>='a' && id[i]<='z') || (id[i]>='A' && id[i]<='Z') || (id[i]>='0' && id[i]<='9') )
                newid += id[i];
            else 
                break;
        }
        this->id = newid;
        this->num_index=-1;
        this->id_index="\0";
    }
    ASTIdNode(string id, string num_index, string id_index)
    {
        string newid = "";
        for (int i=0;i<id.size();i++)
        {
            if ((id[i]>='a' && id[i]<='z') || (id[i]>='A' && id[i]<='Z') || (id[i]>='0' && id[i]<='9') )
                newid += id[i];
            else 
                break;
        }
        this->id = newid;

        if(num_index!="-1")
             num_index = num_index.substr(1,num_index.size()-2);
        
        int num_index1 = stoi(num_index);
        
        if(id_index!="NULL")
        {
            id_index = id_index.substr(1,id_index.size()-2);
            cout<<"array id index is :: "<<id_index<<endl;
        }
        else
            id_index="\0";

        
        this->num_index=num_index1;
        this->id_index=id_index;
    }
    void accept(Visitor * v)
    {
        v->visit(this);
    }
    
};


//declaration parameters
class ASTDeclParams:public ASTDeclStmt{
public:
        ASTDeclMultiParams* DeclMultiParams;
        ASTDeclIdParams* DeclIdParams;
        ASTDeclParams ()
        {
            this->DeclMultiParams=NULL;
            this->DeclIdParams=NULL;
        }
        void accept(Visitor * v)
        {
            v->visit(this);
        }

};
class ASTDeclMultiParams:public ASTDeclParams{
public:
   ASTDeclParams *param1;
   ASTDeclParams *param2;
   ASTDeclMultiParams(ASTDeclParams* param1, ASTDeclParams* param2)
   {
       this->param1 = param1;
       this->param2 = param2;
   }
   void accept(Visitor * v)
   {
       v->visit(this);
   }
};
class ASTDeclIdParams:public ASTDeclParams{
public:
    ASTIdNode *id;
    ASTDeclIdParams(ASTIdNode* id)
    {
        this->id = id;
    }
    void accept(Visitor* v)
    {
        v->visit(this);
    }
};

//assignment
class ASTAssignment:public ASTCodeStmt{
public:
    ASTIdNode *id;
    ASTExp *exp;
    ASTAssignment(ASTIdNode *id, ASTExp *exp)
    {
        this->id = id;
        this->exp = exp;
    }
    void accept(Visitor *v)
    {
        cout<<"calling assignment visit"<<endl;
        v->visit(this);
    }
};

//goto statement
class ASTGotoStmt:public ASTCodeStmt{
public:
    union{
        ASTGoto* Goto;
        ASTGotoExp* GotoExp;
    };
};
class ASTGoto:public ASTGotoStmt{
public:
    string id;
    ASTGoto(string id)
    {
        this->id = id;
    }

};
class ASTGotoExp: public ASTGotoStmt{
public:
    string id;
    ASTExp *exp;
    ASTGotoExp(string id, ASTExp* exp)
    {
        this->id = id;
        this->exp = exp;
    }
};
