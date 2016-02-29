#include "../inc/storage_class.h"

using namespace std;

storage_class::storage_class() {
    elements = new int[10];
    rozmiar = 10;
}

int storage_class::get_size() {
    return rozmiar;
}

bool storage_class::save(int n) {
    if(!is_full())
        ;
    else
    {
        increase_size();
    }

}

bool storage_class::is_full() {


    return false;
}

bool storage_class::increase_size() {
    int *new_elements = new int[rozmiar+1];
    for(int i=0; i < rozmiar; i++) {
        new_elements[i] = elements[i];
    }
    rozmiar++;
    delete elements; // tutaj nie jestem pewien czy nie bedzie wycieku pamieci
    elements = new_elements;
}
