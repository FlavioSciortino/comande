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
};
#endif


	

