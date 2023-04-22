/*
#include <iostream>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"

int main() {

	CNodeStatic c_root;

	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//zad 3
	std::cout << "PrintUp drzewa nr 1: ";
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	c_root.pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(31);

	std::cout << "\nPrintUp drzewa nr 2: ";
	c_root.pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vPrintUp();
	std::cout << std::endl;

	//zad 4 test
	CTreeStatic tree(c_root);
	std::cout << "Print depthfirst drzewa: ";
	tree.vPrintTree();

	//zad 5
	CTreeDynamic dyn_tree;

	dyn_tree.pcGetRoot()->vAddNewChild();
	dyn_tree.pcGetRoot()->vAddNewChild();
	
	dyn_tree.pcGetRoot()->pcGetChild(0)->vSetValue(4);
	dyn_tree.pcGetRoot()->pcGetChild(1)->vSetValue(6);
	
	dyn_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(41);
	dyn_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(42);
	dyn_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(61);
	dyn_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(62);
	
	std::cout << "\nPrint depthfirst drzewa dynamicznego: ";

	dyn_tree.vPrintTree();

	//zad 6

	CTreeStatic stree2;

	stree2.pcGetRoot()->vAddNewChild();
	stree2.pcGetRoot()->vAddNewChild();
	stree2.pcGetRoot()->vAddNewChild();

	stree2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	stree2.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	stree2.pcGetRoot()->pcGetChild(2)->vSetValue(3);

	stree2.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	stree2.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	CTreeStatic stree3;
	stree3.pcGetRoot()->vAddNewChild();
	stree3.pcGetRoot()->vAddNewChild();

	stree3.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	stree3.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	stree3.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	stree3.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	stree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	stree3.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	stree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	stree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	stree2.bMoveSubtree(stree2.pcGetRoot()->pcGetChild(2), stree3.pcGetRoot()->pcGetChild(0));
	std::cout << "\nPrint depthfirst bMoveSubtree statyczny: ";
	stree2.vPrintTree();
	std::cout << "\nDrzewo z ktorego usuwano: ";
	stree3.vPrintTree();


	CTreeDynamic dtree2;

	dtree2.pcGetRoot()->vAddNewChild();
	dtree2.pcGetRoot()->vAddNewChild();
	dtree2.pcGetRoot()->vAddNewChild();

	dtree2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	dtree2.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	dtree2.pcGetRoot()->pcGetChild(2)->vSetValue(3);

	dtree2.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	dtree2.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	CTreeDynamic dtree3;
	dtree3.pcGetRoot()->vAddNewChild();
	dtree3.pcGetRoot()->vAddNewChild();

	dtree3.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	dtree3.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	dtree3.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dtree3.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	dtree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	dtree3.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	dtree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	dtree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	dtree2.bMoveSubtree(dtree2.pcGetRoot()->pcGetChild(2), dtree3.pcGetRoot()->pcGetChild(0));
	std::cout << "\nPrint depthfirst bMoveSubtree dynamiczny:";
	dtree2.vPrintTree();
	std::cout << "\nDrzewo z ktorego usuwano: ";
	dtree3.vPrintTree();



}
*/