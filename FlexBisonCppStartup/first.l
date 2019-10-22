%option noyywrap


%{
#include <iostream>
#include <cstdlib>
#include "first.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}

%% 
"+" {return '+';}
";" {return ';';}
0|[1-9][0-9]* { yylval->node = new CSTNode(EXPRESSION_NUMBER,0);
				return token::NUMBER;}

[ \t\r\n]+ ;

%%