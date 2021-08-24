#include <string>
#include <iostream>

class HasPtr
{
private:
    std::string *ps;
    int i;

public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s)), i(0)
    {
        std::cout << "HasPtr(const std::string &s = std::string())" << std::endl;
    }
    HasPtr(const HasPtr &hp)
        : ps(new std::string(*hp.ps)), i(hp.i)
    {
        std::cout << "operator=(const HasPtr& hp)" << std::endl;
    } //copy constructor
    HasPtr &operator=(const HasPtr &hp);
    ~HasPtr()
    {
        std::cout << "~HasPtr" << std::endl;
        delete ps;
    }
};

inline HasPtr &HasPtr::operator=(const HasPtr &hp)
{
    std::cout << "operator=(const HasPtr& hp)" << std::endl;
    this->i = hp.i;
    this->ps = new std::string(*hp.ps);
    return *this;
}