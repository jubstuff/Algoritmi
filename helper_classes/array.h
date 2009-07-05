//classe Array
#ifndef ARRAY_H_
#define ARRAY_H_

#include <time.h>
#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

class Array {
  friend ostream &operator<< (ostream &, const Array &);
  friend istream &operator>> (istream &, Array &);
  public:
    Array(int = 10);				//Costruttore di default
    Array( const Array & );			//Costruttore di copia
    ~Array();					//Distruttore
    int getSize() const;			//Restituisce size
    const Array &operator= (const Array &); 	//assegna gli Array
    bool operator== (const Array &) const; 	//Confronta due Array
    bool operator!= (const Array &right) const  {
      return ! ( *this == right );
    }
    int &operator[] (int); 			//operatore di indicizzazione
    const int &operator[] (int) const; 		//operatore di indicizzazione
    void mischia();

  private:
    int size;
    int *ptr;
    void scambia(int &,int &);

};
#endif
