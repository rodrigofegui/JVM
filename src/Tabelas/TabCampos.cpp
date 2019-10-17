#include <iomanip>
#include <iostream>
#include "../../lib/Tabelas/TabCampos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


u1 TabCampos::decodificar (FILE *const arq){
    for (int cnt = 0; cnt < *this->tam; cnt++){
        Campo c_campo(this->tab_simbolos);

        c_campo.decodificar(arq);

        this->registros.push_back(c_campo);
    }

    return 0;
}

void TabCampos::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');
    int tam = *this->tam;

    if (!tam){
        std::cout << tabs + "Não há itens na tabela de campos" << std::endl;
        return;
    }

    u1 padding = get_padding(tam);

    for (int cnt = 0; cnt < tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt;
        std::cout << "] ";

        this->registros[cnt].exibir(qnt_tabs + 1);
    }
}

void TabCampos::deletar (){
    std::vector<Campo>().swap(this->registros);

    delete this;
}
