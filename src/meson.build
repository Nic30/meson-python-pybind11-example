myLib_lib = static_library('myLib',
    ['myLib.cpp'],
    cpp_args: [],
    dependencies: [],
    include_directories: [mesonPythonPybind11Example_inc, ],
)

myLib_cpp_dep = declare_dependency(link_with : myLib_lib, include_directories : mesonPythonPybind11Example_inc)