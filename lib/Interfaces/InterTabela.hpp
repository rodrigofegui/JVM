#ifndef INTERFACE_TABELA_HPP
    #define INTERFACE_TABELA_HPP

    /**
     *  @file   InterTabela.hpp
     */
    #include <stdio.h>
    #include "../Tipos/Basicos.hpp"

    /**
     *  @class InterTabela
     *  Interface para as tabelas de um arquivo .class
     */
    class InterTabela {
        protected:
            /** Tabela de símbolos que está vinculada */
            InterTabela *tab_simbolos = nullptr;

            /** Ref. para o tamanho da tabela */
            u2 tam = 0;

        public:
            /** Construtor padrão */
            InterTabela ();

            /**
             *  Construtor com o conhecimento prévio do seu tamanho
             *  @param tam Tamanho a ser atribuido à tabela
             */
            explicit InterTabela (const u2 tam) : tam(tam) {};

            /**
             *  Construtor com o conhecimento prévio tanto do seu tamanho quanto da tabela de símbolos que está vinculada
             *  @param tam Tamanho a ser atribuido à tabela
             *  @param tab_simbolos Tabela de símbolos que está vinculada
             */
            explicit InterTabela (const u2 tam, InterTabela *const tab_simbolos) : tam(tam), tab_simbolos(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para uma tabela, extraindo todos
             *  os seus registros específicos
             *  @param arq Arquivo .class sob análise
             *  @returns 0 se não aconteceu problemas na decodificação, caso contrário
             *  outro número
             */
            virtual u1 decodificar (FILE *const arq) = 0;

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            virtual void exibir (const u1 qnt_tabs) = 0;

            /**
             *  Destrutor de uma tabela e suas dependências
             */
            virtual void deletar () = 0;
    };
#endif
