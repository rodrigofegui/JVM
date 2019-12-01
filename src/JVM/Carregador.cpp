#include <iostream>
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/JVM/Carregador.hpp"


void Carregador::analise_semantica (std::vector<std::string> const &nomes_arqs){
    exibir_se_verboso("++++++++++++++++++++++++");

    for (auto &nome_arq : nomes_arqs){
        ArqClass arq_class(nome_arq);

        u1 status = arq_class.decodificar();

        if (status == ARQ_MAIN) {
            set_nome_arq_main(nome_arq);
            exibir_se_verboso("O arquivo '" + nome_arq + "' é válido");

        } else if (status != SUCESSO) {
            exibir_se_verboso("O arquivo '" + nome_arq + "' não é válido");
        }

        arq_class.deletar();
    }

    exibir_se_verboso("++++++++++++++++++++++++");
}

u1 Carregador::carregar (const std::string &nome_arq){
    for (auto &arq : this->arquivos){
        if (!arq->nome_arq.compare(nome_arq))
            return JA_EXISTIA;
    }

    ArqClass *arq_class = new ArqClass(nome_arq);

    u1 status = arq_class->decodificar();

    if ((status != ARQ_MAIN) && ((status != SUCESSO)))
        return ERRO;

    this->arquivos.push_back(arq_class);

    return SUCESSO;
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

ArqClass* Carregador::topo(){
    return this->arquivos.back();
}

ArqClass* Carregador::localizar(std::string const &nome_arq){
    for (auto &arq : this->arquivos)
        if (!arq->nome_arq.compare(nome_arq))
            return arq;
}

void Carregador::deletar (){
    for (auto &arq_class : this->arquivos){
        arq_class->deletar();
        delete arq_class;
    }

    std::vector<ArqClass*>().swap(this->arquivos);
}
