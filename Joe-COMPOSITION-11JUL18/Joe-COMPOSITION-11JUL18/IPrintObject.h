#pragma once
#include <iostream>
#include <string>

class PrintObject  //main object for vector in main()
{
protected:
	double m_resolution{ 0.0 };
	int m_speed{ 0 };
	std::string m_name{ "" };
public:
	PrintObject() = default;
	~PrintObject() = default;
	virtual void GetData() 
	{
		std::cout << "Enter print name: ";
		std::cin >> m_name;
		std::cout << "Enter resolution: ";
		std::cin >> m_resolution;
		std::cout << "Enter printing speed: ";
		std::cin >> m_speed;
	}
	virtual void DispData() const
	{
		std::cout << m_name << "\""
			<< "\nLayer resolution: " << m_resolution
			<< "\nPrint speed: " << m_speed;
	}
};

class Supports
{
public:
	virtual void AddSupports() = 0;
	virtual void DispSupports() = 0;
};

class SupportPointer
{
public:
	virtual Supports* GetSupports() = 0;
};

class DefaultSupports: public Supports
{
protected:
	std::string m_supports{ "None" };
public:
	DefaultSupports() = default;
	~DefaultSupports() = default;
	virtual void AddSupports() override
	{
		char supports{ 'y' };
		std::cout << "Add supports? (y/n): ";
		std::cin >> supports;
		if (supports != 'n')
			m_supports = "Added";
	}
	virtual void DispSupports() override
	{
		std::cout << "Supports: "<<m_supports;
	}
};