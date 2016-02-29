#include <iostream>
#include "../inc/storage_class.h"

using namespace std;

int main() {

    storage_class pojemnik;

    cout <<  "Rozmiar pojemnika: " << pojemnik.get_size() << " elementy." << endl;
    for(int i =0; i < 15; i++)
        pojemnik.save(i);

    cout <<  "Rozmiar pojemnika po dodaniu: " << pojemnik.get_size() << " elementy." << endl;

    return 0;
}
