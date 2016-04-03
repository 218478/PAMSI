# Lab2 - tablica dynamiczna

Sposób pomiaru czasu nie jest właściwy.
``static_cast <double>(clock()) /CLOCKS_PER_SEC;``
Proszę korzystać z ``gettimeofday()`` http://linux.die.net/man/2/gettimeofday

Sprawozdanie w LaTeXu, bdb.

# Lab3 - projektowanie obiektowe

Sprawozdanie w LaTeXu, bdb.
Doxygen OK.
Bałagan w repozytorium.

# Lab4 - ADT, lista / kolejka / stos

Dlaczego wypełnianie listy ma złożoność O(n^2)? Jeżeli jest to linked-list, to
powinno być O(1), jeżeli lista zbudowana na tablicy, to wiemy już jak poradzić
sobie z tym problemem.

Dlaczego tylko trzy punkty pomiarowe? Miało być 10^{1,2,3,6,9}.

Dlaczego złożoność wyszukiwania O(log n)? Jak to się ma do oczekiwań teoretycznych?
Jakie wnioski z tej rozbieżności praktyki z teorią?
