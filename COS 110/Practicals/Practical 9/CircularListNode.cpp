#include "CircularListNode.h"

template <class T>
CircularListNode<T>::CircularListNode(T data) : data(data), next(NULL) {
}

template <class T>
CircularListNode<T>::~CircularListNode() {
}
