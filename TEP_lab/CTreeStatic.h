#ifndef CTreeStat
#define CTreeStat
#include <iostream>
#include "CNodeStatic.h"
class CTreeStatic{
private:
	CNodeStatic c_root;
public:
	CTreeStatic();

	CTreeStatic(CNodeStatic root);

	~CTreeStatic() {};

	CNodeStatic *pcGetRoot() { return(&c_root); }

	void vPrintTree();
	
	bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
};

#endif CTreeStat