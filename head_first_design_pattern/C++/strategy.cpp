//Strategy Pattern

#include<iostream>

using namespace::std;

// interface
class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class QuackBehavior
{
public:
	virtual void quack() = 0;
};

//behavior class
class Fly:public FlyBehavior
{
	void fly()
	{
		cout << "Fly" << endl;
	}
};

class FlyNoWay :public FlyBehavior
{
	void fly()
	{
		cout << "I can't fly" << endl;
	}
};

class FlyRocketPowered :public FlyBehavior
{
	void fly()
	{
		cout << "I'm flying with a rocket!" << endl;
	}
};

class FlyWithWings :public FlyBehavior
{
	void fly()
	{
		cout << "I'm flying!!" << endl;
	}
};

class Quack :public QuackBehavior
{
	void quack() 
	{
		cout << "Quack" << endl;
	}
};

class MuteQuack : public QuackBehavior
{
	void quack()
	{
		cout << "<< Silence >>" << endl;
	}
};

class Squeak :public QuackBehavior
{
	void quack()
	{
		cout << "Squeak" << endl;
	}
};

class Duck
{
public:
	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;
	virtual void display() = 0;
	void swim()
	{
		cout << "All ducks float, even decoys!" << endl;
	}

	void perform_fly()
	{
		flyBehavior->fly();
	}
	
	void perform_quack()
	{
		quackBehavior->quack();
	}

	void set_fly_behavior(FlyBehavior *fb)
	{
		flyBehavior = fb;
	}

	void set_quack_behavior(QuackBehavior *qb)
	{
		quackBehavior = qb;
	}
};


class ModelDuck :public Duck
{
public:
	ModelDuck()
	{
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	};

	void display()
	{
		cout << "I'm a model duck" << endl;
	}
};

int main(void)
{
	Duck *model = new ModelDuck();
	model->perform_fly();
	model->set_fly_behavior(new FlyRocketPowered());
	model->perform_fly();
	return 0;
}