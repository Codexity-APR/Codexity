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
    PyObject* result;

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

    // close file pointer
    fclose(fp);

    // create a Python dictionary to store the apparms struct
    result = Py_BuildValue("{s:H,s:B,s:i,s:i}",
                           "version", apparms.version,
                           "upgrade", apparms.upgrade,
                           "time1", time1,
                           "time2", time2);
    return result;
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* dict;

    if (!PyArg_ParseTuple(args, "O&s", PyDict_Check, &dict, &filepath))
        return NULL;

    // populate apparms struct from Python dictionary
    if (!PyArg_Parse(dict, "{s:H,s:B,s:i,s:i}",
                     "version", &apparms.version,
                     "upgrade", &apparms.upgrade,
                     "time1", &time1,
                     "time2", &time2))
        return NULL;

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

    // close file pointer
    fclose(fp);

    Py_RETURN_NONE;
}

static PyMethodDef module_methods[] = {
    {"read_binary_data", read_binary_data, METH_VARARGS, "Reads binary data from a file"},
    {"write_binary_data", write_binary_data, METH_VARARGS, "Writes binary data to a file"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef apparms_module = {
    PyModuleDef_HEAD_INIT,
    "apparms",
    "Module for reading and writing apparms binary data",
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_apparms(void) {
    return PyModule_Create(&apparms_module);
}