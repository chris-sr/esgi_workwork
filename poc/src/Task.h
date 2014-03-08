
class Task;

#ifndef TASK_H
#define TASK_H

class Task{
public:
                    Task();
    virtual         ~Task();
    virtual void    execute()=0;
};

#endif // TASK_H

