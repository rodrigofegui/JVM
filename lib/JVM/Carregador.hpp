#ifndef JVM_CARREGADOR_HPP
    #define JVM_CARREGADOR_HPP

    #include <vector>
    #include <string>
    #include "../Tipos/ArqClass.hpp"

    class Carregador{
        private:
            std::vector<ArqClass> arquivos;

        public:
            Carregador (){};

            void decodificar (std::vector<std::string> const &nomes_arqs);

            void exibir ();

            void deletar();
    };
#endif
