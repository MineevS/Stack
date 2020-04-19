﻿//Обьявление операций.

#pragma once

#include <iostream>
#include <cstring>
#include <iterator>
#include <cmath>

using namespace std;

// стратегия изменения capacity
enum class ResizeStrategy {
	Additive,
	Multiplicative
};
//
enum class SortedStrategy {
	increasing, //Возрастание.
	decreasing //Убывание.
};

// тип значений в векторе
// потом будет заменен на шаблон
using ValueType = double;

class MyVector
{
	private:
	
		ValueType* _data; // Указатель на массив _data.
		size_t _size;	// Длина массива.
		size_t _capacity; //
		float _coef;
		ResizeStrategy _ResizeStrategy;
	
	public:
	
		//MyVector();//
		MyVector(size_t size = 0, ResizeStrategy ResizeStrategyK = ResizeStrategy::Multiplicative, float coef = 1.5f); //+// Конструктор (без параметров)(по умолчанию).
		MyVector(size_t size, ValueType value, ResizeStrategy ResizeStrategyK = ResizeStrategy::Multiplicative, float coef = 1.5f);//+
	
		MyVector(const MyVector& copy);//+
		MyVector& operator=(const MyVector& copy);//+

		~MyVector();//-

		// для умненьких — реализовать конструктор и оператор для перемещения

		size_t capacity() const;
		size_t size() const;
		float loadFactor();

		// доступ к элементу, 
		// должен работать за O(1)
		ValueType operator[](const size_t i) const;

		// добавить в конец,
		// должен работать за amort(O(1))
		void pushBack(const ValueType& value);
		// вставить,
		// должен работать за O(n)
		void insert(const size_t i, const ValueType& value);	// версия для одного значения
		void insert(const size_t i, const MyVector& value);		// версия для вектора

		// удалить с конца,
		// должен работать за amort(O(1))
		void popBack();
		// удалить
		// должен работать за O(n)
		void erase(const size_t i);
		void erase(const size_t i, const size_t len);			// удалить len элементов начиная с i

		// найти элемент,
		// должен работать за O(n)
		// если isBegin == true, найти индекс первого элемента, равного value, иначе последнего
		// если искомого элемента нет, вернуть -1
		long long int find(const ValueType& value, bool isBegin) const;	

		// зарезервировать память (принудительно задать capacity)
		void reserve(const size_t capacity);

		// изменить размер
		// если новый размер больше текущего, то новые элементы забиваются дефолтными значениями
		// если меньше - обрезаем вектор
		void resize(const size_t size, const ValueType value);

		// очистка вектора, без изменения capacity
		void clear();
		
		//Доп:
		
			//Изменение вместимости вектора.
			void shrink_fit();

			//Доп. методы.
			void Show_ResizeStrategy() const;
		
		//Итераторы:
		
			class Iterator;
			typedef const ValueType *ConstIterator;
			
			Iterator begin(); // возвращает итератор, указывающий на первый элемент
			Iterator end();   // возвращает итератор, "указывающий" за последний элемент

		// Можем напрямую использовать указатели в качества итераторов
		
			ConstIterator begin() const {return (this->_data);}
			ConstIterator end() const {return (this->_data);}
			
		//Доп 2:
		
			MyVector(const MyVector& vec, SortedStrategy strategy, ResizeStrategy ResizeStrategyK = ResizeStrategy::Multiplicative, float coef = 1.5f);
			
};

class MyVector::Iterator
{
	private:
		ValueType *ptr;
		Iterator(ValueType *p): ptr(p) {}
		friend class MyVector;
		
	public:
		Iterator(const Iterator &i):ptr(i.ptr) {}
		
		bool operator==(const Iterator &i) {return ptr == i.ptr;}
		bool operator!=(const Iterator &i) {return ptr != i.ptr;}

		Iterator &operator++() 
		{
			ptr++;
			return *this;
		}

		Iterator &operator--() 
		{
			ptr--;
			return *this;
		}

		ValueType &operator*() {return *ptr;}
};

template <>
struct std::iterator_traits<MyVector::Iterator>
{
    using iterator_category = std::bidirectional_iterator_tag;
};

