#include "CMax3SatProblem.h"

CMax3SatProblem::CMax3SatProblem(){

}

void CMax3SatProblem::vPrint() {
	for (CMax3SatClause i : vClauseList) {
		i.vPrint();
	}
}

void CMax3SatProblem::vLoad(std::string sFile){
	std::string sText;
	std::ifstream fFile(sFile);

	while (std::getline (fFile, sText)){
		int intArr[3];
		int start = 0;
		int end = sText.find(" ");
		int i = 0;

		while (end != -1){
			std::string sSub = sText.substr(start, end - start);
			if (sSub != "("){
				intArr[i] = stoi(sSub);
				i++;
			}
			start = end + 1;
			end = sText.find("  ", start);
		}
		vClauseList.push_back(CMax3SatClause(intArr));
	}
}

double CMax3SatProblem::dCompute(std::vector<bool> v_solution_list){
	double correct_counter = 0;
	double clause_counter = 0;
	for (CMax3SatClause i : vClauseList){
		if (i.bCompute(v_solution_list)) correct_counter++;
		clause_counter += 1;
	}
	return correct_counter / clause_counter;
}

