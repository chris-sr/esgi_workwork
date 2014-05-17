#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

namespace ww{

//Forward declarations
class Worker;
class Factory;

/**
 * A chain is a machine which gathers workers and sends
 * them resources to craft or morph, according to these
 * workers' tasks.
 */
class Chain{
friend class Factory;

public:
                    Chain();
                    ~Chain();
    void            affect_worker(Worker*);
    void            reject_worker(Worker*);

private:
    std::vector<Worker*>*
            _affected_workers;

    Factory*        _factory;
};

}

#endif // CHAIN_H
