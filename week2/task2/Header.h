#ifndef HEADER_H_
#define HEADER_H_
class Triangle {
	int AB;
	int BC;
	int AC;
public:
	void initialize(int a, int b, int c);
	bool checkPrav();
	bool checkRavnobedren();
	double area();
	int perimeter();
	void height();
};
#endif
