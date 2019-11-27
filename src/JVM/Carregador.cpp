#include <iostream>
#include "../../lib/JVM/Carregador.hpp"

void Carregador::carregar (std::vector<std::string> const &nomes_arqs){
    for (auto &nome_arq : nomes_arqs){
        ArqClass arq_class(nome_arq);

        if (arq_class.decodificar()){
            set_pontoEntrada(arq_class);
        }

        this->arquivos.push_back(arq_class);
    }

    // LIMPA MEMÓRIA?
}

void Carregador::exibir (){
    for (auto &arq_class : this->arquivos){
        arq_class.exibir();
        std::cout << std::endl << "************************" << std::endl << std::endl;
    }
}

void Carregador::set_pontoEntrada (ArqClass const &arq){
    if (!arq.e_valido || this->pontoEntrada.e_valido) return;

    this->pontoEntrada = arq;
}

ArqClass Carregador::get_pontoEntrada (){
    return this->pontoEntrada;
}

void Carregador::deletar (){
    for (auto &arq_class : this->arquivos)
        arq_class.deletar();

    std::vector<ArqClass>().swap(this->arquivos);
}
