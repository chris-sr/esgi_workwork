
#include "TaskCarEngine.h"
#include "Utils.h"

TaskCarEngine::TaskCarEngine(){
}

TaskCarEngine::~TaskCarEngine(){
}

void TaskCarEngine::execute(){
    basiclog("Launching task for creating a car engine\n");

    //Emulate some work
    int a = 0;
    while(true){
        a += 3;
        a -= 8;
        a += 6;
        a -= 8;
        a -= 8;
        a -= 8;
        a += 25;
        if(a > 100000000) return;
    }
}
