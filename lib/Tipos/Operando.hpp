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
    #include "../Uteis/Flags_Tags.hpp"

    class Objeto;
    /**
     *  @class Operando
     *  Operandos dos métodos
     */
    class Operando{
    public:
        u1 tag = TAG_VAZ;
        union {
            u4 tipo_bool;
            u4 tipo_byte;
            u4 tipo_char;
            u4 tipo_short;
            u4 tipo_int;
            float tipo_float;
            u8 tipo_long;
            double tipo_double;
        };
        std::string tipo_string;
        std::vector<Operando*> lista_operandos;
        Objeto* obj = nullptr;


        /** Construtor padrão */
        Operando (){};

        std::string get ();

        // VERIFICAR: ESTAR CAUSANDO MEMORY LEAK
        void deletar ();

        Operando* duplicar();
    };

    class Objeto{
        public:
            std::string nome;
            std::map< std::string, Operando* > referencias;
            ArqClass *classe;

            /** Construtor padrão */
            Objeto (std::string const &nome, ArqClass *const classe): nome(nome), classe(classe){};

            Objeto* duplicar();

            void deletar ();
    };
#endif
