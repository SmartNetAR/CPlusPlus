#pragma once
#include "Nodo.h"
#include <iostream>

template<class T>
class Tree
{
public:
	Tree() :root(NULL) {}
	Tree(const Tree& tree);
	Tree<T>& operator= (const Tree<T>& rhs);
	~Tree() ;
	void Insert(T data);
	Node<T>* find(T x);
	void travel();			//Recorre
	void makeEmpty();		//Vaciar Arbol
	void Delete(T x);		//Borrar elemento 
	Node<T>* getRoot();
	void printBalance();
private:
	Node<T>* root; //raiz
	void copyNodes(Node<T> * t, Node<T> * r);
	void makeEmpty(Node<T>* & t);
	void InsertPri(Node<T>* &node, T data); 
	int height(Node<T>* node);					//Devulve la altura del �rbol 
	int Max(int cmpa, int cmpb);				//M�ximo 
	void SingRotateLeft(Node<T>* &k2);			//rotaci�n a la izquierda 
	void SingRotateRight(Node<T>* &k2);			//rotaci�n a la derecha
	void DoubleRotateLeftRight(Node<T>* &k3);	//rotar alrededor de casos
	void DoubleRotateRightLeft(Node<T>* &k3);	//doble rotaci�n derecha e izquierda
	Node<T>* findpri(Node<T>* node, T x);		//Buscar 
	void insubtree(Node<T>* node);				//Recorrido en �rden
	void Deletepri(Node<T>* &node, T x);	//Borrar
	void printBalance(Node<T> *n);
};

template<class T>
Tree<T>::Tree(const Tree<T>& rhs) : root() {
	//copy constructor
	copyNodes(rhs.root, root);
}

template<class T>
Tree<T>::~Tree() {
	makeEmpty(root);
	delete root;
};

template<class T>
void Tree<T>::copyNodes(Node<T>* t, Node<T>* r) {
	if (t != NULL) 	{
		copyNodes(t->lson, r);
		copyNodes(t->rson, r);
		InsertPri(r , t->data);
		//std::cout << t->data << r->data << std::endl; //these always print as the same 
	}
}

template<class T>
void Tree<T>::makeEmpty() {
	makeEmpty(root);
}

template<class T>
void Tree<T>::makeEmpty(Node<T>* & t) {
	if (t != NULL) {
		makeEmpty(t->lson);
		makeEmpty(t->rson);
	}
	delete t;
	t = NULL;
}

template<class T>
Tree<T>& Tree<T>::operator= (const Tree<T>& rhs) {
	makeEmpty(root);
	copyNodes(rhs.root, root);
	return this;
}


//Para calcular la altura para el nodo ra�z de �rbol 
template<class T>
int Tree<T>::height(Node<T>* node)
{
	if (node != NULL)
		return node->hgt;
	return -1;
}

//M�ximo 
template<class T>
int Tree<T>::Max(int cmpa, int cmpb) {
	return cmpa>cmpb ? cmpa : cmpb;
}

//En el caso de la rotaci�n de la izquierda 
template<class T>
void Tree<T>::SingRotateLeft(Node<T>* &k2) {
	Node<T>* k1;
	k1 = k2->lson;
	k2->lson = k1->rson;
	k1->rson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->lson), k2->hgt) + 1;
}

//En el caso de la rotaci�n de la derecha 
template<class T>
void Tree<T>::SingRotateRight(Node<T>* &k2){
	Node<T>* k1;
	k1 = k2->rson;
	k2->rson = k1->lson;
	k1->lson = k2;

	k2->hgt = Max(height(k2->lson), height(k2->rson)) + 1;
	k1->hgt = Max(height(k1->rson), k2->hgt) + 1;
}

//Rotar alrededor de la situaci�n 
template<class T>
void Tree<T>::DoubleRotateLeftRight(Node<T>* &k3)
{
	SingRotateRight(k3->lson);
	SingRotateLeft(k3);
}
//La rotaci�n de la izquierda a la derecha 
template<class T>
void Tree<T>::DoubleRotateRightLeft(Node<T>* &k3)
{
	SingRotateLeft(k3->rson);
	SingRotateRight(k3);
}

template<class T>
void Tree<T>::InsertPri(Node<T>* &node, T data) {
	if (node == NULL) {//Si los nodos est�n vac�os
		node = new Node<T>();
		node->data = data;
		return;
	}
	if (node->data > data) { //Si data es inferior al valor del nodo, sigue en la rama izquierda
		//recursivo vuelvo a insertar con el hijo izquierdo
		InsertPri(node->lson, data);
		if (height(node->lson) - height(node->rson) == 2) {  //si la diferencia entre altura del hijo izquierdo es 2
			if (node->lson->data > data)
				SingRotateLeft(node);
			else
				DoubleRotateLeftRight(node);
		}
	}else if (node->data < data) { //Si data es mayor que el valor del nodo, sigue a la rama derecha
		InsertPri(node->rson, data);
		if (height(node->rson) - height(node->lson) == 2) { //si la diferencia de altura del hijo derecho es 2
			if (node->rson->data < data)
				SingRotateRight(node);
			else
				DoubleRotateRightLeft(node);
		}
	}
	else ++(node->freq);	//Si es el mismo valor aumento la frecuqncia
	node->hgt = Max(height(node->lson), height(node->rson));
}

template<class T>			//funci�n miembro insert
void Tree<T>::Insert(T data) {
	InsertPri(root, data);
}


//Buscar 
template<class T>
Node<T>* Tree<T>::findpri(Node<T>* node, T x)
{
	if (node == NULL)//Si los nodos vac�o que no encontrar, devuelve null 
	{
		return NULL;
	}
	if (node->data>x)//Si X es inferior al valor del nodo, continuar la b�squeda de X en el �rbol de la izquierda del nodo 
	{
		return findpri(node->lson, x);
	}
	else if (node->data<x)//Si X es mayor que el valor del nodo, continuar la b�squeda de X en el �rbol de la izquierda del nodo 
	{
		return findpri(node->rson, x);
	}
	else return node;//Si son iguales, de encontrar este nodo 
}
//Interfaz de b�squeda 
template<class T>
Node<T>* Tree<T>::find(T x)
{
	return findpri(root, x);
}

//En funci�n de la reserva 
template<class T>
void Tree<T>::insubtree(Node<T>* node)
{
	if (node == NULL) return;
	insubtree(node->lson);//Antes de atravesar la izquierda sub�rbol 
	std::cout << node->data << " ";//El nodo ra�z de salida 
	insubtree(node->rson);//A trav�s de la derecha sub�rbol 
}

template<class T>
void Tree<T>::travel()
{
	insubtree(root);
}



//Borrar 
template<class T>
void Tree<T>::Deletepri(Node<T>* &node, T x)
{
	if (node == NULL) return;//No es encontrar el valor X de los nodos 
	if (x <node->data)
	{
		Deletepri(node->lson, x);//Si X es inferior al valor del nodo, sigue en el �rbol de la izquierda elimina el nodo X 
		if (2 == height(node->rson) - height(node->lson))
			if (node->rson->lson != NULL && (height(node->rson->lson)>height(node->rson->rson)))
				DoubleRotateRightLeft(node);
			else
				SingRotateRight(node);
	}

	else if (x > node->data)
	{
		Deletepri(node->rson, x);//Si X es mayor que el valor del nodo, sigue en el nodo eliminar X sub�rbol 
		if (2 == height(node->lson) - height(node->rson))
			if (node->lson->rson != NULL && (height(node->lson->rson)>height(node->lson->lson)))
				DoubleRotateLeftRight(node);
			else
				SingRotateLeft(node);
	}

	else//Si son iguales, el nodo es eliminar nodo 
	{
		if (node->lson&&node->rson)//El nodo tiene dos hijos 
		{
			Node<T>* temp = node->rson;//Nodos hijo temp hacia la derecha 
			while (temp->lson != NULL) temp = temp->lson;//Encontrar un m�nimo de nodos sub�rbol mediana 
														 //A la derecha en el valor m�nimo de nodos sub�rbol de asignar a este nodo 
			node->data = temp->data;
			node->freq = temp->freq;
			Deletepri(node->rson, temp->data);//Eliminar nodos en el valor m�nimo de la derecha sub�rbol 
			if (2 == height(node->lson) - height(node->rson))
			{
				if (node->lson->rson != NULL && (height(node->lson->rson)>height(node->lson->lson)))
					DoubleRotateLeftRight(node);
				else
					SingRotateLeft(node);
			}
		}
		else//El nodo tiene un hijo o 1 0 
		{
			Node<T>* temp = node;
			if (node->lson == NULL)//Hijo o no, el hijo de la derecha 
				node = node->rson;
			else if (node->rson == NULL)//A la izquierda, hijo 
				node = node->lson;
			delete(temp);
			temp = NULL;
		}
	}
	if (node == NULL) return;
	node->hgt = Max(height(node->lson), height(node->rson)) + 1;
	return;
}
//Borrar de la interfaz 
template<class T>
void Tree<T>::Delete(T x)
{
	Deletepri(root, x);
}

template <class T>
Node<T>* Tree<T>::getRoot() {
	return root;
}

template <class T>
void Tree<T>::printBalance() {
	printBalance(root);
	std::cout << std::endl;
}

template <class T>
void Tree<T>::printBalance(Node<T> *n) {
	if (n != NULL) {
		printBalance(n->lson);
		std::cout << n->hgt << " ";
		printBalance(n->rson);
	}
}