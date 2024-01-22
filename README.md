# meson-python-pybind11-example
This repository contains a minimalistic example project which is using meson-python and pybind11 to build a python c++ extension.
This extension has one static library (myLib) and python files (myLib2.py).

## Build and installation

There are several options how to execute build and installation.

* python recommends to use venv (virtualenv) https://docs.python.org/3/library/venv.html
```
sudo pip3 install venv # or sudo apt install python3-venv # or equivalent for your distro
python3 -m venv myvenv # create virtual env, which will reside in folder named myvenv
source myvenv/bin/activate # switch shell to use this virtualenv
```

* Build and install at once.
```
pip3 install .
```

* Build .whl package and then install.
```
python3 -m build
pip3 install dist/*.whl
```

* Build in-place using pure meson.
```
meson setup build
ninja -C build
``` 
   * This does not automatically install dependencies.
   * This is good for debugging as it preserves build files.

### Obscurities

* All files which are not commited in git are ignored during the build with `python3 -m build`
  Howerver if the file which is already in git is modified the modified version is used.
```
+ meson dist --allow-dirty --no-tests --formats gztar
WARNING: Repository has uncommitted changes that will not be included in the dist tarball
```

* If you do not commit meson.build to git the execution of python -m build will endup with error:
```
+ meson dist --allow-dirty --no-tests --formats gztar
Dist currently only works with Git or Mercurial repos
```
The reason for this is https://github.com/mesonbuild/meson/blob/760d8d50b67ac2cf57ca6a450079885072b7a068/mesonbuild/mdist.py#L75


## Coverage reporting

```
# python3 -m build -Csetup-args="-Dbuildtype=debug" -Csetup-args="-Db_coverage=true" -Ccompile-args="--verbose" .
pip3 install pybind11 meson-python
pip3 install -e . --no-build-isolation \
    -Csetup-args="-Dbuildtype=debug" \
    -Csetup-args="-Db_coverage=true" \
    -Ccompile-args="--verbose" \
    -Cbuild-dir=build-dbg
lcov --compat-libtool --directory . --capture --output-file coverage.info.raw --ignore-errors mismatch # collect coverage reports
lcov --remove coverage.info.raw -o coverage.info '/usr/*' 'pybind11/*' # remove system includes and pybind11 from coverage
genhtml coverage.info --output-directory coverage_out # generate coverage report html
```

### Obscurities
* lcov 2.0-1 is broken package missing some files, yet in 2024 Q1 is still default on distros like ubuntu 23.10
  https://bugs.launchpad.net/ubuntu/+source/lcov/+bug/2029924
```
lcov/install/bin/lcov
Can't locate lcovutil.pm in @INC (you may need to install the lcovutil module) (@INC contains: install/lib/lcov /Library/Perl/5.30/darwin-thread-multi-2level /Library/Perl/5.30 /Network/Library/Perl/5.30/darwin-thread-multi-2level /Network/Library/Perl/5.30 /Library/Perl/Updates/5.30.3 /System/Library/Perl/5.30/darwin-thread-multi-2level /System/Library/Perl/5.30 /System/Library/Perl/Extras/5.30/darwin-thread-multi-2level /System/Library/Perl/Extras/5.30) at lcov/install/bin/lcov line 77.
BEGIN failed--compilation aborted at lcov/install/bin/lcov line 102.
```

