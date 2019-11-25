#ifndef COMPOSITE_CONCRETE_
#define COMPOSITE_CONCRETE_
#include "Composite.h"

// Class forward Declarations
class CStatements;
class CStatement;
class CExpression;
class CNUMBER;

// Concrete Node Classes


class CCompileUnit : public CSTNode {
public:

	CCompileUnit(CStatements* stats);
	virtual ~CCompileUnit();

	virtual void PrintSyntaxTree(CSTNode* node) override;
private:	
};

class CStatements : public CSTNode {
public:

	CStatements(CStatement* stat);
	CStatements(CStatements* stats, CStatement* stat);
	virtual ~CStatements();

	virtual void PrintSyntaxTree(CSTNode* node) override;
private:
};

class CStatement : public CSTNode {
public:

	CStatement();
	CStatement(CExpression* expr);	
	virtual ~CStatement();

	virtual void PrintSyntaxTree(CSTNode* node) override;
private:
};

class CExpression : public CSTNode {
public:

	CExpression(CNUMBER *num);
	CExpression(CExpression* exprl,CExpression*exprr);
	virtual ~CExpression();

	virtual void PrintSyntaxTree(CSTNode* node) override;
private:
};

class CNUMBER : public CSTNode {
	union value{
		int i;
		double d;
	} m_value;
public :
	CNUMBER(char *text,int val);
	CNUMBER(char* text, double val);
	virtual ~CNUMBER();

	virtual void PrintSyntaxTree(CSTNode* node) override;
};



#endif



