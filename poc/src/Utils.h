
#ifndef UTILS_H
#define UTILS_H

#include "boost/thread.hpp"

//Basic log function
#define basiclog(X) log_lock(); \
               std::cout << " * " << boost::this_thread::get_id() << "\t" << X ; \
               log_unlock();

//Stdout lock handle
void log_lock();
void log_unlock();

#endif // UTILS_H
