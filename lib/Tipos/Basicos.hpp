#ifndef TIPOS_BASICOS_HPP
    #define TIPOS_BASICOS_HPP

    /**
     *  @file   Basicos.hpp
     *  @brief Definição dos tipos básicos a serem utilizados
     */
    #include <stdint.h>

    /** Tipo básico para 1 byte sem sinal */
    typedef uint8_t u1;
    /** Tipo básico para 2 bytes sem sinal */
    typedef uint16_t u2;
    /** Tipo básico para 4 bytes sem sinal */
    typedef uint32_t u4;

    /** Código característico de um arquivo .class válido */
    #define COD_ARQ_CLASS 0xCAFEBABE
#endif
