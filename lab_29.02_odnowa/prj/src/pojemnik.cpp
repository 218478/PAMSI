#include "pojemnik.h"


pojemnik::pojemnik(int x) {
  elementy = new int[x];
  rozmiar = x;
  indeks = 0;
}

pojemnik::~pojemnik() { delete [] elementy; rozmiar = indeks = 0; }

bool pojemnik::czy_pelne() {
  if(indeks >= (rozmiar) )
    return true;
  else
    return false;
}

void pojemnik::zapisz(int dana) {
  if( czy_pelne() )
    zwieksz_rozmiar();

  elementy[indeks++] = dana;
}
 
int pojemnik::zwieksz_rozmiar() {
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

unsigned long pojemnik::zwroc_rozmiar() { return rozmiar; }
    

void pojemnik::wypisz() {
  std::cout << "Indeks: " << indeks << "    Rozmiar: " << rozmiar << "\n\n";
  for(unsigned int i=0; i < rozmiar; i++)
    std::cout << elementy[i] << std::endl;
}

