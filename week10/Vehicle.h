#ifndef vehicle_H_
#define vehicle_H_
class Vehicle {
	int id;
	int numberOfSeats;
	int maxSpeed; 
	double priceForRent;
public: 
	Vehicle(int id, int numberOfSeats, int MaxSpeed, double PriceForRent);
	virtual ~Vehicle();
	virtual void AddVehicle(int id, int numberOfSeats, int MaxSpeed, double PriceForRent);
};

#endif // !vehicle_H_

