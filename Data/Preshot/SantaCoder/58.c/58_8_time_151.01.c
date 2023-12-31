#include <Python.h>
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint16_t version;
    uint8_t upgrade;
    int32_t time1;
    int32_t time2;
} apparms_t;

static PyObject* read_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp = NULL;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* result = NULL;

    if (!PyArg_ParseTuple(args, "s", &filepath))
        return NULL;

    fp = fopen(filepath, "rb");
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

    result = Py_BuildValue("(i,i,i,i)", apparms.version, apparms.upgrade, time1, time2);

    fclose(fp);

    return result;
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp = NULL;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* result = NULL;

    if (!PyArg_ParseTuple(args, "sii", &filepath, &time1, &time2))
        return NULL;

    apparms.version = 1;
    apparms.upgrade = 0;
    apparms.time1 = time1;
    apparms.time2 = time2;

    fp = fopen(filepath, "wb");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        return NULL;
    }

    if (fwrite(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to write data");
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    result = Py_BuildValue("i", 1);
    return result;
}

static PyMethodDef binary_methods[] = {
    {"read_binary_data", read_binary_data, METH_VARARGS, "Read binary data from file."},
    {"write_binary_data", write_binary_data, METH_VARARGS, "Write binary data to file."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef binary_module = {
    PyModuleDef_HEAD_INIT,
    "binary_module",
    NULL,
    -1,
    binary_methods
};

PyMODINIT_FUNC PyInit_binary_module(void) {
    return PyModule_Create(&binary_module);
}