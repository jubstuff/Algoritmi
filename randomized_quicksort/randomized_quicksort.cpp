#include "randomized_quicksort.h"
#include "../helper_classes/array.h"
#include "../helper_classes/randomized_partition.h"

void randomized_quicksort(Array &A, int p, int r){

  if (p<r){ // se l'indice p e' minore dell'indice r

  int q = randomized_partition(A, p, r);

  randomized_quicksort(A,p,q-1); // chiamo la rand_quick su i due sottovettori
  randomized_quicksort(A,q+1,r);
            }
  }
