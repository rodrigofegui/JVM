#ifndef TABELA_ATRIBUTOS_HPP
    #define TABELA_ATRIBUTOS_HPP

    /**
     *  @file   TabAtributos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include "../Interfaces/InterAtributo.hpp"
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class TabAtributos
     *  Tabela de atributos, sejam os do arquivo .class em si quanto os de um método
     */
    class TabAtributos : public InterTabela {
        private:
            /** Conteúdo da tabela em si */
            std::vector<InterAtributo*> registros;

        public:
            /* Herdando método já implementado */
            explicit TabAtributos (u2 *const tam, InterTabela *const tab_simbolos) : InterTabela(tam, tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para a tabela de atributos
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
