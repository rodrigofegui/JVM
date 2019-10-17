#ifndef TABELA_SIMBOLO_HPP
    #define TABELA_SIMBOLO_HPP

    /**
     *  @file   TabSimbolos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include <string>
    #include "../Interfaces/InterTabela.hpp"
    #include "../Interfaces/InterCPDado.hpp"

    /**
     *  @class TabSimbolos
     *  Tabela de símbolos do arquivo .class
     */
    class TabSimbolos : public InterTabela {
        private:
            /** Conteúdo da tabela em si */
            std::vector<InterCPDado*> registros;

        public:
            /* Herdando método já implementado */
            explicit TabSimbolos (u2 *const tam) : InterTabela(tam){};

            /**
             *  Decodificador do arquivo binário .class para a tabela de símbolos
             *  @param arq Arquivo .class sob análise
             *  @returns 1 se houver a string `main` definida, 0 se não aconteceu
             *  problemas na decodificação, caso contrário outro número
             */
            u1 decodificar (FILE *const arq) override;

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Recuperação da descrição do item da tabela na posição requisitada, podendo
             *  ser um campo UTF-8, Classe ou Nome e Tipo
             *  @param ind_name Índice da tabela que se está querendo a descrição
             *  @return A string do UTF-8, seja via UTF-8 seja via Classe, ou uma string
             *  no formato "<nome> : <descritor>" caso seja um Nome e Tipo, caso contrário
             *  uma string vazia
             */
            std::string get_string (u2 ind_name);

            /**
             *  Destrutor da tabela e suas dependências
             */
            void deletar () override;
    };
#endif
