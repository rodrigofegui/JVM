#include "../../lib/JVM/Maquina_Virtual.hpp"
#include "../../lib/Tipos/ByteCode.hpp"


void MaquinaVirtual::iniciar (int argc, char *argv[]){
    iniciar_bytecodes();

    this->parametros.get_entradas(argc, argv);

    this->carregador.carregar(this->parametros.nome_arqs);
}

void MaquinaVirtual::executar (){
    if (this->parametros.e_leitura()){
        this->carregador.exibir();
    } else{
        // std::cout << "operando como interpretador" << std::endl;

        // for (auto &arq_class : arqs_class){
        //     arq_class.deletar();
        // }
    }
}

void MaquinaVirtual::deletar(){
    this->carregador.deletar();

    this->parametros.deletar();
}
