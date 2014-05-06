#include "chain.h"

#include <iostream>
#include <sstream>
#include "tools.h"

ww::Chain::Chain(){
    _name = this->_generate_name();
}

ww::Chain::Chain(const char* name){
    if(NULL == name){
        _name = this->_generate_name();
    }else{
        _name = new std::string(name);
    }
}

ww::Chain::Chain(const Chain& other){
    this->operator =(other);
}

ww::Chain::~Chain(){
    delete _name;
}

ww::Chain&
ww::Chain::operator=(const Chain& other){
    if(_name == other._name){
        return *this;
    }

    delete _name;
    _name = new std::string(other.get_name());
    return *this;
}

std::string&
ww::Chain::get_name() const{
    return *_name;
}

std::string*
ww::Chain::_generate_name(){
    std::stringstream name;
    name << "Chain_" << Tools::generate_id();
    return new std::string(name.str());
}








