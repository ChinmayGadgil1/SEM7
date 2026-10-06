%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*    printf("Identifier: %s\n", yytext);
[ \t\n]+                  ;
.                         printf("Not an identifier: %s\n", yytext);
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}