## ***How to import 3rdparty***
* using vscpg to install it
* set the ENV_VAR ---> `VCPKG_ROOT` and `VCPKG_DEFAULT_TRIPLET`
* set the XXX_DIR
  * such as `set(TBB_DIR $ENV{VCPKG_ROOT}/installed/x64-windows/share/tbb CACHE STRING "")`
* `find_package` and `target_link_libraries`