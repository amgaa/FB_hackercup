#!/usr/bin/python

import sys
import random


print "25"
for i in range(25):
	print "10000 5000"
	for i in range(10000):
		sys.stdout.write(str(random.randint(0, 2000000000)))
		sys.stdout.write(" ")
		sys.stdout.write("\n")


