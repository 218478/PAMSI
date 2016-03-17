#include "Tablica.h"


// Zdecydowalem sie na uzycie szablonow, dlatego musialem pozbyc sie definicji
// metod w pliku zrodlowym i przeniesc je do naglowkowego.

// template <class Type>
// Tablica<Type>::Tablica(uint x) { elements=new int[x]; current_size=x; index=0; }

// template <class Type>
// Tablica<Type>::~Tablica() { delete [] elements; }

// template <class Type>
// void Tablica<Type>::prepare (uint size) { desired_size = size; }

// template <class Type>
// void Tablica<Type>::run() {
//   while(index < desired_size) {
//     if(isFull())
//       increaseSize();

//     elements[index++] = 123;
//   }
// }

// template <class Type>
// bool Tablica<Type>::isFull() { return ((index >= (current_size)) ?true:false); }

// template <class Type>
// uint Tablica<Type>::getSize() { return current_size; }

// template <class Type>
// void Tablica<Type>::increaseSize() {
//   uint new_size = current_size * 2;
//   try {
//     int *new_elements = new int[new_size];
//     for(uint i=0; i < current_size; i++)
//       new_elements[i] = elements[i];

//     delete [] elements;
//     current_size = new_size;
//     elements = new_elements;
//   }
//   // if you fail to allocate memory
//   catch (std::bad_alloc& ex) {
//     std::cerr << ex.what() << std::endl;
//   }

// }

 
