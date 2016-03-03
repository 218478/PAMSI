#ifndef STORAGE_CLASS_H
#define STORAGE_CLASS_H

class storage_class {
private:
    int *elements;
    unsigned int rozmiar;
    unsigned int indeks; // zmienna, ktora przechowuje w pamieci indeks ostatniego elementu
public:
    storage_class();

    ~storage_class();

    bool is_full();

    void save(int n);

    unsigned int get_size();

    bool increase_size();

    int get();

};

#endif
