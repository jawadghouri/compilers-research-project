%{
#include <stdio.h>

// Declare yylval for token values
extern int yylval;

// Declare yylex and yyerror prototypes
int yylex(void);
void yyerror(const char *s);
%}

// Token declarations
%token INT
%token PLUS MINUS MULT DIV
%token LPAREN RPAREN
%token EOL

// Precedence and associativity rules
%left PLUS MINUS
%left MULT DIV
%left UMINUS // Unary minus (optional)

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
        | MINUS expr %prec UMINUS { $$ = -$2; } // Unary minus
;

%%

int main() 
{
  yyparse();
  return 0;
}

void yyerror(const char *s) 
{
  fprintf(stderr, "Error: %s\n", s);
}
