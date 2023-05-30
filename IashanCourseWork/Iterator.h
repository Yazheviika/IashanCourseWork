#pragma once

template <class T>
class Iterator {

	T* current;

public:

	Iterator(T* first) :current(first) {};

	T& operator+(int n) { return *(current + n); }

	T& operator-(int n) { return *(current - n); }

	T& operator++(int) { return *(current++); }

	T& operator--(int) { return *(current--); }

	T& operator++() { return *++current; }

	T& operator--() { return *--current; }

	bool operator!=(const Iterator& it) { return current != it.current; }

	bool operator==(const Iterator& it) { return current == it.current; }

	T& operator*() { return *current; }
};