cmake_minimum_required(VERSION 3.4)
project(python_subinterpreters)

# SET(PYTHON_VERSION 3.12) #Set this to your version of python
# SET(PYTHON_ENV /root/miniconda3/envs/clear) #point this to your python home path

SET(PYTHON_VERSION 3.13) #Set this to your version of python
SET(PYTHON_ENV /usr/local) #point this to your python home path


add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME}  PUBLIC cxx_std_11)
target_include_directories(${PROJECT_NAME} PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(${PROJECT_NAME}  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so)

add_executable(mul1 a1main_multithread.cpp)
target_include_directories(mul1 PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(mul1  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so pthread)


add_executable(mul2 a2multithreads.cpp)
target_include_directories(mul2 PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(mul2  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so pthread)

add_executable(mul3 a3multithreads_class.cpp)
target_include_directories(mul3 PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(mul3  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so pthread)


add_executable(mul4 a4main_multithread_state)
target_include_directories(mul4 PUBLIC ${PYTHON_ENV}/include/python${PYTHON_VERSION}/)
target_link_libraries(mul4  PUBLIC ${PYTHON_ENV}/lib/libpython${PYTHON_VERSION}.so pthread)


# set(pybind11_DIR /root/db/origin/duckdb_origin/tools/pythonpkg/.eggs/pybind11-2.12.0-py3.12.egg/pybind11/share/cmake/pybind11)
# set(PYTHON_INCLUDE_DIRS /root/miniconda3/envs/clear/include/python3.12)
# set(PYTHON_LIBRARIES /root/miniconda3/envs/clear/lib)
# message(STATUS "________________________________________Found ${PYTHON_LIBRARIES} PYBIND11_RELATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}")

# include_directories(${pybind11_INCLUDE_DIR})
# include_directories(${PYTHON_INCLUDE_DIRS})

# find_package(pybind11)
# if(NOT pybind11_FOUND)
#   return()
# endif()
# pybind11_add_module(example example.cpp)


# add_library(example2 MODULE example2.cpp)
# target_link_libraries(example2 ${PYTHON_LIBRARIES})
# set_target_properties(example PROPERTIES PREFIX "")
