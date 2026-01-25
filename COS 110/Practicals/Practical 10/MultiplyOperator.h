#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H

#include <stack>
#include <cstddef>
#include <iostream>
#include <sstream>

#include "Operator.h"

template <class T>
class MultiplyOperator : public Operator<T>{
		public:
			virtual T operator()(T lhs, T rhs);
			virtual Operator<T>* clone();
};

#include "MultiplyOperator.cpp"

#endif /* MULTIPLYOPERATOR_H */