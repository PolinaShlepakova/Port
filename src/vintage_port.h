#ifndef VINTAGE_PORT_H
#define VINTAGE_PORT_H

#include "port.h"

class VintagePort : public Port { // style always == "vintage"
private:
    char* nickname; // like "The Noble", "Old Velvet", etc.
    int year; // year of bottling

    static constexpr char defaultNickname[] = "none";
public:
    VintagePort();
    VintagePort(const char* br, int b, const char* nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort() override { delete [] nickname; }

    VintagePort& operator=(const VintagePort& vp);
    void Show() const override;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp);
};

#endif // VINTAGE_PORT_H