%{
#include "calculator.tab.h" // Include Bison-generated header
%}

%%

[0-9]+      { yylval = atoi(yytext); return INT; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }
"("         { return LPAREN; }
")"         { return RPAREN; }
\n          { return EOL; }
[ \t]       ; // Ignore whitespace
.           { printf("Invalid char: %s\n", yytext); }

%%

int yywrap() {
  return 1;
}
