#include <iostream>
#include "emp.h"
//abstr_emp method
abstr_emp::abstr_emp() : fname("no one"), lname("no one"),
    job("not") {

}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
                     const std::string & j) : fname(fn), lname(ln), job(j) {

}
void abstr_emp::ShowAll() const
{
    std::cout << "First name:\t" << fname << "\nLast name:\t"
              << lname << "\nPosition:\t" << job << std::endl;
}
void abstr_emp::SetAll()
{
    std::cout << "Enter first name: ";
    std::cin >> fname;
    std::cout << "and last name: ";
    std::cin >> lname;
    std::cout << "Enter position: ";
    std::cin >> job;
}
std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.fname << " " << e.lname ;
    return os;
}
abstr_emp::~abstr_emp() {

}
//employee method
employee::employee(): abstr_emp() {

}
employee::employee(const std::string & fn, const std::string & ln,
                   const std::string & j) : abstr_emp(fn, ln, j) {

}
void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    abstr_emp::SetAll();
}
//manager method
manager::manager() : abstr_emp(), inchargeof(0) {

}
manager::manager(const std::string & fn, const std::string & ln,
        const std::string & j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {

}
manager::manager(const abstr_emp & e, int ico)
    : abstr_emp(e), inchargeof(ico) {

}
manager::manager(const manager & m) :abstr_emp(m), inchargeof(m.inchargeof) {

}
void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "in charge of " << InChargeOf() << ".\n";
}
void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "How many people in his charge: ";
    std::cin >> InChargeOf();
}
//fink method
fink::fink() : abstr_emp(), reportsto("no one") {

}
fink::fink(const std::string & fn, const std::string & ln,
     const std::string & j, const std::string & rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {

}
fink::fink(const abstr_emp & e, const std::string & rpo)
    : abstr_emp(e), reportsto(rpo) {

}
fink::fink(const fink & e)
    : abstr_emp(e), reportsto(e.reportsto) {

}
void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reports to " << ReportsTo() << ".\n";
}
void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Reports to: ";
    std::cin >> ReportsTo();
}
//highfink method
highfink::highfink() : abstr_emp(), manager(), fink() {

}
highfink::highfink(const std::string & fn, const std::string & ln,
    const std::string & j, const std::string & rpo, int ico)
    : abstr_emp(fn, ln, j), manager(fn, ln, j, ico),
      fink(fn, ln, j, rpo) {

}
highfink::highfink(const abstr_emp & e, const std::string & rpo,
                   int ico) : abstr_emp(e), manager(e, ico),
                   fink(e, rpo) {

}
highfink::highfink(const fink & f, int ico)
    : abstr_emp(f), manager(f, ico), fink(f) {

}
highfink::highfink(const manager & m, const std::string & rpo)
    : abstr_emp(m), manager(m), fink(m, rpo) {

}
highfink::highfink(const highfink & h) : abstr_emp(h),
    manager(h), fink(h) {

}
void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "in charge of " << InChargeOf() << ".\n";
    std::cout << "Reports to " << ReportsTo() << ".\n";
}
void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "How many people in his charge: ";
    std::cin >> InChargeOf();
    std::cout << "Reports to: ";
    std::cin >> ReportsTo();
}
