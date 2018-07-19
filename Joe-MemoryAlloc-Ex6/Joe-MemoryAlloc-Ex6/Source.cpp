#include<iostream>

class MyValue
{
public:
	static MyValue *getObject();
	void setValue(int i_myValue)
	{
		 value = i_myValue;
	}

	int getValue()
	{
		return value;
	}

	MyValue() : value(0)
	{ }

private:
	int value;
	static MyValue* instance;
};

MyValue* MyValue::instance = 0;

MyValue *MyValue::getObject()
{
	if (instance == 0) {
		instance = new MyValue();
	}
	return instance;
}

int main()
{
	auto userValue = MyValue::getObject();
	userValue->setValue(2);
	std::cout << "value = " << userValue->getValue() << std::endl;

	auto userValue2 = MyValue::getObject();
	std::cout << "value = " << userValue2->getValue() << std::endl;
	userValue2->setValue(100);
	std::cout << "value = " << userValue2->getValue() << std::endl;

	return 0;
}
