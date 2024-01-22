project(
  'mesonPythonPybind11Example',
  ['c', 'cpp'],
  # https://stackoverflow.com/questions/59201214/can-the-meson-project-version-be-assigned-dynamically
  version: '0.0', # FIXME: git hash (see URL above).
  license: 'MIT',
  meson_version: '>= 1.1.0',
  default_options: ['cpp_std=c++20'],
)

py3_mod = import('python')
py3 = py3_mod.find_installation(required: true)

py3_dep = py3.dependency()
pybind11_inc = run_command(py3, '-c', 'from pybind11 import get_include;  print(get_include())', check: true).stdout().strip()
pybind11_dep = declare_dependency(
  include_directories : pybind11_inc)

mesonPythonPybind11Example_inc = include_directories('include/')
# sources of c++ library which is build separately
subdir('src')
# sources of python extension wich is build as a shared library and is linked with previous library from src/
subdir('mesonPythonPybind11Example')
