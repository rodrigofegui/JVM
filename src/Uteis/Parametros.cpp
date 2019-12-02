#include "../../lib/Uteis/Parametros.hpp"
#include "../../lib/Uteis/Arquivos.hpp"


void Parametros::get_entradas (int argc, char *argv[]){
    check_modo(argc, argv);

    check_nome_arqs(argc, argv);
}

void Parametros::check_modo (int argc, char *argv[]){
    if (tem_modo_cli(argc, argv))
        return;

    std::string leitura;

    std::cout << "Não houve o modo de operação!" << std::endl;

    do{
        std::cout << "Digite o modo de operação: [e/i]" << std::endl;
        std::cin >> leitura; getchar();

        if (!leitura.compare("e") || !leitura.compare("i"))
            break;

        std::cout << "Entrada inválida!" << std::endl;
        std::cout << "Só pode ser ou 'e' ou 'i'" << std::endl;

    }while(true);

    set_modo("-" + leitura);
}

void Parametros::check_nome_arqs (int argc, char *argv[]){
     if (tem_arqs_cli(argc, argv)) {
        return;
    }

    std::string leitura;

    std::cout << "Não houve arquivo por linha de comando!" << std::endl;

    do{
        std::cout << "Digite o nome do arquivo que deseja incluir:" << std::endl;
        std::cin >> leitura; getchar();

        this->nome_arqs.push_back(leitura);

        std::cout << "Deseja incluir mais um arquivo? Digite 'q' caso não queira:" << std::endl;
        std::cin >> leitura; getchar();

        if (!leitura.compare("q"))
            break;
    }while(true);
}

u1 Parametros::tem_modo_cli (int argc, char *argv[]){
    for (int cnt = 1; cnt < argc; cnt++){
        std::string temp(argv[cnt]);

        if (temp.compare("-e") && temp.compare("-i"))
            continue;

        set_modo(temp);
        return 1;
    }

    return 0;
}

u1 Parametros::tem_arqs_cli (int argc, char *argv[]){
    u1 achou_tag = 0;

    for (int cnt = 1; cnt < argc; cnt++){
        std::string temp(argv[cnt]);

        if (!achou_tag){
            if (!temp.compare("--arqs") || !temp.compare("--arq"))
                achou_tag = 1;

            continue;

        }else if (temp.compare("-e") && temp.compare("-i") && temp.compare("-f") && temp.compare("-p"))
            this->nome_arqs.push_back(temp);
        else
            break;
    }

    return this->nome_arqs.size();
}

void Parametros::set_modo (std::string modo){
    if (!modo.compare("-e"))
        this->flags &= 0xF1;
    else
        this->flags &= 0xF2;
}

u1 Parametros::e_leitura (){
    if (this->flags & 0x01)
        return 1;

    return 0;
}

void Parametros::deletar (){
    std::vector<std::string>().swap(nome_arqs);
}
