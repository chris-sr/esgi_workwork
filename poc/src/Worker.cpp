
#include "Worker.h"
#include "Utils.h"
#include "Task.h"

Worker::Worker(const char* name){
    _name = name;
    _task = NULL;
    _thread = NULL;
    _continue = true;
    basiclog("Worker "<<_name<<" created\n");
}

Worker::~Worker(){
    if(NULL != _thread)
        delete _thread;
    basiclog("Worker "<<_name<<" destroyed\n");
}

void Worker::start(){
    _thread = new boost::thread(_threadMain,this);
}

void Worker::_threadMain(Worker* w){
    basiclog("Thread of "<<w->_name<<" launched\n");
    Task* task = w->_task;
    if(task != NULL) task->execute();
    basiclog("Thread of "<<w->_name<<" ended\n");
}

void Worker::waitEnd(){
    if(NULL != _thread)
        _thread->join();
}

void Worker::stop(){
    _continue = false;
    waitEnd();
}

void Worker::setTask(Task* t){
    _task = t;
}
