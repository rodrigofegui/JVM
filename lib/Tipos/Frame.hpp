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
            AttrCodigo* attr_codigo = nullptr;

            Frame () {};
            Frame (InterTabela *simbolos, Campo *metodo);
            Frame (InterCPDado *const dados) : Frame() {};
            void executar();
            InterCPDado* buscar_simbolo (u2 indice);
            void a_empilhar (Frame *frame) {};
            void deletar();
    };
#endif
