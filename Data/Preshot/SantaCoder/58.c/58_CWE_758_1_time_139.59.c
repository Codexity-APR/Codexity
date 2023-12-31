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

    fclose(fp);
    return Py_BuildValue("(bii)", apparms.version, apparms.upgrade, time1, time2);
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp;
    apparms_t apparms;
    int32_t time1, time2;

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
    Py_RETURN_NONE;
}

static PyMethodDef binary_data_methods[] = {
    {"read", read_binary_data, METH_VARARGS, "Read binary data from file"},
    {"write", write_binary_data, METH_VARARGS, "Write binary data to file"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef binary_data_module = {
    PyModuleDef_HEAD_INIT,
    "binary_data",
    "Module for reading and writing binary data",
    -1,
    binary_data_methods
};

PyMODINIT_FUNC PyInit_binary_data(void) {
    return PyModule_Create(&binary_data_module);
}