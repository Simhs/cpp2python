
#include <Python.h>
#include <iostream>

using namespace std;
static PyObject *ErrorObject;

static PyObject* write_log(PyObject *self, PyObject *args)
{
    char* msg;

    if(!PyArg_ParseTuple(args, "s", &msg))
        return NULL;

    cout<<msg<<endl;
    return Py_BuildValue("i", 0);
}

static struct PyMethodDef methods[] =
{
    {"printf", write_log, METH_VARARGS},
    {NULL, NULL}
};

extern "C" void initmylib()
{
    PyObject* m;
   // Py_InitModule("모듈명", 이모듈에 적용된 메쏘드들을 담을 구조체배열 포인터)
    m = Py_InitModule("mylib", methods);
    ErrorObject = Py_BuildValue("s", "error");
}
