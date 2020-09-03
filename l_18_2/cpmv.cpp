#include <iostream>
#include "cpmv.h"

int Cpmv::ct = 0;

Cpmv::Cpmv() : pi(nullptr)
{
    ++ct;
    std::cout << "default constructor called; number of objects: "
              << ct << std::endl;
}
Cpmv::Cpmv(std::string q, std::string z)
{
    ++ct;
    std::cout << "string, string constructor called; number"
                 " of objects: " << ct << std::endl;
    pi = new Info;
    pi->qcode = q;
    pi->zcode = z;

}
Cpmv::Cpmv(const Cpmv & cp)
{
    ++ct;
    std::cout << "copy const constructor called; number"
                 " of objects: " << ct << std::endl;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
}
Cpmv::Cpmv(Cpmv && mv)
{
    ++ct;
    std::cout << "move constructor called; number"
                 " of objects: " << ct << std::endl;
    pi = mv.pi;
    mv.pi = nullptr;
}
Cpmv::~Cpmv()
{
    std::cout << "destructor called; objects left: " << --ct
              << std::endl;
    delete pi;
}
Cpmv & Cpmv::operator=(const Cpmv & cp)
{
    std::cout << "copy assignment operator called:\n";
    if (this == &cp)
        return *this;
    delete pi;
    pi = new Info;
    pi->qcode = cp.pi->qcode;
    pi->zcode = cp.pi->zcode;
    return *this;
}
Cpmv & Cpmv::operator=(Cpmv && mv)
{
    std::cout << "move assignment operator called:\n";
    if (this == &mv)
        return *this;
    delete pi;
    pi = mv.pi;
    mv.pi = nullptr;
    return *this;
}
Cpmv Cpmv::operator+(const Cpmv & obj) const
{
    std::cout << "Entering operator+()\n";
    Cpmv temp;                  //default constructor called
    delete temp.pi;
    temp.pi = new Info;
    temp.pi->qcode = pi->qcode + obj.pi->qcode;
    temp.pi->zcode = pi->zcode + obj.pi->zcode;
    std::cout << "Living operator+()\n";
    return temp;
}
void Cpmv::Display() const
{
    std::cout << "Qcode: " << pi->qcode << std::endl;
    std::cout << "Zcode: " << pi->zcode << std::endl;
}
