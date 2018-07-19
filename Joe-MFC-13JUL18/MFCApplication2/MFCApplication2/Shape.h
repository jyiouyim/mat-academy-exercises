#pragma once

#include <iostream>
#include <vector>
#include "stdafx.h"

class Shape
{
public:
	~Shape() = default;
	virtual void GetData(POINT&, POINT&) = 0;
};

class Line final: public Shape
{
protected:
	POINT m_point1;
	POINT m_point2;
public:
	Line(long first_x = 0, long first_y = 0, long second_x = 0, long second_y = 0); //constructor
	Line(const Line& line); //copy constructor
	~Line() = default; //destructor
	virtual void GetData(POINT& one, POINT& two) override; //obtains the coordinates to two POINT variables
};

class Circle final : public Shape
{
public:
	Circle(long cx = 0, long cy = 0, long r = 0); //constructor
	Circle(const Circle& circ); //copy constructor
	~Circle() = default; //destructor
	void SetPoints(); //calculates the coordinates for the circle's bounding box corners
	virtual void GetData(POINT& one, POINT& two) override; //same as function in Line class
	void WriteData(POINT& center, long& rad); //obtains only the center coordinates and radius and pass by reference
private:
	POINT m_p1, m_p2, m_c;
	long radius{};
};

extern std::vector<Shape*> shape_vec; //externally linked vector