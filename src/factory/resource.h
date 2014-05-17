#ifndef RESOURCE_H
#define RESOURCE_H

namespace ww{

//Forward declarations
class Factory;

class Resource{
friend class Factory;

public:
                    Resource();
                    ~Resource();

private:
    Factory*        _factory;
};

}

#endif // RESOURCE_H
