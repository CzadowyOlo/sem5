%{
    #include <stdbool.h>
    bool displaydoxy = false;
%}

%x COM1 
%x COM2
%x DOC1
%x DOC2
%x INC
%x PRINT

%%
"printf\("    {ECHO; BEGIN(PRINT);}
#    {ECHO; BEGIN(INC);}
"/\\\n/"    {BEGIN(COM1);}
\/\*\*|\/\*!    {
    if(displaydoxy){
    {ECHO;}
    }
    else{
        { BEGIN(DOC1);}
    }
}
\/\/\/|\/\/!  {    if(displaydoxy){
    {ECHO;}
    }
    else{
        {BEGIN(DOC2);}
    }}
\/\//[^\/!]   {BEGIN(COM1);}
\/\*/[^\*!]     {BEGIN(COM2);}

<PRINT>{
    "\);" {ECHO;  BEGIN(INITIAL);}
    \\\)\;  {ECHO;}
}

<INC>{
    ".h' '>"|".h>"|".h\""|".h' '\""    {ECHO;  BEGIN(INITIAL); }
    .       {ECHO;}    
    \n      {ECHO; BEGIN(INITIAL);}
}

<DOC1>{
    \*\/  { BEGIN(INITIAL);}
    \n   {  }
    .   { }
}

<DOC2>{
    \n  {ECHO;  BEGIN(INITIAL);}
    .   { }
}

<COM1>{
    "\\\n" { }
    "\n"    {ECHO; BEGIN(INITIAL); }
    .       { }
}

<COM2>{
    "\*\/"     { BEGIN(INITIAL);}
    \n   { }
    .   { }
}



%%

int yywrap(){}
int main(int argc, char ** argv){

    if ( argc > 1 && ! strcmp(argv[1], "--doxygen")){
        displaydoxy = true;
    }
    yylex();
    return 0;
}