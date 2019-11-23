#ifndef JVM_CARREGADOR_HPP
    #define JVM_CARREGADOR_HPP

    /**
     *  @file   Carregador.hpp
     */
    #include <vector>
    #include <string>
    #include "../Tipos/ArqClass.hpp"

    /**
     *  @class Carregador
     *  Inicialização das classes e interfaces, verifica a corretude dos arquivos
     *  .class e os carrega na memória, caso não haja problemas
     */
    class Carregador{
        private:
            /** Arquivo .class com a função main */
            ArqClass *pontoEntrada = nullptr;

            /** Arquivos .class em memória */
            std::vector<ArqClass> arquivos;

        public:
            /** Construtor padrão */
            Carregador (){};

            /**
             *  Carregamento dos arquivos .class para a memória, 1 ou mais
             *  @param nomes_arqs Nomes dos arquivos a serem carregados
             */
            void carregar (std::vector<std::string> const &nomes_arqs);

            /**
             *  Exibição dos arquivos .class carregados em memória na saída padrão
             */
            void exibir ();

            /**
             *  Dentre os arquivos considerados pelo sistema, o primeiro que possuir a função
             *  `main` definida será considerado como o arquivo de entrada pelo interpretador
             *  @param arq Arquivo .class que pode conter um método main
             */
            void set_pontoEntrada (ArqClass *const arq);

            ArqClass * get_pontoEntrada ();

            /**
             *  Destrutor do carregador e suas dependências
             */
            void deletar();
    };
#endif
