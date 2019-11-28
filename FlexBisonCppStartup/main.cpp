#include <iostream>
#include <fstream>
#include "Composite.h"
#include "first.tab.h"
extern FILE* yyin;
using namespace std;


void main(int argc, char** argv) {
	CSTNode* root;
	ofstream *dotfile;
	fopen_s(&yyin, "test.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();
	root = g_root;
	cout << "Finished!!!";

	dotfile = new ofstream("ST.dot",std::ofstream::out);
	(*dotfile) << "digraph G{\n";
	root->PrintSyntaxTree(dotfile);
	(*dotfile) << "}";
	dotfile->close();

	system("dot -Tgif ST.dot -o ST.gif");

}