#include "../lib/Principal.hpp"


int main(int argc, char *argv[]){
    MaquinaVirtual maqVirtual;

    maqVirtual.iniciar(argc, argv);

    maqVirtual.executar();

    maqVirtual.deletar();

    return 0;
}
