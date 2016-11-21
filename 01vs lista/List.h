#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Node.h"


//typedef int Type ;
enum VALUES { MAXITEMS= 20 , ZERO = -1};


template <class T>
struct nodo {
	T item;
	int next;
};

template <class T>
class List
{
public:
	List();
	~List();
	bool isEmpty();
	bool isFull();
	bool Insert(T item);
	bool Apend(T item);
	bool RemoveItem(T item);
	int PosOfItem(T item);
	int IndexOfItem(T item);
	T* First(void);
	T* Last(void);
	T* Next(void);
	bool isLast();
	void Print();

private:
    Node<T> *m_head;
	nodo<T> rep[ MAXITEMS ] ;
	int first;
	int last;
	int free;
	int current;
	int count;
	int nextFree;
};

//Definicion
template<class T>
List<T>::List()
{
	first = ZERO;
	last = ZERO;
	free = 0;
	current = ZERO;
	count = 0;
	nextFree = 0;
	for (int i = 0; i < MAXITEMS; i++) {
		rep[i].item = 0;
		rep[i].next = i+1;
	}
	rep[MAXITEMS-1].next = -1;
}

template<class T>
List<T>::~List()
{
	//delete rep;
}

template<class T>
bool List<T>::isEmpty() {
	return (first == ZERO);
}

template<class T>
bool List<T>::isLast() {
	return (current == last);
}

template<class T>
bool List<T>::isFull() {
	return (free == ZERO);
}

template<class T>
bool List<T>::Insert( T item ) {
	if (free != ZERO) { //SI NO ESTA LLENA
		nextFree = rep[free].next;
		rep[free].item = item;
		if (first == ZERO) { //SI ESTA VACIA
			last = free;
			rep[free].next = -1;
		}
		else { //SI NO ESTA VACIA
			rep[free].next = first;
		}
		first = free;
		free = nextFree;
		count++;
	}
	return true;
}

template<class T>
bool List<T>::Apend(T item) {
	if (free != ZERO) { //SI NO ESTA LLENA
		nextFree = rep[free].next;
		rep[free].item = item;
		if (first == ZERO) { //SI ESTA VACIA
			first = free; last = free;
			rep[free].next = ZERO;
		}
		else {
			rep[last].next = free;
			last = free;
			rep[last].next = ZERO;

		}
		free = nextFree;
		count++;
	}
	return true;
}

template<class T>
T* List<T>::First(void) {
	T* firstItem = nullptr;
	if (count != 0) {
		firstItem = &(rep[first].item);
		current = first;
	}
	return firstItem;
}

template<class T>
T* List<T>::Last(void) {
	T* lastItem = nullptr;
	if (count != 0) {
		lastItem = &(rep[last].item);
		current = last;
	}
	return lastItem;
}

template<class T>
T* List<T>::Next(void) {
	T* nextItem = nullptr;
	if (current != ZERO) {
		current = rep[current].next;
		if (current != ZERO) {
			nextItem = &(rep[current].item);
		}
		else {
			nextItem = nullptr;
		}
	}
	return nextItem;
}

template<class T>
void List<T>::Print() {
	int i=0;
	while (i < count) {
		//std::cout << rep[i].item << ',' << rep[i].next << std::endl;
		i++;
	}
}

template<class T>
bool List<T>::RemoveItem(T item) {
	bool result = false;
	if (count != 0) {
		int current = first;
		int previous = ZERO;
		while (current != ZERO && rep[current].item != item) {
			previous = current;
			current = rep[current].next;
		}
		if (current != ZERO) {
			if (previous == ZERO) {
				first = rep[current].next;
			}
			else {
				rep[previous].next = rep[current].next;
				if (rep[current].next == ZERO) {
					last = previous;
				}
			}
			rep[current].next = free;
			free = current;
			count--;
			result = true;
		}
	}
	return result;
}

template<class T>
int List<T>::PosOfItem(T item) {
	int pos = 0;
	int current = first;
	while (current != ZERO && rep[current].item != item) {
		current = rep[current].next;
		pos++;
	}
	if (current == ZERO) pos = -1;
	return pos;
}

template<class T>
int List<T>::IndexOfItem(T item) {
	int pos = 0;
	while (pos < count && rep[pos].item != item) {
		pos++;
	}
	if (pos == count ) pos = -1;
	return pos;
}

#endif // LIST_H_INCLUDED
