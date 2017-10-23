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
class ASTNode{
// public:
    // virtual void accept(Visitor *);
};

//declaration block
class ASTDeclBlockNode : public ASTNode{
public:
    ASTDeclStmt * decl_stmt;
    ASTCodeBlockNode  *code_block;
// public:
    // void accept(Visitor *);
};

//declaration statement
class ASTDeclStmt:public ASTDeclBlockNode{

};
class ASTParamsDeclStmt:public ASTDeclStmt{
public:
    ASTDeclParams *params;
};
class ASTMultiDeclStmt:public ASTDeclStmt{
public:
    ASTDeclStmt *stmt1;
    ASTDeclStmt *stmt2;
};

//code block
class ASTCodeBlockNode : public ASTDeclBlockNode{ 
    public:
        ASTCodeStmt * code_stmt;
    // public:
        // void accept(Visitor *);
};

//code statements
class ASTCodeStmt:public ASTCodeBlockNode{
public:
    union{
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
    };
};
class ASTCodeAssignment:public ASTCodeStmt{
public:
    ASTAssignment *assign;
    ASTCodeAssignment(ASTAssignment* assign)
    {
        this->assign = assign;
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
};
class ASTCodePrint:public ASTCodeStmt{
public:
    ASTPrintStmt *stmt;
    ASTCodePrint(ASTPrintStmt* stmt)
    {
        this->stmt = stmt;
    }
};
class ASTCodeRead:public ASTCodeStmt{
public:
    ASTIdNode *id;
    ASTCodeRead(ASTIdNode* id)
    {
        this->id = id;
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
};
class ASTCodeIfStmt:public ASTCodeStmt{
public:
    ASTIfStmt *ifstmt;
    ASTCodeIfStmt(ASTIfStmt* ifstmt)
    {
        this->ifstmt = ifstmt;
    }
};
class ASTCodeFor:public ASTCodeStmt{
public:
    ASTForStmt *stmt;
    ASTCodeFor(ASTForStmt *stmt)
    {
        this->stmt = stmt;
    }
};
class ASTCodeWhile:public ASTCodeStmt{
public:
    ASTWhileStmt *stmt;
    ASTCodeWhile(ASTWhileStmt *stmt)
    {
        this->stmt = stmt;
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
    ASTCodeStmt *stmt1;
    ASTPrintStmt *stmt2;
    ASTMultiCodePrint(ASTCodeStmt* stmt1, ASTPrintStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
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
};
class ASTMultiCodeIfElse:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt;
    ASTIfStmt *ifstmt;
    ASTElseStmt *elsestmt;
    ASTMultiCodeIfElse(ASTCodeStmt* stmt, ASTIfStmt* ifstmt, ASElseStmt* elsestmt)
    {
        this->stmt = stmt;
        this->ifstmt = ifstmt;
        this->elsestmt = elsestmt;
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
};
class ASTMultiCodeFor:public ASTCodeStmt{
public:
    ASTCodeStmt *stmt1;
    ASTForStmt *stmt2;
    ASTMultiCodeFor(ASTCodeStmt* stmt1, ASTCodeStmt* stmt2)
    {
        this->stmt1 = stmt1;
        this->stmt2 = stmt2;
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
    bool newline;    
    union{
        ASTMultiPrintStmt* MulPrintStmt;
        ASTFinPrintStmt* FinPrintStmt;  
    };

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
};
class ASTFinPrintStmt: public ASTPrintStmt{
public:
    ASTFinalPrintStmt *stmt;
    ASTFinPrintStmt(ASTFinalPrintStmt* stmt)
    {
        this->stmt = stmt;
    }
};

//final print statement
class ASTFinalPrintStmt:public ASTCodeStmt, public ASTPrintStmt{
public:
    union{    
        ASTFinalPrintStmtId* FinalPrintStmtId;
        ASTFinalPrintStmtText* FinalPrintStmtText;
    };
};
class ASTFinalPrintStmtId:public ASTFinalPrintStmt{
public:
    ASTIdNode *id;
    ASTFinalPrintStmtId(ASTIdNode* id)
    {
        this->id = id;
    }
};
class ASTFinalPrintStmtText:public ASTFinalPrintStmt{
public:
    string text;
    ASTFinalPrintStmtText(string text)
    {
        this->text = text;
    }
};

//if statement
class ASTIfStmt:public ASTCodeStmt{
public:
    ASTExp *exp;
    ASTCodeStmt *stmt;
};

//else statement
class ASTElseStmt:public ASTCodeStmt{

};
class ASTElse:public ASTElseStmt{
public:
    ASTCodeStmt *stmt;
};
class ASTElseIf:public ASTElseStmt{
public:
    ASTIfStmt *if_stmt;
};

//for statement
class ASTForStmt:public ASTCodeStmt{
public:
    ASTForExp *exp;
    ASTCodeStmt *stmt;
};

//for expression
class ASTForExp:public ASTForStmt{
public:
    string id;
    int num1;
    int num2;
    int num3;
};

//while statement
class ASTWhileStmt:public ASTCodeStmt{
public:
    ASTExp *exp;
    ASTCodeStmt *stmt;
};

//Expression
class ASTExp:public ASTCodeStmt{
public:
    union{
        ASTExpTerm* ExpTerm;
        ASTExpParan* ExpParan;
        ASTExpOps* ExpOps;
    };
// public:
    // virtual void accept(Visitor *);
};
class ASTExpTerm:public ASTExp{
public:
    ASTTerm *term;
    ASTExpTerm(ASTTerm *term)
    {
        this->term = term;
    }
// public:
    // void accept(Visitor *);
};
class ASTExpParan:public ASTExp{
public:
    ASTExp *exp;
    ASTExpParan(ASTExp *exp)
    {
        this->exp = exp;
    }
// public:
    // void accept(Visitor *);
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
// public:
    // void accept(Visitor *);
};


// Term
class ASTTerm:public ASTExp{
public:
    union{
        ASTTermNum* NumTerm;
        ASTTermId* IdTerm;
    };
// public:
    // virtual void accept(Visitor *);
};
class ASTTermNum : public ASTTerm{
public:
    int num;
    ASTTermNum(int num)
    {
        this->num = num;
    }
// public:
    // void accept(Visitor *);
};
class ASTTermId : public ASTTerm{
public:
    ASTIdNode *id;
    ASTTermId(ASTIdNode* id)
    {
        this->id = id;
    }
// public:
    // void accept(Visitor *);
};


//variable
class ASTVariable:public ASTTerm{
public:
    union{
        ASTMultiVariable *MulVar;
        ASTIdVariable *IdVar;
    };
// public:
    // virtual void accept(Visitor *);
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
// public:
    // void accept(Visitor *);
};
class ASTIdVariable:public ASTVariable{
public:
    ASTIdNode *id_var;
    ASTIdVariable(ASTIdNode* id_var )
    {
        this->id_var = id_var;
    }
// public:
    // void accept(Visitor *);
};


//Identifiers
class ASTIdNode: public ASTTerm{
public:
    string id;
    int num_index;
    string id_index;
    ASTIdNode(string id)
    {
        this->id=id;
        this->num_index=-1;
        this->id_index='\0';
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
            id_index = id_index.substr(1,id_index.size()-1);
        else
            id_index='\0';

        
        this->num_index=num_index1;
        this->id_index=id_index;
    }
    
// public:
    // virtual void accept(Visitor *);
};
// class ASTId:public ASTIdNode{
// public:
//     string id;
//     ASTId(string id)
//     {
//         this->id = id ;
//     };
// // public:
//     // void accept(Visitor *);
// };
// class ASTArrayIndexNum: public ASTIdNode{
// public:
//     string id;
//     int index;
// // public:
//     // void accept(Visitor *);
// };
// class ASTArrayIndexId: public ASTIdNode{
// public:
//     string id;
//     string index;
// // public:
//     // void accept(Visitor *);
// };


//declaration parameters
class ASTDeclParams:public ASTDeclStmt{

};
class ASTDeclMultiParams:public ASTDeclParams{
public:
   ASTDeclParams *param1;
   ASTDeclParams *param2; 
};
class ASTDeclIdParams:public ASTDeclParams{
public:
    ASTIdNode *id;
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
// public:
    // void accept(Visitor *);
};

//goto statement
class ASTGotoStmt:public ASTCodeStmt{

};
class ASTGoto:public ASTGotoStmt{
public:
    string id;
};
class ASTGotoExp: public ASTGotoStmt{
public:
    string id;
    ASTExp *exp;
};
