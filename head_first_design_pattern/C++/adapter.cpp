#include"adapter.h"
#include<iostream>

using namespace std;

void MallardDuck::quack() {
	cout <<"Quack"<< endl;
}

void MallardDuck::fly() {
	cout << "I'm flying" << endl;
}

void WildTurkey::gobble() {
	cout <<"Gobble google"<< endl;
}

void WildTurkey::fly() {
	cout <<"I'm flying a short distance"<< endl;
}

TurkeyAdapter::TurkeyAdapter(Turkey* turkey) {
	this->turkey = turkey;
};

void TurkeyAdapter::quack() {
	this->turkey->gobble();
};

void TurkeyAdapter::fly() {
	this->turkey->fly();
}

void Turkey::gobble() {
	cout << "In" << endl;
};
void Turkey::fly() {};