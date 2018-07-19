#pragma once
#include <cmath>
#include <ostream>

class Vector
{
private:
	double m_x{ 0 }, m_y{ 0 }, m_z{ 0 };
public:
	Vector() = default;
	explicit Vector(double i_a, double i_b, double i_c) : m_x(i_a),m_y(i_b),m_z(i_c)
	{}
	~Vector()
	{}

	double GetX() const;
	double GetY() const;
	double GetZ() const;

	Vector& operator+ (const Vector& i_second);
	Vector& operator- (const Vector& i_second);
	Vector& operator* (const Vector& i_second);
	Vector& operator* (const double& scale); 
	double length();
	double DotProduct(const Vector& i_vec);
};

std::ostream& operator<<(std::ostream& os, const Vector& i_second);
double Angle(Vector& a, Vector& b);
