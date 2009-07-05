// Funzione che calcola il tempo trascorso fra due chiamate
// di gettimeofday(). Prende in ingresso il tempo di inizio
// il tempo di fine, e un flag che se alto ritorna il tempo
// in secondi, altrimenti in microsecondi
#include "calcola_tempo.h"
double tempo_esecuzione(timeval start,timeval end,bool secondi){
  double differenza_in_microsecondi = double(((end.tv_sec*1000000)+end.tv_usec)-((start.tv_sec*1000000)+start.tv_usec));
  if (secondi){
    return differenza_in_microsecondi/1000000;
  }
  return differenza_in_microsecondi;
}
