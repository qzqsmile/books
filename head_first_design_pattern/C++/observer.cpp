#include<iostream>
#include<vector>

using namespace std;

// interface
class Observer {
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class Subject {
public:
	virtual void register_observer(Observer* o) = 0;
	virtual void remove_observer(Observer *o) = 0;
	virtual void notify_observers() = 0;
};

class DisplayElement {
public:
	virtual void display() = 0;
};


class  WeatherData :public Subject {
private:
	vector<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;

public:
	WeatherData() {};
	void register_observer(Observer *o) {
		observers.push_back(o);
	};
	
	void remove_observer(Observer *o) {
		vector<Observer *> ::iterator index;
		if ((index = find(observers.begin(), observers.end(), o)) != observers.end()){
			observers.erase(index);
		}
	};

	void notify_observers() {
		for (int i = 0; i < observers.size(); i++) {
			observers[i]->update(temperature, humidity, pressure);
		}
	};

	void measurements_changed() {
		notify_observers();
	};

	void set_measurements(float temperature, float humidity, float pressure){
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurements_changed();
	};
};

class CurrentConditionsDisplay :public Observer, DisplayElement {
private:
	float temperature;
	float humidity;
	Subject * weatherData;

public:
	CurrentConditionsDisplay(Subject * weatherData) {
		this->weatherData = weatherData;
		weatherData->register_observer(this);
	};

	void update(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;
		display();
	}

	void display() {
		cout <<"Current conditions:" << temperature << "F degrees and"<< humidity << endl;
	}
};

class StatisticsDisplay :public Observer, DisplayElement {
private:
	float temperature;
	float humidity;
	Subject * weatherData;

public:
	StatisticsDisplay(Subject * weatherData) {
		this->weatherData = weatherData;
		weatherData->register_observer(this);
	};

	void update(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;
		display();
	}

	void display() {
		cout << "StatisticsDisplay conditions:" << temperature << "F degrees and" << humidity << endl;
	}
};


int main(void)
{
	WeatherData *weather_data = new WeatherData();
	CurrentConditionsDisplay * current_display = new CurrentConditionsDisplay(weather_data);
	StatisticsDisplay* statistics_display = new StatisticsDisplay(weather_data);

	weather_data->set_measurements(80, 65, 30.4);
	while (1);

	return 0;
}