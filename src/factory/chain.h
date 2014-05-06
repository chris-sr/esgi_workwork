#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>

namespace ww{

class Chain{
public:
                        Chain();
                        Chain(const char*);
                        Chain(const Chain&);
                        ~Chain();
    Chain&              operator=(const Chain&);

    std::string&        get_name() const;

private:
    static std::string* _generate_name();

    std::string*        _name;

};

}

#endif // CHAIN_H
