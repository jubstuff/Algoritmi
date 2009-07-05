#include "randomized_quicksort.h"


void randomized_quicksort(Array &A, int p, int r){

  if (p<r){ // se l'indice p e' minore dell'indice r
  
  int q = randomized_partition(A, p, r);
  
  randomized_quicksort(A,p,q-1); // chiamo la rand_quick su i due sottovettori
  randomized_quicksort(A,q+1,r);
            }
  }
  
  
int randomized_partition(Array &A, int c ,int d){
    
     int key;
     int i=c + (rand() %(d-c)); // genero un valore compreso tra c e d ! 
     
     key = A[i];   // scambio A[i] (con i calcolato in maniera random) con 
     A[i]=A[c];   // A[c] (e' l'indice del primo elemento dell'array)
     A[c]=key;
    
    return partition(A,c,d); // chiamo la partition.  
     }  
  

int partition(Array &A,int e ,int f){
                                 
    int x= A[f]; // ad x assegno l'ultimo elemento dell'array.
                                
    int i= e-1; // ad i assegno l'indice del primo elemento dell'array - 1
                             
    for (int j=e; j<=f-1;j++){  // f-1 poichè il ciclo deve terminare quando j 
                               // diventa il penultimo elemento dell'array
                               
        if (A[j]<=x) {    // confronto l'elemento j-esimo con x : se è minore        
            i=i+1;            // allora incremento l'indice i
             
        int key = A[i];   // e scambio A[i] con A[j]
             A[i]=A[j];            
             A[j]=key; 
             } 
     }                     
      int key = A[i+1];      // Terminato il ciclo For, scambio A[i+1] con A[f]
          A[i+1]=A[f];    // che è l'ultimo elemento dell'array, così da 
          A[f]=key;      // posizionare l'ultimo elemento A[f] nella  
                             // posizione giusta, poichè fino ad i ci sono gli  
                             // elementi di piccoli di x;

   return i+1;          // ritorno l'indice della posizione dell'elemento pivot
    }
