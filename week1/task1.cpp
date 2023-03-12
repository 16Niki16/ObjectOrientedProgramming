#include <iostream>
#include<cmath>
struct Vector {
	int x, y, z;
	double getVectorLenght() {
		return sqrt(x * x + y * y + z * z);
	}
	double getScalarProduct(Vector first, Vector second);
	bool arePerpendicular(Vector first, Vector second);
	Vector plus(Vector v)
	{
		Vector sum;
		sum.x = x + v.x;
		sum.y = y + v.y;
		sum.z = z + v.z;
		return sum;
	}
	void print() const{
		std::cout << x << " " << y << " " << z << std::endl;
	}
};

double Vector::getScalarProduct(Vector first, Vector second) {
	return  first.x * second.x + first.y * second.y + first.z * second.z;
}
bool Vector::arePerpendicular(Vector first, Vector second) {
	return getScalarProduct(first, second) == 0;
}

int main(){

}
