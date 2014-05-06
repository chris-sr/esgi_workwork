#ifndef CHAIN_H
#define CHAIN_H

namespace ww{

class Chain{
public:
                        Chain();
                        Chain(const Chain&);
                        ~Chain();
    Chain&              operator=(const Chain&);
};

}

#endif // CHAIN_H
