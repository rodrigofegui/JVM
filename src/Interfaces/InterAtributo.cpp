#include <iostream>
#include "../../lib/Interfaces/InterAtributo.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


InterAtributo::InterAtributo (const u2 ind_nome) : InterAtributo(){
    this->ind_nome = ind_nome;
}

InterAtributo::InterAtributo (const u2 ind_nome, InterTabela *const tab_simbolos) : InterAtributo(ind_nome){
    this->tab_simbolos = tab_simbolos;
}

void InterAtributo::decodificar (FILE *const arq){
    if (!this->ind_nome)
        ler_u2(arq, &this->ind_nome);

    if (!this->tam)
        ler_u4(arq, &this->tam);
}

void InterAtributo::deletar (){
    delete this;
}
