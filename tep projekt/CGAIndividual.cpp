#include "CGAIndividual.h"


CGAIndividual::CGAIndividual(){

}

CGAIndividual::CGAIndividual(int n){
	vRandomize(n);
}

void CGAIndividual::vRandomize(int n){

	std::uniform_real_distribution<double> distribution(0, 2);
	std::random_device rand;
	uint64_t entropy = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq seeder{
		rand(),
		static_cast<uint32_t>(entropy),
		static_cast<uint32_t>(entropy >> 32),
	};
	std::mt19937 eng(seeder);

	for (int i = 0; i < n; i++){
		if ( distribution(eng) > 1){
			v_solution_list.push_back(true);
		}
		else{
			v_solution_list.push_back(false);
		}
	}
}


void CGAIndividual::vMutation(double dProbability){
	std::uniform_real_distribution<double> distribution(0, 1);
	std::random_device rand;
	uint64_t entropy_from_time = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq seeder{
		rand(),
		static_cast<uint32_t>(entropy_from_time),
		static_cast<uint32_t>(entropy_from_time >> 32),
	};
	std::mt19937 eng(seeder);

	for (int i = 0; i < v_solution_list.size(); i++){
		if ( distribution(eng) <= dProbability){
			v_solution_list.at(i) = !v_solution_list.at(i);
		}
	}
}

std::tuple<CGAIndividual, CGAIndividual> CGAIndividual::tCrossover(CGAIndividual cParent1, CGAIndividual cParent2){
	int iSize = cParent1.vGet().size();

	std::uniform_real_distribution<double> distribution(0, iSize);
	std::random_device rand;
	uint64_t entropy = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::seed_seq seeder{
		rand(),
		static_cast<uint32_t>(entropy),
		static_cast<uint32_t>(entropy >> 32),
	};
	std::mt19937 eng(seeder);

	int separation_point = (int) floor(distribution(eng));

	CGAIndividual cChild1 = CGAIndividual(iSize);
	CGAIndividual cChild2 = CGAIndividual(iSize);

	for (int i = 0; i < separation_point; i++){
		cChild1.vSet(i, cParent1.vGet().at(i));
		cChild2.vSet(i, cParent2.vGet().at(i));
	}
	for (int i = separation_point; i < iSize; i++) {
		cChild1.vSet(i, cParent2.vGet().at(i));
		cChild2.vSet(i, cParent1.vGet().at(i));
	}
	return std::make_tuple(cChild1, cChild2);
}

double CGAIndividual::vFitness(CMax3SatProblem cProblem){
	return cProblem.dCompute(v_solution_list);
}

std::vector<bool> CGAIndividual::vGet() {
	return v_solution_list;
}

void CGAIndividual::vSet(int n, bool bNewValue) {
	v_solution_list.at(n) = bNewValue;
}

void CGAIndividual::operator=(CGAIndividual pcOther) {
	for (int i = 0; i < pcOther.v_solution_list.size(); i++) {
		v_solution_list.at(i) = pcOther.v_solution_list.at(i);
	}
}

void CGAIndividual::vPrint() {
	for (bool i : v_solution_list) {
		std::cout << i;
	}
	std::cout << '\n';
}