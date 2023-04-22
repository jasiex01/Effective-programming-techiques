#ifndef CTabl
#define CTabl
#include <string>

const std::string DEFAULT_NAME = "tablica";
const int DEFAULT_SIZE = 4;

const std::string BEZP = "bezp: ";
const std::string PARAM = "parametr: ";
const std::string COPY = "_copy";
const std::string CLONED = "kopiuj: ";
const std::string DELETING = "usuwam: ";

class CTable {

private:
	std::string s_name;
	int size;
	int* tab;

public:

	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable &pcOther);

	//~CTable();

	bool bSetNewSize(int iTableLen);
	void operator= (CTable &pcOther);
	void operator+ (CTable &pcOther);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	int getSize();

	CTable* pcClone();


};

#endif CTabl




