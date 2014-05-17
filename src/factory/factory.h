/* Todo: add coplient support for factory class */

#ifndef FACTORY_H
#define FACTORY_H

#include <vector>

namespace ww{

//Forward declarations
class Worker;
class Chain;
class Resource;
class Task;

class Factory{
public:
                    Factory();
                    ~Factory();
    /*static Factory* get_instance();
    static Factory& get_reference();
    static void     destroy();*/
    Worker*         create_worker();
    Chain*          create_chain();
    Resource*       create_resource();
    void            register_worker(Worker*);
    void            register_chain(Chain*);
    void            register_resource(Resource*);
    void            unregister_worker(Worker*);
    void            unregister_chain(Chain*);
    void            unregister_resource(Resource*);
    void            print();

private:
    /* Functions */
                    /*Factory();
                    ~Factory();*/

    /* Members */
    /*static Factory* _instance;*/

    std::vector<Worker*>*
            _workers;

    std::vector<Chain*>*
            _chains;

    std::vector<Resource*>*
            _resources;
};

}

#endif // FACTORY_H
