#ifndef TYPES_H
#define TYPES_H

#include <iostream>

#ifdef WW_DEBUG
#include <cassert>
    /* Main logging function, which is a basic std::cout
     * This log function is not compiled in release mode
     * The wwlog_emergency macro does the same, but is always
     * compiled */
    #define wwlog(X) std::cout << " * " << X

    /* Assert function. This small encapsulation does the
     * same as for logging: only debug mode will compile
     * assertions */
    #define wwassert(X) assert(X)
#else
    #define wwlog(X)
    #define wwassert(X)
#endif

#define wwlog_emergency(X) std::cout << " # " << X ;

typedef unsigned int uint;

#endif // TYPES_H
