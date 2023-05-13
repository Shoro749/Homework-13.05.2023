#include <iostream>
using namespace std;

class Base {
private:
	int value1;
	int value2;
public:
	Base() {
		this->value1 = 0;
		this->value2 = 0;
	}

	Base(int value1, int value2) {
		this->value1 = value1;
		this->value2 = value2;
	}

	virtual int getValue() { return this->value1; }
	virtual int getValue2() { return this->value2; }

	~Base() {
		this->value1 = NULL;
		this->value2 = NULL;
	}
};

class Child : public Base {
private:
	int value3;
	int value4;
public:
	Child() {
		this->value3 = 0;
		this->value4 = 0;
	}

	Child(int value3, int value4) {
		this->value3 = value3;
		this->value4 = value4;
	}

	virtual int getValue() { return this->value3; }
	virtual int getValue2() { return this->value4; }

	~Child() {
		this->value3 = NULL;
		this->value4 = NULL;
	}
};

class Child2 : public Base {
private:
	int value5;
	int value6;
public:
	Child2() {
		this->value5 = 0;
		this->value6 = 0;
	}

	Child2(int value5, int value6) {
		this->value5 = value5;
		this->value6 = value6;
	}

	virtual int getValue() { return this->value5; }
	virtual int getValue2() { return this->value6; }

	~Child2() {
		this->value5 = NULL;
		this->value6 = NULL;
	}
};

int main() {
	Base** base = new Base * [3] {
		new Base(4, 1),
		new Child(2, 3),
		new Child2(5, 2)
	};
	for (size_t i = 0; i < 3; i++)
	{
		cout << i+1 << ") " << base[i]->getValue() << ", " << base[i]->getValue2() << endl;
	}
	for (size_t i = 0; i < 3; i++)
	{
		delete base[i];
	}

	return 0;
}