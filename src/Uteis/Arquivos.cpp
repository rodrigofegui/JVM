#include <iomanip>
#include <iostream>
#include <sstream>
#include <math.h>
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Status.hpp"


FILE * abrir(const char *nome_arq){
    FILE *arq = fopen(nome_arq, "rb");

    if (arq == NULL){
        std::cout << "\n[ERROR] Falha ao abrir o arquivo: " << nome_arq << std::endl;

        exit(E_ABRIR_ARQUIVO);
    }

    return arq;
}

void ler_u1(FILE *const arq, u1 *dst){
    fread(dst, sizeof(u1), 1, arq);
}

void ler_u2(FILE *const arq, u2 *dst){
   u1 temp = 0;

    for (int ind = 1; ind <= sizeof(u2); ind++){
        fread(&temp, sizeof(u1), 1, arq);
        *dst <<= 8;
        *dst |= temp;
    }
}

void ler_u4(FILE *const arq, u4 *dst){
    u1 temp = 0;

    for (int ind = 0; ind < sizeof(u4); ind++){
        fread(&temp, sizeof(u1), 1, arq);
        *dst <<= 8;
        *dst |= temp;
    }
}

int get_padding(const int num_max){
    int padding = 1;

    do{
       if ((num_max >= pow10(padding - 1)) && (num_max < pow10(padding)))
            break;

        padding++;
    }while(true);

    return padding;
}

std::string get_hex (const u1 fonte){
    std::stringstream hex_str;

    hex_str << "0x" << std::setfill('0') << std::setw(2)
            << std::hex << std::uppercase << fonte;

    return hex_str.str();
}

std::string get_hex_2(const u2 fonte){
    std::stringstream hex_str;

    hex_str << "0x" << std::setfill('0') << std::setw(4)
            << std::hex << std::uppercase << fonte;

    return hex_str.str();
}

std::string get_hex_4(const u4 fonte){
    std::stringstream hex_str;

    hex_str << "0x" << std::setfill('0') << std::setw(8)
            << std::hex << std::uppercase  << fonte;

    return hex_str.str();
}

void exibir_se_verboso (std::string const &mensagem){
    #ifdef E_VERBOSO
        std::cout << mensagem << std::endl;
    #endif
}
