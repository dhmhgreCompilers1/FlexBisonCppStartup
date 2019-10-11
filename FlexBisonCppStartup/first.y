
%language "C++"

%{
#include <iostream>
#include "first.tab.h"
using namespace std;
void yyerror(const char *message);
extern int yylex(yy::parser::semantic_type *yylval);
%}


%start compileunit

%%

compileunit:;


%%
namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}

void main(){}
