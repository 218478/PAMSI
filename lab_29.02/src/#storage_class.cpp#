#include "../inc/storage_class.h"

using namespace std;

storage_class::storage_class() {
    elements = new int[10];
    rozmiar = 10;
    indeks = 0;
}

int storage_class::get_size() {
    return rozmiar;
}

bool storage_class::save(int n) {
    if(is_full())
        increase_size();

    indeks++;
    elements[indeks] = n;

}

bool storage_class::is_full() {
    if(rozmiar == indeks+1)
        return true;
    else
        return false;
}

bool storage_class::increase_size() {
    int nowy_rozmiar = rozmiar + 1; // metoda alokacji pamieci

    int *new_elements = new int[nowy_rozmiar];
    for(int i=0; i < rozmiar; i++) {
        new_elements[i] = elements[i];
    }

    delete elements; // tutaj nie jestem pewien czy nie bedzie wycieku pamieci
                     // bo nie usuwam new_elements, tylko elements
    elements = new_elements;
    rozmiar = nowy_rozmiar;
}
