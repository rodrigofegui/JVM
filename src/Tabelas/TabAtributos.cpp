#include <iomanip>
#include <iostream>
#include "../../lib/Tabelas/TabAtributos.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/Atributos.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


u1 TabAtributos::decodificar (FILE *const arq){
    for (int cnt = 0; cnt < this->tam; cnt++){
        std::string nome("");
        InterAtributo *attr = nullptr;
        u2 temp = 0xFFFF;

        ler_u2(arq, &temp);

        if ((dynamic_cast<TabSimbolos*>(this->tab_simbolos)))
            nome = (dynamic_cast<TabSimbolos*>(this->tab_simbolos))->get_string(temp);

        if (nome.empty()) continue;

        if (!nome.compare("Code"))
            attr = new AttrCodigo(temp, this->tab_simbolos);

        else if (!nome.compare("LineNumberTable"))
            attr = new AttrLinhaNum(temp);

        else if (!nome.compare("SourceFile"))
            attr = new AttrArqFonte(temp, this->tab_simbolos);

        else if (!nome.compare("ConstantValue"))
            attr = new AttrVlrConst(temp, this->tab_simbolos);

        else if (!nome.compare("Exceptions"))
            attr = new AttrExcp(temp, this->tab_simbolos);

        else if (!nome.compare("InnerClasses"))
            attr = new AttrClass(temp, this->tab_simbolos);

        else if (!nome.compare("Synthetic"))
            attr = new AttrSintetico(temp, this->tab_simbolos);

        else
            attr = new AttrSilenciado(temp, this->tab_simbolos);

        attr->decodificar(arq);

        this->registros.push_back(attr);
    }

    return 0;
}

void TabAtributos::exibir (const u1 qnt_tabs){
    std::string tabs(qnt_tabs, '\t');

    if (!this->tam){
        std::cout << tabs + "Não há itens na tabela de atributos" << std::endl;
        return;
    }

    u1 padding = get_padding(this->tam);

    for (int cnt = 0; cnt < this->tam; cnt++){
        std::cout << tabs + "[";
        std::cout << std::setfill('0') << std::setw(padding) << cnt;
        std::cout << "] ";

        this->registros[cnt]->exibir(qnt_tabs + 1);
    }
}

void TabAtributos::deletar (){
    for (auto &registro : registros)
        registro->deletar();

    std::vector<InterAtributo*>().swap(this->registros);

    delete this;
}
