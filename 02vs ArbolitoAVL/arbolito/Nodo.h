#pragma once

template<class T>
class Node {
private:
public:
	T data;
	Node* lson; //hijo izquierdo
	Node* rson; //hijo derecho
	int freq; //frecuencia de repetidos
	int hgt; //la raiz de la altura del nodo del árbol

	Node() :lson(NULL), rson(NULL), freq(1), hgt(0) {}
	/*T Data() {return data}
	int Freq() {return freq}
	int Hgt() {return hgt}
	Node* LSon() {return lson}
	Node* RSon() {return rson}
	*/
};