#ifndef COMPOSITE_
#define COMPOSITE_
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <stdarg.h>
#include "BaseVisitor.h"
using namespace std;
class BaseVisitor;

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

	// ********* Syntax Tree Traversals/Passes ************
	virtual void PrintTree(ofstream *outfile,CSTNode *current,CSTNode *parent);

	virtual Y Accept(BaseVisitor *visitor) = 0;

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
};

extern CSTNode* g_root;


#endif



