#ifndef UTEIS_ARQUIVOS_HPP
    #define UTEIS_ARQUIVOS_HPP

    /**
     *  @file   Arquivos.hpp
     *  @brief  Junção de funções para manipulação de arquivos ou relacionados
     *  a estes úteis para este projeto
     */
    #include <stdio.h>
    #include <string>
    #include "../Tipos/Basicos.hpp"

    /**
     *  Abertura de um arquivo binário, verificando a ocorrência ou não erros no processo
     *  @param nome_arq Nome do arquivo a ser manipulado
     *  @returns Um FILE* se houve êxito na manipulado, caso contrário encerra o programa
     */
    FILE* abrir (const char *nome_arq);

    /**
     *  Leitura de 1 byte de um arquivo, considerado como binário
     *  @param arq Arquivo a ser manipulado
     *  @param dst Variável a ter o valor alterado conforme a leitura do arquivo
     */
    void ler_u1 (FILE *const arq, u1 *dst);

    /**
     *  Leitura de 2 bytes de um arquivo, considerado como binário
     *  @param arq Arquivo a ser manipulado
     *  @param dst Variável a ter o valor alterado conforme a leitura do arquivo
     */
    void ler_u2 (FILE *const arq, u2 *dst);

    /**
     *  Leitura de 4 bytes de um arquivo, considerado como binário
     *  @param arq Arquivo a ser manipulado
     *  @param dst Variável a ter o valor alterado conforme a leitura do arquivo
     */
    void ler_u4 (FILE *const arq, u4 *dst);

    /**
     *  Recuperação do padding a ser utilizado na numeração de tabelas, conforme as
     *  potências de 10
     *  @param tam Tamanho a ser considerado
     *  @returns A quantidade de dígitos de padding, ex: com um tamanho máximo até 9
     *  o padding é 1, até 99 é 2 e assim em diante
     */
    int get_padding (const int tam);

    /**
     *  Recuperação da representação em hexadecimal de um número de 2 bytes
     *  @param fonte Número a ser exibido
     *  @returns String no formato "0xFFFF"
     */
    std::string get_hex_2 (const u2 fonte);

    /**
     *  Recuperação da representação em hexadecimal de um número de 4 bytes
     *  @param fonte Número a ser exibido
     *  @returns String no formato "0xFFFFFFFF"
     */
    std::string get_hex_4 (const u4 fonte);
#endif
