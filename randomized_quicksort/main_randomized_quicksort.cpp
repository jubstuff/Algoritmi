#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "fstream"

#include "../helper_classes/array.h"
#include "randomized_quicksort.h"
#include "../helper_classes/calcola_tempo.h"


const int START_COUNT_ARRAY = 1; //Numero da cui iniziare il ciclo per l'input
const int NUM_OF_ARRAY = 100; //Numero di array di input che si vuole valutare
const int MAX_ARRAY = START_COUNT_ARRAY + NUM_OF_ARRAY; //Condizione da testare nel ciclo
const int MAX = 1000; //I numeri all'interno dei vari array di input sono compresi tra 0 e MAX

using namespace std;

int main() {

  int i,j;
  int counter = 1;
  double differenza_tempo;
  struct timeval start,end; //Queste sono per gettimeofday
  cout.precision(15); //Imposta la precisione dei numeri a 15 cifre significative max
  char nome_file_dati[] = "dati_randomized_quicksort.dat";
  char nome_file_gnuplot[] = "gnuplot_randomized_quicksort";
  //Apertura file in scrittura e controllo
  ofstream outFileGnuplot (nome_file_gnuplot,ios::out);
  ofstream outFileDati (nome_file_dati,ios::out);
  if (!outFileDati) {
		cerr << "Il file dati o quello Gnuplot non è stato aperto!" << endl;
		exit(1);
    }
  outFileDati << "#Array n°" << " | " << "Dimensione Array"  << " | " << "Tempo Impiegato" << '\n';
  for ( j = START_COUNT_ARRAY; j < MAX_ARRAY; j++) {
    //Inizializzo un array con dimensione crescente
    Array test(j*(j*100));
    cout << "Sto ordinando l'array numero " << counter
    << " di " << test.getSize() << " elementi" << endl;
    int y= test.getSize()-1;
    test.mischia();
//    cout << test;
    //Faccio partire la misurazione del tempo
    gettimeofday(&start,0);

    randomized_quicksort(test,0,y);
    //Termine misurazione
    gettimeofday(&end,0);
//    cout << test;
//    Calcolo la differenza di tempo
    differenza_tempo = tempo_esecuzione(start, end);
    cout << "Tempo impiegato: " << differenza_tempo << endl;
    //Scrivo su file il tempo impiegato
    outFileDati << counter << " " << test.getSize()  << " " << differenza_tempo << '\n';
    counter++;
    if (counter == 99)
    cout << test;
  }
  return EXIT_SUCCESS;
}
