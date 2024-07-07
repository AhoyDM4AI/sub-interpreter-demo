// Author: Baruch Sterin <baruchs@gmail.com>

#include <Python.h>

#include <string>
#include <vector>
#include <iostream>
#include <thread>

using namespace std;

void f(const char *tname)
{
    PyThreadState *_ts;
    PyInterpreterConfig config = {
        .use_main_obmalloc = 0,
        .allow_fork = 0,
        .allow_exec = 0,
        .allow_threads = 1,
        .allow_daemon_threads = 0,
        .check_multi_interp_extensions = 1,
        .gil = PyInterpreterConfig_OWN_GIL,
    };
    Py_NewInterpreterFromConfig(&_ts, &config);
    std::string code = R"PY(
# import sys
# sys.path.append(f"/root/db/python_subinterpreters_example/build/")
# import example2
# print(example2.add(3, 4))

#import numpy as np
#print(np.__version__)
#import datetime

print("TNAME")
a=0
for i in range(100):
    a = a+1
    )PY";

    code.replace(code.find("TNAME"), 5, tname);
    // sub->swap_to_self();
    PyRun_SimpleString(code.c_str());
    // std::cout<<"step2________________"<<std::endl;
    Py_EndInterpreter(_ts);
    // std::cout<<"step3________________"<<std::endl;
}

int main()
{
    Py_Initialize();
    PyRun_SimpleString(R"PY(
import sys
print(sys.version)
    )PY");

    // std::cout<<"step1________________"<<std::endl;
    std::thread t1{f, "t1___"};
    std::thread t2{f, "t2___"};
    std::thread t3{f, "t3___"};
    std::thread t4{f, "t4___"};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    // f("main");
    Py_Finalize();
    return 0;
}
