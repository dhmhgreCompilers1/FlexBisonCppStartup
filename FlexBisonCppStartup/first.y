
%language "C++"

%{
#include <iostream>
#include "first.tab.h"

using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
%}
%error-verbose

%code requires { 
	#include "Composite.h"
	#include "CompositeConcrete.h"
}

%union {
	 CSTNode *node;
};

%start compileunit
%token <node> NUMBER
%left '+'
%type <node> compileunit statements statement expression
%%

compileunit: statements { g_root= $$ = new CCompileUnit((CStatements *)$1);}
			;

statements : statement				{ $$ = new CStatements((CStatement *)$1); }
		   | statements statement	{ $$ = new CStatements((CStatements *)$1,(CStatement *)$2); }
		   ;

statement : expression ';'	{ $$ = new CStatement((CExpression *)$1); }
		  | ';'				{ $$ = new CStatement(); }
		  ;

expression : NUMBER					   { $$ = $1; }
		   | expression '+' expression { $$ = new CExpression((CExpression *)$1,(CExpression *)$3); }
		 ;


%%
namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}

void main(int argc, char **argv){
	CSTNode *root;
	fopen_s(&yyin,"test.txt","r");
	yy::parser *p = new yy::parser();
	p->parse();
	root = g_root;
	cout <<"Finished!!!";
	root->PrintSyntaxTree();

}
