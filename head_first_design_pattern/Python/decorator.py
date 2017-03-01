from abc import ABC, abstractmethod


class Beverage(ABC):
    def __init__(self):
        self.description = "Unknown Beverage"

    def get_description(self):
        return self.description

    @abstractmethod
    def cost(self):
        pass


class CondimentDecorator(Beverage):
    @abstractmethod
    def get_description(self):
        pass


class Espresso(Beverage):
    def __init__(self):
        self.description = "Espresso"

    def cost(self):
        return 1.99


class HouseBlend(Beverage):
    def __int__(self):
        self.description = "House Blend Coffee"

    def cost(self):
        return 0.89


class Mocha(CondimentDecorator):
    def __init__(self, beverage):
        self.beverage = beverage

    def get_description(self):
        return self.beverage.get_description()+", Mocha"

    def cost(self):
        return 0.20 + self.beverage.cost()


beverage = Espresso()
print("{}${}".format(beverage.get_description(), beverage.cost()))

beverage2 = HouseBlend()
beverage2 = Mocha(beverage2)
beverage2 = Mocha(beverage2)
print("{}${}".format(beverage2.get_description(), beverage2.cost()))

