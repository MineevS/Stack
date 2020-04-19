#pragma once

#include "Stack.h"
#include "StackImplementation.h"

#include "LinkedList.h"
#include <iostream>
//class LinkedList; // меняете на include вашего листа

// вариант с использованием ранее написанного списка и множественного наследования
// если бы список не был реализован, то было бы наследование только от интерфейса
// множественное наследование можно заменить на композицию
class ListStack : public StackImplementation, public LinkedList
{
	// вот тут вы вступаете в дело
	
	private:
	
	public:
	
		ListStack();
		
		~ListStack();
		
		void push(const ValueType& value);
		
		void pop();
		
		ValueType& top();
		
		const ValueType& top() const;
		
		bool isEmpty() const;
		
		size_t size() const;
		
};

