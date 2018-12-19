#include "vintage_port.h"
#include <cstring>

constexpr char VintagePort::defaultNickname[];

VintagePort::VintagePort()
: Port("none", "vintage"), nickname(new char[strlen(defaultNickname) + 1]), year(0) {
	strcpy(nickname, defaultNickname);
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y): Port(br, "vintage", b), year(y) {
	if (nn != nullptr) {
		nickname = new char[strlen(nn) + 1];
		strcpy(nickname, nn);
	} else {
		delete[] nickname;
	}
}

VintagePort::VintagePort(const VintagePort& vp)
: Port(vp), nickname(new char[strlen(vp.nickname)]), year(vp.year) {
	strcpy(nickname, vp.nickname);
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
	if (this != &vp) {
		Port::operator=(vp);
		delete[] nickname;
		nickname = new char[strlen(vp.nickname) + 1];
		strcpy(nickname, vp.nickname);
		year = vp.year;
	}
	return *this;
}

void VintagePort::Show() const {
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {
	return os << static_cast<Port>(vp) << ", " << vp.nickname << ", " << vp.year;
}
