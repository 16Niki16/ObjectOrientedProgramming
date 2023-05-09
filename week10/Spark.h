#ifndef Spark_H_
#define Spark_H_
#include "Vehicle.h"
class Spark {
	Vehicle** vehicle;
	int capacity;
	int size;

	void erase();
	void copy(const Spark& obj);
public:
	Spark(Vehicle** vehicle, int capacity, int size);
	~Spark();
	Spark(const Spark& obj);
	Spark& operator=(const Spark& obj);

	void addVehicle(const Vehicle& obj);
	virtual void getPrice() const = 0;
};
#endif // !Spark_H_

