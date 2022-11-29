cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -pthread")
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

message(STATUS $ENV{VCPKG_ROOT})

# IF USE VCPKG IN WIN32

# vcpkg
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "")
set(VCPKG_TARGET_TRIPLET $ENV{VCPKG_DEFAULT_TRIPLET} CACHE STRING "")
# tbb
set(TBB_DIR $ENV{VCPKG_ROOT}/installed/x64-windows/share/tbb CACHE STRING "")

# IF USE VCPKG IN WIN32

# how to use the `option`
option(USE_SOMETHING "optional" ON)

if(USE_SOMETHING)
    message(STATUS "Choose to use something.")
endif()
# how to use the `option`

project(Test_Vcpkg LANGUAGES CXX)

file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp include/*.h)

add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(${PROJECT_NAME} PUBLIC include)

# Insert Macro defines to your program
# target_compile_definitions(${PROJECT_NAME} PUBLIC RT)

# the way to import 3rdparty
find_package(TBB CONFIG REQUIRED COMPONENTS tbb)
find_package(benchmark CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC benchmark::benchmark benchmark::benchmark_main)
target_link_libraries(${PROJECT_NAME} PUBLIC TBB::tbb)
