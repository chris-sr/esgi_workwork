
class Worker;

#ifndef WORKER_H
#define WORKER_H

#include "boost/thread.hpp"

/////////////Forward declarations
class Task;

/////////////Class declaration
class Worker{
public:
                    Worker(const char*);
    virtual         ~Worker();

    void            start();
    void            stop();
    void            waitEnd();
    void            waitOther(Worker*);
    void            setTask(Task*);

private:
    const char*     _name;
    bool            _continue;
    boost::thread*  _thread;
    static void     _threadMain(Worker*);
    Task*           _task;
};

#endif // WORKER_H
