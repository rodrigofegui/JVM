#ifndef TIPOS_FRAME_HPP
    #define TIPOS_FRAME_HPP

    /**
     *  @file   Frame.hpp
     */
    #include <vector>
    #include <stack>
    #include "Basicos.hpp"
    #include "../Interfaces/InterTabela.hpp"
    #include "../Interfaces/InterCPDado.hpp"
    #include "../Tipos/Campo.hpp"
    #include "../Tipos/Atributos.hpp"
    #include "../Tipos/Operando.hpp"

    class Frame{
        public:
            u4 pc = 0;
            std::vector<Operando *> var_locais;
            std::stack<Operando *> pilha_operandos;
            InterTabela *tab_simbolos = nullptr;
            Campo *referencia_metodo = nullptr;
            AttrCodigo *attr_codigo = nullptr;

            InterCPDado *a_empilhar = nullptr;
            u1 pode_desempilhar = false;
            Operando *retorno = nullptr;

            Frame () {};
            explicit Frame (Campo *const metodo);

            void executar();

            u1 get_prox_byte ();

            InterCPDado* buscar_simbolo (u2 indice);

            Operando* desempilhar();

            void deletar();
    };
#endif
