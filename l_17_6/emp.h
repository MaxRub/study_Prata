#ifndef EMP_H
#define EMP_H
#include <iostream>
#include <fstream>
#include <string>
class abstr_emp
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
              const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream &
    operator<<(std::ostream & os, const abstr_emp & e);
    //just displays first and last name
    virtual ~abstr_emp() = 0;        //virtual base class
    virtual void writeall(std::ofstream & fo);
    virtual void getall(std::ifstream & fi);
};
class employee : public abstr_emp
{
public:
    enum classkind{Employee, Manager, Fink, Highfink};
    employee();
    employee(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo);
    virtual void getall(std::ifstream & fi);
};
class manager : virtual public abstr_emp
{
public:
    int inchargeof;         //number of abstr_emps managed
protected:
    int InChargeOf() const { return inchargeof; }
    int & InChargeOf() { return inchargeof; }
public:
    manager();
    manager(const std::string & fn, const std::string & ln,
            const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo);
    virtual void getall(std::ifstream & fi);
};
class fink : virtual public abstr_emp
{
private:
    std::string reportsto;          //to whom fink reports
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void writeall(std::ofstream & fo);
    virtual void getall(std::ifstream & fi);
};
class highfink : public manager, public fink //management fink
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo,
             int ico);
    highfink(const abstr_emp & e, const std::string & rpo,
             int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void writeall(std::ofstream & fo);
    virtual void getall(std::ifstream & fi);
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif // EMP_H
