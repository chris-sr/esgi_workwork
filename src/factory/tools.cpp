#include "tools.h"

uint
ww::Tools::_index = 10;

uint
ww::Tools::generate_id(){
    return _index++;
}
