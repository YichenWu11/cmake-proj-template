set(TBB_DIR $ENV{VCPKG_ROOT}/installed/x64-windows/share/tbb CACHE STRING "")
set(BENCHMARK_DIR $ENV{VCPKG_ROOT}/installed/x64-windows/share/benchmark CACHE STRING "")

find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(benchmark CONFIG REQUIRED)

Module(
    NAME Test
    TYPE Executable
    SRC_PATH
    DEPS
    DEPS_PUBLIC benchmark::benchmark benchmark::benchmark_main TBB::tbb
    INCLUDES_PUBLIC
    INCLUDES
    LINKS
    LINKS_PUBLIC
)

target_compile_definitions(Test PUBLIC ROOT_DIR=${ROOT_DIR})