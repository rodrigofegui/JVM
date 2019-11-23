#ifndef Operando_HPP
    #define Operando_HPP

    /**
     *  @file   Operando.hpp
     */
    #include <string>
    #include <vector>
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class Operando
     *  Operandos dos métodos
     */
    class Operando{
    public:
        u1 tag;
        union {
          u4 type_bool;
          u4 type_byte;
          u4 type_char;
          u4 type_short;
          u4 type_int;
          u4 type_float;
          uint64_t type_long;
          uint64_t type_double;
        };
        std::string* tipo_string;
        std::vector<Operando*> *lista_operandos;
        
        /** Construtor padrão */
        Operando (){};
    };
#endif
