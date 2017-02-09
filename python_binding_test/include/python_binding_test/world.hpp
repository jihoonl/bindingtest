

#ifndef __PYTHON_BINDING_TEST_WORLD_HPP__
#define __PYTHON_BINDING_TEST_WORLD_HPP__
#include<ros/ros.h>
#include<std_msgs/String.h>

class World
{
  public:
    World();
    World(std::string msg);
    void set(std::string msg);
    std::string greet();
  private:
    std::string msg;
};
#endif
