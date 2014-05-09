#include "factory.h"

#include "types.h"

ww::Factory*
ww::Factory::_instance = NULL;

ww::Factory::Factory(){
    _workers = new std::vector<Worker*>();
    _chains = new std::vector<Chain*>();
    /*_resources = new std::vector<Resource*>();*/
}

ww::Factory::~Factory(){
    /* Deallocate the factory elements. */

    /* Free the containers */
    delete _chains;
    delete _workers;
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
        wwlog("warning: worker is a nullptr\n");
        return;
    }

    for(uint i=0; i<_workers->size(); i++){
        if(_workers->at(i) == worker){
            wwlog("worker already registered\n");
            return;
        }
    }

    _workers->push_back(worker);
    wwlog("registered worker at " << worker << "\n");
}

void
ww::Factory::unregister_worker(Worker* worker){
    wwassert(NULL != worker);
    if(NULL == worker){
        wwlog("warning: worker is a nullptr\n");
        return;
    }

    for(uint i=0; i<_workers->size(); i++){
        if(_workers->at(i) == worker){
            _workers->erase(_workers->begin()+i);
            wwlog("unregistered worker at "
                  << worker << "\n");
            return;
        }
    }

    wwlog("warning: worker not found\n");
}

void
ww::Factory::register_chain(Chain* chain){
    wwassert(NULL != chain);
    if(NULL == chain){
        wwlog("warning: chain is a nullptr\n");
        return;
    }

    for(uint i=0; i<_chains->size(); i++){
        if(_chains->at(i) == chain){
            wwlog("chain already registered\n");
            return;
        }
    }

    _chains->push_back(chain);
    wwlog("registered chain at " << chain << "\n");
}

void
ww::Factory::unregister_chain(Chain* chain){
    wwassert(NULL != chain);
    if(NULL == chain){
        wwlog("warning: chain is a nullptr\n");
        return;
    }

    for(uint i=0; i<_chains->size(); i++){
        if(_chains->at(i) == chain){
            _chains->erase(_chains->begin()+i);
            wwlog("unregistered chain at "
                  << chain << "\n");
            return;
        }
    }

    wwlog("warning: chain not found\n");
}

void
ww::Factory::print(){
    uint i;

    for(i=0; i<_workers->size(); i++){
        wwlog_emergency("worker: " << _workers->at(i) << "\n");
    }
    for(i=0; i<_chains->size(); i++){
        wwlog_emergency("chain: " << _chains->at(i) << "\n");
    }
    /*for(i=0; i<_resources->size(); i++){
        wwlog_emergency("resource: " << _resources->at(i) << "\n");
    }*/
}








