#include <iostream>
#include "../../lib/JVM/Interpretador.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/Tipos/CPDados.hpp"


Interpretador::Interpretador (Carregador *const area_metodos) : Interpretador() {
    this->area_metodos = area_metodos;
}

void Interpretador::executar (){
    if (!this->area_metodos->get_pontoEntrada()){
        std::cout << "Sem ponto de entrada válido!" << std::endl;
        return;
    }

    std::string nome_metodos_basicos[] = {"main", "<init>"};

    for (auto &nome_metodo : nome_metodos_basicos)
        empilhar(nome_metodo);

    do {
        Frame *c_frame = topo();

        std::cout << "Frame: " << c_frame << std::endl;

        c_frame->executar();

        if (c_frame->a_empilhar){
            empilhar(c_frame->a_empilhar);
            std::cout << std::endl << std::endl;
        }

        else if (c_frame->pode_desempilhar){
            desempilhar()->deletar();
            std::cout << std::endl << std::endl;
        }

    } while (!this->pilha_frames.empty());
}

void Interpretador::empilhar (Frame *const frame){
    this->pilha_frames.push_back(frame);
}

void Interpretador::empilhar (std::string const &nome_metodo){
    Campo *metodo = this->area_metodos->topo()->get_metodo(nome_metodo);

    if (metodo)
        empilhar(new Frame(metodo));
}

void Interpretador::empilhar (std::string const &nome_metodo, std::string const &nome_classe){
    Campo *metodo = this->area_metodos->localizar(nome_classe)->get_metodo(nome_metodo);

    if (metodo)
        empilhar(new Frame(metodo));
}

void Interpretador::empilhar (InterCPDado *const dados){
    if ((dados->tag == TAG_REF_MTD) || (dados->tag == TAG_REF_MTD_ITF))
        return empilhar_frame(dados);

    if (dados->tag == TAG_REF_CMP)
        return empilhar_operandos(dados);

}

void Interpretador::empilhar_frame (InterCPDado *const dados){
    std::string nome_classe = dados->tag == TAG_REF_MTD ? \
        (dynamic_cast<InfoRefMetodo*>(dados))->get_nome_classe() : \
        (dynamic_cast<InfoRefMetInterface*>(dados))->get_nome_classe();
    nome_classe += ".class";

    u1 status = this->area_metodos->carregar(nome_classe);

    if ((status != JA_EXISTIA) && (status != SUCESSO))
        return;

    std::string nome_metodo = dados->tag == TAG_REF_MTD ? \
        (dynamic_cast<InfoRefMetodo*>(dados))->get_nome_metodo() : \
        (dynamic_cast<InfoRefMetInterface*>(dados))->get_nome_metodo();

    empilhar(nome_metodo, nome_classe);
}

void Interpretador::empilhar_operandos (InterCPDado *const dados){
    std::string nome_classe = (dynamic_cast<InfoRefCampo*>(dados))->get_nome_classe();
    nome_classe += ".class";

    u1 status = this->area_metodos->carregar(nome_classe);

    if ((status != JA_EXISTIA) && (status != SUCESSO))
        return;

    std::string nome_campo = (dynamic_cast<InfoRefCampo*>(dados))->get_nome_campo();

    // A PENSAR
    // empilhar(nome_metodo, nome_classe);
}

Frame* Interpretador::topo (){
    return this->pilha_frames.back();
}

Frame* Interpretador::desempilhar (){
    Frame *topo_ = topo();

    this->pilha_frames.pop_back();

    return topo_;
}

void Interpretador::deletar(){
    for (auto &frame : this->pilha_frames)
        frame->deletar();

    std::vector<Frame *>().swap(this->pilha_frames);

    delete this;
}
