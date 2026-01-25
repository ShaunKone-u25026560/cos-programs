#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stack>
#include <cstddef>
#include <iostream>
#include <sstream>

#include "Operator.h"

template <class T>
class Calculator{
		private:
			std::stack<T*>* valueStack;
			std::stack<Operator<T>*>* operatorStack;
		public:
			Calculator();
			~Calculator();
			void addValue(T val);
			void addOperator(Operator<T>* op);
			T removeValue();
			Operator<T>* removeOperator();
			int numValues();
			int numOperators();
			T calculate();
};

#include "Calculator.cpp"

#endif /* CALCULATOR_H */