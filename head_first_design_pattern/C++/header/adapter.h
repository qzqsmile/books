#pragma once

class Duck {
public:
	virtual void quack() = 0;
	virtual void fly() = 0;
};

class MallardDuck :public Duck {
public:
	void quack();
	void fly();
};

class Turkey {
public:
	void gobble();
	void fly();
};

class WildTurkey :public Turkey {
public:
	void gobble();
	void fly();
};

class TurkeyAdapter :public Duck {
public:
	Turkey * turkey;
	TurkeyAdapter(Turkey* turkey);
	void quack();
	void fly();
};