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
    FILE* fp = NULL;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* ret = NULL;

    if (!PyArg_ParseTuple(args, "s", &filepath)) {
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return NULL;
    }

    fp = fopen(filepath, "rb");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        goto end;
    }

    if (fread(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to read data");
        goto end;
    }

    // convert time_t fields to Python objects
    time1 = (int32_t) apparms.time1;
    time2 = (int32_t) apparms.time2;

    // create a Python dictionary object to hold the read data
    ret = Py_BuildValue("{s:i,s:i,s:B}", "time1", time1, "time2", time2, "upgrade", apparms.upgrade);

end:
    if (fp)
        fclose(fp);

    return ret;
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp = NULL;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* dict;
    PyObject* ret = NULL;

    if (!PyArg_ParseTuple(args, "O&s", &dict, &filepath)) {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments");
        return NULL;
    }

    if (!PyDict_Check(dict)) {
        PyErr_SetString(PyExc_TypeError, "Invalid dictionary object");
        return NULL;
    }

    // extract values from the Python dictionary object
    PyDict_GetItemStringAndSize(dict, "time1", &time1);
    PyDict_GetItemStringAndSize(dict, "time2", &time2);
    PyDict_GetItemStringAndSize(dict, "upgrade", &apparms.upgrade);

    apparms.time1 = (int32_t) time1;
    apparms.time2 = (int32_t) time2;

    fp = fopen(filepath, "wb");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        goto end;
    }

    if (fwrite(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to write data");
        goto end;
    }

    ret = Py_BuildValue("i", 1);

end:
    if (fp)
        fclose(fp);

    return ret;
}

#ifdef __cplusplus
}