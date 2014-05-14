#include "task.h"

ww::Task::Task(){
    _completed = false;
    _repeat = false;
    _time_spent = 0;
    _time_required = 1000;
    _result_resource = NULL;
    _required_resources = new Resource*[2];
    _required_resources[0] = NULL;
    _required_resources[1] = NULL;
}

ww::Task::~Task(){
    delete _required_resources;
}

void
ww::Task::set_required(uint idx, Resource* res){
    if(idx >1){
        wwlog("warning: assinging resource at outer range\n");
        return;
    }
    _required_resources[idx] = res;
}

void
ww::Task::set_result(Resource* res){
    wwassert(NULL != res);
    _result_resource = res;
}

ww::Resource*
ww::Task::get_required(uint idx){
    if(idx >1){
        return NULL;
        wwlog("warning: getting resource at outer range\n");
    }

    return _required_resources[idx];
}

ww::Resource*
ww::Task::get_result(){
    return _result_resource;
}




