#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabCampos.hpp"
#include "../../lib/Tabelas/TabMetodos.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tabelas/TabInterfaces.hpp"
#include "../../lib/Tipos/ArqClass.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/Uteis/Status.hpp"


ArqClass::ArqClass (const std::string &nome_arq) : ArqClass() {
    this->nome_arq = nome_arq;
}

void ArqClass::check_validade (){
    ler_u4(this->arq, &this->codigo);

    if (this->codigo == COD_ARQ_CLASS) this->e_valido = 1;
}

std::string ArqClass::get_versao_java (const u2 versao){
    switch (versao){
        case V1_1:  return "JDK 1.1";
        case V1_2:  return "JDK 1.2";
        case V1_3:  return "JDK 1.3";
        case V1_4:  return "JDK 1.4";
        case V5:    return "Java SE 5.0";
        case V6:    return "Java SE 6.0";
        case V7:    return "Java SE 7";
        case V8:    return "Java SE 8";
        case V9:    return "Java SE 9";
        case V10:   return "Java SE 10";
        case V11:   return "Java SE 11";
        case V12:   return "Java SE 12";
        case V13:   return "Java SE 13";
        case V14:   return "Java SE 14";
        default:    return "Sem expecificação";
    }
}

u1 ArqClass::decodificar (){
    u1 tem_main = 0;

    this->arq = abrir(nome_arq.c_str());

    if (!this->arq) return 0;

    check_validade();

    if (!this->e_valido) return 0;

    ler_u2(this->arq, &this->versao_min);
    ler_u2(this->arq, &this->versao_max);
    ler_u2(this->arq, &this->tam_tab_simbolo);

    if (this->tam_tab_simbolo){
        this->tab_simbolo = new TabSimbolos(this->tam_tab_simbolo);

        tem_main = this->tab_simbolo->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->flag_acesso);
    ler_u2(this->arq, &this->class_atual);
    ler_u2(this->arq, &this->class_super);
    ler_u2(this->arq, &this->tam_tab_interfaces);

    if (this->tam_tab_interfaces){
        this->tab_interfaces = new TabInterfaces(this->tam_tab_interfaces, this-> tab_simbolo);
        this->tab_interfaces->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->tam_tab_campos);

    if (this->tam_tab_campos){
        this->tab_campos = new TabCampos(this->tam_tab_campos, this->tab_simbolo);
        this->tab_campos->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->tam_tab_metodos);

    if (this->tam_tab_metodos){
        this->tab_metodos = new TabMetodos(this->tam_tab_metodos, this->tab_simbolo);
        this->tab_metodos->decodificar(this->arq);
    }

    ler_u2(this->arq, &this->tam_tab_atributos);

    if (this->tam_tab_atributos){
        this->tab_atributos = new TabAtributos(this->tam_tab_atributos, this->tab_simbolo);
        this->tab_atributos->decodificar(this->arq);
    }

    fclose(this->arq);
    this->arq = nullptr;

    if (!tem_main) return 0;

    return 1;
}

Campo* ArqClass::get_metodo (const std::string &nome){
    std::cout << (dynamic_cast<TabMetodos*>(this->tab_metodos))->buscar(nome) << std::endl;

    return nullptr;
}

void ArqClass::exibir (){
    std::cout << "Nome do arquivo .class: " << this->nome_arq << std::endl;
    std::cout << "Código indentificador: " << get_hex_4(this->codigo) << std::endl;

    if (!this->e_valido){
        std::cout << "Não é um arquivo válido!" << std::endl;
        return;
    }

    std::cout << "Versão mínima compilador: ";
    std::cout << get_versao_java(this->versao_min) << std::endl;
    std::cout << "Versão máxima compilador: ";
    std::cout << get_versao_java(this->versao_max) << std::endl;

    std::cout << "Qnt. de entradas na tabela de símbolos: ";
    std::cout << this->tam_tab_simbolo << std::endl;

    if (this->tab_simbolo) this->tab_simbolo->exibir(1);

    std::cout << "Flag de acesso: " << get_flag(this->flag_acesso) << std::endl;

    std::cout << "Classe corrente: " << this->class_atual << std::endl;

    std::cout << "Classe super: " << this->class_super << std::endl;

    std::cout << "Qnt. de entradas na tabela de interfaces: ";
    std::cout << this->tam_tab_interfaces << std::endl;

    if (this->tab_interfaces) this->tab_interfaces->exibir(1);

    std::cout << "Qnt. de entradas na tabela de campos: ";
    std::cout << this->tam_tab_campos << std::endl;

    if (this->tab_campos) this->tab_campos->exibir(1);

    std::cout << "Qnt. de entradas na tabela de métodos: ";
    std::cout << this->tam_tab_metodos << std::endl;

    if (this->tab_metodos) this->tab_metodos->exibir(1);

    std::cout << "Qnt. de entradas na tabela de atributos: ";
    std::cout << this->tam_tab_atributos << std::endl;

    if (this->tab_atributos) this->tab_atributos->exibir(1);

    std::cout << "Fim dos dados sobre: " << this->nome_arq << std::endl;
}

void ArqClass::deletar (){
    if (this->tab_simbolo)
        this->tab_simbolo->deletar();

    if (this->tab_interfaces)
        this->tab_interfaces->deletar();

    if (this->tab_campos)
        this->tab_campos->deletar();

    if (this->tab_metodos)
        this->tab_metodos->deletar();

    if (this->tab_atributos)
        this->tab_atributos->deletar();

    if (this->arq) fclose(this->arq);
}

