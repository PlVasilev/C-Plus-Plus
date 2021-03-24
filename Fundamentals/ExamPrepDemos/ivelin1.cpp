#include <map>
#include <string>
#include <sstream>

using namespace std;

class Sale {

private:

	std::string town, product;
	double price, quantity;

	std::map<std::pair<std::string, std::string>, std::pair<double, double>> x;
	// Това което искам да направя е да разделя мапа на town, product, price и quantity.
	std::map<std::pair<std::string, std::string>, std::pair<double, double>>::iterator s = x.begin();
public:

	Sale(std::string town, std::string product, double
		price, double quantity) :
		town(town), product(product), price(price), quantity(quantity)
	{
		/*
		Проблемът ми тук е , че искам да търся в първия pair , първия string, а ми излизат 2 грешки,

				Severity	Code	Description	Project	File	Line	Suppression State
				Error (active)	E0349	no operator "!=" matches these operands	Cpp_problems	C:\Users\Ivo\source\repos\Cpp_problems\Cpp_problems\Cpp_problems.cpp	23

				Severity	Code	Description	Project	File	Line	Suppression State
				Error	C2677	binary '!=': no global operator found which takes type 'std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const std::pair<std::string,std::string>,std::pair<double,double>>>>>' (or there is no acceptable conversion)	Cpp_problems	C:\Users\Ivo\source\repos\Cpp_problems\Cpp_problems\Cpp_problems.cpp	24

			Надявам се, че някой може да ми обясни как мога да го направя по правилен начин.

		*/
		if (s->first.first.find(product) != x.end())

			x.insert({ {town, product}, {price, quantity} });

	}

	string Print()
	{
		std::ostringstream output;

		output << this->town << " -> " << this->quantity *
			this->price;
	}

};