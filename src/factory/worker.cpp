#include "worker.h"

#include "types.h"
#include "factory.h"

ww::Worker::Worker(){
    //Initialize a standard worker

    //Notify the factory we created a worker
    Factory::get_reference().register_worker(this);
}

ww::Worker::~Worker(){

}
