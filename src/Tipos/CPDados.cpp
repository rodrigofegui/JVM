#include <iostream>
#include <math.h>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InfoPadding::exibir (const u1 qnt_tabs){
    std::cout << "Extensão de número largo" << std::endl;
}



void InfoClasse::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_nome);
}

void InfoClasse::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Class" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;
}



void InfoRefCampo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

std::string InfoRefCampo::get_nome_classe (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe);
}

std::string InfoRefCampo::get_str_nome_tipo (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo);
}

std::string InfoRefCampo::get_nome_campo (){
    std::string campo = get_str_nome_tipo();

    return campo.substr(0, campo.find(" "));
}

void InfoRefCampo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Fieldref" << std::endl;

    std::cout << tabs + "Índice para a classe: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << get_nome_classe() << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << get_str_nome_tipo() << std::endl;
}



void InfoNomeTipo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_nome);
    ler_u2(arq, &this->ind_descritor);
}

void InfoNomeTipo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_NameAndType" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome) << std::endl;
    std::cout << tabs + "Índice para o descritor: ";
    std::cout << this->ind_descritor;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_descritor) << std::endl;
}



void InfoUTF8::decodificar (FILE *const arq){
    u1 temp;

    ler_u2(arq, &this->tam);

    for (int cnt = 0; cnt < this->tam; cnt++){
        ler_u1(arq, &temp);
        this->bytes.push_back(temp);
    }
}

void InfoUTF8::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Utf8" << std::endl;

    std::cout << tabs + "Tamanho da string: " << this->tam << std::endl;
    std::cout << tabs + "String: "<< get_string() << std::endl;
}

std::string InfoUTF8::get_string (){
    std::string str(this->bytes.begin(), this->bytes.end());

    return str;
}

void InfoUTF8::deletar (){
    std::vector<u1>().swap(this->bytes);

    InterCPDado::deletar();
}



void InfoRefMetodo::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

std::string InfoRefMetodo::get_nome_classe (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe);
}

std::string InfoRefMetodo::get_str_nome_tipo (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo);
}

std::string InfoRefMetodo::get_nome_metodo (){
    std::string metodo = get_str_nome_tipo();

    return metodo.substr(0, metodo.find(" "));
}


void InfoRefMetodo::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Methodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << get_nome_classe() << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << get_str_nome_tipo() << std::endl;
}



void InfoRefMetInterface::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_classe);
    ler_u2(arq, &this->ind_nome_tipo);
}

std::string InfoRefMetInterface::get_nome_classe (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_classe);
}

std::string InfoRefMetInterface::get_str_nome_tipo (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome_tipo);
}

std::string InfoRefMetInterface::get_nome_metodo (){
    std::string metodo = get_str_nome_tipo();

    return metodo.substr(0, metodo.find(" "));
}

void InfoRefMetInterface::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_InterfaceMethodref" << std::endl;

    std::cout << tabs + "Índice para a clase: ";
    std::cout << this->ind_classe;
    std::cout << " -> " << get_nome_classe() << std::endl;
    std::cout << tabs + "Índice para o nome e tipo: ";
    std::cout << this->ind_nome_tipo;
    std::cout << " -> " << get_str_nome_tipo() << std::endl;
}



void InfoString::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_string);
}

void InfoString::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_String" << std::endl;

    std::cout << tabs + "Índice para a string: ";
    std::cout << this->ind_string;
    std::cout << " -> " << (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_string) << std::endl;
}

void InfoInteiro::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes);
}

void InfoInteiro::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Integer" << std::endl;

    std::cout << tabs + "Bytes: " << get_hex_4(this->bytes) << std::endl;
    std::cout << tabs + "Valor correspondente: " << this->bytes << std::endl;
}



void InfoFloat::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes);
}

void InfoFloat::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Float" << std::endl;

    std::cout << tabs + "Bytes: " << get_hex_4(this->bytes) << std::endl;
    std::cout << tabs + "Valor correspondente: " << get() << std::endl;
}

std::string InfoFloat::get (){
    if (this->bytes == 0x7f800000)
        return "Infinity";

    if (this->bytes == 0xff800000)
        return "-Infinity";

    if (((this->bytes >= 0x7f800001) && (this->bytes <= 0x7fffffff))
            || ((this->bytes >= 0xff800001) && (this->bytes <= 0xffffffff)))
        return "NaN";

    int sinal = ((this->bytes >> 31) == 0) ? 1 : -1,
        expoente = ((this->bytes >> 23) & 0xff),
        mantissa = (expoente == 0) ? (this->bytes & 0x7fffff) << 1 : (this->bytes & 0x7fffff) | 0x800000;

    return std::to_string(sinal * mantissa * pow(2, expoente - 150));
}



void InfoLong::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes_mais);
    ler_u4(arq, &this->bytes_menos);
}

void InfoLong::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Long" << std::endl;

    std::cout << tabs + "Bytes mais significativos: " << get_hex_4(this->bytes_mais) << std::endl;
    std::cout << tabs + "Bytes menos significativos: " << get_hex_4(this->bytes_menos) << std::endl;
    std::cout << tabs + "Valor correspondente: " << get() << std::endl;
}

std::string InfoLong::get (){
    return std::to_string(((long) this->bytes_mais << 32) + this->bytes_menos);
}



void InfoDouble::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes_mais);
    ler_u4(arq, &this->bytes_menos);
}

void InfoDouble::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Double" << std::endl;

    std::cout << tabs + "Bytes mais significativos: " << get_hex_4(this->bytes_mais) << std::endl;
    std::cout << tabs + "Bytes menos significativos: " << get_hex_4(this->bytes_menos) << std::endl;
    std::cout << tabs + "Valor correspondente: " << get() << std::endl;
}

std::string InfoDouble::get (){
    unsigned long int bytes = ((long) this->bytes_mais << 32) + this->bytes_menos;

    if (bytes == 0x7FF0000000000000L)
        return "Infinity";

    if (bytes == 0xFFF0000000000000L)
        return "-Infinity";

    if (((bytes >= 0x7FF0000000000001L) && (bytes <= 0x7FFFFFFFFFFFFFFFL))
            || ((bytes >= 0xFFF0000000000001L) && (bytes <= 0xFFFFFFFFFFFFFFFFL)))
        return "NaN";

    int sinal = ((bytes >> 63) == 0) ? 1 : -1,
        expoente = ((bytes >> 52) & 0x7FFL);
    long mantissa = (expoente == 0) ? (bytes & 0xfffffffffffffL) << 1 : (bytes & 0xfffffffffffffL) | 0x10000000000000L;

    return std::to_string(sinal * mantissa * pow(2, expoente - 1075));
}
