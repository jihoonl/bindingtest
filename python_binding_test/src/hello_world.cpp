
#include <python_binding_test/hello.hpp>
#include <python_binding_test/world.hpp>
#include <python_binding_test/inherit.hpp>

#include <boost/python.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(hello)
{
  def("greet", greet);

  class_<World>("World")
    .def(init<std::string>())
    .def("greet", &World::greet)
    .def("set", &World::set)
    .def("initialize", &World::initialize)
    .def("to_print", &World::to_print)
//    .def("out", &World::out)
   ;

  class_<BaseWrapper, boost::noncopyable>("Base")
    .def("name", &Base::name)
    .def("basename", &Base::basename)
    .def("childname", &Base::childname, &BaseWrapper::default_childname)
    .def(self_ns::str(self_ns::self))
  ;

  class_<Derived, bases<Base> >("Derived")
  ;
}
