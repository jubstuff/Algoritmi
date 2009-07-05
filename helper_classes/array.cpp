#include "array.h"

//Costruttore di default



Array::Array ( int arraySize ){
  srand(time(0));
  size = ( arraySize > 0 ? arraySize : 10 );
  ptr = new int[size]; //alloca spazio per l'array
  assert( ptr != 0 ); //controlla se ci sono stati errori
  for ( int i = 0; i < size; i++ )
    ptr[i] = i; //inizializza l'array in uno stato coerente con i numeri da 0 a size-1
}

//Costruttore di copia per la classe Array
//Riceve un riferimento

Array::Array (const Array &init ) : size (init.size) {
  ptr = new int[size]; //alloca spazio per l'array
  assert ( ptr != 0 ); //controlla se ci sono stati errori


  for( int i = 0; i < size; i++)
    ptr[i] = init.ptr[i]; //copia init nell'oggetto
}

//Distruttore
Array::~Array() {
  delete [] ptr; //restituisce lo spazio dell'array
}

//Ottiene size
int Array::getSize() const { return size; }

//Overloading dell'operatore di assegnamento
const Array &Array::operator= (const Array &right) {
  if ( &right != this ) { //controlla che non sia autoassegnamento
    if ( size != right.size ){
      delete [] ptr;
      size = right.size;
      ptr = new int[size];
      assert( ptr != 0);
    }
    for ( int i = 0; i < size; i++)
	ptr[i] = right.ptr[i];
  }
  return *this;
}

//Overloading dell'operatore confronto

bool Array::operator== ( const Array &right ) const {
  if ( size != right.size)
    return false;
  for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
	return false;
  return true;
}

//Overloading operatore di indicizzazione

int &Array::operator[] (int indice){
  assert ( 0 <= indice && indice < size );
  return ptr[indice];
}

const int &Array::operator[] (int indice) const{
  assert ( 0 <= indice && indice < size );
  return ptr[indice];
}

//Overloading degli operatori di input e output

istream &operator>> (istream &input, Array &a){
  for ( int i = 0; i < a.size; i++)
    input >> a.ptr[i];
  return input;
}

ostream &operator<< (ostream &output, const Array &a){
  int i;
  cout << "\n ===Stampo l'array=== \n";
  for (i = 0; i < a.size; i++) {
    output << a.ptr[i] << " ";
    if ( (i+1) % 20 == 0 )
      output << endl;
  }
  cout << endl;
  return output;
}

void Array::mischia(){
  int i;
  for (i=0;i<size;i++){
    scambia(ptr[i],ptr[rand()%size]);
  }
}

void Array::scambia(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}

