#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "MatrixOps.cpp"
#include <vector>

namespace py = pybind11;

PYBIND11_MODULE(MatrixOps, m) {
    py::class_<Operational1D>(m, "Operational1D")
        .def(py::init< vector<vector<double>> >())
        .def("__add__", &Operational1D::addMatrix)
        .def("__sub__", &Operational1D::substractMatrix)
        .def("__mul__", &Operational1D::multiplyMatrix)
        .def("__truediv__", &Operational1D::divideMatrix)
        .def("__floordiv__", &Operational1D::intdivideMatrix)
        .def("__matmul__", &Operational1D::atMatrix)
        .def("__repr__", &Operational1D::printMatrix)
        .def("__getitem__", py::overload_cast<pair<int, int>>(&Operational1D::at))
        .def("__getitem__", py::overload_cast<int>(&Operational1D::at))
        .def("__setitem__", py::overload_cast<pair<int, int>, double>(&Operational1D::set))
        .def("__setitem__", py::overload_cast<int, vector<double>>(&Operational1D::set))
        .def("__add__", &Operational1D::addConstant)
        .def("__sub__", &Operational1D::subtractConstant)
        .def("__mul__", &Operational1D::multiplyConstant)
        .def("__truediv__", &Operational1D::divideConstant)
        .def("__floordiv__", &Operational1D::intdivideConstant)
        .def("T", &Operational1D::T)
        .def("transpose", &Operational1D::T)
        .def("det", &Operational1D::det)
        .def("inv", &Operational1D::inverse)
        .def("adjoint", &Operational1D::adjoint)
        .def("cofactor", &Operational1D::cofactor)
        .def("copy", &Operational1D::copy)
        .def_readonly("height", &Operational1D::height)
        .def_readonly("width", &Operational1D::width)
        .def_readonly("shape", &Operational1D::shape)
        ;
}