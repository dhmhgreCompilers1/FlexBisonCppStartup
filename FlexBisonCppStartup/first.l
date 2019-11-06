%option noyywrap


%{
#include <iostream>
#include <cstdlib>
#include "first.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}
INT 0|[1-9][0-9]*
%% 
"+" {return '+';}
";" {return ';';}
0|[1-9][0-9]* { yylval->node = new CNUMBER(yytext,atoi(yytext));
				return token::NUMBER;}
[+-]?({INT}?\.{INT})|({INT}\.{INT}?) { yylval->node = new CNUMBER(yytext,atof(yytext));
									   return token::NUMBER;}


[ \t\r\n]+ ;

%%