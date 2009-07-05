#ifndef CALCOLA_TEMPO_H_
#define CALCOLA_TEMPO_H_

#include <sys/time.h>
// Funzione che calcola il tempo trascorso fra due chiamate
// di gettimeofday(). Prende in ingresso il tempo di inizio
// il tempo di fine, e un flag che se alto ritorna il tempo
// in secondi, altrimenti in microsecondi
double tempo_esecuzione(timeval start,timeval end,bool secondi=1);

#endif
