#pragma once
#include "IPrintObject.h"

class Dry
{
public:
	virtual void GetTemp() = 0;
	virtual void DispTemp() = 0;
};

class DryPointer
{
public:
	virtual Dry* GetDry() = 0;
};

class FDMTemp : public Dry
{
protected:
	int m_nozzle_temp{};
	int m_heatbed_temp{};
public:
	FDMTemp() = default;
	~FDMTemp() = default;
	virtual void GetTemp() override
	{
		std::cout << "Enter print temperature: ";
		std::cin >> m_nozzle_temp;
		std::cout << "Enter heatbed temperature: ";
		std::cin >> m_heatbed_temp;
	}
	virtual void DispTemp() override
	{
		std::cout << "\nPrint temperature: " << m_nozzle_temp
				  << "\nHeatbed temperature: "<< m_heatbed_temp<<std::endl;
	}
};

class SLSTemp : public Dry
{
protected:
	int m_laser_temp{};
public:
	SLSTemp() = default;
	~SLSTemp() = default;
	virtual void GetTemp() override
	{
		std::cout << "Enter laser temperature: ";
		std::cin >> m_laser_temp;
	}
	virtual void DispTemp() override
	{
		std::cout << "\nLaser temperature: " << m_laser_temp << std::endl;
	}
};

class FDM final : public PrintObject, public DryPointer, public SupportPointer
{
public:
	FDM() : dry_ptr(new FDMTemp), m_material("PLA"), spp_ptr(new DefaultSupports)
	{}
	~FDM() = default;
	virtual Dry* GetDry() override
	{
		return dry_ptr;
	}
	virtual Supports* GetSupports() override
	{
		return spp_ptr;
	}
	virtual void GetData() override
	{
		std::cout << "\nFor FDM print: \n";
		PrintObject::GetData();
		dry_ptr->GetTemp();
	}
	virtual void DispData() const override
	{
		std::cout << "\nPRINTING FDM : \"";
		PrintObject::DispData();
		dry_ptr->DispTemp();
		std::cout << "Material: " << m_material << std::endl;
		spp_ptr->DispSupports();
	}
private:
	Dry * dry_ptr;
	Supports* spp_ptr;
	std::string m_material;
};

class SLS final : public PrintObject, public DryPointer
{
public:
	SLS() : dry_ptr(new SLSTemp), m_material("Alumide")
	{}
	~SLS() = default;
	virtual Dry* GetDry() override
	{
		return dry_ptr;
	}
	virtual void GetData() override
	{
		std::cout << "\nFor SLS print: \n";
		PrintObject::GetData();
		dry_ptr->GetTemp();
	}
	virtual void DispData() const override
	{
		std::cout << "\nPRINTING SLS : \"";
		PrintObject::DispData();
		dry_ptr->DispTemp();
		std::cout << "Material: " << m_material<<std::endl;
	}
private:
	Dry * dry_ptr;
	std::string m_material;
};
