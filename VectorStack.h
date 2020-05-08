#pragma once
#include "StackImplementation.h"

#include "MyVector.h"
//class MyVector; // меняете на include вашего вектора

// вариант с использованием ранее написанного вектора и множественного наследования
// если бы вектор не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class VectorStack : public StackImplementation, public MyVector
{
	// вот тут вы вступаете в дело
	
	private:
	
	public:
	
		VectorStack();
		
		~VectorStack();
	
		void push(const ValueType& value);
		
		void pop();
		
		ValueType& top();
		
		const ValueType& top() const;
		
		bool isEmpty() const;
		
		size_t size() const;
};

