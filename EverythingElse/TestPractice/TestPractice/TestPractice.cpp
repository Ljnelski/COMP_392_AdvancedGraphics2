#include <iostream>
#include <vector>
#include "Car.hpp"

using namespace testPractice;

void TestCar()
{

	CarInfo info;
	info.manufacturer = "Honda";
	info.model = "CRV";
	info.price = 20000;
	info.year = 2015;
	info.markup = 0.05;
	int percent = 0;
	std::vector<Car*> lot{};
	int quantity = 10;
	std::cout << "Creating " << quantity << " cars\n";
	for (int i = 0; i < 10; i++)
	{
		percent++;
		percent %= 50;
		info.markup = percent / 100.0;
		lot.push_back(Car::CreateCar(info));
	}


	Car* carPtr;

	info.model = "Pilot";
	info.price = 15000;
	info.year = 2012;
	info.markup = 0.05;
	carPtr = Car::CreateCar(info);
	lot.push_back(carPtr);


	info.model = "RAV4";
	info.manufacturer = "Toyota";
	info.price = 10000;
	info.year = 2016;
	info.markup = 0.03;
	carPtr = Car::CreateCar(info);
	lot.push_back(carPtr);

	std::cout << "All the vehicles in the lot\n";
	int counter = 1;
	//3 mark for statements to give the required output
	for (size_t i = 0; i < lot.size(); i++)
	{
		std::cout << *lot[i] << "\n";
	}


	int begin = 2016, end = 2019;
	counter = 1;
	std::cout << "Vehicles between " << begin << " and " << end << "\n";
	//3 mark for statements to give the required output
	for (size_t i = 0; i < lot.size(); i++)
	{
		int year = lot[i]->getYear();
		if (year >= begin && year <= end)
		{
			std::cout << *lot[i] << "\n";
		}
	}

	counter = 1;
	std::cout << "Deallocating all the vehicles in the lot\n";
	//3 mark for statements to give the required output
	for (size_t i = 0; i < lot.size(); i++)
	{
		delete lot[i];
	}
}


void whiteBoardCarTest()
{
	std::vector<Car*> cars;

	CarInfo car1 = CarInfo();
	car1.manufacturer = "Honda";
	car1.model = "Civic";
	car1.price = 500.00;
	car1.markup = 0.05;
	car1.year = 2001;
	cars.push_back(Car::CreateCar(car1));

	CarInfo car2 = CarInfo();
	car2.manufacturer = "Kia";
	car2.model = "Rondo";
	car2.price = 0.0;
	car2.year = 2008;
	car2.markup = -0.02;
	cars.push_back(Car::CreateCar(car2));

	CarInfo car3 = CarInfo();
	car3.manufacturer = "Tesla";
	car3.model = "Model s";
	car3.price = 0.0;
	car3.year = 2021;
	car3.markup = 1.45;
	cars.push_back(Car::CreateCar(car3));


	CarInfo car4 = CarInfo();
	car4.manufacturer = "Kia";
	car4.model = "Rondo";
	car4.price = 0.0;
	car4.year = 2010;
	car4.markup = -0.02;
	cars.push_back(Car::CreateCar(car4));

	CarInfo car5 = CarInfo();
	car5.manufacturer = "Kia";
	car5.model = "Rondo";
	car5.price = 0.0;
	car5.year = 2018;
	car5.markup = 7.92;
	cars.push_back(Car::CreateCar(car5));

	CarInfo car6 = CarInfo();
	car6.manufacturer = "Honda";
	car6.model = "Civic";
	car6.price = 0.0;
	car6.year = 2013;
	car6.markup = 1.02;
	cars.push_back(Car::CreateCar(car6));


	CarInfo car7 = CarInfo();
	car7.manufacturer = "Nuffield Mechanisation and Aero";
	car7.model = "Tank, Cruiser, Mk VIII, Cromwell (A27M)";
	car7.price = 1250349.99;
	car7.year = 1945;
	car7.markup = 459.99;
	cars.push_back(Car::CreateCar(car7));

	CarInfo car8 = CarInfo();
	car8.manufacturer = "AMG Transport Dynamics";
	car8.model = " M12 Force Application Light Reconnaissance Vehicle";
	car8.price = 0.0;
	car8.year = 2469;
	car8.markup = -0.02;
	cars.push_back(Car::CreateCar(car8));

	CarInfo car9 = CarInfo();
	car9.manufacturer = "Carpenter John";
	car9.model = "Carrage";
	car9.price = 5.00;
	car9.year = 1456;
	car9.markup = -1045.34;
	cars.push_back(Car::CreateCar(car9));

	CarInfo car10 = CarInfo();
	car10.manufacturer = "Porsche";
	car10.model = "Panzerkampfwagen Tiger Ausf. B";
	car10.price = 2000000;
	car10.year = 1944;
	car10.markup = 128000.00;
	cars.push_back(Car::CreateCar(car10));


	std::cout << "Cars\n-------------\n";
	for (size_t i = 0; i < cars.size(); i++)
	{
		std::cout << *cars[i] << "\n";
		// > cars are only being printed once,
		// delete here so the vector is only looped through once
		// Im la
		delete cars[i];
	}
}


int main()
{
	TestCar();
}