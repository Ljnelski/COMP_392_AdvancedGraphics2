#include "Prescription.hpp"

namespace medical
{
	Prescription::Prescription(std::string docter, std::string patient)
		: docter_{ docter }, patient_{ patient }
	{

	}

	Prescription::~Prescription()
	{
	}

	std::string Prescription::GetDocter()
	{
		return docter_;
	}

	std::string Prescription::GetPatient()
	{
		return patient_;
	}

	std::vector<Drug*> Prescription::GetDrugs()
	{
		return drugs_;
	}

	void Prescription::AddDrug(Drug* ptr)
	{
		drugs_.push_back(ptr);
	}

	std::ostream& operator<<(std::ostream& os, const Prescription& prescription)
	{
		int drugCount = prescription.drugs_.size();
		for (size_t i = 0; i < drugCount; i++)
		{
			os << "     " << *prescription.drugs_[i] << "\n";
		}

		return os;
	}
}
