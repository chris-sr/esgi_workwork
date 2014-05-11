#include "resource.h"
#include "factory.h"

ww::Resource::Resource(){

    /* Notify the factory of a resource creation */
    Factory::get_reference().register_resource(this);
}

ww::Resource::~Resource(){

    /* Notify the factory of a resource deletion */
    Factory::get_reference().unregister_resource(this);
}
