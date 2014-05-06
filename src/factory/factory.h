#ifndef FACTORY_H
#define FACTORY_H

#include <list>
#include "boost/timer.hpp"

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

private:
    std::list<Worker*>*
        _workers;

    std::list<Chain*>*
        _chains;
};

}

#endif // FACTORY_H
