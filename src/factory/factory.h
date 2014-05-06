#ifndef FACTORY_H
#define FACTORY_H

#include <list>
#include "boost/thread.hpp"

namespace ww{

class Worker;
class Chain;

class Factory{
public:
                        Factory();
                        Factory(const Factory&);
                        ~Factory();
    Factory&            operator=(const Factory&);
    void                update(double);
    void                print();
    Worker*             create_worker(const char*);
    Chain*              create_chain(const char*);

private:
    boost::mutex*       _factory_mutex;

    std::list<Worker*>*
        _workers;

    std::list<Chain*>*
        _chains;
};

}

#endif // FACTORY_H
