
#include "stdafx.h"
#include "Shape.h"
#include <vector>

Line::Line(long first_x, long first_y , long second_x , long second_y )
{
	m_point1.x = first_x;
	m_point1.y = first_y;
	m_point2.x = second_x;
	m_point2.y = second_y;
}

Line::Line(const Line& line)
{
	m_point1 = line.m_point1;
	m_point2 = line.m_point2;
}

void Line::GetData(POINT& one, POINT& two)
{
	one.x = m_point1.x;
	one.y = m_point1.y;
	two.x = m_point2.x;
	two.y = m_point2.y;
}

Circle::Circle(long cx , long cy , long r )
{
	radius = r;
	m_c.x = cx;
	m_c.y = cy;
	SetPoints();
}

Circle::Circle(const Circle& circ)
{
	radius = circ.radius;
	m_c = circ.m_c;
	SetPoints();
}

void Circle::SetPoints()
{
	m_p1.x = m_c.x - radius;
	m_p1.y = m_c.y - radius;
	m_p2.x = m_c.x + radius;
	m_p2.y = m_c.y + radius;
}

void Circle::GetData(POINT& one, POINT& two)
{
	one.x = m_p1.x;
	one.y = m_p1.y;
	two.x = m_p2.x;
	two.y = m_p2.y;
}

void Circle::WriteData(POINT& center, long& rad)
{
	center.x = m_c.x;
	center.y = m_c.y;
	rad = radius;
}

std::vector<Shape*>shape_vec;


