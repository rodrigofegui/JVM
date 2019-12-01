#include <iostream>
#include "../../lib/Tipos/Operando.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


void Operando::exibir (){
    switch (this->tag){
        case TAG_INT: std::cout << this->tipo_int << std::endl; break;
        case TAG_DBL: std::cout << this->tipo_double << std::endl; break;
        case TAG_LNG: std::cout << this->tipo_long << std::endl; break;
        case TAG_STR: std::cout << this->tipo_string << std::endl; break;
        default:
            std::cout << "Indefinido, tag: " << (int)this->tag << std::endl;
    }
}
