#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CClause.h"

class CMax3SatProblem{

public:
	CMax3SatProblem();

	void vLoad(std::string sFile);
	double dCompute(std::vector <bool> v_solution_list);
	void vPrint();

private:
	std::vector <CMax3SatClause> vClauseList;
};

