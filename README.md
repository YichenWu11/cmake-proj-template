## ***How to import 3rdparty***
* IF USE VCPKG IN WIN32
  * using `vcpkg` to install it
  * set the `ENV_VAR` ---> `VCPKG_ROOT` and `VCPKG_DEFAULT_TRIPLET`
  * set the `XXX_DIR`
    * such as `set(TBB_DIR $ENV{VCPKG_ROOT}/installed/x64-windows/share/tbb CACHE STRING "")`
* `find_package` and `target_link_libraries`
  
## ***SetUp***
```shell
  // Linux[Ubuntu]
  sudo apt-get install libtbb-dev
  sudo apt-get install libbenchmark-dev

  // Windows[vcpkg]
  vcpkg install tbb:x64-windows
  vcpkg install benchmark:x64-windows
``
