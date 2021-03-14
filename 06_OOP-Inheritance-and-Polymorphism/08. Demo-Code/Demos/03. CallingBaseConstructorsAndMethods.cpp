#include <iostream>
#include <string>
#include <sstream>

class Vehicle {
protected:
	double speed;

	Vehicle(double speed) : speed(speed) {}


	std::string toString() const {
		std::ostringstream stream;
		stream << "speed: " << this->speed;
		return stream.str();
	}

public:
	virtual void stop(void) { speed = 0; }

	virtual void f(void) {
		std::cout << "from Vehicle" << std::endl;
	}

};

class Car : public Vehicle {
	bool parkingBrakeOn;
public:
	Car(double speed, bool parkingBrakeOn)
		: Vehicle(speed),
		parkingBrakeOn(parkingBrakeOn) {}

	virtual void stop(void) {
		Vehicle::stop();
		parkingBrakeOn = true;
	}

	std::string toString() const {
		std::ostringstream stream;
		stream << Vehicle::toString() << " parking brake: " << (this->parkingBrakeOn ? "yes" : "no");
		return stream.str();
	}

	virtual void f(void) {
		std::cout << "from Car" << std::endl;
	}

};

class Airplane : public Vehicle {
	double altitude;
	double heading;
public:
	Airplane(double speed, double altitude, double heading)
		: Vehicle(speed), altitude(altitude), heading(heading) {}

	virtual void stop(void) {
		Vehicle::stop();
		altitude = 0;
		heading = 0;
	}

	std::string toString() const {
		std::ostringstream stream;
		stream << Vehicle::toString() << this->speed << " altitude: " << this->altitude << " heading: " << this->heading;
		return stream.str();
	}
};

int main() {
	Car car(90, false);
	Airplane airplane(700, 10000, 90);

	Vehicle* v = &airplane;

	std::cout << car.toString() << std::endl;
	std::cout << airplane.toString() << std::endl;

	return 0;
}