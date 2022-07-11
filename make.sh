#!/bin/bash

if [ $1 -gt 0 ]
then
	c++ -shared -fPIC $(python3 -m pybind11 --includes) bind.cpp MatrixOps.cpp -o MatrixOps$(python3-config --extension-suffix)
	python3 test.py
else
	python3 test.py
fi