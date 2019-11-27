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
             *  Verifica se os arquivos passados podem ser considerados arquivos .class,
             *  um feedback é disponibilizado na saída padrão
             *  @param nomes_arqs Nomes dos arquivos a serem analisados
             */
            void analise_semantica (std::vector<std::string> const &nomes_arqs);

            /**
             *  Decodifica e carrega o arquivo em memória
             *  @param nome_arq Nome do arquivo a ser carregado
             */
            void carregar (std::string const &nome_arq);

            /**
             *  Exibição dos arquivos carregados em memória na saída padrão
             */
            void exibir ();

            /**
             *  Dentre os arquivos considerados pelo sistema, o primeiro que possuir a função
             *  `main` definida será considerado como o arquivo de entrada
             *  @param nome_arq Nome do arquivo .class que contém o método main
             */
            void set_pontoEntrada (std::string const &nome_arq);

            /**
             *  Recuperação do nome do arquivo de entrada
             *  @return Nome do arquivo
             */
            std::string get_pontoEntrada ();

            /**
             *  Destrutor do carregador e suas dependências
             */
            void deletar();
    };
#endif
