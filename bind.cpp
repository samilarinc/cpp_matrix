#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include "MatrixOps.cpp"
#include <vector>

namespace py = pybind11;

template<>
Operational1D<double>;

template<>
Operational1D<int>;

PYBIND11_MODULE(MatrixOps, m) {
    py::class_<Operational1D>(m, "Operational1D")
        .def(py::init< vector<vector<double>> >())
        .def("__add__", &Operational1D<double>::addMatrix)
        .def("__sub__", &Operational1D<double>::substractMatrix)
        .def("__mul__", &Operational1D<double>::multiplyMatrix)
        .def("__truediv__", &Operational1D<double>::divideMatrix)
        .def("__floordiv__", &Operational1D<double>::intdivideMatrix)
        .def("__matmul__", &Operational1D<double>::atMatrix)
        .def("__repr__", &Operational1D<double>::printMatrix)
        .def("__getitem__", py::overload_cast<pair<int, int>>(&Operational1D<double>::at))
        .def("__getitem__", py::overload_cast<int>(&Operational1D<double>::at))
        .def("__setitem__", py::overload_cast<pair<int, int>, double>(&Operational1D<double>::set))
        .def("__setitem__", py::overload_cast<int, vector<double>>(&Operational1D<double>::set))
        .def("__add__", &Operational1D<double>::addConstant)
        .def("__sub__", &Operational1D<double>::subtractConstant)
        .def("__mul__", &Operational1D<double>::multiplyConstant)
        .def("__truediv__", &Operational1D<double>::divideConstant)
        .def("__floordiv__", &Operational1D<double>::intdivideConstant)
        .def("__len__", &Operational1D<double>::length)
        .def("T", &Operational1D<double>::T)
        .def("transpose", &Operational1D<double>::T)
        .def("det", &Operational1D<double>::det)
        .def("inv", &Operational1D<double>::inverse)
        .def("adjoint", &Operational1D<double>::adjoint)
        .def("cofactor", &Operational1D<double>::cofactor)
        .def("copy", &Operational1D<double>::copy)
        .def_readonly("height", &Operational1D<double>::height)
        .def_readonly("width", &Operational1D<double>::width)
        .def_readonly("shape", &Operational1D<double>::shape)
        ;
}