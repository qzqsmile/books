#pragma once

class Light {
public:
	Light();
	void on();
	void off();
};

class Command {
public:
	Command();
	virtual void execute() = 0;
};

class LightOnCommand :public Command {
public:
	Light* light;
	LightOnCommand(Light* light);
	void execute();
};

class SimpleRemoteControl {
public:
	Command* slot;
	SimpleRemoteControl();
	void set_command(Command * command);
	void button_was_pressed();
};