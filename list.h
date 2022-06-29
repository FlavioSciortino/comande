#include "comande.h"
#ifndef LIST_H
#define LIST_H
template<typename T>
class nodo {
	T val;
	nodo<T> * next;
	template<typename U>
	friend class list;
public:
	nodo(T val) : val(val) {next = nullptr; }
	nodo<T> * getNext() {return this->next; }
	friend ostream &operator<<(ostream &os, nodo<T> & n) {
		return os << n.val << endl;
	}
};

template<typename T>
class list {
	nodo<T> * head;
public:
	list() {head = nullptr; }
	bool isEmpty() {return head == nullptr; }
	void insert(T val) {
		if(isEmpty()) {
			head = new nodo<T>(val);
		}
	}

	void insertHead(T val) {
		if(isEmpty())
			insert(val);
		nodo<T> * toInsert = new nodo<T> (val);
		toInsert->next = head;
		head = toInsert;
		return;
	}

	void insertTail(T val) {
		if(isEmpty())
			insertHead(val);

		nodo<T> * ptr = head;
		while(ptr) {
			ptr = ptr->next;
		}
		nodo<T> * toInsert = new nodo<T>(val);
		ptr->next = toInsert;
		return;
	}

	void removeHead() {
		if(isEmpty())
			return;
		nodo<T> * tmp = head;
		head = head->next;
		delete tmp;
		return;
	}

	void removeTail() {
		if(isEmpty())
			return;
		nodo<T> * cur = head;
		nodo<T> * prev = nullptr;
		while(cur->next) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = nullptr;
		delete cur;
		return;
	}

	void removeElement(T val) {
		if(isEmpty())
			return;
		nodo<T> * cur = head;
		nodo<T> * prev = nullptr;
		while(cur->next && cur->val != val) {
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		return;
	}

	list create(list &l) {
		ifstream fin("comande.txt");
		while(fin.good()) {
			comande c;
			fin>>c;
			l.insertHead(c);

		}
		return l;
	}

	friend ostream &operator<<(ostream &os, list<T> & l) {
		if(l.isEmpty())
			return os << "empty " << endl;
		nodo<T> * ptr = l.head;
		while(ptr) {
			os << *ptr << endl;
			ptr = ptr->getNext();
		}
		return os;
	}
};
#endif


	

