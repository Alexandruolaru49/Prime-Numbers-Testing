#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "isPrime.h"

// Calculam (a ^ n) % p
int power_fermat(int a, unsigned int n, int p)
{
    int res = 1;      
    a = a % p;   // Actualizam a daca a >= p
 
    while (n > 0) {
        // Daca n este impar, inmultim rezultatul cu a
        if (n & 1) {
            res = (res*a) % p;
        }
        // n ar trebui sa fie par in acest moment
        n = n >> 1; // n = n/2
        a = (a * a) % p;
    }
    return res;
}
 
/*Recursive function to calculate gcd of 2 numbers*/
// Functie recursiva care calculeaza cel mai mare divizor comun pentru doua numere
// Pentru a elimina cazurile in care gcd(a, b) este diferit de 1 , pentru ca numerele ar fi "co-prime"
int gcd(int a, int b)
{
    if(a < b)
        return gcd(b, a);
    else if(a%b == 0)
        return b;
    else return gcd(b, a%b); 
}
 
// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct
// result.

// Daca n este prim, se va returna 1 (true), iar daca nu este prim, 0 (false)
// Parametrul k indica numarul de iteratii (de cate ori se genereaza un numar a pentru care se face verificarea)
// Cu cat numarul de iteratii k este mai mare, cu atat acuratetea programului va fi mai mare.
int isPrime(int n, int k)
{
   // Eliminam cazurile :
    // Daca n <= 1 sau n = 4, numarul nu este prim
   if (n <= 1 || n == 4)  return 0; //return false
   // Daca cele de sus nu se respecta , iar n este fie 2, fie 3, numarul este prim.
   if (n <= 3) return 1;            //return true
 
   // Repetam de k ori, se face iesirea in cazul in care se intoarce 0 (false)
   while (k>0)
   {
       // Se genereaza un numar la intamplare din intervalul [2 ; n - 2]
       // Verificarea se face pentru n > 4
       int a = 2 + rand()%(n-4); 
 
       // Se verifica daca a si n sunt "co-prime", caz in care se returneaza 0 (false)
       if (gcd(n, a) != 1)
          return 0;     //return false
  
       // "Fermat's Little Theorem"
       if (power_fermat(a, n-1, n) != 1)
          return 0;     //return false
 
       k--;
    }
 
    // Daca pentru toate iteratiile nu s-a intors 0 (false), numarul este prim
    return 1;           //return true
}
