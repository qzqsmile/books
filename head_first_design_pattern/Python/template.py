from abc import ABC, abstractmethod


class CaffeineBeverage(ABC):
    def __init__(self):
        pass

    def prepare_recipe(self):
        self.boil_water()
        self.brew()
        self.pour_in_cup()
        self.add_condiments()

    @abstractmethod
    def brew(self):
        pass

    @abstractmethod
    def add_condiments(self):
        pass

    def boil_water(self):
        print("Boiling water")

    def pour_in_cup(self):
        print("Pouring into cup")


class Tea(CaffeineBeverage):
    def __int__(self):
        pass

    def brew(self):
        print("Steeping the tea")

    def add_condiments(self):
        print("Adding Lemon")


class Coffee(CaffeineBeverage):
    def __init__(self):
        pass

    def brew(self):
        print("Dripping Coffee through filter")

    def add_condiments(self):
        print("Adding Sugar and Milk")

my_tea = Tea()
my_tea.prepare_recipe()
