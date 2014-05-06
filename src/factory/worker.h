#ifndef WORKER_H
#define WORKER_H

namespace ww{

class Worker{

public:
                        Worker();
                        Worker(const Worker&);
                        ~Worker();
    Worker&             operator=(const Worker&);
};

}

#endif // WORKER_H
