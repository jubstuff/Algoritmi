#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "fstream"
#include "../helper_classes/array.h"
#include "insertion_sort.h"
#include "../helper_classes/calcola_tempo.h"


const int START_COUNT_ARRAY = 0; //Numero da cui iniziare il ciclo per l'input
const int NUM_OF_ARRAY = 10; //Numero di array di input che si vuole valutare
const int MAX_ARRAY = START_COUNT_ARRAY + NUM_OF_ARRAY; //Condizione da testare nel ciclo
const int MAX = 1000; //I numeri all'interno dei vari array di input sono compresi tra 0 e MAX

using namespace std;

int main() {

  int i,j;
  int counter = 1;
  double differenza_tempo;
  struct timeval start,end; //Queste sono per gettimeofday
  cout.precision(15); //Imposta la precisione dei numeri a 15 cifre significative max
  char nome_file_dati[] = "dati_insertion_sort.dat";
  char nome_file_gnuplot[] = "gnuplot_insertion_sort";
  //Apertura file in scrittura e controllo
  ofstream outFileGnuplot (nome_file_gnuplot,ios::out);
  ofstream outFileDati (nome_file_dati,ios::out);
  if (!outFileDati || !outFileGnuplot) {
		cerr << "Il file dati o quello Gnuplot non è stato aperto!" << endl;
		exit(1);
    }
  outFileDati << "#Array n°" << " | " << "Dimensione Array"  << " | " << "Tempo Impiegato" << '\n';
  for ( j = START_COUNT_ARRAY; j < MAX_ARRAY; j++) {
    //Inizializzo un array con dimensione crescente
    Array test(j*(j*100));
    cout << "Sto ordinando l'array numero " << counter
    << " di " << test.getSize() << " elementi" << endl;

    test.mischia();
    //Faccio partire la misurazione del tempo
    gettimeofday(&start,0);
    insertion_sort(test);
    //Termine misurazione
    gettimeofday(&end,0);
//    Calcolo la differenza di tempo
    differenza_tempo = tempo_esecuzione(start, end);
    cout << "Tempo impiegato: " << differenza_tempo << endl;
    //Scrivo su file il tempo impiegato
    outFileDati << counter << " " << test.getSize()  << " " << differenza_tempo << '\n';
    counter++;
  }

  return EXIT_SUCCESS;
}
