#include <iostream>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/Excessao.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void Excessao::decodificar (FILE *const arq){
    ler_u2(arq, &this->lin_comeco);
    ler_u2(arq, &this->lin_final);
    ler_u2(arq, &this->lin_tratamento);
    ler_u2(arq, &this->ind_tipo_catch);
}

void Excessao::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << tabs << this->lin_comeco << '\t';
    std::cout << this->lin_final << '\t';
    std::cout << this->lin_tratamento << '\t';
    std::cout << this->ind_tipo_catch;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string (this->ind_tipo_catch) << std::endl;
}
