#ifndef TIPOS_EXCESSAO_HPP
    #define TIPOS_EXCESSAO_HPP

    /**
     *  @file   Excessao.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include "../Interfaces/InterTabela.hpp"

    /**
     *  @class Excessao
     *  Excessão aos métodos existentes
     */
    class Excessao{
        private:
            InterTabela *tab_simbolos = nullptr;

            /** Estrutura de uma excessão */
            u2 lin_comeco = 0;
            u2 lin_final = 0;
            u2 lin_tratamento = 0;
            u2 ind_tipo_catch = 0;

        public:
            /** Construtor padrão */
            Excessao (){};

            explicit Excessao (InterTabela *const tab_simbolos) : tab_simbolos(tab_simbolos){};

            /**
             *  Decodificador do arquivo binário .class para uma excessão, extraindo todos
             *  os seus campos
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *arq);

            /**
             *  Exibição de uma excessão na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs);
    };
#endif
