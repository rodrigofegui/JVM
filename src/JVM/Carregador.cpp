#include <iostream>
#include "../../lib/JVM/Carregador.hpp"

void Carregador::decodificar (std::vector<std::string> const &nomes_arqs){
    for (auto &nome_arq : nomes_arqs){
        ArqClass arq_class(nome_arq);

        arq_class.decodificar();

        this->arquivos.push_back(arq_class);
    }
}

void Carregador::exibir (){
    for (auto &arq_class : this->arquivos){
        arq_class.exibir();
        std::cout << std::endl;
    }
}

void Carregador::deletar (){
    for (auto &arq_class : this->arquivos)
        arq_class.deletar();

    std::vector<ArqClass>().swap(this->arquivos);
}
