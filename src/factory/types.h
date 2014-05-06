#ifndef TYPES_H
#define TYPES_H

#include <iostream>

#ifdef WW_DEBUG
    /* Main logging function, which is a basic std::cout
     * This log function is not compiled in release mode
     * The wwlog_emergency macro does the same, but is always
     * compiled */
    #define wwlog(X) std::cout << " * " << X ;
#else
    #define wwlog(X)
#endif

#define wwlog_emergency(X) std::cout << " # " << X ;

typedef unsigned int uint;

#endif // TYPES_H
