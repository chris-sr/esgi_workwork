#ifndef TOOLS_H
#define TOOLS_H

#include "types.h"

namespace ww{

class Tools{
public:
    static uint     generate_id();
private:
    static uint
                    _index;
};

}

#endif // TOOLS_H
