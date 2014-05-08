#include "factory.h"

#include "types.h"

ww::Factory*
ww::Factory::_instance = NULL;

ww::Factory::Factory(){
    _workers = new std::vector<Worker*>();
    _chains = new std::vector<Chain*>();
    _resources = new std::vector<Resource*>();
    _tasks = new std::vector<Task*>();
}

ww::Factory::~Factory(){

}

ww::Factory*
ww::Factory::get_instance(){
    if(NULL == _instance){
        _instance = new Factory();
    }

    return _instance;
}

ww::Factory&
ww::Factory::get_reference(){
    return *(ww::Factory::get_instance());
}

void
ww::Factory::register_worker(Worker* worker){
    wwassert(NULL != worker);
    if(NULL == worker){
        wwlog("error: worker is a nullptr\n");
        return;
    }

    for(uint i=0; i<_workers->size(); i++){
        if(_workers->at(i) == worker){
            wwlog("worker already registered\n");
            return;
        }
    }

    _workers->push_back(worker);
}

void
ww::Factory::print(){
    uint i;

    wwlog("[Workers]" << "\n");
    for(i=0; i<_workers->size(); i++){
        wwlog_emergency("worker: " << _workers->at(i) << "\n");
    }
}








