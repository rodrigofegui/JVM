#ifndef TABELA_CAMPOS_HPP
    #define TABELA_CAMPOS_HPP

    /**
     *  @file   TabCampos.hpp
     */
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/Campo.hpp"

    /**
     *  @class TabCampos
     *  Tabela de campos do arquivo .class
     */
    class TabCampos : public InterTabela {
        private:
            /** Conteúdo da tabela em si */
            std::vector<Campo> registros;

        public:
            /* Herdando método já implementado */
            explicit TabCampos (const u2 tam, InterTabela *const tab_simbolos) : InterTabela(tam, tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para a tabela de campos
             *  @param arq Arquivo .class sob análise
             *  @returns 0 se não aconteceu problemas na decodificação, caso contrário
             *  outro número
             */
            u1 decodificar (FILE *const arq) override;

            /**
             *  Exibição da tabela na saída padrão com controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor da tabela e suas dependências
             */
            void deletar () override;
    };
#endif
