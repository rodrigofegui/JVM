#include <string>
#include "../../lib/Tipos/Operando.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


std::string Operando::get (){
    std::string op;
    switch (this->tag){
        case TAG_INT: op = std::to_string((int) this->tipo_int); break;
        case TAG_FLT: op = std::to_string(this->tipo_float); break;
        case TAG_DBL: op = std::to_string(this->tipo_double); break;
        case TAG_LNG: op = std::to_string((long) this->tipo_long); break;
        case TAG_STR: op = this->tipo_string; break;
        default: op = "Indefinido";
    }

    #ifdef E_VERBOSO
        return op + " ~> " + get_tag(this->tag);
    #else
        return op;
    #endif
}

Operando* Operando::duplicar(){
    Operando *novo = new Operando();

    novo->tag = this->tag;

    novo->tipo_bool = this->tipo_bool;
    novo->tipo_byte = this->tipo_byte;
    novo->tipo_char = this->tipo_char;
    novo->tipo_short = this->tipo_short;
    novo->tipo_int = this->tipo_int;
    novo->tipo_float = this->tipo_float;
    novo->tipo_long = this->tipo_long;
    novo->tipo_double = this->tipo_double;

    novo->tipo_string = this->tipo_string;
    novo->lista_operandos = this->lista_operandos;

    if (this->obj)
        novo->obj = this->obj->duplicar();

    return novo;
}

void Operando::deletar (){
    if(this->lista_operandos)
        delete this->lista_operandos;

    if (this->obj)
        this->obj->deletar();
}

Objeto* Objeto::duplicar(){
    Objeto *novo = new Objeto(this->nome, this->classe);

    novo->referencias = this->referencias;

    return novo;
}

void Objeto::deletar (){
    std::map< std::string, Operando* >().swap(this->referencias);

    delete this;
}