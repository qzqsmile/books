from abc import ABC, abstractmethod


# interfaces
class Subject(ABC):
    @abstractmethod
    def register_observer(self, o):
        pass

    @abstractmethod
    def remove_observer(self, o):
        pass

    @abstractmethod
    def notify_observers(self, o):
        pass


class Observer(ABC):
    @abstractmethod
    def update(self, temp, humidity, pressure):
        pass


class DisplayElement(ABC):
    @abstractmethod
    def display(self):
        pass


class WeatherDate(Subject):
    observers = []

    def __init__(self):
        self.temperature = 0
        self.humidity = 0
        self.pressure = 0
        pass

    def register_observer(self, o):
        self.observers.append(o)

    def remove_observer(self, o):
        if o in self.observers:
            self.observers.remove(o)

    def notify_observers(self):
        for x in self.observers:
            x.update(self.temperature, self.humidity, self.pressure)

    def measurements_changed(self):
        self.notify_observers()

    def set_measurements(self, temperature, humidity, pressure):
        self.temperature = temperature
        self.humidity = humidity
        self.pressure = pressure
        self.measurements_changed()


class CurrentConditionsDisplay(DisplayElement):
    def __init__(self, weather_data):
        self.temperature = 0
        self.humidity = 0
        self.pressure = 0
        self.weather = weather_data
        weather_data.register_observer(self)

    def update(self, temperature, humidity, pressure):
        self.temperature = temperature
        self.humidity = humidity
        self.pressure = pressure
        self.display()

    def display(self):
        print("Current conditions {} F degrees and {} humidity".format(self.temperature, self.humidity))


class StatisticsDisplay(DisplayElement):
    def __init__(self, weather_data):
        self.temperature = 0
        self.humidity = 0
        self.pressure = 0
        self.weather = weather_data
        weather_data.register_observer(self)

    def update(self, temperature, humidity, pressure):
        self.temperature = temperature
        self.humidity = humidity
        self.pressure = pressure
        self.display()

    def display(self):
        print("Statistics conditions {} F degrees and {} humidity".format(self.temperature, self.humidity))

weather_data = WeatherDate()
current_display = CurrentConditionsDisplay(weather_data)
statistics_display = StatisticsDisplay(weather_data)
weather_data.set_measurements(80, 65, 30.4)