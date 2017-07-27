// Adapted from the python wrapper tutorial
// by Dan Foreman-Mackey found here:
// http://dan.iel.fm/posts/python-c-extensions/
//
// Peter F. Klemperer
// May 12, 2014

#include <Python.h>
#include "multibench.h"

/* Docstrings */
static char module_docstring[] =
    "This module provides an interface for testing memory performance in C.";
static char multibench_docstring[] =
    "Read a predefined amount of memory.";
static char multibench_print_info_docstring[] =
    "Print the configuration variables to stdout";
static char multibench_init_docstring[] =
    "Open the Shared Memory Interface.";
static char multibench_close_docstring[] =
    "Close the Shared Memory Interface.";

static PyObject *multibench_read_memory(PyObject *self, PyObject *args);
static PyObject *multibench_print_info(PyObject *self, PyObject *args);
static PyObject *multibench_init(PyObject *self, PyObject *args);
static PyObject *multibench_close(PyObject *self, PyObject *args);

static PyMethodDef module_methods[] = {
    {"multibench", multibench_read_memory, METH_VARARGS, multibench_docstring},
    {"multibench_print_info", multibench_print_info, METH_VARARGS, multibench_print_info_docstring},
    {"multibench_init", multibench_init, METH_VARARGS, multibench_init_docstring},
    {"multibench_close", multibench_close, METH_VARARGS, multibench_close_docstring},
    {NULL, NULL, 0, NULL}
};

/* Initialize the module */
PyMODINIT_FUNC init_multibench(void)
{
    PyObject *m = Py_InitModule3("_multibench", module_methods, module_docstring);
    if (m == NULL)
        return;
}

static PyObject *multibench_read_memory(PyObject *self, PyObject *args)
{
    // call write_memory
    read_memory( WRITE_BYTES_GLOBAL, WORKING_SET_BYTES_GLOBAL, LAST_BYTE_WRITTEN_OFFSET, MEMORY_BLOCK_GLOBAL );

    PyObject *ret = Py_BuildValue("n", 101);
    return ret; 
}

static PyObject *multibench_print_info(PyObject *self, PyObject *args)
{
    printf("WORKING_SET_BYTES_GLOBAL %d ", WORKING_SET_BYTES_GLOBAL );
    printf("LAST_BYTE_WRITTEN_OFFSET %" PRIu64 " ", LAST_BYTE_WRITTEN_OFFSET );
    printf("MEMORY_BLOCK_GLOBAL %p ", MEMORY_BLOCK_GLOBAL );

    PyObject *ret = Py_BuildValue("s", "opened file");
    return ret;
}

static PyObject *multibench_init(PyObject *self, PyObject *args) 
{
    int wss_mb_arg;
    long write_mb_arg;

    if( ! PyArg_ParseTuple( args, "ii", &wss_mb_arg, &write_mb_arg ) ) {
        printf("init failed: %d wss_mb_arg, %ld write_mb_arg\n",
                wss_mb_arg, write_mb_arg );
    }

    // 830320960 is a magic number calibration number that should write for 1/10 of a second
    // on morgan.ece.cmu.edu

    initialize( wss_mb_arg, (uint64_t) 1048576 * (uint64_t) write_mb_arg );
    PyObject *ret = Py_BuildValue("s", "opened file");
    return ret;
}

static PyObject *multibench_close(PyObject *self, PyObject *args)
{
    cleanup();
    PyObject *ret = Py_BuildValue("s", "close file");
    return ret;
}

