
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
void yyerror(const char *message){
	cout << message;
}

void main(){}
