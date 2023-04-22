/*
#include <iostream>
#include "CTable.h"

int main() 
{
	//1
	/*CTable c_tab_0, c_tab_1;

	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1; */

	//bedzie wyjatek i program przerwie wykonywanie poniewaz destruktory beda chcialy zdealokowac tablice a jedna tablica jest przypisana do 2 obiektow wiec bedzie probowac dealokowac juz zdealokowana pamiec

	//2 po usunieciu destruktora program sie skompiluje i wykona poniewaz nie ma destruktora i blad nie wystepuje

	//3
/*
	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	
	for (int i = 0; i < c_tab_0.getSize(); i++) {
		c_tab_0.vSetValueAt(i, i + 1);
	}
	for (int i = 0; i < c_tab_1.getSize(); i++) {
		c_tab_1.vSetValueAt(i, i + 51);
	}

	c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrint();
	std::cout << std::endl;
	c_tab_1.vPrint();

	//4
	c_tab_0 + c_tab_1;
	std::cout << std::endl;
	c_tab_0.vPrint();
}
*/