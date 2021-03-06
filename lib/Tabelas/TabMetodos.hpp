#ifndef TABELA_METODOS_HPP
    #define TABELA_METODOS_HPP

    /**
     *  @file   TabMetodos.hpp
     */
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    /**
     *  @class TabMetodos
     *  Tabela de métodos do arquivo .class
     */
    class TabMetodos : public InterTabela {
        public:
            /** Conteúdo da tabela em si */
            std::vector<Campo> registros;

            /* Herdando método já implementado */
            explicit TabMetodos (const u2 tam, InterTabela *const tab_simbolos) : InterTabela(tam, tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para a tabela de métodos
             *  @param arq Arquivo .class sob análise
             *  @returns 0 se não aconteceu problemas na decodificação, caso contrário
             *  outro número
             */
            u1 decodificar (FILE *arq) override;

            Campo* buscar (const std::string &nome);

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (u1 qnt_tabs) override;

            /**
             *  Destrutor da tabela e suas dependências
             */
            void deletar () override;
    };
#endif
