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

    if (!PyArg_ParseTuple(args, "s", &filepath))
        return NULL;

    fp = fopen(filepath, "r+b");
    if (!fp) {
        PyErr_SetString(PyExc_IOError, "Failed to open file");
        goto error;
    }

    if (fread(&apparms, sizeof(apparms), 1, fp) != 1) {
        PyErr_SetString(PyExc_IOError, "Failed to read data");
        goto error;
    }

    // convert time_t fields to Python objects
    time1 = (int32_t) apparms.time1;
    time2 = (int32_t) apparms.time2;
    
    fclose(fp);
    return Py_BuildValue("ii", time1, time2);

error:
    if (fp != NULL) {
        fclose(fp);
    }
    return NULL;
}

static PyMethodDef methods[] = {
    {"read_binary_data", read_binary_data, METH_VARARGS, "Read binary data from a file"},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "read_binary_data",
    "Read binary data from a file",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_read_binary_data(void) {
    return PyModule_Create(&module);
}
#else
PyMODINIT_FUNC initread_binary_data(void) {
    (void) Py_InitModule("read_binary_data", methods);
}