#include "CompositeConcrete.h"

CCompileUnit::CCompileUnit(CStatements *stats):CSTNode(COMPILEUNIT,1,stats){	
}
CCompileUnit::~CCompileUnit() {
}

CStatements::CStatements(CStatement* stat) :CSTNode(STATEMENTS,1,stat){}

CStatements::CStatements(CStatements *stats, CStatement *stat) :CSTNode(STATEMENTS,2,stats,stat) {	
}
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

void CCompileUnit::PrintSyntaxTree(ofstream* dotfile) {
	if (m_parent != nullptr) {
		(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	}
	// Call base class method to do the visit
	CSTNode::PrintSyntaxTree(dotfile);
}
void CStatements::PrintSyntaxTree(ofstream* dotfile) {

	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	// Call base class method to do the visit
	CSTNode::PrintSyntaxTree(dotfile);
}
void CStatement::PrintSyntaxTree(ofstream* dotfile) {

	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	// Call base class method to do the visit
	CSTNode::PrintSyntaxTree(dotfile);
}
void CExpression::PrintSyntaxTree(ofstream* dotfile) {

	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	// Call base class method to do the visit
	CSTNode::PrintSyntaxTree(dotfile);
}
void CNUMBER::PrintSyntaxTree(ofstream* dotfile) {

	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	// Call base class method to do the visit
	CSTNode::PrintSyntaxTree(dotfile);
}
