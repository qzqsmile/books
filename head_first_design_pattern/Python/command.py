from abc import ABC, abstractmethod


class Light:
    def __init__(self):
        pass

    def on(self):
        print("light on")

    def off(self):
        print("light off")


# command class like an abstract level
class Command(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def execute(self):
        pass


class LightOnCommand(Command):
    def __init__(self, light):
        self.light = light

    def execute(self):
        self.light.on()


class SimpleRemoteControl:
    def __init__(self):
        self.slot = None

    def set_command(self, command):
        self.slot = command

    def button_was_pressed(self):
        self.slot.execute()


remote = SimpleRemoteControl()
light = Light()
lighton = LightOnCommand(light)

remote.set_command(lighton)
remote.button_was_pressed()