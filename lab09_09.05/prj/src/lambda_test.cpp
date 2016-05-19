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
	Lista() {}

	Lista(std::list<Node> l) : list_container(l) {}

	Lista(int e, int w = 1) { list_container.push_back(Node(e,w)); }

	bool operator > (Lista& second) const {
		return (sum() > second.sum()) ? true : false;
	}

	bool operator < (Lista& second) const {
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

	int size() { return list_container.size(); }

	void print() { std::cout << *this << std::endl; }

	int search(int searched_word) {
		if (list_container.empty())
			return -2;

		Node node(searched_word);
		std::cout << node.element << "\t" << node.weight << std::endl;
		auto temp = std::find(list_container.begin(), list_container.end(), node);
		if (temp == list_container.end())
			return -1;
		else
			return temp->element;
	}

	friend std::ostream& operator <<(std::ostream& str, const Lista& l);
};

	std::ostream& operator << (std::ostream& str, const Lista& l){
		for (auto it = l.list_container.begin(); it != l.list_container.end(); it++)
			str << it->element << " (" << it->weight << ") ";
		return str;
	}

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
