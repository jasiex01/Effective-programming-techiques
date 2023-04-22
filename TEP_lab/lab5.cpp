//uzyc cCreate tab do testu zad 4
#include <iostream>
#include "CTab.h"
#include "CMySmartPointer.h"
#include <string>

CTab cCreateTab()
{
	CTab c_result;
	c_result.bSetSize(5);
	return(std::move(c_result));
}

int main() {


	CMySmartPointer<int> smart_ptr1(new int(20));
	std::cout<< "Wartosc pamieci, na ktora wskazuje smart_ptr1: " << *smart_ptr1 << std::endl;

	CMySmartPointer<int> smart_ptr2(smart_ptr1);
	std::cout << "Wartosc pamieci, na ktora wskazuje smart_ptr2: " << *smart_ptr2 << std::endl;

	{
		CMySmartPointer<int> smart_ptr3(smart_ptr1);
		std::cout << "Wartosc pamieci, na ktora wskazuje smart_ptr3: " << *smart_ptr2 << std::endl;
	}
	std::cout << "Wartosc pamieci, na ktora wskazuje smart_ptr1 po usunieciu smart_ptr3: " << *smart_ptr1 << std::endl;

	CMySmartPointer<int> smart_ptr3(new int(30));
	smart_ptr2 = smart_ptr3;

	std::cout << "Wartosc pamieci, na ktora wskazuje smart_ptr2: " << *smart_ptr2 << std::endl;
	std::cout << "Wartosc pamieci, na ktora wskazuje smart_ptr1: " << *smart_ptr1 << std::endl;
	
	CTab c_tab = cCreateTab();
	std::cout << "Rozmiar Tab 1: " << c_tab.iGetSize() << std::endl;
	CTab c_tab_copy(c_tab);

	std::cout << "Tab 1: " << std::endl;
	for (int i = 0; i < c_tab.iGetSize(); i++)
	{
		c_tab.iGetTab()[i] = i + 1;
		std::cout << c_tab.iGetTab()[i] << *smart_ptr1 << std::endl;
	}
	std::cout << "Tab 2: " << std::endl;
	for (int i = 0; i < c_tab_copy.iGetSize(); i++)
	{
		c_tab.iGetTab()[i] = i + 10;
		std::cout << c_tab_copy.iGetTab()[i] << *smart_ptr1 << std::endl;
	}
	c_tab_copy = c_tab;
	std::cout << "Tab 2 po operatorze = z Tab 1 : " << std::endl;
	for (int i = 0; i < c_tab_copy.iGetSize(); i++)
	{
		std::cout << c_tab_copy.iGetTab()[i] << *smart_ptr1 << std::endl;
	}
	return 0;
}