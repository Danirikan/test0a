#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	std::cout << "Hello world!" << "\n";

	std::cout << Module1::getMyName() << "\n";
	std::cout << Module2::getMyName() << "\n";

	{
		using namespace Module1; // использовать имена из Module1
		std::cout << getMyName() << "\n"; // (A) Вызов 'getMyName()' из Module1
		std::cout << Module2::getMyName() << "\n";
	}
	using namespace Module2; // (B) Можно предыдущее прострнанство имён Module1 объявить в отдельном блоке {...}
	std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)

	using Module2::getMyName; // 'getMyName' вызывать из Module2 
	std::cout << getMyName() << "\n"; // (D) Вызов и Module2

	cout << Module3::getMyName() << "\n";

	return 0;
}