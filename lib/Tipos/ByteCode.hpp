#ifndef TIPOS_BYTE_CODE_HPP
    #define TIPOS_BYTE_CODE_HPP

    /**
     *  @file   ByteCode.hpp
     *  @author Rodrigo F. Guimarães
     *  @brief  Definição dos mnemônicos e dos manipuladores dos bytecodes da JVM, considerando tanto o
     *  [site oficial da JVM](https://docs.oracle.com/javase/specs/jvms/se7/html/jvms-6.html) quanto os slides da
     *  matéria quanto o site
     */
    #include <string>
    #include <vector>
    #include "Basicos.hpp"

    #define CAT1(x,y) (x ## y)
    #define FUNC(y) (CAT1(manipulador, y))

    /**  Estrutura de um item da tabela de bytecodes */
    typedef struct bc {
        /** Nome que indentifica o bytecode */
        std::string mnemonico;
        /** Função manipuladora do bytecode */
        int (*manipulador) (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
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
    int manipulador_undef (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 0 (0x00)
    int manipulador_nop (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 1 (0x01)
    int manipulador_aconst_null (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 2 (0x02)
    int manipulador_iconst_m1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 3 (0x03)
    int manipulador_iconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 4 (0x04)
    int manipulador_iconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 5 (0x05)
    int manipulador_iconst_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 6 (0x06)
    int manipulador_iconst_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 7 (0x07)
    int manipulador_iconst_4 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 8 (0x08)
    int manipulador_iconst_5 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 9 (0x09)
    int manipulador_lconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 10 (0x0A)
    int manipulador_lconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 11 (0x0B)
    int manipulador_fconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 12 (0x0C)
    int manipulador_fconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 13 (0x0D)
    int manipulador_fconst_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 14 (0x0E)
    int manipulador_dconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 15 (0x0F)
    int manipulador_dconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 16 (0x10)
    int manipulador_bipush (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 17 (0x11)
    int manipulador_sipush (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 18 (0x12)
    int manipulador_ldc (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 19 (0x13)
    int manipulador_ldc_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 20 (0x14)
    int manipulador_ldc2_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 21 (0x15)
    int manipulador_iload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 22 (0x16)
    int manipulador_lload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 23 (0x17)
    int manipulador_fload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 24 (0x18)
    int manipulador_dload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 25 (0x19)
    int manipulador_aload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 26 (0x1A)
    int manipulador_iload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 27 (0x1B)
    int manipulador_iload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 28 (0x1C)
    int manipulador_iload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 29 (0x1D)
    int manipulador_iload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 30 (0x1E)
    int manipulador_lload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 31 (0x1F)
    int manipulador_lload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 32 (0x20)
    int manipulador_lload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 33 (0x21)
    int manipulador_lload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 34 (0x22)
    int manipulador_fload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 35 (0x23)
    int manipulador_fload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 36 (0x24)
    int manipulador_fload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 37 (0x25)
    int manipulador_fload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 38 (0x26)
    int manipulador_dload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 39 (0x27)
    int manipulador_dload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 40 (0x28)
    int manipulador_dload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 41 (0x29)
    int manipulador_dload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 42 (0x2A)
    int manipulador_aload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 43 (0x2B)
    int manipulador_aload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 44 (0x2C)
    int manipulador_aload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 45 (0x2D)
    int manipulador_aload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 46 (0x2E)
    int manipulador_iaload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 47 (0x2F)
    int manipulador_laload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 48 (0x30)
    int manipulador_faload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 49 (0x31)
    int manipulador_daload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 50 (0x32)
    int manipulador_aaload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 51 (0x33)
    int manipulador_baload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 52 (0x34)
    int manipulador_caload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 53 (0x35)
    int manipulador_saload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 54 (0x36)
    int manipulador_istore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 55 (0x37)
    int manipulador_lstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 56 (0x38)
    int manipulador_fstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 57 (0x39)
    int manipulador_dstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 58 (0x3A)
    int manipulador_astore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 59 (0x3B)
    int manipulador_istore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 60 (0x3C)
    int manipulador_istore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 61 (0x3D)
    int manipulador_istore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 62 (0x3E)
    int manipulador_istore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 63 (0x3F)
    int manipulador_lstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 64 (0x40)
    int manipulador_lstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 65 (0x41)
    int manipulador_lstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 66 (0x42)
    int manipulador_lstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 67 (0x43)
    int manipulador_fstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 68 (0x44)
    int manipulador_fstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 69 (0x45)
    int manipulador_fstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 70 (0x46)
    int manipulador_fstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 71 (0x47)
    int manipulador_dstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 72 (0x48)
    int manipulador_dstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 73 (0x49)
    int manipulador_dstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 74 (0x4A)
    int manipulador_dstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 75 (0x4B)
    int manipulador_astore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 76 (0x4C)
    int manipulador_astore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 77 (0x4D)
    int manipulador_astore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 78 (0x4E)
    int manipulador_astore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 79 (0x4F)
    int manipulador_iastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 80 (0x50)
    int manipulador_lastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 81 (0x51)
    int manipulador_fastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 82 (0x52)
    int manipulador_dastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 83 (0x53)
    int manipulador_aastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 84 (0x54)
    int manipulador_bastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 85 (0x55)
    int manipulador_castore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 86 (0x56)
    int manipulador_sastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 87 (0x57)
    int manipulador_pop (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 88 (0x58)
    int manipulador_pop2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 89 (0x59)
    int manipulador_dup (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 90 (0x5A)
    int manipulador_dup_x1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 91 (0x5B)
    int manipulador_dup_x2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 92 (0x5C)
    int manipulador_dup2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 93 (0x5D)
    int manipulador_dup2_x1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 94 (0x5E)
    int manipulador_dup2_x2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 95 (0x5F)
    int manipulador_swap (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 96 (0x60)
    int manipulador_iadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 97 (0x61)
    int manipulador_ladd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 98 (0x62)
    int manipulador_fadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 99 (0x63)
    int manipulador_dadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 100 (0x64)
    int manipulador_isub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 101 (0x65)
    int manipulador_lsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 102 (0x66)
    int manipulador_fsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 103 (0x67)
    int manipulador_dsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 104 (0x68)
    int manipulador_imul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 105 (0x69)
    int manipulador_lmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 106 (0x6A)
    int manipulador_fmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 107 (0x6B)
    int manipulador_dmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 108 (0x6C)
    int manipulador_idiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 109 (0x6D)
    int manipulador_ldiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 110 (0x6E)
    int manipulador_fdiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 111 (0x6F)
    int manipulador_ddiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 112 (0x70)
    int manipulador_irem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 113 (0x71)
    int manipulador_lrem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 114 (0x72)
    int manipulador_frem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 115 (0x73)
    int manipulador_drem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 116 (0x74)
    int manipulador_ineg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 117 (0x75)
    int manipulador_lneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 118 (0x76)
    int manipulador_fneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 119 (0x77)
    int manipulador_dneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 120 (0x78)
    int manipulador_ishl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 121 (0x79)
    int manipulador_lshl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 122 (0x7A)
    int manipulador_ishr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 123 (0x7B)
    int manipulador_lshr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 124 (0x7C)
    int manipulador_iushr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 125 (0x7D)
    int manipulador_lushr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 126 (0x7E)
    int manipulador_iand (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 127 (0x7F)
    int manipulador_land (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 128 (0x80)
    int manipulador_ior (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 129 (0x81)
    int manipulador_lor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 130 (0x82)
    int manipulador_ixor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 131 (0x83)
    int manipulador_lxor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 132 (0x84)
    int manipulador_iinc (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 133 (0x85)
    int manipulador_i2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 134 (0x86)
    int manipulador_i2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 135 (0x87)
    int manipulador_i2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 136 (0x88)
    int manipulador_l2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 137 (0x89)
    int manipulador_l2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 138 (0x8A)
    int manipulador_l2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 139 (0x8B)
    int manipulador_f2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 140 (0x8C)
    int manipulador_f2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 141 (0x8D)
    int manipulador_f2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 142 (0x8E)
    int manipulador_d2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 143 (0x8F)
    int manipulador_d2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 144 (0x90)
    int manipulador_d2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 145 (0x91)
    int manipulador_i2b (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 146 (0x92)
    int manipulador_i2c (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 147 (0x93)
    int manipulador_i2s (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 148 (0x94)
    int manipulador_lcmp (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 149 (0x95)
    int manipulador_fcmpl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 150 (0x96)
    int manipulador_fcmpg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 151 (0x97)
    int manipulador_dcmpl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 152 (0x98)
    int manipulador_dcmpg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 153 (0x99)
    int manipulador_ifeq (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 154 (0x9A)
    int manipulador_ifne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 155 (0x9B)
    int manipulador_iflt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 156 (0x9C)
    int manipulador_ifge (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 157 (0x9D)
    int manipulador_ifgt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 158 (0x9E)
    int manipulador_ifle (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 159 (0x9F)
    int manipulador_if_icmpeq (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 160 (0xA0)
    int manipulador_if_icmpne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 161 (0xA1)
    int manipulador_if_icmplt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 162 (0xA2)
    int manipulador_if_icmpge (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 163 (0xA3)
    int manipulador_if_icmpgt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 164 (0xA4)
    int manipulador_if_icmple (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 165 (0xA5)
    int manipulador_if_acmpeg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 166 (0xA6)
    int manipulador_if_acmpne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 167 (0xA7)
    int manipulador_goto (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 168 (0xA8)
    int manipulador_jsr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 169 (0xA9)
    int manipulador_ret (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 170 (0xAA)
    int manipulador_tableswitch (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 171 (0xAB)
    int manipulador_lookupswitch (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 172 (0xAC)
    int manipulador_ireturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 173 (0xAD)
    int manipulador_lreturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 174 (0xAE)
    int manipulador_freturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 175 (0xAF)
    int manipulador_dreturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 176 (0xB0)
    int manipulador_areturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 177 (0xB1)
    int manipulador_return (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 178 (0xB2)
    int manipulador_getstatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 179 (0xB3)
    int manipulador_putstatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 180 (0xB4)
    int manipulador_getfield (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 181 (0xB5)
    int manipulador_putfield (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 182 (0xB6)
    int manipulador_invokevirtual (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 183 (0xB7)
    int manipulador_invokespecial (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 184 (0xB8)
    int manipulador_invokestatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 185 (0xB9)
    int manipulador_invokeinterface (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 186 (0xBA)
    int manipulador_invokedynamic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 187 (0xBB)
    int manipulador_new (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 188 (0xBC)
    int manipulador_newarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 189 (0xBD)
    int manipulador_anewarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 190 (0xBE)
    int manipulador_arraylength (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 191 (0xBF)
    int manipulador_athrow (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 192 (0xC0)
    int manipulador_checkcast (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 193 (0xC1)
    int manipulador_instanceof (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 194 (0xC2)
    int manipulador_monitorenter (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 195 (0xC3)
    int manipulador_monitorexit (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 196 (0xC4)
    int manipulador_wide (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 197 (0xC5)
    int manipulador_multianewarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 198 (0xC6)
    int manipulador_ifnull (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 199 (0xC7)
    int manipulador_ifnonnull (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 200 (0xC8)
    int manipulador_goto_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);

    // 201 (0xC9)
    int manipulador_jsr_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 202 (0xCA)
    int manipulador_break_point (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 254 (0xFE)
    int manipulador_impdep_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
    // 255 (0xFF)
    int manipulador_impdep_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador);
#endif
