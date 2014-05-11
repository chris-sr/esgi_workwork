#ifndef WORKER_H
#define WORKER_H

#include <iostream>
#include "types.h"

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
friend class Factory;
public:
                    Worker();
                    ~Worker();
    void            affect_task(Task*);

private:
    Task*           _task;
    Chain*          _affected_chain;
    Task*           _affected_task;
};

}

#endif // WORKER_H
