#include "test/*asd*/fheader.h" // escaped include
#include <stdio.h> // escaped include
#include <foo/*bar*/baz.h> // escaped include   //com2 begin // escaped com2



 // escaped com1

//com2 begin // escaped com2


//start doc1
//escape doc1

int foo();

int bar(); //start doc1
//escape doc1


//start doc2
//escape doc2
int g_global_var = 1;

//com2 begin // escaped com2

int baz();

 // escaped com1

//start doc1
//escape doc1

volatile int g_global;

//start doc2
//escape doc2
int main(int argc, const char* argv)
{
    printf("/* foo bar"); // escaped print
    
 // escaped com1

    
 // escaped com1
    baz();
    //com2 begin // escaped com2



 // escaped com1
    baz();
//com2 begin // escaped com2


    return 1; /
}