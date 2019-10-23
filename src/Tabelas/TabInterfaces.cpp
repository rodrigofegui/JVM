#include <iomanip>
#include <iostream>
#include "../../lib/Tabelas/TabInterfaces.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Tipos/CPDados.hpp"


u1 TabInterfaces::decodificar (FILE *const arq){
    for (int cnt = 0; cnt < this->tam; cnt++){
        u2 ind_class;
        ler_u2(arq, &ind_class);
        this->registros.push_back(ind_class);
    }

    return 0;
}

void TabInterfaces::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    if (!this->tam){
        std::cout << tabs + "Não há itens na tabela de interfaces" << std::endl;
        return;
    }

    u1 padding = get_padding(this->tam);

    for (int cnt = 0; cnt < this->tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt;
        std::cout << "] ";
        std::cout << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->registros[cnt]) << std::endl;
        std::cout << tabs + tabs + "Índice para a classe: " << this->registros[cnt] << std::endl;

    }
}

void TabInterfaces::deletar (){
    std::vector<u2>().swap(this->registros);

    delete this;
}
