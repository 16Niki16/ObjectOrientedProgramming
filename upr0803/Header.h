#ifndef HEADER_H_
#define HEADER_H_
class TimeStamp {
public:
	int hours; 
	int minutes; 
	int seconds;
	void createSeconds();
	void print();
	void sbor(int seconds1, int seconds2);

};
#endif
