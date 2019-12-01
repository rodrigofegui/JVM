#ifndef INTERFACE_CP_DADO_HPP
    #define INTERFACE_CP_DADO_HPP

    /**
     *  @file   InterCPDado.hpp
     */
    #include <stdio.h>
    #include <iostream>
    #include "InterTabela.hpp"

    /**
     *  @class InterCPDado
     *  Interface para os dados da tabela de símbolos de um arquivo .class
     */
    class InterCPDado{
        public:
            /** Tabela de símbolos do arquivo .class ao qual os dados pertencem */
            u1 tag;
            InterTabela *tab_simbolos = nullptr;
            /** Construtor padrão */
            InterCPDado () : tab_simbolos(nullptr), tag(0){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos
             *  @param tab_simbolos Tabela de símbolo que está vinculado
             */
            explicit InterCPDado (InterTabela *const tab_simbolos, u1 tag) : tab_simbolos(tab_simbolos), tag(tag){};

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

            virtual std::string get () = 0;

            /**
             *  Destrutor de um dado da tabela de símbolos e suas eventuais dependências
             */
            virtual void deletar () {delete this;};
    };
#endif
