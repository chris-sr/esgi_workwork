#ifndef RESOURCE_H
#define RESOURCE_H

namespace ww{

class Resource{
public:
                    Resource();
                    Resource(const Resource&);
                    ~Resource();
    Resource&       operator=(const Resource&);
};

}

#endif // RESOURCE_H
