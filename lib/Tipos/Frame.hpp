#ifndef TIPOS_FRAME_HPP
    #define TIPOS_FRAME_HPP

    /**
     *  @file   Frame.hpp
     */
    #include <vector>
    #include "Basicos.hpp"
    #include "../Interfaces/InterTabela.hpp"

    class Frame{
        private:
            std::vector<u2> var_locais;
            std::vector<u2> parametros;
            InterTabela *tab_simbolos = nullptr;

        public:
            Frame(){};

            void deletar();
    }
#endif
