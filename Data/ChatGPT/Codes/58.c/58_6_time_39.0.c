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

    // Create Python objects for the time fields
    PyObject* pyTime1 = PyLong_FromLong(time1);
    PyObject* pyTime2 = PyLong_FromLong(time2);

    // Create a Python dictionary to store the apparms data
    PyObject* apparmsDict = PyDict_New();
    PyDict_SetItemString(apparmsDict, "version", PyLong_FromUnsignedLong(apparms.version));
    PyDict_SetItemString(apparmsDict, "upgrade", PyLong_FromUnsignedLong(apparms.upgrade));
    PyDict_SetItemString(apparmsDict, "time1", pyTime1);
    PyDict_SetItemString(apparmsDict, "time2", pyTime2);

    // Clean up
    fclose(fp);
    Py_DECREF(pyTime1);
    Py_DECREF(pyTime2);

    // Return the apparms dictionary
    return apparmsDict;
}