#ifndef TABELA_INTERFACE_HPP
    #define TABELA_INTERFACE_HPP

    /**
     *  @file   TabInterface.hpp
     */
    #include <vector>
    #include <string>
    #include "../Interfaces/InterTabela.hpp"
    #include "../Tipos/CPDados.hpp"

    /**
     *  @class TabInterfaces
     *  Tabela de interfaces do arquivo .class
     */
    class TabInterfaces : public InterTabela {
        private:
            /** Conteúdo da tabela em si */
            std::vector<u2> registros;

        public:
            /* Herdando método já implementado */
            explicit TabInterfaces (const u2 tam, InterTabela *const tab_simbolos) : InterTabela(tam, tab_simbolos){};


            /**
             *  Decodificador do arquivo binário .class para a tabela de interfaces
             *  @param arq Arquivo .class sob análise
             *  @returns Retorna 0 para demonstrar que não aconteceu
             *  problemas na decodificação
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
