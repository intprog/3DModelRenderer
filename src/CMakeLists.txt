cmake_minimum_required(VERSION 3.0)
project(3DModelRenderer)
include(CTest)
option(BUILD_TESTS "Build unit tests" OFF)

set(CMAKE_BUILD_TYPE Debug)

include_directories(src)
add_compile_options(-std=c++11)
link_directories(./)

set(APP_NAME main)
add_executable(${APP_NAME} main.cc)
target_link_libraries(${APP_NAME} PRIVATE pthread glut GLU GL) 
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