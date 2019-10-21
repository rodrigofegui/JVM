#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Tipos/ByteCode.hpp"

AttrCnst::AttrCnst (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrCnst::decodificar (FILE *const arq){
    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->cnst_id);
}

void AttrCnst::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Índice para valor da constante: " << this->cnst_id << std::endl;
}

void AttrCnst::deletar (){
    InterAtributo::deletar();
}

AttrExcp::AttrExcp (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrExcp::decodificar (FILE *const arq){
    InterAtributo::decodificar(arq);
    ler_u2(arq, &this->num_excp);
    u2 temp;
    for (int cnt = 0; cnt < this->num_excp; cnt++){
        ler_u2(arq, &temp);
        this->exceptions.push_back(temp);
    }
}

void AttrExcp::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Número de exceções: " << this->num_excp << std::endl;
    for(int i=0; i<this->num_excp; i++) {
        std::cout << tabs << "Execção número " << i << ": " << std::endl;
        std::cout << tabs + '\t' << "Índice para exceção: " << this->exceptions[i]
        << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->exceptions[i])
        << std::endl;
    }
}

void AttrExcp::deletar (){
    std::vector<u2>().swap(this->exceptions);
    InterAtributo::deletar();
}

// InnerClass

AttrClass::AttrClass (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrClass::decodificar (FILE *const arq){
    InterAtributo::decodificar(arq);
    ler_u2(arq, &this->num_classes);
    for (int cnt = 0; cnt < this->num_classes; cnt++){
        InfoClasse temp;
        
        ler_u2(arq, &temp.classe_interna_id);
        ler_u2(arq, &temp.classe_externa_id);
        ler_u2(arq, &temp.nome_interna_id);
        ler_u2(arq, &temp.classe_interna_flag_acesso);
        
        this->classes.push_back(temp);
    }
}

void AttrClass::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "InnerClass" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Número de classes: " << this->num_classes << std::endl;
    int i = 0;
    for (auto &temp : this->classes){
        std::cout << tabs << "Classe número " << i << ": " << std::endl;
        std::cout << tabs + '\t' << "Índice para classe interna: " << temp.classe_interna_id << std::endl;
        std::cout << tabs + '\t' << "Índice para classe externa: " << temp.classe_externa_id << std::endl;
        std::cout << tabs + '\t' << "Índice nome interno: " << temp.nome_interna_id << std::endl;       
        std::cout << tabs + '\t' << "Flag acesso classe interna: " << temp.classe_interna_flag_acesso <<std::endl;
        i++;
    }
}

void AttrClass::deletar (){
    std::vector<InfoClasse>().swap(this->classes);
    InterAtributo::deletar();
}



AttrCode::AttrCode (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrCode::decodificar (FILE *const arq){
    u1 temp;

    InterAtributo::decodificar(arq);

    ler_u2(arq, &this->max_pilha);
    ler_u2(arq, &this->max_locais);
    ler_u4(arq, &this->tam_codigo);

    for (int cnt = 0; cnt < this->tam_codigo; cnt++){
        ler_u1(arq, &temp);
        this->codigo.push_back(temp);
    }

    ler_u2(arq, &this->tam_tab_excessao);

    if (this->tam_tab_excessao){
        for (int cnt =0; cnt < this->tam_tab_excessao; cnt++){
            Excessao excessao(this->tab_simbolos);

            excessao.decodificar(arq);

            this->tab_excessao.push_back(excessao);
        }
    }

    ler_u2(arq, &this->tam_tab_atributos);

    if (this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(&this->tam_tab_atributos, this->tab_simbolos);
        this->tab_atributos->decodificar(arq);
    }
}

void AttrCode::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "Code" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Tamanho máximo da pilha: " << this->max_pilha << std::endl;
    std::cout << tabs + "Tamanho máximo das variáveis locais: " << this->max_locais << std::endl;
    std::cout << tabs + "Tamanho do código: " << this->tam_codigo << std::endl;

    exibir_bytecodes(qnt_tabs + 1);

    std::cout << tabs + "Tamanho da tabela de excessões: " << this->tam_tab_excessao << std::endl;

    if (this->tam_tab_excessao)
        std::cout << tabs + "\tIni.\tFim\tTrat.\tCatch" << std::endl;

    for (auto &excessao : this->tab_excessao)
        excessao.exibir(qnt_tabs + 1);

    std::cout << tabs + "Tamanho da tabela de atributos: " << this->tam_tab_atributos << std::endl;

     if (this->tab_atributos) this->tab_atributos->exibir(qnt_tabs + 1);
}

void AttrCode::exibir_bytecodes (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    for (int cnt = 0; cnt < this->codigo.size(); cnt++){
        u1 bytecode = this->codigo[cnt];

        std::cout << tabs << cnt << ": "
                  << bytecodes[bytecode].mnemonico << std::endl;

        cnt += bytecodes[bytecode].manipulador(this->codigo, cnt, 0);
    }
}

void AttrCode::deletar (){
    std::vector<u1>().swap(this->codigo);

    std::vector<Excessao>().swap(tab_excessao);

    if (this->tab_atributos)
        this->tab_atributos->deletar();

    InterAtributo::deletar();
}



void AttrLinhaNum::decodificar (FILE *const arq){
    ler_u4(arq, &this->tam);

    ler_u2(arq, &this->tam_tab_valores);

    for (int cnt = 0; cnt < this->tam_tab_valores; cnt++){
        InfoNumero info;

        ler_u2(arq, &info.pc_comeco);
        ler_u2(arq, &info.lin_num);

        this->tab_valores.push_back(info);
    }
}

void AttrLinhaNum::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "LineNumberTable" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Tamanho da tabela de numeros: " << this->tam_tab_valores << std::endl;

    for (auto &valores : this->tab_valores){
        std::cout << tabs + '\t';
        std::cout << "Vale " << valores.lin_num;
        std::cout << " após a linha " << valores.pc_comeco <<std::endl;
    }
}

void AttrLinhaNum::deletar (){
    std::vector<InfoNumero>().swap(tab_valores);

    InterAtributo::deletar ();
}



AttrArqFonte::AttrArqFonte (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrArqFonte::decodificar (FILE *const arq){
    InterAtributo::decodificar (arq);

    ler_u2(arq, &this->ind);
}

void AttrArqFonte::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "SourceFile" << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
    std::cout << tabs + "Índice para o nome do arquivo-fonte: " << this->ind;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind) << std::endl;
}

void AttrArqFonte::deletar (){
    InterAtributo::deletar();
}



AttrSilenciado::AttrSilenciado (const u2 ind_nome, InterTabela *const tab_simbolos) :
    InterAtributo(ind_nome, tab_simbolos){
};

void AttrSilenciado::decodificar (FILE *const arq){
    InterAtributo::decodificar(arq);

    fseek(arq, this->tam, SEEK_CUR);
}

void AttrSilenciado::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "Não reconhecido";
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;

    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Tamanho do atributo: " << this->tam << std::endl;
}

void AttrSilenciado::deletar (){
    InterAtributo::deletar();
}
