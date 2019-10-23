#include <iostream>
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


std::string get_flag(u2 a_verificar){
    std::string flag;

    if (a_verificar & FLG_PBC)
        flag += "pública ";

    if (a_verificar & FLG_PVD)
        flag += "privada ";

    if (a_verificar & FLG_PTD)
        flag += "protegida ";

    if (a_verificar & FLG_STC)
        flag += "estática ";

    if (a_verificar & FLG_FNL)
        flag += "final ";

    if (a_verificar & FLG_SPR)
        flag += "super ";

    if (a_verificar & FLG_VLT)
        flag += "volátil ";

    if (a_verificar & FLG_TST)
        flag += "transiente ";

    if (a_verificar & FLG_NTV)
        flag += "nativa ";

    if (a_verificar & FLG_ITF)
        flag += "interface ";

    if (a_verificar & FLG_ABS)
        flag += "abstrata ";

    if (a_verificar & FLG_STT)
        flag += "estrita ";

    if (a_verificar & FLG_SNT)
        flag += "sintética ";

    if (!flag.length())
        return "Sem expecificação";

    flag += "[" + get_hex_2(a_verificar) + "]";

    return flag;
}
