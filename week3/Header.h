#ifndef HEADER_H_
#define HEADER_H_
class MyString {
	int size;
	char* arr;
public:
	MyString();
	~MyString();
	MyString(const MyString& other);
	MyString(const char* str);
	int length();
	char& at(unsigned index);
	int find(char c, unsigned startPos);
	bool empty();
	void print();
	MyString substr(unsigned pos, unsigned n);
	void append(const MyString& str);
};
#endif
