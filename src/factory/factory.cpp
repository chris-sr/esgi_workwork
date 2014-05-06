#include "factory.h"
#include "types.h"

ww::Factory::Factory(){
    _workers = new std::list<Worker*>();
    _chains = new std::list<Chain*>();
}

ww::Factory::Factory(const Factory& other){
    this->operator =(other);
}

ww::Factory::~Factory(){

}

ww::Factory&
ww::Factory::operator =(const ww::Factory& other){
    if(this->_chains == other._chains){
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
    wwlog("Updating, delta is " << delta << "\n");
}
