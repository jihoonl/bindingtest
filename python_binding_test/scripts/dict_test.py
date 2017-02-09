#!/usr/bin/env python

import python_binding_test.hello as hello


w = hello.World()
mydict = {}
mydict['first'] = 0.122
mydict['second'] = 2.55123
mydict['third'] = 3.01
print "Hola"
w.initialize(mydict)
w.to_print()
