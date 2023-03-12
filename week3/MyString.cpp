#include <iostream>
#include <cstring>
#include "Header.h"

void myString(const char* str, char* arr, int size) {
	if (size == 0)
		arr = nullptr;
	else
	{
		arr = new char[size];
		for (int i = 0; i < size; i++)
			arr[i] = str[i];
	}
}

MyString::MyString() {
	arr = nullptr;
	size = 0;
}

MyString::~MyString() {
	delete[] arr;
}

MyString::MyString(const MyString& other) {
	size = other.size;
	myString(other.arr, arr, size);
}

MyString::MyString(const char* str){
	size = strlen(str);
	myString(str, arr, size);
}

int MyString::length() {
	return size;
}
char& MyString::at(unsigned index) {
if(index>=size){
	throw std::exception("There is not index with this number");
	}
return arr[index];
}

int MyString::find(char c, unsigned startPos){
	for (int i = startPos; i < size; i++) {
	if(arr[i] == c){
		return i;
		}
	}
	return -1;
}

bool MyString::empty() {
	if (size == 0)
		return true;
	return false;
}

MyString MyString::substr(unsigned pos, unsigned n) {
	MyString function;
	if (pos >= size)
		throw std::exception("Invalid number");
	if (pos + n < size) {
		function.size = n;
	}
	else {
		function.size = size - pos;
	}
	function.arr = new char[function.size];
	int k = 0;
	for (int i = pos; i < pos + n && i < size; i++) {
		function.arr[k] = arr[i];
		++k;
	}
	return function;
}

void MyString::append(const MyString& str) {
	if (strlen(str.arr) != 0) {
		MyString temp;
		int k = 0;
		temp.size = strlen(str.arr) + size;
		temp.arr = new char[temp.size];
		for(int i = 0; i<temp.size;i++){
	if(i<size){
		temp.arr[i] = arr[i];
	}
	else {
		temp.arr[i] = str.arr[k];
		++k;
	}
		}
		*this = temp;
	}
}

void MyString::print() {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}