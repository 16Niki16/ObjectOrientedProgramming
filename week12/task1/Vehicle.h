#ifndef vehicle_H_
#define vehicle_H_
class Vehicle{
	int power;
	int weight; 
public:
	Vehicle(int power, int weight);
	virtual ~Vehicle();
	int getPower();
	int getWeight();
	virtual void startEngine() = 0;
};
#endif // !vehicle_H_



