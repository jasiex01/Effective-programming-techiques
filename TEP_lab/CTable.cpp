#include <iostream>
#include "CTable.h"

CTable::CTable() {

	s_name = DEFAULT_NAME;
	size = DEFAULT_SIZE;
	tab = new int[size];

	std::cout << BEZP << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
	if (iTableLen > 0) {

		this->s_name = sName;
		this->size = iTableLen;
		tab = new int[iTableLen];

		std::cout << PARAM << s_name << std::endl;
	}
}

CTable::CTable(CTable &pcOther) {

	s_name = pcOther.s_name + COPY;
	size = pcOther.size;
	tab = new int[size];

	for (int i = 0; i < size; i++) {
		tab[i] = pcOther.tab[i];
	}

	std::cout << CLONED << s_name << std::endl;
}
/*
CTable::~CTable() {
	std::cout << DELETING << s_name << std::endl;
	delete[] tab;
}
*/

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen > 0) {
		delete[] tab;
		size = iTableLen;
		tab = new int[iTableLen];
		return true;
	}
	else
		return false;
}

void CTable::operator=(CTable &pcOther)
{
	//ten kod nie zwalnia pamieci tab
	tab = pcOther.tab;
	size = pcOther.size;
}

void CTable::operator+(CTable &pcOther)
{
	int* pom;
	pom = new int[size + pcOther.size];
	for (int i = 0; i < size; i++) {
		pom[i] = tab[i];
	}
	for (int i = 0; i < pcOther.size; i++) {
		pom[i+size] = tab[i];
	}
	size += pcOther.size;
	delete[] tab;
	tab = pom;
}

void CTable::vSetValueAt(int iOffset, int iNewVal) {
	tab[iOffset] = iNewVal;
}

void CTable::vPrint() {
	for (int i = 0; i < size; i++) {
		std::cout << tab[i] << std::endl;
	}
}

int CTable::getSize() {
	return size;
}

CTable* CTable::pcClone() {

	CTable* clonedTable = new CTable(*this);
	return clonedTable;
}