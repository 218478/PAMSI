// Copyright 2016 Kamil Kuczaj
#include "Lista.h"


Lista::Lista() {
  head = new Node;  // alokacja pamieci
}

Lista::~Lista() {
  delete head;  // usuwanie pamieci
}




