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
                    ~Factory();
    static Factory* get_instance();
    static Factory& get_reference();
    void            register_worker(Worker*);
    void            register_chain(Chain*);
    void            register_resource(Resource*);
    void            register_task(Task*);
    void            print();

private:
    /* Functions */
                    Factory();

    /* Members */
    static Factory* _instance;

    std::vector<Worker*>*
            _workers;

    std::vector<Chain*>*
            _chains;

    std::vector<Resource*>*
            _resources;

    std::vector<Task*>*
            _tasks;
};

}

#endif // FACTORY_H
