#include <iostream>
#include "Composite.h"
#include "first.tab.h"
extern FILE* yyin;
using namespace std;


void main(int argc, char** argv) {
	CSTNode* root;
	fopen_s(&yyin, "test.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();
	root = g_root;
	cout << "Finished!!!";
	root->PrintSyntaxTree();

}