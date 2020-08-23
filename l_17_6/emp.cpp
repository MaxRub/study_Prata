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
void abstr_emp::writeall(std::ofstream & fo)
{
    fo << "First name: ";
    fo << fname << std::endl;
    fo << "Last name: ";
    fo << lname << std::endl;
    fo << "Position: ";
    fo << job << std::endl;
}
void abstr_emp::getall(std::ifstream & fi)
{
    fi.ignore(255, ':');
    fi.ignore(1);
    std::getline(fi, fname);
    fi.ignore(255, ':');
    fi.ignore(1);
    std::getline(fi, lname);
    fi.ignore(255, ':');
    fi.ignore(1);
    std::getline(fi, job);
}
//employee method
employee::employee(): abstr_emp() {

}
employee::employee(const std::string & fn, const std::string & ln,
                   const std::string & j) : abstr_emp(fn, ln, j) {

}
void employee::ShowAll() const
{
    std::cout << "\tEmployee:\n";
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    abstr_emp::SetAll();
}
void employee::writeall(std::ofstream & fo)
{
    fo << employee::Employee << std::endl;
    abstr_emp::writeall(fo);
}
void employee::getall(std::ifstream & fi)
{
    abstr_emp::getall(fi);
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
    std::cout << "\tManager:\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << InChargeOf() << ".\n";
}
void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "How many people in his charge: ";
    std::cin >> InChargeOf();
}
void manager::writeall(std::ofstream & fo)
{
    fo << employee::Manager << std::endl;
    abstr_emp::writeall(fo);
    fo << "In charge of: ";
    fo << InChargeOf() << std::endl;
}
void manager::getall(std::ifstream & fi)
{
    abstr_emp::getall(fi);
    fi.ignore(255, ':');
    fi.ignore(1);
    fi >> inchargeof;
    fi.get();
}
//fink method
fink::fink() : abstr_emp(), reportsto("no one") {

}
fink::fink(const std::string & fn, const std::string & ln,
     const std::string & j, const std::string & rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo) {

}
fink::fink(const abstr_emp &e, const std::string & rpo)
    : abstr_emp(e), reportsto(rpo) {

}
fink::fink(const fink & e)
    : abstr_emp(e), reportsto(e.reportsto) {

}
void fink::ShowAll() const
{
    std::cout << "\tFink:\n";
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << ReportsTo() << ".\n";
}
void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cin.get();
    std::cout << "Reports to: ";
    std::getline(std::cin, ReportsTo());
}
void fink::writeall(std::ofstream & fo)
{
    fo << employee::Fink << std::endl;
    abstr_emp::writeall(fo);
    fo << "Reports to: " << ReportsTo() << "\n";
}
void fink::getall(std::ifstream & fi)
{
    abstr_emp::getall(fi);
    fi.ignore(255, ':');
    std::getline(fi, ReportsTo());
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
    std::cout << "\tHighfink:\n";
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << InChargeOf() << ".\n";
    std::cout << "Reports to: " << ReportsTo() << ".\n";
}
void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "How many people in his charge: ";
    std::cin >> InChargeOf();
    std::cin.get();
    std::cout << "Reports to: ";
    std::getline(std::cin, ReportsTo());
}
void highfink::writeall(std::ofstream & fo)
{
    fo << employee::Highfink << std::endl;
    abstr_emp::writeall(fo);
    fo << "In charge of: ";
    fo << InChargeOf() << std::endl;
    fo << "Reports to: ";
    fo << ReportsTo() << std::endl;
}
void highfink::getall(std::ifstream & fi)
{
    abstr_emp::getall(fi);
    fi.ignore(255, ':');
    fi >> inchargeof;
    fi.get();
    fi.ignore(255, ':');
    fi.ignore(1);
    std::getline(fi, ReportsTo());
}
