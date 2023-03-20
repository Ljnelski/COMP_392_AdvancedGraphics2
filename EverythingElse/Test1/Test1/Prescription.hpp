#pragma once

#include <vector>
#include "Drug.hpp"
namespace medical
{
	class Prescription
	{
	private:
		std::vector<Drug*> drugs_;
		std::string patient_;
		std::string docter_;
	public:
		Prescription(std::string docter, std::string patient);
		~Prescription();

		std::string GetDocter();
		std::string GetPatient();
		std::vector<Drug*> GetDrugs();
		void AddDrug(Drug* ptr);

		friend std::ostream& operator<<(std::ostream& os, const Prescription& prescription);
	};
}