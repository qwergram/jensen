# distutils: language=c++

from libcpp.string cimport string as cstring
from libcpp.map cimport map as cmap

cdef extern from "queue.cc" namespace "jensen":
    pass

cdef extern from "queue.h" namespace "jensen":
    cdef cppclass Queue:
        Queue() except +;
        void push(cstring &payload, cstring &queue) except +;
        void pushFront(cstring &payload, cstring &queue) except +;
        cstring& pop(cstring &queue) except +;

        void clear(cstring& queue) except +;
        void clearAll() except +;

        size_t size() except +;
        cmap[cstring, size_t] sizes() except +;