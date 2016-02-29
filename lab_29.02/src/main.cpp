#include <iostream>
#include "../inc/storage_class.h"

using namespace std;

int main() {

    storage_class pojemnik;

    cout <<  "Rozmiar pojemnika: " << pojemnik.get_size() << " elementy." << endl;
    return 0;
}
