#ifndef JVM_INTERPRETADOR_HPP
    #define JVM_INTERPRETADOR_HPP

    #include <vector>
    #include "Carregador.hpp"
    #include "../Tipos/Frame.hpp"

    class Interpretador{
        private:
            Carregador *area_metodos = nullptr;
            std::vector<Frame *> pilha_frames;

            void empilhar (Frame *const frame);

            void empilhar (std::string const &nome_metodo);

            void empilhar (std::string const &nome_metodo, std::string const &nome_classe);

            void empilhar (InterCPDado *const dados);

            void empilhar_frame (InterCPDado *const dados);

            void empilhar_operandos (InterCPDado *const dados);

            void manipular_estaticos(InterCPDado *const dados);

            Frame* topo ();

            Frame* desempilhar ();

        public:
            Interpretador() {};

            explicit Interpretador (Carregador *const area_metodos);

            void executar ();

            void deletar();
    };
#endif
