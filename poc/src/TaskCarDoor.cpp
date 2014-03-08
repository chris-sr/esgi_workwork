
#include "TaskCarDoor.h"
#include "Utils.h"

TaskCarDoor::TaskCarDoor(){
}

TaskCarDoor::~TaskCarDoor(){
}

void TaskCarDoor::execute(){
    basiclog("Launching task for creating a door\n");

    //Emulate some work
    int a = 0;
    while(true){
        a += 3;
        a -= 8;
        a += 6;
        if(a > 100000000) return;
    }
}
