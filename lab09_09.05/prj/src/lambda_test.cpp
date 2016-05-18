#include <functional>
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


class Lista {
private:
  int element;

public:
	Lista(int x) : element(x) {}
	bool operator > (Lista& second) {
		return (element > second.element) ? true : false;
	}

	bool operator < (Lista& second) {
		return (element < second.element) ? true : false;
	}

	int sum() const {
		return element;
	}


	friend std::ostream& operator <<(std::ostream& str, const Lista& l);
};
 
std::ostream& operator << (std::ostream& str, const Lista& l) {
		return str << l.sum();
	}


//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

struct Node {
	int element, weight;
	Node() : element(0), weight(0){}
	Node(int e, int w = 1) : element(e), weight(w) {}
};

class Lista2 {
private:


	std::list<Node> list_container;

public:
	Lista2() {}

	Lista2(std::list<Node> l) : list_container(l) {}

	Lista2(int e, int w = 1) { list_container.push_back(Node(e,w)); }

	bool operator > (Lista2& second) const {
		return (sum() > second.sum()) ? true : false;
	}

	bool operator < (Lista2& second) const {
		return (sum() < second.sum()) ? true : false;
	}

	int sum() const {
		int temp = 0;
		for (auto it = list_container.begin(); it != list_container.end(); it++)
			temp += it->weight;
		return temp;
	}

	void push_back(int e, int w = 1) { list_container.push_back(Node(e,w)); }

	Node front() const { return list_container.front(); }

	Node back() const { return list_container.back(); }

	std::list<Node>::iterator begin() { return list_container.begin(); }

	std::list<Node>::iterator end() { return list_container.end(); }

	friend std::ostream& operator <<(std::ostream& str, const Lista2& l);
};

	std::ostream& operator << (std::ostream& str, const Lista2& l){
		for (auto it = l.list_container.begin(); it != l.list_container.end(); it++)
			str << it->element << " (" << it->weight << ") ";
		return str;
	}


int main() {
	struct CompareLists {
		bool operator()(Lista2& left, Lista2& right) {
			return left > right;
		}
	};

	std::priority_queue< Lista2, std::vector<Lista2>, CompareLists > q;
	int index = 0;
	for(int n : {1,8,5,6,3,4,0,9,7,2})
		q.push( Lista2(index++, n));

	print_queue(q);
}
