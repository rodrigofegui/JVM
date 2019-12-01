#include <string>
#include "../../lib/Tipos/Operando.hpp"

std::string Operando::get (){
    std::string op;
    switch (this->tag){
        case TAG_INT: op = std::to_string((int) this->tipo_int); break;
        case TAG_FLT: op = std::to_string(this->tipo_float); break;
        case TAG_DBL: op = std::to_string(this->tipo_double); break;
        case TAG_LNG: op = std::to_string((long) this->tipo_long); break;
        case TAG_STR: op = this->tipo_string; break;
        default: op = "Indefinido";
    }

    return op + " ~> " + get_tag(this->tag);
}
