#include <string>
#include "CarInfo.hpp"
namespace testPractice
{
	class Car
	{
	private:
		std::string _manufacturer;
		std::string _model;
		int _year;
		double _markup;
		static double MARKUP;

	private:
		Car();

	public:
		Car(std::string manufacturer, std::string model, int year);
		
		static Car* CreateCar(CarInfo info);
		friend std::ostream& operator<<(std::ostream&, const Car&);
		
		int getYear();
	};
}