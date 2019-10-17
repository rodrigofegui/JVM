#include <iostream>
#include <vector>
#include "../lib/Tipos/ArqClass.hpp"
#include "../lib/Tipos/ByteCode.hpp"
#include "../lib/Uteis/Arquivos.hpp"
#include "../lib/Uteis/Parametros.hpp"


int main(int argc, char *argv[]){
    iniciar_bytecodes();

    Parametros param;

    param.get_entradas(argc, argv);

    std::vector<ArqClass> arqs_class;

    for (auto &nome_arq : param.nome_arqs){
        ArqClass arq_class(nome_arq);

        arq_class.decodificar();

        arqs_class.push_back(arq_class);
    }

    if (param.e_leitura()){
        for (auto &arq_class : arqs_class){
            arq_class.exibir();
            std::cout << std::endl;
        }
    } else{
        // std::cout << "operando como interpretador" << std::endl;

        // for (auto &arq_class : arqs_class){
        //     arq_class.deletar();
        // }
    }

    ArqClass::executar();

    for (auto &arq_class : arqs_class)
        arq_class.deletar();
    std::vector<ArqClass>().swap(arqs_class);

    param.deletar();

    return 0;
}
