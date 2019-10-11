%option noyywrap


%{
#include <iostream>
#include <cstdlib>
#include "first.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)

%}

%%


%%