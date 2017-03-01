#include<iostream>
#include<string>

using namespace std;

class Beverage {
public:
	string description;  
	Beverage() {
		this->description = "Unkown Beverage";
	};

	string get_description() {
		return this->description;
	}

	virtual float cost()=0;
};

class CondimentDecorator :public Beverage {
public:
	CondimentDecorator() {};
	virtual string get_description()=0;
};


class Espresso :public Beverage {
public:
	Espresso() { this->description = "Espresso";};

	float cost(){
		return 1.99;
	}
};

class HouseBlend :public Beverage {
public:
	HouseBlend() { this->description = "House Blend Coffee"; };
	
	float cost() {
		return 0.99;
	}
};

class Mocha :public CondimentDecorator{
public:
	Beverage *beverage;
	Mocha(Beverage *beverage) {
		this->beverage = beverage;
	};

	string get_description() {
		return this->beverage->get_description() + ", Mocha";
	}

	float cost() {
		return this->beverage->cost() + 0.20;
	}
};

int main(void) {
	Beverage *beverage = new Espresso();
	cout << beverage->get_description()<<"$"<<beverage->cost() << endl;

	//not worked, beverage2 call base function.
	Beverage *beverage2 = new HouseBlend();
	beverage2 = new Mocha(beverage2);
	cout << beverage2->get_description() << "$" << beverage2->cost() << endl;
	/*beverage2 = new Mocha(beverage2);
	cout << beverage2->get_description()<<"$"<<beverage2->cost()<<endl;*/
	while (1);
	return 0;
}