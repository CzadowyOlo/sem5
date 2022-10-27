#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <tgmath.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NO_OF_CHARS 256

size_t static getNextState(const char *pat, size_t M, size_t state, int x);
size_t static getNextState(const char *pat, size_t M, size_t state, int x)
{
    // If the character c is same as next character
    // in pattern,then simply increment state
    if (state < M && x == pat[state])
        return state+1;
 
    // ns stores the result which is next state
    int ns, i;
 
    // ns finally contains the longest prefix
    // which is also suffix in "pat[0..state-1]c"
 
    // Start from the largest possible value
    // and stop when you find a prefix which
    // is also suffix
    for (ns = state; ns > 0; ns--)
    {
        if (pat[ns-1] == x)
        {
            for (i = 0; i < ns-1; i++)
                if (pat[i] != pat[state-ns+1+i])
                    break;
            if (i == ns-1)
                return ns;
        }
    }
 
    return 0;
}
 
/* This function builds the TF table which represents4
    Finite Automata for a given pattern */
void static sigma(const char *pat, size_t M, size_t TF[][NO_OF_CHARS]);
void static sigma(const char *pat, size_t M, size_t TF[][NO_OF_CHARS])
{
    size_t state, x;
    for (state = 0; state <= M; ++state)
        for (x = 0; x < NO_OF_CHARS; ++x)
            TF[state][x] = getNextState(pat, M, state, x);
}
 
/* Prints all occurrences of pat in txt */
void search(const char *pat, char *txt);
void search(const char *pat, char *txt)
{
    size_t M = strlen(pat);
    size_t N = strlen(txt);
 
    size_t TF[M+1][NO_OF_CHARS];
 
    sigma(pat, M, TF);
 
    // Process txt over FA.
    size_t i, state=0;
    for (i = 0; i < N; i++)
    {
        state = TF[state][txt[i]];
        if (state == M)
            printf ("\n Wzorzec występuje na pozycji %zu",
                                           i-M+1);
    }
    printf("\n");
}

int main(int argc, char* argv[argc+1]){

const char* pattern = argv[1]; // @param my pattern to seek
const size_t m = strlen(pattern);
FILE *f = fopen(argv[2], "rb");
fseek(f, 0, SEEK_END);
size_t fsize = (size_t)ftell(f);
fseek(f, 0, SEEK_SET);  /* same as rewind(f); */

char *text = malloc(fsize + 1);
fread(text, fsize, 1, f);
fclose(f);

search(pattern, text);

free(text);
return 0;

}
