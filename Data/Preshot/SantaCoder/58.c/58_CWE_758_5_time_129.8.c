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
    PyObject* res;

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

    res = Py_BuildValue("{siisi}", "version", apparms.version, "upgrade", apparms.upgrade, "time1", time1, "time2", time2);

    fclose(fp);

    return res;
}

static PyObject* write_binary_data(PyObject* self, PyObject* args) {
    const char* filepath;
    FILE* fp;
    apparms_t apparms;
    int32_t time1, time2;
    PyObject* version;
    PyObject* upgrade;
    PyObject* time1_obj;
    PyObject* time2_obj;

    if (!PyArg_ParseTuple(args, "sO!O!O!O!", &filepath, &PyLong_Type, &version, &PyLong_Type, &upgrade, &PyLong_Type, &time1_obj, &PyLong_Type, &time2_obj))
        return NULL;

    fp = fopen(filepath, "w+b");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        return NULL;
    }

    apparms.version = PyLong_AsUnsignedLong(version);
    apparms.upgrade = PyLong_AsUnsignedLong(upgrade);
    apparms.time1 = PyLong_AsUnsignedLong(time1_obj);
    apparms.time2 = PyLong_AsUnsignedLong(time2_obj);

    if (fwrite(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to write data");
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    Py_RETURN_NONE;
}

#ifdef __cplusplus
}