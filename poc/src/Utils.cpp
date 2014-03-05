
#include "Utils.h"

static boost::mutex* m = new boost::mutex();

void log_lock(){
    m->lock();
}

void log_unlock(){
    m->unlock();
}
