// for without pybind11 see https://meson-python.readthedocs.io/en/latest/tutorials/introduction.html
#include <pybind11/pybind11.h>
#include <mesonPythonPybind11Example/myLib.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(_mesonPythonPybind11Example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function that adds two numbers");
    m.def("is_even", &is_even, "A function function which is part of library build separately");
}

