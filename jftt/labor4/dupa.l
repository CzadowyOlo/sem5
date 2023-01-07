%{
      #include <stdbool.h>
      int lines = 0; 
      int words = 0;
      bool word_occurence = false;
%}


WS  [ \t]+
NEWLINE [\n]



%%

{NEWLINE} {
printf(" ");
}

^{WS} /* bialy znak tylko na początku lini - usuń */
{WS}$ /* biały znak tylko na końcu lini - usuń */
{WS}     {printf(" ");}/* zastępuje ciąg bz jedną spacją */

%%

int yywrap(){}
int main(){
      yylex();
      //printf("lines: %d, words: %d \n", lines, words);
      return 0;
}
