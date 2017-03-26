from abc import ABC, abstractmethod


class Pizza(ABC):
    def __init__(self, name, dough, sauce):
        self.name = name
        self.dough = dough
        self.sauce = sauce
        self.toppings = []

    def prepare(self):
        print("Preparing {}".format(self.name))
        print("Tossing dough...")
        print("Adding sauce...")
        print("Adding toppings:")
        for i in self.toppings:
            print(" ".format(self.toppings[i]))

    def bake(self):
        print("Bake for 25 minutes at 350")

    def cut(self):
        print("Cutting the pizza into diagonal slices")

    def box(self):
        print("Place pizza in official PizzaStore box")

    def get_name(self):
        return self.name


class NYStyleCheesePizza(Pizza):
    def __init__(self, name, dough, sauce):
        self.name = name
        self.dough = dough
        self.sauce = sauce


class PizzaStore:
    def __init__(self):
        pass

    def order_pizza(self):
        pizza = create_pizza(type)


    @abstractmethod
    def create_pizza(self):
        pass