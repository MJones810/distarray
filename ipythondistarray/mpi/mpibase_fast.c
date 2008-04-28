/* Generated by Cython 0.9.6.13.1 on Mon Apr 28 14:03:22 2008 */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#include "structmember.h"
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#if PY_VERSION_HEX < 0x02050000
  typedef int Py_ssize_t;
  #define PY_SSIZE_T_MAX INT_MAX
  #define PY_SSIZE_T_MIN INT_MIN
  #define PyInt_FromSsize_t(z) PyInt_FromLong(z)
  #define PyInt_AsSsize_t(o)   PyInt_AsLong(o)
  #define PyNumber_Index(o)    PyNumber_Int(o)
  #define PyIndex_Check(o)     PyNumber_Check(o)
#endif
#if PY_VERSION_HEX < 0x02040000
  #define METH_COEXIST 0
#endif
#ifndef __stdcall
  #define __stdcall
#endif
#ifndef __cdecl
  #define __cdecl
#endif
#ifdef __cplusplus
#define __PYX_EXTERN_C extern "C"
#else
#define __PYX_EXTERN_C extern
#endif
#include <math.h>
#include "mpi.h"


#ifdef __GNUC__
#define INLINE __inline__
#elif _WIN32
#define INLINE __inline
#else
#define INLINE 
#endif

typedef struct {PyObject **p; char *s;} __Pyx_InternTabEntry; /*proto*/
typedef struct {PyObject **p; char *s; long n; int is_unicode;} __Pyx_StringTabEntry; /*proto*/



static int __pyx_skip_dispatch = 0;


/* Type Conversion Predeclarations */

#define __Pyx_PyBool_FromLong(b) ((b) ? (Py_INCREF(Py_True), Py_True) : (Py_INCREF(Py_False), Py_False))
static INLINE int __Pyx_PyObject_IsTrue(PyObject* x);
static INLINE PY_LONG_LONG __pyx_PyInt_AsLongLong(PyObject* x);
static INLINE unsigned PY_LONG_LONG __pyx_PyInt_AsUnsignedLongLong(PyObject* x);
static INLINE Py_ssize_t __pyx_PyIndex_AsSsize_t(PyObject* b);

#define __pyx_PyInt_AsLong(x) (PyInt_CheckExact(x) ? PyInt_AS_LONG(x) : PyInt_AsLong(x))
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))

static INLINE unsigned char __pyx_PyInt_unsigned_char(PyObject* x);
static INLINE unsigned short __pyx_PyInt_unsigned_short(PyObject* x);
static INLINE char __pyx_PyInt_char(PyObject* x);
static INLINE short __pyx_PyInt_short(PyObject* x);
static INLINE int __pyx_PyInt_int(PyObject* x);
static INLINE long __pyx_PyInt_long(PyObject* x);
static INLINE signed char __pyx_PyInt_signed_char(PyObject* x);
static INLINE signed short __pyx_PyInt_signed_short(PyObject* x);
static INLINE signed int __pyx_PyInt_signed_int(PyObject* x);
static INLINE signed long __pyx_PyInt_signed_long(PyObject* x);
static INLINE long double __pyx_PyInt_long_double(PyObject* x);
#ifdef __GNUC__
/* Test for GCC > 2.95 */
#if __GNUC__ > 2 ||               (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)) 
#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#else /* __GNUC__ > 2 ... */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ > 2 ... */
#else /* __GNUC__ */
#define likely(x)   (x)
#define unlikely(x) (x)
#endif /* __GNUC__ */
    
static PyObject *__pyx_m;
static PyObject *__pyx_b;
static PyObject *__pyx_empty_tuple;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static char * __pyx_cfilenm= __FILE__;
static char *__pyx_filename;
static char **__pyx_f;

static INLINE void __Pyx_RaiseArgtupleTooLong(Py_ssize_t num_expected, Py_ssize_t num_found); /*proto*/

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list); /*proto*/

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t); /*proto*/

static int __Pyx_ExportFunction(char *n, void *f, char *s); /*proto*/

static int __Pyx_SetVtable(PyObject *dict, void *vtable); /*proto*/

static void __Pyx_AddTraceback(char *funcname); /*proto*/

/* Declarations */

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pxd":11
 *     cdef MPI_Comm c_clone(self)
 *     
 * cdef class Group:             # <<<<<<<<<<<<<< 
 * 
 *     cdef MPI_Group group
 */

struct __pyx_obj_12mpibase_fast_Group {
  PyObject_HEAD
  MPI_Group group;
};

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pxd":3
 * include "../include/mpi.pxi"
 * 
 * cdef class Comm:             # <<<<<<<<<<<<<< 
 *         
 *     cdef MPI_Comm comm
 */

struct __pyx_obj_12mpibase_fast_Comm {
  PyObject_HEAD
  struct __pyx_vtabstruct_12mpibase_fast_Comm *__pyx_vtab;
  MPI_Comm comm;
};


/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":8
 * 
 * 
 * cdef class Comm:             # <<<<<<<<<<<<<< 
 *             
 *     def __init__(self, comm=None):
 */

struct __pyx_vtabstruct_12mpibase_fast_Comm {
  MPI_Group (*c_get_group)(struct __pyx_obj_12mpibase_fast_Comm *);
  int (*c_get_size)(struct __pyx_obj_12mpibase_fast_Comm *);
  int (*c_get_rank)(struct __pyx_obj_12mpibase_fast_Comm *);
  MPI_Comm (*c_clone)(struct __pyx_obj_12mpibase_fast_Comm *);
};
static struct __pyx_vtabstruct_12mpibase_fast_Comm *__pyx_vtabptr_12mpibase_fast_Comm;

static PyTypeObject *__pyx_ptype_12mpibase_fast_Comm = 0;
static PyTypeObject *__pyx_ptype_12mpibase_fast_Group = 0;


/* Implementation of mpibase_fast */


static PyObject *__pyx_n___init__;
static PyObject *__pyx_n_mpi4py;
static PyObject *__pyx_n_MPI;

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":10
 * cdef class Comm:
 *             
 *     def __init__(self, comm=None):             # <<<<<<<<<<<<<< 
 *         if comm is None:
 *             self.comm
 */

static int __pyx_pf_12mpibase_fast_4Comm___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static int __pyx_pf_12mpibase_fast_4Comm___init__(PyObject *__pyx_v_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_comm = 0;
  int __pyx_r;
  int __pyx_1;
  static char *__pyx_argnames[] = {"comm",0};
  __pyx_v_comm = Py_None;
  if (likely(!__pyx_kwds) && likely(0 <= PyTuple_GET_SIZE(__pyx_args)) && likely(PyTuple_GET_SIZE(__pyx_args) <= 1)) {
    if (PyTuple_GET_SIZE(__pyx_args) > 0) {
      __pyx_v_comm = PyTuple_GET_ITEM(__pyx_args, 0);
    }
  }
  else {
    if (unlikely(!PyArg_ParseTupleAndKeywords(__pyx_args, __pyx_kwds, "|O", __pyx_argnames, &__pyx_v_comm))) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 10; __pyx_clineno = __LINE__; goto __pyx_L2;}
  }
  goto __pyx_L3;
  __pyx_L2:;
  __Pyx_AddTraceback("mpibase_fast.Comm.__init__");
  return -1;
  __pyx_L3:;

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":11
 *             
 *     def __init__(self, comm=None):
 *         if comm is None:             # <<<<<<<<<<<<<< 
 *             self.comm
 *             
 */
  __pyx_1 = (__pyx_v_comm == Py_None);
  if (__pyx_1) {

    /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":12
 *     def __init__(self, comm=None):
 *         if comm is None:
 *             self.comm             # <<<<<<<<<<<<<< 
 *             
 *     cdef MPI_Group c_get_group(self):
 */
    ((struct __pyx_obj_12mpibase_fast_Comm *)__pyx_v_self)->comm;
    goto __pyx_L4;
  }
  __pyx_L4:;

  __pyx_r = 0;
  return __pyx_r;
}

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":14
 *             self.comm
 *             
 *     cdef MPI_Group c_get_group(self):             # <<<<<<<<<<<<<< 
 *         pass
 *     
 */

static  MPI_Group __pyx_f_12mpibase_fast_4Comm_c_get_group(struct __pyx_obj_12mpibase_fast_Comm *__pyx_v_self) {
  MPI_Group __pyx_r;

  __pyx_r = 0;
  return __pyx_r;
}

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":17
 *         pass
 *     
 *     cdef int c_get_size(self):             # <<<<<<<<<<<<<< 
 *         cdef int size, ierr
 *         ierr = MPI_Comm_size(self.comm, &size)
 */

static  int __pyx_f_12mpibase_fast_4Comm_c_get_size(struct __pyx_obj_12mpibase_fast_Comm *__pyx_v_self) {
  int __pyx_v_size;
  int __pyx_v_ierr;
  int __pyx_r;

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":19
 *     cdef int c_get_size(self):
 *         cdef int size, ierr
 *         ierr = MPI_Comm_size(self.comm, &size)             # <<<<<<<<<<<<<< 
 *         return size
 *         
 */
  __pyx_v_ierr = MPI_Comm_size(__pyx_v_self->comm, (&__pyx_v_size));

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":20
 *         cdef int size, ierr
 *         ierr = MPI_Comm_size(self.comm, &size)
 *         return size             # <<<<<<<<<<<<<< 
 *         
 *     cdef int c_get_rank(self):
 */
  __pyx_r = __pyx_v_size;
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":22
 *         return size
 *         
 *     cdef int c_get_rank(self):             # <<<<<<<<<<<<<< 
 *         cdef int rank, ierr
 *         ierr = MPI_Comm_rank(self.comm, &rank)
 */

static  int __pyx_f_12mpibase_fast_4Comm_c_get_rank(struct __pyx_obj_12mpibase_fast_Comm *__pyx_v_self) {
  int __pyx_v_rank;
  int __pyx_v_ierr;
  int __pyx_r;

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":24
 *     cdef int c_get_rank(self):
 *         cdef int rank, ierr
 *         ierr = MPI_Comm_rank(self.comm, &rank)             # <<<<<<<<<<<<<< 
 *         return rank
 *         
 */
  __pyx_v_ierr = MPI_Comm_rank(__pyx_v_self->comm, (&__pyx_v_rank));

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":25
 *         cdef int rank, ierr
 *         ierr = MPI_Comm_rank(self.comm, &rank)
 *         return rank             # <<<<<<<<<<<<<< 
 *         
 *     cdef MPI_Comm c_clone(self):
 */
  __pyx_r = __pyx_v_rank;
  goto __pyx_L0;

  __pyx_r = 0;
  __pyx_L0:;
  return __pyx_r;
}

/* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":27
 *         return rank
 *         
 *     cdef MPI_Comm c_clone(self):             # <<<<<<<<<<<<<< 
 *         pass
 *         
 */

static  MPI_Comm __pyx_f_12mpibase_fast_4Comm_c_clone(struct __pyx_obj_12mpibase_fast_Comm *__pyx_v_self) {
  MPI_Comm __pyx_r;

  __pyx_r = 0;
  return __pyx_r;
}

static __Pyx_InternTabEntry __pyx_intern_tab[] = {
  {&__pyx_n_MPI, "MPI"},
  {&__pyx_n___init__, "__init__"},
  {&__pyx_n_mpi4py, "mpi4py"},
  {0, 0}
};
static struct __pyx_vtabstruct_12mpibase_fast_Comm __pyx_vtable_12mpibase_fast_Comm;

static PyObject *__pyx_tp_new_12mpibase_fast_Comm(PyTypeObject *t, PyObject *a, PyObject *k) {
  struct __pyx_obj_12mpibase_fast_Comm *p;
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  p = ((struct __pyx_obj_12mpibase_fast_Comm *)o);
  *(struct __pyx_vtabstruct_12mpibase_fast_Comm **)&p->__pyx_vtab = __pyx_vtabptr_12mpibase_fast_Comm;
  return o;
}

static void __pyx_tp_dealloc_12mpibase_fast_Comm(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static struct PyMethodDef __pyx_methods_12mpibase_fast_Comm[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Comm = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_Comm = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_Comm = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Comm = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_12mpibase_fast_Comm = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "mpibase_fast.Comm", /*tp_name*/
  sizeof(struct __pyx_obj_12mpibase_fast_Comm), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_12mpibase_fast_Comm, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_Comm, /*tp_as_number*/
  &__pyx_tp_as_sequence_Comm, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_Comm, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_Comm, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_12mpibase_fast_Comm, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  __pyx_pf_12mpibase_fast_4Comm___init__, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_12mpibase_fast_Comm, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static PyObject *__pyx_tp_new_12mpibase_fast_Group(PyTypeObject *t, PyObject *a, PyObject *k) {
  PyObject *o = (*t->tp_alloc)(t, 0);
  if (!o) return 0;
  return o;
}

static void __pyx_tp_dealloc_12mpibase_fast_Group(PyObject *o) {
  (*o->ob_type->tp_free)(o);
}

static struct PyMethodDef __pyx_methods_12mpibase_fast_Group[] = {
  {0, 0, 0, 0}
};

static PyNumberMethods __pyx_tp_as_number_Group = {
  0, /*nb_add*/
  0, /*nb_subtract*/
  0, /*nb_multiply*/
  0, /*nb_divide*/
  0, /*nb_remainder*/
  0, /*nb_divmod*/
  0, /*nb_power*/
  0, /*nb_negative*/
  0, /*nb_positive*/
  0, /*nb_absolute*/
  0, /*nb_nonzero*/
  0, /*nb_invert*/
  0, /*nb_lshift*/
  0, /*nb_rshift*/
  0, /*nb_and*/
  0, /*nb_xor*/
  0, /*nb_or*/
  0, /*nb_coerce*/
  0, /*nb_int*/
  0, /*nb_long*/
  0, /*nb_float*/
  0, /*nb_oct*/
  0, /*nb_hex*/
  0, /*nb_inplace_add*/
  0, /*nb_inplace_subtract*/
  0, /*nb_inplace_multiply*/
  0, /*nb_inplace_divide*/
  0, /*nb_inplace_remainder*/
  0, /*nb_inplace_power*/
  0, /*nb_inplace_lshift*/
  0, /*nb_inplace_rshift*/
  0, /*nb_inplace_and*/
  0, /*nb_inplace_xor*/
  0, /*nb_inplace_or*/
  0, /*nb_floor_divide*/
  0, /*nb_true_divide*/
  0, /*nb_inplace_floor_divide*/
  0, /*nb_inplace_true_divide*/
  #if Py_TPFLAGS_DEFAULT & Py_TPFLAGS_HAVE_INDEX
  0, /*nb_index*/
  #endif
};

static PySequenceMethods __pyx_tp_as_sequence_Group = {
  0, /*sq_length*/
  0, /*sq_concat*/
  0, /*sq_repeat*/
  0, /*sq_item*/
  0, /*sq_slice*/
  0, /*sq_ass_item*/
  0, /*sq_ass_slice*/
  0, /*sq_contains*/
  0, /*sq_inplace_concat*/
  0, /*sq_inplace_repeat*/
};

static PyMappingMethods __pyx_tp_as_mapping_Group = {
  0, /*mp_length*/
  0, /*mp_subscript*/
  0, /*mp_ass_subscript*/
};

static PyBufferProcs __pyx_tp_as_buffer_Group = {
  0, /*bf_getreadbuffer*/
  0, /*bf_getwritebuffer*/
  0, /*bf_getsegcount*/
  0, /*bf_getcharbuffer*/
};

PyTypeObject __pyx_type_12mpibase_fast_Group = {
  PyObject_HEAD_INIT(0)
  0, /*ob_size*/
  "mpibase_fast.Group", /*tp_name*/
  sizeof(struct __pyx_obj_12mpibase_fast_Group), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_12mpibase_fast_Group, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  0, /*tp_compare*/
  0, /*tp_repr*/
  &__pyx_tp_as_number_Group, /*tp_as_number*/
  &__pyx_tp_as_sequence_Group, /*tp_as_sequence*/
  &__pyx_tp_as_mapping_Group, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  &__pyx_tp_as_buffer_Group, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_BASETYPE, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  __pyx_methods_12mpibase_fast_Group, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_12mpibase_fast_Group, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
};

static struct PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

static void __pyx_init_filenames(void); /*proto*/

PyMODINIT_FUNC init2mpibase_fast(void);

PyMODINIT_FUNC initmpibase_fast(void); /*proto*/
PyMODINIT_FUNC initmpibase_fast(void) {
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  /*--- Libary function declarations ---*/
  __pyx_init_filenames();
  /*--- Module creation code ---*/
  __pyx_m = Py_InitModule4("mpibase_fast", __pyx_methods, 0, 0, PYTHON_API_VERSION);
  if (!__pyx_m) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1;};
  __pyx_b = PyImport_AddModule("__builtin__");
  if (!__pyx_b) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1;};
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1;};
  /*--- Intern code ---*/
  if (__Pyx_InternStrings(__pyx_intern_tab) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1;};
  /*--- String init code ---*/
  /*--- Builtin init code ---*/
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 1; __pyx_clineno = __LINE__; goto __pyx_L1;}
  __pyx_skip_dispatch = 0;
  /*--- Global init code ---*/
  /*--- Function export code ---*/
  if (__Pyx_ExportFunction("init2mpibase_fast", (void*)init2mpibase_fast, "int (void)") < 0) {__pyx_filename = __pyx_f[1]; __pyx_lineno = 0; __pyx_clineno = __LINE__; goto __pyx_L1;}
  /*--- Type init code ---*/
  __pyx_vtabptr_12mpibase_fast_Comm = &__pyx_vtable_12mpibase_fast_Comm;
  *(void(**)(void))&__pyx_vtable_12mpibase_fast_Comm.c_get_group = (void(*)(void))__pyx_f_12mpibase_fast_4Comm_c_get_group;
  *(void(**)(void))&__pyx_vtable_12mpibase_fast_Comm.c_get_size = (void(*)(void))__pyx_f_12mpibase_fast_4Comm_c_get_size;
  *(void(**)(void))&__pyx_vtable_12mpibase_fast_Comm.c_get_rank = (void(*)(void))__pyx_f_12mpibase_fast_4Comm_c_get_rank;
  *(void(**)(void))&__pyx_vtable_12mpibase_fast_Comm.c_clone = (void(*)(void))__pyx_f_12mpibase_fast_4Comm_c_clone;
  if (PyType_Ready(&__pyx_type_12mpibase_fast_Comm) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; __pyx_clineno = __LINE__; goto __pyx_L1;}
  if (__Pyx_SetVtable(__pyx_type_12mpibase_fast_Comm.tp_dict, __pyx_vtabptr_12mpibase_fast_Comm) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; __pyx_clineno = __LINE__; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "Comm", (PyObject *)&__pyx_type_12mpibase_fast_Comm) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 8; __pyx_clineno = __LINE__; goto __pyx_L1;}
  __pyx_ptype_12mpibase_fast_Comm = &__pyx_type_12mpibase_fast_Comm;
  if (PyType_Ready(&__pyx_type_12mpibase_fast_Group) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 30; __pyx_clineno = __LINE__; goto __pyx_L1;}
  if (PyObject_SetAttrString(__pyx_m, "Group", (PyObject *)&__pyx_type_12mpibase_fast_Group) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 30; __pyx_clineno = __LINE__; goto __pyx_L1;}
  __pyx_ptype_12mpibase_fast_Group = &__pyx_type_12mpibase_fast_Group;
  /*--- Type import code ---*/
  /*--- Function import code ---*/
  init2mpibase_fast();
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("mpibase_fast");
}

PyMODINIT_FUNC init2mpibase_fast(void); /*proto*/
PyMODINIT_FUNC init2mpibase_fast(void) {
  static int __Pyx_unique = 0;
  if (__Pyx_unique==1) return;
  __Pyx_unique = 1;
  PyObject *__pyx_1 = 0;
  PyObject *__pyx_2 = 0;
  /*--- Execution code ---*/

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":5
 * # Importing this calls MPI_Init and insures that MPI_Finalize is called
 * # at the right time.
 * from mpi4py import MPI             # <<<<<<<<<<<<<< 
 * 
 * 
 */
  __pyx_1 = PyList_New(1); if (unlikely(!__pyx_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; __pyx_clineno = __LINE__; goto __pyx_L1;}
  Py_INCREF(__pyx_n_MPI);
  PyList_SET_ITEM(__pyx_1, 0, __pyx_n_MPI);
  __pyx_2 = __Pyx_Import(__pyx_n_mpi4py, __pyx_1); if (unlikely(!__pyx_2)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; __pyx_clineno = __LINE__; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  __pyx_1 = PyObject_GetAttr(__pyx_2, __pyx_n_MPI); if (unlikely(!__pyx_1)) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; __pyx_clineno = __LINE__; goto __pyx_L1;}
  if (PyObject_SetAttr(__pyx_m, __pyx_n_MPI, __pyx_1) < 0) {__pyx_filename = __pyx_f[0]; __pyx_lineno = 5; __pyx_clineno = __LINE__; goto __pyx_L1;}
  Py_DECREF(__pyx_1); __pyx_1 = 0;
  Py_DECREF(__pyx_2); __pyx_2 = 0;

  /* "/Users/bgranger/Documents/Computation/IPython/branches/ipythondistarray/ipythondistarray/mpi/mpibase_fast.pyx":30
 *         pass
 *         
 * cdef class Group:             # <<<<<<<<<<<<<< 
 * 
 *     pass */
  return;
  __pyx_L1:;
  Py_XDECREF(__pyx_1);
  Py_XDECREF(__pyx_2);
  __Pyx_AddTraceback("mpibase_fast");
}

static char *__pyx_filenames[] = {
  "mpibase_fast.pyx",
  "mpibase_fast",
};

/* Runtime support code */

static void __pyx_init_filenames(void) {
  __pyx_f = __pyx_filenames;
}

static INLINE void __Pyx_RaiseArgtupleTooLong(
    Py_ssize_t num_expected,
    Py_ssize_t num_found)
{
    const char* error_message =
    #if PY_VERSION_HEX < 0x02050000
        "function takes at most %d positional arguments (%d given)";
    #else
        "function takes at most %zd positional arguments (%zd given)";
    #endif
    PyErr_Format(PyExc_TypeError, error_message, num_expected, num_found);
}

static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list) {
    PyObject *__import__ = 0;
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    __import__ = PyObject_GetAttrString(__pyx_b, "__import__");
    if (!__import__)
        goto bad;
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    module = PyObject_CallFunction(__import__, "OOOO",
        name, global_dict, empty_dict, list);
bad:
    Py_XDECREF(empty_list);
    Py_XDECREF(__import__);
    Py_XDECREF(empty_dict);
    return module;
}

static int __Pyx_InternStrings(__Pyx_InternTabEntry *t) {
    while (t->p) {
        *t->p = PyString_InternFromString(t->s);
        if (!*t->p)
            return -1;
        ++t;
    }
    return 0;
}

static int __Pyx_ExportFunction(char *name, void *f, char *sig) {
    PyObject *d = 0;
    PyObject *p = 0;
    d = PyObject_GetAttrString(__pyx_m, "__pyx_capi__");
    if (!d) {
        PyErr_Clear();
        d = PyDict_New();
        if (!d)
            goto bad;
        Py_INCREF(d);
        if (PyModule_AddObject(__pyx_m, "__pyx_capi__", d) < 0)
            goto bad;
    }
    p = PyCObject_FromVoidPtrAndDesc(f, sig, 0);
    if (!p)
        goto bad;
    if (PyDict_SetItemString(d, name, p) < 0)
        goto bad;
    Py_DECREF(d);
    return 0;
bad:
    Py_XDECREF(p);
    Py_XDECREF(d);
    return -1;
}

static int __Pyx_SetVtable(PyObject *dict, void *vtable) {
    PyObject *pycobj = 0;
    int result;
    
    pycobj = PyCObject_FromVoidPtr(vtable, 0);
    if (!pycobj)
        goto bad;
    if (PyDict_SetItemString(dict, "__pyx_vtable__", pycobj) < 0)
        goto bad;
    result = 0;
    goto done;

bad:
    result = -1;
done:
    Py_XDECREF(pycobj);
    return result;
}

#include "compile.h"
#include "frameobject.h"
#include "traceback.h"

static void __Pyx_AddTraceback(char *funcname) {
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    PyObject *py_globals = 0;
    PyObject *empty_string = 0;
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    
    py_srcfile = PyString_FromString(__pyx_filename);
    if (!py_srcfile) goto bad;
    if (__pyx_clineno) {
        py_funcname = PyString_FromFormat( "%s (%s:%u)", funcname, __pyx_cfilenm, __pyx_clineno);
    }
    else {
        py_funcname = PyString_FromString(funcname);
    }
    if (!py_funcname) goto bad;
    py_globals = PyModule_GetDict(__pyx_m);
    if (!py_globals) goto bad;
    empty_string = PyString_FromString("");
    if (!empty_string) goto bad;
    py_code = PyCode_New(
        0,            /*int argcount,*/
        0,            /*int nlocals,*/
        0,            /*int stacksize,*/
        0,            /*int flags,*/
        empty_string, /*PyObject *code,*/
        __pyx_empty_tuple,  /*PyObject *consts,*/
        __pyx_empty_tuple,  /*PyObject *names,*/
        __pyx_empty_tuple,  /*PyObject *varnames,*/
        __pyx_empty_tuple,  /*PyObject *freevars,*/
        __pyx_empty_tuple,  /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        __pyx_lineno,   /*int firstlineno,*/
        empty_string  /*PyObject *lnotab*/
    );
    if (!py_code) goto bad;
    py_frame = PyFrame_New(
        PyThreadState_Get(), /*PyThreadState *tstate,*/
        py_code,             /*PyCodeObject *code,*/
        py_globals,          /*PyObject *globals,*/
        0                    /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    py_frame->f_lineno = __pyx_lineno;
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    Py_XDECREF(empty_string);
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* Type Conversion Functions */

static INLINE Py_ssize_t __pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject* x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}

static INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   if (x == Py_True) return 1;
   else if (x == Py_False) return 0;
   else return PyObject_IsTrue(x);
}

static INLINE PY_LONG_LONG __pyx_PyInt_AsLongLong(PyObject* x) {
    if (PyInt_CheckExact(x)) {
        return PyInt_AS_LONG(x);
    }
    else if (PyLong_CheckExact(x)) {
        return PyLong_AsLongLong(x);
    }
    else {
        PY_LONG_LONG val;
        PyObject* tmp = PyNumber_Int(x); if (!tmp) return (PY_LONG_LONG)-1;
        val = __pyx_PyInt_AsLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}

static INLINE unsigned PY_LONG_LONG __pyx_PyInt_AsUnsignedLongLong(PyObject* x) {
    if (PyInt_CheckExact(x)) {
        long val = PyInt_AS_LONG(x);
        if (unlikely(val < 0)) {
            PyErr_SetString(PyExc_TypeError, "Negative assignment to unsigned type.");
            return (unsigned PY_LONG_LONG)-1;
        }
        return val;
    }
    else if (PyLong_CheckExact(x)) {
        return PyLong_AsUnsignedLongLong(x);
    }
    else {
        PY_LONG_LONG val;
        PyObject* tmp = PyNumber_Int(x); if (!tmp) return (PY_LONG_LONG)-1;
        val = __pyx_PyInt_AsUnsignedLongLong(tmp);
        Py_DECREF(tmp);
        return val;
    }
}


static INLINE unsigned char __pyx_PyInt_unsigned_char(PyObject* x) {
    if (sizeof(unsigned char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        unsigned char val = (unsigned char)long_val;
        if (unlikely((val != long_val)  || (long_val < 0))) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to unsigned char");
            return (unsigned char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE unsigned short __pyx_PyInt_unsigned_short(PyObject* x) {
    if (sizeof(unsigned short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        unsigned short val = (unsigned short)long_val;
        if (unlikely((val != long_val)  || (long_val < 0))) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to unsigned short");
            return (unsigned short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE char __pyx_PyInt_char(PyObject* x) {
    if (sizeof(char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        char val = (char)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to char");
            return (char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE short __pyx_PyInt_short(PyObject* x) {
    if (sizeof(short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        short val = (short)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to short");
            return (short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE int __pyx_PyInt_int(PyObject* x) {
    if (sizeof(int) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        int val = (int)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to int");
            return (int)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE long __pyx_PyInt_long(PyObject* x) {
    if (sizeof(long) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        long val = (long)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to long");
            return (long)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed char __pyx_PyInt_signed_char(PyObject* x) {
    if (sizeof(signed char) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed char val = (signed char)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed char");
            return (signed char)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed short __pyx_PyInt_signed_short(PyObject* x) {
    if (sizeof(signed short) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed short val = (signed short)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed short");
            return (signed short)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed int __pyx_PyInt_signed_int(PyObject* x) {
    if (sizeof(signed int) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed int val = (signed int)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed int");
            return (signed int)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE signed long __pyx_PyInt_signed_long(PyObject* x) {
    if (sizeof(signed long) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        signed long val = (signed long)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to signed long");
            return (signed long)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}

static INLINE long double __pyx_PyInt_long_double(PyObject* x) {
    if (sizeof(long double) < sizeof(long)) {
        long long_val = __pyx_PyInt_AsLong(x);
        long double val = (long double)long_val;
        if (unlikely((val != long_val) )) {
            PyErr_SetString(PyExc_OverflowError, "value too large to convert to long double");
            return (long double)-1;
        }
        return val;
    }
    else {
        return __pyx_PyInt_AsLong(x);
    }
}
