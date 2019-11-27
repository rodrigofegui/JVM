#include "../../lib/JVM/Maquina_Virtual.hpp"
#include "../../lib/Tipos/ByteCode.hpp"


void MaquinaVirtual::iniciar (int argc, char *argv[]){
    iniciar_bytecodes();

    this->parametros.get_entradas(argc, argv);

    this->carregador.analise_semantica(this->parametros.nome_arqs);
}

void MaquinaVirtual::executar (){
    if (this->parametros.e_leitura()){
        for (auto &nome_arq : this->parametros.nome_arqs){
            this->carregador.carregar(nome_arq);
        }

        this->carregador.exibir();

    } else {
        this->carregador.carregar(this->carregador.get_pontoEntrada());

        // this->interpretador = new Interpretador(this->carregador.get_pontoEntrada());

        // this->interpretador->executar();
    }
}

void MaquinaVirtual::deletar(){
    if (this->interpretador)
        this->interpretador->deletar();

    this->carregador.deletar();

    this->parametros.deletar();
}
