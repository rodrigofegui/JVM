#include <iostream>
#include <math.h>
#include <inttypes.h>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void InfoPadding::exibir (const u1 qnt_tabs){
    std::cout << get() << std::endl;
}

std::string InfoPadding::get(){
    return "Extensão de número largo";
}



void InfoClasse::decodificar (FILE *const arq){
    ler_u2(arq, &this->ind_nome);
}

void InfoClasse::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Class" << std::endl;

    std::cout << tabs + "Índice para o nome: ";
    std::cout << this->ind_nome;
    std::cout << " -> " << get_nome() << std::endl;
}

std::string InfoClasse::get_nome() {
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome);
}

std::string InfoClasse::get(){
    return get_nome();
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

std::string InfoRefCampo::get(){
    return get_nome_classe() + "." + get_str_nome_tipo();
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
    std::cout << this->ind_nome << " -> " << get_nome() << std::endl;
    std::cout << tabs + "Índice para o descritor: ";
    std::cout << this->ind_descritor << " -> " << get_descritor() << std::endl;
}

std::string InfoNomeTipo::get_nome(){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_nome);
}

std::string InfoNomeTipo::get_descritor(){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_descritor);
}

std::string InfoNomeTipo::get (){
    return get_nome() + " : " + get_descritor();
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
    std::cout << tabs + "String: "<< get() << std::endl;
}

std::string InfoUTF8::get (){
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

std::string InfoRefMetodo::get(){
    return get_nome_classe() + "." + get_str_nome_tipo();
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

std::string InfoRefMetInterface::get(){
    return get_nome_classe() + "." + get_str_nome_tipo();
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

std::string InfoString::get (){
    return (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(this->ind_string);
}

void InfoString::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_String" << std::endl;

    std::cout << tabs + "Índice para a string: ";
    std::cout << this->ind_string;
    std::cout << " -> " << get() << std::endl;
}



void InfoInteiro::decodificar (FILE *const arq){
    ler_u4(arq, &this->bytes);
}

std::string InfoInteiro::get (){
    return std::to_string((int) this->bytes);
}

void InfoInteiro::exibir (u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    std::cout << "CONSTANT_Integer" << std::endl;

    std::cout << tabs + "Bytes: " << get_hex_4(this->bytes) << std::endl;
    std::cout << tabs + "Valor correspondente: " << get() << std::endl;
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
        
    float valor;
    std::memcpy(&valor, &this->bytes, sizeof(float));
    

    return std::to_string(valor);
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
	uint64_t bytes = ((uint64_t)(this->bytes_mais) << 32 )+ this->bytes_menos;
	long valor;
	std::memcpy(&valor, &bytes, sizeof(long));
	
    return std::to_string(valor);
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
    uint64_t bytes = ((uint64_t)(this->bytes_mais) << 32 )+ this->bytes_menos;
    double valor;
    std::memcpy(&valor, &bytes, sizeof(double));

    if (bytes == 0x7FF0000000000000L)
        return "Infinity";

    if (bytes == 0xFFF0000000000000L)
        return "-Infinity";

    if (((bytes >= 0x7FF0000000000001L) && (bytes <= 0x7FFFFFFFFFFFFFFFL))
            || ((bytes >= 0xFFF0000000000001L) && (bytes <= 0xFFFFFFFFFFFFFFFFL)))
        return "NaN";
    
    return std::to_string(valor);
}
