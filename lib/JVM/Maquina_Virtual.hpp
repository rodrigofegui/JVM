#ifndef JVM_MAQUINA_VIRTUAL_HPP
    #define JVM_MAQUINA_VIRTUAL_HPP

    #include "Carregador.hpp"
    #include "../Uteis/Parametros.hpp"
    #include "../Tipos/ByteCode.hpp"

    class MaquinaVirtual{
        private:
            Parametros parametros;
            Carregador carregador;

        public:
            MaquinaVirtual (){};

            void iniciar (int argc, char *argv[]);

            void executar ();

            void deletar();
    };
#endif
