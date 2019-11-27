#ifndef JVM_INTERPRETADOR_HPP
    #define JVM_INTERPRETADOR_HPP

    #include <vector>
    #include "../Tipos/ArqClass.hpp"
    #include "../Tipos/Frame.hpp"

    class Interpretador{
        private:
            ArqClass pontoEntrada;
            std::vector<Frame *> pilha_frames;

            void empilhar (Frame const &frame);

            Frame desempilhar ();

            void erro();
        public:
            Interpretador() {};

            Interpretador (ArqClass const &arq) : pontoEntrada(arq){};

            void executar ();

            void deletar();
    };
#endif
