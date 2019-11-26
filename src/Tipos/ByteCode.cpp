#include <iostream>
#include "../../lib/Tabelas/TabSimbolos.hpp"
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

void manipulador_undef (Frame *frame){
}

// 0 (0x00)
void manipulador_nop (Frame *frame){
    frame->pc++;
}

// 1 (0x01)
void manipulador_aconst_null (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_VAZ;
    frame->pilha_operandos.push(op);
    frame->pc++;

}

// 2 (0x02)
void manipulador_iconst_m1 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = -1;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 3 (0x03)
void manipulador_iconst_0 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 0;
    frame->pilha_operandos.push(op);
    frame->pc++;

}

// 4 (0x04)
void manipulador_iconst_1 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 1;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 5 (0x05)
void manipulador_iconst_2 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 2;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 6 (0x06)
void manipulador_iconst_3 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 3;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 7 (0x07)
void manipulador_iconst_4 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 4;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 8 (0x08)
void manipulador_iconst_5 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = 5;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 9 (0x09)
void manipulador_lconst_0 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_LNG;
    op->tipo_long = 0;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 10 (0x0A)
void manipulador_lconst_1 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_LNG;
    op->tipo_long = 1;
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 11 (0x0B)
void manipulador_fconst_0 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 0.0;
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 12 (0x0C)
void manipulador_fconst_1 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 1.0;
    frame->pilha_operandos.push(op);
    frame->pc++;   
}

// 13 (0x0D)
void manipulador_fconst_2 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 2.0;
    frame->pilha_operandos.push(op);
    frame->pc++;   
}

// 14 (0x0E)
void manipulador_dconst_0 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_DBL;
    op->tipo_double = 0.0;
    frame->pilha_operandos.push(op);
    frame->pc++;   
}

// 15 (0x0F)
void manipulador_dconst_1 (Frame *frame){
    Operando* op = new Operando();
    op->tag = TAG_DBL;
    op->tipo_double = 1.0;
    frame->pilha_operandos.push(op);
    frame->pc++;   
}

// 16 (0x10)
void manipulador_bipush (Frame *frame){
    frame->pc++;
    Operando* op = new Operando();
    u1 byte = frame->attr_codigo->codigo[frame->pc++];
    op->tag = TAG_INT;
    op->tipo_int = (u1)byte;
    
    frame->pilha_operandos.push(op);
}

// 17 (0x11)
void manipulador_sipush (Frame *frame){
    Operando* op = new Operando();

    u1 byte1 = frame->attr_codigo->codigo[frame->pc++];
    u1 byte2 = frame->attr_codigo->codigo[frame->pc++];

    op->tag = TAG_INT;
    op->tipo_int = (byte1 << 8) | byte2;
    
    frame->pilha_operandos.push(op);
}

// 18 (0x12)
void manipulador_ldc (Frame *frame){
    frame->pc++;
    Operando* op = new Operando();
    u1 indice = frame->attr_codigo->codigo[frame->pc++];

    InterCPDado *ts =  dynamic_cast<TabSimbolos*>(frame->tab_simbolos)->registros[indice - 1];
    op->tag = ts->tag;

    switch(op->tag) {
        case TAG_STR: {
            op->tipo_string = (dynamic_cast<TabSimbolos*>(ts->tab_simbolos))->get_string(dynamic_cast<InfoString*>(ts)->ind_string);
            break;
        }
        case TAG_FLT: {
            op->tipo_float = dynamic_cast<InfoFloat*>(ts)->bytes;
            break;
        }
        case TAG_INT: {
            op->tipo_int = dynamic_cast<InfoInteiro*>(ts)->bytes;
            break;
        }
    }

    frame->pilha_operandos.push(op);
}

// 19 (0x13)
void manipulador_ldc_w (Frame *frame){
    manipulador_nop(frame);
}

// 20 (0x14)
void manipulador_ldc2_w (Frame *frame){
    frame->pc++;

    Operando *op = new Operando();
    u1 indice1 = frame->attr_codigo->codigo[frame->pc++];
    u1 indice2 = frame->attr_codigo->codigo[frame->pc++];

    u1 indice3 = (indice1 << 8) + indice2;

    InterCPDado *ts =  dynamic_cast<TabSimbolos*>(frame->tab_simbolos)->registros[indice3 - 1];
    op->tag = ts->tag;

    switch(op->tag) {
        case TAG_DBL:
            op->tipo_double = ((uint64_t)(dynamic_cast<InfoDouble*>(ts)->bytes_mais) << 32);
            op->tipo_double = op->tipo_double + ((uint64_t)(dynamic_cast<InfoDouble*>(ts)->bytes_menos));
        break;

        default: 
            op->tipo_long = ((uint64_t)(dynamic_cast<InfoLong*>(ts)->bytes_mais) << 32);
            op->tipo_long = op->tipo_long + ((uint64_t)(dynamic_cast<InfoLong*>(ts)->bytes_menos));
    }

    frame->pilha_operandos.push(op);

}

// 21 (0x15)
void manipulador_iload (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->var_locais[(int)indice];

    frame->pilha_operandos.push(op);

}

// 22 (0x16)
void manipulador_lload (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando * op = frame->var_locais[(int)indice];

    frame->pilha_operandos.push(op);

}

// 23 (0x17)
void manipulador_fload (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->var_locais[(int)indice];

    frame->pilha_operandos.push(op);
}

// 24 (0x18)
void manipulador_dload (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->var_locais[(int)indice];

    frame->pilha_operandos.push(op);
}

// 25 (0x19)
void manipulador_aload (Frame *frame){
    manipulador_nop(frame);
}

// 26 (0x1A)
void manipulador_iload_0 (Frame *frame){
    Operando* op = frame->var_locais[0];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 27 (0x1B)
void manipulador_iload_1 (Frame *frame){
    Operando* op = frame->var_locais[1];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 28 (0x1C)
void manipulador_iload_2 (Frame *frame){
    Operando* op = frame->var_locais[2];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 29 (0x1D)
void manipulador_iload_3 (Frame *frame){
    Operando* op = frame->var_locais[3];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 30 (0x1E)
void manipulador_lload_0 (Frame *frame){
    Operando* op = frame->var_locais[0];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 31 (0x1F)
void manipulador_lload_1 (Frame *frame){
    Operando* op = frame->var_locais[1];
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 32 (0x20)
void manipulador_lload_2 (Frame *frame){
    Operando* op = frame->var_locais[2];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 33 (0x21)
void manipulador_lload_3 (Frame *frame){
    Operando* op = frame->var_locais[3];
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 34 (0x22)
void manipulador_fload_0 (Frame *frame){
    Operando* op = frame->var_locais[0];
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 35 (0x23)
void manipulador_fload_1 (Frame *frame){
    Operando* op = frame->var_locais[1];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 36 (0x24)
void manipulador_fload_2 (Frame *frame){
    Operando* op = frame->var_locais[2];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 37 (0x25)
void manipulador_fload_3 (Frame *frame){
    Operando* op = frame->var_locais[3];
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 38 (0x26)
void manipulador_dload_0 (Frame *frame){
    Operando* op = frame->var_locais[0];
    frame->pilha_operandos.push(op);
    frame->pc++;  
}

// 39 (0x27)
void manipulador_dload_1 (Frame *frame){
    Operando* op = frame->var_locais[1];
    frame->pilha_operandos.push(op);
    frame->pc++;  
}

// 40 (0x28)
void manipulador_dload_2 (Frame *frame){
    Operando* op = frame->var_locais[2];
    frame->pilha_operandos.push(op);
    frame->pc++;  
}

// 41 (0x29)
void manipulador_dload_3 (Frame *frame){
    Operando* op = frame->var_locais[3];
    frame->pilha_operandos.push(op);
    frame->pc++;  
}

// 42 (0x2A)
void manipulador_aload_0 (Frame *frame){
    Operando* op = frame->var_locais[0];
    frame->pilha_operandos.push(op);
    frame->pc++;    
}

// 43 (0x2B)
void manipulador_aload_1 (Frame *frame){
    Operando* op = frame->var_locais[1];
    frame->pilha_operandos.push(op);
    frame->pc++;  
}

// 44 (0x2C)
void manipulador_aload_2 (Frame *frame){
    Operando* op = frame->var_locais[2];
    frame->pilha_operandos.push(op);
    frame->pc++;      
}

// 45 (0x2D)
void manipulador_aload_3 (Frame *frame){
    Operando* op = frame->var_locais[3];
    frame->pilha_operandos.push(op);
    frame->pc++;      
}

// 46 (0x2E)
void manipulador_iaload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 47 (0x2F)
void manipulador_laload (Frame *frame){
    manipulador_nop(frame);
}

// 48 (0x30)
void manipulador_faload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 49 (0x31)
void manipulador_daload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 50 (0x32)
void manipulador_aaload (Frame *frame){
    manipulador_nop(frame);
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if(lista == NULL) {
        std::cout << "Excecao Ponteiro Nulo" << std::endl;
    }

    if((int)indice->tipo_int < 0 || indice->tipo_int >= lista->lista_operandos->size()) {
        std::cout << "Excecao indice de array fora dos limites" << std::endl;
    }

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
}

// 51 (0x33)
void manipulador_baload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 52 (0x34)
void manipulador_caload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 53 (0x35)
void manipulador_saload (Frame *frame){
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando * op = lista->lista_operandos->at(indice->tipo_int);

    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 54 (0x36)
void manipulador_istore (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[(int)(indice)] = op;
}

// 55 (0x37)
void manipulador_lstore (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[(int)(indice)] = op;
}

// 56 (0x38)
void manipulador_fstore (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[(int)(indice)] = op;
}

// 57 (0x39)
void manipulador_dstore (Frame *frame){
    frame->pc++;
    u1 indice = frame->attr_codigo->codigo[frame->pc++];
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[(int)(indice)] = op;    
}

// 58 (0x3A)
void manipulador_astore (Frame *frame){
    manipulador_nop(frame);
}

// 59 (0x3B)
void manipulador_istore_0 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[0] = op;    
    frame->pc++;

}

// 60 (0x3C)
void manipulador_istore_1 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[1] = op;    
    frame->pc++;
}

// 61 (0x3D)
void manipulador_istore_2 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[2] = op;    
    frame->pc++;
}

// 62 (0x3E)
void manipulador_istore_3 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[3] = op;    
    frame->pc++;    
}

// 63 (0x3F)
void manipulador_lstore_0 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[0] = op;    
    frame->pc++;        
}

// 64 (0x40)
void manipulador_lstore_1 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[1] = op;    
    frame->pc++;    
}

// 65 (0x41)
void manipulador_lstore_2 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[2] = op;    
    frame->pc++;        
}

// 66 (0x42)
void manipulador_lstore_3 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[3] = op;    
    frame->pc++;        
}

// 67 (0x43)
void manipulador_fstore_0 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[0] = op;    
    frame->pc++;       
}

// 68 (0x44)
void manipulador_fstore_1 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[1] = op;    
    frame->pc++;     
}

// 69 (0x45)
void manipulador_fstore_2 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[2] = op;    
    frame->pc++;     
}

// 70 (0x46)
void manipulador_fstore_3 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[3] = op;    
    frame->pc++;     
}

// 71 (0x47)
void manipulador_dstore_0 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[0] = op;    
    frame->pc++;     
}

// 72 (0x48)
void manipulador_dstore_1 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[1] = op;    
    frame->pc++;  
}

// 73 (0x49)
void manipulador_dstore_2 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[2] = op;    
    frame->pc++;  
}

// 74 (0x4A)
void manipulador_dstore_3 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[3] = op;    
    frame->pc++;  
}

// 75 (0x4B)
void manipulador_astore_0 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[0] = op;    
    frame->pc++;      
}

// 76 (0x4C)
void manipulador_astore_1 (Frame *frame){
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[1] = op;    
    frame->pc++;  
}

// 77 (0x4D)
void manipulador_astore_2 (Frame *frame){
    manipulador_nop(frame);
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[2] = op;    
    frame->pc++;  
}

// 78 (0x4E)
void manipulador_astore_3 (Frame *frame){
    manipulador_nop(frame);
    Operando * op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->var_locais[3] = op;    
    frame->pc++;  
}

// 79 (0x4F)
void manipulador_iastore (Frame *frame){
    Operando * valor = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    lista->lista_operandos->at(indice->tipo_int) = valor;
}

// 80 (0x50)
void manipulador_lastore (Frame *frame){
    manipulador_nop(frame);
}

// 81 (0x51)
void manipulador_fastore (Frame *frame){
    Operando * valor = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando * indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando * lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    memcpy(&lista->lista_operandos->at(indice->tipo_int), &valor->tipo_float, sizeof(uint64_t));
}

// 82 (0x52)
void manipulador_dastore (Frame *frame){
    manipulador_nop(frame);
}

// 83 (0x53)
void manipulador_aastore (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando* indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando* lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    memcpy(&lista->lista_operandos->at(indice->tipo_int), &op, sizeof(uint64_t));
}

// 84 (0x54)
void manipulador_bastore (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    u1 valor_8 = (u1) op->tipo_int;
    Operando* indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    memcpy(&lista->lista_operandos->at(indice->tipo_int), &valor_8, sizeof(u1));
}

// 85 (0x55)
void manipulador_castore (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    u2 valor_16 = (u2) op->tipo_int;
    Operando* indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    memcpy(&lista->lista_operandos->at(indice->tipo_int), &valor_16, sizeof(u2));
}

// 86 (0x56)
void manipulador_sastore (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    short valor_short = (short) op->tipo_int;
    Operando* indice = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* lista = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    memcpy(&lista->lista_operandos->at(indice->tipo_int), &valor_short, sizeof(uint64_t));
}

// 87 (0x57)
void manipulador_pop (Frame *frame){
    frame->pilha_operandos.pop();
}

// 88 (0x58)
void manipulador_pop2 (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if(op->tag != TAG_DBL && op->tag != TAG_LNG) frame->pilha_operandos.pop();
}

// 89 (0x59)
void manipulador_dup (Frame *frame){
    manipulador_nop(frame);
}

// 90 (0x5A)
void manipulador_dup_x1 (Frame *frame){
    manipulador_nop(frame);
}

// 91 (0x5B)
void manipulador_dup_x2 (Frame *frame){
    manipulador_nop(frame);
}

// 92 (0x5C)
void manipulador_dup2 (Frame *frame){
    manipulador_nop(frame);
}

// 93 (0x5D)
void manipulador_dup2_x1 (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_3 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    frame->pilha_operandos.push(op_2);
    frame->pilha_operandos.push(op_1);
    frame->pilha_operandos.push(op_3);
    frame->pilha_operandos.push(op_2);
    frame->pilha_operandos.push(op_1);
}

// 94 (0x5E)
void manipulador_dup2_x2 (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_3 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_4 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    frame->pilha_operandos.push(op_2);
    frame->pilha_operandos.push(op_1);
    frame->pilha_operandos.push(op_4);
    frame->pilha_operandos.push(op_3);
    frame->pilha_operandos.push(op_2);
    frame->pilha_operandos.push(op_1);
    
    frame->pc++;
}

// 95 (0x5F)
void manipulador_swap (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    frame->pilha_operandos.push(op_1);
    frame->pilha_operandos.push(op_2);
    frame->pc++;
}

// 96 (0x60)
void manipulador_iadd (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_long = op_2->tipo_int + op_1->tipo_int;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 97 (0x61)
void manipulador_ladd (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = op_2->tipo_long + op_1->tipo_long;
    frame->pilha_operandos.push(resultado);
    frame->pc++; 
}

// 98 (0x62)
void manipulador_fadd (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_float,sizeof(float));
    std::memcpy(&valor_2,&op_2->tipo_float,sizeof(float));
    valor_1 += valor_2;
    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &valor_1, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 99 (0x63)
void manipulador_dadd (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_double,sizeof(double));
    std::memcpy(&valor_2,&op_2->tipo_double,sizeof(double));
    valor_1 += valor_2;
    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    memcpy(&resultado->tipo_double, &valor_1, sizeof(uint64_t));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 100 (0x64)
void manipulador_isub (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = op_2->tipo_int - op_1->tipo_int;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 101 (0x65)
void manipulador_lsub (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = op_2->tipo_long - op_1->tipo_long;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 102 (0x66)
void manipulador_fsub (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_float,sizeof(float));
    std::memcpy(&valor_2,&op_2->tipo_float,sizeof(float));
    valor_2 -= valor_1;
    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &valor_2, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 103 (0x67)
void manipulador_dsub (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_double,sizeof(double));
    std::memcpy(&valor_2,&op_2->tipo_double,sizeof(double));
    valor_2 -= valor_1;
    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    memcpy(&resultado->tipo_double, &valor_2, sizeof(uint64_t));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 104 (0x68)
void manipulador_imul (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = op_1->tipo_int * op_2->tipo_int;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 105 (0x69)
void manipulador_lmul (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = op_1->tipo_long * op_2->tipo_long;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 106 (0x6A)
void manipulador_fmul (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_float,sizeof(float));
    std::memcpy(&valor_2,&op_2->tipo_float,sizeof(float));
    valor_1 *= valor_2;
    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &valor_1, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 107 (0x6B)
void manipulador_dmul (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_double,sizeof(double));
    std::memcpy(&valor_2,&op_2->tipo_double,sizeof(double));
    valor_1 *= valor_2;
    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    memcpy(&resultado->tipo_double, &valor_1, sizeof(uint64_t));
    frame->pilha_operandos.push(resultado);
    frame->pc++;   
}

// 108 (0x6C)
void manipulador_idiv (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = floor(op_2->tipo_int/op_1->tipo_int);
    frame->pilha_operandos.push(resultado);
    frame->pc++;   
}

// 109 (0x6D)
void manipulador_ldiv (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_int = floor(op_2->tipo_long/op_1->tipo_long);
    frame->pilha_operandos.push(resultado);
    frame->pc++; 
}

// 110 (0x6E)
void manipulador_fdiv (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_float,sizeof(float));
    std::memcpy(&valor_2,&op_2->tipo_float,sizeof(float));
    valor_2 /= valor_1;
    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &valor_2, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 111 (0x6F)
void manipulador_ddiv (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_double,sizeof(double));
    std::memcpy(&valor_2,&op_2->tipo_double,sizeof(double));
    valor_2 /= valor_1;
    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    memcpy(&resultado->tipo_double, &valor_1, sizeof(uint64_t));
    frame->pilha_operandos.push(resultado);
    frame->pc++; 
    
}

// 112 (0x70)
void manipulador_irem (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = op_2->tipo_int % op_1->tipo_int;
    frame->pilha_operandos.push(resultado);
    frame->pc++;  
    
}

// 113 (0x71)
void manipulador_lrem (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_int = op_2->tipo_long % op_1->tipo_long;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 114 (0x72)
void manipulador_frem (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_float,sizeof(float));
    std::memcpy(&valor_2,&op_2->tipo_float,sizeof(float));
    valor_1 = fmod(valor_2, valor_1);
    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &valor_1, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 115 (0x73)
void manipulador_drem (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_1, valor_2;
    std::memcpy(&valor_1,&op_1->tipo_double,sizeof(double));
    std::memcpy(&valor_2,&op_2->tipo_double,sizeof(double));
    valor_1 = fmod(valor_2, valor_1);
    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    memcpy(&resultado->tipo_double, &valor_1, sizeof(uint64_t));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 116 (0x74)
void manipulador_ineg (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = (~op->tipo_int)+1;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 117 (0x75)
void manipulador_lneg (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = (~op->tipo_long)+1;
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 118 (0x76)
void manipulador_fneg (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    Operando* resultado = new Operando();
    resultado->tag = TAG_FLT;
    
    float valor, valor_neg;
    std::memcpy(&valor, &op->tipo_float, sizeof(float));
    
    valor_neg = (~op->tipo_float)+1;
    
    std::memcpy(&resultado->tipo_float, &valor_neg, sizeof(float));
    frame->pilha_operandos.push(resultado);
    frame->pc++;
}

// 119 (0x77)
void manipulador_dneg (Frame *frame){
    frame->pc++;

    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    
    double valor1, valor2;
    std::memcpy(&valor1, &op->tipo_double, sizeof(double));
    valor2 = -valor1;

    Operando* resultado = new Operando();
    resultado->tag = TAG_DBL;
    
    std::memcpy(&resultado->tipo_double, &valor2, sizeof(double));
    
    frame->pilha_operandos.push(resultado);
}

// 120 (0x78)
void manipulador_ishl (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    u4 valor1 = op1->tipo_int;
    u4 valor2 = op2->tipo_int;

    valor2 &= 0x0000003F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor1 << valor2;
    
    frame->pilha_operandos.push(resultado);

    frame->pc++;
}

// 121 (0x79)
void manipulador_lshl (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    uint64_t valor1 = op1->tipo_long;
    uint64_t valor2 = op2->tipo_long;

    valor2 &= 0x0000003F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = valor1 << valor2;

    frame->pilha_operandos.push(resultado);

    frame->pc++;    
}

// 122 (0x7A)
void manipulador_ishr (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    u4 valor1 = op1->tipo_int;
    u4 valor2 = op2->tipo_int;

    valor2 &= 0x0000003F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor1 >> valor2;

    frame->pilha_operandos.push(resultado);

    frame->pc++;        
}

// 123 (0x7B)
void manipulador_lshr (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    uint64_t valor1 = op1->tipo_long;
    uint64_t valor2 = op2->tipo_long;

    valor2 &= 0x0000003F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = valor1 >> valor2;

    frame->pilha_operandos.push(resultado);

    frame->pc++;       
}

// 124 (0x7C)
void manipulador_iushr (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    u4 valor1 = op1->tipo_int;
    u4 valor2 = op2->tipo_int;

    valor2 &= 0x0000001F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor1 >> valor2;

    frame->pilha_operandos.push(resultado);

    frame->pc++;      
}

// 125 (0x7D)
void manipulador_lushr (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    uint64_t valor1 = op1->tipo_long;
    uint64_t valor2 = op2->tipo_long;

    valor2 &= 0x0000003F;

    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = valor1 >> valor2;

    frame->pilha_operandos.push(resultado);

    frame->pc++;      
}

// 126 (0x7E)
void manipulador_iand (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    int resultado = op1->tipo_int & op2->tipo_int;

    std::memcpy(&op1->tipo_int, &resultado, sizeof(int));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;      

}

// 127 (0x7F)
void manipulador_land (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    uint64_t resultado = op1->tipo_long & op2->tipo_long;

    std::memcpy(&op1->tipo_long, &resultado, sizeof(uint64_t));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;        
}

// 128 (0x80)
void manipulador_ior (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    int resultado = op1->tipo_int | op2->tipo_int;

    std::memcpy(&op1->tipo_int, &resultado, sizeof(u4));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;   
}

// 129 (0x81)
void manipulador_lor (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    uint64_t resultado = op1->tipo_long | op2->tipo_long;

    std::memcpy(&op1->tipo_long, &resultado, sizeof(uint64_t));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;       
    
}

// 130 (0x82)
void manipulador_ixor (Frame *frame){

    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    int resultado = op1->tipo_int ^ op2->tipo_int;

    std::memcpy(&op1->tipo_int, &resultado, sizeof(u4));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;      
}

// 131 (0x83)
void manipulador_lxor (Frame *frame){
    
    Operando* op1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();   

    uint64_t resultado = op1->tipo_long ^ op2->tipo_long;

    std::memcpy(&op1->tipo_long, &resultado, sizeof(uint64_t));

    frame->pilha_operandos.push(op1);
    
    frame->pc++;      
}

// 132 (0x84)
void manipulador_iinc (Frame *frame){

    u1 campo = frame->attr_codigo->codigo[frame->pc+1];
    u1 valor = frame->attr_codigo->codigo[frame->pc+2];

    frame->var_locais.at((int)campo)->tipo_int += valor;

    for(int i = 0; i < 3; i++) {
        frame->pc++;
    }
}

// 133 (0x85)
void manipulador_i2l (Frame *frame){
    
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    uint64_t valor_convertido = (uint64_t) op->tipo_int;

    std::memcpy(&op->tipo_long, &valor_convertido, sizeof(uint64_t));

    op->tag = TAG_LNG;
    frame->pilha_operandos.push(op);

    frame->pc++;

}

// 134 (0x86)
void manipulador_i2f (Frame *frame){
    
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    float valor_convertido = (float) op->tipo_int;

    std::memcpy(&op->tipo_float, &valor_convertido, sizeof(u4));

    op->tag = TAG_FLT;
    frame->pilha_operandos.push(op);

    frame->pc++;    
}

// 135 (0x87)
void manipulador_i2d (Frame *frame){
    
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    double valor_convertido = (double) op->tipo_int;

    std::memcpy(&op->tipo_double, &valor_convertido, sizeof(uint64_t));

    op->tag = TAG_DBL;
    frame->pilha_operandos.push(op);

    frame->pc++;      
}

// 136 (0x88)
void manipulador_l2i (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int valor_convertido = (int) op->tipo_long;
    std::memcpy(&op->tipo_int, &valor_convertido, sizeof(u4));
    op->tag = TAG_INT;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 137 (0x89)
void manipulador_l2f (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    float valor_convertido = (float) op->tipo_long;
    std::memcpy(&op->tipo_float, &valor_convertido, sizeof(uint64_t));
    op->tag = TAG_FLT;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 138 (0x8A)
void manipulador_l2d (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    double valor_convertido = (double) op->tipo_long;
    std::memcpy(&op->tipo_double, &valor_convertido, sizeof(uint64_t));
    op->tag = TAG_DBL;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 139 (0x8B)
void manipulador_f2i (Frame *frame){
    float valor_float;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_float, &op->tipo_float, sizeof(float));
    int valor = (int) valor_float;
    std::memcpy(&op->tipo_int, &valor, sizeof(u4));
    op->tag = TAG_INT;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 140 (0x8C)
void manipulador_f2l (Frame *frame){
    float valor_float;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_float, &op->tipo_float, sizeof(float));
    long valor = (long) valor_float;
    std::memcpy(&op->tipo_long, &valor, sizeof(uint64_t));
    op->tag = TAG_LNG;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 141 (0x8D)
void manipulador_f2d (Frame *frame){
    float valor_float;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_float, &op->tipo_float, sizeof(float));
    double valor = (double) valor_float;
    std::memcpy(&op->tipo_double, &valor, sizeof(uint64_t));
    op->tag = TAG_DBL;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 142 (0x8E)
void manipulador_d2i (Frame *frame){
    double valor_double;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_double, &op->tipo_double, sizeof(double));
    int valor = (int) valor_double;
    std::memcpy(&op->tipo_int, &valor, sizeof(u4));
    op->tag = TAG_INT;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 143 (0x8F)
void manipulador_d2l (Frame *frame){
    double valor_double;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_double, &op->tipo_double, sizeof(double));
    long valor = (long) valor_double;
    std::memcpy(&op->tipo_long, &valor, sizeof(uint64_t));
    op->tag = TAG_LNG;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 144 (0x90)
void manipulador_d2f (Frame *frame){
    double valor_double;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    std::memcpy(&valor_double, &op->tipo_double, sizeof(double));
    float valor = (float) valor_double;
    std::memcpy(&op->tipo_float, &valor, sizeof(u4));
    op->tag = TAG_FLT;
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 145 (0x91)
void manipulador_i2b (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    u4 valor = (u4) op->tipo_int;
    std::memcpy(&op->tipo_byte, &valor, sizeof(u4));
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 146 (0x92)
void manipulador_i2c (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    char valor = (char) op->tipo_int;
    std::memcpy(&op->tipo_char, &valor, sizeof(u4));
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 147 (0x93)
void manipulador_i2s (Frame *frame){
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    short valor = (short) op->tipo_int;
    std::memcpy(&op->tipo_short, &valor, sizeof(u4));
    frame->pilha_operandos.push(op);
    frame->pc++;
}

// 148 (0x94)
void manipulador_lcmp (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int resultado = 0;
    if(op_1->tipo_long < op_2->tipo_long)
        resultado = 1;
    else if (op_1->tipo_long > op_2->tipo_long)
        resultado = -1;

    std::memcpy(&op_1->tipo_int, &resultado, sizeof(u4));
    op_1->tag = TAG_INT;
    frame->pilha_operandos.push(op_1);
    frame->pc++;
}

// 149 (0x95)
void manipulador_fcmpl (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int resultado = 0;
    if(std::isnan(op_1->tipo_float) || std::isnan(op_2->tipo_float))
        resultado = 1;
    else if((int)op_1->tipo_float < (int)op_2->tipo_float)
        resultado = 1;
    else if((int)op_1->tipo_float > (int)op_2->tipo_float)
        resultado = -1;

    std::memcpy(&op_1->tipo_int, &resultado, sizeof(u4));
    op_1->tag = TAG_INT;
    frame->pilha_operandos.push(op_1);
    frame->pc++;
}

// 150 (0x96)
void manipulador_fcmpg (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int resultado = 0;
    if(std::isnan(op_1->tipo_float) || std::isnan(op_2->tipo_float))
        resultado = 1;
    else if((float)op_1->tipo_float < (float)op_2->tipo_float)
        resultado = 1;
    else if((float)op_1->tipo_float > (float)op_2->tipo_float)
        resultado = -1;

    std::memcpy(&op_1->tipo_int, &resultado, sizeof(u4));
    op_1->tag = TAG_INT;
    frame->pilha_operandos.push(op_1);
    frame->pc++;
}

// 151 (0x97)
void manipulador_dcmpl (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int resultado = 0;
    if(std::isnan(op_1->tipo_double) || std::isnan(op_2->tipo_double))
        resultado = 1;
    else if((long)op_1->tipo_double < (long)op_2->tipo_double)
        resultado = 1;
    else if((long)op_1->tipo_double > (long)op_2->tipo_double)
        resultado = -1;

    std::memcpy(&op_1->tipo_int, &resultado, sizeof(u4));
    op_1->tag = TAG_INT;
    frame->pilha_operandos.push(op_1);
    frame->pc++;
}

// 152 (0x98)
void manipulador_dcmpg (Frame *frame){
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    int resultado = 0;
    if(std::isnan(op_1->tipo_double) || std::isnan(op_2->tipo_double))
        resultado = 1;
    else if((double)op_1->tipo_double < (double)op_2->tipo_double)
        resultado = 1;
    else if((double)op_1->tipo_double > (double)op_2->tipo_double)
        resultado = -1;

    std::memcpy(&op_1->tipo_int, &resultado, sizeof(u4));
    op_1->tag = TAG_INT;
    frame->pilha_operandos.push(op_1);
    frame->pc++;
}

// 153 (0x99)
void manipulador_ifeq (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int == 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 154 (0x9A)
void manipulador_ifne (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int != 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 155 (0x9B)
void manipulador_iflt (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int < 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 156 (0x9C)
void manipulador_ifge (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int >= 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 157 (0x9D)
void manipulador_ifgt (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int > 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 158 (0x9E)
void manipulador_ifle (Frame *frame){
    u4 deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op->tipo_int <= 0) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 159 (0x9F)
void manipulador_if_icmpeq (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int == (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 160 (0xA0)
void manipulador_if_icmpne (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int != (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 161 (0xA1)
void manipulador_if_icmplt (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int < (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 162 (0xA2)
void manipulador_if_icmpge (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int >= (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 163 (0xA3)
void manipulador_if_icmpgt (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int > (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 164 (0xA4)
void manipulador_if_icmple (Frame *frame){
    int16_t deslocamento;
    Operando* op_1 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();
    Operando* op_2 = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if((int)op_2->tipo_int <= (int)op_1->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc+1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    } else {
        deslocamento = 3;
    }
    frame->pc+=deslocamento;
}

// 165 (0xA5)
void manipulador_if_acmpeg (Frame *frame){
    manipulador_nop(frame);
}

// 166 (0xA6)
void manipulador_if_acmpne (Frame *frame){
    manipulador_nop(frame);
}

// 167 (0xA7)
void manipulador_goto (Frame *frame){
    int16_t byte_1 = frame->attr_codigo->codigo[frame->pc+1];
    int16_t byte_2 = frame->attr_codigo->codigo[frame->pc+2];
    int16_t deslocamento = (byte_1 << 8) | byte_2;
    frame->pc+=deslocamento;
}

// 168 (0xA8)
void manipulador_jsr (Frame *frame){
    Operando* op = new Operando();
    op->tipo_byte = frame->pc;
    frame->pilha_operandos.push(op);
    int16_t byte_1 = frame->attr_codigo->codigo[frame->pc+1];
    int16_t byte_2 = frame->attr_codigo->codigo[frame->pc+2];
    int16_t deslocamento = (byte_1 << 8) | byte_2;
    frame->pc+=deslocamento;
}

// 169 (0xA9)
void manipulador_ret (Frame *frame){
    manipulador_nop(frame);
}

// 170 (0xAA)
void manipulador_tableswitch (Frame *frame){
    manipulador_nop(frame);
}

// 171 (0xAB)
void manipulador_lookupswitch (Frame *frame){
    manipulador_nop(frame);
}

// 172 (0xAC)
void manipulador_ireturn (Frame *frame){
    manipulador_nop(frame);
}

// 173 (0xAD)
void manipulador_lreturn (Frame *frame){
    manipulador_nop(frame);
}

// 174 (0xAE)
void manipulador_freturn (Frame *frame){
    manipulador_nop(frame);
}

// 175 (0xAF)
void manipulador_dreturn (Frame *frame){
    manipulador_nop(frame);
}

// 176 (0xB0)
void manipulador_areturn (Frame *frame){
    manipulador_nop(frame);
}

// 177 (0xB1)
void manipulador_return (Frame *frame){
    manipulador_nop(frame);
}

// 178 (0xB2)
void manipulador_getstatic (Frame *frame){
    manipulador_nop(frame);
}

// 179 (0xB3)
void manipulador_putstatic (Frame *frame){
    manipulador_nop(frame);
}

// 180 (0xB4)
void manipulador_getfield (Frame *frame){
    manipulador_nop(frame);
}

// 181 (0xB5)
void manipulador_putfield (Frame *frame){
    manipulador_nop(frame);
}

// 182 (0xB6)
void manipulador_invokevirtual (Frame *frame){
    manipulador_nop(frame);
}

// 183 (0xB7)
void manipulador_invokespecial (Frame *frame){
    manipulador_nop(frame);
}

// 184 (0xB8)
void manipulador_invokestatic (Frame *frame){
    manipulador_nop(frame);
}
// rever-
// 185 (0xB9)
void manipulador_invokeinterface (Frame *frame){
    manipulador_nop(frame);
}
// add
// 186 (0xBA)
void manipulador_invokedynamic (Frame *frame){
    manipulador_nop(frame);
}

// 187 (0xBB)
void manipulador_new (Frame *frame){
    manipulador_nop(frame);
}

// 188 (0xBC)
void manipulador_newarray (Frame *frame){
    manipulador_nop(frame);
}

// 189 (0xBD)
void manipulador_anewarray (Frame *frame){
    manipulador_nop(frame);
}

// 190 (0xBE)
void manipulador_arraylength (Frame *frame){
    manipulador_nop(frame);
    // checar o tipo pra array
}

// 191 (0xBF)
void manipulador_athrow (Frame *frame){
    manipulador_nop(frame);
}

// 192 (0xC0)
void manipulador_checkcast (Frame *frame){
    manipulador_nop(frame);
}

// 193 (0xC1)
void manipulador_instanceof (Frame *frame){
    manipulador_nop(frame);
}

// 194 (0xC2)
void manipulador_monitorenter (Frame *frame){
    manipulador_nop(frame);
}

// 195 (0xC3)
void manipulador_monitorexit (Frame *frame){
    manipulador_nop(frame);
}

// 196 (0xC4)
void manipulador_wide (Frame *frame){
    manipulador_nop(frame);
}

// 197 (0xC5)
void manipulador_multianewarray (Frame *frame){
    manipulador_nop(frame);
}

// 198 (0xC6)
void manipulador_ifnull (Frame *frame){
    int deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if(!op->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc + 1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    }
    else 
        deslocamento = 3;
    
    frame->pc += deslocamento;
}

// 199 (0xC7)
void manipulador_ifnonnull (Frame *frame){
    int deslocamento;
    Operando* op = frame->pilha_operandos.top();
    frame->pilha_operandos.pop();

    if(op->tipo_int) {
        deslocamento = frame->attr_codigo->codigo[frame->pc + 1];
        deslocamento = (deslocamento << 8) | frame->attr_codigo->codigo[frame->pc + 2];
    }
    else 
        deslocamento = 3;
    
    frame->pc += deslocamento;
}

// 200 (0xC8)
void manipulador_goto_w (Frame *frame){
    u4 byte_1 = frame->attr_codigo->codigo[frame->pc + 1];
    u4 byte_2 = frame->attr_codigo->codigo[frame->pc + 2];
    u4 byte_3 = frame->attr_codigo->codigo[frame->pc + 3];
    u4 byte_4 = frame->attr_codigo->codigo[frame->pc + 4];

    u4 deslocamento = (byte_1 << 24) | (byte_2 << 16) | (byte_3 << 8) | byte_4;
    frame->pc += deslocamento;
}


// 201 (0xC9)
void manipulador_jsr_w (Frame *frame){
    Operando* op = new Operando();
    op->tipo_byte = frame->pc;
    frame->pilha_operandos.push(op);
    u4 byte_1 = frame->attr_codigo->codigo[frame->pc + 1];
    u4 byte_2 = frame->attr_codigo->codigo[frame->pc + 2];
    u4 byte_3 = frame->attr_codigo->codigo[frame->pc + 3];
    u4 byte_4 = frame->attr_codigo->codigo[frame->pc + 4];

    u4 deslocamento = (byte_1 << 24) | (byte_2 << 16) | (byte_3 << 8) | byte_4;
    frame->pc += deslocamento;
}

// 202 (0xCA)
void manipulador_break_point (Frame *frame){
    manipulador_nop(frame);
}

// 254 (0xFE)
void manipulador_impdep_1 (Frame *frame){
    manipulador_nop(frame);
}

// 255 (0xFF)
void manipulador_impdep_2 (Frame *frame){
    manipulador_nop(frame);
}