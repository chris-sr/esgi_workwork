#include <iostream>
//#include "application/application.h"
#include "factory/factory.h"
#include "factory/chain.h"
#include "factory/worker.h"
#include "factory/tools.h"
#include <vector>

int main(){

//    ww::Factory* factory = ww::Factory::get_instance();
//    ww::Factory factory = ww::Factory::get_reference();

    ww::Worker wa;
    ww::Worker wb;
    ww::Worker wc;
    ww::Worker wd;
    ww::Worker we;
    ww::Worker wf;

    ww::Factory::get_reference().print();
    wwlog("A worker has a size of " << sizeof(ww::Worker)) << "\n";

    /*
    Application app;
    app.run();

    ww::Factory factory;
    factory.create_worker(NULL);
    factory.create_worker(NULL);
    factory.create_worker("frank");
    factory.create_worker("bob");
    factory.create_worker(NULL);
    factory.create_worker(NULL);
    factory.create_chain(NULL);
    factory.create_chain("mychain");
    factory.create_chain(NULL);
    factory.print();

    ww::Chain* mychain = factory.create_chain("Weapons crafting");
    mychain->affect_worker(NULL,100);

    std::vector<ww::Worker*>* vec = new std::vector<ww::Worker*>();
    vec->push_back(factory.create_worker("a"));
    vec->push_back(factory.create_worker("b"));
    vec->push_back(factory.create_worker("c"));
    ww::Worker* workerinsert = factory.create_worker("ins");

    vec->insert(vec->begin()+,1,workerinsert);
    std::cout << "0:" << vec->at(0)->get_name() << "\n";
    std::cout << "1:" << vec->at(1)->get_name() << "\n";
    std::cout << "2:" << vec->at(2)->get_name() << "\n";
    std::cout << "3:" << vec->at(3)->get_name() << "\n";
    std::cout << vec->at(3)->get_name << "\n";
    */

    return 0;
}

