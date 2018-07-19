#include "3DVector.h"
#include <iostream>
#include <iomanip>

int main()
{
	Vector v1(-2, 5, 4);
	Vector v2(3, 7, 3);
	Vector add = v1 + v2; //addition
	std::cout << add << std::endl;
	Vector sub = v1 - v2; //subtraction
	std::cout << sub << std::endl;
	Vector scalar = v1 * 3; //scale multiplication
	std::cout << scalar << std::endl;
	Vector cross = v1 * v2; //cross product
	std::cout << cross << std::endl;
	double dot = v1.DotProduct(v2); //dot product
	std::cout <<fixed<<setprecision(2)<< dot << std::endl;
	double length = v2.length(); //length
	std::cout << fixed << setprecision(2) << length << std::endl;
	double angle = Angle(v1, v2); //angle between vectors
	std::cout << fixed << setprecision(2) << angle << " rad" << std::endl;
}
