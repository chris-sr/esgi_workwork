#include "worker.h"

#include "types.h"
#include "factory.h"
#include "chain.h"

ww::Worker::Worker(){
    //Initialize a standard worker
    _affected_chain = NULL;
    _affected_task = NULL;
    _task = NULL;

    //Notify the factory we created a worker
    Factory::get_reference().register_worker(this);
}

ww::Worker::~Worker(){
    //Deallocate local members

    //Remove this worker from it's chain
    if(NULL != _affected_chain){
        _affected_chain->reject_worker(this);
    }

    //Unregister this worker from factory
    Factory::get_reference().unregister_worker(this);
}

void
ww::Worker::affect_task(Task* task){
    wwassert(NULL != task);
    _task = task;
}









