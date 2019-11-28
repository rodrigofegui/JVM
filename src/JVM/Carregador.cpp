#include <iostream>
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/JVM/Carregador.hpp"


void Carregador::analise_semantica (std::vector<std::string> const &nomes_arqs){
    std::cout << std::endl << "++++++++++++++++++++++++" << std::endl;

    for (auto &nome_arq : nomes_arqs){
        ArqClass arq_class(nome_arq);

        u1 status = arq_class.decodificar();

        std::cout << "O arquivo '" << nome_arq << "'";

        if (status == ARQ_MAIN) {
            set_nome_arq_main(nome_arq);

        } else if (status != SUCESSO) {
            std::cout << " não";

        }

        std::cout << " é válido" << std::endl;

        arq_class.deletar();
    }

    std::cout << "++++++++++++++++++++++++" << std::endl;
}

void Carregador::carregar (const std::string &nome_arq){
    ArqClass *arq_class = new ArqClass(nome_arq);

    arq_class->decodificar();

    this->arquivos.push_back(arq_class);
}

void Carregador::exibir (){
    for (auto &arq_class : this->arquivos){
        std::cout << std::endl << "************************" << std::endl;
        arq_class->exibir();
        std::cout << "************************" << std::endl << std::endl;
    }
}

void Carregador::set_nome_arq_main (std::string const &nome_arq){
    if (nome_arq.empty() || !this->nome_arq_main.empty()) return;

    this->nome_arq_main = nome_arq;
}

std::string Carregador::get_nome_arq_main (){
    return this->nome_arq_main;
}

ArqClass* Carregador::get_pontoEntrada(){
    return this->arquivos.front();
}

void Carregador::deletar (){
    for (auto &arq_class : this->arquivos){
        arq_class->deletar();
        delete arq_class;
    }

    std::vector<ArqClass *>().swap(this->arquivos);

}
