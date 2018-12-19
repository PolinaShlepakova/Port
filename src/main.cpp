#include "port.h"
#include "vintage_port.h"

#include <iostream>
#include <cstring>

int main() {
	std::cout << "=== Port ===" << std::endl;
	Port p1;
	Port p2("Gallo", "tawny", 20);
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	p1.Show();
	p2.Show();

	std::cout << std::endl;
	p1 = p2;
	Port p3(p2);
	std::cout << p1 << std::endl;
	std::cout << p3 << std::endl;

	std::cout << std::endl;
	std::cout << "current: " << p3.BottleCount() << std::endl;
	p3 += 10;
	std::cout << "add 10: " << p3.BottleCount() << std::endl;
	p3 -= 10;
	std::cout << "subtract 10: " << p3.BottleCount() << std::endl;
	p3 -= 100;
	std::cout << "subtract 100: " << p3.BottleCount() << std::endl;
	p3 -= 20;
	std::cout << "subtract 20: " << p3.BottleCount() << std::endl;

	std::cout << std::endl << "=== Vintage Port ===" << std::endl;
	VintagePort vp1;
	VintagePort vp2("Hallo", 5, "The Noble", 1970);
	std::cout << vp1 << std::endl;
	std::cout << vp2 << std::endl;
	vp1.Show();
	vp2.Show();

	std::cout << std::endl;
	vp1 = vp2;
	VintagePort vp3(vp2);
	std::cout << vp1 << std::endl;
	std::cout << vp3 << std::endl;

	return 0;
}