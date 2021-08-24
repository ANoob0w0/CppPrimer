#include <iostream>
#include <vector>
#include <memory>

#include "HasPtr.h"

using namespace std;

class numbered
{
private:
    int mysn;
    static int unique;

public:
    numbered() : mysn(++unique) {}
    numbered(const numbered &num) : mysn(++unique) {}
    int getSN() const { return mysn; }
    // numbered &operator=(const numbered &num)
    // {
    //     mysn = ++unique;
    //     return *this;
    // };
};
int numbered::unique = 10000;

class Employee
{
private:
    string name;
    int id;
    static int idctl;

public:
    Employee() : id(++idctl) {}
    Employee(const string &n) : name(n), id(++idctl)
    {
        cout << name << " " << id << endl;
    }
    ~Employee() = default;
    Employee &operator=(const Employee &) = delete;
};
int Employee::idctl = 100000;

inline void f(const numbered &n) { cout << n.getSN(); }

int main()
{
    

    // //13.18&19
    // Employee p1("john");
    // Employee p2;
    // p2 = p1;

    // //13.17
    // numbered a, b = a, c = b;
    // b = c;
    // f(a);
    // f(b);
    // f(c);

    // //13.13
    // // HasPtr hp1;
    // HasPtr hp2("hp2");
    // HasPtr hp3 = hp2;
    // // string s = "hpvec";
    // // vector<HasPtr> vhp(3, s);
    // auto hpptr = make_shared<HasPtr>(hp3);
}