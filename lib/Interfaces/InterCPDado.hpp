#ifndef INTERFACE_CP_DADO_HPP
    #define INTERFACE_CP_DADO_HPP

    /**
     *  @file   InterCPDado.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <stdio.h>
    #include <iostream>
    #include "InterTabela.hpp"

    /**
     *  @class InterCPDado
     *  Interface para os dados da tabela de símbolos de um arquivo .class
     */
    class InterCPDado{
        protected:
            /** Tabela de símbolos do arquivo .class ao qual os dados pertencem */
            InterTabela *tab_simbolos = nullptr;

        public:
            /** Construtor padrão */
            InterCPDado () : tab_simbolos(nullptr){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos
             *  @param tab_simbolos Tabela de símbolo que está vinculado
             */
            explicit InterCPDado (InterTabela *const tab_simbolos) : tab_simbolos(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para um dado da tabela de
             *  símbolos, extraindo todos os seus campos específicos
             *  @param arq Arquivo .class sob análise
             */
            virtual void decodificar (FILE *const arq) = 0;

            /**
             *  Exibição do dado na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            virtual void exibir (const u1 qnt_tabs) = 0;

            /**
             *  Destrutor de um dado da tabela de símbolos e suas eventuais dependências
             */
            virtual void deletar () {delete this;};
    };
#endif
