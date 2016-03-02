#include <iostream>
#include <ctime>
#include "../inc/storage_class.h"

using namespace std;

int main() {

    cout << "Rozmiar pojemnika\t" << "Czas programu" << endl;

    clock_t start = clock();
    storage_class container;
    cout <<  "     " << container.get_size() << " el.";
    clock_t end = clock();
    double elapsed_time = double(end - start)/CLOCKS_PER_SEC*1000;
    cout << "\t\t  " << elapsed_time << " ms" << endl;

    start = clock();
    for(int i =0; i < 1000; i++)
        container.save(i%1000);
    cout <<  "     " << container.get_size() << " el.";
    end = clock();
    elapsed_time = double(end - start)/CLOCKS_PER_SEC*1000;
    cout << "\t\t  " << elapsed_time << " ms" << endl;

    start = clock();
    for(int i =0; i < 1000000; i++) {
        container.save(i%1000);
        if (i%100000 == 0)
            cout << container.get() << endl;
    }
    cout <<  "     " << container.get_size() << " el.";
    end = clock();
    elapsed_time = double(end - start)/CLOCKS_PER_SEC*1000;
    cout << "\t\t  " << elapsed_time << " ms" << endl;


    return 0;
}
