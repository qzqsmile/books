#include<iostream>

using namespace std;

class Light {
public:
	Light() {};
	void on() {
		cout <<"light on" << endl;
	}
	void off() {
		cout <<"light off"<< endl;
	}
};

class Command {
public:
	Command() {};
	virtual void execute() = 0;
};

class LightOnCommand :public Command {
public:
	Light* light;
	LightOnCommand(Light* light) { this->light = light; };
	void execute() {
		this->light->on();
	};
};

class SimpleRemoteControl{
public:
	Command* slot;
	SimpleRemoteControl() {};
	void set_command(Command * command) {
		this->slot = command;
	};
	void button_was_pressed() {
		this->slot->execute();
	};
};

int main(void) {
	SimpleRemoteControl * remote = new SimpleRemoteControl();
	Light* light = new Light();
	LightOnCommand * lighton = new LightOnCommand(light);

	remote->set_command(lighton);
	remote->button_was_pressed();
	while (1);

	return 0;
}