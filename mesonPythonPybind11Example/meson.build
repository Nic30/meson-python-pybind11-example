
# mark sources of a single module for an installation
py3.install_sources(
    ['myLib2.py'],
    pure: false, # Will be installed next to binaries
    subdir: 'mesonPythonPybind11Example',  # Folder relative to site-packages to install to
)

py3.extension_module(
    '_mesonPythonPybind11Example',
    ['module.cpp'],
    include_directories: [mesonPythonPybind11Example_inc],
    dependencies : [py3_dep, pybind11_dep, myLib_cpp_dep],
    install: true,
    cpp_args: [],
    subdir: 'mesonPythonPybind11Example/',
)