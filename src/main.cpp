#include <iostream>
#include "application/application.h"
#include "factory/factory.h"
#include "factory/chain.h"
#include "factory/worker.h"
#include "factory/tools.h"

int main(){

//    Application app;
//    app.run();

    try{
        ww::Factory factory;
        factory.create_worker(NULL);
        factory.create_worker(NULL);
        factory.create_worker(NULL);
        factory.create_worker(NULL);
        factory.create_worker(NULL);
        factory.create_worker(NULL);
        factory.create_chain(NULL);
        factory.create_chain("mychain");
        factory.create_chain(NULL);
        factory.print();
    }
    catch(std::exception& e){
        wwlog("Got an std exception:\n")
        wwlog(e.what() << "\n");
    }

    return 0;
}

