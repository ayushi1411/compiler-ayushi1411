#include<bits/stdc++.h>
using namespace std;

class ASTNode{
// public:
    // virtual void accept(Visitor *);
}

//declaration block
class ASTDeclBlockNode : public ASTNode{
private:
    ASTDeclStmt * decl_stmt;
    ASTCodeBlockNode  *code_block;
// public:
    // void accept(Visitor *);
}

//declaration statement
class ASTDeclStmt{

}
class ASTParamsDeclStmt:public ASTDeclStmt{
private:
    ASTDeclParams *params;
}
class ASTMultiDeclStmt:public ASTDeclStmt{
private:
    ASTDeclStmt *stmt1;
    ASTDeclStmt *stmt2;
}

//code block
class ASTCodeBlockNode : public ASTNode{ 
    private:
        ASTCodeStmt * code_stmt;
    // public:
        // void accept(Visitor *);
}

//code statements
class ASTCodeStmt{

}
class ASTCodeAssignment:public ASTCodeStmt{
private:
    ASTAssignment *assign;
}
class ASTMultiCodeAssignment: public ASTCodeStmt{
private:
    ASTCodeStmt *stmt;
    ASTAssignment *assign;
}
class ASTCodePrint:public ASTCodeStmt{
private:
    ASTPrintStmt *stmt;
}
class ASTCodeRead:public ASTCodeStmt{
private:
    ASTIdNode *id;
}
class ASTCodeIfElse:public ASTCodeStmt{
private:
    ASTIfStmt *ifstmt;
    ASTElseStmt *elsestmt;
}
class ASTCodeIfStmt:public ASTCodeStmt{
private:
    ASTIfStmt *ifstmt;
}
class ASTCodeFor:public ASTCodeStmt{
private:
    ASTForStmt *stmt;
}
class ASTCodeWhile:public ASTCodeStmt{
private:
    ASTWhileStmt *stmt;
}
class ASTCodeGoto:public ASTCodeStmt{
private:
    ASTGotoStmt *stmt;
}
class ASTCodeLabel:public ASTCodeStmt{
private:
    string id;
}
class ASTMultiCodePrint:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt1;
    ASTPrintStmt *stmt2;
}
class ASTMultiCodeRead:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt;
    ASTIdNode *id;
}
class ASTMultiCodeIfElse:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt;
    ASTIfStmt *ifstmt;
    ASTElseStmt *elsestmt;
}
class ASTMultiCodeIfStmt:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt;
    ASTIfStmt *ifstmt;
}
class ASTMultiCodeFor:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt1;
    ASTForStmt *stmt2;
}
class ASTMultiCodeWhile:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt1;
    ASTWhileStmt *stmt2;
}
class ASTMultiCodeGoto:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt1;
    ASTGotoStmt *stmt2;
}
class ASTMultiCodeLabel:public ASTCodeStmt{
private:
    ASTCodeStmt *stmt;
    string id;
}


//print statement
class ASTPrintStmt{

}
class ASTMultiPrintStmt:public ASTPrintStmt{
private:
    ASTPrintStmt *stmt1;
    ASTFinalPrintStmt *stmt2;
}
class ASTFinPrintStmt: public ASTPrintStmt{
private:
    ASTFinalPrintStmt *stmt;
}

//final print statement
class ASTFinalPrintStmt{

}
class ASTFinalPrintStmtId:public ASTFinalPrintStmt{
private:
    ASTIdNode *id;
    bool newline;
}
class ASTFinalPrintStmtText:public ASTFinalPrintStmt{
private:
    string text;
    bool newline;
}

//if statement
class ASTIfStmt{
private:
    ASTExp *exp;
    ASTCodeStmt *stmt;
}

//else statement
class ASTElseStmt{

}
class ASTElse:public ASTElseStmt{
private:
    ASTCodeStmt *stmt;
}
class ASTElseIf;public ASTElseStmt{
private:
    ASTIfStmt *if_stmt;
}

//for statement
class ASTForStmt{
private:
    ASTForExp *exp;
    ASTCodeStmt *stmt;
}

//for expression
class ASTForExp{
private:
    string id;
    int num1;
    int num2;
    int num3;
}

//while statement
class ASTWhileStmt{
private:
    ASTExp *exp;
    ASTCodeStmt *stmt;
}

//variable
class ASTVariable{
// public:
    // virtual void accept(Visitor *);
}
class ASTMultiVariable:public ASTVariable{
private:
    ASTVariable * var1;
    ASTVariable * var2;
// public:
    // void accept(Visitor *);
}
class ASTIdVariable:public ASTVariable{
private:
    ASTIdNode *id_var;
// public:
    // void accept(Visitor *);
}

//Identifiers
class ASTIdNode{
// public:
    // virtual void accept(Visitor *);
}
class ASTId:public ASTIdNode{
private:
    string id;
// public:
    // void accept(Visitor *);
}
class ASTArrayIndexNum: public ASTIdNode{
private:
    string id;
    int index;
// public:
    // void accept(Visitor *);
}
class ASTArrayIndexId: public ASTIdNode{
private:
    string id;
    string index;
// public:
    // void accept(Visitor *);
}


//declaration parameters
class ASTDeclParams{

}
class ASTDeclMultiParams:public ASTDeclParams{
private:
   ASTDeclParams *param1;
   ASTDeclParams *param2; 
}
class ASTDeclIdParams:public ASTDeclParams{
private:
    ASTIdNode *id;
}

// Term
class ASTTerm{
// public:
    // virtual void accept(Visitor *);
}
class ASTTermNum : public ASTTerm{
private:
    int num;
// public:
    // void accept(Visitor *);
}
class ASTTermId : public ASTTerm{
private:
    ASTIdNode * id;
// public:
    // void accept(Visitor *);
}

//Expression
class ASTExp{
// public:
    // virtual void accept(Visitor *);
}
class ASTExpTerm:public ASTExp{
private:
    ASTTerm *term;
// public:
    // void accept(Visitor *);
}
class ASTExpParan:public ASTExp{
private:
    ASTExp *exp;
// public:
    // void accept(Visitor *);
}
class ASTExpOps:public ASTExp{
private:
    ASTExp *left_exp;
    string op_type;
    ASTExp *right_exp;
// public:
    // void accept(Visitor *);
}

//assignment
class ASTAssignment{
private:
    ASTIdNode *id;
    ASTExp *exp;
// public:
    // void accept(Visitor *);
}

//goto statement
class ASTGotoStmt{

}
class ASTGoto:public ASTGotoStmt{
private:
    string id;
}
class ASTGotoExp: public ASTGotoStmt{
private:
    string id;
    ASTExp *exp;
}
