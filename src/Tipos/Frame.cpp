#include <iostream>
#include "../../lib/Tipos/Frame.hpp"
#include "../../lib/Tipos/ByteCode.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

Frame::Frame (Campo *const metodo) : Frame() {
    this->pc = 0;

    this->tab_simbolos = metodo->tab_simbolos;
    this->referencia_metodo = metodo;

    this->attr_codigo = dynamic_cast<AttrCodigo*>(
        dynamic_cast<TabAtributos*>(metodo->tab_atributos)->registros[0]
    );

    this->var_locais.resize(this->attr_codigo->max_locais);

    std::fill(this->var_locais.begin(), this->var_locais.end(), new Operando());
}

void Frame::executar(){
    if (this->a_empilhar) this->a_empilhar = nullptr;

    u4 pc_anterior = pc;

    u1 opcode = this->attr_codigo->codigo[pc];

    exibir_se_verboso("A executar [" + std::to_string((int) pc) + "]: " + bytecodes[opcode].mnemonico);

    bytecodes[opcode].manipulador(this);

    if (pc == pc_anterior)
        this->pode_desempilhar = true;

    // getchar();
}

u1 Frame::get_prox_byte (){
    return this->attr_codigo->codigo[++this->pc];
}

InterCPDado* Frame::buscar_simbolo(u2 indice){
    return dynamic_cast<TabSimbolos*>(this->tab_simbolos)->buscar(indice);
}

Operando* Frame::desempilhar(){
    Operando *topo = this->pilha_operandos.top();

    this->pilha_operandos.pop();

    return topo;
}

void Frame::empilhar(Operando *op){
    this->pilha_operandos.push(op);

    exibir_se_verboso("\tEmpilhou: " + op->get());
}

std::string Frame::get_tipo_parametros(){
    std::string descritivo = this->referencia_metodo->get_descritor();

    return descritivo.substr(1, descritivo.rfind(")") - 1);
}

std::string Frame::get_tipo_retorno(){
    std::string descritivo = this->referencia_metodo->get_descritor();

    return descritivo.substr(descritivo.rfind(")") + 1);
}

void Frame::deletar (){
    // for (auto &var_local : this->var_locais) var_local->deletar();

    // std::vector<Operando *>().swap(this->var_locais);

    // std::stack<Operando *>().swap(this->pilha_operandos);

    this->tab_simbolos = nullptr;
    this->referencia_metodo = nullptr;
    this->attr_codigo = nullptr;

    delete this;
}
