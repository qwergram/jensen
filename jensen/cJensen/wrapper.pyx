# distutils: language = c++
from cython.operator import dereference, preincrement, address

from libcpp.string cimport string as cstring

from wrapper cimport Queue as cQueue

cdef class Queue:
    cdef cQueue* _queue

    def __cinit__(self):
        self._queue = new cQueue()

    def __dealloc__(self):
        del self._queue

    def push(self, cstring element, cstring queue = "main"):
        dereference(self._queue).push(element, queue)

    def pushFront(self, cstring element, cstring queue = "main"):
        dereference(self._queue).pushFront(element, queue)

    def pop(self, cstring queue = "main"):
        return dereference(self._queue).pop(queue)

    def size(self):
        return dereference(self._queue).size()
