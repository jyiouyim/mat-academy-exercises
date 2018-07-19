#pragma once
#include "IPrintObject.h"
#include "Dry_new.h"

class Wet
{
public:
	virtual void GetUV() = 0;
	virtual void DispUV() = 0;
};

class WetPointer
{
public:
	virtual Wet* GetWet() = 0;
};

class DefaultUV : public Wet
{
protected:
	int m_uv_intensity{};
public:
	DefaultUV() = default;
	~DefaultUV() = default;
	virtual void GetUV() override
	{
		std::cout << "Enter UV intensity: ";
		std::cin >> m_uv_intensity;
	}
	virtual void DispUV() override
	{
		std::cout << "\nUV light intensity: " << m_uv_intensity << std::endl;
	}
};

class SLA final : public PrintObject, public WetPointer, public SupportPointer
{
public:
	SLA() : wet_ptr(new DefaultUV), m_material("Resin"), spp_ptr(new DefaultSupports)
	{}
	~SLA() = default;
	virtual Wet* GetWet() override
	{
		return wet_ptr;
	}
	virtual Supports* GetSupports() override
	{
		return spp_ptr;
	}
	virtual void GetData() override
	{
		std::cout << "\nFor SLA print: \n";
		PrintObject::GetData();
		wet_ptr->GetUV();
	}
	virtual void DispData() const override
	{
		std::cout << "\nPRINTING SLA : \"";
		PrintObject::DispData();
		wet_ptr->DispUV();
		std::cout << "Material: " << m_material << std::endl;
		spp_ptr->DispSupports();
	}
private:
	Wet * wet_ptr;
	Supports* spp_ptr;
	std::string m_material;
};

class OPJ final : public PrintObject, public WetPointer
{
public:
	OPJ() : wet_ptr(new DefaultUV), m_material("Photopolymer")
	{}
	~OPJ() = default;
	virtual Wet* GetWet() override
	{
		return wet_ptr;
	}
	virtual void GetData() override
	{
		std::cout << "\nFor OBJET print: \n";
		PrintObject::GetData();
		wet_ptr->GetUV();
	}
	virtual void DispData() const override
	{
		std::cout << "\nPRINTING OBJET : \"";
		PrintObject::DispData();
		wet_ptr->DispUV();
		std::cout << "Material: " << m_material << std::endl;
	}
private:
	Wet * wet_ptr;
	std::string m_material;
};