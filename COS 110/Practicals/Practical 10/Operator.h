#ifndef OPERATOR_H
#define OPERATOR_H

#include <stack>
#include <cstddef>
#include <iostream>
#include <sstream>

template <class T>
class Operator{
		public:
			Operator();
			virtual T operator()(T lhs, T rhs) =0;
			virtual ~Operator();
			virtual Operator<T>* clone() =0;
};

#include "Operator.cpp"

#endif /* OPERATOR_H */