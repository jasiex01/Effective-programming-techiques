#ifndef CNodeStat
#define CNodeStat
#include <iostream>
#include <vector>

const int DEFAULT_VALUE = 0;

class CNodeStatic{
private:
	std::vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;

public:
	CNodeStatic() { i_val = 0; pc_parent_node = NULL; };

	~CNodeStatic() {};

	void vSetValue(int iNewVal) { i_val = iNewVal; };
	void vSetParent(CNodeStatic *new_parent_node) { pc_parent_node = new_parent_node; };

	CNodeStatic* vGetParent() { return pc_parent_node; };

	int iGetChildrenNumber() { return(v_children.size()); };

	void vAddNewChild();

	void vAddNewChild(CNodeStatic node);

	CNodeStatic *pcGetChild(int iChildOffset);

	void vPrint() { std::cout << " " << i_val; };

	void vPrintAllBelow();

	void vPrintUp();

	void removeChild(CNodeStatic* Child);


};

#endif CNodeStat
