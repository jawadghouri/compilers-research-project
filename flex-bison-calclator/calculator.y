%{
        #include <stdio.h>
%}

%token INT FLOAT PLUS MINUS MULT DIV LPAREN RPAREN EOL

%%
        input:    /* empty */
                | input line
        ;

        line:     EOL                { printf("> "); }
                | expr EOL           { printf("Result: %d\n", $1); }
        ;

        expr:     INT                { $$ = $1; }
                | expr PLUS expr     { $$ = $1 + $3; }
                | expr MINUS expr    { $$ = $1 - $3; }
                | expr MULT expr     { $$ = $1 * $3; }
                | expr DIV expr      { $$ = $1 / $3; }
                | LPAREN expr RPAREN { $$ = $2; }
        ;
%%

int main() 
{
  yyparse();
  return 0;
}

yyerror(char *s) 
{
  fprintf(stderr, "Error: %s\n", s);
}