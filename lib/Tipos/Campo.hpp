#ifndef TIPOS_CAMPO_HPP
    #define TIPOS_CAMPO_HPP

    /**
     *  @file   Campo.hpp
     */
    #include <vector>
    #include "../Interfaces/InterTabela.hpp"
    // #include "Operando.hpp" // VERIFICAR: para o putstatic

    /**
     *  @class Campo
     *  Campo presente tanto na tabela de campos quanto na de métodos
     */
    class Campo {
        public:
            /** Tabela de símbolos que está vinculado */
            InterTabela *tab_simbolos = nullptr;

            /** Estrutura de um campo */
            u2 flag_acesso = 0;
            u2 ind_nome = 0;
            u2 ind_descritor = 0;
            u2 tam_tab_atributos = 0;
            InterTabela *tab_atributos = nullptr;
            // Operando *valor = nullptr; // VERIFICAR: para o putstatic

            /** Construtor padrão */
            Campo (){};

            /**
             *  Construtor com o conhecimento prévio da tabela de símbolos que está
             *  vinculado
             *  @param tab_simbolos Tabela de símbolos que está vinculado
             */
            explicit Campo (InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para um campo, extraindo todos os
             *  seus dados específicos, além de seus atributos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq);

            std::string get_nome ();

            std::string get_descritor ();

            int get_quantidade_argumentos ();

            /**
             *  Exibição de um campo na saída padrão, com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs);

            /**
             *  Destrutor de um campo e suas dependências
             */
            void deletar ();
    };
#endif
