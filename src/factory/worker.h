#ifndef WORKER_H
#define WORKER_H

#include <iostream>

namespace ww{

class Worker{

public:
                        Worker();
                        Worker(const char*);
                        Worker(const Worker&);
                        ~Worker();
    Worker&             operator=(const Worker&);
    std::string&         get_name() const;

private:
    static std::string* _generate_name();

    std::string*        _name;
};

}

#endif // WORKER_H
