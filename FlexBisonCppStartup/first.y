
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
}

%union {
	 CSTNode *node;
};

%start compileunit
%token <node> NUMBER
%left '+'
%type <node> compileunit statements statement expression
%%

compileunit: statements { g_root= $$ = new CSTNode(COMPILEUNIT,1,$1);}
			;

statements : statement				{ $$ = new CSTNode(STATEMENTS,1,$1); }
		   | statements statement	{ $$ = new CSTNode(STATEMENTS,2,$1,$2); }
		   ;

statement : expression ';'	{ $$ = new CSTNode(STATEMENT,1,$1); }
		  | ';'				{ $$ = new CSTNode(STATEMENT,0); }
		  ;

expression : NUMBER					   { $$ = $1; }
		   | expression '+' expression { $$ = new CSTNode(STATEMENTS,2,$1,$3); }
		 ;


%%
namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}

void main(int argc, char **argv){

	fopen_s(&yyin,"test.txt","r");
	yy::parser *p = new yy::parser();
	p->parse();


}
