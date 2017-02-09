#ifndef __PYTHON_BINDING_TEST_INHERIT_HPP__
#define __PYTHON_BINDING_TEST_INHERIT_HPP__

#include <iostream>
#include <string>
#include <boost/python.hpp>

using namespace boost::python;

class Base
{
public:
    virtual std::string name() const { return "Base"; }
    virtual std::string basename() const { return "My Base"; }
    virtual ~Base() {}

    virtual std::string childname() const { return "Noinheritance"; };
};

struct BaseWrapper : Base, wrapper<Base>
{
  virtual std::string childname() const {
    if (override n = this->get_override("childname"))
      return n();
     return Base::childname();
  }

  std::string default_childname() const {
    return this->Base::childname();
  }
};

class Derived : public Base
{
public:
    virtual std::string name() const { return "Derived"; }
    virtual std::string childname() const { return "Child Derived"; }
};


std::ostream& operator << (std::ostream& out, const Base& b)
{
  out << "Name       : " << b.name() << std::endl;
  out << "Base Name  : " << b.basename() << std::endl;
  out << "Child Name : " << b.childname() << std::endl;
  return out;
}

#endif
