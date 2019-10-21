
%language "C++"

%{
#include <iostream>
#include "first.tab.h"
using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
%}


%start compileunit
%token NUMBER
%left '+'
%%

compileunit: statements
			;

statements : statement
		   | statements statement
		   ;

statement : expression ';'
		  | ';'
		  ;

expression : NUMBER
		 | expression '+' expression
		 ;


%%
namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}

void main(){}
