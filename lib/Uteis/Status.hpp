#ifndef UTEIS_STATUS_HPP
    #define UTEIS_STATUS_HPP

    /**
     *  @file   Status.hpp
     *  @brief  Códigos de erros e avisos considerados neste projeto
     */
    enum erros {
        E_QNT_ARGS = 200,
        E_MODO,
        E_TIPO,
        E_SEM_ARQ,
        E_NAO_CLASS,
        E_ABRIR_ARQUIVO,
        E_ALOCAR,
        E_ALOCAR_CLASS,
        E_ALOCAR_TAB_SIMB,
        E_ALOCAR_UTF8,
        E_ALOCAR_TAB_CAMPOS,
        E_ALOCAR_ATTR_CAMPOS,
        E_ALOCAR_INFO_ATTR_CAMPOS,
        E_ALOCAR_TAB_METODOS,
        E_ALOCAR_ATTR_METODOS,
        E_ALOCAR_INFO_ATTR_METODOS,
        E_ALOCAR_COD_METODOS,
        E_ALOCAR_EXC_COD_METODOS,
        E_ALOCAR_ATTR_COD_METODOS,
        E_ALOCAR_LIN_NMB_ATTR_COD_METODOS,
        E_ALOCAR_TAB_ATRIBUTOS
    };

    enum avisos {
        W_SEM_MODO = 100,
    };

    #define SUCESSO 0
#endif
