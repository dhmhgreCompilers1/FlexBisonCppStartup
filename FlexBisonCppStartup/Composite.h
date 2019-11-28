#ifndef COMPOSITE_
#define COMPOSITE_
#include <iostream>
#include <string>
#include <list>
#include <stdarg.h>
using namespace std;

class CSTNode;
extern CSTNode* g_root;
extern const char* g_nodeTypeLabels[];
typedef enum nodeType{
	COMPILEUNIT, STATEMENTS, STATEMENT, EXPRESSION_NUMBER, EXPRESSION_ADDITION
} NodeType;

class CSTNode{
public:
	CSTNode(NodeType,int,...);
	virtual ~CSTNode();	

	//  ********* QUERY METHODS **************
	NodeType GetNodeType();
	string GetGraphVizLabel();
	virtual void PrintSyntaxTree();


	// ********** MODIFIER METHODS ***********
	void SetParent(CSTNode* parent) { m_parent = parent; }

private:
	// Type of node
	NodeType m_nodeType;
	// A label that will be used to render the node in graphviz
	string m_graphvizLabel;
	int m_serial;
	// A counter counting the nodes created for giving a
	// unique serial counter
	static int ms_serialCounter;
	list<CSTNode *> *m_children;
	CSTNode* m_parent;
};









#endif



