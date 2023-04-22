#include "CClause.h"

CMax3SatClause::CMax3SatClause(int x[3]) {
	for (int i = 0; i < 3; i++){
		vElems.push_back(x[i]);
	}
}

bool CMax3SatClause::bCompute(std::vector<bool> v_solution_list){
	bool bTab[3];
	int a, b, c;
	a = vElems.at(0);
	b = vElems.at(1);
	c = vElems.at(2);
	int iter = 0;
	if (a > 0) {
		bTab[0] = v_solution_list.at(abs(a));
	}
	else{
		bTab[0] = !v_solution_list.at(abs(a));
	}
	if (b > 0) {
		bTab[1] = v_solution_list.at(abs(b));
	}
	else {
		bTab[1] = !v_solution_list.at(abs(b));
	}
	if (b > 0) {
		bTab[2] = v_solution_list.at(abs(c));
	}
	else {
		bTab[2] = !v_solution_list.at(abs(c));
	}
	for (bool i: bTab){
		if (i) return true;
	}
	return false;
}

void CMax3SatClause::vPrint() {
	for (int i : vElems) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}