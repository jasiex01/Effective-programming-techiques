#pragma once
#include <vector>
#include <iostream>

class CMax3SatClause{

public:
	CMax3SatClause(int x[3]);

	void vPrint();
	bool bCompute(std::vector <bool> v_solution_list);

private:
	std::vector <int> vElems;
};