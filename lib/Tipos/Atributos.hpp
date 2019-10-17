#ifndef TIPOS_ATRIBUTOS_HPP
    #define TIPOS_ATRIBUTOS_HPP

    /**
     *  @file   Atributos.hpp
     *  @author Rodrigo F. Guimarães
     */
    #include <vector>
    #include "../Tabelas/TabAtributos.hpp"
    #include "../Tipos/Excessao.hpp"

    /**
     *  @class AttrCode
     *  Atributo do tipo __Code__, presente somente nos métodos
     */
    class AttrCode : public InterAtributo {
        private:
            /* Estrutura de um atributo __Code__ */
            u2 max_pilha = 0;
            u2 max_locais = 0;
            u4 tam_codigo = 0;
            std::vector<u1> codigo;
            u2 tam_tab_excessao = 0;
            std::vector<Excessao> tab_excessao;
            u2 tam_tab_atributos = 0;
            TabAtributos *tab_atributos = nullptr;

        public:
            /* Herdando método já implementado */
            explicit AttrCode (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __Code__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Code__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            void exibir_bytecodes (const u1 qnt_tabs);

            /**
             *  Destrutor do atributo __Code__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrLinhaNum
     *  Atributo do tipo __LineNumberTable__, comulmente associados aos atributos __Code__
     */
    class AttrLinhaNum : public InterAtributo {
        private:
            /** Estrutura dos número de um atributo __LineNumberTable__ */
            typedef struct info_num {
                u2 pc_comeco;
                u2 lin_num;
            } InfoNumero;

            /** Estrutura de um atributo __LineNumberTable__ */
            u2 tam_tab_valores = 0;
            std::vector<InfoNumero> tab_valores;

        public:
            /* Herdando método já implementado */
            explicit AttrLinhaNum (const u2 ind_nome) : InterAtributo(ind_nome){};

            /**
             *  Decodificador do arquivo binário .class para o atributo
             *  __LineNumberTable__, extraindo todos os seus campos, além do índice do
             *  nome e do seu tamanho, caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Code__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __LineNumberTable__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrArqFonte
     *  Atributo do tipo __SourceFile__
     */
    class AttrArqFonte : public InterAtributo {
        private:
            /** Estrutura de um atributo __SourceFile__ */
            u2 ind = 0;

        public:
            /* Herdando método já implementado */
            explicit AttrArqFonte (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __SourceFile__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Code__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __SourceFile__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrSilenciado
     *  Atributo sem tipo tratável
     */
    class AttrSilenciado : public InterAtributo {
        public:
            /* Herdando método já implementado */
            explicit AttrSilenciado (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo não tratável para
             *  o seu índice do nome e o seu tamanho, caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Code__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo não tratável e suas dependências
             */
            void deletar () override;
    };
#endif
