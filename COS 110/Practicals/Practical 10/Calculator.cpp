#include "Operator.h"

template <class T>
Calculator<T>::Calculator() // Function 1
{
	valueStack = new std::stack<T*>;
	operatorStack = new std::stack<Operator<T>*>;
}

template <class T>
Calculator<T>::~Calculator() // Function 2
{
	if (valueStack)
		delete valueStack;
	if (operatorStack)
		delete operatorStack;
}

template <class T>
void Calculator<T>::addValue(T val) // Function 3
{
	T* newVal = new T;
	*newVal = val;
	valueStack->push(newVal);
}

template <class T>
void Calculator<T>::addOperator(Operator<T>* op) // Function 4
{
	if (op)
	{
		Operator<T>* newOp = op->clone();
		operatorStack->push(newOp);
	}
}

template <class T>
T Calculator<T>::removeValue()
{
	if (valueStack->empty())
	{
		//std::string errMsg = "Value stack is empty.";
		throw "Value stack is empty.";
	}
	
	T removedValue = *(valueStack->top());
	T* deleteValue = valueStack->top();
	valueStack->pop();
	delete deleteValue;
	return removedValue;
}

template <class T>
Operator<T>* Calculator<T>::removeOperator()
{
	if (operatorStack->empty())
		return NULL;
	
	Operator<T>* removedOp = operatorStack->top();
	operatorStack->pop();
	return removedOp;
}

template <class T>
int Calculator<T>::numValues()
{
	return valueStack->size();
}

template <class T>
int Calculator<T>::numOperators()
{
	return operatorStack->size();
}

template <class T>
T Calculator<T>::calculate()
{
	if (valueStack->empty())
	{
		//std::string errMsg = "Value stack is empty.";
		throw "Value stack is empty.";
	}
	
	while (!operatorStack->empty())
	{
		if ( numValues() < 2)
		{
			//std::string errMsg = "Not enough values to perform operation.";
			throw "Not enough values to perform operation.";
		}
		
		T* interim = new T;
		T val1 = removeValue();
		T val2 = removeValue();
		
		Operator<T>* op = removeOperator();
		
		*interim = (*op)(val1, val2);
		delete op;
		valueStack->push(interim);
	}
	
	return removeValue();
}