#ifndef CHAIN_H
#define CHAIN_H

#include <vector>

namespace ww{

class Worker;

class Chain{
public:
                    Chain();
                    ~Chain();

private:
    std::vector<Worker*>*
            _affected_workers;
};

}

#endif // CHAIN_H
