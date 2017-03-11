from abc import ABC, abstractmethod


class Duck(ABC):
    def quack(self):
        pass

    def fly(self):
        pass


class MallardDuck(Duck):
    def quack(self):
        print("Quack")

    def fly(self):
        print("I'm flying")


class Turkey(ABC):
    def gobble(self):
        pass

    def fly(self):
        pass


class WildTurkey(Turkey):
    def gobble(self):
        print("Gobble google")

    def fly(self):
        print("I'm flying a short distance")

#object adaptive
class TurkeyAdapter(Duck):
    def __init__(self, turkey):
        self.turkey = turkey

    def quack(self):
        self.turkey.gobble()

    def fly(self):
        for i in range(0, 5):
            self.turkey.fly()


def test_duck(duck):
    duck.quack()
    duck.fly()

duck = MallardDuck()
turkey = WildTurkey()
turkeyAdapter = TurkeyAdapter(turkey)

print("The Turkey says...")
turkey.gobble()
turkey.fly()

print("The Duck says...")
test_duck(duck)

print("The TurkeyAdapter says..")
test_duck(turkeyAdapter)