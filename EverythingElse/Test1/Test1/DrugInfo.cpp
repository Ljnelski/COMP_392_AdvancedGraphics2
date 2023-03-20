#include <string>
namespace medical
{
	struct DrugInfo
	{
	public:
		std::string name;
		std::string otc_name;
		std::string unit;
		int quantity;
		int duration;
	};
}