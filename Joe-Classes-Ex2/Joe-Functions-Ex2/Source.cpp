#include <iostream>

class SpaceObject
{
public:
	std::string Name;
};
/////////////////////////////////////////
class Star : public SpaceObject
{
protected:
	int temperature = 0; //temperature of star
	int size{}; //size of star
	static Star* instance;
public:
	Star() = default;
	~Star()
	{}
	static Star* getObject()
	{
		if (instance == 0)   //singleton concept to limit to only one instance
			instance = new Star();
		return instance;
	}
};
Star* Star::instance = 0;
///////////////////////////////////////
class Planet : virtual public SpaceObject
{
protected: 
	int orbit;  //size of orbit 
	int diameter; //diameter of planet
	int mass; //planet mass
	int rings; //number of rings 
	int satellite; //number of satellites
	double rotation_speed; //speed of planet rotation
	double density; //density
};
///////////////////////////////////////
class SmallBodies :virtual public SpaceObject
{
protected:
	unsigned int speed;
public:
	SmallBodies(unsigned int a): speed(a)
	{}
	SmallBodies(double) = delete;
	~SmallBodies()
	{}
};
//////////////////////////////////////
class Asteroid : public SmallBodies
{};
class Comets: public SmallBodies
{};
/////////////////////////////////////////
class DwarfPlanet: public Planet, public SmallBodies  //multiple base inheritance
{};
//////////////////////////////////////////
class Terrestrial : public Planet   //Mercury, Venus, Earth, Mars
{
protected:
	int population{};
	static Terrestrial* terra;
	static size_t count;
public:
	Terrestrial() = default;
	~Terrestrial()
	{}
	static Terrestrial* getPlanet()
	{
		if (count < 4) {   //limit to only 4 instances, using linked list
			Terrestrial* newterra = new Terrestrial();
			newterra->terra = terra;
			terra = newterra;
			++count;
		}
		return terra;
	}
};
Terrestrial* Terrestrial::terra = nullptr;
size_t Terrestrial::count = 0;
///////////////////////////////////////////////////////
class GasGiant : public Planet	   //Jupiter, Saturn, Uranus, Neptune
{
protected:
	int population{};
	static GasGiant* gas;
	static size_t count;
public:
	GasGiant() = default;
	~GasGiant()
	{}
	static GasGiant* getPlanet()
	{
		if (count < 4) {  //limit to only 4 instances, using linked list
			GasGiant* newgas = new GasGiant();
			newgas->gas = gas;
			gas = newgas;
			++count;
		}
		return gas;
	}
};
