#include "test/*asd*/fheader.h"
#include <stdio.h>
#include <foo/*bar*/baz.h>   /* <-- this file may require -I. in GCC */

//dupsko

/*

1) //
2) /*
3) /**
4) /*!
5) ///
6) //!

*/

/** \brief Java style Doc String - Foo function */
int foo();

int bar(); /**< Bar function */

/// .NET Style Doc String
int g_global_var = 1;

/* Hello
/* World
// */
int baz();
// */

/*! Global variable
 *  ... */
volatile int g_global;

//! Main
int main(int argc, const char* argv)
{
    printf("/* foo bar");
    //*/ bar();

    // \
    /*
    baz();
    /*/
    foo();
    //*/

/\
/*
    baz();
/*/
    foo();
//*/

    return 1; /
}