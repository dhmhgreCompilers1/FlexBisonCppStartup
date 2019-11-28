#include "Composite.h"

// initialize static variables
CSTNode* g_root = NULL;
int CSTNode::ms_serialCounter = 0;
const char* g_nodeTypeLabels[] = { "COMPILEUNIT","STATEMENTS", "STATEMENT", "EXPRESSION_NUMBER", "EXPRESSION_ADDITION" };

CSTNode::CSTNode(NodeType type, int num, ...) :m_nodeType{ type } {
	va_list argumentList;
	CSTNode* child;

	va_start(argumentList, num);

	m_serial = ms_serialCounter++;
	m_graphvizLabel = g_nodeTypeLabels[m_nodeType];
	m_children = new list<CSTNode*>();

	for (int i = 0; i < num; i++) {
		child = va_arg(argumentList, CSTNode*);		
		m_children->push_back(child);
		child->SetParent(this);
	}

	va_end(argumentList);
}

CSTNode::~CSTNode() {
	list<CSTNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		delete *it;
	}
	delete m_children;
}

NodeType CSTNode::GetNodeType() {
	return m_nodeType;

}
string CSTNode::GetGraphVizLabel() {
	return m_graphvizLabel;
}

void CSTNode::PrintSyntaxTree() {
	list<CSTNode*>::iterator it;
	cout << "Visiting node " << m_graphvizLabel << std::endl;
	for ( it = m_children->begin(); it !=m_children->end(); it++) {
		(*it)->PrintSyntaxTree();
	}
}
