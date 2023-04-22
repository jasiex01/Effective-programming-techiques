#include <vector>
#include <iostream>

template <typename T> class CNodeDynamic {
public:
	CNodeDynamic() { i_val = NULL; pc_parent_node = NULL; }

	~CNodeDynamic() {
		for (int i = 0; i < v_children.size(); i++)
		{
			delete v_children.at(i);
		}
	}

	void vSetValue(T iNewVal);

	void vAddNewChild();
	CNodeDynamic<T>* pcGetChild(int iChildOffset);
	void vSetParent(CNodeDynamic<T>* pcNewParent);
	CNodeDynamic<T>* vGetParent() { return pc_parent_node; };
	int iGetChildrenNumber() { return v_children.size(); };
	std::vector<CNodeDynamic<T>*> *vGetChildren();

	void vPrint();
	void vPrintAllBelow();

private:
	std::vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;
};

template <typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
	i_val = iNewVal;
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
std::vector<CNodeDynamic<T>*>* CNodeDynamic<T>::vGetChildren() {
	return &v_children;
}

template <typename T>
void CNodeDynamic<T>::vSetParent(CNodeDynamic<T>* new_parent_node) {
	pc_parent_node = new_parent_node;
}

template <typename T>
void CNodeDynamic<T>::vPrint() {
	std::cout << " " << i_val << std::endl;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {

	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}


//CTreeDynamic

template <typename T>class CTreeDynamic{
public:
	CTreeDynamic() {pc_root = new CNodeDynamic<T>();}
	~CTreeDynamic() {
		pc_root->~CNodeDynamic<T>();
		delete pc_root;
	}

	CNodeDynamic<T>* pcGetRoot();

	void vPrintTree();

	bool bMoveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode);

private:
	CNodeDynamic<T>* pc_root;
};

template <typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {
	return pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
	if (pcParentNode == NULL || pcNewChildNode == NULL) {
		return false;
	}
	else if (pcNewChildNode->vGetParent() != NULL)
	{
		for (int i = 0; i < pcNewChildNode->vGetParent()->iGetChildrenNumber(); i++) {
			if (pcNewChildNode->vGetParent()->pcGetChild(i) == pcNewChildNode) {
				pcNewChildNode->vGetParent()->vGetChildren()->erase(pcNewChildNode->vGetParent()->vGetChildren()->begin() + i);
			}
		}
	}
	else {
		return false;
	}
	pcNewChildNode->vSetParent(pcParentNode);
	pcParentNode->vGetChildren()->push_back(pcNewChildNode);
	return true;
}

