#include <iostream>
#include <vector>
#include "../lib/JVM/Maquina_Virtual.hpp"


int main(int argc, char *argv[]){
    MaquinaVirtual maqVirtual;

    maqVirtual.iniciar(argc, argv);

    maqVirtual.executar();

    maqVirtual.deletar();

    return 0;
}
