#ifndef UTEIS_PARAMETROS_HPP
    #define UTEIS_PARAMETROS_HPP

    /**
     *  @file   Parametros.hpp
     *  @brief  Verificação dos parâmetros para a execução deste projeto
     */
    #include <iostream>
    #include <stdlib.h>
    #include <vector>
    #include <string>
    #include <string.h>
    #include "Status.hpp"
    #include "../Tipos/Basicos.hpp"

    /** Controles dos parâmetros */
    #define DELIMITADOR_ARGS    ","
    #define TIPO_ARQ_ACEITO     ".class"

    /**
     *  Verifica os parâmetros passados via linha de comando
     *  @param argc Quantidade de parâmetros
     *  @param argv Argumentos
     *  @return Caso não tenha acontecido algum erro, retorna a flag se é para leitura
     *  ou interpretação
     */
    void check_parametros (int argc, char *argv[]);

    class Parametros {
        private:
            /** Flags de controle: para leitor e exibidor ou interpretador e
             *  para exibir na saída padrão ou num arquivo */
            u1 flags = 0xFF;

            /**
             *  Verifica qual o modo de operação do sistema, podendo ser:
             *  - Leitor e exibidor;
             *  - Interpretador
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            void check_modo (int argc, char *argv[]);

            /**
             *  Verifica qual os arquivos que serão considerados pelo sistema
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            void check_nome_arqs (int argc, char *argv[]);

            /**
             *  Verifica se os textos devem ser exibidos na saída padrão ou se devem ser escritos num arquivo
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            void check_exibicao (int argc, char *argv[]);

            /**
             *  Verifica se o modo de operação foi especificado via linha de comando
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            u1 tem_modo_cli (int argc, char *argv[]);

            /**
             *  Verifica se arquivos foram especificados via linha de comando
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            u1 tem_arqs_cli (int argc, char *argv[]);

            /**
             *  Configuração da flag do modo, considerando a informação dada, seja via linha de comando
             *  seja entrada padrão
             *  @param modo Modo de operação
             */
            void set_modo (std::string modo);

        public:
            /** Arquivos a serem considerados pelo sistema */
            std::vector<std::string> nome_arqs;

            /** Consrutor padrão */
            Parametros(){};

            /** 
             *  Configuração de todas as entradas necessárias para o sistema
             *  @param argc Quantidade de parâmetros
             *  @param argv Argumentos
             */
            void get_entradas (int argc, char *argv[]);

            /**
             *  Verifica se a operação é em leitura
             *  @returns True se for para leitura, False caso contrário
             */
            u1 e_leitura();

            /**
             *  Destrutor dos parâmetros e suas dependências
             */
            void deletar ();
    };
#endif
