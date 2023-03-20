#pragma once

#include <string>
#include <ostream>
#include "DrugInfo.cpp"

namespace medical
{
	class Drug
	{
	private:
		int duration_;
		std::string name_;
		std::string otc_name_;
		int quantity_;
		std::string unit_;

		Drug();

	public:
		~Drug();
		static Drug* CreateDrug(const DrugInfo& DrugInfo);
		friend std::ostream& operator<<(std::ostream& os, const Drug& drug);
	};
}