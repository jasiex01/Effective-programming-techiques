#include <iostream>
#include "CNodeDynamic.h"


template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children[i];
	}
}


template <typename T>
void CNodeDynamic<T>::vAddNewChild() {

	v_children.push_back(new CNodeDynamic());
	v_children[v_children.size() - 1]->vSetParent(this);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset < v_children.size())
		return v_children[iChildOffset];
	else
		return NULL;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {

	vPrint();
	if (iGetChildrenNumber() > 0) {
		for (int i = 0; i < iGetChildrenNumber(); i++) {
			v_children[i]->vPrintAllBelow();
		}
	}
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic* child)
{
	child->vSetParent(this);
	v_children.push_back(child);
}

template <typename T>
void CNodeDynamic<T>::removeChild(CNodeDynamic* child)
{
	int k = -1;
	for (int i = 0; i < v_children.size(); i++)
		if (child == v_children[i])
			k = i;
	if (k != -1)
		v_children.erase(v_children.begin() + k);
}