%{
#include <iostream>   
#include <string> 
#include <math.h>
#include <stdio.h>
#include "../arithmetics.hpp"
#include <cstdlib> // for atoi
#include <vector>
#include <map>
#include <fstream>
#define YYDEBUG 1

extern int yylex (void);
extern int yyparse();
void yyerror (std::string s);
extern FILE *yyin;
FILE *fout;     
// Plik wyjściowy z kodem MW
// Mapa ktorej kluczem będą nazwy zmiennych,
// a adresami indeksy adresów pamięci
map<std::string, int> p {{"acc", 0}};
size_t p_len = 1;
size_t k = 0;
string dupa = ""; // kod assemblera w zmiennej dupa
string cipka = "";
string cipkaa = "";

%}
%code requires {
  #include <string>
}

/* Bison declarations. */
%define parse.error verbose

%define api.value.type {std::string}

%token NUM
%token IDENTIFIER
%token ASSIGN
%token NEQ LEQ GEQ
%token PROCEDURE IS_VAR IS_BEGIN BEGINN END PROGRAM_IS_VAR PROGRAM_IS_BEGIN IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL READ WRITE

%left '-' '+'
%left '*' '/'
%left '%'

%%
program_all:
    procedures main

procedures:
    procedures PROCEDURE proc_head IS_VAR declarations BEGINN commands END
|   procedures PROCEDURE proc_head IS_BEGIN commands END
|   %empty

main:
    PROGRAM_IS_VAR declarations BEGINN commands END {dupa += $4 + "HALT\n"; cout<<"CIPASKO\n"; k++;}
|   PROGRAM_IS_BEGIN commands END

commands:
    commands command {$$ += $2;}
|   command {$$ = $1;}


command:
    IDENTIFIER ASSIGN expression ';'                {cipka = ""; assign_val(cipka, k, p, $1); $$ = $3 + cipka;}
|   IF condition THEN commands ELSE commands ENDIF
|   IF condition THEN commands ENDIF                {cipka = ""; cipkaa = ""; cipka = $2; cipkaa = $4; cipka += to_string(k) + "\n"; cout<<cipka + "\n" + cipkaa + "\n"; $$ = cipka + cipkaa;}
|   WHILE condition DO commands ENDWHILE
|   REPEAT commands UNTIL condition ';'
|   proc_head ';'
|   READ IDENTIFIER ';'                             {cipka = ""; read_val(cipka, k, p, $2); $$ = cipka;}
|   WRITE value ';'                                 {cipka = ""; write_val(cipka, k, p, $2);$$ = cipka;}


proc_head:
    IDENTIFIER '(' declarations ')' 

declarations:
    declarations ',' IDENTIFIER     { p.insert(pair<string,int>($3,p_len)); p_len++;cout<< "INSERT plen: " << p_len << " p[" << $3 <<"] = " << p[$3] << endl;}
|   IDENTIFIER                      { p.insert(pair<string,int>($1,p_len)); p_len++;cout<< "INSERT plen: " << p_len << " p[" << $1 <<"] = " << p[$1] << endl;}

expression:
    value               {cipka = ""; set_val(cipka, k, p, $1); $$ = cipka;}
|   value '+' value     {cipka = ""; add(cipka, k, p, $1, $3); $$ = cipka;}
|   value '-' value     {}
|   value '*' value     {}
|   value '/' value     {}
|   value '%' value     {}

condition:
    value '=' value     {cipka = ""; is_equal(cipka, k, p, $1, $3); $$ = cipka;}
|   value '>' value     {}
|   value '<' value     {}
|   value GEQ value     {}
|   value LEQ value     {}
|   value NEQ value     {cipka = ""; is_notequal(cipka, k, p, $1, $3); $$ = cipka;}

value:
    NUM         {}
|   IDENTIFIER  { if( p.find($1) == p.end() ){
                yyerror("undeclared variable \"" + $1 + "\"\n");
                YYERROR;
            }}

%%

void yyerror(std::string s){
  std::cout << "\nBłąd: " << s << std::endl;
}
//cipa
int main(int argc, char const * argv[]){
  
    if(argc < 3){
        cout << "Za mała liczba argumentów!" << endl;
        return -1;
    }

    FILE *data;
    data = fopen( argv[1], "r" );
    if( !data ){
        cout << "Nie ma takiego pliku!" << endl; 
        return -1;
    }
    yyin = data;

    ofstream out(argv[2]);

    //yydebug = 1; // This is new    
    yyparse();
    
    cout << endl;
    // Wypisuje wszytskie nazwy zmiennych wraz z ich adresami pamięci
    for(const auto& elem : p) {
        std::cout << "dupcia: " << elem.first << " " << elem.second << endl;
    }
    string kobieta = dupa + cipka;
    out << kobieta;
    fclose(data);
    //fclose(out);
    return 0;
}
