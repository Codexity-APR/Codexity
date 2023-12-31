#include <Python.h>
#include <stdio.h>
#include <stdint.h>  // for int32_t and int64_t

typedef struct {
    uint16_t version;
    uint8_t upgrade;
    int32_t time1;
    int32_t time2;
} apparms_t;

static PyObject* read_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp;
    apparms_t apparms;
    int32_t time1, time2;

    if (!PyArg_ParseTuple(args, "s", &filepath))
        return NULL;

    fp = fopen(filepath, "r+b");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        return NULL;
    }

    if (fread(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to read data");
        fclose(fp);
        return NULL;
    }

    // convert time_t fields to Python objects
    time1 = (int32_t) apparms.time1;
    time2 = (int32_t) apparms.time2;

    // TODO: Add your code here to complete the rest of the function

    return Py_BuildValue("ii", time1, time2);
}

static PyMethodDef myModule_methods[] = {
    {"read_binary_data", read_binary_data, METH_VARARGS, "Read binary data from a file"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "myModule",
    "Module description",
    -1,
    myModule_methods
};

PyMODINIT_FUNC PyInit_myModule(void) {
    return PyModule_Create(&myModule);
}