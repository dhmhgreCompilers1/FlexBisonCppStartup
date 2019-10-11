
%{
#include <iostream>
using namespace std;
void yyerror(const char *message);
extern int yylex();
%}


%start compileunit

%%

compileunit:;


%%
void yyerror(const char *message){
	cout << message;
}

void main(){}
