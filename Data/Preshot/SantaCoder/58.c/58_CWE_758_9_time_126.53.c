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
    PyObject* ret = NULL;

    if (!PyArg_ParseTuple(args, "s", &filepath))
        return NULL;

    fp = fopen(filepath, "r+b");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        return NULL;
    }

    if (fread(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to read data");
        ret = NULL;
    } else {
        // convert time_t fields to Python objects
        time1 = (int32_t) apparms.time1;
        time2 = (int32_t) apparms.time2;
        ret = Py_BuildValue("{s:H,s:b,s:i,s:i}", "version", apparms.version, "upgrade", apparms.upgrade, "time1", time1, "time2", time2);
    }
    fclose(fp);
    return ret;
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* input;

    if (!PyArg_ParseTuple(args, "sO", &filepath, &input))
        return NULL;

    if (!PyDict_Check(input)) {
        PyErr_SetString(PyExc_TypeError, "Expected a dictionary object");
        return NULL;
    }

    if (!PyArg_ParseDict(input, "{s:H,s:b,s:i,s:i}", "version", &apparms.version, "upgrade", &apparms.upgrade, "time1", &time1, "time2", &time2))
        return NULL;

    apparms.time1 = time1;
    apparms.time2 = time2;

    fp = fopen(filepath, "w+b");
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
    Py_RETURN_TRUE;
}

#ifdef __cplusplus
}