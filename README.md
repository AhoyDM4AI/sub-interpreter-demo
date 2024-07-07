# Python Subinterpreters Example
An example project of how to use subinterpreters in the lastest version of the Python C API (Python 3.9.7) without threads.

Many examples online use an old, deprecated version where the GIL had to be locked and unlocked manually. These examples no longer work.

## 说明

```c++
// 使用的原demo状态保存的子解释器调用方法（推荐这种）
a1main_multithread.cpp // 执行程序：mul1
a4main_multithread_state.cpp // 执行程序：mul4

// 不采用状态保存的子解释器调用方法（Python 3.12可用，预发布的3.13会产生线程hang的情况（可能是死锁））
a2multithreads.cpp // 执行程序: mul2
a3multithreads_class.cpp //执行程序: mul3

// 纯python的多进程demo（multiprocessing和joblib）
multiproces.py

// pybind打包c++ module
example.cpp

// python C_API打包c++ module（多阶段初始化）
example2.cpp

// python源码编译方法
1. 先拉取对应版本的源码
2. apt-get install libbz2-dev libreadline-dev libssl-dev zlib1g-dev libsqlite3-dev libncurses5-dev libncursesw5-dev xz-utils tk-dev libffi-dev liblzma-dev python-openssl git libgdbm-compat-dev libgdbm-dev libdb-dev
3. ./configure  --enable-shared
4. make -j32
4. make altinstall
```


# How to Run the Code

This example code may be built via the following steps:

1. Update the commented lines of code in CmakeLists.txt to point to your machine's python
2. Run the following command and observe the output


```
$bash run.sh
Interpreter 0 Initializing val to 0
Interpreter 1 Initializing val to 0
Interpreter 2 Initializing val to 0
Interpreter 0 has been called 1 times
Interpreter 1 has been called 1 times
Interpreter 2 has been called 1 times
Interpreter 0 has been called 2 times
Interpreter 1 has been called 2 times
Interpreter 2 has been called 2 times
Interpreter 0 has been called 3 times
Interpreter 1 has been called 3 times
Interpreter 2 has been called 3 times
Interpreter 0 shutting down now...
Interpreter 1 shutting down now...
Interpreter 2 shutting down now...
```

