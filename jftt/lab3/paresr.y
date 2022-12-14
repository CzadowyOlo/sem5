%{
#include <iostream>    
#include <math.h>
#include <stdio.h>
#define BASE 1234577

extern int yylex (void);
extern int yyparse();
void yyerror (std::string dup);
std::string postfix = "";
%}

/* Bison declarations. */

%define api.value.type {double}
%token NUM
%token LEFT_BRACE
%token RIGHT_BRACE
%token ERR
%token MINUS
%token PLUS
%token MULT
%token DIV
%token POW
%type exp
%type value
%type line


%left MINUS PLUS
%left MULT DIV
%left NEG /* negation--unary minus */
%nonassoc POW /* exponentiation */

%% /* The grammar follows. */
input: 
    %empty
    | input line 
;
line: 
    exp '\n' { 
      std::cout << "Notation: " << notation << std::endl;
      std::cout << "Result: " << $1 << std::endl;
      notation = "";
    }
    | error '\n' { 
      yyerrok ;
    }
;
exp:
    value { $$ = $1; postfix += std::to_string($1) + " "; }
    | exp PLUS exp { $$ = _add($1, $3, BASE); postfix += "+ ";}
    | exp MINUS exp { $$ = _sub($1, $3, BASE); postfix += "- ";}
    | exp MULT exp { $$ = _mul($1, $3, BASE); postfix += "* ";}
    | exp DIV exp {       
        int out = _div($1, $3, BASE);
        if (out == -1){
            yyerror("nieodwracalna");
            YYERROR;
        } else {
            $$ = out; 
            notation += "/ ";
        } 
        }
    | exp POW powexp { $$ = _pow($1, $3, BASE); postfix += "^ "; }
    | LEFT_BRACE exp RIGHT_BRACE { $$ = $2; }
;

value: 
    NUM { $$ = $1 % BASE; }
    | MINUS NUM %prec NEG { $$ = _neg(-$2, P); }
;

%%
void yyerror(std::string s){
  std::cout << "Błąd" << std::endl;
}
int main(){
  yyparse();
  return 0;
}