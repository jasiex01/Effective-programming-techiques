#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

template <typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	pc_root->~CNodeDynamic();
	delete pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
	pcGetRoot()->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode)
{
	if (parentNode == NULL || newChildNode == NULL || newChildNode->vGetParent() == NULL)
		return false;

	newChildNode->vGetParent()->removeChild(newChildNode);
	parentNode->vAddNewChild(newChildNode);

	return true;
}