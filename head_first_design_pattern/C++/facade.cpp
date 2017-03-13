#include"facade.h"

class Amplifier {};

class Tunner {};

class DvdPlayer {};

class CdPlayer {};

class Projector {};

class HomeTheaterFacade {
public:
	HomeTheaterFacade(Amplifier *amp, Tunner* tunner, DvdPlayer* dvd, CdPlayer* cd) {};
	void watch_movie() {
	// some action of movie
	};

	void end_movie() {
	// some action of tmp, tunner, dvc
	}
};