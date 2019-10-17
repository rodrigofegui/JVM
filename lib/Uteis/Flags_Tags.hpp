#ifndef UTEIS_TAGS_FLAGS_HPP
    #define UTEIS_TAGS_FLAGS_HPP

    /**
     *  @file   Flags_Tags.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Catálogo de todas as flags e tags utilizadas neste projeto
     */
    #include <string>
    #include "../Tipos/Basicos.hpp"

    /** Versionamento do JAVAC */
    #define V1_1 45
    #define V1_2 46
    #define V1_3 47
    #define V1_4 48
    #define V5 49
    #define V6 50
    #define V7 51
    #define V8 52
    #define V9 53
    #define V10 54
    #define V11 55
    #define V12 56
    #define V13 57
    #define V14 58

    /** Tags dos dados da tabela de símbolos */
    #define TAG_UTF 1
    #define TAG_INT 3
    #define TAG_FLT 4
    #define TAG_LNG 5
    #define TAG_DBL 6
    #define TAG_CLAS 7
    #define TAG_STR 8
    #define TAG_REF_CMP 9
    #define TAG_REF_MTD 10
    #define TAG_REF_MTD_ITF 11
    #define TAG_NOM_TIP 12

    /** Flags de acesso */
    #define FLG_PBC 0x0001
    #define FLG_PVD 0x0002
    #define FLG_PTD 0x0004
    #define FLG_STC 0x0008
    #define FLG_FNL 0x0010
    #define FLG_SPR 0x0020
    #define FLG_VLT 0x0040
    #define FLG_TST 0x0080
    #define FLG_NTV 0x0100
    #define FLG_ITF 0x0200
    #define FLG_ABS 0x0400
    #define FLG_STT 0x0800

    /**
     *  Recuperação de uma flag traduzida
     *  @param a_verificar Flag a ser analisada
     */
    std::string get_flag(u2 a_verificar);
#endif
