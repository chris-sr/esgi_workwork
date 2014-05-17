#include <iostream>
#include "factory/factory.h"
#include "factory/chain.h"
#include "factory/worker.h"
#include "factory/tools.h"
#include "factory/types.h"
#include "factory/resource.h"
#include <vector>

int main(){
    ww::Factory f;
    f.create_worker();
    f.create_worker();
    f.create_chain();
    delete f.create_chain();
    f.create_resource();
    f.create_resource();

    return 0;
}

