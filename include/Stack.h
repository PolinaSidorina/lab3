#pragma once
#include <iostream>
using namespace std;
template<class T>
class Stack
{
	T* begin;
	T* end;
	int size;
public:
	Stack() {
		size = 100;
		begin = new T[size];
		end = begin;
	};
	Stack(int _n) {
		if (_n <= 0||_n>100) throw invalid_argument("error");
		size = _n;
		begin = new T[size];
		end = begin;
	};
	Stack(const Stack& s) {
		size = s.size;
		begin = new T[size]{};
		for (int i = 0; i < size; i++) {
			begin[i] = s.begin[i];
			end = begin + (s.end - s.begin);
		}
	};
	~Stack() {
		delete[] begin;
	};
	void push(T el) {
		if (end - begin == size) {
			size = size * 2;
			T* tmp = new T[size];
			for (int i = 0; i < end - begin; i++) {
				tmp[i] = begin[i];
			}
			end = tmp + (end - begin);
			delete[]begin;
			begin = tmp;
		}
		*end = el;
		end++;

	};
	T top() {
		if (!isEmpty()) {
			return *(end-1);
		}
		else {
			throw out_of_range("error");
		}
	};
	T pop() {

		if (begin == end) throw - 1;
		else { 
			T last = *(end-1);
			end--;
			return last;
		};
	};
	bool isEmpty() {
		return begin == end;
	};
	int Size() {
		return end - begin;
	};
	T* g_begin() {
		return begin;
	}
	T* g_end() {
		return end;
	}
	bool operator==(const Stack& s) {
		if ((end - begin) != (s.end - s.begin)) return false;
		else {
			for (int i = 0; i < end - begin; i++) {
				if (begin[i] != s.begin[i]) return false;
			}
			return true;
		}

	}
	friend ostream& operator<<(ostream& ostr, const Stack& s) {
		for (int i = s.end - s.begin - 1; i >= 0; i--) {
			cout << s.begin[i] << " ";

		}
		return ostr;
	}

};
#pragma once
