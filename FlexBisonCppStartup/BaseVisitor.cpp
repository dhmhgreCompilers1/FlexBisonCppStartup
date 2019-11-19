#include "BaseVisitor.h"


BaseVisitor::BaseVisitor() {}
Y BaseVisitor::VisitCompileUnit(CCompileUnit* visitor) {
	return Y::defaultResult();
	
}
Y BaseVisitor::VisitStatements(CStatements* visitor) {
	return Y::defaultResult();
}
Y BaseVisitor::VisitStatement(CStatement* visitor) {
	return Y::defaultResult();
}
Y BaseVisitor::VisitExpression(CExpression* visitor) {
	return Y::defaultResult();
}
Y BaseVisitor::VisitNUMBER(CNUMBER* visitor){
	return Y::defaultResult();
}
