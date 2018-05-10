#include <iostream>
#include "wyrazenie_arytmetyczne.hpp"

using namespace std;
using namespace wyrazenie_arytmetyczne ;


int main()
{

	wyrazenie *w = new odejmij(new pi(), new dodaj(new liczba(2), new mnoz(new zmienna("x"), new liczba(7)
	)
	)
	);
	for (double i = 1; i <= 10; i++)
	{
		zmienna::ustaw("x", i);
		cout << w->opis() << " = " << w->oblicz() << endl;
	}
	system("pause");
	return 0;





}
