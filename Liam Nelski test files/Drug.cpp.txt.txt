#include "Drug.hpp"


namespace medical
{
	medical::Drug::Drug()
	{
	}

	medical::Drug::~Drug()
	{
	}

	Drug* medical::Drug::CreateDrug(const DrugInfo& drugInfo)
	{
		Drug* newDrug = new Drug();

		newDrug->name_ = drugInfo.name;
		newDrug->otc_name_ = drugInfo.otc_name;
		newDrug->unit_ = drugInfo.unit;
		newDrug->quantity_ = drugInfo.quantity;
		newDrug->duration_ = drugInfo.duration;

		return newDrug;
	}

	std::ostream& medical::operator<<(std::ostream& os, const Drug& drug)
	{
		os << drug.name_ << " " << drug.quantity_ << " " << drug.unit_ << " for " << drug.duration_ << "days";
		return os;
	}
}