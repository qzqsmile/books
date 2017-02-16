from abc import ABC, abstractmethod


# interface
class FlyBehavior(ABC):
    @abstractmethod
    def fly(self):
        pass


class QuackBehavior(ABC):
    @abstractmethod
    def quack(self):
        pass


# behavior
class Fly(FlyBehavior):
    def fly(self):
        print("Fly")


class FlyNoWay(FlyBehavior):
    def fly(self):
        print("I can't fly")


class FlyRocketPowered(FlyBehavior):
    def fly(self):
        print("I'm flying with a rocket!")


class Quack(QuackBehavior):
    def quack(self):
        print("Quack")


class MuteQuack(QuackBehavior):
    def quack(self):
        print("<< Silence >>")


class Squeak(QuackBehavior):
    def quack(self):
        print("Squeak")


class Duck(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def display(self):
        pass

    def swim(self):
        print("All ducks float, even decoys!")

    def perform_fly(self):
        self.fly_behavior.fly()

    def perfrom_quack(self):
        self.quack_behavior.quack()

    def set_fly_behavior(self, fb):
        self.fly_behavior= fb

    def set_quack_behavior(self, qb):
        self.quack_behavior = qb


class ModelDuck(Duck):
    def __init__(self):
        self.fly_behavior = FlyNoWay()
        self.quack_behavior = Quack()
        pass

    def display(self):
        print("I'm a model duck")

model = ModelDuck()
model.perform_fly()
model.set_fly_behavior(FlyRocketPowered())
model.perform_fly()