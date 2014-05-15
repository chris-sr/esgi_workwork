
class TaskCarEngine;

#ifndef TASK_ENGINE_H
#define TASK_ENGINE_H

#include "Task.h"

class TaskCarEngine: public Task{
public:
                    TaskCarEngine();
                    ~TaskCarEngine();
    void            execute();
};

#endif // TASK_ENGINE_H

