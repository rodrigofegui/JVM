#ifndef INTERFACE_ATRIBUTO_HPP
    #define INTERFACE_ATRIBUTO_HPP

    /**
     *  @file   InterAtributo.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdio.h>
    #include "InterTabela.hpp"
    #include "../Tipos/Basicos.hpp"

    /**
     *  @class InterAtributo
     *  Interface para todos os tipos de atributos de um arquivo .class
     */
    class InterAtributo {
        protected:
            /** Tabela de símbolos que está vinculado */
            InterTabela *tab_simbolos = nullptr;

        public:
            /** Índice do nome na tabela de símbolos */
            u2 ind_nome = 0;
            /** Tamanho do atributo */
            u4 tam = 0;

            /** Construtor padrão */
            InterAtributo (){};

            /**
             *  Construtor com o conhecimento prévio do índice do nome
             *  @param ind_nome Índice do nome
             */
            explicit InterAtributo (const u2 ind_nome);

            /**
             *  Construtor com o conhecimento prévio tanto do índice do nome quanto da tabela de símbolos que está
             *  vinculado
             *  @param ind_nome Índice do nome
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit InterAtributo (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para um atributo, extraindo todos os seus campos específicos,
             *  caso exista, além do índice do nome e do seu tamanho
             *  @param arq Arquivo .class sob análise
             */
            virtual void decodificar (FILE *const arq);

            /**
             *  Exibição do atributo na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            virtual void exibir (const u1 qnt_tabs) = 0;

            /**
             *  Destrutor de um atributo e suas eventuais dependências
             */
            virtual void deletar ();
    };
#endif
