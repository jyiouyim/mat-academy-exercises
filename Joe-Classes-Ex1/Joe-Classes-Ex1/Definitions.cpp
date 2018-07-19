#include "3DVector.h"
#include <iostream>
#include <cmath>

double Vector::GetX() const
{
	return m_x;
}

double Vector::GetY() const
{
	return m_y;
}

double Vector::GetZ() const
{
	return m_z;
}

Vector& Vector::operator+ (const Vector& i_second) //addition
{
	m_x += i_second.m_x;
	m_y += i_second.m_y;
	m_z += i_second.m_z;
	return *this;
}

Vector& Vector::operator- (const Vector& i_second) //subtraction
{
	m_x -= i_second.m_x;
	m_y -= i_second.m_y;
	m_z -= i_second.m_z;
	return *this;
}

Vector& Vector::operator* (const Vector& i_second) //cross product
{
	m_x = (m_y*i_second.m_z) - (i_second.m_y*m_z);
	m_y = -((m_x*i_second.m_z) - (i_second.m_x*m_z));
	m_z = (m_x*i_second.m_y) - (i_second.m_y*m_x);
	return *this;
}

Vector& Vector::operator* (const double& scale) //scale product
{
	m_x *= scale;
	m_y *= scale;
	m_z *= scale;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& i_second) //stream operator
{
	char sign_x = ((i_second.GetX()) < 0) ? '-' : '+';
	char sign_y = ((i_second.GetY()) < 0) ? '-': '+';
	char sign_z = ((i_second.GetZ()) < 0) ? '-' : '+';
	os << sign_x<< abs(i_second.GetX()) << "i"<<sign_y << abs(i_second.GetY()) 
		<< "j" << sign_z<< abs(i_second.GetZ()) << "k";
	return os;
}

double Vector::length() //length of vector
{
	double ans = sqrt(pow(m_x, 2)+pow(m_y,2)+pow(m_z,2));
	return ans;
}

double Vector::DotProduct(const Vector& i_vec) //dot product
{
	m_x *= i_vec.m_x;
	m_y *= i_vec.m_y;
	m_z *= i_vec.m_z;
	return (m_x + m_y + m_z);
}

double Angle(Vector& a, Vector& b) //angle between vectors
{
	return acos(a.DotProduct(b) / (a.length() * b.length()));
}

