#include "randomized_select.h"


int randomized_select(Array& A,int p,int r,int i){
    if (p==r) {
      return A[p];
    }
    int q = randomized_partition(A,p,r);
//    cout<<"L'array e'" <<A<<endl;
    int k = q-p;
    if (i==k){
      return A[q];
    }
    else if (i<k) {
         cout<<endl<<"Chiamo la Partition sulla parte sx dell'array"<<endl;
         cout<<"cioe' da A["<<p<<"] ad A["<<q-1<<"]"<<endl;
      return randomized_select(A,p,q-1,i);
    }
    else if (i>k){
    cout<<endl<<"Chiamo la Partition sulla parte dx dell'array"<<endl;
         cout<<"cioe' da A["<<q+1<<"] ad A["<<r<<"]"<<endl;
    return randomized_select(A,q+1,r,i-k-1);
    }
}


