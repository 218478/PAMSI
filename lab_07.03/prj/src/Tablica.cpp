#include "Tablica.h"


Tablica::Tablica(int x) {
  elementy = new int[x];
  rozmiar = x;
  indeks = 0;
}

Tablica::~Tablica() { delete [] elementy; rozmiar = indeks = 0; }

bool Tablica::czy_pelne() {
  if(indeks >= (rozmiar) )
    return true;
  else
    return false;
}

void Tablica::zapisz(int dana) {
  if( czy_pelne() )
    zwieksz_rozmiar();

  elementy[indeks++] = dana;
}
 
int Tablica::zwieksz_rozmiar() {
  long nowy_rozmiar = rozmiar +rozmiar*0.5;
  try {
    int *nowe_elementy = new int[nowy_rozmiar];

    for(unsigned long i=0; i < rozmiar; i++)
      nowe_elementy[i] = elementy[i];

    delete [] elementy;
    rozmiar = nowy_rozmiar;
    elementy=nowe_elementy;

    return 0;
  }
  catch (std::bad_alloc& ex) {
    std::cerr << ex.what() << std::endl;
    return -1;
  }

}

unsigned long Tablica::zwroc_rozmiar() { return rozmiar; }
    

void Tablica::wypisz() {
  std::cout << "Indeks: " << indeks << "    Rozmiar: " << rozmiar << "\n\n";
  for(unsigned int i=0; i < rozmiar; i++)
    std::cout << elementy[i] << std::endl;
}

