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
            std::string nome_arq_main;

            /** Arquivos .class em memória */
            std::vector<ArqClass> arquivos;

        public:
            /** Construtor padrão */
            Carregador (){};

            /**
             *  Carregamento dos arquivos .class para a memória, 1 ou mais
             *  @param nomes_arqs Nomes dos arquivos a serem carregados
             */
            void analise_semantica (std::vector<std::string> const &nomes_arqs);

            void carregar (std::string const &nome_arq);

            /**
             *  Exibição dos arquivos .class carregados em memória na saída padrão
             */
            void exibir ();

            /**
             *  Dentre os arquivos considerados pelo sistema, o primeiro que possuir a função
             *  `main` definida será considerado como o arquivo de entrada pelo interpretador
             *  @param arq Arquivo .class que pode conter um método main
             */
            void set_pontoEntrada (std::string const &nome_arq);

            std::string get_pontoEntrada ();

            void liberar_memoria ();

            /**
             *  Destrutor do carregador e suas dependências
             */
            void deletar();
    };
#endif
