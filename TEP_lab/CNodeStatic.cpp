#include <iostream>
#include "CNodeStatic.h"

void CNodeStatic::vAddNewChild() {
	CNodeStatic node;
	node.vSetParent(this);
	v_children.push_back(node);
}

void CNodeStatic::vAddNewChild(CNodeStatic node) {
	node.vSetParent(this);
	v_children.push_back(node);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < v_children.size())
		return &v_children[iChildOffset];
	else
		return NULL;
}

void CNodeStatic::vPrintAllBelow() {

	vPrint();
	if (iGetChildrenNumber() > 0) {
		for (int i = 0; i < iGetChildrenNumber(); i++) {
			v_children[i].vPrintAllBelow();
		}
	}
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		CNodeStatic node = *pc_parent_node;

		while (node.pc_parent_node != NULL) {
			node.vPrint();
			node = *node.pc_parent_node;
		}
		node.vPrint();
	}
}

void CNodeStatic::removeChild(CNodeStatic* child)
{
	int k = -1;
	bool b = false;
	for (int i = 0; i < v_children.size(); i++)
		if (child == &v_children[i])
			k = i;
	if (k != -1)
		v_children.erase(v_children.begin() + k);
}

	