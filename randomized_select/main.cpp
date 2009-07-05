#include <cstdlib>
#include <iostream>
#include "../helper_classes/array.h"
#include "randomized_select.h"
#include "fstream"
//const int START_COUNT_ARRAY = 10; //Numero da cui iniziare il ciclo per l'input
//const int NUM_OF_ARRAY = 10; //Numero di array di input che si vuole valutare
//const int MAX_ARRAY = START_COUNT_ARRAY + NUM_OF_ARRAY; //Condizione da testare nel ciclo
//const int MAX = 1000; //I numeri all'interno dei vari array di input sono compresi tra 0 e MAX
using namespace std;

int main(){
   cout<<"inserire grandezza dell'array: ";
   int size = 10 ;

   Array test(size);
   for (int i=0;i<size;i++){

       test[i]=i;
   }

   for ( long int i=0;i<=(size/2);i++) { // i va da 0 a 99 per avere 100 permutazioni
         int x=rand()%size; // assegno ogni volta ad x un valore random
         int z= test[i]; // Scambio ciascun elemento dell'array con quello di
         test[i]=test[x]; // indice x dato dalla random
         test[x]=z;
         }

   cout<<test;
   cout<<endl<<"inserire i-esima statistica d'ordine: "<<endl;
   int k=0;
   cin>>k;
   cout<<endl<<"la "<<k<<"a statistica d'ordine e': "<<randomized_select(test,0,size-1,k-1)<<endl;
   system("PAUSE");
   return EXIT_SUCCESS;
}
