#include <iostream>
//#include "application/application.h"
#include "factory/factory.h"
#include "factory/chain.h"
#include "factory/worker.h"
#include "factory/tools.h"
#include "factory/types.h"
#include <vector>

int main(){
    ww::Worker* wa = new ww::Worker();
    ww::Worker* wb = new ww::Worker();
    ww::Worker* wc = new ww::Worker();
    ww::Chain* ca = new ww::Chain();
    ww::Chain* cb = new ww::Chain();
    ca->affect_worker(wa);
    ca->affect_worker(wb);
    ca->affect_worker(wc);
    cb->affect_worker(wa);
    cb->affect_worker(wb);
    cb->affect_worker(wc);

    return 0;
}

