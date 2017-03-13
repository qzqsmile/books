# This file can not be executed


class Amplifier:
    pass


class Tuner:
    pass


class DvdPlayer:
    pass


class CdPlayer:
    pass


class Projector:
    pass


class TheaterLights:
    pass


class HomeTheaterFacade:
    def __init__(self, amp, tuner, dvd, cd, projector):
        self.amp = amp
        self.tuner = tuner
        self.dvd = dvd
        self.cd = cd
        self.projector = projector

    def watch_movie(self):
        # some action of tmp, tunner, dvd, cd, projector
        pass

    def end_movie(self):
        # some action of tmp, tunner, dvc, cd, projector
        pass

