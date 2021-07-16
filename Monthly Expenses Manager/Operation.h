#pragma once

enum operations {
	insert,
	remove1,
};

template <class T>
class Operation
{
private:
	T change;
	operations operation;
public:
	Operation(T change, operations op);
	T getChange();
	operations getOperation();
	
};

template<class T>
inline Operation<T>::Operation(T change, operations op)
{
	this->change = change;
	this->operation = op;
}

template<class T>
inline T Operation<T>::getChange()
{
	return change;
}

template<class T>
inline operations Operation<T>::getOperation()
{
	return operation;
}
