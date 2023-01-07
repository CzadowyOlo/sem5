#include "test/*asd*/fheader.h" // escaped include
#include <stdio.h> // escaped include
#include <foo/*bar*/baz.h> // escaped include   //com2 begin // escaped com2


 // escaped com1
//com2 begin // escaped com2

/** \brief Java style Doc String - Foo function */
int foo();

int bar(); /**< Bar function */

/// .NET Style Doc String
int g_global_var = 1;

//com2 begin // escaped com2
int baz();

 // escaped com1
/*! Global variable
 *  ... */
volatile int g_global;

//! Main
int main(int argc, const char* argv)
{
    printf("/* foo bar"); // escaped print
    
 // escaped com1
    
 // escaped com1    //com2 begin // escaped com2
    foo();
    
 // escaped com1
/\
//com2 begin // escaped com2
    foo();

 // escaped com1
    return 1; /
}