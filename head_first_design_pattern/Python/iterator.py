from abc import ABC, abstractmethod


class Iterator(ABC):
    @abstractmethod
    def has_next(self):
        pass
    @abstractmethod
    def next(self):
        pass


class DinerMenuIterator(Iterator):
    def __init__(self, items=[]):
        self.items = items
        self.position = 0

    def next(self):
        menuItem = self.items[self.position]
        self.position = self.position + 1
        return menuItem

    def has_next(self):
        if self.position >= len(self.items):
            return False
        else:
            return True


class MenuItem:
    def __init__(self, name, description, vegetarian, price):
        self.name = name
        self.description = description
        self.vegetarian = vegetarian
        self.price = price

    def get_name(self):
        return self.name

    def get_description(self):
        return self.description

    def get_price(self):
        return self.price

    def is_vegetarian(self):
        return self.vegetarian


class PancakeHouseMenuIterator(Iterator):
    def __init__(self, items=[]):
        self.items = items
        self.position = 0

    def next(self):
        menu_item = self.items[self.position]
        self.position = self.position + 1
        return menu_item

    def has_next(self):
        if self.position >= len(self.items):
            return False
        else:
            return True


class DinnerMenu:
    def __init__(self):
        self.menu_items = []
        self.number_of_items = 0
        self.add_item('Vegetarian', 'Bacon with lettuce', True, 2.99)
        self.add_item('BLT', 'Bacon with lettuce & tomato', False, 2.99)
        self.add_item('Hotdog', "A hot dog", False, 3.05)

    def add_item(self, name, description, vegetarian, price):
        menu_item = MenuItem(name, description, vegetarian, price)
        self.menu_items.append(menu_item)

    def get_menu_items(self):
        return self.menu_items

    def create_iterator(self):
        return DinerMenuIterator(self.menu_items)


class PancakeHouseMenu:
    def __init__(self):
        self.menu_items = []
        self.number_of_items = 0
        self.add_item('Vegetarian', 'Bacon with lettuce', True, 2.99)
        self.add_item('BLT', 'Bacon with lettuce & tomato', False, 2.99)
        self.add_item('Hotdog', "A hot dog", False, 3.05)

    def add_item(self, name, description, vegetarian, price):
        menu_item = MenuItem(name, description, vegetarian, price)
        self.menu_items.append(menu_item)

    def create_iterator(self):
        return PancakeHouseMenuIterator(self.menu_items)


class Waitress:
    def __init__(self, pancake_house_menu, dinner_menu):
        self.pancake_house_menu =pancake_house_menu
        self.dinner_menu = dinner_menu

    def print_menu(self, iterator=None):
        if iterator is None:
            pancake_iterator = self.pancake_house_menu.create_iterator()
            dinner_iterator = self.dinner_menu.create_iterator()
            print("MENU\n-----\nBREAKFAST")
            self.print_menu(pancake_iterator)
            print("\nLUNCH")
            self.print_menu(dinner_iterator)
        else:
            while iterator.has_next():
                menu_item = iterator.next()
                print(menu_item.get_name() + ",")
                print(menu_item.get_price())
                print(menu_item.get_description())


pancake_house_menu = PancakeHouseMenu()
dinner_menu = DinnerMenu()
waitress = Waitress(pancake_house_menu, dinner_menu)
waitress.print_menu()