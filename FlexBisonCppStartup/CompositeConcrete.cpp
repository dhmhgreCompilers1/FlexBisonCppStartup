#include "CompositeConcrete.h"

CCompileUnit::CCompileUnit(CStatements *stats):CSTNode(COMPILEUNIT,1,stats){}
CCompileUnit::~CCompileUnit() {}

CStatements::CStatements(CStatement* stat) :CSTNode(STATEMENTS,2,stat){}
CStatements::CStatements(CStatements *stats, CStatement *stat) :CSTNode(STATEMENTS,2,stats,stat) {}
CStatements::~CStatements() {}


CStatement::CStatement() :CSTNode(STATEMENT,1,nullptr){}
CStatement::CStatement(CExpression *expr):CSTNode(STATEMENT,1,expr) {}
CStatement::~CStatement() {}


CExpression::CExpression(CNUMBER *num):CSTNode(EXPRESSION_NUMBER,2,num,nullptr) {}
CExpression::CExpression(CExpression *exprl, CExpression *exprr):CSTNode(EXPRESSION_ADDITION,2,exprl,exprr) {}
CExpression::~CExpression() {}

CNUMBER::CNUMBER(char *text,int val) :CSTNode(EXPRESSION_NUMBER,0) {
	m_value.i = val;	
}
CNUMBER::CNUMBER(char* text, double val) : CSTNode(EXPRESSION_NUMBER, 0) {
	m_value.d = val;	
}
CNUMBER::~CNUMBER() {}


Y CCompileUnit::Accept(BaseVisitor* visitor) {
	return visitor->VisitCompileUnit(this);
}
Y CStatements::Accept(BaseVisitor* visitor) {
	return visitor->VisitStatements(this);
}
Y CStatement::Accept(BaseVisitor* visitor) {
	return visitor->VisitStatement(this);
}
Y CExpression::Accept(BaseVisitor* visitor) {
	return visitor->VisitExpression(this);
}
Y CNUMBER::Accept(BaseVisitor* visitor) {
	return visitor->VisitNUMBER(this);
}

void CCompileUnit::PrintTree(ofstream* outfile, CSTNode* current, CSTNode* parent) {}
void CStatements::PrintTree(ofstream* outfile, CSTNode* current, CSTNode* parent) {}
void CStatement::PrintTree(ofstream* outfile, CSTNode* current, CSTNode* parent) {}
void CExpression::PrintTree(ofstream* outfile, CSTNode* current, CSTNode* parent) {}
void CNUMBER::PrintTree(ofstream* outfile, CSTNode* current, CSTNode* parent) {}
