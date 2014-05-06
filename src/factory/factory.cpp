#include "factory.h"

#include <iostream>
#include <sstream>
#include "types.h"
#include "chain.h"
#include "worker.h"

ww::Factory::Factory(){
    _workers = new std::list<Worker*>();
    _chains = new std::list<Chain*>();
    _factory_mutex = new boost::mutex();
}

ww::Factory::Factory(const Factory& other){
    this->operator =(other);
}

ww::Factory::~Factory(){

}

ww::Factory&
ww::Factory::operator =(const ww::Factory& other){
    if(this->_factory_mutex == other._factory_mutex){
        return *this;
    }

    delete _chains;
    delete _workers;

    _chains = new std::list<Chain*>();
    std::list<Chain*>::iterator it_chains = other._chains->begin();
    while(it_chains != other._chains->end()){
        _chains->push_back(*it_chains);
        it_chains++;
    }

    _workers = new std::list<Worker*>();
    std::list<Worker*>::iterator it_workers = other._workers->begin();
    while(it_workers != other._workers->end()){
        _workers->push_back(*it_workers);
        it_workers++;
    }

    return *this;
}

void
ww::Factory::update(double delta){
    //wwlog("Updating, delta is " << delta << "\n");
}

void
ww::Factory::print(){
    std::list<Chain*>::iterator it_chains = _chains->begin();
    while(it_chains != _chains->end()){
        wwlog("chain: " << (*it_chains)->get_name() << "\n");
        it_chains++;
    }

    std::list<Worker*>::iterator it_workers = _workers->begin();
    while(it_workers != _workers->end()){
        wwlog("worker: " << (*it_workers)->get_name() << "\n");
        it_workers++;
    }
}

ww::Chain*
ww::Factory::create_chain(const char* chain_name){
    Chain* c = new Chain(chain_name);
    _factory_mutex->lock();
    _chains->push_back(c);
    wwlog("added chain " << c->get_name() << " to factory's list\n");
    _factory_mutex->unlock();
    return c;
}

ww::Worker*
ww::Factory::create_worker(const char* worker_name){
    Worker* c = new Worker(worker_name);
    _factory_mutex->lock();
    _workers->push_back(c);
    wwlog("added worker " << c->get_name() << " to factory's list\n");
    _factory_mutex->unlock();
    return c;
}







