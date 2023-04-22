#pragma once
#include <vector>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"

class CGAOptimizer{

public:
	CGAOptimizer(int iSize, int iRange, double dCrossingProb, double dMutationProb, CMax3SatProblem cProblem);

	void vInitialize();
	void vRunIteration();

	void vCalculate();
	void vPrint();
	CGAIndividual cChooseParent();

private:
	int iSize;
	int iRange;
	double dCrossingProb;
	double dMutationProb;

	std::vector<CGAIndividual> vIndividualList;
	CMax3SatProblem cProblem;
};

