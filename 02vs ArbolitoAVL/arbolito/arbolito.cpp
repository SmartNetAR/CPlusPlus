// arbolito.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Arbol.h"
#include <iostream>

int main()
{
	std::printf("arbol 'a' INT\n");
	Tree<int> a;
	a.Insert(2); a.Insert(3); a.Insert(5); a.Insert(1); a.Insert(6); a.Insert(11); a.Insert(4); a.Insert(12); a.Insert(10);
	a.travel();
	std::printf("\n");
	a.printBalance();

	std::printf("\narbol 'c' CHAR\n");
	Tree<char> c;
	c.Insert('j');
	c.Insert('h');
	c.Insert('a');
	c.Insert('r');
	c.Insert('b');
	c.Insert('z');
	c.travel(); std::cout << '\n';
	std::printf("borrar elemento 'b'\n");
	c.Delete('b');
	c.travel(); std::cout << '\n';
	
	std::printf("\narbol 'd' DOUBLE\n");
	Tree<double> d;
	d.Insert(10.0);
	d.Insert(5.0);
	d.Insert(15.20);
	d.Insert(15.25);
	d.Insert(15.2);
	d.Insert(13.1);
	d.travel();
	std::cout << '\n';

	std::printf("\narbol 'e' = 'a' INT\n");
	Tree<int> e = a;
	e.travel();
	std::cout << '\n';

	std::printf("\narbol 'f'('c') CHAR (copy constructor)\n");
	Tree<char> f(c);
	/*f.Insert('a');
	f.Insert('b');
	f.Insert('m');
	f.Insert('d');*/
	f.travel();
	std::printf ("\n");

	system("pause");
    return 0;
}

