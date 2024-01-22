
## Build and installation

### Obscurities

* All files which are not commited in git are ignored during the build with `python3 -m build` 
* If you do not commit meson.build to git the execution of python -m build will endup with error:
```
+ meson dist --allow-dirty --no-tests --formats gztar
Dist currently only works with Git or Mercurial repos
```
The reason for this is https://github.com/mesonbuild/meson/blob/760d8d50b67ac2cf57ca6a450079885072b7a068/mesonbuild/mdist.py#L75



## Coverage reporting

```
python3 -m build -Csetup-args="-Dbuildtype=debug" -Csetup-args="-Db_coverage=true" -Ccompile-args="--verbose" .
pip3 install dist/*.whl
```

### Obscurities
* lcov 2.0-1 is broken package missing some files, yet in 2024 Q1 is still default on distros like ubuntu 23.10
  https://bugs.launchpad.net/ubuntu/+source/lcov/+bug/2029924
```
lcov/install/bin/lcov
Can't locate lcovutil.pm in @INC (you may need to install the lcovutil module) (@INC contains: install/lib/lcov /Library/Perl/5.30/darwin-thread-multi-2level /Library/Perl/5.30 /Network/Library/Perl/5.30/darwin-thread-multi-2level /Network/Library/Perl/5.30 /Library/Perl/Updates/5.30.3 /System/Library/Perl/5.30/darwin-thread-multi-2level /System/Library/Perl/5.30 /System/Library/Perl/Extras/5.30/darwin-thread-multi-2level /System/Library/Perl/Extras/5.30) at lcov/install/bin/lcov line 77.
BEGIN failed--compilation aborted at lcov/install/bin/lcov line 102.
```