#ifndef STORAGE_CLASS_H
#define STORAGE_CLASS_H

class storage_class {
private:
    int *elements;
    int rozmiar;
    int indeks; // zmienna, ktora przechowuje w pamieci indeks ostatniego elementu
public:
    storage_class();

    bool is_full();

    void save(int n);

    int get_size();

    bool increase_size();

    int get();

};

#endif
