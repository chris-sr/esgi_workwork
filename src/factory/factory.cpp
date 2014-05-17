#include "factory.h"

#include "types.h"
#include "worker.h"
#include "chain.h"
#include "resource.h"

ww::Factory::Factory(){
    _workers = new std::vector<Worker*>();
    _chains = new std::vector<Chain*>();
    _resources = new std::vector<Resource*>();
}


ww::Factory::~Factory(){
#ifdef WW_DEBUG
    /* Print all the registered elements, since they
     * may be a possible memory leak */
    wwlog("Destroying the factory. The following dump shows possible memory leaks\n");
    wwlog("Each element will be unregistered\n");
    this->print();
#endif

    /* Free the containers */
    delete _chains;
    delete _workers;
    delete _resources;
}


ww::Worker*
ww::Factory::create_worker(){
    Worker* w = new Worker();
    this->register_worker(w);
    w->_factory = this;
    return w;
}


ww::Chain*
ww::Factory::create_chain(){
    Chain* c = new Chain();
    this->register_chain(c);
    c->_factory = this;
    return c;
}


ww::Resource*
ww::Factory::create_resource(){
    Resource* r = new Resource();
    this->register_resource(r);
    r->_factory = this;
    return r;
}


/*void
ww::Factory::destroy(){
    if(NULL == _instance){
        wwlog("warning: attempting to destroy a non "
              << "existent factory\n");
        return;
    }
    delete _instance;
    _instance = NULL;
}*/


/*ww::Factory*
ww::Factory::get_instance(){
    if(NULL == _instance){
        _instance = new Factory();
    }

    return _instance;
}*/


/*ww::Factory&
ww::Factory::get_reference(){
    return *(ww::Factory::get_instance());
}*/


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

    wwlog("warning: worker not registered\n");
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

    wwlog("warning: chain not registered\n");
}


void
ww::Factory::register_resource(Resource* res){
    wwassert(NULL != res);
    if(NULL == res){
        wwlog("warning: resource is a nullptr\n");
        return;
    }

    for(uint i=0; i<_resources->size(); i++){
        if(_resources->at(i) == res){
            wwlog("resource already registered\n");
            return;
        }
    }

    _resources->push_back(res);
    wwlog("registered resource at " << res << "\n");
}


void
ww::Factory::unregister_resource(Resource* res){
    wwassert(NULL != res);
    if(NULL == res){
        wwlog("warning: resource is a nullptr\n");
        return;
    }

    for(uint i=0; i<_resources->size(); i++){
        if(_resources->at(i) == res){
            _resources->erase(_resources->begin()+i);
            wwlog("unregistered resource at "
                  << res << "\n");
            return;
        }
    }

    wwlog("warning: resource not registered\n");
}


void
ww::Factory::print(){
    uint i;
    wwlog("------Factory dump-----\n");

    for(i=0; i<_workers->size(); i++){
        wwlog("worker: " << _workers->at(i) << "\n");
    }
    for(i=0; i<_chains->size(); i++){
        wwlog("chain: " << _chains->at(i) << "\n");
    }
    for(i=0; i<_resources->size(); i++){
        wwlog("resource: " << _resources->at(i) << "\n");
    }

    wwlog("-----------------------\n");
}








