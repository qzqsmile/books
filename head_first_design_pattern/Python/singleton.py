class Singleton:
    def __init__(self):
        self.unique_instance = None

    def get_instance(self):
        if self.unique_instance is None:
            self.unique_instance = Singleton()
        return self.unique_instance
