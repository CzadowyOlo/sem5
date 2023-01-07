%option noyywrap
%{
    #include "calc.tab.hpp"
    #include <iostream>
    #include <cstdlib> // for atoi
    #include <string> 

    int yylex();
%}


NUMBER  [0-9]+
ID      [a-z]+

%%
\[([^\]]|\n)*\]   ;
[ \t\n]+ 
"("         {ECHO; return '(';}
")"         {ECHO; return ')';}
","         {ECHO; return ',';}
";"         {ECHO; return ';';}
"+"         {ECHO; return '+';}
"-"         {ECHO; return '-';}
"*"         {ECHO; return '*';}
"/"         {ECHO; return '/';}
"%"         {ECHO; return '%';}
"="         {ECHO; return '=';}
">"         {ECHO; return '>';}
"<"         {ECHO; return '<';}
"!="        {ECHO; return NEQ;}
">="        {ECHO; return GEQ;}
"<="        {ECHO; return LEQ;}
":="        {ECHO; return ASSIGN;}

"IS"[ \t\n]+"VAR"                       {ECHO; return IS_VAR;}
"IS"[ \t\n]+"BEGIN"                     {ECHO; return IS_BEGIN;}
"PROGRAM"[ \t\n]+"IS"[ \t\n]+"VAR"      {ECHO; return PROGRAM_IS_VAR;}
"PROGRAM"[ \t\n]+"IS"[ \t\n]+"BEGIN"    {ECHO; return PROGRAM_IS_BEGIN;}

"PROCEDURE"         {ECHO; return PROCEDURE;}
"BEGIN"             {ECHO; return BEGINN;}
"END"               {ECHO; return END;}
"IF"                {ECHO; return IF;}
"THEN"              {ECHO; return THEN;}
"ELSE"              {ECHO; return ELSE;}
"ENDIF"             {ECHO; return ENDIF;}
"WHILE"             {ECHO; return WHILE;}
"DO"                {ECHO; return DO;}
"ENDWHILE"          {ECHO; return ENDWHILE;}
"REPEAT"            {ECHO; return REPEAT;}
"UNTIL"             {ECHO; return UNTIL;}
"READ"              {ECHO; return READ;}
"WRITE"             {ECHO; return WRITE;}


{NUMBER}    {ECHO; yylval = std::string(yytext); return NUM;}
{ID}        {ECHO; yylval = std::string(yytext); return IDENTIFIER;}

   
.           {return(yytext[0]);}

%%