%option noyywrap


%{
#include <iostream>
#include <cstdlib>
#include "first.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
%}

%% 
'+' {return '+';}
';' {return ';';}
0|[1-9][0-9]* {return yy::parser::token::yytokentype::NUMBER;}


%%