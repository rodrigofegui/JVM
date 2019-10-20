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
            explicit TabInterfaces (u2 *const tam, InterTabela *const tab_simbolos) : InterTabela(tam, tab_simbolos){};


            /**
             *  Decodificador do arquivo binário .class para a tabela de interfaces
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
             *  Destrutor da tabela e suas dependências
             */
            void deletar () override;
    };
#endif
