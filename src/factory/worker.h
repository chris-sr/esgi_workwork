#ifndef WORKER_H
#define WORKER_H

#include <iostream>

namespace ww{

class Chain;
class Task;

/**
 * A worker is a single unit of the factory
 * which may have a task, and may be affected
 * to a chain.
 * A worker may do (or repeat) a single work at
 * any given time.
 */
class Worker{
friend class Chain;
public:
                    Worker();
                    ~Worker();

/*private:*/
    /* Functions */
    std::string*    _generate_name;

    /* Members */
    Chain*          _affected_chain;
    Task*           _affected_task;
};

}

#endif // WORKER_H
