#ifndef TIPOS_FRAME_HPP
    #define TIPOS_FRAME_HPP

    /**
     *  @file   Frame.hpp
     */
    #include <vector>
    #include <stack>
    #include "Basicos.hpp"
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"
    #include "../Tipos/Atributos.hpp"
    #include "../Tipos/Operando.hpp"

    class Frame{
        public:
            u4 pc;
            std::vector<Operando *> var_locais;
            std::stack<Operando *> pilha_operandos;
            InterTabela *tab_simbolos = nullptr;
            Campo *referencia_metodo = nullptr;
            AttrCodigo* attr_codigo = nullptr;
            Frame(InterTabela *, Campo *);
            void executar();
            InterCPDado* buscar (u2 indice);
            void a_empilhar (Frame *frame) {};
            void deletar();
    };
#endif
