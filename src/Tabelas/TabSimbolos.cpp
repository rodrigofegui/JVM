#include <iomanip>
#include <iostream>
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


u1 TabSimbolos::decodificar (FILE *const arq){
    int tam = this->tam;
    if (!tam) return 2;

    u1 temp = 0, ignora = 0, tem_main = 0;

    for (int cnt = 0; cnt < tam - 1; cnt++){
        if (ignora){
            this->registros.push_back(new InfoPadding());
            ignora = 0;
            continue;
        }

        ler_u1(arq, &temp);

        InterCPDado *c_dados = nullptr;

        switch (temp){
            case TAG_UTF:           c_dados = new InfoUTF8(this, temp); break;
            case TAG_INT:           c_dados = new InfoInteiro(this, temp); break;
            case TAG_FLT:           c_dados = new InfoFloat(this, temp); break;
            case TAG_LNG:           c_dados = new InfoLong(this, temp); ignora = 1; break;
            case TAG_DBL:           c_dados = new InfoDouble(this, temp); ignora = 1; break;
            case TAG_CLAS:          c_dados = new InfoClasse(this, temp); break;
            case TAG_STR:           c_dados = new InfoString(this, temp); break;
            case TAG_REF_CMP:       c_dados = new InfoRefCampo(this, temp); break;
            case TAG_REF_MTD:       c_dados = new InfoRefMetodo(this, temp); break;
            case TAG_REF_MTD_ITF:   c_dados = new InfoRefMetInterface(this, temp); break;
            case TAG_NOM_TIP:       c_dados = new InfoNomeTipo(this, temp); break;
        }

        if (c_dados){
            c_dados->decodificar(arq);

            if (dynamic_cast<InfoUTF8*>(c_dados)
                    && !(dynamic_cast<InfoUTF8*>(c_dados))->get().compare("main"))
                tem_main = 1;

            this->registros.push_back(c_dados);
        }
    }

    return tem_main;
}

void TabSimbolos::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    if (!this->tam){
        std::cout << tabs + "Não há itens na tabela de símbolos" << std::endl;
        return;
    }

    int padding = get_padding(this->tam);
    int cnt = 0;

    for (auto &registro : this->registros){
        std::cout << tabs + "["
                  << std::setfill('0') << std::setw(padding)
                  << ++cnt << "] ";

        registro->exibir(qnt_tabs + 1);
    }
}

InterCPDado* TabSimbolos::buscar (u2 ind){
    u2 tam = this->tam ? this->tam : 0;

    if (!tam) return nullptr;

    if (ind == 0 || (ind > tam)) return nullptr;

    return this->registros[--ind];
}

std::string TabSimbolos::get_string (u2 ind_nome){
    InterCPDado *c_dados = buscar(ind_nome);

    if (!c_dados)
        return "";

    return c_dados->get();
}

void TabSimbolos::deletar (){
    for (auto &registro: this->registros)
        registro->deletar();

    std::vector<InterCPDado*>().swap(this->registros);

    delete this;
}
