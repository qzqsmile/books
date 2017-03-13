#include<iostream>
#include"command.h"

using namespace std;



Command::Command() {};
LightOnCommand::LightOnCommand(Light* light) {
	this->light = light;
}

void LightOnCommand::execute() {
	this->light->on();
}

SimpleRemoteControl::SimpleRemoteControl() {};
void SimpleRemoteControl::set_command(Command* command) {
	this->slot = command;
};

void SimpleRemoteControl::button_was_pressed() {
	this->slot->execute();
};

Light::Light() {};
void Light::on() {
	cout << "light on" << endl;
};
void Light::off() {
	cout << "light off" << endl;
};
