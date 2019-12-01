#include <iostream>
#include "../../lib/Uteis/Arquivos.hpp"
#include "../../lib/Uteis/Flags_Tags.hpp"


std::string get_flag (u2 a_verificar){
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

std::string get_tag (u1 a_verificar){
    if (a_verificar == TAG_VAZ)
        return "'Indefinido'";

    if (a_verificar == TAG_UTF)
        return "'UTF-8'";

    if (a_verificar == TAG_INT)
        return "'Inteiro'";

    if (a_verificar == TAG_FLT)
        return "'Float'";

    if (a_verificar == TAG_LNG)
        return "'Longo'";

    if (a_verificar == TAG_DBL)
        return "'Double'";

    if (a_verificar == TAG_CLAS)
        return "'Classe'";

    if (a_verificar == TAG_STR)
        return "'String'";

    if (a_verificar == TAG_REF_CMP)
        return "'Ref. para campo'";

    if (a_verificar == TAG_REF_MTD)
        return "'Ref. para método'";

    if (a_verificar == TAG_REF_MTD_ITF)
        return "'Ref. para método de interface'";

    if (a_verificar == TAG_NOM_TIP)
        return "'Nome e tipo'";

    if (a_verificar == TAG_BYTE)
        return "'Byte'";

    if (a_verificar == TAG_REF)
        return "'Referência'";

    if (a_verificar == TAG_CHR)
        return "'Char'";

    if (a_verificar == TAG_SHT)
        return "'Short'";

    if (a_verificar == TAG_ARR)
        return "'Array'";
}

u1 to_tag (char a_verificar){
    if (a_verificar == 'B')
        return TAG_BYTE;

    if (a_verificar == 'C')
        return TAG_CHR;

    if (a_verificar == 'D')
        return TAG_DBL;

    if (a_verificar == 'F')
        return TAG_FLT;

    if (a_verificar == 'I')
        return TAG_INT;

    if (a_verificar == 'J')
        return TAG_LNG;

    if ((a_verificar == 'L') || (a_verificar == '['))
        return TAG_REF;

    if (a_verificar == 'S')
        return TAG_SHT;

    if (a_verificar == 'Z')
        return TAG_BLN;

    return TAG_VAZ;
}
