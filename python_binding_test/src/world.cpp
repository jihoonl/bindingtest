
#include<python_binding_test/world.hpp>

World::World() {}

World::World(std::string msg) : msg(msg) {}

void World::set(std::string msg)
{
  this->msg = msg;
}

std::string World::greet()
{
  return msg;
}
