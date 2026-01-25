#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

#include <stack>
#include <cstddef>
#include <iostream>
#include <sstream>

#include "Operator.h"

template <class T>
class PlusOperator : public Operator<T>{
		public:
			virtual T operator()(T lhs, T rhs);
			virtual Operator<T>* clone();
};

#include "PlusOperator.cpp"

#endif /* PLUSOPERATOR_H */