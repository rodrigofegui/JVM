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
            u4 tipo_bool;
            u4 tipo_byte;
            u4 tipo_char;
            u4 tipo_short;
            u4 tipo_int;
            u4 tipo_float;
            uint64_t tipo_long;
            uint64_t tipo_double;
        };
        std::string tipo_string;
        std::vector<Operando*> *lista_operandos = nullptr;

        /** Construtor padrão */
        Operando (){};

        // VERIFICAR: ESTAR CAUSANDO MEMORY LEAK
        void deletar (){};
    };
#endif
