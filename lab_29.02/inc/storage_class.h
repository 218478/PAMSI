#ifndef STORAGE_CLASS_H
#define STORAGE_CLASS_H

class storage_class {
private:
    int* elements;
public:
    storage_class();

    bool is_full();

    bool save(int n);

    int get_size();

};

#endif
