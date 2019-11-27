#include <iomanip>
#include <iostream>
#include "../../lib/Interfaces/InterAtributo.hpp"
#include "../../lib/Tabelas/TabMetodos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


u1 TabMetodos::decodificar (FILE *const arq){
    for (int cnt = 0; cnt < this->tam; cnt++){
        Campo c_campo(this->tab_simbolos);

        c_campo.decodificar(arq);

        this->registros.push_back(c_campo);
    }

    return 0;
}

Campo* TabMetodos::buscar (const std::string &nome){
    for (u1 cnt = 0; cnt < this->registros.size(); cnt++){
        if (!this->registros[cnt].get_nome().compare(nome))
            std::cout << "Encontrado o método" << std::endl;
    }

    return nullptr;
}

void TabMetodos::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    if (!this->tam){
        std::cout << tabs + "Não há itens na tabela de métodos" << std::endl;
        return;
    }

    std::cout << "Endereço: " << this << std::endl;

    int padding = get_padding(this->tam);
    int cnt = 0;

    for (auto &registro : this->registros){
        std::cout << tabs + "["
                  << std::setfill('0') << std::setw(padding)
                  << cnt++ << "] ";

        registro.exibir(qnt_tabs + 1);
    }
}

void TabMetodos::deletar (){
    for (auto &registro : registros)
        registro.deletar();

    delete this;
}
