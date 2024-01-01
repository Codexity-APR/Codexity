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
    // create Python dictionary to return
        PyObject* dict = PyDict_New();
        if (!dict) {
            PyErr_SetString(PyExc_RuntimeError, "Failed to create dictionary");
            fclose(fp);
            return NULL;
        }

        // add version to dictionary
        PyObject* version = PyLong_FromUnsignedLong(apparms.version);
        if (!version) {
            Py_DECREF(dict);
            PyErr_SetString(PyExc_RuntimeError, "Failed to create version object");
            fclose(fp);
            return NULL;
        }
        PyDict_SetItemString(dict, "version", version);

        // add upgrade to dictionary
        PyObject* upgrade = PyBool_FromLong(apparms.upgrade);
        if (!upgrade) {
            Py_DECREF(version);
            Py_DECREF(dict);
            PyErr_SetString(PyExc_RuntimeError, "Failed to create upgrade object");
            fclose(fp);
            return NULL;
        }
        PyDict_SetItemString(dict, "upgrade", upgrade);

        // add time1 to dictionary
        PyObject* time1_obj = PyLong_FromLong(time1);
        if (!time1_obj) {
            Py_DECREF(upgrade);
            Py_DECREF(version);
            Py_DECREF(dict);
            PyErr_SetString(PyExc_RuntimeError, "Failed to create time1 object");
            fclose(fp);
            return NULL;
        }
        PyDict_SetItemString(dict, "time1", time1_obj);

        // add time2 to dictionary
        PyObject* time2_obj = PyLong_FromLong(time2);
        if (!time2_obj) {
            Py_DECREF(time1_obj);
            Py_DECREF(upgrade);
            Py_DECREF(version);
            Py_DECREF(dict);
            PyErr_SetString(PyExc_RuntimeError, "Failed to create time2 object");
            fclose(fp);
            return NULL;
        }
        PyDict_SetItemString(dict, "time2", time2_obj);

        fclose(fp);
        return dict;
    }
