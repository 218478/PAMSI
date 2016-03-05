#include "../inc/storage_class.h"
#include <iostream>
#include <cstring>

using namespace std;

storage_class::storage_class() {
    elements = new int[10];
    rozmiar = 10;
    indeks = 0;
}

storage_class::~storage_class() { delete [] elements; }

unsigned int storage_class::get_size() { return rozmiar; }

void storage_class::save(int n) {
    if(is_full()) {
//        if(!increase_size())
//            cerr << "Blad alokacji pamieci" << endl;
        increase_size();
    }

    // Tutaj wazna jest kolejnosc, aby najpierw zapisac, a dopiero potem zmienic indeks
    elements[indeks++] = n;
}

bool storage_class::is_full() {
    if(rozmiar <= indeks )
        return true;
    else
        return false;
}


/*
 * W momencie alokacji podwojnej program wpieprza
 * <orkiestra tusz> 3 GB ramu
 * Ale blad jest tez gdzies indziej.
 */

bool storage_class::increase_size() {
    unsigned int nowy_rozmiar = rozmiar*3; // metoda alokacji pamieci

    int *new_elements = new int[nowy_rozmiar];

//    for(unsigned int i=0; i < rozmiar; i++) {
//        new_elements[i] = elements[i];
//    }

    copy(elements,elements+indeks,new_elements);
    // zasugerowany sposob ze http://stackoverflow.com/questions/1350630/how-to-expand-an-array-dynamically-in-c-like-in-vector

    rozmiar = nowy_rozmiar;
    delete [] elements;
    elements = new_elements;

    return true;
}

/*
 * Napisana w celu debuggowania programu
 */
int storage_class::get() { return elements[indeks]; }
