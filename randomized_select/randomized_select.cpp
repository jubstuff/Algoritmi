#include "randomized_select.h"

int randomized_select(Array& A,int p,int r,int i){
    if (p==r) { 
      return A[p];
    }
    int q = randomized_partition(A,p,r);
    cout<<"L'array e'" <<A<<endl;
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

int randomized_partition(Array& A,int p, int r){
    srand(time(0));
    int i=(p+rand() % (r-p));
    
    //queste prime 2 istruzioni scelgono l'elemento randomly
    cout<<endl<<"L'indice scelto per la partiotion e' "<<i<<endl;
    int o=A[r];
    A[r]=A[i];
    A[i]=o;		//queste altre 3 istruzioni servono a fare lo scambio dei 2 valori
   
    return partition(A,p,r); //richiama la partition
}

int partition(Array &A,int e ,int f){
                                 
    int x= A[f]; // ad x devo assegnare l'ultimo indice dell'array.
                                
    int i= e-1; // ad i devo assegnare il valore del primo indice
    
                             
    for (int j=e; j<=f-1;j++){  // f-1 poichè il ciclo termina quando j diventa 
                               // il penultimo elemento dell'array
                               
        if (A[j]<=x) {
                              
        i=i+1;
        
        int key = A[i]; //scambio A[i] con A[j];

             A[i]=A[j];
                              
              A[j]=key;           
                              
                     
      }cout<<endl<<"Vettore dopo la "<<j+1<<"a iterazione della Partition"<<A<<endl;}
                              
      int key = A[i+1];
      
             A[i+1]=A[f];
             
              A[f]=key;
              
                            
        

   return i+1;
    
    }
