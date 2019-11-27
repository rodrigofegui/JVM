#include <iostream>
#include "../../lib/JVM/Interpretador.hpp"


void Interpretador::executar (){
    if (!this->pontoEntrada.e_valido) return erro();

    this->pontoEntrada.exibir();

    std::cout << "Tem main!!" << std::endl;

    // c_campo->exibir(0);
    // empilhar(new Frame(c_campo));

    // c_campo = this->pontoEntrada->get_metodo("<init>");
    // empilhar(new Frame(c_campo));

    // do{
    //     Frame *c_frame = this->pilha_frames.back();

    //     c_frame->executar();

    //     if (c_frame.a_empilhar)
    //         empilhar(c_frame.a_empilhar);

    //     if (c_frame.a_desempilhar)
    //         desempilhar();
    // }while (this->pilha_frames.size());
}

void Interpretador::erro(){
    std::cout << "Não tem main!" << std::endl;
}

void Interpretador::deletar(){
    std::vector<Frame *>().swap(this->pilha_frames);

    delete this;
}
