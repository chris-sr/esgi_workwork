
#include "Worker.h"
#include "Utils.h"

Worker::Worker(){
    _t = NULL;
    _continue = true;
    basiclog("Worker created\n");
}

Worker::~Worker(){
    if(NULL != _t)
        delete _t;
    basiclog("Worker destroyed\n");
}

void Worker::start(){
    _t = new boost::thread(_threadMain);
    _t->join();
}

void Worker::_threadMain(){
    basiclog("Thread launched\n");
    basiclog("Thread ended\n");
}

void Worker::waitEnd(){
    _t->join();
}
