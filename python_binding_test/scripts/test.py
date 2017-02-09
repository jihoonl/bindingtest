#!/usr/bin/env python

import python_binding_test.hello as hello


class PythonDerived(hello.Base):
    def childname(self):
        return "Python Derived"

if __name__ == '__main__':

    print 'Hello World'
    p = PythonDerived()
    print str(p)

    a = hello.Derived()
    print str(a)
