#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "isPrime.h"

// Returneaza (x ^ y) % p
int power_miller(int x, unsigned int y, int p)
{
    int res = 1;      
    x = x % p;  // Se actualizeaza x in cazul in care x>=p
    while (y > 0)
    {
        // Daca y este impar, se multiplica resultatul cu x
        if (y & 1)
            res = (res * x) % p;
 
        // y ar trebui sa fie in acest moment par
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int millerTest(int d, int n) {
    // Pick a random number in [2..n-2]
    // Se genereaza un numar la intamplare din intervalul [2 ; n - 2]
    // Verificarea se face pentru n > 4
    int a = 2 + (rand() % (n - 4));

    //Calculeaza (a ^ d) % n
    int x = power_miller(a, d, n);

    if(x == 1 || x == (n - 1)){
        return 1; // return true;
    }

    // Se actualizeaza x cu x * x atat timp cat:
    // 1) d este diferit de n - 1
    // 2) (x^2) % n este diferit de 1
    // 3) (x^2) % n este diferit de n - 1

    while (d != n-1)
    {
        x = (x * x) % n;
        d = d * 2;
 
        if (x == 1)      return 0; // return false;
        if (x == n-1)    return 1; // return true;
    }

    return 0; // return false ;
}

// Functia returneaza 0 (false) daca n este compus si 1 (true) daca este posibil prim.
// Parametrul k indica numarul de iteratii (de cate ori se genereaza un numar a pentru care se face verificarea)
// Cu cat numarul de iteratii k este mai mare, cu atat acuratetea programului va fi mai mare.
int isPrime(int n, int k)
{
    // Eliminam cazurile :
    // Daca n <= 1 sau n = 4, numarul nu este prim
    if (n <= 1 || n == 4)  return 0;
    // Daca cele de sus nu se respecta , iar n este fie 2, fie 3, numarul este prim.
    if (n <= 3) return 1;
 
    // Vrem sa gasim un numar r >= 1, care sa respecte conditia: n = 2 ^ d * r + 1
    int d = n - 1;
    while (d % 2 == 0){
        d = d / 2;
    }
 
    // Repetam de k ori, se face iesirea in cazul in care se intoarce 0 (false)
    for (int i = 0; i < k; i++){
        if (millerTest(d, n) == 0){
            return 0;
        }
    }
    
    // Daca pentru toate iteratiile nu s-a intors 0 (false), numarul este prim
    return 1;
}
