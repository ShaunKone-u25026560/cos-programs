#include <iostream>
#include "Calculator.h"
#include "Operator.h"
#include "PlusOperator.h"
#include "MinusOperator.h"
#include "MultiplyOperator.h"


int main(){
	Calculator<int> esProCalc;
	
	esProCalc.addValue(3);
	esProCalc.addValue(2);
	esProCalc.addValue(1);
	
	Operator<int>* add = new PlusOperator<int>;
	Operator<int>* subtract = new MinusOperator<int>;
	
	esProCalc.addOperator(subtract);
	esProCalc.addOperator(add);
	
	std::cout << "= " << esProCalc.calculate() << std::endl;
	
	if (add)
		delete add;
	if (subtract)
		delete subtract;
	
	return 0;
}