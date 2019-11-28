#include <iostream>
#include "../../lib/JVM/Interpretador.hpp"


Interpretador::Interpretador (Carregador *const area_metodos) : Interpretador() {
    this->area_metodos = area_metodos;
}

void Interpretador::executar (){
    std::string metodos_basicos[] = {"main", "<init>"};

    for (auto &metodo : metodos_basicos){
        Campo *c_campo = this->area_metodos->get_pontoEntrada()->get_metodo(metodo);

        empilhar(new Frame(c_campo));
    }

    do {
        Frame *c_frame = topo();

        std::cout << "Topo: " << c_frame << std::endl;

        c_frame->executar();

        if (c_frame->a_empilhar)
            empilhar(c_frame->a_empilhar);

        else if (c_frame->pode_desempilhar){
            desempilhar();
            std::cout << std::endl << std::endl;
        }

    } while (!this->pilha_frames.empty());
}

void Interpretador::empilhar (Frame *const frame){
    this->pilha_frames.push_back(frame);
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
