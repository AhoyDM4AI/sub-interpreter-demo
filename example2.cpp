#include <Python.h>

// 函数的实现
static PyObject* add(PyObject* self, PyObject* args) {
    int i, j;
    if (!PyArg_ParseTuple(args, "ii", &i, &j))
        return NULL;
    return PyLong_FromLong(i + j);
}

// 方法表
static PyMethodDef ExampleMethods[] = {
    {"add",  add, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// static PyModuleDef_Slot slots[] = {
//     {Py_mod_multiple_interpreters, Py_MOD_PER_INTERPRETER_GIL_SUPPORTED},
//     {0, NULL}
// };

// 模块定义
static struct PyModuleDef examplemodule = {
    PyModuleDef_HEAD_INIT,
    "example2",   /* name of module */
    NULL,        /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    ExampleMethods,
    NULL,
    NULL,
    NULL,
    NULL
};

// 模块初始化函数
PyMODINIT_FUNC PyInit_example2(void) {
    return PyModule_Create(&examplemodule);
}