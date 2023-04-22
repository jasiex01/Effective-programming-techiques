#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer(int iNewSize, int iNewRange, double dNewCrossingProb, double dNewMutationProb, CMax3SatProblem cNewProblem){
	iSize = iNewSize;
	iRange = iNewRange;
	cProblem = cNewProblem;
	dCrossingProb = dNewCrossingProb;
	dMutationProb = dNewMutationProb;
}

void CGAOptimizer::vInitialize(){
	for (int i = 0; i < iSize; i++){
		vIndividualList.push_back(CGAIndividual(iRange));
	}
}

CGAIndividual CGAOptimizer::cChooseParent(){

	std::uniform_real_distribution<double> distribution(0, iSize);
	std::random_device rand;
	uint64_t entropy = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq seeder{
		rand(),
		static_cast<uint32_t>(entropy),
		static_cast<uint32_t>(entropy >> 32),
	};
	std::mt19937 eng(seeder);

	CGAIndividual r1 = vIndividualList.at( (int) floor(distribution(eng)));
	CGAIndividual r2 = vIndividualList.at( (int) floor(distribution(eng)));
	if (cProblem.dCompute(r1.vGet()) >= cProblem.dCompute(r2.vGet())){
		return r1;
	}
	return r2;
}

void CGAOptimizer::vRunIteration(){

	std::uniform_real_distribution<double> distribution(0, 1);
	std::random_device rand;
	uint64_t entropy = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq seeder{
		rand(),
		static_cast<uint32_t>(entropy),
		static_cast<uint32_t>(entropy >> 32),
	};
	std::mt19937 eng(seeder);

	std::vector<CGAIndividual> newGeneration;

	while (newGeneration.size() < vIndividualList.size()){
		CGAIndividual cParent1 = cChooseParent();
		CGAIndividual cParent2 = cChooseParent();
		CGAIndividual cChild1 = CGAIndividual(iRange);
		CGAIndividual cChild2 = CGAIndividual(iRange);

		if (distribution(eng) < dCrossingProb){
			std::tuple<CGAIndividual, CGAIndividual> dzieci = cChild1.tCrossover(cParent1, cParent2);
			cChild1 = std::get<0>(dzieci);
			cChild2 = std::get<1>(dzieci);
		}
		else{
			cChild1 = cParent1;
			cChild2 = cParent2;
		}
		cChild1.vMutation(dMutationProb);
		cChild2.vMutation(dMutationProb);
		newGeneration.push_back(cChild1);
		newGeneration.push_back(cChild2);
	}
	vIndividualList.clear();
	for (int i = 0; i < newGeneration.size(); i++){
		vIndividualList.push_back(newGeneration.at(i));
	}
}

void CGAOptimizer::vPrint(){
	int iter = 0;
	for (CGAIndividual i: vIndividualList)
	{
		std::cout << iter << " ";
		i.vPrint();
		iter++;
	}
}

void CGAOptimizer::vCalculate(){
	double iMax = 0;
	for (int i = 0; i < iSize; i++){
		double iTemp = vIndividualList.at(i).vFitness(cProblem);
		if (iMax < iTemp) {
			iMax = iTemp;
		}
	}
	std::cout << "Najwieksza poprawnosc: " << iMax << '\n';
}