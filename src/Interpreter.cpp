#include "ASTDefinitions.h"

class Interpreter : public Visitor 
{
public:
    void visit (class ASTNode* );
    void visit (class ASTDeclBlockNode* );
    
};

void Interpreter::visit(ASTNode* astNode)
{
    cout<<"Root noce visited"<<endl;
    ASTDeclBlockNode* astDeclBlockNode = dynamic_cast<ASTDeclBlockNode*>(astNode);
    astDeclBlockNode->accept(this); 
}

void Interpreter::visit(ASTDeclBlockNode* astDeclBlockNode)
{
    cout<<"Decl block visited"<<endl;
    return ;
}