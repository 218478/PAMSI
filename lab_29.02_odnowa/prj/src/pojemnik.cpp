#include "pojemnik.h"


pojemnik::pojemnik(int x) {
  elementy = new int[x];
  rozmiar = x;
  indeks = 0;
}

pojemnik::~pojemnik() { delete [] elementy; }

bool pojemnik::czy_pelne() {
  if(indeks >= (rozmiar-1) )
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
  int nowy_rozmiar = rozmiar + 1;
  try {
    int *nowe_elementy = new int[nowy_rozmiar];

    for(unsigned int i=0; i < rozmiar; i++)
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

int pojemnik::zwroc_rozmiar() {
  return rozmiar;
}
    

