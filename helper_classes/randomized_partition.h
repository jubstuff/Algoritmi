#include "../helper_classes/partition.h"
int randomized_partition(Array &A, int c ,int d){

     int key;
     int i=c + (rand() %(d-c)); // genero un valore compreso tra c e d !

     key = A[i];   // scambio A[i] (con i calcolato in maniera random) con
     A[i]=A[c];   // A[c] (e' l'indice del primo elemento dell'array)
     A[c]=key;

    return partition(A,c,d); // chiamo la partition.
    }
