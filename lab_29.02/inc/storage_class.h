#ifndef STORAGE_CLASS_H
#define STORAGE_CLASS_H

class storage_class {
private:
    int *elements;
    long long rozmiar;
    long long indeks; // zmienna, ktora przechowuje w pamieci indeks ostatniego elementu
public:
    storage_class();

    bool is_full();

    bool save(int n);

    int get_size();

    bool increase_size();

};

#endif
