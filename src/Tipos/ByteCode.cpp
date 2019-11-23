#include <iostream>
#include "../../lib/Tipos/ByteCode.hpp"


std::vector<ByteCode> bytecodes;


void iniciar_bytecodes (){
    // 0 (0x00)
    bytecodes.push_back({"nop", 0, FUNC(_nop)});

    // 1 (0x01)
    bytecodes.push_back({"aconst_null", 0, FUNC(_aconst_null)});
    // 2 (0x02)k
    bytecodes.push_back({"iconst_m1", 0, FUNC(_iconst_m1)});
    // 3 (0x03)
    bytecodes.push_back({"iconst_0", 0, FUNC(_iconst_0)});
    // 4 (0x04)
    bytecodes.push_back({"iconst_1", 0, FUNC(_iconst_1)});
    // 5 (0x05)
    bytecodes.push_back({"iconst_2", 0, FUNC(_iconst_2)});

    // 6 (0x06)
    bytecodes.push_back({"iconst_3", 0, FUNC(_iconst_3)});
    // 7 (0x07)
    bytecodes.push_back({"iconst_4", 0, FUNC(_iconst_4)});
    // 8 (0x08)
    bytecodes.push_back({"iconst_5", 0, FUNC(_iconst_5)});
    // 9 (0x09)
    bytecodes.push_back({"lconst_0", 0, FUNC(_lconst_0)});
    // 10 (0x0A)
    bytecodes.push_back({"lconst_1", 0, FUNC(_lconst_1)});

    // 11 (0x0B)
    bytecodes.push_back({"fconst_0", 0, FUNC(_fconst_0)});
    // 12 (0x0C)
    bytecodes.push_back({"fconst_1", 0, FUNC(_fconst_1)});
    // 13 (0x0D)
    bytecodes.push_back({"fconst_2", 0, FUNC(_fconst_2)});
    // 14 (0x0E)
    bytecodes.push_back({"dconst_0", 0, FUNC(_dconst_0)});
    // 15 (0x0F)
    bytecodes.push_back({"dconst_1", 0, FUNC(_dconst_1)});

    // 16 (0x10)
    bytecodes.push_back({"bipush", 1, FUNC(_bipush)});
    // 17 (0x11)
    bytecodes.push_back({"sipush", 2, FUNC(_sipush)});
    // 18 (0x12)
    bytecodes.push_back({"ldc", 1, FUNC(_ldc)});
    // 19 (0x13)
    bytecodes.push_back({"ldc_w", 2, FUNC(_ldc_w)});
    // 20 (0x14)
    bytecodes.push_back({"ldc2_w", 2, FUNC(_ldc2_w)});

    // 21 (0x15)
    bytecodes.push_back({"iload", 1, FUNC(_iload)});
    // 22 (0x16)
    bytecodes.push_back({"lload", 1, FUNC(_lload)});
    // 23 (0x17)
    bytecodes.push_back({"fload", 1, FUNC(_fload)});
    // 24 (0x18)
    bytecodes.push_back({"dload", 1, FUNC(_dload)});
    // 25 (0x19)
    bytecodes.push_back({"aload", 1, FUNC(_aload)});

    // 26 (0x1A)
    bytecodes.push_back({"iload_0", 0, FUNC(_iload_0)});
    // 27 (0x1B)
    bytecodes.push_back({"iload_1", 0, FUNC(_iload_1)});
    // 28 (0x1C)
    bytecodes.push_back({"iload_2", 0, FUNC(_iload_2)});
    // 29 (0x1D)
    bytecodes.push_back({"iload_3", 0, FUNC(_iload_3)});
    // 30 (0x1E)
    bytecodes.push_back({"lload_0", 0, FUNC(_lload_0)});

    // 31 (0x1F)
    bytecodes.push_back({"lload_1", 0, FUNC(_lload_1)});
    // 32 (0x20)
    bytecodes.push_back({"lload_2", 0, FUNC(_lload_2)});
    // 33 (0x21)
    bytecodes.push_back({"lload_3", 0, FUNC(_lload_3)});
    // 34 (0x22)
    bytecodes.push_back({"fload_0", 0, FUNC(_fload_0)});
    // 35 (0x23)
    bytecodes.push_back({"fload_1", 0, FUNC(_fload_1)});

    // 36 (0x24)
    bytecodes.push_back({"fload_2", 0, FUNC(_fload_2)});
    // 37 (0x25)
    bytecodes.push_back({"fload_3", 0, FUNC(_fload_3)});
    // 38 (0x26)
    bytecodes.push_back({"dload_0", 0, FUNC(_dload_0)});
    // 39 (0x27)
    bytecodes.push_back({"dload_1", 0, FUNC(_dload_1)});
    // 40 (0x28)
    bytecodes.push_back({"dload_2", 0, FUNC(_dload_2)});

    // 41 (0x29)
    bytecodes.push_back({"dload_3", 0, FUNC(_dload_3)});
    // 42 (0x2A)
    bytecodes.push_back({"aload_0", 0, FUNC(_aload_0)});
    // 43 (0x2B)
    bytecodes.push_back({"aload_1", 0, FUNC(_aload_1)});
    // 44 (0x2C)
    bytecodes.push_back({"aload_2", 0, FUNC(_aload_2)});
    // 45 (0x2D)
    bytecodes.push_back({"aload_3", 0, FUNC(_aload_3)});

    // 46 (0x2E)
    bytecodes.push_back({"iaload", 0, FUNC(_iaload)});
    // 47 (0x2F)
    bytecodes.push_back({"laload", 0, FUNC(_laload)});
    // 48 (0x30)
    bytecodes.push_back({"faload", 0, FUNC(_faload)});
    // 49 (0x31)
    bytecodes.push_back({"daload", 0, FUNC(_daload)});
    // 50 (0x32)
    bytecodes.push_back({"aaload", 0, FUNC(_aaload)});

    // 51 (0x33)
    bytecodes.push_back({"baload", 0, FUNC(_baload)});
    // 52 (0x34)
    bytecodes.push_back({"caload", 0, FUNC(_caload)});
    // 53 (0x35)
    bytecodes.push_back({"saload", 0, FUNC(_saload)});
    // 54 (0x36)
    bytecodes.push_back({"istore", 1, FUNC(_istore)});
    // 55 (0x37)
    bytecodes.push_back({"lstore", 1, FUNC(_lstore)});

    // 56 (0x38)
    bytecodes.push_back({"fstore", 1, FUNC(_fstore)});
    // 57 (0x39)
    bytecodes.push_back({"dstore", 1, FUNC(_dstore)});
    // 58 (0x3A)
    bytecodes.push_back({"astore", 1, FUNC(_astore)});
    // 59 (0x3B)
    bytecodes.push_back({"istore_0", 0, FUNC(_istore_0)});
    // 60 (0x3C)
    bytecodes.push_back({"istore_1", 0, FUNC(_istore_1)});

    // 61 (0x3D)
    bytecodes.push_back({"istore_2", 0, FUNC(_istore_2)});
    // 62 (0x3E)
    bytecodes.push_back({"istore_3", 0, FUNC(_istore_3)});
    // 63 (0x3F)
    bytecodes.push_back({"lstore_0", 0, FUNC(_lstore_0)});
    // 64 (0x40)
    bytecodes.push_back({"lstore_1", 0, FUNC(_lstore_1)});
    // 65 (0x41)
    bytecodes.push_back({"lstore_2", 0, FUNC(_lstore_2)});

    // 66 (0x42)
    bytecodes.push_back({"lstore_3", 0, FUNC(_lstore_3)});
    // 67 (0x43)
    bytecodes.push_back({"fstore_0", 0, FUNC(_fstore_0)});
    // 68 (0x44)
    bytecodes.push_back({"fstore_1", 0, FUNC(_fstore_1)});
    // 69 (0x45)
    bytecodes.push_back({"fstore_2", 0, FUNC(_fstore_2)});
    // 70 (0x46)
    bytecodes.push_back({"fstore_3", 0, FUNC(_fstore_3)});
    // 71 (0x47)
    bytecodes.push_back({"dstore_0", 0, FUNC(_dstore_0)});
    // 72 (0x48)
    bytecodes.push_back({"dstore_1", 0, FUNC(_dstore_1)});
    // 73 (0x49)
    bytecodes.push_back({"dstore_2", 0, FUNC(_dstore_2)});
    // 74 (0x4A)
    bytecodes.push_back({"dstore_3", 0, FUNC(_dstore_3)});
    // 75 (0x4B)
    bytecodes.push_back({"astore_0", 0, FUNC(_astore_0)});
    // 76 (0x4C)
    bytecodes.push_back({"astore_1", 0, FUNC(_astore_1)});
    // 77 (0x4D)
    bytecodes.push_back({"astore_2", 0, FUNC(_astore_2)});
    // 78 (0x4E)
    bytecodes.push_back({"astore_3", 0, FUNC(_astore_3)});
    // 79 (0x4F)
    bytecodes.push_back({"iastore", 0, FUNC(_iastore)});
    // 80 (0x50)
    bytecodes.push_back({"lastore", 0, FUNC(_lastore)});
    // 81 (0x51)
    bytecodes.push_back({"fastore", 0, FUNC(_fastore)});
    // 82 (0x52)
    bytecodes.push_back({"dastore", 0, FUNC(_dastore)});
    // 83 (0x53)
    bytecodes.push_back({"aastore", 0, FUNC(_aastore)});
    // 84 (0x54)
    bytecodes.push_back({"bastore", 0, FUNC(_bastore)});
    // 85 (0x55)
    bytecodes.push_back({"castore", 0, FUNC(_castore)});
    // 86 (0x56)
    bytecodes.push_back({"sastore", 0, FUNC(_sastore)});
    // 87 (0x57)
    bytecodes.push_back({"pop", 0, FUNC(_pop)});
    // 88 (0x58)
    bytecodes.push_back({"pop2", 0, FUNC(_pop2)});
    // 89 (0x59)
    bytecodes.push_back({"dup", 0, FUNC(_dup)});
    // 90 (0x5A)
    bytecodes.push_back({"dup_x1", 0, FUNC(_dup_x1)});
    // 91 (0x5B)
    bytecodes.push_back({"dup_x2", 0, FUNC(_dup_x2)});
    // 92 (0x5C)
    bytecodes.push_back({"dup2", 0, FUNC(_dup2)});
    // 93 (0x5D)
    bytecodes.push_back({"dup2_x1", 0, FUNC(_dup2_x1)});
    // 94 (0x5E)
    bytecodes.push_back({"dup2_x2", 0, FUNC(_dup2_x2)});
    // 95 (0x5F)
    bytecodes.push_back({"swap", 0, FUNC(_swap)});

    // 96 (0x60)
    bytecodes.push_back({"iadd", 0, FUNC(_iadd)});
    // 97 (0x61)
    bytecodes.push_back({"ladd", 0, FUNC(_ladd)});
    // 98 (0x62)
    bytecodes.push_back({"fadd", 0, FUNC(_fadd)});
    // 99 (0x63)
    bytecodes.push_back({"dadd", 0, FUNC(_dadd)});
    // 100 (0x64)
    bytecodes.push_back({"isub", 0, FUNC(_isub)});
    // 101 (0x65)
    bytecodes.push_back({"lsub", 0, FUNC(_lsub)});
    // 102 (0x66)
    bytecodes.push_back({"fsub", 0, FUNC(_fsub)});
    // 103 (0x67)
    bytecodes.push_back({"dsub", 0, FUNC(_dsub)});
    // 104 (0x68)
    bytecodes.push_back({"imul", 0, FUNC(_imul)});
    // 105 (0x69)
    bytecodes.push_back({"lmul", 0, FUNC(_lmul)});
    // 106 (0x6A)
    bytecodes.push_back({"fmul", 0, FUNC(_fmul)});
    // 107 (0x6B)
    bytecodes.push_back({"dmul", 0, FUNC(_dmul)});
    // 108 (0x6C)
    bytecodes.push_back({"idiv", 0, FUNC(_idiv)});
    // 109 (0x6D)
    bytecodes.push_back({"ldiv", 0, FUNC(_ldiv)});
    // 110 (0x6E)
    bytecodes.push_back({"fdiv", 0, FUNC(_fdiv)});
    // 111 (0x6F)
    bytecodes.push_back({"ddiv", 0, FUNC(_ddiv)});
    // 112 (0x70)
    bytecodes.push_back({"irem", 0, FUNC(_irem)});
    // 113 (0x71)
    bytecodes.push_back({"lrem", 0, FUNC(_lrem)});
    // 114 (0x72)
    bytecodes.push_back({"frem", 0, FUNC(_frem)});
    // 115 (0x73)
    bytecodes.push_back({"drem", 0, FUNC(_drem)});
    // 116 (0x74)
    bytecodes.push_back({"ineg", 0, FUNC(_ineg)});
    // 117 (0x75)
    bytecodes.push_back({"lneg", 0, FUNC(_lneg)});
    // 118 (0x76)
    bytecodes.push_back({"fneg", 0, FUNC(_fneg)});
    // 119 (0x77)
    bytecodes.push_back({"dneg", 0, FUNC(_dneg)});
    // 120 (0x78)
    bytecodes.push_back({"ishl", 0, FUNC(_ishl)});

    // 121 (0x79)
    bytecodes.push_back({"lshl", 0, FUNC(_lshl)});
    // 122 (0x7A)
    bytecodes.push_back({"ishr", 0, FUNC(_ishr)});
    // 123 (0x7B)
    bytecodes.push_back({"lshr", 0, FUNC(_lshr)});
    // 124 (0x7C)
    bytecodes.push_back({"iushr", 0, FUNC(_iushr)});
    // 125 (0x7D)
    bytecodes.push_back({"lushr", 0, FUNC(_lushr)});

    // 126 (0x7E)
    bytecodes.push_back({"iand", 0, FUNC(_iand)});
    // 127 (0x7F)
    bytecodes.push_back({"land", 0, FUNC(_land)});
    // 128 (0x80)
    bytecodes.push_back({"ior", 0, FUNC(_ior)});
    // 129 (0x81)
    bytecodes.push_back({"lor", 0, FUNC(_lor)});
    // 130 (0x82)
    bytecodes.push_back({"ixor", 0, FUNC(_ixor)});

    // 131 (0x83)
    bytecodes.push_back({"lxor", 0, FUNC(_lxor)});
    // 132 (0x84)
    bytecodes.push_back({"iinc", 2, FUNC(_iinc)});
    // 133 (0x85)
    bytecodes.push_back({"i2l", 0, FUNC(_i2l)});
    // 134 (0x86)
    bytecodes.push_back({"i2f", 0, FUNC(_i2f)});
    // 135 (0x87)
    bytecodes.push_back({"i2d", 0, FUNC(_i2d)});

    // 136 (0x88)
    bytecodes.push_back({"l2i", 0, FUNC(_l2i)});
    // 137 (0x89)
    bytecodes.push_back({"l2f", 0, FUNC(_l2f)});
    // 138 (0x8A)
    bytecodes.push_back({"l2d", 0, FUNC(_l2d)});
    // 139 (0x8B)
    bytecodes.push_back({"f2i", 0, FUNC(_f2i)});
    // 140 (0x8C)
    bytecodes.push_back({"f2l", 0, FUNC(_f2l)});

    // 141 (0x8D)
    bytecodes.push_back({"f2d", 0, FUNC(_f2d)});
    // 142 (0x8E)
    bytecodes.push_back({"d2i", 0, FUNC(_d2i)});
    // 143 (0x8F)
    bytecodes.push_back({"d2l", 0, FUNC(_d2l)});
    // 144 (0x90)
    bytecodes.push_back({"d2f", 0, FUNC(_d2f)});
    // 145 (0x91)
    bytecodes.push_back({"i2b", 0, FUNC(_i2b)});

    // 146 (0x92)
    bytecodes.push_back({"i2c", 0, FUNC(_i2c)});
    // 147 (0x93)
    bytecodes.push_back({"i2s", 0, FUNC(_i2s)});
    // 148 (0x94)
    bytecodes.push_back({"lcmp", 0, FUNC(_lcmp)});
    // 149 (0x95)
    bytecodes.push_back({"fcmpl", 0, FUNC(_fcmpl)});
    // 150 (0x96)
    bytecodes.push_back({"fcmpg", 0, FUNC(_fcmpg)});

    // 151 (0x97)
    bytecodes.push_back({"dcmpl", 0, FUNC(_dcmpl)});
    // 152 (0x98)
    bytecodes.push_back({"dcmpg", 0, FUNC(_dcmpg)});
    // 153 (0x99)
    bytecodes.push_back({"ifeq", 2, FUNC(_ifeq)});
    // 154 (0x9A)
    bytecodes.push_back({"ifne", 2, FUNC(_ifne)});
    // 155 (0x9B)
    bytecodes.push_back({"iflt", 2, FUNC(_iflt)});

    // 156 (0x9C)
    bytecodes.push_back({"ifge", 2, FUNC(_ifge)});
    // 157 (0x9D)
    bytecodes.push_back({"ifgt", 2, FUNC(_ifgt)});
    // 158 (0x9E)
    bytecodes.push_back({"ifle", 2, FUNC(_ifle)});
    // 159 (0x9F)
    bytecodes.push_back({"if_icmpeq", 2, FUNC(_if_icmpeq)});
    // 160 (0xA0)
    bytecodes.push_back({"if_icmpne", 2, FUNC(_if_icmpne)});

    // 161 (0xA1)
    bytecodes.push_back({"if_icmplt", 2, FUNC(_if_icmplt)});
    // 162 (0xA2)
    bytecodes.push_back({"if_icmpge", 2, FUNC(_if_icmpge)});
    // 163 (0xA3)
    bytecodes.push_back({"if_icmpgt", 2, FUNC(_if_icmpgt)});
    // 164 (0xA4)
    bytecodes.push_back({"if_icmple", 2, FUNC(_if_icmple)});
    // 165 (0xA5)
    bytecodes.push_back({"if_acmpeg", 2, FUNC(_if_acmpeg)});

    // 166 (0xA6)
    bytecodes.push_back({"if_acmpne", 2, FUNC(_if_acmpne)});
    // 167 (0xA7)
    bytecodes.push_back({"goto", 2, FUNC(_goto)});
    // 168 (0xA8)
    bytecodes.push_back({"jsr", 2, FUNC(_jsr)});
    // 169 (0xA9)
    bytecodes.push_back({"ret", 2, FUNC(_ret)});
    // 170 (0xAA)
    bytecodes.push_back({"tableswitch", 34, FUNC(_tableswitch)});

    // 171 (0xAB)
    bytecodes.push_back({"lookupswitch", 26, FUNC(_lookupswitch)});
    // 172 (0xAC)
    bytecodes.push_back({"ireturn", 0, FUNC(_ireturn)});
    // 173 (0xAD)
    bytecodes.push_back({"lreturn", 0, FUNC(_lreturn)});
    // 174 (0xAE)
    bytecodes.push_back({"freturn", 0, FUNC(_freturn)});
    // 175 (0xAF)
    bytecodes.push_back({"dreturn", 0, FUNC(_dreturn)});

    // 176 (0xB0)
    bytecodes.push_back({"areturn", 0, FUNC(_areturn)});
    // 177 (0xB1)
    bytecodes.push_back({"return", 0, FUNC(_return)});
    // 178 (0xB2)
    bytecodes.push_back({"getstatic", 2, FUNC(_getstatic)});
    // 179 (0xB3)
    bytecodes.push_back({"putstatic", 2, FUNC(_putstatic)});
    // 180 (0xB4)
    bytecodes.push_back({"getfield", 2, FUNC(_getfield)});

    // 181 (0xB5)
    bytecodes.push_back({"putfield", 2, FUNC(_putfield)});
    // 182 (0xB6)
    bytecodes.push_back({"invokevirtual", 2, FUNC(_invokevirtual)});
    // 183 (0xB7)
    bytecodes.push_back({"invokespecial", 2, FUNC(_invokespecial)});
    // 184 (0xB8)
    bytecodes.push_back({"invokestatic", 2, FUNC(_invokestatic)});
    // 185 (0xB9)
    bytecodes.push_back({"invokeinterface", 4, FUNC(_invokeinterface)});

    // 186 (0xBA)
    bytecodes.push_back({"invokedynamic", 4, FUNC(_invokedynamic)});
    // 187 (0xBB)
    bytecodes.push_back({"new", 2, FUNC(_new)});
    // 188 (0xBC)
    bytecodes.push_back({"newarray", 1, FUNC(_newarray)});
    // 189 (0xBD)
    bytecodes.push_back({"anewarray", 2, FUNC(_anewarray)});
    // 190 (0xBE)
    bytecodes.push_back({"arraylength", 0, FUNC(_arraylength)});

    // 191 (0xBF)
    bytecodes.push_back({"athrow", 0, FUNC(_athrow)});
    // 192 (0xC0)
    bytecodes.push_back({"checkcast", 2, FUNC(_checkcast)});
    // 193 (0xC1)
    bytecodes.push_back({"instanceof", 2, FUNC(_instanceof)});
    // 194 (0xC2)
    bytecodes.push_back({"monitorenter", 0, FUNC(_monitorenter)});
    // 195 (0xC3)
    bytecodes.push_back({"monitorexit", 0, FUNC(_monitorexit)});

    // 196 (0xC4)
    bytecodes.push_back({"wide", 3, FUNC(_wide)});
    // 197 (0xC5)
    bytecodes.push_back({"multianewarray", 3, FUNC(_multianewarray)});
    // 198 (0xC6)
    bytecodes.push_back({"ifnull", 2, FUNC(_ifnull)});
    // 199 (0xC7)
    bytecodes.push_back({"ifnonnull", 2, FUNC(_ifnonnull)});
    // 200 (0xC8)
    bytecodes.push_back({"goto_w", 4, FUNC(_goto_w)});

    // 201 (0xC9)
    bytecodes.push_back({"jsr_w", 4, FUNC(_jsr_w)});
    // 202 (0xCA)
    bytecodes.push_back({"break_point", 0, FUNC(_break_point)});
    // 203 (0xCB)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 204 (0xCC)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 205 (0xCD)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 206 (0xCE)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 207 (0xCF)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 208 (0xD0)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 209 (0xD1)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 210 (0xD2)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 211 (0xD3)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 212 (0xD4)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 213 (0xD5)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 214 (0xD6)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 215 (0xD7)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 216 (0xD8)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 217 (0xD9)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 218 (0xDA)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 219 (0xDB)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 220 (0xDC)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 221 (0xDD)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 222 (0xDE)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 223 (0xDF)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 224 (0xE0)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 225 (0xE1)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 226 (0xE2)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 227 (0xE3)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 228 (0xE4)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 229 (0xE5)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 230 (0xE6)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 231 (0xE7)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 232 (0xE8)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 233 (0xE9)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 234 (0xEA)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 235 (0xEB)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 236 (0xEC)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 237 (0xED)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 238 (0xEE)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 239 (0xEF)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 240 (0xF0)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 241 (0xF1)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 242 (0xF2)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 243 (0xF3)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 244 (0xF4)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 245 (0xF5)
    bytecodes.push_back({"-", 0, FUNC(_undef)});

    // 246 (0xF6)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 247 (0xF7)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 248 (0xF8)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 249 (0xF9)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 250 (0xFA)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 251 (0xFB)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 252 (0xFC)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 253 (0xFD)
    bytecodes.push_back({"-", 0, FUNC(_undef)});
    // 254 (0xFE)
    bytecodes.push_back({"impdep_1", 0, FUNC(_impdep_1)});
    // 255 (0xFF)
    bytecodes.push_back({"impdep_2", 0, FUNC(_impdep_2)});
}


int manipulador_undef (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 0 (0x00)
int manipulador_nop (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 1 (0x01)
int manipulador_aconst_null (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 2 (0x02)
int manipulador_iconst_m1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 3 (0x03)
int manipulador_iconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 4 (0x04)
int manipulador_iconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 5 (0x05)
int manipulador_iconst_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 6 (0x06)
int manipulador_iconst_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 7 (0x07)
int manipulador_iconst_4 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 8 (0x08)
int manipulador_iconst_5 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 9 (0x09)
int manipulador_lconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 10 (0x0A)
int manipulador_lconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 11 (0x0B)
int manipulador_fconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 12 (0x0C)
int manipulador_fconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 13 (0x0D)
int manipulador_fconst_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 14 (0x0E)
int manipulador_dconst_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 15 (0x0F)
int manipulador_dconst_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 16 (0x10)
int manipulador_bipush (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 17 (0x11)
int manipulador_sipush (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 18 (0x12)
int manipulador_ldc (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 19 (0x13)
int manipulador_ldc_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 20 (0x14)
int manipulador_ldc2_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 21 (0x15)
int manipulador_iload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 22 (0x16)
int manipulador_lload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 23 (0x17)
int manipulador_fload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 24 (0x18)
int manipulador_dload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 25 (0x19)
int manipulador_aload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 26 (0x1A)
int manipulador_iload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 27 (0x1B)
int manipulador_iload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 28 (0x1C)
int manipulador_iload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 29 (0x1D)
int manipulador_iload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 30 (0x1E)
int manipulador_lload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 31 (0x1F)
int manipulador_lload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 32 (0x20)
int manipulador_lload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 33 (0x21)
int manipulador_lload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 34 (0x22)
int manipulador_fload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 35 (0x23)
int manipulador_fload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 36 (0x24)
int manipulador_fload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 37 (0x25)
int manipulador_fload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 38 (0x26)
int manipulador_dload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 39 (0x27)
int manipulador_dload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 40 (0x28)
int manipulador_dload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 41 (0x29)
int manipulador_dload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 42 (0x2A)
int manipulador_aload_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 43 (0x2B)
int manipulador_aload_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 44 (0x2C)
int manipulador_aload_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 45 (0x2D)
int manipulador_aload_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 46 (0x2E)
int manipulador_iaload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 47 (0x2F)
int manipulador_laload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 48 (0x30)
int manipulador_faload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 49 (0x31)
int manipulador_daload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 50 (0x32)
int manipulador_aaload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 51 (0x33)
int manipulador_baload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 52 (0x34)
int manipulador_caload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 53 (0x35)
int manipulador_saload (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 54 (0x36)
int manipulador_istore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 55 (0x37)
int manipulador_lstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 56 (0x38)
int manipulador_fstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 57 (0x39)
int manipulador_dstore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 58 (0x3A)
int manipulador_astore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 59 (0x3B)
int manipulador_istore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 60 (0x3C)
int manipulador_istore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 61 (0x3D)
int manipulador_istore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 62 (0x3E)
int manipulador_istore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 63 (0x3F)
int manipulador_lstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 64 (0x40)
int manipulador_lstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 65 (0x41)
int manipulador_lstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 66 (0x42)
int manipulador_lstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 67 (0x43)
int manipulador_fstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 68 (0x44)
int manipulador_fstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 69 (0x45)
int manipulador_fstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 70 (0x46)
int manipulador_fstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 71 (0x47)
int manipulador_dstore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 72 (0x48)
int manipulador_dstore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 73 (0x49)
int manipulador_dstore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 74 (0x4A)
int manipulador_dstore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 75 (0x4B)
int manipulador_astore_0 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 76 (0x4C)
int manipulador_astore_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 77 (0x4D)
int manipulador_astore_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 78 (0x4E)
int manipulador_astore_3 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 79 (0x4F)
int manipulador_iastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 80 (0x50)
int manipulador_lastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 81 (0x51)
int manipulador_fastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 82 (0x52)
int manipulador_dastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 83 (0x53)
int manipulador_aastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 84 (0x54)
int manipulador_bastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 85 (0x55)
int manipulador_castore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 86 (0x56)
int manipulador_sastore (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 87 (0x57)
int manipulador_pop (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 88 (0x58)
int manipulador_pop2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 89 (0x59)
int manipulador_dup (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 90 (0x5A)
int manipulador_dup_x1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 91 (0x5B)
int manipulador_dup_x2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 92 (0x5C)
int manipulador_dup2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 93 (0x5D)
int manipulador_dup2_x1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 94 (0x5E)
int manipulador_dup2_x2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 95 (0x5F)
int manipulador_swap (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 96 (0x60)
int manipulador_iadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 97 (0x61)
int manipulador_ladd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 98 (0x62)
int manipulador_fadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 99 (0x63)
int manipulador_dadd (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 100 (0x64)
int manipulador_isub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 101 (0x65)
int manipulador_lsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 102 (0x66)
int manipulador_fsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 103 (0x67)
int manipulador_dsub (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 104 (0x68)
int manipulador_imul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 105 (0x69)
int manipulador_lmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 106 (0x6A)
int manipulador_fmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 107 (0x6B)
int manipulador_dmul (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 108 (0x6C)
int manipulador_idiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 109 (0x6D)
int manipulador_ldiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 110 (0x6E)
int manipulador_fdiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 111 (0x6F)
int manipulador_ddiv (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 112 (0x70)
int manipulador_irem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 113 (0x71)
int manipulador_lrem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 114 (0x72)
int manipulador_frem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 115 (0x73)
int manipulador_drem (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 116 (0x74)
int manipulador_ineg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 117 (0x75)
int manipulador_lneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 118 (0x76)
int manipulador_fneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 119 (0x77)
int manipulador_dneg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 120 (0x78)
int manipulador_ishl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 121 (0x79)
int manipulador_lshl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 122 (0x7A)
int manipulador_ishr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 123 (0x7B)
int manipulador_lshr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 124 (0x7C)
int manipulador_iushr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 125 (0x7D)
int manipulador_lushr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 126 (0x7E)
int manipulador_iand (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 127 (0x7F)
int manipulador_land (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 128 (0x80)
int manipulador_ior (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 129 (0x81)
int manipulador_lor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 130 (0x82)
int manipulador_ixor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 131 (0x83)
int manipulador_lxor (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 132 (0x84)
int manipulador_iinc (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 133 (0x85)
int manipulador_i2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 134 (0x86)
int manipulador_i2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 135 (0x87)
int manipulador_i2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 136 (0x88)
int manipulador_l2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 137 (0x89)
int manipulador_l2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 138 (0x8A)
int manipulador_l2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 139 (0x8B)
int manipulador_f2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 140 (0x8C)
int manipulador_f2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 141 (0x8D)
int manipulador_f2d (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 142 (0x8E)
int manipulador_d2i (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 143 (0x8F)
int manipulador_d2l (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 144 (0x90)
int manipulador_d2f (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 145 (0x91)
int manipulador_i2b (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 146 (0x92)
int manipulador_i2c (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 147 (0x93)
int manipulador_i2s (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 148 (0x94)
int manipulador_lcmp (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 149 (0x95)
int manipulador_fcmpl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 150 (0x96)
int manipulador_fcmpg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 151 (0x97)
int manipulador_dcmpl (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 152 (0x98)
int manipulador_dcmpg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 153 (0x99)
int manipulador_ifeq (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 154 (0x9A)
int manipulador_ifne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 155 (0x9B)
int manipulador_iflt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 156 (0x9C)
int manipulador_ifge (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 157 (0x9D)
int manipulador_ifgt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 158 (0x9E)
int manipulador_ifle (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 159 (0x9F)
int manipulador_if_icmpeq (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 160 (0xA0)
int manipulador_if_icmpne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 161 (0xA1)
int manipulador_if_icmplt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 162 (0xA2)
int manipulador_if_icmpge (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 163 (0xA3)
int manipulador_if_icmpgt (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 164 (0xA4)
int manipulador_if_icmple (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 165 (0xA5)
int manipulador_if_acmpeg (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 166 (0xA6)
int manipulador_if_acmpne (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 167 (0xA7)
int manipulador_goto (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 168 (0xA8)
int manipulador_jsr (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 169 (0xA9)
int manipulador_ret (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 170 (0xAA)
int manipulador_tableswitch (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 3 + 4 + 4 + 4;
}

// 171 (0xAB)
int manipulador_lookupswitch (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 3 + 4 + 4;
}

// 172 (0xAC)
int manipulador_ireturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 173 (0xAD)
int manipulador_lreturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 174 (0xAE)
int manipulador_freturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 175 (0xAF)
int manipulador_dreturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 176 (0xB0)
int manipulador_areturn (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 177 (0xB1)
int manipulador_return (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 178 (0xB2)
int manipulador_getstatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 179 (0xB3)
int manipulador_putstatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 180 (0xB4)
int manipulador_getfield (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 181 (0xB5)
int manipulador_putfield (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 182 (0xB6)
int manipulador_invokevirtual (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 183 (0xB7)
int manipulador_invokespecial (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 184 (0xB8)
int manipulador_invokestatic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}
// rever-
// 185 (0xB9)
int manipulador_invokeinterface (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 4;
}
// add
// 186 (0xBA)
int manipulador_invokedynamic (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 4;
}

// 187 (0xBB)
int manipulador_new (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 188 (0xBC)
int manipulador_newarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 1;
}

// 189 (0xBD)
int manipulador_anewarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 190 (0xBE)
int manipulador_arraylength (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 191 (0xBF)
int manipulador_athrow (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 192 (0xC0)
int manipulador_checkcast (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 193 (0xC1)
int manipulador_instanceof (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 194 (0xC2)
int manipulador_monitorenter (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 195 (0xC3)
int manipulador_monitorexit (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 196 (0xC4)
int manipulador_wide (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 3;
}

// 197 (0xC5)
int manipulador_multianewarray (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 3;
}

// 198 (0xC6)
int manipulador_ifnull (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 199 (0xC7)
int manipulador_ifnonnull (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 2;
}

// 200 (0xC8)
int manipulador_goto_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 4;
}

// 201 (0xC9)
int manipulador_jsr_w (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 4;
}

// 202 (0xCA)
int manipulador_break_point (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 254 (0xFE)
int manipulador_impdep_1 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}

// 255 (0xFF)
int manipulador_impdep_2 (const std::vector<u1> codigo, const u2 c_pos, const u1 e_interpretador){
    return 0;
}
