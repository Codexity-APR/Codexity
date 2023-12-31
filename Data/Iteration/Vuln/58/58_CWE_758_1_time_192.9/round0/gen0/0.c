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

    // Continue with the rest of the code here

    // Example:
    printf("Version: %d\n", apparms.version);
    printf("Upgrade: %d\n", apparms.upgrade);
    printf("Time1: %d\n", time1);
    printf("Time2: %d\n", time2);

    fclose(fp);

    Py_RETURN_NONE;
}

static PyMethodDef module_methods[] = {
    {"read_binary_data", read_binary_data, METH_VARARGS, "Read binary data from file"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

static struct PyModuleDef module_definition = {
    PyModuleDef_HEAD_INIT,
    "my_module",
    "My module description",
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_my_module(void) {
    return PyModule_Create(&module_definition);
}