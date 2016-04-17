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

# Lab5 - sortowanie

# Lab6 - tablica asocjacyjna

W sprawozdaniu brakuje omówienia kwestii powiększania tablicy dynamicznej, które
jest niezbędne, aby faktycznie osiągnąć złożoność O(1). Współczynnik wypełnienia
musi być utrzymywany na odpowiednim poziomie. Po zmianie rozmiaru tablicy konieczne
jest wykonanie tzw. "rehashowania", czyli przeorganizowania całej tablicy, co wiążę
się z pewnym kosztem, który jednak "amortyzuje się" podobnie jak operacje wykonywane
przy powiększaniu tablicy dynamicznej (przy odpowedniej strategii tego powiększania).

Załączone do sprawozdania tabele są dla mnie niezrozumiałe - brak opisów kolumn.

Wniosek niepoprawny lub nieprecyzyjny - funkcja skrótu

```
unsigned int HashTable::hashFunction(const std::string& key)
```

nie może wpływać na zmianę złożoności z O(1) na O(log n) - sama nie zależy w
żaden sposób od n, a jedynie od długości klucza k.
Problem wynika najprawdopodobniej z nieuwzględnienia współczynnika wypełnienia.

Ocena: 4
