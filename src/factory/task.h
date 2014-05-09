#ifndef TASK_H
#define TASK_H

#include <vector>

namespace ww{

class Resource;

class Task{
public:
                    Task();
    virtual         ~Task();

private:
    std::vector<Resource*>*
            _required_resources;
};

}

#endif // TASK_H
