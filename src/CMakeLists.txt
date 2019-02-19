cmake_minimum_required(VERSION 3.0)
project(3DModelRenderer)
include(CTest)
option(BUILD_TESTS "Build unit tests" OFF)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_BUILD_TYPE Debug)

include_directories(src)
add_compile_options(-std=c++11)
link_directories(./)

set(APP_NAME main)
add_executable(${APP_NAME} main.cc graphic_operations/graphic_operations.cc graphic_operations/tests.cc)
target_link_libraries(${APP_NAME} PRIVATE glut GLU GL ${GTEST_LIBRARIES} pthread) 
#add_dependencies(${APP_NAME} ${LIB})

message(STATUS "Tests building")
file(GLOB files "tests/test_*.cc")
link_directories(build)

# foreach(file ${files})
# 	string(REGEX REPLACE "(^.*/|\\.[^.]*$)" "" file_without_ext ${file})
# 	add_executable(${file_without_ext} ${file})
# 	target_link_libraries(${file_without_ext} pthread)
# 	add_test(${file_without_ext} tests/${file_without_ext})
# 	set_tests_properties(${file_without_ext}
# 		PROPERTIES
# 		PASS_REGULAR_EXPRESSION "Test passed")
# 	set_tests_properties(${file_without_ext}
# 		PROPERTIES
# 		FAIL_REGULAR_EXPRESSION "(Exception|Test failed)")
# 	set_tests_properties(${file_without_ext}
# 		PROPERTIES
# 		TIMEOUT 120)
# endforeach()