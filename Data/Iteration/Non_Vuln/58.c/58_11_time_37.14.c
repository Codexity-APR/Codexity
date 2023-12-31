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

    // Continue with the rest of the code

    // Create Python objects for the time1 and time2 values
    PyObject* py_time1 = PyLong_FromLong(time1);
    PyObject* py_time2 = PyLong_FromLong(time2);

    // Build a Python dictionary to hold the apparms data
    PyObject* apparms_dict = PyDict_New();
    PyDict_SetItemString(apparms_dict, "version", PyLong_FromUnsignedLong(apparms.version));
    PyDict_SetItemString(apparms_dict, "upgrade", PyLong_FromUnsignedLong(apparms.upgrade));
    PyDict_SetItemString(apparms_dict, "time1", py_time1);
    PyDict_SetItemString(apparms_dict, "time2", py_time2);

    // Close the file and return the apparms dictionary
    fclose(fp);
    return apparms_dict;
}