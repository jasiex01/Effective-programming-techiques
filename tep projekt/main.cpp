#include <iostream>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"

int main() {

    CMax3SatProblem max3sat = CMax3SatProblem();
    max3sat.vLoad("C:\\m3s_300_1.txt");
    CGAOptimizer result = CGAOptimizer(30, 300, 0.75, 0.01, max3sat);
    result.vInitialize();

    for (int i = 0; i < 10; i++) {
        result.vRunIteration();
        result.vCalculate();
    }
}
