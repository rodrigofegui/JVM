#include "../../lib/Tipos/Frame.hpp"

Frame::Frame(InterTabela *simbolos, Campo * metodo) {
    this->pc = 0;
    this->tab_simbolos = simbolos;
    this->referencia_metodo = metodo;
    this->attr_codigo = dynamic_cast<AttrCodigo*>(dynamic_cast<TabAtributos*>(metodo->tab_atributos)->registros[0]);
    this->var_locais.resize(this->attr_codigo->max_locais);
    Operando* op = new Operando();
    std::fill(this->var_locais.begin(), this->var_locais.end(), op);
}

void Frame::executar(){ 
    u1 opcode = this->attr_codigo->codigo[pc];
    bytecodes[opcode].manipulador(this);
}