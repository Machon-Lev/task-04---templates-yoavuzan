#pragma once

#include <iostream>
#include <list>
#include <exception>
template <class T >
struct MyComparator {
	bool operator () (const T& a, const T& b) const {
		return a > b;
	}
};

template <class T>
class PriorityQueue { 

private:
	// add relevant data members
	std::list<T> data;
	MyComparator<T> comparator;
public:
   // You need to complete the implement : 
	void push(const T& value);
		T poll();
	
};
template <class T>
void PriorityQueue<T>:: push(const T& value)
{
	auto it = data.begin();
	while (it != data.end() && comparator(value, *it))
		++it;
	data.insert(it, value);
}
template <class T>
T PriorityQueue<T>::poll()
{
	if (data.empty()) {
		throw std::out_of_range("PriorityQueue empty !");
	}

	T topElement = data.front();
	data.pop_front();

	return topElement;
}