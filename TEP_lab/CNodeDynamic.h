#ifndef CNodeDyn
#define CNodeDyn
#include <iostream>
#include <vector>

template <typename T> class CNodeDynamic
{
private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic *pc_parent_node;
	T i_val;

public:
	CNodeDynamic() { pc_parent_node = NULL; };

	~CNodeDynamic();

	void vSetValue(T iNewVal) { i_val = iNewVal; };
	void vSetParent(CNodeDynamic *new_parent_node) { pc_parent_node = new_parent_node; };
	CNodeDynamic* vGetParent() { return pc_parent_node; };
	void removeChild(CNodeDynamic* child);

	int iGetChildrenNumber() { return v_children.size(); };

	void vAddNewChild();
	void vAddNewChild(CNodeDynamic* newChild);

	CNodeDynamic *pcGetChild(int iChildOffset);

	void vPrint() { std::cout << " " << i_val; };

	void vPrintAllBelow();

};
#endif CNodeDyn