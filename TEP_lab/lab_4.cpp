#include <iostream>
#include "CNodeDynamic4.h"
#include <string>
/*
int main() {

	CTreeDynamic<int> dyn_tree;
	dyn_tree.pcGetRoot()->vSetValue(0);

	dyn_tree.pcGetRoot()->vAddNewChild();
	dyn_tree.pcGetRoot()->vAddNewChild();

	dyn_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	dyn_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	dyn_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	dyn_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	dyn_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	dyn_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	dyn_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	std::cout << "\nPrint depthfirst drzewa dynamicznego typu int: \n";

	dyn_tree.vPrintTree();
	
	CTreeDynamic <float> dtree2;
	dtree2.pcGetRoot()->vSetValue(0.1);

	dtree2.pcGetRoot()->vAddNewChild();
	dtree2.pcGetRoot()->vAddNewChild();
	dtree2.pcGetRoot()->vAddNewChild();
	
	dtree2.pcGetRoot()->pcGetChild(0)->vSetValue(1.1);
	dtree2.pcGetRoot()->pcGetChild(1)->vSetValue(2.2);
	dtree2.pcGetRoot()->pcGetChild(2)->vSetValue(3.3);

	dtree2.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	dtree2.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4.4);
	
	std::cout << "\nPrint depthfirst drzewa typu double przed modyfikacja:\n";
	dtree2.vPrintTree();

	CTreeDynamic <float> dtree5;
	dtree5.pcGetRoot()->vSetValue(0.2);

	dtree5.pcGetRoot()->vAddNewChild();
	dtree5.pcGetRoot()->vAddNewChild();

	dtree5.pcGetRoot()->pcGetChild(0)->vSetValue(54.4);
	dtree5.pcGetRoot()->pcGetChild(1)->vSetValue(55.5);

	dtree5.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dtree5.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	dtree5.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56.6);
	dtree5.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57.7);

	dtree5.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	dtree5.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58.8);

	std::cout << "\nPrint depthfirst drugiego drzewa typu double przed modyfikacja:\n";
	dtree5.vPrintTree();

	dtree2.bMoveSubtree(dtree2.pcGetRoot()->pcGetChild(2), dtree5.pcGetRoot()->pcGetChild(0));
	
	std::cout << "\nPrint depthfirst bMoveSubtree po przeniesieniu:\n";
	dtree2.vPrintTree();
	std::cout << "\nDrzewo z ktorego usuwano: \n";
	dtree5.vPrintTree();

	CTreeDynamic <bool> dtree3;
	dtree3.pcGetRoot()->vSetValue(false);

	dtree3.pcGetRoot()->vAddNewChild();
	dtree3.pcGetRoot()->vAddNewChild();
	dtree3.pcGetRoot()->vAddNewChild();

	dtree3.pcGetRoot()->pcGetChild(0)->vSetValue(true);
	dtree3.pcGetRoot()->pcGetChild(1)->vSetValue(false);
	dtree3.pcGetRoot()->pcGetChild(2)->vSetValue(true);

	std::cout << "\nPrint depthfirst drzewa typu bool:\n";
	dtree3.vPrintTree();

	/*
	CTreeDynamic <std::string>  dtree4;
	dtree3.pcGetRoot()->vSetValue(" ");

	dtree4.pcGetRoot()->vAddNewChild();
	dtree4.pcGetRoot()->vAddNewChild();
	dtree4.pcGetRoot()->vAddNewChild();

	dtree4.pcGetRoot()->pcGetChild(0)->vSetValue("Ala");
	dtree4.pcGetRoot()->pcGetChild(1)->vSetValue("ma");
	dtree4.pcGetRoot()->pcGetChild(2)->vSetValue("kota");

	dtree4.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	dtree4.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue("i psa");
	
	std::cout << "\nPrint depthfirst drzewa typu string:\n";
	dtree4.vPrintTree();
	

	return 0;
}
*/