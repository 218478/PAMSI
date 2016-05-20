#ifndef LISTA_H_
#define LISTA_H_
#include <functional>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
#include <iostream>

/*! \file Plik, na ktorym nauczlem sie obslugi nowych funkcji.
 *
 * \author Kamil Kuczaj
 *
 * \details Nowe funkcje to kolejka priorytetowa, lambdy i funkcjonaly.
 */

template<typename T> void print_queue(T& q) {
	while(!q.empty()) {
		std::cout << q.top() << " ";
		q.pop();
	}
	std::cout << '\n';
}

struct Node {
	int element, weight;
	Node() : element(0), weight(0){}
	Node(int e, int w = 1) : element(e), weight(w) {}
	bool operator == (Node second) {
		if (element == second.element && weight == second.weight)
			return true;
		else
			return false;
	}
};

class Lista {
private:


	std::list<Node> list_container;

public:
	/*! \brief Konstruktor bezparametryczny.
	*/
	Lista() {}

	/*! \brief Konstruktor paramatetrczyny.
	*
	* \details	Dodaje pierwszy wezel do listy. Potrzebne do implementacji kolejki
	*			priorytetowej.
	*/
	Lista(std::list<Node> l) : list_container(l) {}

	/*! \brief Konstruktor paramatetrczyny.
	*
	* \details	Dodaje pierwszy wezel do listy. Potrzebne do implementacji kolejki
	*			priorytetowej.
	*/
	Lista(int e, int w = 1) { list_container.push_back(Node(e,w)); }

	/*! \brief Konstruktor kopiujacy.
	*/
	Lista(const Lista& second) { list_container = second.list_container; }

	/*! \brief	Przeciazenie operatora porownania.
	*
	* \details	Potrzebne do implementacji kolejki priorytetowej.
	*/
	bool operator > (Lista& second) const {
		return (sum() > second.sum()) ? true : false;
	}

	/*! \brief	Przeciazenie operatora porownania.
	*
	* \details	Potrzebne do implementacji kolejki priorytetowej.
	*/
	bool operator < (Lista& second) const {
		return (sum() < second.sum()) ? true : false;
	}

	/*! \brief	Suma wag wszystkich elementow w liscie.
	*
	* \details	Zwraca sume wag wszystkich wezlow w liscie.
	*/
	int sum() const {
		int temp = 0;
		for (auto it = list_container.begin(); it != list_container.end(); it++)
			temp += it->weight;
		return temp;
	}

	/*! \brief	Dodaje element do kolejki.
	*
	* \param[in]	e	Nr wezla.
	* \param[in]	w	Waga.
	* \param[in]	pos	Pozycja, gdzie ma byc wstawiony wezel.
	*/
	void add(int e, int w, int pos) {
		auto it = list_container.begin();
		for (int i = 0; i < pos; i++)
			it++;
		list_container.insert(it, Node(e,w));
	}

	/*! \brief	Dodaje element na sam koniec listy.
	* \details	Wstawia element za wszystkie elementy.
	*/
	void push_back(int e, int w = 1) { list_container.push_back(Node(e,w)); }

	/*! \brief	Dodaje element na sam koniec listy.
	* \details	Wstawia element za wszystkie elementy.
	*/
	void push_back(Node temp) { list_container.push_back(temp); }

	/*! \brief	Zwraca indeks elementu w liscie.
	*
	* \details	Nie zawsze numer elementu jest taki sam jak indeks na liscie.
	*/
	int get(int pos) {
		auto it = list_container.begin();
		for (int i = 0; i < pos; i++)
			it++;
		return it->element;
	}

	/*! \brief	Zwraca wage elementu w liscie.
	*/
	int getWeight(int pos) {
		auto it = list_container.begin();
		for (int i = 0; i < pos; i++)
			it++;
		return it->weight;
	}

	/*! \brief Zwraca wierzcholki o najmniejszej wadze.
	*/
	Lista getMinWeight() {
		Lista temp(list_container.front().element, list_container.front().weight);
		int min_weight = list_container.front().weight;
		for (auto it = list_container.begin(); it != list_container.end(); it++) {
			if (it->weight < min_weight) {
				temp.clear();
				temp.push_back(it->element, it->weight);
			}
		}
		return temp;
	}

	/*! \brief	Nalezy to zmienic
	*
	* \details	Nalezy zmienic to, bo nie patrzy tutaj na wage. Ale do dzialania
	*			grafu jest wystarczajace, gdyz nie uzywamy tej funkcji. Dopero do
	*			brancha
	*/
	void remove(int e) { list_container.remove(Node(e)); }

	void clear() { list_container.clear(); }

	Node front() { return list_container.front(); }

	Node back() { return list_container.back(); }

	std::list<Node>::iterator begin() { return list_container.begin(); }

	std::list<Node>::iterator end() { return list_container.end(); }

	int size() { return list_container.size(); }

	void print() { std::cout << *this << std::endl; }

	int search(int searched_word) {
		if (list_container.empty())
			return -2;

		Node node(searched_word);
		auto temp = std::find(list_container.begin(), list_container.end(), node);
		if (temp == list_container.end())
			return -1;
		else
			return temp->element;
	}

	friend std::ostream& operator <<(std::ostream& str, const Lista& l);
};

// // List test: just compile this file with g++

// int main() {
// 	struct CompareLists {
// 		bool operator()(Lista& left, Lista& right) {
// 			return left > right;
// 		}
// 	};

// 	Lista temp;
// 	temp.push_back(12);
// 	temp.push_back(1);
// 	temp.push_back(2);

// 	temp.search(12);

// 	std::priority_queue< Lista, std::vector<Lista>, CompareLists > q;
// 	int index = 0;
// 	for(int n : {1,8,5,6,3,4,0,9,7,2})
// 		q.push( Lista(index++, n));

// 	print_queue(q);
// }

#endif  // LISTA_H_