#pragma once


class CNUMBER;
class CExpression;
class CStatement;
class CStatements;
class CCompileUnit;

template <typename T>
class Result {
public:
	T m_value;
	
	operator T() {
		return m_value;
	}

	static Result<T> defaultResult() {
		return *(new Result<T>());
	}	
};

typedef struct Result<int *> Y;


class BaseVisitor {
public:

	BaseVisitor();

	virtual Y VisitCompileUnit(CCompileUnit* visitor);
	virtual Y VisitStatements(CStatements* visitor);
	virtual Y VisitStatement(CStatement* visitor);
	
	virtual Y VisitExpression(CExpression* visitor);
	virtual Y VisitNUMBER(CNUMBER* visitor);
	
};


