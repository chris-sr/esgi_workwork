
class Worker;

#ifndef WORKER_H
#define WORKER_H

#include "boost/thread.hpp"

class Worker{
public:
                    Worker();
    virtual         ~Worker();

    void            start();
    void            waitEnd();

private:
    bool            _continue;
    boost::thread*  _t;
    static void     _threadMain();
};

#endif // WORKER_H
