#include <iostream>
#include "CTab.h"

CTab::CTab(CTab &cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}

CTab::CTab(CTab &&cOther)
{
	*this = std::move(cOther);
	
	std::cout << "MOVE ";
}
CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}
CTab CTab::operator=(const CTab &cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}

void CTab::v_copy(const CTab &cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}

bool CTab::bSetSize(int iNewSize)
{
	if (i_size < 0)
	{
		return false;
	}

	int* new_tab = new int[i_size];

	std::memcpy(new_tab, pi_tab, i_size * sizeof(int));

	delete[] pi_tab;
	pi_tab = new_tab;
	i_size = i_size;

	return true;
}