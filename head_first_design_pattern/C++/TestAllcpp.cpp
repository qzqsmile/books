#include<iostream>
#include"command.h"
#include"adapter.h"

using namespace std;

void test_command();
void test_adapter();

void test_command()
{
	SimpleRemoteControl * remote = new SimpleRemoteControl();
	Light* light = new Light();
	LightOnCommand * lighton = new LightOnCommand(light);

	remote->set_command(lighton);
	remote->button_was_pressed();
}

void test_adapter() {	
	// not work
	Duck *duck = new MallardDuck();
	WildTurkey * turkey = new WildTurkey();
	Duck * turkeyAdapter = new TurkeyAdapter(turkey);
	cout <<"The Turkey says.."<< endl;
	turkey->gobble();
	turkey->fly();
	cout << "The Duck says..."<< endl;
	duck->quack();
	duck->fly();
	cout <<"The TurkeyAdapter says"<< endl;
	turkeyAdapter->quack();
	turkeyAdapter->fly();
	while (1);
}

int main(void)
{
	//test_command();
	test_adapter();

	return 0;
}