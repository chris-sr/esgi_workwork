#include "worker.h"

#include <sstream>
#include "tools.h"

ww::Worker::Worker(){
    _name = this->_generate_name();
}

ww::Worker::Worker(const char* name){
    if(NULL == name){
        _name = this->_generate_name();
    }else{
        _name = new std::string(name);
    }
}

ww::Worker::Worker(const Worker& other){
    this->operator =(other);
}

ww::Worker::~Worker(){
    delete _name;
}

ww::Worker&
ww::Worker::operator=(const Worker& other){
    if(_name == other._name){
        return *this;
    }

    delete _name;
    _name = new std::string(other.get_name());
    return *this;
}

std::string&
ww::Worker::get_name() const{
    return *_name;
}

std::string*
ww::Worker::_generate_name(){
    std::stringstream name;
    name << "Worker_" << Tools::generate_id();
    return new std::string(name.str());
}










//#include "worker.h"

//ww::Worker::Worker(){

//}

//ww::Worker::Worker(const Worker& other){

//}

//ww::Worker::~Worker(){

//}

//ww::Worker&
//ww::Worker::operator=(const Worker& other){
//    return *this;
//}
