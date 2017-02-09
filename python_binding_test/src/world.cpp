
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

void World::initialize(const dict data)
{
  params_["first"] = extract<double>(data["first"]);
  params_["second"] = extract<double>(data["second"]);
  params_["third"] = extract<double>(data["third"]);
}


void World::to_print()
{
  for (std::map<std::string, double>::iterator it=params_.begin(); it != params_.end(); ++it)
    std::cout << it->first << " : " << it->second << std::endl;
}

std::map<std::string, double> World::out()
{
  return params_;
}
