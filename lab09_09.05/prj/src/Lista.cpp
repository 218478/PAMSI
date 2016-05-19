// Copyright 2016 Kamil Kuczaj
#include "Lista.h"


std::ostream& operator << (std::ostream& str, const Lista& l){
    for (auto it = l.list_container.begin(); it != l.list_container.end(); it++)
        str << it->element << " (" << it->weight << ") ";
    return str;
}
