#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/Campo.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


Campo::Campo (InterTabela *const tab_simbolos) : Campo(){
    this->tab_simbolos = tab_simbolos;
}

void Campo::decodificar (FILE *const arq){
    this->tam_tab_atributos = 0;

    ler_u2(arq, &this->flag_acesso);
    ler_u2(arq, &this->ind_nome);
    ler_u2(arq, &this->ind_descritor);
    ler_u2(arq, &this->tam_tab_atributos);

    if(this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(this->tam_tab_atributos, this->tab_simbolos);
        this->tab_atributos->decodificar(arq);
    }
}

std::string Campo::get_nome (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome);
}

std::string Campo::get_descritor (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_descritor);
}

int Campo::get_quantidade_argumentos (){
    std::string descritor = get_descritor();
    int qnt_args = 0;

    for (int pos = 1; pos < descritor.size(); pos++){
        if (descritor[pos] == ')') break;

        if (descritor[pos] == 'L'){
            qnt_args++;
            pos++;

            while (descritor[pos++] != ';');
        }

        qnt_args++;

        if (descritor[pos] == '[') break;
    }

    return qnt_args;
}

void Campo::exibir (const u1 qnt_tabs){
    if (!this) return;

    std::string tabs(qnt_tabs, '\t');

    std::cout << get_nome() << std::endl;

    std::cout << tabs + "Flag de acesso: " << get_flag(this->flag_acesso) << std::endl;
    std::cout << tabs + "Índice para o nome: " << this->ind_nome << std::endl;
    std::cout << tabs + "Índice para o descritor: " << this->ind_descritor;
    std::cout << " -> " << get_descritor() << std::endl;
    std::cout << tabs + "Qnt. de entradas na tabela de atributos: " << this->tam_tab_atributos << std::endl;

    if (this->tab_atributos)
        this->tab_atributos->exibir(qnt_tabs + 1);
}

void Campo::deletar (){
    if (this->tab_atributos)
        this->tab_atributos->deletar();
}
