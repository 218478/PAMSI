#include "../inc/storage_class.h"

using namespace std;

storage_class::storage_class() {
    elements = new int[10];
}

int storage_class::get_size() {
    return sizeof(elements)/sizeof(int);
}

bool storage_class::save(int n) {

}

bool storage_class::is_full() {


    return false;
}
