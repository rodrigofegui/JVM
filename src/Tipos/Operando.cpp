#include <string>
#include "../../lib/Tipos/Operando.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


std::string Operando::get (){
    std::string op;
    switch (this->tag){
        case TAG_INT: op = std::to_string((int) this->tipo_int); break;
        case TAG_FLT: op = std::to_string(this->tipo_float); break;
        case TAG_CHR: op = std::to_string((char)this->tipo_char); break;
        case TAG_SHT: op = std::to_string((short)this->tipo_short); break;
        case TAG_DBL: op = std::to_string(this->tipo_double); break;
        case TAG_LNG: op = std::to_string((long) this->tipo_long); break;
        case TAG_STR: op = this->tipo_string; break;
        case TAG_BYTE: op = std::to_string((int) this->tipo_byte); break;
        case TAG_ARR:
            op += "[";
            for (u2 cnt = 0; cnt < this->lista_operandos->size(); cnt++){
                op += "'" + this->lista_operandos->at(cnt)->get() + "'";
                op += cnt + 1 < this->lista_operandos->size()? ", " : "";
            }
            op += "]";
            break;
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

void Operando::atualizar_tipo (u1 tag){
    if (this->tag != TAG_BYTE)
        return;

    this->tag = tag;

    switch (tag){
        case TAG_CHR:
            this->tipo_char = (char) this->tipo_byte; break;
        case TAG_SHT:
            this->tipo_short = (short) this->tipo_byte; break;
        case TAG_INT:
            this->tipo_int = (int) this->tipo_byte; break;
        case TAG_LNG:
            this->tipo_long = (long) this->tipo_byte; break;
        case TAG_FLT:
            this->tipo_float = (float) this->tipo_byte; break;
    }
}

void Operando::deletar (){
    // if (this->obj)
    //     this->obj->deletar();
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
