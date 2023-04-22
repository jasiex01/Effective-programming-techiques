#include <iostream>
#include "lab_1.h"
#include "CTable.h"
/*
void v_alloc_table_add_5(int iSize)
{
	if (iSize > 0) {
		int* tab;
		tab = new int[iSize];

		for (int i = 0; i < iSize; i++)
			*(tab + i) = i + FIVE;

		for (int i = 0; i < iSize; i++)
			std::cout << tab[i] << std::endl;

		delete[] tab;
	}
	else
		std::cout << "niepoprawny rozmiar tablicy" << std::endl;

}
bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY)
{
	if (iSizeX <= 0 || iSizeY <= 0)
	{
		return false;
	}
	else
	{
		*piTable = new int*[iSizeX];

		for (int i = 0; i < iSizeX; i++)
			(*piTable)[i] = new int[iSizeY];

		//*(*piTable)[0] = 3;
		return true;
	}
}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY)
{
	if (iSizeX < 0) {
		for (int i = 0; i < iSizeX; i++)
			delete[] piTable[i];

		delete[] piTable;

		return true;
	}
	else
		return false;

}

void v_mod_tab(CTable *pcTab, int iNewSize) 
{
	std::cout << (*pcTab).bSetNewSize(iNewSize) << std::endl;
}
void v_mod_tab(CTable cTab, int iNewSize)
{
	std::cout << cTab.bSetNewSize(iNewSize) << std::endl;
}

int main()
{
	//zadanie 1
	v_alloc_table_add_5(5);

	//zadanie 2
	int **pi_table;
	std::cout << b_alloc_table_2_dim(&pi_table, 5, 3) << std::endl;
	//std::cout << *(pi_table[0]);

	//zadanie 3
	b_dealloc_table_2_dim(pi_table, 5, 3);
	//std::cout << pi_table[0][0];

	//zadanie 4
	CTable c_tab;
	CTable c_tab2("druga", 6);
	CTable c_tab3(c_tab2);
	CTable *pc_new_tab = c_tab.pcClone();
	CTable tab_c_tab[5];

	v_mod_tab(pc_new_tab, 2);
	v_mod_tab(tab_c_tab[2], 2);
	
	delete pc_new_tab;
}
*/