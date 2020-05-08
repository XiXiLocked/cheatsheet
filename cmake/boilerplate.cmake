# https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html
cmake_minimum_required(VERSION 3.13) # Specifies the minimum required version of CMake. It is set to the version of CMake bundled in CLion (always one of the newest versions available).

project(cmake_testapp)	 # Defines the project name according to what we provided during project creation.

set(CMAKE_CXX_STANDARD 14)	# Sets the CMAKE_CXX_STANDARD variable to the value of 14, as we selected when creating the project.

add_executable(cmake_testapp main.cpp)	# Adds the cmake_testapp executable target which will be built from main.cpp.

install(TARGETS cmake_testapp DESTINATION bin) # 安装的make 命令


find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_subdirectory(src)

include_directories(includes/math)

add_library(test_library STATIC calc.cpp) #  Create a static library from the calc.cpp source fil

target_link_libraries(cmake_testapp test_library) # 链接库



# mkdir _build
# cd _build
# cmake .. -DCMAKE_INSTALL_PREFIX=../_install
# make
# make install