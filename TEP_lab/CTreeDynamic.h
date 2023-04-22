#ifndef CTreeDyn
#define CTreeDyn
#include <iostream>
#include "CNodeDynamic.h"

template <typename T> class CTreeDynamic{
private:
	CNodeDynamic<T> *pc_root;
public:
	CTreeDynamic();

	~CTreeDynamic();

	CNodeDynamic<T> *pcGetRoot() { return(pc_root); }

	void vPrintTree();

	bool bMoveSubtree(CNodeDynamic<T>* parentNode, CNodeDynamic<T>* newChildNode);
};

#endif CTreeDyn
