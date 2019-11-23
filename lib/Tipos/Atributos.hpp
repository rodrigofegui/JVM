#ifndef TIPOS_ATRIBUTOS_HPP
    #define TIPOS_ATRIBUTOS_HPP

    /**
     *  @file   Atributos.hpp
     */
    #include <vector>
    #include "../Tabelas/TabAtributos.hpp"
    #include "../Tipos/Excessao.hpp"


    /**
     *  @class AttrVlrConst
     *  Atributo do tipo __ConstantValue__, presente somente nos campos
     */
    class AttrVlrConst : public InterAtributo {
        private:
            /* Estrutura de um atributo __ConstantValue__ */
            u2 cnst_id = 0;

        public:
            /* Herdando método já implementado */
            explicit AttrVlrConst (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __ConstantValue__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __ConstantValue__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __ConstantValue__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrExcp
     *  Atributo do tipo __Exception__, presente somente nos métodos
     */
    class AttrExcp : public InterAtributo {
        private:
            /* Estrutura de um atributo __Exception__ */
            u2 num_excp = 0;
            std::vector<u2> exceptions;

        public:
            /* Herdando método já implementado */
            explicit AttrExcp (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __Exception__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Exception__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __Exception__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrClass
     *  Atributo do tipo __InnerClass__, presente somente na tabela de atributos com estrutura ClassFile
     */
    class AttrClass : public InterAtributo {
        private:
            /** Estrutura do array de classes de um atributo __InnerClass__ */
            typedef struct info_classe {
                u2 classe_interna_id;
                u2 classe_externa_id;
                u2 nome_interna_id;
                u2 classe_interna_flag_acesso;
            } InfoClasse;

            /* Estrutura de um atributo __InnerClass__ */
            u2 num_classes = 0;
            std::vector<InfoClasse> classes;

        public:
            /* Herdando método já implementado */
            explicit AttrClass (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __InnerClass__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __InnerClass__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __InnerClass__ e suas dependências
             */
            void deletar () override;
    };

    /**
     *  @class AttrCodigo
     *  Atributo do tipo __Code__, presente somente nos métodos
     */
    class AttrCodigo : public InterAtributo {
        public:
            /* Estrutura de um atributo __Code__ */
            u2 max_pilha = 0;
            u2 max_locais = 0;
            u4 tam_codigo = 0;
            std::vector<u1> codigo;
            u2 tam_tab_excessao = 0;
            std::vector<Excessao> tab_excessao;
            u2 tam_tab_atributos = 0;
            TabAtributos *tab_atributos = nullptr;

            /* Herdando método já implementado */
            explicit AttrCodigo (const u2 ind_nome, InterTabela *const tab_simbolos);

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
     *  @class AttrSintetico
     *  Atributo do tipo __Synthetic__
     */
    class AttrSintetico : public InterAtributo {
       public:
            /* Herdando método já implementado */
            explicit AttrSintetico (const u2 ind_nome, InterTabela *const tab_simbolos);

            /**
             *  Decodificador do arquivo binário .class para o atributo __Synthetic__,
             *  extraindo todos os seus campos, além do índice do nome e do seu tamanho,
             *  caso já não os tenha extraído
             *  @param arq Arquivo .class sob análise
             */
            void decodificar (FILE *const arq) override;

            /**
             *  Exibição do atributo __Synthetic__ na saída padrão, conhecendo-se o controle de tabulação
             *  @param qnt_tabs Quantidade de TABs
             */
            void exibir (const u1 qnt_tabs) override;

            /**
             *  Destrutor do atributo __Synthetic__ e suas dependências
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
