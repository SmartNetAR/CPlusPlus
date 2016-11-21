#include <iostream>
#include "List.h"

using namespace std;

void MostrarElementos(List<char> list) {
	cout << "el primer item es = " << *list.First() << endl;
	while (!list.isLast()) {
		cout << "el siguiente item es = " << *list.Next() << endl;
	}
	cout << "el ultimo item es = " << *list.Last();
}

int main()
{
	List<char> x;
	cout << ( x.isEmpty() ? "vacia" : "no vacia") << endl;

	x.Apend('a'); cout << "Apend a" << endl;
	x.Apend('b'); cout << "Apend b" << endl;
	x.Apend('c'); cout << "Apend c" << endl;
	x.Apend('d'); cout << "Apend d" << endl;
	x.Apend('e'); cout << "Apend e" << endl;

	cout << "elimino el item c" << endl;
	x.RemoveItem('c');

	/*
	x.Insert(4);
	x.Insert(2);
	x.Insert(6);
	x.Insert(2);
	x.Insert(7);
	*/
	//x.Print();

	//cout << "el siguiente item es = " << *x.Next() << endl;
	cout << (x.isEmpty() ? "vacia" : "no vacia") << endl;
	cout << "posicion logica del item b= " << x.PosOfItem('b') << endl;
	cout << "posicion fisica del item b= " << x.IndexOfItem('b') << endl;

	MostrarElementos(x);
    return 0;
}
