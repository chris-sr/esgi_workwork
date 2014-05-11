#ifndef TASK_H
#define TASK_H

#include <vector>
#include "types.h"

namespace ww{

class Resource;

class Task{
friend class Worker;
public:
                    Task();
    virtual         ~Task();
    void            progress(uint);
    void            set_required(uint, Resource*);
    Resource*       get_required(uint);
    Resource*       get_result();
    void            set_result(Resource*);

private:
    Resource**      _required_resources;
    Resource*       _result_resource;
    uint            _time_required;
    uint            _time_spent;
    bool            _completed;
    bool            _repeat;
};

}

#endif // TASK_H
