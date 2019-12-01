#ifndef TIPOS_BYTE_CODE_HPP
    #define TIPOS_BYTE_CODE_HPP

    /**
     *  @file   ByteCode.hpp
     *  @brief  Definição dos mnemônicos e dos manipuladores dos bytecodes da JVM, considerando tanto o
     *  [site oficial da JVM](https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-6.html) quanto os slides da
     *  matéria quanto o site
     */
    #include <string>
    #include <vector>
    #include <cstring>
    #include <cmath>
    #include "./Basicos.hpp"
    #include "../Tipos/Frame.hpp"
    #include "../Tipos/CPDados.hpp"
    #include "../Uteis/Flags_Tags.hpp"

    #define CAT1(x,y) (x ## y)
    #define FUNC(y) (CAT1(manipulador, y))

    /**  Estrutura de um item da tabela de bytecodes */
    typedef struct bc {
        /** Nome que indentifica o bytecode */
        std::string mnemonico;
        /** Função manipuladora do bytecode */
        int bytes;
        void (*manipulador) (Frame *frame);
    } ByteCode;

    //  Conjunto de ByteCode a ser consultado pelo sitema
    extern std::vector<ByteCode> bytecodes;

    /*  Inicialização da tabela de bytecodes da JVM */
    void iniciar_bytecodes ();

    /**
     *  Manipulador de bytecode não implementado pelo sistema
     *  @param codigo Código ao qual o bytecode está sendo usado
     *  @param c_pos Posição atual do código em que aparece o bytecode
     *  @param e_interpretador Flag que varia o comportamento do manipulador, 1 é como interpretador
     *  caso contrário será como exibidor
     *  @returns Quantidade de bytes do código que foram necessários para o funcionamento do manipulador
     */
    void manipulador_undef (Frame *frame);

    void manipulador_iconst (Frame *frame, int valor);

    void manipulador_xstore_n (Frame *frame, u1 ind, u1 tag);
    void manipulador_xstore (Frame *frame, u1 tag);
    void manipulador_xastore (Frame *frame, u1 tag);

    void manipulador_xload_n (Frame *frame, u1 ind);
    void manipulador_xaload (Frame *frame);

    void manipulador_xreturn (Frame *frame, u1 tag);

    void get_deslocamento (Frame *frame);


    // 0 (0x00)
    void manipulador_nop (Frame *frame);

    // 1 (0x01)
    void manipulador_aconst_null (Frame *frame);
    // 2 (0x02)
    void manipulador_iconst_m1 (Frame *frame);
    // 3 (0x03)
    void manipulador_iconst_0 (Frame *frame);
    // 4 (0x04)
    void manipulador_iconst_1 (Frame *frame);
    // 5 (0x05)
    void manipulador_iconst_2 (Frame *frame);

    // 6 (0x06)
    void manipulador_iconst_3 (Frame *frame);
    // 7 (0x07)
    void manipulador_iconst_4 (Frame *frame);
    // 8 (0x08)
    void manipulador_iconst_5 (Frame *frame);
    // 9 (0x09)
    void manipulador_lconst_0 (Frame *frame);
    // 10 (0x0A)
    void manipulador_lconst_1 (Frame *frame);

    // 11 (0x0B)
    void manipulador_fconst_0 (Frame *frame);
    // 12 (0x0C)
    void manipulador_fconst_1 (Frame *frame);
    // 13 (0x0D)
    void manipulador_fconst_2 (Frame *frame);
    // 14 (0x0E)
    void manipulador_dconst_0 (Frame *frame);
    // 15 (0x0F)
    void manipulador_dconst_1 (Frame *frame);

    // 16 (0x10)
    void manipulador_bipush (Frame *frame);
    // 17 (0x11)
    void manipulador_sipush (Frame *frame);
    // 18 (0x12)
    void manipulador_ldc (Frame *frame);
    // 19 (0x13)
    void manipulador_ldc_w (Frame *frame);
    // 20 (0x14)
    void manipulador_ldc2_w (Frame *frame);

    // 21 (0x15)
    void manipulador_iload (Frame *frame);
    // 22 (0x16)
    void manipulador_lload (Frame *frame);
    // 23 (0x17)
    void manipulador_fload (Frame *frame);
    // 24 (0x18)
    void manipulador_dload (Frame *frame);
    // 25 (0x19)
    void manipulador_aload (Frame *frame);

    // 26 (0x1A)
    void manipulador_iload_0 (Frame *frame);
    // 27 (0x1B)
    void manipulador_iload_1 (Frame *frame);
    // 28 (0x1C)
    void manipulador_iload_2 (Frame *frame);
    // 29 (0x1D)
    void manipulador_iload_3 (Frame *frame);
    // 30 (0x1E)
    void manipulador_lload_0 (Frame *frame);

    // 31 (0x1F)
    void manipulador_lload_1 (Frame *frame);
    // 32 (0x20)
    void manipulador_lload_2 (Frame *frame);
    // 33 (0x21)
    void manipulador_lload_3 (Frame *frame);
    // 34 (0x22)
    void manipulador_fload_0 (Frame *frame);
    // 35 (0x23)
    void manipulador_fload_1 (Frame *frame);

    // 36 (0x24)
    void manipulador_fload_2 (Frame *frame);
    // 37 (0x25)
    void manipulador_fload_3 (Frame *frame);
    // 38 (0x26)
    void manipulador_dload_0 (Frame *frame);
    // 39 (0x27)
    void manipulador_dload_1 (Frame *frame);
    // 40 (0x28)
    void manipulador_dload_2 (Frame *frame);

    // 41 (0x29)
    void manipulador_dload_3 (Frame *frame);
    // 42 (0x2A)
    void manipulador_aload_0 (Frame *frame);
    // 43 (0x2B)
    void manipulador_aload_1 (Frame *frame);
    // 44 (0x2C)
    void manipulador_aload_2 (Frame *frame);
    // 45 (0x2D)
    void manipulador_aload_3 (Frame *frame);

    // 46 (0x2E)
    void manipulador_iaload (Frame *frame);
    // 47 (0x2F)
    void manipulador_laload (Frame *frame);
    // 48 (0x30)
    void manipulador_faload (Frame *frame);
    // 49 (0x31)
    void manipulador_daload (Frame *frame);
    // 50 (0x32)
    void manipulador_aaload (Frame *frame);

    // 51 (0x33)
    void manipulador_baload (Frame *frame);
    // 52 (0x34)
    void manipulador_caload (Frame *frame);
    // 53 (0x35)
    void manipulador_saload (Frame *frame);
    // 54 (0x36)
    void manipulador_istore (Frame *frame);
    // 55 (0x37)
    void manipulador_lstore (Frame *frame);

    // 56 (0x38)
    void manipulador_fstore (Frame *frame);
    // 57 (0x39)
    void manipulador_dstore (Frame *frame);
    // 58 (0x3A)
    void manipulador_astore (Frame *frame);
    // 59 (0x3B)
    void manipulador_istore_0 (Frame *frame);
    // 60 (0x3C)
    void manipulador_istore_1 (Frame *frame);

    // 61 (0x3D)
    void manipulador_istore_2 (Frame *frame);
    // 62 (0x3E)
    void manipulador_istore_3 (Frame *frame);
    // 63 (0x3F)
    void manipulador_lstore_0 (Frame *frame);
    // 64 (0x40)
    void manipulador_lstore_1 (Frame *frame);
    // 65 (0x41)
    void manipulador_lstore_2 (Frame *frame);

    // 66 (0x42)
    void manipulador_lstore_3 (Frame *frame);
    // 67 (0x43)
    void manipulador_fstore_0 (Frame *frame);
    // 68 (0x44)
    void manipulador_fstore_1 (Frame *frame);
    // 69 (0x45)
    void manipulador_fstore_2 (Frame *frame);
    // 70 (0x46)
    void manipulador_fstore_3 (Frame *frame);

    // 71 (0x47)
    void manipulador_dstore_0 (Frame *frame);
    // 72 (0x48)
    void manipulador_dstore_1 (Frame *frame);
    // 73 (0x49)
    void manipulador_dstore_2 (Frame *frame);
    // 74 (0x4A)
    void manipulador_dstore_3 (Frame *frame);
    // 75 (0x4B)
    void manipulador_astore_0 (Frame *frame);

    // 76 (0x4C)
    void manipulador_astore_1 (Frame *frame);
    // 77 (0x4D)
    void manipulador_astore_2 (Frame *frame);
    // 78 (0x4E)
    void manipulador_astore_3 (Frame *frame);
    // 79 (0x4F)
    void manipulador_iastore (Frame *frame);
    // 80 (0x50)
    void manipulador_lastore (Frame *frame);

    // 81 (0x51)
    void manipulador_fastore (Frame *frame);
    // 82 (0x52)
    void manipulador_dastore (Frame *frame);
    // 83 (0x53)
    void manipulador_aastore (Frame *frame);
    // 84 (0x54)
    void manipulador_bastore (Frame *frame);
    // 85 (0x55)
    void manipulador_castore (Frame *frame);

    // 86 (0x56)
    void manipulador_sastore (Frame *frame);
    // 87 (0x57)
    void manipulador_pop (Frame *frame);
    // 88 (0x58)
    void manipulador_pop2 (Frame *frame);
    // 89 (0x59)
    void manipulador_dup (Frame *frame);
    // 90 (0x5A)
    void manipulador_dup_x1 (Frame *frame);

    // 91 (0x5B)
    void manipulador_dup_x2 (Frame *frame);
    // 92 (0x5C)
    void manipulador_dup2 (Frame *frame);
    // 93 (0x5D)
    void manipulador_dup2_x1 (Frame *frame);
    // 94 (0x5E)
    void manipulador_dup2_x2 (Frame *frame);
    // 95 (0x5F)
    void manipulador_swap (Frame *frame);

    // 96 (0x60)
    void manipulador_iadd (Frame *frame);
    // 97 (0x61)
    void manipulador_ladd (Frame *frame);
    // 98 (0x62)
    void manipulador_fadd (Frame *frame);
    // 99 (0x63)
    void manipulador_dadd (Frame *frame);
    // 100 (0x64)
    void manipulador_isub (Frame *frame);

    // 101 (0x65)
    void manipulador_lsub (Frame *frame);
    // 102 (0x66)
    void manipulador_fsub (Frame *frame);
    // 103 (0x67)
    void manipulador_dsub (Frame *frame);
    // 104 (0x68)
    void manipulador_imul (Frame *frame);
    // 105 (0x69)
    void manipulador_lmul (Frame *frame);

    // 106 (0x6A)
    void manipulador_fmul (Frame *frame);
    // 107 (0x6B)
    void manipulador_dmul (Frame *frame);
    // 108 (0x6C)
    void manipulador_idiv (Frame *frame);
    // 109 (0x6D)
    void manipulador_ldiv (Frame *frame);
    // 110 (0x6E)
    void manipulador_fdiv (Frame *frame);

    // 111 (0x6F)
    void manipulador_ddiv (Frame *frame);
    // 112 (0x70)
    void manipulador_irem (Frame *frame);
    // 113 (0x71)
    void manipulador_lrem (Frame *frame);
    // 114 (0x72)
    void manipulador_frem (Frame *frame);
    // 115 (0x73)
    void manipulador_drem (Frame *frame);

    // 116 (0x74)
    void manipulador_ineg (Frame *frame);
    // 117 (0x75)
    void manipulador_lneg (Frame *frame);
    // 118 (0x76)
    void manipulador_fneg (Frame *frame);
    // 119 (0x77)
    void manipulador_dneg (Frame *frame);
    // 120 (0x78)
    void manipulador_ishl (Frame *frame);

    // 121 (0x79)
    void manipulador_lshl (Frame *frame);
    // 122 (0x7A)
    void manipulador_ishr (Frame *frame);
    // 123 (0x7B)
    void manipulador_lshr (Frame *frame);
    // 124 (0x7C)
    void manipulador_iushr (Frame *frame);
    // 125 (0x7D)
    void manipulador_lushr (Frame *frame);

    // 126 (0x7E)
    void manipulador_iand (Frame *frame);
    // 127 (0x7F)
    void manipulador_land (Frame *frame);
    // 128 (0x80)
    void manipulador_ior (Frame *frame);
    // 129 (0x81)
    void manipulador_lor (Frame *frame);
    // 130 (0x82)
    void manipulador_ixor (Frame *frame);

    // 131 (0x83)
    void manipulador_lxor (Frame *frame);
    // 132 (0x84)
    void manipulador_iinc (Frame *frame);
    // 133 (0x85)
    void manipulador_i2l (Frame *frame);
    // 134 (0x86)
    void manipulador_i2f (Frame *frame);
    // 135 (0x87)
    void manipulador_i2d (Frame *frame);

    // 136 (0x88)
    void manipulador_l2i (Frame *frame);
    // 137 (0x89)
    void manipulador_l2f (Frame *frame);
    // 138 (0x8A)
    void manipulador_l2d (Frame *frame);
    // 139 (0x8B)
    void manipulador_f2i (Frame *frame);
    // 140 (0x8C)
    void manipulador_f2l (Frame *frame);

    // 141 (0x8D)
    void manipulador_f2d (Frame *frame);
    // 142 (0x8E)
    void manipulador_d2i (Frame *frame);
    // 143 (0x8F)
    void manipulador_d2l (Frame *frame);
    // 144 (0x90)
    void manipulador_d2f (Frame *frame);
    // 145 (0x91)
    void manipulador_i2b (Frame *frame);

    // 146 (0x92)
    void manipulador_i2c (Frame *frame);
    // 147 (0x93)
    void manipulador_i2s (Frame *frame);
    // 148 (0x94)
    void manipulador_lcmp (Frame *frame);
    // 149 (0x95)
    void manipulador_fcmpl (Frame *frame);
    // 150 (0x96)
    void manipulador_fcmpg (Frame *frame);

    // 151 (0x97)
    void manipulador_dcmpl (Frame *frame);
    // 152 (0x98)
    void manipulador_dcmpg (Frame *frame);
    // 153 (0x99)
    void manipulador_ifeq (Frame *frame);
    // 154 (0x9A)
    void manipulador_ifne (Frame *frame);
    // 155 (0x9B)
    void manipulador_iflt (Frame *frame);

    // 156 (0x9C)
    void manipulador_ifge (Frame *frame);
    // 157 (0x9D)
    void manipulador_ifgt (Frame *frame);
    // 158 (0x9E)
    void manipulador_ifle (Frame *frame);
    // 159 (0x9F)
    void manipulador_if_icmpeq (Frame *frame);
    // 160 (0xA0)
    void manipulador_if_icmpne (Frame *frame);

    // 161 (0xA1)
    void manipulador_if_icmplt (Frame *frame);
    // 162 (0xA2)
    void manipulador_if_icmpge (Frame *frame);
    // 163 (0xA3)
    void manipulador_if_icmpgt (Frame *frame);
    // 164 (0xA4)
    void manipulador_if_icmple (Frame *frame);
    // 165 (0xA5)
    void manipulador_if_acmpeq (Frame *frame);

    // 166 (0xA6)
    void manipulador_if_acmpne (Frame *frame);
    // 167 (0xA7)
    void manipulador_goto (Frame *frame);
    // 168 (0xA8)
    void manipulador_jsr (Frame *frame);
    // 169 (0xA9)
    void manipulador_ret (Frame *frame);
    // 170 (0xAA)
    void manipulador_tableswitch (Frame *frame);

    // 171 (0xAB)
    void manipulador_lookupswitch (Frame *frame);
    // 172 (0xAC)
    void manipulador_ireturn (Frame *frame);
    // 173 (0xAD)
    void manipulador_lreturn (Frame *frame);
    // 174 (0xAE)
    void manipulador_freturn (Frame *frame);
    // 175 (0xAF)
    void manipulador_dreturn (Frame *frame);

    // 176 (0xB0)
    void manipulador_areturn (Frame *frame);
    // 177 (0xB1)
    void manipulador_return (Frame *frame);
    // 178 (0xB2)
    void manipulador_getstatic (Frame *frame);
    // 179 (0xB3)
    void manipulador_putstatic (Frame *frame);
    // 180 (0xB4)
    void manipulador_getfield (Frame *frame);

    // 181 (0xB5)
    void manipulador_putfield (Frame *frame);
    // 182 (0xB6)
    void manipulador_invokevirtual (Frame *frame);
    // 183 (0xB7)
    void manipulador_invokespecial (Frame *frame);
    // 184 (0xB8)
    void manipulador_invokestatic (Frame *frame);
    // 185 (0xB9)
    void manipulador_invokeinterface (Frame *frame);

    // 186 (0xBA)
    void manipulador_invokedynamic (Frame *frame);

    // 187 (0xBB)
    void manipulador_new (Frame *frame);
    // 188 (0xBC)
    void manipulador_newarray (Frame *frame);
    // 189 (0xBD)
    void manipulador_anewarray (Frame *frame);
    // 190 (0xBE)
    void manipulador_arraylength (Frame *frame);

    // 191 (0xBF)
    void manipulador_athrow (Frame *frame);
    // 192 (0xC0)
    void manipulador_checkcast (Frame *frame);
    // 193 (0xC1)
    void manipulador_instanceof (Frame *frame);
    // 194 (0xC2)
    void manipulador_monitorenter (Frame *frame);
    // 195 (0xC3)
    void manipulador_monitorexit (Frame *frame);

    // 196 (0xC4)
    void manipulador_wide (Frame *frame);
    // 197 (0xC5)
    void manipulador_multianewarray (Frame *frame);
    // 198 (0xC6)
    void manipulador_ifnull (Frame *frame);
    // 199 (0xC7)
    void manipulador_ifnonnull (Frame *frame);
    // 200 (0xC8)
    void manipulador_goto_w (Frame *frame);

    // 201 (0xC9)
    void manipulador_jsr_w (Frame *frame);
    // 202 (0xCA)
    void manipulador_break_point (Frame *frame);
    // 254 (0xFE)
    void manipulador_impdep_1 (Frame *frame);
    // 255 (0xFF)
    void manipulador_impdep_2 (Frame *frame);
#endif
