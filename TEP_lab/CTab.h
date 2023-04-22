#pragma once
#define DEF_TAB_SIZE 10
class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(CTab &cOther);
	CTab(CTab &&cOther);
	CTab operator=(const CTab &cOther);
	~CTab();

	bool bSetSize(int iNewSize);
	int *iGetTab() { return (pi_tab); }
	int iGetSize() { return(i_size); }
private:
	void v_copy(const CTab &cOther);
	int *pi_tab;
	int i_size;
};