%{
#include "minilang.h"
%}
%option nounput yylineno

%%

int | bool									return DATATYPE;

print|true|false|if|else  					return KEYWORD;


[*+-/=]										return OPERATOR;
"==="										return OPERATOR;
"!="										return OPERATOR;

[a-zA-Z_][_]*[a-zA-Z0-9_]*					return IDENTIFIER;
['"][A-Z a-z_]*['"]		    				return STRING_LITERAL;

[0-9]+										return INT_LITERAL;
[(){}]										return PARENTHESIS;
[//]*										return COMMENT;

[ \t\n]				;
[;]					;
.					printf("unexpected character\n");

%%

int yywrap(void)
{
	return 1;
}
