
class TaskCarDoor;

#ifndef TASK_DOOR_H
#define TASK_DOOR_H

#include "Task.h"

class TaskCarDoor: public Task{
public:
                    TaskCarDoor();
                    ~TaskCarDoor();
    void            execute();
};

#endif // TASK_DOOR_H
