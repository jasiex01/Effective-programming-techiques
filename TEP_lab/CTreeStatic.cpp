#include "CTreeStatic.h"
#include "CNodeStatic.h"

CTreeStatic::CTreeStatic() {
	c_root = *new CNodeStatic();
}

CTreeStatic::CTreeStatic(CNodeStatic root) {
	c_root = root;
}

void CTreeStatic::vPrintTree() {
	pcGetRoot()->vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic * parentNode, CNodeStatic * newChildNode)
{
	if (newChildNode == NULL || parentNode == NULL)
		return false;

	parentNode->vAddNewChild(*newChildNode);
	newChildNode->vGetParent()->removeChild(newChildNode);

	return true;
}

