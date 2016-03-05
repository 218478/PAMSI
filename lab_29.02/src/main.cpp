#include <iostream>
#include <ctime>
#include <iomanip>
#include "../inc/storage_class.h"

#include <limits> // just to test the int limits

using namespace std;

void HowManyToSave(unsigned int n);

int main() {

    // Just for the info
    cout << "CLOCK_PER_SEC = " << CLOCKS_PER_SEC << endl << endl;
    cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
    cout << endl << endl;

    cout << "Rozmiar pojemnika" << setw(30) << "Czas programu" << endl;
    HowManyToSave(20);          // dziesiec     10
    HowManyToSave(1000);        // tysiac       1000
    HowManyToSave(100000);      // sto tysiecy  100 000
    HowManyToSave(1000000);     // milion       1 000 000
    HowManyToSave(1000000000);  // miliard      1 000 000 000


    return 0;
}


void HowManyToSave(unsigned int n) {
    storage_class container;

    clock_t start = clock();
    for(unsigned int i = 0; i < (n-1); i++) {
        container.save(i%1000);
        container.get(); }

    clock_t end = clock();

    float elapsed_time = float(end - start)/CLOCKS_PER_SEC*100000;


    if(n > 10000) {
        cout << setw(15) << container.get_size() << " el."
             << setw(20) << elapsed_time/100.0 << " ms" << endl;
    }
    else
    {
        cout << setw(15) << container.get_size() << " el."
             << setw(20) << elapsed_time << " us" << endl;
    }
}
