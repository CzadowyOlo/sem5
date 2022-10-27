#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[argc+1]){



    const char* pattern = argv[1];
    unsigned char y = *(unsigned char*)(&pattern[0]);
    printf("first bit %d\n", pattern[0]);
    printf("first bit %d\n", y);

    // if((pattern[0] > 224)){
    //     printf("dupa\n");
    // }

    return 0;
}
