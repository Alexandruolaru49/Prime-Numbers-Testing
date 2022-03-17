#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "isPrime.h"

int main() {

    FILE *in = fopen("./test.in", "r");
    FILE *out = fopen("./test.out", "w");

    int n, k;
    fscanf(in, "%d %d", &n, &k);
    fprintf(out,"Numarul %d (%d iteratii) : ", n, k);


    if (isPrime(n, k) == 1) {
        fprintf(out,"este prim.");
    }
    else {
        fprintf(out,"NU este prim.");
    }


    fclose(in);
    fclose(out);
;

    return 0; 
}
