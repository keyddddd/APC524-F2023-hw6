cmake_minimum_required(VERSION 3.18...3.25)
project(se_for_sci_hw6 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2
  URL_HASH SHA256=b4c198460eba6f28d34894e3a5710998818515104d6e74e5cc331ce31e46e626)
FetchContent_MakeAvailable(eigen)

if(DEFINED SKBUILD)
  find_package(pybind11 REQUIRED)
  add_library(_core MODULE src/_core.cpp)
  target_include_directories(_core PRIVATE ${PYTHON_INCLUDE_DIRS} ${pybind11_INCLUDE_DIRS})
  target_link_libraries(_core PRIVATE ${PYTHON_LIBRARIES} Eigen3::Eigen)
else()
  add_executable(main src/main.cpp src/integrator.hpp)
  target_include_directories(main PRIVATE src ${eigen_SOURCE_DIR})
  target_compile_features(main PRIVATE cxx_std_11)
endif()
