#ifndef JVM_INTERPRETADOR_HPP
    #define JVM_INTERPRETADOR_HPP

    #include <vector>
    #include "Carregador.hpp"
    #include "../Tipos/Frame.hpp"

    class Interpretador{
        private:
            Carregador *area_metodos = nullptr;
            std::vector<Frame *> pilha_frames;

            void empilhar (Frame const &frame) {};

            Frame desempilhar (){};

            void erro();
        public:
            Interpretador() {};

            explicit Interpretador (Carregador *const area_metodos);

            void executar ();

            void deletar();
    };
#endif
