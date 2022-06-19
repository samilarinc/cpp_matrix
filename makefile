all:
	c++ -shared -fPIC -I/usr/include/python3.8 -I/home/samil/.local/lib/python3.8/site-packages/pybind11/include bind.cpp MatrixOps.cpp -o MatrixOps.cpython-38-x86_64-linux-gnu.so
	python3 test.py