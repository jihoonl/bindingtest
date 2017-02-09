

#ifndef __PYTHON_BINDING_TEST_WORLD_HPP__
#define __PYTHON_BINDING_TEST_WORLD_HPP__
#include<ros/ros.h>
#include<std_msgs/String.h>

#include <boost/python.hpp>

using namespace boost::python;


class World
{
  public:
    World();
    World(std::string msg);
    void set(std::string msg);
    std::string greet();

    void initialize(const dict data);
    void to_print();
    //std::map<std::string, double> out();
  private:
    std::string msg;
    std::map<std::string, double> params_;
};
#endif
