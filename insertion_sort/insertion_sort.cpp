#include "insertion_sort.h"

void insertion_sort(Array &A){
  int i,j,key;
  for(i=1;i<A.getSize();i++){ 	//qui ho dovuto cambiare:nello pseudocodice ci sta i=2 perchè
    key = A[i];			//gli elementi dell'array iniziano da 1 e non da 0 come nel c++
    j = i-1;
    while(j>=0 && A[j]>key){ 	// dato che abbiamo messo il 2 nel for, qui la condizione da testare 
      A[j+1] = A[j];		// è >=0 e non solo > come nel libro
      j -= 1;
    }
  A[j+1] = key;
  }
  cout << "\nFinito l'ordinamento di un array di " << A.getSize() << " elementi\n\n";
}