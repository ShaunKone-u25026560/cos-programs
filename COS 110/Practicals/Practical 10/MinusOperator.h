#ifndef MINUSOPERATOR_H
#define MINUSOPERATOR_H

#include <stack>
#include <cstddef>
#include <iostream>
#include <sstream>

#include "Operator.h"

template <class T>
class MinusOperator : public Operator<T>{
		public:
			virtual T operator()(T lhs, T rhs);
			virtual Operator<T>* clone();
};

#include "MinusOperator.cpp"

#endif /* MINUSOPERATOR_H */