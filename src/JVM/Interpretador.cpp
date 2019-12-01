#include <iostream>
#include "../../lib/JVM/Interpretador.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Tipos/CPDados.hpp"


Interpretador::Interpretador (Carregador *const area_metodos) : Interpretador() {
    this->area_metodos = area_metodos;
}

void Interpretador::executar (){
    if (!this->area_metodos->get_pontoEntrada()){
        std::cout << "Sem ponto de entrada válido!" << std::endl;
        return;
    }

    std::string nome_metodos_basicos[] = {"main", "<init>"};

    for (auto &nome_metodo : nome_metodos_basicos)
        empilhar(nome_metodo);

    do {
        Frame *c_frame = topo();

        exibir_se_verboso("Frame: " + c_frame->referencia_metodo->get_nome());

        c_frame->executar();

        if (c_frame->a_empilhar){
            empilhar(c_frame->a_empilhar);
            exibir_se_verboso("\n");
        }

        else if (c_frame->pode_desempilhar){
            desempilhar()->deletar();
            exibir_se_verboso("\n");
        }

        // getchar();

    } while (!this->pilha_frames.empty());
}

void Interpretador::empilhar (Frame *const frame){
    this->pilha_frames.push_back(frame);
}

void Interpretador::empilhar (std::string const &nome_metodo){
    Campo *metodo = this->area_metodos->topo()->get_metodo(nome_metodo);

    if (metodo)
        empilhar(new Frame(metodo));
}

void Interpretador::empilhar (std::string const &nome_metodo, std::string const &nome_classe){
    exibir_se_verboso(
        "\tA empilhar o frame para o método: '" + nome_metodo
        + "' da classe: '" + nome_classe + "'");

    Campo *metodo = this->area_metodos->localizar(nome_classe)->get_metodo(nome_metodo);
    std::string descritor = metodo->get_descritor();
    int args = 0, cnt = 1;
    std::vector<Operando*> argumentos_instancia;
    while(descritor[cnt] != ')') {
        char tipo = descritor[cnt];
        if(tipo == 'L') {
            args++;
            while(descritor[++cnt] != ';');
        } else if(tipo == '[') {
            args++;
            while(descritor[++cnt] != '[');
            if(descritor[cnt] == 'L') while(descritor[++cnt] != ';');
        } else {
            args++;
        }
        cnt++;
    }

    for(int i=0; i<args; i++) {
        Operando* argumento = this->topo()->desempilhar();
        argumentos_instancia.insert(argumentos_instancia.begin(), argumento);
        if(argumento->tag == TAG_DBL || argumento->tag == TAG_LNG){
            Operando* op_vazio = new Operando();
            op_vazio->tag = TAG_VAZ;
            argumentos_instancia.insert(argumentos_instancia.begin()+1, op_vazio);
        }
    }
    Operando* classe_atual = this->topo()->desempilhar();
    argumentos_instancia.insert(argumentos_instancia.begin(), classe_atual);
    Frame* novo_frame = new Frame(metodo);

    for(int i=0; i<argumentos_instancia.size(); i++){
        novo_frame->var_locais.at(i) = argumentos_instancia.at(i);
    }

    if (metodo)
        empilhar(novo_frame);
}

void Interpretador::empilhar (InterCPDado *const dados){
    if ((dados->tag == TAG_REF_MTD) || (dados->tag == TAG_REF_MTD_ITF))
        return empilhar_frame(dados);

    if (dados->tag == TAG_CLAS) {
        return empilhar_operandos(dados);
    }
}

void Interpretador::empilhar_frame (InterCPDado *const dados){
    std::string nome_classe = dados->tag == TAG_REF_MTD ? \
        (dynamic_cast<InfoRefMetodo*>(dados))->get_nome_classe() : \
        (dynamic_cast<InfoRefMetInterface*>(dados))->get_nome_classe();
    nome_classe += ".class";

    if(nome_classe.find("java/") == std::string::npos) {
        nome_classe = "CasosTestes/" + nome_classe;
    }

    u1 status = this->area_metodos->carregar(nome_classe);

    if ((status != JA_EXISTIA) && (status != SUCESSO))
        return;

    std::string nome_metodo = dados->tag == TAG_REF_MTD ? \
        (dynamic_cast<InfoRefMetodo*>(dados))->get_nome_metodo() : \
        (dynamic_cast<InfoRefMetInterface*>(dados))->get_nome_metodo();

    empilhar(nome_metodo, nome_classe);
}

void Interpretador::empilhar_operandos (InterCPDado *const dados){
    // std::string nome_classe = (dynamic_cast<InfoRefCampo*>(dados))->get_nome_classe();
    // std::cout << nome_classe << std::endl;

    // u1 status = this->area_metodos->carregar(nome_classe);

    // if ((status != JA_EXISTIA) && (status != SUCESSO))
    //     return;

    // std::string nome_campo = (dynamic_cast<InfoRefCampo*>(dados))->get_nome_campo();

    // VERIFICAR
    if(dados->tag == TAG_CLAS) {
        std::string nome_classe = (dynamic_cast<InfoClasse*>(dados))->get_nome();
        Operando* op = new Operando();
        if(nome_classe == "java/lang/StringBuilder" || nome_classe == "Ljava/lang/String") {
            op->tag = TAG_STR;
            op->tipo_string = "";
        }else{
            op->tag = TAG_REF; // TAG_CLAS?
            u1 status = this->area_metodos->carregar("CasosTestes/"+ nome_classe +".class");
            if ((status != JA_EXISTIA) && (status != SUCESSO))
                return;

            ArqClass * arquivo_classe = this->area_metodos->localizar("CasosTestes/"+ nome_classe +".class");
            op->obj = new Objeto(nome_classe, arquivo_classe);
        }
        this->topo()->pilha_operandos.push(op);
    }
}

Frame* Interpretador::topo (){
    return this->pilha_frames.back();
}

Frame* Interpretador::desempilhar (){
    Frame *topo_ = topo();

    this->pilha_frames.pop_back();

    if (topo_->retorno) {
        topo()->pilha_operandos.push(topo_->retorno);
    }

    return topo_;
}

void Interpretador::deletar(){
    for (auto &frame : this->pilha_frames)
        frame->deletar();

    std::vector<Frame *>().swap(this->pilha_frames);

    delete this;
}
