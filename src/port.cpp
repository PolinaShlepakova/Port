#include "port.h"
#include <cstring>

Port::Port(const char* br, const char* st, int b): bottles(b) {
	if (br != nullptr) {
		brand = new char[strlen(br) + 1];
		strcpy(brand, br);
	}
	if (st != nullptr) {
		size_t stLen = strlen(st);
		if (stLen < styleLimit) {
			strcpy(style, st);
		} else {
			strncpy(style, st, styleLimit - 1);
			style[styleLimit - 1] = '\0';
		}
	}
}

Port::Port(const Port& p): brand(new char[strlen(p.brand) + 1]), bottles(p.bottles) {
	strcpy(brand, p.brand);
	strcpy(style, p.style);
}

Port& Port::operator=(const Port& p) {
	if (this != &p) {
		delete[] brand;
		brand = new char[strlen(p.brand) + 1];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
		bottles = p.bottles;
	}
	return *this;
}

// adds b to bottles
Port& Port::operator+=(int b) {
	bottles += b;
	return *this;
}

// subtracts b from bottles, if possible
Port& Port::operator-=(int b) {
	if (b <= bottles) {
		bottles -= b;
	}
	return *this;
}

void Port::Show() const {
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p) {
	return os << p.brand << ", " << p.style << ", " << p.bottles;
}

