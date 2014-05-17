#include "resource.h"

#include "types.h"
#include "factory.h"

ww::Resource::Resource(){
    _factory = NULL;
    /* Notify the factory of a resource creation */
    //Factory::get_reference().register_resource(this);
}

ww::Resource::~Resource(){
    /* Notify the factory of a resource deletion */
    if(NULL != _factory){
        _factory->unregister_resource(this);
    }
    //Factory::get_reference().unregister_resource(this);
}
