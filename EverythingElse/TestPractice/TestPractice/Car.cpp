#include "Car.hpp"
#include <iostream>

namespace testPractice
{
	double Car::MARKUP = 0.02;

	Car::Car(std::string manufacturer, std::string model, int year)
		:_manufacturer{ manufacturer }, _model{ model }, _year{ year }
	{
		_markup = MARKUP;
	}

	Car* Car::CreateCar(CarInfo carInfo)
	{
		Car* newCar = new Car(carInfo.manufacturer, carInfo.model, carInfo.year);
		// newCar->_markup += carInfo.markup;
		(*newCar)._markup += carInfo.markup;
		return newCar;
	}

	int Car::getYear()
	{
		return _year;
	}

	std::ostream& operator<<(std::ostream& os, const Car& rhs)
	{
		os << rhs._manufacturer << " <-> " << rhs._model << ", " << rhs._year << ", Markup: " << rhs._markup;
		return os;
	}
}


