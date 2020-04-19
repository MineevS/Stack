
#include "Stack.h"
#include "ListStack.h"
#include "LinkedList.h"
#include "MyVector.h"
#include "VectorStack.h"
#include "StackImplementation.h"

using namespace std;

int main(int argc, char** argv)
{
	//Создание:
	
		LinkedList list1;//Создание обычного листа.//+
	
		MyVector Vector1;//Создание обычного вектора.//+
	
		ListStack LStack1;//Создаем Стек листа.//+
	
		VectorStack VStack1;// Создаем Стек вектора.//+
	//
	
	//Add:
	
		list1.pushBack(5);//Добавление элементов в лист.//+
	
		Vector1.pushBack(5);//Добавление элементов в вектор.//+
		
		LStack1.push(5);//Добавление элементов в Стек листа.//+-
		
		VStack1.push(5);//Добавление элементов в Стек вектора.//+-
	//
	
	
}