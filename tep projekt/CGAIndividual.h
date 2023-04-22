#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>
#include <time.h>
#include <tuple>

#include "CMax3SatProblem.h"

class CGAIndividual{

public:
	CGAIndividual();
	CGAIndividual(int n);

	std::vector <bool> vGet();
	void vSet(int n, bool bNewValue);
	void vRandomize(int n);
	void vMutation(double dProbability);
	std::tuple<CGAIndividual, CGAIndividual> tCrossover(CGAIndividual cParent1, CGAIndividual cParent2);
	double vFitness(CMax3SatProblem cProblem);

	void operator=(CGAIndividual pcOther);
	void vPrint();

private:
	std::vector<bool> v_solution_list;
};

