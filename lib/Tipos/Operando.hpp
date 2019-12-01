#ifndef Operando_HPP
    #define Operando_HPP

    /**
     *  @file   Operando.hpp
     */
    #include <string>
    #include <vector>
    #include <map>
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/ArqClass.hpp"
    
    class Objeto;
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
            u8 tipo_long;
            double tipo_double;
        };
        std::string tipo_string;
        std::vector<Operando*> *lista_operandos = nullptr;
        Objeto* obj = nullptr;


        /** Construtor padrão */
        Operando (){};

        void exibir ();

        // VERIFICAR: ESTAR CAUSANDO MEMORY LEAK
        void deletar (){};
    };

    class Objeto{
        public:
            std::string nome;
            std::map< std::string, Operando* > referencias;
            ArqClass * classe;

            /** Construtor padrão */
            Objeto (std::string nome, ArqClass* classe): nome(nome), classe(classe){};
    };
#endif
