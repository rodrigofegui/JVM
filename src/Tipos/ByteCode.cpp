#include <iostream>
#include "../../lib/Tipos/ByteCode.hpp"
#include "../../lib/Tabelas/TabSimbolos.hpp"
#include "../../lib/Tipos/CPDados.hpp"
#include "../../lib/Uteis/Arquivos.hpp"

std::vector<ByteCode> bytecodes;

/**
 *  Mapeamento bytecode mnemônico <-> manipulador
 */
void iniciar_bytecodes (){
    // 0 (0x00)
    bytecodes.push_back({"nop", 0, FUNC(_nop)});
    // 1 (0x01)
    bytecodes.push_back({"aconst_null", 0, FUNC(_aconst_null)});
    // 2 (0x02)
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
    bytecodes.push_back({"if_acmpeq", 2, FUNC(_if_acmpeq)});
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


/**
 *  Classes de manipuladores
 */
void manipulador_undef (Frame *frame){
}

void manipulador_iconst (Frame *frame, int valor){
    Operando *op = new Operando();
    op->tag = TAG_INT;
    op->tipo_int = valor;

    frame->empilhar(op);
    frame->pc++;
}

void manipulador_xstorex_n (Frame *frame, int ind, u1 tag){
    Operando *op = frame->desempilhar();

    if ((op->tag != tag) && (op->tag != TAG_BYTE)){
        std::cout << "Não foi possível armazenar: o operando é do tipo errado" << std::endl;
        std::cout << "\t" << get_tag(op->tag) << " não é " << get_tag(tag) << std::endl;
        return;
    }

    op->atualizar_tipo(tag);

    exibir_se_verboso("\tVar[" + std::to_string((int)ind) + "]: " + op->get());

    frame->var_locais[ind] = op;
    frame->pc++;
}

void manipulador_xstore_n (Frame *frame, u1 ind, u1 tag){
    manipulador_xstorex_n(frame, ind, tag);
}

void manipulador_xstore2_n (Frame *frame, u2 ind, u1 tag){
    manipulador_xstorex_n(frame, ind, tag);
}

void manipulador_xstore (Frame *frame, u1 tag){
    u1 indice = frame->get_prox_byte();

    manipulador_xstore_n (frame, indice, tag);
}

void manipulador_xastore (Frame *frame, u1 tag){
    Operando *valor = frame->desempilhar();
    Operando *indice = frame->desempilhar();
    Operando *lista = frame->desempilhar();

    int ind = (int) indice->tipo_int;

    if (!lista) {
        std::cout << "Exceção Ponteiro Nulo" << std::endl;
        return;
    }

    if ((ind < 0) || (ind >= lista->lista_operandos->size())) {
        std::cout << "Exceção indice de array fora dos limites" << std::endl;
        return;
    }

    if ((valor->tag != tag) && (valor->tag != TAG_BYTE)){
        std::cout << "Não foi possível armazenar no array: o operando não é do tipo correto" << std::endl;
        return;
    }

    // VERIFICAR: QUAL A MELHOR ABORDAGEM?
    // memcpy(&lista->lista_operandos->at(indice->tipo_int), &valor->tipo_float, sizeof(u8));

    valor->atualizar_tipo(tag);
    lista->lista_operandos->at(ind) = valor;
    frame->pc++;
}

void manipulador_xloadx_n (Frame *frame, int ind, u1 tag){
    if (!frame->var_locais[ind]){
        std::cout << "Não existe var local" << std::endl;
    }

    exibir_se_verboso("\tA empilhar a Var[" + std::to_string(ind)
        + "]: " + frame->var_locais[ind]->get());

    Operando *op = frame->var_locais[ind];

    if ((op->tag != tag) && (op->tag != TAG_BYTE)){
        std::cout << "Não foi possível armazenar: o operando é do tipo errado" << std::endl;
        std::cout << "\t" << get_tag(op->tag) << " não é " << get_tag(tag) << std::endl;
        return;
    }

    op->atualizar_tipo(tag);

    frame->empilhar(op->duplicar());
    frame->pc++;
}

void manipulador_xload_n (Frame *frame, u1 ind, u1 tag){
    manipulador_xloadx_n (frame, (int) ind, tag);
}

void manipulador_xload2_n (Frame *frame, u2 ind, u1 tag){
    manipulador_xloadx_n (frame, (int) ind, tag);
}

void manipulador_xaload (Frame *frame, u1 tag){
    Operando *indice = frame->desempilhar();
    Operando *lista = frame->desempilhar();

    int ind = (int) indice->tipo_int;

    if (!lista) {
        std::cout << "Exceção Ponteiro Nulo" << std::endl;
        return;
    }

    if (lista->tag != TAG_ARR){
        std::cout << "Um " << get_tag(lista->tag) << " não é um " << get_tag(TAG_ARR) << std::endl;
        return;
    }

    if(ind < 0 || ind >= lista->lista_operandos->size()) {
        std::cout << "Exceção indice de array fora dos limites" << std::endl;
        return;
    }

    Operando *a_empilhar = lista->lista_operandos->at(ind);

    if ((a_empilhar->tag != tag) && (a_empilhar->tag != TAG_BYTE)){
        std::cout << "Não foi possível carregar: o operando é do tipo errado," << std::endl;
        std::cout << "\tdeveria ser " << get_tag(tag) << std::endl;
        return;
    }

    a_empilhar->atualizar_tipo(tag);    frame->empilhar(a_empilhar);
    frame->pc++;
}

void manipulador_xreturn (Frame *frame, u1 tag){
    if (tag != TAG_VAZ){
        Operando *op = frame->desempilhar();

        if (to_tag(frame->get_tipo_retorno()[0]) != tag){
            std::cout << "O operando deveria ser do tipo " << get_tag(tag);
            std::cout << " mas é " << get_tag(op->tag) << std::endl;

            return;
        }

        exibir_se_verboso("\tRetornando: " + op->get() + " do tipo " + get_tag(tag));
        frame->retorno = op;

    } else {
        exibir_se_verboso("\tRetorno vazio");
    }

    frame->pode_desempilhar = true;
    frame->pc++;
}

void manipulador_iincx (Frame *frame, int ind, int valor){
    exibir_se_verboso("\tA somar " + std::to_string(valor)
        + " a Var[" + std::to_string(ind) + "]: " + frame->var_locais.at(ind)->get());

    if (frame->var_locais.at(ind)->tag != TAG_INT){
        std::cout << "Não é possível somar a um não inteiro, é ";
        std::cout << get_tag(frame->var_locais.at(ind)->tag) << std::endl;
        return;
    }

    frame->var_locais.at(ind)->tipo_int += valor;

    exibir_se_verboso("\tVar[" + std::to_string(ind) + "]: "
        + frame->var_locais.at(ind)->get());

    frame->pc++;
}

int16_t get_deslocamento (Frame *frame){
    int16_t deslocamento = frame->get_prox_byte();
    deslocamento = (deslocamento << 8) | frame->get_prox_byte();
    deslocamento -= 2;

    return deslocamento;
}


/**
 *  Manipuladores dos bytecodes
 */


// 0 (0x00)
 /**
 * @brief Função de operação da instrução nop
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Não executa nenhuma instrução.
 */
void manipulador_nop (Frame *frame){
    frame->pc++;
}

// 1 (0x01)
 /**
 * @brief Função de operação da instrução aconst_null
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a referência nula de objeto no topo da pilha de operandos.
 */
void manipulador_aconst_null (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_VAZ;

    frame->empilhar(op);
    frame->pc++;
}

// 2 (0x02)
/**
 * @brief Função de operação da instrução iconst_m1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira -1 no topo da pilha de operandos.
 */
void manipulador_iconst_m1 (Frame *frame){
    manipulador_iconst(frame, -1);
}

// 3 (0x03)
/**
 * @brief Função de operação da instrução iconst_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 0 no topo da pilha de operandos.
 */
void manipulador_iconst_0 (Frame *frame){
    manipulador_iconst(frame, 0);
}

// 4 (0x04)
/**
 * @brief Função de operação da instrução iconst_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 1 no topo da pilha de operandos.
 */
void manipulador_iconst_1 (Frame *frame){
    manipulador_iconst(frame, 1);
}

// 5 (0x05)
/**
 * @brief Função de operação da instrução iconst_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 2 no topo da pilha de operandos.
 */
void manipulador_iconst_2 (Frame *frame){
    manipulador_iconst(frame, 2);
}

// 6 (0x06)
/**
 * @brief Função de operação da instrução iconst_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 3 no topo da pilha de operandos.
 */
void manipulador_iconst_3 (Frame *frame){
    manipulador_iconst(frame, 3);
}

// 7 (0x07)
/**
 * @brief Função de operação da instrução iconst_4
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 4 no topo da pilha de operandos.
 */
void manipulador_iconst_4 (Frame *frame){
    manipulador_iconst(frame, 4);
}

// 8 (0x08)
/**
 * @brief Função de operação da instrução iconst_5
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo inteira 5 no topo da pilha de operandos.
 */
void manipulador_iconst_5 (Frame *frame){
    manipulador_iconst(frame, 5);
}

// 9 (0x09)
/**
 * @brief Função de operação da instrução lconst_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo longo 0 no topo da pilha de operandos.
 */
void manipulador_lconst_0 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_LNG;
    op->tipo_long = 0;

    frame->empilhar(op);
    frame->pc++;
}

// 10 (0x0A)
/**
 * @brief Função de operação da instrução lconst_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo longo 1 no topo da pilha de operandos.
 */
void manipulador_lconst_1 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_LNG;
    op->tipo_long = 1;

    frame->empilhar(op);
    frame->pc++;
}

// 11 (0x0B)
/**
 * @brief Função de operação da instrução fconst_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo flutuante 0.0 no topo da pilha de operandos.
 */
void manipulador_fconst_0 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 0.0;

    frame->empilhar(op);
    frame->pc++;
}

// 12 (0x0C)
/**
 * @brief Função de operação da instrução fconst_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo flutuante 1.0 no topo da pilha de operandos.
 */
void manipulador_fconst_1 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 1.0;

    frame->empilhar(op);
    frame->pc++;
}

// 13 (0x0D)
/**
 * @brief Função de operação da instrução fconst_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo flutuante 2.0 no topo da pilha de operandos.
 */
void manipulador_fconst_2 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_FLT;
    op->tipo_float = 2.0;

    frame->empilhar(op);
    frame->pc++;
}

// 14 (0x0E)
/**
 * @brief Função de operação da instrução dconst_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo double 0.0 no topo da pilha de operandos.
 */
void manipulador_dconst_0 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_DBL;
    op->tipo_double = 0.0;

    frame->empilhar(op);
    frame->pc++;
}

// 15 (0x0F)
/**
 * @brief Função de operação da instrução dconst_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Coloca a constante tipo double 1.0 no topo da pilha de operandos.
 */
void manipulador_dconst_1 (Frame *frame){
    Operando *op = new Operando();
    op->tag = TAG_DBL;
    op->tipo_double = 1.0;

    frame->empilhar(op);
    frame->pc++;
}

// 16 (0x10)
/**
 * @brief Função de operação da instrução bipush
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Extende o sinal do byte imediato para um valor do tipo inteiro.
 */
void manipulador_bipush (Frame *frame){
    u1 byte = frame->get_prox_byte();

    Operando *op = new Operando();
    op->tag = TAG_BYTE;
    op->tipo_byte = byte;

    frame->empilhar(op);
    frame->pc++;
}

// 17 (0x11)
/**
 * @brief Função de operação da instrução sipush
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Os valores dos bytes imediatos byte1 e byte2 são colocados em um intermediário de tipo short, onde o valor do short é (byte1 << 8) | byte2. O tipo do valor do intermediário é, então, extendido para um valor do tipo inteiro. Esse valor é colocado no topo da pilha de operandos.
 */
void manipulador_sipush (Frame *frame){
    u1 byte1 = frame->get_prox_byte();
    u1 byte2 = frame->get_prox_byte();

    Operando *op = new Operando();
    op->tag = TAG_BYTE;
    op->tipo_byte = (byte1 << 8) | byte2;

    frame->empilhar(op);
    frame->pc++;
}

// 18 (0x12)
/**
 * @brief Função de operação da instrução ldc
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice é um byte sem sinal que precisa ser um índice valido para a pool de constantes em tempo de execução da classe atual. O acesso à pool de constantes em tempo de execução no índice deve ser uma constante em tempo de execução do tipo inteiro, flutuante, referência para um literal de uma string ou referência simbólica para uma classe, tipo de método ou handle de método.
 * Se o acesso em tempo de execução à pool de constante for do tipo inteiro ou flutuante, o valor numérico dessa constante em tempo de execução é colocado no topo da pilha de operandos como inteiro ou flutuante, respectivamente.
 * Caso contrário, se a pool de constante em tempo de execução é uma referência para uma instância da classe String, representando um literal de uma string, então uma referência para essa instância, op, é colocado no topo da pilha de operandos.
 * Caso contrário, se a pool de constante em tempo de execução é uma referência para uma classe, então a classe nomeada é resolvida, e uma referência para o Class object representando essa classe, op, é colocado no topo da pilha de operandos.
 * Caso contrário, a pool de constante em tempo de execução deve ser uma referência simbólica para um tipo ou handle de método. O tipo de método ou handle, é resolvido, e uma referência para a instância resultante de java.lang.invoke.MethodType ou java.lang.invoke.MethodHandle, po, é colocado no topo da pilha de operandos.
 */
void manipulador_ldc (Frame *frame){
    u1 indice = frame->get_prox_byte();

    InterCPDado *c_dados =  frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_STR) && (c_dados->tag != TAG_FLT) && (c_dados->tag != TAG_INT)){
        std::cout << "Não foi possível armazenar: símbolo não é do tipo correto" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_STR) << ", ";
        std::cout << get_tag(TAG_FLT) << " ou " << get_tag(TAG_INT) << std::endl;
        return;
    }

    Operando *op = new Operando();
    op->tag = c_dados->tag;

    switch (op->tag) {
        case TAG_STR:
            op->tipo_string = (dynamic_cast<InfoString*>(c_dados))->get();
            break;
        case TAG_FLT:
            op->tipo_float = std::stof((dynamic_cast<InfoFloat*>(c_dados))->get());
            break;
        case TAG_INT:
            op->tipo_int = std::stoi((dynamic_cast<InfoInteiro*>(c_dados))->get());
            break;
    }

    frame->empilhar(op);
    frame->pc++;
}

// 19 (0x13)
/**
 * @brief Função de operação da instrução ldc_w
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Os bytes sem sinal, byte1 e byte2 são montados em um índice sem sinal de 16-bits em uma pool de constante em tempo de execução da classe atual, onde o valor do índice é calculado como (byte1 << 8) | byte2. O acesso à pool de constantes em tempo de execução no índice deve ser válido e deve ser uma constante em tempo de execução do tipo inteiro, flutuante, referência para um literal de string ou uma referência simbólica para uma classe, tipo de método ou handle de método.
 * Se o acesso em tempo de execução à pool de constante for do tipo inteiro ou flutuante, o valor numérico dessa constante em tempo de execução é colocado no topo da pilha de operandos como inteiro ou flutuante, respectivamente.
 * Caso contrário, se a pool de constante em tempo de execução é uma referência para uma instância da classe String, representando um literal de uma string, então uma referência para essa instância, op, é colocado no topo da pilha de operandos.
 * Caso contrário, se a pool de constante em tempo de execução é uma referência para uma classe, então a classe nomeada é resolvida, e uma referência para o Class object representando essa classe, op, é colocado no topo da pilha de operandos.
 * Caso contrário, a pool de constante em tempo de execução deve ser uma referência simbólica para um tipo ou handle de método. O tipo de método ou handle, é resolvido, e uma referência para a instância resultante de java.lang.invoke.MethodType ou java.lang.invoke.MethodHandle, po, é colocado no topo da pilha de operandos.
 */
void manipulador_ldc_w (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados =  frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_STR) && (c_dados->tag != TAG_FLT) && (c_dados->tag != TAG_INT)){
        std::cout << "Não foi possível armazenar: símbolo não é do tipo correto" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_STR) << ", ";
        std::cout << get_tag(TAG_FLT) << " ou " << get_tag(TAG_INT) << std::endl;
        return;
    }

    Operando *op = new Operando();
    op->tag = c_dados->tag;

    switch (op->tag) {
        case TAG_STR:
            op->tipo_string = (dynamic_cast<InfoString*>(c_dados))->get();
            break;
        case TAG_FLT:
            op->tipo_float = std::stof((dynamic_cast<InfoFloat*>(c_dados))->get());
            break;
        case TAG_INT:
            op->tipo_int = std::stoi((dynamic_cast<InfoInteiro*>(c_dados))->get());
            break;
    }

    frame->empilhar(op);
    frame->pc++;
}

// 20 (0x14)
/**
 * @brief Função de operação da instrução ldc2_w
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Os bytes sem sinal, byte1 e byte2 são montados em um índice sem sinal de 16-bits em uma pool de constante em tempo de execução da classe atual, onde o valor do índice é calculado como (byte1 << 8) | byte2. O acesso à pool de constantes em tempo de execução no índice deve ser válido e deve ser uma constante em tempo de execução do tipo longo ou double, o valor numérico dessa constante em tempo de execução é colocado no topo da pilha de operandos como flutuante ou double, respectivamente.
 */
void manipulador_ldc2_w (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_DBL) && (c_dados->tag != TAG_LNG)){
        std::cout << "Não foi possível armazenar: símbolo não é do tipo correto" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_DBL);
        std::cout << " ou " << get_tag(TAG_LNG) << std::endl;
        return;
    }

    Operando *op = new Operando();
    op->tag = c_dados->tag;

    switch(op->tag) {
        case TAG_DBL:
            op->tipo_double = std::stod((dynamic_cast<InfoDouble*>(c_dados))->get());
            break;

        default:
            op->tipo_long = std::stol((dynamic_cast<InfoLong*>(c_dados))->get());
    }

    frame->empilhar(op);
    frame->pc++;
}

// 21 (0x15)
/**
 * @brief Função de operação da instrução iload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (passsado para manipulador_xload_n como o próximo byte do frame) é um byte sem sinal que deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um inteiro. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_iload (Frame *frame){
    manipulador_xload_n(frame, frame->get_prox_byte(), TAG_INT);
}

// 22 (0x16)
/**
 * @brief Função de operação da instrução lload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (passsado para manipulador_xload_n como o próximo byte do frame) é um byte sem sinal. Tanto o índice quanto o índice+1 devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo longo. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_lload (Frame *frame){
    manipulador_xload_n(frame, frame->get_prox_byte(), TAG_LNG);
}

// 23 (0x17)
/**
 * @brief Função de operação da instrução fload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (passsado para manipulador_xload_n como o próximo byte do frame) é um byte sem sinal que deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo flutuante. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_fload (Frame *frame){
    manipulador_xload_n(frame, frame->get_prox_byte(), TAG_FLT);
}

// 24 (0x18)
/**
 * @brief Função de operação da instrução dload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (passsado para manipulador_xload_n como o próximo byte do frame) quanto o índice+1 devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo double. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_dload (Frame *frame){
    manipulador_xload_n(frame, frame->get_prox_byte(), TAG_DBL);
}

// 25 (0x19)
/**
 * @brief Função de operação da instrução aload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (passsado para manipulador_xload_n como o próximo byte do frame) é um byte sem sinal que deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter uma referência. O objectref na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_aload (Frame *frame){
    manipulador_xload_n(frame, frame->get_prox_byte(), TAG_ARR);
}

// 26 (0x1A)
/**
 * @brief Função de operação da instrução iload_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (0) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um inteiro. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_iload_0 (Frame *frame){
    manipulador_xload_n(frame, 0, TAG_INT);
}

// 27 (0x1B)
/**
 * @brief Função de operação da instrução iload_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (1) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um inteiro. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_iload_1 (Frame *frame){
    manipulador_xload_n(frame, 1, TAG_INT);
}

// 28 (0x1C)
/**
 * @brief Função de operação da instrução iload_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (2) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um inteiro. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_iload_2 (Frame *frame){
    manipulador_xload_n(frame, 2, TAG_INT);
}

// 29 (0x1D)
/**
 * @brief Função de operação da instrução iload_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice (3) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um inteiro. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_iload_3 (Frame *frame){
    manipulador_xload_n(frame, 3, TAG_INT);
}

// 30 (0x1E)
/**
 * @brief Função de operação da instrução lload_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (0) quanto o índice+1 (1) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo longo. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_lload_0 (Frame *frame){
    manipulador_xload_n(frame, 0, TAG_LNG);
}

// 31 (0x1F)
/**
 * @brief Função de operação da instrução lload_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (1) quanto o índice+1 (2) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo longo. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_lload_1 (Frame *frame){
    manipulador_xload_n(frame, 1, TAG_LNG);
}

// 32 (0x20)
/**
 * @brief Função de operação da instrução lload_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (2) quanto o índice+1 (3) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo longo. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_lload_2 (Frame *frame){
    manipulador_xload_n(frame, 2, TAG_LNG);
}

// 33 (0x21)
/**
 * @brief Função de operação da instrução lload_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (3) quanto o índice+1 (4) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo longo. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_lload_3 (Frame *frame){
    manipulador_xload_n(frame, 3, TAG_LNG);
}

// 34 (0x22)
/**
 * @brief Função de operação da instrução fload_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo flutuante. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_fload_0 (Frame *frame){
    manipulador_xload_n(frame, 0, TAG_FLT);
}

// 35 (0x23)
/**
 * @brief Função de operação da instrução fload_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo flutuante. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_fload_1 (Frame *frame){
    manipulador_xload_n(frame, 1, TAG_FLT);
}

// 36 (0x24)
/**
 * @brief Função de operação da instrução fload_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo flutuante. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_fload_2 (Frame *frame){
    manipulador_xload_n(frame, 2, TAG_FLT);
}

// 37 (0x25)
/**
 * @brief Função de operação da instrução fload_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo flutuante. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_fload_3 (Frame *frame){
    manipulador_xload_n(frame, 3, TAG_FLT);
}

// 38 (0x26)
/**
 * @brief Função de operação da instrução dload_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (0) quanto o índice+1 (1) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo double. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_dload_0 (Frame *frame){
    manipulador_xload_n(frame, 0, TAG_DBL);
}

// 39 (0x27)
/**
 * @brief Função de operação da instrução dload_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (1) quanto o índice+1 (2) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo double. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_dload_1 (Frame *frame){
    manipulador_xload_n(frame, 1, TAG_DBL);
}

// 40 (0x28)
/**
 * @brief Função de operação da instrução dload_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (2) quanto o índice+1 (3) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo double. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_dload_2 (Frame *frame){
    manipulador_xload_n(frame, 2, TAG_DBL);
}

// 41 (0x29)
/**
 * @brief Função de operação da instrução dload_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Tanto o índice (3) quanto o índice+1 (4) devem ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter um tipo double. O valor da variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_dload_3 (Frame *frame){
    manipulador_xload_n(frame, 3, TAG_DBL);
}

// 42 (0x2A)
/**
 * @brief Função de operação da instrução aload_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter uma referêmcia. O objectref na variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_aload_0 (Frame *frame){
    manipulador_xload_n(frame, 0, TAG_ARR);
}

// 43 (0x2B)
/**
 * @brief Função de operação da instrução aload_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter uma referêmcia. O objectref na variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_aload_1 (Frame *frame){
    manipulador_xload_n(frame, 1, TAG_ARR);
}

// 44 (0x2C)
/**
 * @brief Função de operação da instrução aload_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter uma referêmcia. O objectref na variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_aload_2 (Frame *frame){
    manipulador_xload_n(frame, 2, TAG_ARR);
}

// 45 (0x2D)
/**
 * @brief Função de operação da instrução aload_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) deve ser um indíce para o vetor de variáveis locais do frame atual. A variável local na posição do índice deve conter uma referêmcia. O objectref na variável local na posição do índice é colocado no topo da pilha de operandos.
 */
void manipulador_aload_3 (Frame *frame){
    manipulador_xload_n(frame, 3, TAG_ARR);
}

// 46 (0x2E)
/**
 * @brief Função de operação da instrução iaload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo inteiro. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O inteiro na posição do índice é encontrado e colocado no topo da pilha de operandos.
 */
void manipulador_iaload (Frame *frame){
    manipulador_xaload(frame, TAG_INT);
}

// 47 (0x2F)
/**
 * @brief Função de operação da instrução laload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo long. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O long na posição do índice é encontrado e colocado no topo da pilha de operandos.
 */
void manipulador_laload (Frame *frame){
    manipulador_xaload(frame, TAG_LNG);
}

// 48 (0x30)
/**
 * @brief Função de operação da instrução faload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo flutuante. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O flutuante na posição do índice é encontrado e colocado no topo da pilha de operandos.
 */
void manipulador_faload (Frame *frame){
    manipulador_xaload(frame, TAG_FLT);
}

// 49 (0x31)
/**
 * @brief Função de operação da instrução daload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo double. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O double na posição do índice é encontrado e colocado no topo da pilha de operandos.
 */
void manipulador_daload (Frame *frame){
    manipulador_xaload(frame, TAG_DBL);
}

// 50 (0x32)
/**
 * @brief 
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo referência. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. A referência na posição do índice é encontrada e colocado no topo da pilha de operandos.
 */
void manipulador_aaload (Frame *frame){
    manipulador_xaload(frame, TAG_REF);
}

// 51 (0x33)
/**
 * @brief Função de operação da instrução baload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo booleano. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O byte na posição do índice é encontrado, extendido para tipo inteiro e colocado no topo da pilha de operandos.
 */
void manipulador_baload (Frame *frame){
    manipulador_xaload(frame, TAG_INT);
}

// 52 (0x34)
/**
 * @brief Função de operação da instrução caload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo char. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O byte na posição do índice é encontrado, extendido com zero para tipo inteiro e colocado no topo da pilha de operandos.
 */
void manipulador_caload (Frame *frame){
    manipulador_xaload(frame, TAG_CHR);
}

// 53 (0x35)
/**
 * @brief Função de operação da instrução saload
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e precisa referenciar um vetor cujos componentes são do tipo short. O índice precisa ser do tipo inteiro. Tanto arrayref quanto o índice são removidos do topo da pilha de operandos. O byte na posição do índice é encontrado, extendido com sinal para tipo inteiro e colocado no topo da pilha de operandos.
 */
void manipulador_saload (Frame *frame){
    manipulador_xaload(frame, TAG_INT);
}

// 54 (0x36)
/**
 * @brief Função de operação da instrução istore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo inteiro. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe o valor do elemento.
 */
void manipulador_istore (Frame *frame){
    manipulador_xstore(frame, TAG_INT);
}

// 55 (0x37)
/**
 * @brief Função de operação da instrução lstore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice é um byte sem sinal. Tanto o índice quanto o índice+1 devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo long. Esse elemento é retirado do topo da pilha, e o valor da variável no índice e no índice+1 recebem o valor do elemento.
 */
void manipulador_lstore (Frame *frame){
    manipulador_xstore(frame, TAG_LNG);
}

// 56 (0x38)
/**
 * @brief Função de operação da instrução fstore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo flutuante. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice recebe valor'.
 */
void manipulador_fstore (Frame *frame){
    manipulador_xstore(frame, TAG_FLT);
}

// 57 (0x39)
/**
 * @brief Função de operação da instrução dstore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice é um byte sem sinal. Tanto o índice quanto o índice+1 devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo double. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice e no índice+1 recebem valor'.
 */
void manipulador_dstore (Frame *frame){
    manipulador_xstore(frame, TAG_DBL);
}

// 58 (0x3A)
/**
 * @brief Função de operação da instrução astore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo returnAddress ou referência. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_astore (Frame *frame){
    manipulador_xstore(frame, TAG_ARR);
}

// 59 (0x3B)
/**
 * @brief Função de operação da instrução istore_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo inteiro. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe o valor do elemento.
 */
void manipulador_istore_0 (Frame *frame){
    manipulador_xstore_n(frame, 0, TAG_INT);
}

// 60 (0x3C)
/**
 * @brief Função de operação da instrução istore_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo inteiro. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe o valor do elemento.
 */
void manipulador_istore_1 (Frame *frame){
    manipulador_xstore_n(frame, 1, TAG_INT);
}

// 61 (0x3D)
/**
 * @brief Função de operação da instrução istore_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo inteiro. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe o valor do elemento.
 */
void manipulador_istore_2 (Frame *frame){
    manipulador_xstore_n(frame, 2, TAG_INT);
}

// 62 (0x3E)
/**
 * @brief Função de operação da instrução istore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo inteiro. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe o valor do elemento.
 */
void manipulador_istore_3 (Frame *frame){
    manipulador_xstore_n(frame, 3, TAG_INT);
}

// 63 (0x3F)
/**
 * @brief Função de operação da instrução lstore_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) é um byte sem sinal. Tanto o índice (0) quanto o índice+1 (1) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo long. Esse elemento é retirado do topo da pilha, e o valor da variável no índice e no índice+1 recebem o valor do elemento.
 */
void manipulador_lstore_0 (Frame *frame){
    manipulador_xstore_n(frame, 0, TAG_LNG);
}

// 64 (0x40)
/**
 * @brief Função de operação da instrução lstore_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) é um byte sem sinal. Tanto o índice (1) quanto o índice+1 (2) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo long. Esse elemento é retirado do topo da pilha, e o valor da variável no índice e no índice+1 recebem o valor do elemento.
 */
void manipulador_lstore_1 (Frame *frame){
    manipulador_xstore_n(frame, 1, TAG_LNG);
}

// 65 (0x41)
/**
 * @brief Função de operação da instrução lstore_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) é um byte sem sinal. Tanto o índice (2) quanto o índice+1 (3) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo long. Esse elemento é retirado do topo da pilha, e o valor da variável no índice e no índice+1 recebem o valor do elemento.
 */
void manipulador_lstore_2 (Frame *frame){
    manipulador_xstore_n(frame, 2, TAG_LNG);
}

// 66 (0x42)
/**
 * @brief Função de operação da instrução lstore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) é um byte sem sinal. Tanto o índice (3) quanto o índice+1 (4) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo long. Esse elemento é retirado do topo da pilha, e o valor da variável no índice e no índice+1 recebem o valor do elemento.
 */
void manipulador_lstore_3 (Frame *frame){
    manipulador_xstore_n(frame, 3, TAG_LNG);
}

// 67 (0x43)
/**
 * @brief Função de operação da instrução fstore_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo flutuante. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice recebe valor'.
 */
void manipulador_fstore_0 (Frame *frame){
    manipulador_xstore_n(frame, 0, TAG_FLT);
}

// 68 (0x44)
/**
 * @brief Função de operação da instrução fstore_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo flutuante. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice recebe valor'.
 */
void manipulador_fstore_1 (Frame *frame){
    manipulador_xstore_n(frame, 1, TAG_FLT);
}

// 69 (0x45)
/**
 * @brief Função de operação da instrução fstore_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo flutuante. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice recebe valor'.
 */
void manipulador_fstore_2 (Frame *frame){
    manipulador_xstore_n(frame, 2, TAG_FLT);
}

// 70 (0x46)
/**
 * @brief Função de operação da instrução fstore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo flutuante. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice recebe valor'.
 */
void manipulador_fstore_3 (Frame *frame){
    manipulador_xstore_n(frame, 3, TAG_FLT);
}

// 71 (0x47)
/**
 * @brief Função de operação da instrução dstore_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) é um byte sem sinal. Tanto o índice (0) quanto o índice+1 (1) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo double. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice e no índice+1 recebem valor'.
 */
void manipulador_dstore_0 (Frame *frame){
    manipulador_xstore_n(frame, 0, TAG_DBL);
}

// 72 (0x48)
/**
 * @brief Função de operação da instrução dstore_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) é um byte sem sinal. Tanto o índice (1) quanto o índice+1 (2) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo double. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice e no índice+1 recebem valor'.
 */
void manipulador_dstore_1 (Frame *frame){
    manipulador_xstore_n(frame, 1, TAG_DBL);
}

// 73 (0x49)
/**
 * @brief Função de operação da instrução dstore_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) é um byte sem sinal. Tanto o índice (2) quanto o índice+1 (3) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo double. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice e no índice+1 recebem valor'.
 */
void manipulador_dstore_2 (Frame *frame){
    manipulador_xstore_n(frame, 2, TAG_DBL);
}

// 74 (0x4A)
/**
 * @brief Função de operação da instrução dstore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) é um byte sem sinal. Tanto o índice (3) quanto o índice+1 (4) devem ser um indíce para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo double. Esse elemento é retirado do topo da pilha e passa por uma conversão resultando em um valor'. O valor da variável no índice e no índice+1 recebem valor'.
 */
void manipulador_dstore_3 (Frame *frame){
    manipulador_xstore_n(frame, 3, TAG_DBL);
}

// 75 (0x4B)
/**
 * @brief Função de operação da instrução astore_0
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (0) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo returnAddress ou referência. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_astore_0 (Frame *frame){
    manipulador_xstore_n(frame, 0, TAG_ARR);
}

// 76 (0x4C)
/**
 * @brief Função de operação da instrução astore_1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (1) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo returnAddress ou referência. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_astore_1 (Frame *frame){
    manipulador_xstore_n(frame, 1, TAG_ARR);
}

// 77 (0x4D)
/**
 * @brief Função de operação da instrução astore_2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (2) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo returnAddress ou referência. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_astore_2 (Frame *frame){
    manipulador_xstore_n(frame, 2, TAG_ARR);
}

// 78 (0x4E)
/**
 * @brief Função de operação da instrução astore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O índice (3) é um byte sem sinal que deve ser um índice para o vetor de variáveis locais do frame atual. O elemento no topo da pilha de operandos deve ser do tipo returnAddress ou referência. Esse elemento é retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_astore_3 (Frame *frame){
    manipulador_xstore_n(frame, 3, TAG_ARR);
}

// 79 (0x4F)
/**
 * @brief Função de operação da instrução astore_3
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo inteiro. Tanto o índice quanto o valor devem ser do tipo inteiro. Arrayref, índice e o retirado do topo da pilha, e o valor da variável no índice recebe objectref.
 */
void manipulador_iastore (Frame *frame){
    manipulador_xastore(frame, TAG_INT);
}

// 80 (0x50)
/**
 * @brief Função de operação da instrução lastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo long. O índice deve ser do tipo inteiro e valor do tipo long. Arrayref, índice e o valor são retirados do topo da pilha de operandos, a da variável no índice recebe valor.
 */
void manipulador_lastore (Frame *frame){
    manipulador_xastore(frame, TAG_LNG);
}

// 81 (0x51)
/**
 * @brief Função de operação da instrução fastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo flutuante. O índice deve ser do tipo inteiro e valor do tipo flutuante. Arrayref, índice e o valor são retirados do topo da pilha de operandos. O valor do tipo flutuante passa por uma conversão, resultando em um valor'. A variável no índice recebe valor'.
 */
void manipulador_fastore (Frame *frame){
    manipulador_xastore(frame, TAG_FLT);
}

// 82 (0x52)
/**
 * @brief Função de operação da instrução dastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo double. O índice deve ser do tipo inteiro e valor do tipo double. Arrayref, índice e o valor são retirados do topo da pilha de operandos. O valor do tipo double passa por uma conversão, resultando em um valor'. A variável no índice recebe valor'.
 */
void manipulador_dastore (Frame *frame){
    manipulador_xastore(frame, TAG_DBL);
}

// 83 (0x53)
/**
 * @brief Função de operação da instrução lastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo referência. O índice deve ser do tipo inteiro e valor do tipo referência. Arrayref, índice e o valor são retirados do topo da pilha de operandos, a da variável no índice recebe valor.
 */
void manipulador_aastore (Frame *frame){
    manipulador_xastore(frame, TAG_REF);
}

// 84 (0x54)
/**
 * @brief Função de operação da instrução bastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo byte ou booleano. O índice e o valor devem ser tipo inteiro. Arrayref, índice e o valor são retirados do topo da pilha de operandos. O valor do tipo inteiro é truncado para um byte e armazenado no vetor na posição índice.
 */
void manipulador_bastore (Frame *frame){
    manipulador_xastore(frame, TAG_INT);
}

// 85 (0x55)
/**
 * @brief Função de operação da instrução castore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo char. O índice e o valor devem ser tipo inteiro. Arrayref, índice e o valor são retirados do topo da pilha de operandos. O valor do tipo inteiro é truncado para um char e armazenado no vetor na posição índice.
 */
void manipulador_castore (Frame *frame){
    manipulador_xastore(frame, TAG_INT);
}

// 86 (0x56)
/**
 * @brief Função de operação da instrução sastore
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O arrayref deve ser do tipo referência e deve referenciar um vetor cujos componentes são do tipo short. O índice e o valor devem ser tipo inteiro. Arrayref, índice e o valor são retirados do topo da pilha de operandos. O valor do tipo inteiro é truncado para um short e armazenado no vetor na posição índice.
 */
void manipulador_sastore (Frame *frame){
    manipulador_xastore(frame, TAG_INT);
}

// 87 (0x57)
/**
 * @brief Função de operação da instrução pop
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Executa um pop no topo da pilha de operandos.
 */
void manipulador_pop (Frame *frame){
    frame->desempilhar();
    frame->pc++;
}

// 88 (0x58)
/**
 * @brief Função de operação da instrução pop
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Executa um ou dois pop no topo da pilha de operandos.
 */
void manipulador_pop2 (Frame *frame){
    Operando *op = frame->desempilhar();

    if ((op->tag != TAG_DBL) && (op->tag != TAG_LNG)){
        frame->desempilhar();
    }

    frame->pc++;
}

// 89 (0x59)
/**
 * @brief Função de operação da instrução dup
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do operando do topo da pilha.
 */
void manipulador_dup (Frame *frame){
    Operando *op = frame->desempilhar();

    frame->empilhar(op);
    frame->empilhar(op);
    frame->pc++;
}

// 90 (0x5A)
/**
 * @brief Função de operação da instrução dup_x1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do operando do topo da pilha e o insere duas posições abaixo.
 */
void manipulador_dup_x1 (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    frame->empilhar(valor_1);
    frame->empilhar(valor_2);
    frame->empilhar(valor_1);

    frame->pc++;
}

// 91 (0x5B)
/**
 * @brief Função de operação da instrução dup_x2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do operando do topo da pilha e o insere duas ou três posições abaixo.
 */
void manipulador_dup_x2 (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    // Valor_1 := CAT_1 & Valor_2 := CAT_2
    if (((valor_1->tag != TAG_DBL) && (valor_1->tag != TAG_LNG))
            && ((valor_2->tag == TAG_DBL) || (valor_2->tag == TAG_LNG))){
        frame->empilhar(valor_1);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);

    // Valor_1 := CAT_1 & Valor_2 := CAT_1
    } else if (((valor_1->tag != TAG_DBL) && (valor_1->tag != TAG_LNG))
            && ((valor_2->tag != TAG_DBL) && (valor_2->tag != TAG_LNG))){
        Operando *valor_3 = frame->desempilhar();

        frame->empilhar(valor_1);
        frame->empilhar(valor_3);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);
    }

    frame->pc++;
}

// 92 (0x5C)
/**
 * @brief Função de operação da instrução dup2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do primeiro ou dos dois primeiros operandos da pilha.
 */
void manipulador_dup2 (Frame *frame){
    Operando *valor_1 = frame->desempilhar();

    // Valor_1 := CAT_2
    if ((valor_1->tag == TAG_DBL) || (valor_1->tag == TAG_LNG)){
        frame->empilhar(valor_1);
        frame->empilhar(valor_1);

    } else {
        Operando *valor_2 = frame->desempilhar();

        frame->empilhar(valor_2);
        frame->empilhar(valor_1);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);
    }

    frame->pc++;
}

// 93 (0x5D)
/**
 * @brief Função de operação da instrução dup2_x1
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do primeiro ou dos dois primeiros operandos da pilha e insere duas ou três posições abaixo.
 */
void manipulador_dup2_x1 (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    // Valor_1 := CAT_2 & Valor_2 := CAT_1
    if (((valor_1->tag == TAG_DBL) || (valor_1->tag == TAG_LNG))
            && ((valor_2->tag != TAG_DBL) && (valor_2->tag != TAG_LNG))){
        frame->empilhar(valor_1);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);

    // Valor_1 := CAT_1 & Valor_2 := CAT_1
    } else if (((valor_1->tag != TAG_DBL) && (valor_1->tag != TAG_LNG))
            && ((valor_2->tag != TAG_DBL) && (valor_2->tag != TAG_LNG))){
        Operando *valor_3 = frame->desempilhar();

        frame->empilhar(valor_2);
        frame->empilhar(valor_1);
        frame->empilhar(valor_3);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);
    }

    frame->pc++;
}

// 94 (0x5E)
/**
 * @brief Função de operação da instrução dup2_x2
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Duplica o valor do primeiro ou dos dois primeiros operandos da pilha e insere duas, três ou quatro posições abaixo.
 */
void manipulador_dup2_x2 (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    // Valor_1 := CAT_2 & Valor_2 := CAT_2
    if (((valor_1->tag == TAG_DBL) || (valor_1->tag == TAG_LNG))
            && ((valor_2->tag == TAG_DBL) || (valor_2->tag == TAG_LNG))){
        frame->empilhar(valor_1);
        frame->empilhar(valor_2);
        frame->empilhar(valor_1);

    } else {
        Operando *valor_3 = frame->desempilhar();

        // Valor_1 := CAT_1 & Valor_2 := CAT_1 & Valor_3 := CAT_2
        if (((valor_1->tag != TAG_DBL) && (valor_1->tag != TAG_LNG))
            && ((valor_2->tag != TAG_DBL) && (valor_2->tag != TAG_LNG))
            && ((valor_3->tag == TAG_DBL) || (valor_3->tag == TAG_LNG))){
            frame->empilhar(valor_2);
            frame->empilhar(valor_1);
            frame->empilhar(valor_3);
            frame->empilhar(valor_2);
            frame->empilhar(valor_1);

        // Valor_1 := CAT_2 & Valor_2 := CAT_1 & Valor_3 := CAT_1
        } else if (((valor_1->tag == TAG_DBL) || (valor_1->tag == TAG_LNG))
            && ((valor_2->tag != TAG_DBL) && (valor_2->tag != TAG_LNG))
            && ((valor_3->tag != TAG_DBL) && (valor_3->tag != TAG_LNG))){
            frame->empilhar(valor_1);
            frame->empilhar(valor_3);
            frame->empilhar(valor_2);
            frame->empilhar(valor_1);

        // Valor_1 := CAT_1 & Valor_2 := CAT_1 & Valor_3 := CAT_1
        } else {
            Operando *valor_4 = frame->desempilhar();

            frame->empilhar(valor_2);
            frame->empilhar(valor_1);
            frame->empilhar(valor_4);
            frame->empilhar(valor_3);
            frame->empilhar(valor_2);
            frame->empilhar(valor_1);
        }
    }

    frame->pc++;
}

// 95 (0x5F)
/**
 * @brief Função de operação da instrução swap
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Troca a posição do primeiro com o segundo operador na pilha.
 */
void manipulador_swap (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    frame->empilhar(valor_1);
    frame->empilhar(valor_2);

    frame->pc++;
}

// 96 (0x60)
/**
 * @brief Função de operação da instrução iadd
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Adiciona um inteiro.
 */
void manipulador_iadd (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int i1 = valor_1->tipo_int,
        i2 = valor_2->tipo_int;

    exibir_se_verboso("\tA somar " + std::to_string(i2) + " e " + std::to_string(i1));

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = i2 + i1;

    frame->empilhar(resultado);
    frame->pc++;
}

// 97 (0x61)
/**
 * @brief Função de operação da instrução ladd
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Adiciona um long.
 */
void manipulador_ladd (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    long l2 = (long) valor_2->tipo_long,
         l1 = (long) valor_1->tipo_long;

    exibir_se_verboso("\tA somar " + std::to_string(l2) + " e " + std::to_string(l1));

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = l2 + l1;

    frame->empilhar(resultado);
    frame->pc++;
}

// 98 (0x62)
/**
 * @brief Função de operação da instrução fadd
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Adiciona um flutuante.
 */
void manipulador_fadd (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    float f1 = valor_1->tipo_float,
          f2 = valor_2->tipo_float;

    exibir_se_verboso("\tA somar " + std::to_string(f1) + " e " + std::to_string(f2));

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;
    resultado->tipo_float = f1 + f2;

    frame->empilhar(resultado);
    frame->pc++;
}

// 99 (0x63)
/**
 * @brief Função de operação da instrução dadd
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Adiciona um double.
 */
void manipulador_dadd (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    double d1 = valor_1->tipo_double,
           d2 = valor_2->tipo_double;

    exibir_se_verboso("\tA somar " + std::to_string(d1) + " e " + std::to_string(d2));

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = d1 + d2;

    frame->empilhar(resultado);
    frame->pc++;
}

// 100 (0x64)
/**
 * @brief Função de operação da instrução isub
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Subtrai um inteiro.
 */
void manipulador_isub (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor_2->tipo_int - valor_1->tipo_int;

    frame->empilhar(resultado);
    frame->pc++;
}

// 101 (0x65)
/**
 * @brief Função de operação da instrução lsub
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Subtrai um long.
 */
void manipulador_lsub (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando* resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = valor_2->tipo_long - valor_1->tipo_long;

    frame->empilhar(resultado);
    frame->pc++;
}

// 102 (0x66)
/**
 * @brief Função de operação da instrução fsub
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Subtrai um flutuante.
 */
void manipulador_fsub (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();
    float fvalor_1, fvalor_2;

    std::memcpy(&fvalor_1,&valor_1->tipo_float,sizeof(float));
    std::memcpy(&fvalor_2,&valor_2->tipo_float,sizeof(float));
    fvalor_2 -= fvalor_1;

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;

    memcpy(&resultado->tipo_float, &fvalor_2, sizeof(float));

    frame->empilhar(resultado);
    frame->pc++;
}

// 103 (0x67)
/**
 * @brief Função de operação da instrução dsub
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Subtrai um double.
 */
void manipulador_dsub (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = valor_1->tipo_double - valor_2->tipo_double;

    frame->empilhar(resultado);
    frame->pc++;
}

// 104 (0x68)
/**
 * @brief Função de operação da instrução imul
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Multiplica um inteiro.
 */
void manipulador_imul (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor_1->tipo_int * valor_2->tipo_int;

    frame->empilhar(resultado);
    frame->pc++;
}

// 105 (0x69)
/**
 * @brief Função de operação da instrução lmul
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Multiplica um long.
 */
void manipulador_lmul (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = valor_1->tipo_long * valor_2->tipo_long;

    frame->empilhar(resultado);
    frame->pc++;
}

// 106 (0x6A)
/**
 * @brief Função de operação da instrução fmul
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Multiplica um flutuante.
 */
void manipulador_fmul (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    float fvalor_1, fvalor_2;
    std::memcpy(&fvalor_1, &valor_1->tipo_float, sizeof(float));
    std::memcpy(&fvalor_2, &valor_2->tipo_float, sizeof(float));
    fvalor_1 *= fvalor_2;

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &fvalor_1, sizeof(float));

    frame->empilhar(resultado);
    frame->pc++;
}

// 107 (0x6B)
/**
 * @brief Função de operação da instrução dmul
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Multiplica um double.
 */
void manipulador_dmul (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = valor_1->tipo_double * valor_2->tipo_double;

    frame->empilhar(resultado);
    frame->pc++;
}

// 108 (0x6C)
/**
 * @brief Função de operação da instrução idiv
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Divide um inteiro.
 */
void manipulador_idiv (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = floor(valor_2->tipo_int / valor_1->tipo_int);

    frame->empilhar(resultado);
    frame->pc++;
}

// 109 (0x6D)
/**
 * @brief Função de operação da instrução ldiv
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Divide um long.
 */
void manipulador_ldiv (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_int = floor(valor_2->tipo_long / valor_1->tipo_long);

    frame->empilhar(resultado);
    frame->pc++;
}

// 110 (0x6E)
/**
 * @brief Função de operação da instrução fdiv
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Divide um flutuante.
 */
void manipulador_fdiv (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    float f1 = valor_1->tipo_float,
          f2 = valor_2->tipo_float;

    exibir_se_verboso("\tA dividir " + std::to_string(f1) + " por " + std::to_string(f2));

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;
    resultado->tipo_float = f1 / f2;

    frame->empilhar(resultado);
    frame->pc++;
}

// 111 (0x6F)
/**
 * @brief Função de operação da instrução ddiv
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Divide um double.
 */
void manipulador_ddiv (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = valor_1->tipo_double / valor_2->tipo_double;

    frame->empilhar(resultado);
    frame->pc++;
}

// 112 (0x70)
/**
 * @brief Função de operação da instrução irem
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. O resultando (inteiro) é valor1 - (valor1 / valor2) * valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_irem (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = valor_2->tipo_int % valor_1->tipo_int;

    frame->empilhar(resultado);
    frame->pc++;
}

// 113 (0x71)
/**
 * @brief Função de operação da instrução lrem
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo long. Os valores são retirados do topo da pilha de operandos. O resultando (long) é valor1 - (valor1 / valor2) * valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_lrem (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_int = valor_2->tipo_long % valor_1->tipo_long;

    frame->empilhar(resultado);
    frame->pc++;
}

// 114 (0x72)
/**
 * @brief Função de operação da instrução frem
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo flutuante. Os valores são retirados do topo da pilha de operandos. O resultando (flutuante) é valor1 - (valor1 / valor2) * valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_frem (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    float fvalor_1, fvalor_2;
    std::memcpy(&fvalor_1,&valor_1->tipo_float,sizeof(float));
    std::memcpy(&fvalor_2,&valor_2->tipo_float,sizeof(float));
    fvalor_1 = fmod(fvalor_2, fvalor_1);

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;
    memcpy(&resultado->tipo_float, &fvalor_1, sizeof(float));

    frame->empilhar(resultado);
    frame->pc++;
}

// 115 (0x73)
/**
 * @brief Função de operação da instrução drem
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo double. Os valores são retirados do topo da pilha de operandos. O resultando (double) é valor1 - (valor1 / valor2) * valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_drem (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = fmod(valor_2->tipo_double, valor_1->tipo_double);

    frame->empilhar(resultado);
    frame->pc++;
}

// 116 (0x74)
/**
 * @brief Função de operação da instrução ineg
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O valor deve ser do tipo inteiro. O valor é retirado do topo da pilha de operandos. O valor é subtraído de zero para obter o negativo. O resultado é colocado no topo da pilha.
 */
void manipulador_ineg (Frame *frame){
    Operando *valor = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = (~valor->tipo_int) + 1;    frame->empilhar(resultado);
    frame->pc++;
}

// 117 (0x75)
/**
 * @brief Função de operação da instrução ineg
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O valor deve ser do tipo long. O valor é retirado do topo da pilha de operandos. O valor é subtraído de zero para obter o negativo. O resultado é colocado no topo da pilha.
 */
void manipulador_lneg (Frame *frame){
    Operando *valor = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = (~valor->tipo_long) + 1;    frame->empilhar(resultado);
    frame->pc++;
}

// 118 (0x76)
/**
 * @brief Função de operação da instrução fneg
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O valor deve ser do tipo flutuante. O valor é retirado do topo da pilha de operandos. O valor é subtraído de zero para obter o negativo. O resultado é colocado no topo da pilha.
 */
void manipulador_fneg (Frame *frame){
    Operando *valor = frame->desempilhar();
    float valor1, valor2;

    std::memcpy(&valor1, &valor->tipo_float, sizeof(float));

    valor2 = -valor1;

    Operando *resultado = new Operando();
    resultado->tag = TAG_FLT;
    std::memcpy(&resultado->tipo_float, &valor2, sizeof(float));    frame->empilhar(resultado);
    frame->pc++;
}

// 119 (0x77)
/**
 * @brief Função de operação da instrução dneg
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * O valor deve ser do tipo double. O valor é retirado do topo da pilha de operandos. O valor é subtraído de zero para obter o negativo. O resultado é colocado no topo da pilha.
 */
void manipulador_dneg (Frame *frame){
    Operando *valor = frame->desempilhar();

    Operando *resultado = new Operando();
    resultado->tag = TAG_DBL;
    resultado->tipo_double = valor->tipo_double * -1;    frame->empilhar(resultado);
    frame->pc++;
}

// 120 (0x78)
/**
 * @brief Função de operação da instrução ishl
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado inteiro é calculado a partir do shift para a esquerda do valor1 em S bits, com extensão de sinal, onde S é o número equivalente aos 5 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_ishl (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u4 ivalor1 = valor_1->tipo_int;
    u4 ivalor2 = valor_2->tipo_int;

    ivalor1 &= 0x0000001F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = ivalor2 << ivalor1;

    frame->empilhar(resultado);
    frame->pc++;
}

// 121 (0x79)
/**
 * @brief Função de operação da instrução lshl
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Valor1 deve ser um long e valor2 deve ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado long é calculado a partir do shift para a esquerda do valor1 em S bits, com extensão de sinal, onde S é o número equivalente aos 6 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_lshl (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 lvalor1 = valor_1->tipo_long;
    u8 lvalor2 = valor_2->tipo_long;

    lvalor1 &= 0x0000003F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = lvalor2 << lvalor1;

    frame->empilhar(resultado);
    frame->pc++;

}

// 122 (0x7A)
/**
 * @brief Função de operação da instrução lshl
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Valor1 deve ser um long e valor2 deve ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado long é calculado a partir do shift para a direita do valor1 em S bits, com extensão de sinal, onde S é o número equivalente aos 6 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_ishr (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u4 ivalor1 = valor_1->tipo_int;
    u4 ivalor2 = valor_2->tipo_int;

    ivalor1 &= 0x0000001F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = ivalor2 >> ivalor1;

    frame->empilhar(resultado);
    frame->pc++;
}

// 123 (0x7B)
/**
 * @brief Função de operação da instrução ishr
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado inteiro é calculado a partir do shift para a direita do valor1 em S bits, com extensão de sinal, onde S é o número equivalente aos 5 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_lshr (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 lvalor1 = valor_1->tipo_long;
    u8 lvalor2 = valor_2->tipo_long;

    lvalor1 &= 0x0000003F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = lvalor2 >> lvalor1;

    frame->empilhar(resultado);
    frame->pc++;
}

// 124 (0x7C)
/**
 * @brief Função de operação da instrução iushr
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Ambos valor1 e valor2 devem ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado inteiro é calculado a partir do shift para a direita do valor1 em S bits, sem sinal, onde S é o número equivalente aos 5 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_iushr (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u4 ivalor1 = valor_1->tipo_int;
    u4 ivalor2 = valor_2->tipo_int;

    ivalor2 &= 0x0000001F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_INT;
    resultado->tipo_int = ivalor1 >> ivalor2;

    frame->empilhar(resultado);
    frame->pc++;
}

// 125 (0x7D)
/**
 * @brief Função de operação da instrução lushr
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 * Valor1 deve ser um long e valor2 deve ser do tipo inteiro. Os valores são retirados do topo da pilha de operandos. Um resultado long é calculado a partir do shift para a direita, de maneira lógica, do valor1 em S bits, sem extensão de sinal, onde S é o número equivalente aos 6 últimos bits do valor2. O resultado é colocado no topo da pilha.
 */
void manipulador_lushr (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 lvalor1 = valor_1->tipo_long;
    u8 lvalor2 = valor_2->tipo_long;

    lvalor2 &= 0x0000003F;

    Operando *resultado = new Operando();
    resultado->tag = TAG_LNG;
    resultado->tipo_long = lvalor1 >> lvalor2;

    frame->empilhar(resultado);
    frame->pc++;
}

// 126 (0x7E)
/**
 * @brief Realiza a operação iand com variáveis de tipo inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 *
 *  O valor1 e o valor2 devem ser do tipo inteiro. Eles são removidos da pilha de operandos. Um resultado inteiro é calculado usando AND (bit a bit) de valor1 e valor2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_iand (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = valor_1->tipo_int & valor_2->tipo_int;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(int));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 127 (0x7F)
/**
 * @brief Realiza a operação and com variáveis de tipo longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Eles são removidos da pilha de operandos. Um resultado longo é calculado usando AND bit a bit de valor1 e valor2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_land (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 resultado = valor_1->tipo_long & valor_2->tipo_long;

    std::memcpy(&valor_1->tipo_long, &resultado, sizeof(u8));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 128 (0x80)
/**
 * @brief Realiza a operação or com variáveis de tipo inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Eles são removidos da pilha de operandos. Um resultado inteiro é calculado usando o OR inclusivo bit a bit de value1 e value2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_ior (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = valor_1->tipo_int | valor_2->tipo_int;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 129 (0x81)
/**
 * @brief Realiza a operação or com variáveis de tipo longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Eles são removidos da pilha de operandos. Um resultado longo é calculado usando o OR inclusivo bit a bit de value1 e value2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_lor (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 resultado = valor_1->tipo_long | valor_2->tipo_long;

    std::memcpy(&valor_1->tipo_long, &resultado, sizeof(u8));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 130 (0x82)
/**
 * @brief Realiza a operação xor com variáveis de tipo inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Eles são removidos da pilha de operandos. Um resultado inteiro é calculado utilizando o OR bit a bit exclusivo de value1 e value2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_ixor (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = valor_1->tipo_int ^ valor_2->tipo_int;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 131 (0x83)
/**
 * @brief Realiza a operação xor com variáveis de tipo longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Eles são removidos da pilha de operandos. Um resultado longo é calculado usando o OR exclusivo bit a bit de value1 e value2. O resultado é enviado para a pilha de operandos.
 */
void manipulador_lxor (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    u8 resultado = valor_1->tipo_long ^ valor_2->tipo_long;

    std::memcpy(&valor_1->tipo_long, &resultado, sizeof(u8));

    frame->empilhar(valor_1);
    frame->pc++;
}

// 132 (0x84)
/**
 * @brief Incrementa a variável local por uma constante
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O índice é um unsigned byte que deve ser um índice no array de variáveis locais do frame atual. O const é um unsigned byte imediato. A variável local no índice deve conter um inteiro. O valor constante é primeiro estendido para um sinal de inteiro e, em seguida, a variável local no índice é incrementada por esse valor.
 */
void manipulador_iinc (Frame *frame){
    u1 indice = frame->get_prox_byte();
    int8_t valor = (int) frame->get_prox_byte();

    manipulador_iincx (frame, indice, valor);
}

/**
 * @brief Converte inteiro para longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos e estendido para um resultado longo. Esse resultado é enviado para a pilha de operandos.
 */
// 133 (0x85)
void manipulador_i2l (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((int) topo->tipo_int) + " para long");

    op->tipo_long = (long) ((int) topo->tipo_int);
    op->tag = TAG_LNG;

    frame->empilhar(op);
    frame->pc++;
}

// 134 (0x86)
/**
 * @brief Converte inteiro para flutuante
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos e convertido no resultado em flutuante usando o IEEE 754 arredondado para o modo mais próximo. O resultado é empilhado na pilha de operandos.
 */
void manipulador_i2f (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((int) topo->tipo_int) + " para float");

    op->tipo_float = (float) ((int) topo->tipo_int);
    op->tag = TAG_FLT;

    frame->empilhar(op);
    frame->pc++;
}

// 135 (0x87)
/**
 * @brief Converte inteiro para double
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos e convertido em um resultado double. O resultado é empilhado na pilha de operandos.
 */
void manipulador_i2d (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((int) topo->tipo_int) + " para double");

    op->tipo_double = (double) ((int) topo->tipo_int);
    op->tag = TAG_DBL;

    frame->empilhar(op);
    frame->pc++;
}

// 136 (0x88)
/**
 * @brief Converte longo para inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo longo. Ele é retirado da pilha de operandos e convertido em um resultado inteiro, retirando os 32 bits de ordem baixa do valor longo e descartando os 32 bits de ordem superior. O resultado é empilhado na pilha de operandos.
 */
void manipulador_l2i (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((long) topo->tipo_long) + " para int");

    op->tipo_int = (int) ((long) topo->tipo_long);
    op->tag = TAG_INT;

    frame->empilhar(op);
    frame->pc++;
}

// 137 (0x89)
/**
 * @brief Converte longo para flutuante
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo longo. Ele é retirado da pilha de operandos e convertido em um resultado flutuante usando o IEEE 754 arredondado para o modo mais próximo. O resultado é empilhado na pilha de operandos.
 */
void manipulador_l2f (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((long) topo->tipo_long) + " para float");

    op->tipo_float = (float) ((long) topo->tipo_long);
    op->tag = TAG_FLT;

    frame->empilhar(op);
    frame->pc++;
}

// 138 (0x8A)
/**
 * @brief Converte longo para double
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo longo. Ele é retirado da pilha de operandos e convertido em um resultado double usando o IEEE 754 arredondado para o modo mais próximo. O resultado é empilhado na pilha de operandos.
 */
void manipulador_l2d (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((long) topo->tipo_long) + " para double");

    op->tipo_double = (double) ((long) topo->tipo_long);
    op->tag = TAG_DBL;

    frame->empilhar(op);
    frame->pc++;
}

// 139 (0x8B)
/**
 * @brief Converte flutuante para inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo longo. Ele é retirado da pilha de operandos e convertido em um resultado double usando o IEEE 754 arredondado para o modo mais próximo. O resultado é empilhado na pilha de operandos.
 */
void manipulador_f2i (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((float) topo->tipo_float) + " para int");

    op->tipo_int = (int) ((float) topo->tipo_float);
    op->tag = TAG_INT;

    frame->empilhar(op);
    frame->pc++;
}

// 140 (0x8C)
/**
 * @brief Converte flutuante para longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo flutuante. Ele é retirado da pilha de operandos e sofre conversão de valores0. Esse valor é convertido em um resultado do tipo inteiro e o resultado é empilhado na pilha de operandos
 * Se esse valor não for numérico, o resultado da conversão será um inteiro 0.
 * Caso contrário, se esse valor não for um infinito, ele será arredondado para um valor inteiro V, arredondando para zero usando IEEE 754 arredondado para o modo zero.
 * Se esse valor inteiro puder ser representado como inteiro, o resultado será o próprio valor.
 * Caso contrário, se esse valor for muito pequeno (um valor negativo de grande magnitude ou infinito negativo) e o resultado é o menor valor representável do tipo inteiro ou o valor deve ser grande (um valor positivo de grade magnitude ou positivo) e o resultado é o maior valor responsável do tipo inteiro
 * 
 */
void manipulador_f2l (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((float) topo->tipo_float) + " para long");

    op->tipo_long = (long) ((float) topo->tipo_float);
    op->tag = TAG_LNG;

    frame->empilhar(op);
    frame->pc++;
}

// 141 (0x8D)
/**
 * @brief Converte flutuante para double
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo flutuante. Ele é retirado da pilha de operandos e sofre conversão de conjunto de valores, resultando em um valor. Então o este valor é convertido em um resultado double. Este resultado empilhado na pilha de operandos.
 * 
 */
void manipulador_f2d (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((float) topo->tipo_float) + " para double");

    op->tipo_double = (double) ((float) topo->tipo_float);
    op->tag = TAG_DBL;

    frame->empilhar(op);
    frame->pc++;
}


// 142 (0x8E)
/**
 * @brief Converte double para inteiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo double. Ele é retirado da pilha de operandos e sofre conversão resultando em um valor. Então o valor é convertido em inteiro e empilhado na pilha de operandos.
 * Se o valor não é não numérico o resultado da conversõa é um inteiro 0.
 * Caso contrário, se o valor não for um infinito, ele será arredondado para um valor inteiro V, arredondando para zero usando IEEE 754 arredondado para o modo zero. Se esse valor inteiro V puder ser representado como um inteiro, o resultado será o valor V. 
 * Caso contrário, o valor deve ser muito pequeno (um valor negativo de grande magnitude ou infinito negativo) e o resultado é o menor valor representável do tipo inteiro ou o valor deve ser muito grande (um valor positivo de grande magnitude ou infinito positivo) e o resultado é o maior valor representável do tipo inteiro.
 * 
 */
void manipulador_d2i (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((double) topo->tipo_double) + " para int");

    op->tipo_int = (int) ((double) topo->tipo_double);
    op->tag = TAG_INT;

    frame->empilhar(op);
    frame->pc++;
}

// 143 (0x8F)
/**
 * @brief Converte double para longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo double. Ele é retirado da pilha de operandos e sofre conversão resultando em um valor. Então o valor é convertido em longo
 * O resultado é empilhado na pilha de operandos. 
 * Se o valor não é não numérico o resultado da conversão é um longo 0.
 * Caso contrário, se o valor não for um infinito, ele será arredondado para um valor inteiro V, arredondando para zero usando IEEE 754 arredondado para o modo zero. Se esse valor inteiro V puder ser representado como um inteiro, o resultado será o valor longo V. 
 * Caso contrário, o valor deve ser muito pequeno (um valor negativo de grande magnitude ou infinito negativo) e o resultado é o menor valor representável do tipo longo ou o valor deve ser muito grande (um valor positivo de grande magnitude ou infinito positivo) e o resultado é o maior valor representável do tipo longo.
 * 
 */
void manipulador_d2l (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((double) topo->tipo_double) + " para long");

    op->tipo_long = (long) ((double) topo->tipo_double);
    op->tag = TAG_LNG;

    frame->empilhar(op);
    frame->pc++;
}

// 144 (0x90)
/**
 * @brief Converte double para flutuante
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo double. Ele é retirado da pilha de operandos e sofre conversão de conjunto de valores, resultando em um valor. Em seguida, este valor é convertido em um resultado em flutuante usando o IEEE 754 arredondado para o modo mais próximo. O resultado é enviado para a pilha de operandos.
 * Onde uma instrução d2f é FP estrita, o resultado da conversão é sempre arredondado para o valor representável mais próximo no valor flutuante definido.
 * Onde uma instrução d2f não é estrita para FP, o resultado da conversão pode ser obtido do valor do expoente flutuante estendido. não é necessário o arredondado para o valor representável mais próximo no conjunto de valores flutuantes.
 * Um valor finito muito pequeno para ser representado como um flutuate é convertido em zero do mesmo sinal. Um valor finito muito grande para ser representado como um flutuante é convertido em um infinito do mesmo sinal. Um NaN duplo é convertido em NaN flutuante.
 */
void manipulador_d2f (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((double) topo->tipo_double) + " para float");

    op->tipo_float = (float) ((double) topo->tipo_double);
    op->tag = TAG_FLT;

    frame->empilhar(op);
    frame->pc++;
}

// 145 (0x91)
/**
 * @brief Converte inteiro para byte
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos, truncado para um byte e depois estendido para um resultado inteiro. Esse resultado é enviado para a pilha de operandos.
 */
void manipulador_i2b (Frame *frame){
    Operando *op = frame->desempilhar();

    int valor = (int8_t) op->tipo_int;

    std::memcpy(&op->tipo_byte, &valor, sizeof(u4));

    frame->empilhar(op);
    frame->pc++;
}

// 146 (0x92)
/**
 * @brief Converte inteiro para character
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor do topo da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos, truncado para char e estendido em zero a um resultado int. Esse resultado é enviado para a pilha de operandos.
 */
void manipulador_i2c (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((int) topo->tipo_int) + " para char");

    char valor_convertido =  (char) topo->tipo_int;

    memcpy(&op->tipo_char,&valor_convertido,sizeof(char));

    op->tag = TAG_CHR;

    frame->empilhar(op);
    frame->pc++;
}

// 147 (0x93)
/**
 * @brief Converte inteiro para short
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor na parte superior da pilha de operandos deve ser do tipo inteiro. Ele é retirado da pilha de operandos, truncado para um short e estendido para um resultado inteiro. Esse resultado é empilhado na pilha de operandos.
 */
void manipulador_i2s (Frame *frame){
    Operando *op = new Operando();
    Operando *topo = frame->desempilhar();

    exibir_se_verboso("\tA converter " + std::to_string((int) topo->tipo_int) + " para short");

    op->tipo_int = (short) ((int) topo->tipo_int);
    op->tag = TAG_INT;

    frame->empilhar(op);
    frame->pc++;
}

// 148 (0x94)
/**
 * @brief Compara dois valores do tipo longo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Ambos são removidos da pilha de operandos e uma comparação de número inteiro sem sinal é executada. Se o valor1 for maior que o valor2, o valor inteiro 1 será empilhado na pilha de operandos. Se o valor1 for igual ao valor2, o valor int 0 será empilhado na pilha de operandos. Se o valor1 for menor que o valor2, o valor inteiro -1 será empurrado para a pilha de operandos.
 * 
 */

void manipulador_lcmp (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = 0;

    if (valor_1->tipo_long < valor_2->tipo_long)
        resultado = 1;

    else if (valor_1->tipo_long > valor_2->tipo_long)
        resultado = -1;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));
    valor_1->tag = TAG_INT;    frame->empilhar(valor_1);
    frame->pc++;
}

// 149 (0x95)
/**
 * @brief Compara dois valores do tipo float
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Ambos são removidos da pilha de operandos e uma comparação de número inteiro sem sinal é executada. Se o valor1 for maior que o valor2, o valor int 1 será empilhado para a pilha de operandos. Se o valor1 for igual ao valor2, o valor int 0 será empilhado na pilha de operandos. Se o valor1 for menor que o valor2, o valor int -1 será empilhado na pilha de operandos.
 * Se o novo valor1 for maior que o novo valor2, o valor inteiro 1 é empilhado na pilha de operandos.
 * Caso contrário, se o novo valor1 for igual ao novo valor2, o valor inteiro 0 será empilhado na pilha de operandos.
 * Caso contrário, se o novo valor1 for menor que o novo valor2, o valor inteiro -1 será empilhado na pilha de operandos.
 * Caso contrário, pelo menos um dos value1 ou value2 novos é NaN. A instrução fcmpl envia o valor int -1 para a pilha de operandos.
 * A comparação de ponto flutuante é realizada de acordo com a IEEE 754. Todos os valores diferentes de NaN são ordenados, com infinito negativo menor que todos os valores finitos e infinito positivo maior que todos os valores finitos. O zero positivo e o zero negativo são considerados iguais.
 * 
 */
void manipulador_fcmpl (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = 0;

    if (std::isnan(valor_1->tipo_float) || std::isnan(valor_2->tipo_float))
        resultado = 1;
    else if ((int)valor_1->tipo_float < (int)valor_2->tipo_float)
        resultado = 1;
    else if ((int)valor_1->tipo_float > (int)valor_2->tipo_float)
        resultado = -1;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));
    valor_1->tag = TAG_INT;    frame->empilhar(valor_1);
    frame->pc++;
}

// 150 (0x96)
/**
 * @brief Compara dois valores do tipo float
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo longo. Ambos são removidos da pilha de operandos e uma comparação de número inteiro sem sinal é executada. Se o valor1 for maior que o valor2, o valor int 1 será empilhado para a pilha de operandos. Se o valor1 for igual ao valor2, o valor int 0 será empilhado na pilha de operandos. Se o valor1 for menor que o valor2, o valor int -1 será empilhado na pilha de operandos.
 * Se o novo valor1 for maior que o novo valor2, o valor inteiro 1 é empilhado na pilha de operandos.
 * Caso contrário, se o novo valor1 for igual ao novo valor2, o valor inteiro 0 será empilhado na pilha de operandos.
 * Caso contrário, se o novo valor1 for menor que o novo valor2, o valor inteiro -1 será empilhado na pilha de operandos.
 * Caso contrário, pelo menos um dos value1 ou value2 novos é NaN. A instrução fcmpg envia o valor inteiro 1 para a pilha de operandos.
 * A comparação de ponto flutuante é realizada de acordo com a IEEE 754. Todos os valores diferentes de NaN são ordenados, com infinito negativo menor que todos os valores finitos e infinito positivo maior que todos os valores finitos. O zero positivo e o zero negativo são considerados iguais.
 * 
 */

void manipulador_fcmpg (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = 0;

    if (std::isnan(valor_1->tipo_float) || std::isnan(valor_2->tipo_float))
        resultado = 1;
    else if ((float)valor_1->tipo_float < (float)valor_2->tipo_float)
        resultado = 1;
    else if ((float)valor_1->tipo_float > (float)valor_2->tipo_float)
        resultado = -1;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));
    valor_1->tag = TAG_INT;    frame->empilhar(valor_1);
    frame->pc++;
}

// 151 (0x97)
/**
 * @brief Compara dois valores do tipo double
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo double. Os valores são removidos da pilha de operandos e passam pela conversão de valores. Uma comparação de ponto flutuante é realizada:
 * Se o novo valor1 for maior que o novo valor2, o valor inteiro 1 é empilhado na pilha de operandos.
 * Caso contrário, se o valor1 for igual ao valor2', o valor inteiro 0 será empilhado na pilha de operandos.
 * Caso contrário, se o valor1 for menor que o valor2, o valor inteiro -1 será empilhado na pilha de operandos.
 * Caso contrário, pelo menos um dos valor1 ou valor2' é NaN. A instrução dcmpg envia o valor int 1 para a pilha de operandos e a instrução dcmpl envia o valor inteiro -1 para a pilha de operandos.
 * A comparação de ponto flutuante é realizada de acordo com a IEEE 754. Todos os valores diferentes de NaN são ordenados, com infinito negativo menor que todos os valores finitos e infinito positivo maior que todos os valores finitos. O zero positivo e o zero negativo são considerados iguais.
 * 
 */
void manipulador_dcmpl (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = 0;

    if (std::isnan(valor_1->tipo_double) || std::isnan(valor_2->tipo_double))
        resultado = 1;
    else if ((long)valor_1->tipo_double < (long)valor_2->tipo_double)
        resultado = 1;
    else if ((long)valor_1->tipo_double > (long)valor_2->tipo_double)
        resultado = -1;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));
    valor_1->tag = TAG_INT;    frame->empilhar(valor_1);
    frame->pc++;
}

// 152 (0x98)
/**
 * @brief Compara dois valores do tipo double
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo double. Os valores são removidos da pilha de operandos e passam pela conversão de valores. Uma comparação de ponto flutuante é realizada:
 * Se o novo valor1 for maior que o novo valor2, o valor inteiro 1 é empilhado na pilha de operandos.
 * Caso contrário, se o valor1 for igual ao valor2', o valor inteiro 0 será empilhado na pilha de operandos.
 * Caso contrário, se o valor1 for menor que o valor2, o valor inteiro -1 será empilhado na pilha de operandos.
 * Caso contrário, pelo menos um dos valor1 ou valor2' é NaN. A instrução dcmpg envia o valor int 1 para a pilha de operandos e a instrução dcmpl envia o valor inteiro -1 para a pilha de operandos.
 * A comparação de ponto flutuante é realizada de acordo com a IEEE 754. Todos os valores diferentes de NaN são ordenados, com infinito negativo menor que todos os valores finitos e infinito positivo maior que todos os valores finitos. O zero positivo e o zero negativo são considerados iguais.
 * 
 */
void manipulador_dcmpg (Frame *frame){
    Operando *valor_1 = frame->desempilhar();
    Operando *valor_2 = frame->desempilhar();

    int resultado = 0;
    if (std::isnan(valor_1->tipo_double) || std::isnan(valor_2->tipo_double))
        resultado = 1;
    else if (valor_1->tipo_double < valor_2->tipo_double)
        resultado = 1;
    else if (valor_1->tipo_double > valor_2->tipo_double)
        resultado = -1;

    std::memcpy(&valor_1->tipo_int, &resultado, sizeof(u4));
    valor_1->tag = TAG_INT;    frame->empilhar(valor_1);
    frame->pc++;
}

// 153 (0x99)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_ifeq (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int == 0) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 154 (0x9A)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * ifge é bem-sucedido se, e somente se, valor ≥ 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_ifne (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int != 0) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 155 (0x9B)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * ifge é bem-sucedido se, e somente se, valor ≥ 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_iflt (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int < 0) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 156 (0x9C)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * ifge é bem-sucedido se, e somente se, valor ≥ 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_ifge (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int >= 0) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 157 (0x9D)
// 156 (0x9C)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * ifge é bem-sucedido se, e somente se, valor ≥ 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_ifgt (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int > 0) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 158 (0x9E)
/**
 * @brief Faz um salto se um valor inteiro comparado com zero for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor deve ser do tipo inteiro. Ele é retirado da pilha de operandos e comparado com zero. Todas as comparações são feitas com sinal. Os resultados das comparações são os seguintes:
 * ifeq será bem-sucedido se, e somente se, valor = 0
 * ifne é bem-sucedido se e somente se o valor ≠ 0
 * iflt é bem-sucedido se e somente se o valor <0
 * ifle é bem-sucedido se e somente se o valor ≤ 0
 * O ifgt será bem-sucedido se e somente se o valor> 0
 * ifge é bem-sucedido se, e somente se, valor ≥ 0
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if <cond>. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução if <cond>.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução <cond>.
 * 
 */
void manipulador_ifle (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if ((int)op->tipo_int <= 0) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\t" + std::to_string((int)op->tipo_int) + " <= 0?");
    exibir_se_verboso("\tVai pular para: " + std::to_string(frame->pc + deslocamento));    frame->pc += deslocamento;
}

// 159 (0x9F)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmpeq (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();
    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int) op_1->tipo_int;

    if (i2 == i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " == " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 160 (0xA0)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmpne (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();

    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int) op_1->tipo_int;

    if (i2 != i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " != " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 161 (0xA1)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmplt (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();

    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int)op_1->tipo_int;

    if (i2 < i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " < " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 162 (0xA2)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmpge (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();

    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int)op_1->tipo_int;

    if (i2 >= i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " >= " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 163 (0xA3)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmpgt (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();

    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int)op_1->tipo_int;

    if (i2 > i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " > " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 164 (0xA4)
/**
 * @brief Faz um salto se a comparação de dois inteiros for verdadeiro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser do tipo inteiro. Ambos são retirados da pilha de operandos e comparados. Todas as comparações são com sinal. Os resultados da comparação são os seguintes:
 * if_icmpeq será bem-sucedido se e somente se value1 = value2
 * if_icmpne é bem-sucedido se e somente se value1 ≠ value2
 * if_icmplt é bem-sucedido se e somente se value1 < value2
 * if_icmple é bem-sucedido se e somente se value1 ≤ value2
 * if_icmpgt é bem-sucedido se e somente se value1 > value2
 * if_icmpge é bem-sucedido se e somente se value1 ≥ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados ​​para construir um deslocamento com sinal de 16 bits, onde o deslocamento é calculado para ser 
 * (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_icmp <cond>. O endereço de destino deve 
 * ser o de um código de operação de uma instrução dentro do método que contém esta instrução if_icmp <cond>.
 * 
 */
void manipulador_if_icmple (Frame *frame){
    Operando *op_1 = frame->desempilhar();
    Operando *op_2 = frame->desempilhar();

    int16_t deslocamento = 3;
    int i2 = (int) op_2->tipo_int,
        i1 = (int)op_1->tipo_int;

    if (i2 <= i1) {
        deslocamento = get_deslocamento(frame);
    }

    exibir_se_verboso("\tVerificando se " + std::to_string(i2) + " <= " + std::to_string(i1));
    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 165 (0xA5)
/**
 * @brief Faz um salto se a comparação entre referências for verdadeira
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser de referência do tipo. Ambos são retirados da pilha de operandos e comparados. Os resultados da comparação são os seguintes:
 * if_acmpeq será bem-sucedido se e somente se value1 = value2
 * if_acmpne é bem-sucedido se e somente se value1 ≠ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento de 16 bits com sinal, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_acmp <cond>. O endereço de destino deve ser o código de operação de uma instrução dentro do método que contém esta instrução if_acmp <cond>.
 * Caso contrário, se a comparação falhar, a execução continuará no endereço da instrução após esta instrução if_acmp <cond>.
 * 
 */
void manipulador_if_acmpeq (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    int16_t deslocamento = 3;

    if ((valor_2->tag == valor_1->tag) && (((u4) valor_2->tipo_byte) == ((u4) valor_1->tipo_byte))){
        deslocamento = get_deslocamento(frame);
    }

    frame->pc += deslocamento;
}

// 166 (0xA6)
/**
 * @brief Faz um salto se a comparação entre referências for verdadeira
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * O valor1 e o valor2 devem ser de referência do tipo. Ambos são retirados da pilha de operandos e comparados. Os resultados da comparação são os seguintes:
 * if_acmpeq será bem-sucedido se e somente se value1 = value2
 * if_acmpne é bem-sucedido se e somente se value1 ≠ value2
 * Se a comparação for bem-sucedida, branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento de 16 bits com sinal, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução if_acmp <cond>. O endereço de destino deve ser o código de operação de uma instrução dentro do método que contém esta instrução if_acmp <cond>.
 * Caso contrário, se a comparação falhar, a execução continuará no endereço da instrução após esta instrução if_acmp <cond>.
 * 
 */
void manipulador_if_acmpne (Frame *frame){
    Operando *valor_2 = frame->desempilhar();
    Operando *valor_1 = frame->desempilhar();

    int16_t deslocamento = 3;

    if ((valor_2->tag != valor_1->tag)
            || (((u4) valor_2->tipo_byte) != ((u4) valor_1->tipo_byte))){
        deslocamento = get_deslocamento(frame);
    }

    frame->pc += deslocamento;
}

// 167 (0xA7)
/**
 * @brief Função para sempre fazer branch quando o lida
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos
 * 
 * Os bytes sem sinal branchbyte1 e branchbyte2 são usados para construir um branchoffset de 16 bits com sinal, em que branchoffset é (branchbyte1 << 8) | branchbyte2.
 * A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução goto.
 * O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém essa instrução goto.
 * 
 */
void manipulador_goto (Frame *frame){
    int16_t deslocamento = get_deslocamento(frame);

    exibir_se_verboso("\tCom deslocamento de " + std::to_string(deslocamento)
        + " vai para " + std::to_string(frame->pc + deslocamento));

    frame->pc += deslocamento;
}

// 168 (0xA8)
/**
 * @brief jump para subrotina
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos,
 * 
 * O endereço do código de operação da instrução imediatamente após esta instrução jsr é inserido na pilha de operandos como um valor do tipo returnAddress. 
 * O branchbyte1 e branchbyte2 sem sinal são usados para construir um deslocamento com sinal de 16 bits, onde o deslocamento é (branchbyte1 << 8) | branchbyte2. 
 * A execução prossegue nesse deslocamento a partir do endereço desta instrução jsr. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução jsr.
 */
void manipulador_jsr (Frame *frame){
    Operando *op = new Operando();
    op->tipo_byte = frame->pc;

    frame->empilhar(op);

    frame->pc += get_deslocamento(frame);
}

// 169 (0xA9)
/**
 * @brief Retorno da subrotina
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O índice é um byte sem sinal entre 0 e 255, inclusivo. A variável local no índice no frame atual deve conter um valor do tipo returnAddress. O conteúdo da variável local é gravado no registro pc da Java Virtual Machine e a execução continua lá.
 * 
 */
void manipulador_ret (Frame *frame){
    u1 indice = frame->get_prox_byte();
    Operando *endereco = frame->var_locais.at(indice);

    if (endereco->tag != TAG_END){
        std::cout << "A variável local [" << (int) indice << "] não é " << get_tag(TAG_END) << std::endl;
        return;
    }

    frame->pc = endereco->tipo_int;
}

// 170 (0xAA)
/**
 * @brief Acessa a tabela de saltos por índice e salto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * Um interruptor de tabela é uma instrução de comprimento variável.
 * Imediatamente após o código de operação do comutador de tabelas, entre zero e três bytes devem atuar como preenchimento, de modo que o byte1 padrão comece em um endereço com múltiplos de quatro bytes desde o início do método atual (o código de operação de sua primeira instrução).
 * Imediatamente após o preenchimento, os bytes constituem três valores assinados de 32 bits: padrão, baixo e alto.
 * A seguir, são apresentados os bytes que constituem uma série de compensações alta - baixa + 1 assinadas de 32 bits.
 * O valor baixo deve ser menor ou igual a alto.
 * As compensações alta e baixa + 1 assinadas de 32 bits são tratadas como uma tabela de salto baseada em 0. 
 * Cada um desses valores de 32 bits assinados é construído como (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4.
 * O índice deve ser do tipo inteiro e é exibido na pilha de operandos.
 * Se o índice for menor que baixo ou se for maior que alto, um endereço de destino será calculado adicionando padrão ao endereço do código de operação desta instrução de comutação de tabela.
 * Caso contrário, o deslocamento no índice de posição - baixo da tabela de salto é extraído.
 * O endereço de destino é calculado adicionando esse deslocamento ao endereço do código de operação desta instrução de comutação de tabela.
 * A execução continua no endereço de destino.
 * O endereço de destino que pode ser calculado a partir de cada deslocamento da tabela de salto, bem como o que pode ser calculado a partir do padrão, deve ser o endereço de um código de operação de uma instrução dentro do método que contém esta instrução de comutação de tabela.
 * 
 */
void manipulador_tableswitch (Frame *frame){
    frame->pc += bytecodes[170].bytes + 1;
}

// 171 (0xAB)
/**
 * @brief Acesse a tabela de salto por combinação de teclas e salto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * Um lookupswitch é uma instrução de comprimento variável.
 * Imediatamente após o opcode da pesquisa, entre zero e três bytes deve atuar como preenchimento, de modo que o byte1 padrão comece em um endereço múltiplo de quatro bytes desde o início do método atual (o opcode de sua primeira instrução).
 * Imediatamente após o preenchimento, siga uma série de valores de 32 bits assinados: padrão, npairs e depois emparelha pares de valores de 32 bits assinados.
 * Os n pares devem ser maiores ou iguais a 0.
 * Cada um dos pares n pares consiste em uma correspondência int e um deslocamento assinado de 32 bits.
 * Cada um desses valores de 32 bits com sinal é construído a partir de quatro bytes não assinados como (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4
 * Os pares de deslocamento de correspondência de tabela da instrução lookupswitch devem ser classificados em ordem numérica crescente por correspondência.
 * A chave deve ser do tipo inteiro e é exibida na pilha de operandos.
 * A chave é comparada com os valores correspondentes. Se for igual a um deles, um endereço de destino será calculado adicionando o deslocamento correspondente ao endereço do código de operação desta instrução da chave de pesquisa. Se a chave não corresponder a nenhum dos valores correspondentes, o endereço de destino será calculado adicionando o padrão ao endereço do código de operação desta instrução de pesquisa. A execução continua no endereço de destino.
 * O endereço de destino que pode ser calculado a partir do deslocamento de cada par de deslocamento de correspondência, bem como o calculado a partir do padrão, deve ser o endereço de um código de operação de uma instrução no método que contém essa instrução de pesquisa.
 *  
 */
void manipulador_lookupswitch (Frame *frame){
    frame->pc += bytecodes[171].bytes + 1;
}

// 172 (0xAC)
/**
 * @brief Retorna inteiro do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O método atual deve ter o tipo de retorno booleano, byte, short, char ou inteiro. 
 * O valor deve ser do tipo int.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual. 
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_ireturn (Frame *frame){
    manipulador_xreturn(frame, TAG_INT);
}

// 173 (0xAD)
/**
 * @brief Retorna longo do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O valor deve ser do tipo longo.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual.
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_lreturn (Frame *frame){
    manipulador_xreturn(frame, TAG_LNG);
}

// 174 (0xAE)
/**
 * @brief Retorna flutuante do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O valor deve ser do tipo flutuante.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual.
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_freturn (Frame *frame){
    manipulador_xreturn(frame, TAG_FLT);
}

// 175 (0xAF)
/**
 * @brief Retorna double do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O valor deve ser do tipo double.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual.
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_dreturn (Frame *frame){
    manipulador_xreturn(frame, TAG_DBL);
}

// 176 (0xB0)
/**
 * @brief Retorna referência do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O objectref deve ser de referência de tipo e deve se referir a um objeto de um tipo compatível com atribuição com o tipo representado pelo descritor de retorno do método atual.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual.
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_areturn (Frame *frame){
    manipulador_xreturn(frame, TAG_REF);
}

// 177 (0xB1)
/**
 * @brief Retorna void do método
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O método atual deve ter o tipo de retorno nulo.
 * Se o método atual for um método sincronizado, o monitor inserido ou reinserido na invocação do método será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit no encadeamento atual.
 * Se nenhuma exceção for lançada, o valor será exibido na pilha de operandos do frame atual e empurrado para a pilha de operandos do quadro do invocador.
 * Quaisquer outros valores na pilha de operandos do método atual são descartados.
 * O intérprete retorna o controle ao invocador do método, restabelecendo o frame do invocador.
 * 
 */
void manipulador_return (Frame *frame){
    manipulador_xreturn(frame, TAG_VAZ);
}

// 178 (0xB2)
/**
 * @brief Obter campo estático da classe
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados para construir um índice no pool constant de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um campo, que fornece o nome e o descritor do campo, bem como uma referência simbólica à classe ou interface na qual o campo deve ser encontrado. 
 * O campo referenciado é resolvido.
 * Na resolução bem-sucedida do campo, a classe ou interface que declarou o campo resolvido é inicializada se essa classe ou interface ainda não tiver sido inicializada.
 * O valor do campo de classe ou interface é buscado e enviado para a pilha de operandos.
 * 
 */
void manipulador_getstatic (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    if (c_dados->tag != TAG_REF_CMP){
        std::cout << "Não é possível acessar um campo estático com a referência errada" << std::endl;
        std::cout << "\tDeveria ser " << get_tag(TAG_REF_CMP) << " mas é " << get_tag(c_dados->tag) << std::endl;
        return;
    }

    std::string nome_classe = (dynamic_cast<InfoRefCampo*>(c_dados))->get_nome_classe();

    if (!nome_classe.compare("java/lang/System")){
        exibir_se_verboso("\tSendo 'java/lang/System', não precisa");
        frame->pc++;
        return;
    }

    exibir_se_verboso("\tInd: " + std::to_string((int) indice));

    frame->a_empilhar = c_dados;
    frame->pc++;
}

// 179 (0xB3)
/**
 * @brief Define campo estático da classe
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. 
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um campo, que fornece o nome e o descritor do campo, bem como uma referência simbólica à classe ou interface na qual o campo deve ser encontrado. 
 * O campo referenciado é resolvido.
 * Na resolução bem-sucedida do campo, a classe ou interface que declarou o campo resolvido é inicializada se essa classe ou interface ainda não tiver sido inicializada.
 * O valor do campo de classe ou interface é buscado e enviado para a pilha de operandos.
 * O tipo de valor armazenado por uma instrução putstatic deve ser compatível com o descritor do campo referenciado.
 * Se o tipo de descritor de campo for booleano, byte, char, short ou int, o valor deverá ser um int. Se o tipo de descritor de campo for flutuante, longo ou duplo, o valor deverá ser flutuante, longo ou duplo, respectivamente. Se o tipo de descritor de campo for um tipo de referência, o valor deverá ser de um tipo compatível com a atribuição com o tipo de descritor de campo.
 * Se o campo for final, ele deve ser declarado na classe atual e a instrução deve ocorrer no método <clinit> da classe atual.
 * O valor é retirado da pilha de operandos e passa pela conversão do conjunto de valores. O campo da classe está definido como valor.
 * 
 */
void manipulador_putstatic (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();

    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (c_dados->tag != TAG_REF_CMP){
        std::cout << "Não é possível acessar um campo com a referência errada" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_REF_CMP) << std::endl;
        return;
    }

    std::string nome_classe = (dynamic_cast<InfoRefCampo*>(c_dados))->get_nome_classe();

    if (!nome_classe.compare("java/lang/System")){
        // std::cout << "\tNão precisa" << std::endl;
        frame->pc++;
        return;
    }

    frame->a_empilhar = c_dados;
    frame->retorno = frame->desempilhar();
    frame->pc++;
}

// 180 (0xB4)
/**
 * @brief Buscar campo do objeto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O objectref, que deve ser do tipo referência, é exibido na pilha de operandos.
 * O indexbyte1 e indexbyte2 sem sinal são usados para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um campo, que fornece o nome e o descritor do campo, bem como uma referência simbólica à classe na qual o campo deve ser encontrado. 
 * O campo referenciado é resolvido. O valor do campo referenciado no objectref é buscado e enviado para a pilha de operandos.
 * O tipo de objectref não deve ser um tipo de matriz. Se o campo estiver protegido e for membro de uma superclasse da classe atual, e o campo não for declarado no mesmo pacote de tempo de execução da classe atual, a classe de objectref deve ser a classe atual ou uma subclasse da classe atual.
 * 
 */
void manipulador_getfield (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);
    if (!c_dados){
        std::cout << "Não existe dados no índice: " << (int) indice << std::endl;
        return;
    }

    std::string campo = (dynamic_cast<InfoRefCampo*>(c_dados))->get_nome_campo();
    Operando* instancia_classe = frame->desempilhar();
    std::cout << "tamanho: " << instancia_classe->obj->referencias.size() << std::endl;
    frame->empilhar(instancia_classe->obj->referencias[campo]);
    // frame->pc++;
}

// 181 (0xB5)
/**
 * @brief Define campo no objeto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um campo, que fornece o nome e o descritor do campo, bem como uma referência simbólica à classe na qual o campo deve ser encontrado. A classe de objectref não deve ser uma matriz.
 * Se o campo estiver protegido e for membro de uma superclasse da classe atual, e o campo não for declarado no mesmo pacote de tempo de execução da classe atual, a classe de objectref deve ser a classe atual ou uma subclasse da classe atual.
 * O campo referenciado é resolvido. O tipo de valor armazenado por uma instrução putfield deve ser compatível com o descritor do campo referenciado. 
 * Se o tipo de descritor de campo for booleano, byte, char, short ou int, o valor deverá ser um int.
 * Se o tipo de descritor de campo for flutuante, longo ou duplo, o valor deverá ser flutuante, longo ou duplo, respectivamente.
 * Se o tipo de descritor de campo for um tipo de referência, o valor deverá ser de um tipo compatível com a atribuição (JLS §5.2) com o tipo de descritor de campo. Se o campo for final, ele deve ser declarado na classe atual e a instrução deve ocorrer em um método de inicialização de instância (<init>) da classe atual (§2.9).
 * O valor e objectref são removidos da pilha de operandos. O objectref deve ser de referência do tipo.
 * O valor passa pela conversão de valores, e o campo referenciado no objectref é definido como valor.
 * 
 */
void manipulador_putfield (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);
    if (!c_dados){
        std::cout << "Não existe dados no índice: " << (int) indice << std::endl;
        return;
    }
    std::string nome_campo = (dynamic_cast<InfoRefCampo*>(c_dados))->get_nome_campo();


    Operando *op = frame->desempilhar();

    Operando* instancia_classe = frame->desempilhar();

    if(instancia_classe->obj != nullptr) {
        Operando* atributo = instancia_classe->obj->referencias[nome_campo];
        if(atributo == nullptr) {
            atributo = new Operando();
        }

        atributo->tag = op->tag;

        switch(op->tag){
            case TAG_INT:
                atributo->tipo_int = op->tipo_int;
                break;
            case TAG_LNG:
                atributo->tipo_long = op->tipo_long;
                break;
            case TAG_CHR:
                atributo->tipo_char = op->tipo_char;
                break;
            case TAG_SHT:
                atributo->tipo_short = op->tipo_short;
                break;
            case TAG_BYTE:
                atributo->tipo_byte = op->tipo_byte;
                break;
            case TAG_FLT:
                atributo->tipo_float = op->tipo_float;
                break;
            case TAG_DBL:
                atributo->tipo_double = op->tipo_double;
                break;
            case TAG_STR:
                atributo->tipo_string = op->tipo_string;
                break;
            case TAG_CLAS:
                atributo->obj = op->obj;
                break;
            default:
                break;
        }
        instancia_classe->obj->referencias[nome_campo] = atributo;
    }

    frame->pc++;
}

// 182 (0xB6)
/**
 * @brief Invocar método de instância e expedição com base na classe
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de pconstant pool em tempo de execução nesse índice deve ser uma referência simbólica a um método, que fornece o nome e o descritor do método, bem como uma referência simbólica à classe na qual o método deve ser encontrado. O método nomeado é resolvido. 
 * O método resolvido não deve ser um método de inicialização de instância ou o método de inicialização de classe ou interface. 
 * Por fim, se o método resolvido estiver protegido e for membro de uma superclasse da classe atual, e o método não for declarado no mesmo pacote de tempo de execução da classe atual, o comando classe de objectref deve ser a classe atual ou uma subclasse da classe atual.
 * Se o método resolvido não for polimórfico de assinatura, a instrução invokevirtual será da seguinte maneira.
 * Seja C a classe de objectref. O método real a ser chamado é selecionado pelo seguinte procedimento de pesquisa:
 * Se C contiver uma declaração para um método de instância m que substitua o método resolvido, então m é o método a ser invocado e o procedimento de pesquisa é encerrado.
 * Caso contrário, se C tiver uma superclasse, esse mesmo procedimento de pesquisa será executado recursivamente usando a superclasse direta de C; o método a ser invocado é o resultado da invocação recursiva deste procedimento de pesquisa.
 * Caso contrário, um AbstractMethodError é gerado.
 * O objectref deve ser seguido na pilha de operandos pelos valores do argumento n args, em que o número, tipo e ordem dos valores devem ser consistentes com o descritor do método de instância selecionado.
 * Se o método for sincronizado, o monitor associado ao objectref será inserido ou reinserido como se fosse pela execução de uma instrução do monitorenter (§monitorenter) no encadeamento atual.
 * Se o método não for nativo, os valores do argumento nargs e objectref serão exibidos na pilha de operandos. Um novo quadro é criado na pilha da Java Virtual Machine para o método que está sendo chamado. Os valores objectref e argumento são transformados consecutivamente nos valores das variáveis ​​locais do novo quadro, com objectref na variável local 0, arg1 na variável local 1 (ou, se arg1 for do tipo longo ou duplo, nas variáveis ​​locais 1 e 2) , e assim por diante. Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores (§2.8.3) antes de ser armazenado em uma variável local. O novo quadro é atualizado e o Java Virtual Machine pc é definido como o código de operação da primeira instrução do método a ser chamado. A execução continua com a primeira instrução do método.
 * Se o método for nativo e o código dependente da plataforma que o implementa ainda não tiver sido vinculado (§5.6) à Java Virtual Machine, isso será feito. Os valores do argumento nargs e objectref são removidos da pilha de operandos e são passados ​​como parâmetros para o código que implementa o método. Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores (§2.8.3) antes de ser passado como parâmetro. Os parâmetros são passados ​​e o código é chamado de uma maneira dependente da implementação. Quando o código dependente da plataforma retorna, ocorre o seguinte:
 * Se o método nativo estiver sincronizado, o monitor associado ao objectref será atualizado e possivelmente encerrado como se estivesse executando uma instrução de monitorexit (§monitorexit) no encadeamento atual.
 * Se o método nativo retornar um valor, o valor retornado do código dependente da plataforma será convertido de maneira dependente da implementação no tipo de retorno do método nativo e empurrado para a pilha de operandos.
 * Se o método resolvido for assinatura polimórfica, a instrução invokevirtual continuará da seguinte maneira.
 * Primeiro, uma referência a uma instância de java.lang.invoke.MethodType é obtida como se por resolução de uma referência simbólica a um tipo de método (§5.4.3.5) com o mesmo parâmetro e tipos de retorno que o descritor do método referenciado por a instrução invokevirtual.
 * Se o método nomeado for invokeExact, a instância de java.lang.invoke.MethodType deverá ser semanticamente igual ao descritor de tipo do identificador do método de recebimento objectref. O identificador de método a ser chamado é objectref.
 * Se o método nomeado for chamado, e a instância de java.lang.invoke.MethodType for semanticamente igual ao descritor de tipo do identificador do método receptor, objectref, o identificador do método a ser chamado será objectref.
 * Se o método nomeado for chamado e a instância de java.lang.invoke.MethodType não for semanticamente igual ao descritor de tipo do identificador do método de recebimento objectref, a Java Virtual Machine tentará ajustar o descritor de tipo do identificador do método de recebimento, como se por uma chamada para java.lang.invoke.MethodHandle.asType, para obter um método exatamente invocável, manipule m.
 * O identificador de método a ser chamado é m.
 * O objectref deve ser seguido na pilha de operandos por n args
 * 
 */
void manipulador_invokevirtual (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << (int) indice << std::endl;
        return;
    }

    if (c_dados->tag != TAG_REF_MTD){
        std::cout << "Não é possível acessar um método com a referência errada" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_REF_MTD) << std::endl;
        return;
    }

    std::string nome_classe = (dynamic_cast<InfoRefMetodo*>(c_dados))->get_nome_classe();

    if (!nome_classe.compare("java/io/PrintStream")){
        std::cout << frame->desempilhar()->get();

        if (!(dynamic_cast<InfoRefMetodo*>(c_dados))->get_nome_metodo().compare("println"))
            std::cout << std::endl;

        frame->pc++;

        return;
    }

    frame->pc++;
    frame->a_empilhar = c_dados;
}

// 183 (0xB7)
/**
 * @brief Invocar método de instância e manipulação especial para chamadas de método de inicialização de superclasse, privada e instância
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no pool constante de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. 
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um método, que fornece o nome e o descritor do método, bem como uma referência simbólica à classe na qual o método deve ser encontrado. O método nomeado é resolvido. 
 * Por fim, se o método resolvido estiver protegido e for membro de uma superclasse da classe atual, e o método não for declarado no mesmo pacote de tempo de execução da classe atual, o comando classe de objectref deve ser a classe atual ou uma subclasse da classe atual.
 * Em seguida, o método resolvido é selecionado para chamada, a menos que todas as seguintes condições sejam verdadeiras:
 * O sinalizador ACC_SUPER está definido para a classe atual.
 * A classe do método resolvido é uma superclasse da classe atual.
 * O método resolvido não é um método de inicialização de instância
 * Se as condições acima forem verdadeiras, o método real a ser chamado é selecionado pelo seguinte procedimento de pesquisa. Seja C a superclasse direta da classe atual:
 * Se C contiver uma declaração para um método de instância com o mesmo nome e descritor que o método resolvido, esse método será chamado. O procedimento de pesquisa termina.
 * Caso contrário, se C tiver uma superclasse, esse mesmo procedimento de pesquisa será executado recursivamente usando a superclasse direta de C. O método a ser invocado é o resultado da invocação recursiva desse procedimento de pesquisa.
 * Caso contrário, um AbstractMethodError é gerado.
 * O objectref deve ser de referência de tipo e deve ser seguido na pilha de operandos pelos valores do argumento nargs, em que o número, o tipo e a ordem dos valores devem ser consistentes com o descritor do método de instância selecionado.
 * Se o método for sincronizado, o monitor associado ao objectref será inserido ou reinserido como se fosse pela execução de uma instrução do monitorenter no encadeamento atual.
 * Se o método não for nativo, os valores do argumento nargs e objectref serão exibidos na pilha de operandos. Um novo quadro é criado na pilha da Java Virtual Machine para o método que está sendo chamado.
 * Os valores objectref e argumento são transformados consecutivamente nos valores das variáveis ​​locais do novo quadro, com objectref na variável local 0, arg1 na variável local 1 (ou, se arg1 for do tipo longo ou duplo, nas variáveis ​​locais 1 e 2) , e assim por diante. Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser armazenado em uma variável local.
 * O novo quadro é atualizado e o Java Virtual Machine pc é definido como o código de operação da primeira instrução do método a ser chamado.
 * A execução continua com a primeira instrução do método.
 * Se o método for nativo e o código dependente da plataforma que o implementa ainda não tiver sido vinculado à Java Virtual Machine, isso será feito. Os valores do argumento nargs e objectref são removidos da pilha de operandos e são passados ​​como parâmetros para o código que implementa o método. 
 * Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser passado como parâmetro. 
 * Os parâmetros são passados ​​e o código é chamado de uma maneira dependente da implementação. 
 * Quando o código dependente da plataforma retorna, ocorre o seguinte:
 * e o método nativo estiver sincronizado, o monitor associado ao objectref será atualizado e possivelmente encerrado como se estivesse executando uma instrução de monitorexit no encadeamento atual.
 * Se o método nativo retornar um valor, o valor retornado do código dependente da plataforma será convertido de maneira dependente da implementação no tipo de retorno do método nativo e empurrado para a pilha de operandos.
 * 
 */
void manipulador_invokespecial (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << (int) indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_REF_MTD) && (c_dados->tag != TAG_REF_MTD_ITF)){
        std::cout << "Não é possível acessar um método com a referência errada" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_REF_MTD);
        std::cout << " nem " << get_tag(TAG_REF_MTD_ITF) << std::endl;
        return;
    }

    exibir_se_verboso("\t#" + std::to_string((int) indice) + " -> " + c_dados->get());

    frame->a_empilhar = c_dados;
    frame->pc++;
}

// 184 (0xB8)
/**
 * @brief Invocar um método de classe (estático)
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de pconstant pool em tempo de execução nesse índice deve ser uma referência simbólica a um método, que fornece o nome e o descritor do método, bem como uma referência simbólica à classe na qual o método deve ser encontrado.
 * O método nomeado é resolvido. 
 * O método resolvido não deve ser um método de inicialização de instância ou o método de inicialização de classe ou interface.
 * Deve ser estático e, portanto, não pode ser abstrato.
 * Na resolução bem-sucedida do método, a classe que declarou o método resolvido é inicializada se essa classe ainda não tiver sido inicializada.
 * A pilha de operandos deve conter valores de argumentos de nargs, em que o número, tipo e ordem dos valores devem ser consistentes com o descritor do método resolvido.
 * Se o método estiver sincronizado, o monitor associado ao objeto Classe resolvido será inserido ou reinserido como se fosse pela execução de uma instrução do monitorenter (§monitorenter) no encadeamento atual.
 * Se o método não for nativo, os valores do argumento nargs serão exibidos na pilha de operandos. 
 * Um novo quadro é criado na pilha da Java Virtual Machine para o método que está sendo chamado.
 * Os valores do argumento nargs são transformados consecutivamente nos valores das variáveis ​​locais do novo quadro, com arg1 na variável local 0 (ou, se arg1 for do tipo longo ou duplo, nas variáveis ​​locais 0 e 1) e assim por diante. 
 * Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser armazenado em uma variável local. 
 * O novo quadro é atualizado e o Java Virtual Machine pc é definido como o código de operação da primeira instrução do método a ser chamado.
 * A execução continua com a primeira instrução do método.
 * Se o método for nativo e o código dependente da plataforma que o implementa ainda não tiver sido vinculado à Java Virtual Machine, isso será feito. 
 * Os valores do argumento nargs são removidos da pilha de operandos e são passados ​​como parâmetros para o código que implementa o método. 
 * Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser passado como parâmetro. 
 * Os parâmetros são passados ​​e o código é chamado de uma maneira dependente da implementação.
 * Quando o código dependente da plataforma retorna, ocorre o seguinte:
 * Se o método nativo for sincronizado, o monitor associado ao objeto Classe resolvido será atualizado e possivelmente encerrado como se fosse pela execução de uma instrução de monitorexit (§monitorexit) no encadeamento atual.
 * Se o método nativo retornar um valor, o valor retornado do código dependente da plataforma será convertido de maneira dependente da implementação no tipo de retorno do método nativo e empurrado para a pilha de operandos.
 * 
 */
void manipulador_invokestatic (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_REF_MTD) && (c_dados->tag != TAG_REF_MTD_ITF)){
        std::cout << "Não é possível acessar um método estático com a referência errada" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_REF_MTD);
        std::cout << " nem " << get_tag(TAG_REF_MTD_ITF) << std::endl;
        return;
    }

    frame->a_empilhar = c_dados;
    frame->pc++;
}

// rever-
// 185 (0xB9)
/**
 * @brief Invocar o método da interface
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a um método de interface, que fornece o nome e o descritor do método de interface, bem como uma referência simbólica à interface em qual o método de interface deve ser encontrado. 
 * O método da interface nomeada foi resolvido.
 * O método de interface resolvido não deve ser um método de inicialização de instância ou o método de inicialização de classe ou interface.
 * O operando de contagem é um byte não assinado que não deve ser zero.
 * O objectref deve ser de referência de tipo e deve ser seguido na pilha de operandos pelos valores do argumento nargs, em que o número, o tipo e a ordem dos valores devem ser consistentes com o descritor do método da interface resolvida.
 * O valor do quarto byte do operando deve sempre ser zero.
 * Seja C a classe de objectref. O método real a ser chamado é selecionado pelo seguinte procedimento de pesquisa:
 * Se C contiver uma declaração para um método de instância com o mesmo nome e descritor que o método resolvido, esse é o método a ser chamado e o procedimento de pesquisa será encerrado.
 * Caso contrário, se C tiver uma superclasse, esse mesmo procedimento de pesquisa será executado recursivamente usando a superclasse direta de C; o método a ser invocado é o resultado da invocação recursiva deste procedimento de pesquisa.
 * Caso contrário, um AbstractMethodError é gerado.
 * Se o método for sincronizado, o monitor associado ao objectref será inserido ou reinserido como se fosse pela execução de uma instrução do monitorenter (§monitorenter) no encadeamento atual.
 * Se o método não for nativo, os valores do argumento nargs e objectref serão exibidos na pilha de operandos. Um novo quadro é criado na pilha da Java Virtual Machine para o método que está sendo chamado.
 * Os valores objectref e argumento são transformados consecutivamente nos valores das variáveis ​​locais do novo quadro, com objectref na variável local 0, arg1 na variável local 1 (ou, se arg1 for do tipo longo ou duplo, nas variáveis ​​locais 1 e 2) , e assim por diante. 
 * Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser armazenado em uma variável local.
 * O novo quadro é atualizado e o Java Virtual Machine pc é definido como o código de operação da primeira instrução do método a ser chamado.
 * A execução continua com a primeira instrução do método.
 * Se o método for nativo e o código dependente da plataforma que o implementa ainda não tiver sido vinculado à Java Virtual Machine, isso será feito. 
 * Os valores do argumento nargs e objectref são removidos da pilha de operandos e são passados ​​como parâmetros para o código que implementa o método.
 * Qualquer valor de argumento que seja do tipo de ponto flutuante passa pela conversão do conjunto de valores antes de ser passado como parâmetro.
 * Os parâmetros são passados ​​e o código é chamado de uma maneira dependente da implementação. 
 * Quando o código dependente da plataforma retornar:
 * Se o método nativo estiver sincronizado, o monitor associado ao objectref será atualizado e possivelmente encerrado como se estivesse executando uma instrução de monitorexit (§monitorexit) no encadeamento atual.
 * Se o método nativo retornar um valor, o valor retornado do código dependente da plataforma será convertido de maneira dependente da implementação no tipo de retorno do método nativo e empurrado para a pilha de operandos.
 *  
 */
void manipulador_invokeinterface (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << (int) indice << std::endl;
        return;
    }

    if ((c_dados->tag != TAG_REF_MTD) && (c_dados->tag != TAG_REF_MTD_ITF)){
        std::cout << "Não é possível acessar um método com a referência errada" << std::endl;
        std::cout << "\t" << get_tag(c_dados->tag) << " não é " << get_tag(TAG_REF_MTD);
        std::cout << " nem " << get_tag(TAG_REF_MTD_ITF) << std::endl;
        return;
    }

    exibir_se_verboso("\t#" + std::to_string((int) indice) + " -> " + c_dados->get());

    frame->a_empilhar = c_dados;
    frame->pc++;
}

// add
// 186 (0xBA)
/**
 * @brief Invocar método dinâmico
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * Cada ocorrência lexical específica de uma instrução dinâmica invocada é chamada de site de chamada dinâmica.
 * Primeiro, o indexbyte1 e o indexbyte2 não assinados são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. O item de pool constante em tempo de execução nesse índice deve ser uma referência simbólica a um especificador de site de chamada. Os valores do terceiro e quarto bytes do operando devem sempre ser zero.
 * O especificador do site de chamada foi resolvido para que este site de chamada dinâmico específico obtenha uma referência a uma instância java.lang.invoke.MethodHandle, uma referência a uma instância java.lang.invoke.MethodType e referências a static argumentos.
 * Em seguida, como parte da resolução contínua do especificador do site de chamada, o método de autoinicialização é chamado como se fosse pela execução de uma instrução virtual invokevirtual (§invokevirtual) que contenha um índice de pool constante em tempo de execução para uma referência simbólica a um método com as seguintes propriedades:
 * O nome do método é invocado;
 * O descritor do método possui um tipo de retorno java.lang.invoke.CallSite;
 * O descritor do método possui tipos de parâmetros derivados dos itens enviados para a pilha de operandos, conforme a seguir.
 * Os quatro primeiros tipos de parâmetros no descritor são
 * java.lang.invoke.MethodHandle,
 * java.lang.invoke.MethodHandles.Lookup, String e 
 * java.lang.invoke.MethodType, nessa ordem.
 * Se o especificador do site de chamada tiver argumentos estáticos, um tipo de parâmetro para cada argumento será anexado aos tipos de parâmetros do descritor de método na ordem em que os argumentos foram enviados à pilha de operandos.
 * Esses tipos de parâmetros podem ser Class, java.lang.invoke.MethodHandle, java.lang.invoke.MethodType, String, int, long, float ou double.
 * A referência simbólica do método à classe na qual o método deve ser encontrado indica a classe java.lang.invoke.MethodHandle.
 * onde é como se os seguintes itens fossem empurrados, em ordem, para a pilha de operandos:
 * a referência ao objeto java.lang.invoke.MethodHandle para o método de autoinicialização;
 * uma referência a um objeto java.lang.invoke.MethodHandles.Lookup para a classe na qual esse site de chamada dinâmica ocorre;
 * uma referência à String para o nome do método no especificador do site de chamada;
 * a referência ao objeto java.lang.invoke.MethodType obtido para o descritor de método no especificador de site de chamada;
 * referências a classes, tipos de métodos, identificadores de métodos e literais de cadeia de caracteres denotados como argumentos estáticos no especificador do site de chamada e valores numéricos denotados como argumentos estáticos no especificador de site de chamada, na ordem em que eles aparecem no especificador do site de chamada.
 * (Ou seja, não ocorre boxe para valores primitivos.)
 * Desde que o método de autoinicialização possa ser invocado corretamente pelo método de invocação, seu descritor é arbitrário.
 * Por exemplo, o primeiro tipo de parâmetro pode ser Object, em vez de java.lang.invoke.MethodHandles.Lookup, e o tipo de retorno também pode ser Object, em vez de java.lang.invoke.CallSite.
 * Se o método de autoinicialização for um método de variável variável, alguns ou todos os argumentos na pilha de operandos especificados acima podem ser coletados em um parâmetro de matriz à direita.
 * A chamada de um método de autoinicialização ocorre dentro de um encadeamento que está tentando resolver a referência simbólica ao especificador do site de chamada deste site de chamada dinâmico.
 * Se houver vários desses segmentos, o método de autoinicialização poderá ser chamado em vários segmentos simultaneamente. 
 * Portanto, os métodos de autoinicialização que acessam os dados globais do aplicativo devem tomar as precauções habituais contra as condições de corrida.
 * O resultado retornado pelo método bootstrap deve ser uma referência a um objeto cuja classe é java.lang.invoke.CallSite ou uma subclasse de java.lang.invoke.CallSite. 
 * Este objeto é conhecido como objeto de site de chamada. A referência é exibida na pilha de operandos usada como se estivesse na execução de uma instrução invokevirtual.
 * Se vários encadeamentos executam simultaneamente o método de autoinicialização para o mesmo site de chamada dinâmico, a Java Virtual Machine deve escolher um objeto de site de chamada retornado e instalá-lo visivelmente em todos os encadeamentos.
 * Todos os outros métodos de inicialização executados para o site de chamada dinâmico podem ser concluídos, mas seus resultados são ignorados e a execução dos threads do site de chamada dinâmica continua com o objeto de site de chamada escolhido.
 * O objeto do site de chamada possui um descritor de tipo (uma instância de java.lang.invoke.MethodType) que deve ser semanticamente igual ao objeto java.lang.invoke.MethodType obtido para o descritor de método no especificador de site de chamada.
 * O resultado da resolução bem-sucedida do especificador de site de chamada é um objeto de site de ligação permanentemente vinculado ao site de chamada dinâmico.
 * O identificador de método representado pelo destino do objeto de site de chamada vinculada é chamado. A invocação ocorre como se pela execução de uma instrução invokevirtual (§invokevirtual) que indica um índice de pool constante em tempo de execução para uma referência simbólica a um método com as seguintes propriedades:
 * O nome do método é invokeExact;
 * 
 */
void manipulador_invokedynamic (Frame *frame){
    frame->pc += bytecodes[186].bytes + 1;
}

// 187 (0xBB)
/**
 * @brief Criar novo objeto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O indexbyte1 e indexbyte2 sem sinal são usados para construir um índice no contant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. 
 * O item de constant pool em tempo de execução no índice deve ser uma referência simbólica a um tipo de classe ou interface.
 * A classe nomeada ou o tipo de interface é resolvido e deve resultar em um tipo de classe.
 * A memória para uma nova instância dessa classe é alocada a partir do heap coletado pelo lixo e as variáveis de instância do novo objeto são inicializadas com seus valores iniciais padrão.
 * O objectref, uma referência à instância, é empurrado para a pilha de operandos.
 * Na resolução bem-sucedida da classe, ela é inicializada se ainda não tiver sido inicializada.
 * 
 */
void manipulador_new (Frame *frame){
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();
    u2 indice = (byte_1 << 8) | byte_2;

    InterCPDado *c_dados = frame->buscar_simbolo(indice);

    if (!c_dados){
        std::cout << "Não existe dados no índice: " << indice << std::endl;
        return;
    }

    frame->a_empilhar = c_dados;
    frame->pc++;
}

// 188 (0xBC)
/**
 * @brief Criar novo array
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * A contagem deve ser do tipo inteiro. 
 * É retirado da pilha de operandos. 
 * A contagem representa o número de elementos na matriz a ser criada.
 * O atype é um código que indica o tipo de matriz a ser criada. Ele deve assumir um dos seguintes valores:
 * Array Type   atype
 * T_BOOLEAN    4
 * T_CHAR       5
 * T_FLOAT      6
 * T_DOUBLE     7
 * T_BYTE       8
 * T_SHORT      9
 * T_INT        10
 * T_LONG       11
 * Uma nova matriz cujos componentes são do tipo atype e da contagem de comprimento é alocada no heap coletado pelo lixo.
 * Uma matriz de referênciaref para esse novo objeto de matriz é enviada para a pilha de operandos.
 * Cada um dos elementos da nova matriz é inicializado com o valor inicial padrão para o tipo de elemento do tipo de matriz.
 * 
 */
void manipulador_newarray (Frame *frame){
    Operando *quantidade = frame->desempilhar();

    if (!quantidade){
        std::cout << "Não houve o que desempilhar" << std::endl;
        return;
    }

    u1 tipo_array = frame->get_prox_byte();

    int qnt = (int) quantidade->tipo_int;

    Operando *array = new Operando();
    array->tag = TAG_ARR;

    array->lista_operandos = new std::vector<Operando*>();

    for (int cnt = 0; cnt < qnt; cnt++){
        Operando *op = new Operando();

        switch (tipo_array){
            case ARR_BLN: op->tag = TAG_BLN; break;
            case ARR_CHR: op->tag = TAG_CHR; break;
            case ARR_FLT: op->tag = TAG_FLT; break;
            case ARR_DBL: op->tag = TAG_DBL; break;
            case ARR_BYTE: op->tag = TAG_BYTE; break;
            case ARR_SHT: op->tag = TAG_SHT; break;
            case ARR_INT: op->tag = TAG_INT; break;
            case ARR_LNG: op->tag = TAG_LNG; break;
            default: op->tag = TAG_VAZ;
        }

        if (op->tag != TAG_VAZ)
            array->lista_operandos->push_back(op);

    }

    exibir_se_verboso("\tCriado um vetor com " + std::to_string(qnt) + " itens do tipo "
        + std::to_string(tipo_array));

    frame->empilhar(array);
    frame->pc++;
}

// 189 (0xBD)
/**
 * @brief Crie uma nova matriz de referência
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * A contagem deve ser do tipo inteiro.
 * É retirado da pilha de operandos.
 * A contagem representa o número de componentes da matriz a ser criada.
 * O indexbyte1 e indexbyte2 sem sinal são usados para construir um índice no pool constante de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2.
 * O item de constant pool em tempo de execução nesse índice deve ser uma referência simbólica a uma classe, matriz ou tipo de interface.
 * A classe, matriz ou tipo de interface nomeado é resolvido.
 * Uma nova matriz com componentes desse tipo, de contagem de comprimento, é alocada a partir da pilha coletada de lixo e uma matriz de referênciaref para esse novo objeto de matriz é enviada para a pilha de operandos.
 * Todos os componentes da nova matriz são inicializados como nulos, o valor padrão para os tipos de referência
 * 
 */
void manipulador_anewarray (Frame *frame){
    frame->pc += bytecodes[189].bytes + 1;
}

// 190 (0xBE)
/**
 * @brief Calcula o tamanho de um vetor
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O arraydef deve ser do tipo referência e deve se referir à um vetor. É obtido pegando o primeiro elemento da pilha. O tamanho do vetor é determinado e colocado no topo da pilha de operandos.
 */
void manipulador_arraylength (Frame *frame){
    Operando *array = frame->desempilhar();
    Operando *tamanho = new Operando();
    tamanho->tag = TAG_INT;

    if (array->tag != TAG_ARR || !array->lista_operandos)
        tamanho->tipo_int = 0;
    else
        tamanho->tipo_int = array->lista_operandos->size();

    frame->empilhar(tamanho);
    frame->pc++;
}

// 191 (0xBF)
/**
 * @brief Lançar excessão ou erro
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O objectref deve ser do tipo referência e deve se referir a um objeto que é uma instância da classe Throwable ou de uma subclasse de Throwable. É retirado da pilha de operandos. O objectref é então lançado pesquisando no método atual o primeiro manipulador de exceções que corresponda à classe de objectref
 * Se um manipulador de exceção que corresponda ao objectref for encontrado, ele conterá o local do código destinado a lidar com essa exceção. O registro do pc é redefinido para esse local, a pilha de operandos do frame atual é limpa, o objectref é empurrado de volta para a pilha de operandos e a execução continua.
 * Se nenhum manipulador de exceção correspondente for encontrado no quadro atual, esse quadro será exibido. Se o frame atual representa uma invocação de um método sincronizado, o monitor inserido ou reinserido na invocação do método é encerrado como se estivesse executando uma instrução de monitorexit
 * Finalmente, o quadro de seu invocador é restabelecido, se esse quadro existir, e o objectref é reapresentado. Se esse frame não existir, o encadeamento atual será encerrado.
 * 
 */
void manipulador_athrow (Frame *frame){
    frame->pc += bytecodes[191].bytes + 1;
}

// 192 (0xC0)
/**
 * @brief Verifica se um objeto é de um certo tipo
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos. 
 * 
 * O objectref deve ser de referência do tipo. O indexbyte1 e indexbyte2 não assinado são usados ​​para construir um índice no pool constante de tempo de execução da classe atual (§2.6), em que o valor do índice é (indexbyte1 << 8) | indexbyte2. O item de pool constante em tempo de execução no índice deve ser uma referência simbólica a uma classe, matriz ou tipo de interface.
 * Se objectref for nulo, a pilha de operandos não será alterada.
 * Caso contrário, a classe, matriz ou tipo de interface nomeado será resolvido (§5.4.3.1). Se objectref puder ser convertido para a classe resolvida, matriz ou tipo de interface, a pilha de operandos não será alterada; caso contrário, a instrução checkcast lança uma ClassCastException.
 * As regras a seguir são usadas para determinar se um objectref que não é nulo pode ser convertido para o tipo resolvido: se S é a classe do objeto referido por objectref e T é o tipo de classe, matriz ou interface resolvido, o checkcast determina se objectref pode ser convertido para o tipo T da seguinte maneira:
 * Se S é uma classe comum (sem matriz), então:
 * Se T é um tipo de classe, então S deve ser a mesma classe que T ou S deve ser uma subclasse de T;
 * Se T é um tipo de interface, S deve implementar a interface T.
 * Se S é um tipo de interface, então:
 * Se T é um tipo de classe, T deve ser Objeto.
 * Se T é um tipo de interface, T deve ser a mesma interface que S ou uma superinterface de S.
 * Se S é uma classe que representa o tipo de matriz SC [], ou seja, uma matriz de componentes do tipo SC, então:
 * Se T é um tipo de classe, T deve ser Objeto.
 * Se T é um tipo de interface, T deve ser uma das interfaces implementadas por matrizes (JLS §4.10.3).
 * Se T for um tipo de matriz TC [], ou seja, uma matriz de componentes do tipo TC, um dos seguintes deverá ser verdadeiro:
 * TC e SC são do mesmo tipo primitivo.
 * TC e SC são tipos de referência e o tipo SC pode ser convertido em TC pela aplicação recursiva dessas regras.
 */
void manipulador_checkcast (Frame *frame){
    frame->pc += bytecodes[192].bytes + 1;
}

// 193 (0xC1)
/**
 * @brief Determinar se o objeto é do tipo especificado
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O objectref, que deve ser do tipo referência, é exibido na pilha de operandos. O indexbyte1 e indexbyte2 não assinado são usados ​​para construir um índice no constant pool de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. O item de constant pool em tempo de execução no índice deve ser uma referência simbólica a uma classe, matriz ou tipo de interface.
 * Se objectref for nulo, a instrução instanceof envia um resultado int de 0 como int na pilha de operandos.
 * Caso contrário, a classe, matriz ou tipo de interface nomeado será resolvido. Se objectref é uma instância da classe ou matriz resolvida ou implementa a interface resolvida, a instrução instanceof envia um resultado int de 1 como int na pilha de operandos; caso contrário, ele envia um resultado int de 0.
 * As regras a seguir são usadas para determinar se um objectref que não é nulo é uma instância do tipo resolvido: Se S é a classe do objeto referido por objectref e T é o tipo de classe, matriz ou interface resolvido, instanceof determina se objectref é uma instância de T da seguinte maneira:
 * Se S é uma classe comum (sem matriz), então:
 * Se T é um tipo de classe, então S deve ser a mesma classe que T ou S deve ser uma subclasse de T;
 * Se T é um tipo de interface, S deve implementar a interface T.
 * Se S é um tipo de interface, então:
 * Se T é um tipo de classe, T deve ser Objeto.
 * Se T é um tipo de interface, T deve ser a mesma interface que S ou uma superinterface de S.
 * Se S é uma classe que representa o tipo de matriz SC [], ou seja, uma matriz de componentes do tipo SC, então:
 * Se T é um tipo de classe, T deve ser Objeto.
 * Se T é um tipo de interface, T deve ser uma das interfaces implementadas por matrizes.
 * Se T for um tipo de matriz TC [], ou seja, uma matriz de componentes do tipo TC, um dos seguintes deverá ser verdadeiro:
 * TC e SC são do mesmo tipo primitivo.
 * TC e SC são tipos de referência e o tipo SC pode ser convertido em TC por essas regras de tempo de execução.
 * 
 */
void manipulador_instanceof (Frame *frame){
    frame->pc += bytecodes[193].bytes + 1;
}

// 194 (0xC2)
/**
 * @brief Entrar o monitor para o objeto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O objectref deve ser de referência do tipo.
 * Cada objeto está associado a um monitor. Um monitor está bloqueado se e somente se tiver um proprietário. O encadeamento que executa o monitorenter tenta obter a propriedade do monitor associado ao objectref, da seguinte maneira:
 * Se a contagem de entradas do monitor associada ao objectref for zero, o encadeamento entra no monitor e define sua contagem de entradas como uma. O encadeamento é então o proprietário do monitor.
 * Se o encadeamento já possui o monitor associado ao objectref, ele entra novamente no monitor, aumentando sua contagem de entradas.
 * Se outro encadeamento já possuir o monitor associado ao objectref, o encadeamento será bloqueado até que a contagem de entradas do monitor seja zero e tente novamente obter a propriedade.
 */
void manipulador_monitorenter (Frame *frame){
    frame->pc += bytecodes[194].bytes + 1;
}

// 195 (0xC3)
/**
 * @brief Sai do monitor para objeto
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O objectref deve ser de referência do tipo.
 * O encadeamento que executa monitorexit deve ser o proprietário do monitor associado à instância referenciada por objectref.
 * O encadeamento diminui a contagem de entradas do monitor associado ao objectref. Se, como resultado, o valor da contagem de entradas for zero, o encadeamento sairá do monitor e não será mais seu proprietário. Outros threads que estão bloqueando a entrada no monitor podem tentar fazê-lo.
 */
void manipulador_monitorexit (Frame *frame){
    frame->pc += bytecodes[195].bytes + 1;
}

// 196 (0xC4)
/**
 * @brief Extende o índice de variável local em alguns bytes
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * A instrução ampla modifica o comportamento de outra instrução. É necessário um dos dois formatos, dependendo da instrução que está sendo modificada. A primeira forma da instrução ampla modifica uma das instruções iload, fload, aload, lload, dload, istore, fstore, astore, lstore, dstore ou ret. A segunda forma se aplica apenas à instrução iinc.
 * Em qualquer um dos casos, o próprio código de operação amplo é seguido no código compilado pelo código de operação da instrução de modificação ampla. Nos dois formatos, dois bytes não assinados indexbyte1 e indexbyte2 seguem o código de operação modificado e são montados em um índice não assinado de 16 bits em uma variável local no quadro atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. O índice calculado deve ser um índice na matriz de variáveis ​​locais do quadro atual. Onde a instrução ampla modifica uma instrução lload, dload, lstore ou dstore, o índice após o índice calculado (índice + 1) também deve ser um índice na matriz de variáveis ​​locais. No segundo formulário, dois bytes imediatos não assinados constbyte1 e constbyte2 seguem indexbyte1 e indexbyte2 no fluxo de código. Esses bytes também são montados em uma constante de 16 bits assinada, onde a constante é (constbyte1 << 8) | constbyte2.
 * O bytecode ampliado opera normalmente, exceto pelo uso do índice mais amplo e, no caso da segunda forma, pela maior faixa de incremento.
 */
void manipulador_wide (Frame *frame){
    u1 opcode = frame->get_prox_byte();
    u1 byte_1 = frame->get_prox_byte();
    u1 byte_2 = frame->get_prox_byte();

    u2 indice = (byte_1 << 8) | byte_2;

    // xload
    {
        if (!bytecodes[opcode].mnemonico.compare("iload"))
            return manipulador_xload2_n(frame, indice, TAG_INT);

        if (!bytecodes[opcode].mnemonico.compare("fload"))
            return manipulador_xload2_n(frame, indice, TAG_FLT);

        if (!bytecodes[opcode].mnemonico.compare("aload"))
            return manipulador_xload2_n(frame, indice, TAG_REF);

        if (!bytecodes[opcode].mnemonico.compare("lload"))
            return manipulador_xload2_n(frame, indice, TAG_LNG);

        if (!bytecodes[opcode].mnemonico.compare("dload"))
            return manipulador_xload2_n(frame, indice, TAG_DBL);
    }

    // xstore
    {
        if (!bytecodes[opcode].mnemonico.compare("istore"))
            return manipulador_xstore2_n(frame, indice, TAG_INT);

        if (!bytecodes[opcode].mnemonico.compare("fstore"))
            return manipulador_xstore2_n(frame, indice, TAG_FLT);

        if (!bytecodes[opcode].mnemonico.compare("astore"))
            return manipulador_xstore2_n(frame, indice, TAG_REF);

        if (!bytecodes[opcode].mnemonico.compare("lstore"))
            return manipulador_xstore2_n(frame, indice, TAG_LNG);

        if (!bytecodes[opcode].mnemonico.compare("dstore"))
            return manipulador_xstore2_n(frame, indice, TAG_DBL);
    }

    u1 valor_1 = frame->get_prox_byte();
    u1 valor_2 = frame->get_prox_byte();
    int16_t valor = (valor_1 << 8) | valor_2;

    manipulador_iincx(frame, indice, valor);
}

// 197 (0xC5)
/**
 * @brief Criar um novi array multidimensional
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O operando de dimensões é um byte sem sinal que deve ser maior ou igual a 1.
 * Representa o número de dimensões da matriz a ser criada.
 * A pilha de operandos deve conter valores de dimensões. 
 * Cada um desses valores representa o número de componentes em uma dimensão da matriz a ser criada, deve ser do tipo inteiro e não ser negativo. 
 * O count1 é o comprimento desejado na primeira dimensão, o count2 na segunda, etc.
 * Todos os valores de contagem são retirados da pilha de operandos.
 * O indexbyte1 e indexbyte2 sem sinal o são usados ​​para construir um índice no constant poola de tempo de execução da classe atual, em que o valor do índice é (indexbyte1 << 8) | indexbyte2. 
 * O item de constant pool em tempo de execução no índice deve ser uma referência simbólica a uma classe, matriz ou tipo de interface. 
 * A classe, matriz ou tipo de interface nomeado é resolvido 
 * A entrada resultante deve ser um tipo de dimensionalidade de classe de matriz maior ou igual a dimensões.
 * Uma nova matriz multidimensional do tipo de matriz é alocada a partir do heap coletado pelo lixo. 
 * Se qualquer valor de contagem for zero, nenhuma dimensão subsequente será alocada. Os componentes da matriz na primeira dimensão são inicializados em sub-matrizes do tipo da segunda dimensão e assim por diante.
 * Os componentes da última dimensão alocada da matriz são inicializados com o valor inicial padrão para o tipo de elemento do tipo de matriz.
 * Uma matriz de referênciaref para a nova matriz é enviada para a pilha de operandos.
 */
void manipulador_multianewarray (Frame *frame){
    frame->pc += bytecodes[197].bytes + 1;
}

// 198 (0xC6)
/**
 * @brief Faz um pulo se a referência for nula
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O valor deve ser do tipo referência. É retirado da pilha de operandos. Se o valor for nulo, o branchbyte1 e o branchbyte2 não assinados são usados ​​para construir um deslocamento assinado de 16 bits, onde o deslocamento é calculado para ser (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do código de operação desta instrução nula. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém essa instrução nula.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução nula.
 */
void manipulador_ifnull (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if (!op->tipo_int) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 199 (0xC7)
/**
 * @brief Faz um pulo se a referência não for nula
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O valor deve ser do tipo referência. É retirado da pilha de operandos. Se o valor não for nulo, o branchbyte1 e o branchbyte2 não assinados serão usados ​​para construir um deslocamento assinado de 16 bits, onde o deslocamento é calculado como sendo (branchbyte1 << 8) | branchbyte2. A execução prossegue nesse deslocamento a partir do endereço do opcode desta instrução ifnonnull. O endereço de destino deve ser o código de operação de uma instrução dentro do método que contém esta instrução ifnonnull.
 * Caso contrário, a execução continuará no endereço da instrução após esta instrução nula.
 */
void manipulador_ifnonnull (Frame *frame){
    Operando *op = frame->desempilhar();
    int16_t deslocamento = 3;

    if (op->tipo_int) {
        deslocamento = get_deslocamento(frame);
    }    frame->pc += deslocamento;
}

// 200 (0xC8)
/**
 * @brief Faz um pulo sempre
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * Os bytes sem sinal branchbyte1, branchbyte2, branchbyte3 e branchbyte4 são usados para construir um branchoffset de 32 bits com sinal,
 * em que branchoffset é (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4
 * O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução goto_w
 */
void manipulador_goto_w (Frame *frame){
    u4 byte_1 = frame->attr_codigo->codigo[frame->pc + 1];
    u4 byte_2 = frame->attr_codigo->codigo[frame->pc + 2];
    u4 byte_3 = frame->attr_codigo->codigo[frame->pc + 3];
    u4 byte_4 = frame->attr_codigo->codigo[frame->pc + 4];

    u4 deslocamento = (byte_1 << 24) | (byte_2 << 16) | (byte_3 << 8) | byte_4;
    frame->pc += deslocamento;
}


// 201 (0xC9)
/**
 * @brief Faz um pulo para uma subrotina
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * O endereço do código de operação da instrução imediatamente após esta instrução jsr_w é inserido na pilha de operandos como um valor do tipo returnAddress. O branchbyte1 não assinado, branchbyte2, branchbyte3 e branchbyte4 são usados ​​para construir um deslocamento assinado de 32 bits, onde o deslocamento é (branchbyte1 << 24) | (branchbyte2 << 16) | (branchbyte3 << 8) | branchbyte4. A execução continua nesse deslocamento a partir do endereço desta instrução jsr_w. O endereço de destino deve ser o de um código de operação de uma instrução dentro do método que contém esta instrução jsr_w.
 */
void manipulador_jsr_w (Frame *frame){
    Operando *op = new Operando();
    op->tipo_byte = frame->pc;
    frame->empilhar(op);

    u4 byte_1 = frame->attr_codigo->codigo[frame->pc + 1];
    u4 byte_2 = frame->attr_codigo->codigo[frame->pc + 2];
    u4 byte_3 = frame->attr_codigo->codigo[frame->pc + 3];
    u4 byte_4 = frame->attr_codigo->codigo[frame->pc + 4];

    u4 deslocamento = (byte_1 << 24) | (byte_2 << 16) | (byte_3 << 8) | byte_4;

    frame->pc += deslocamento;
}

// 202 (0xCA)
/**
 * @brief Breakpoint para uso de desenvolvedores
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * Utilizado para achar e consertar bugs no código. Opcode reservado.
 */
void manipulador_break_point (Frame *frame){
    //RESERVADO DO JAVA
    frame->pc += bytecodes[202].bytes + 1;
}

// 254 (0xFE)
/**
 * @brief Opcode reservado
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * Essas instruções fornecem "back doors" e "traps" para funcionalidades específicas da implementação do software e hardware
 */
void manipulador_impdep_1 (Frame *frame){
    //RESERVADO DO JAVA
    frame->pc += bytecodes[254].bytes + 1;
}

// 255 (0xFF)
/**
 * @brief Opcode reservado
 * 
 * @param frame Recebe o frame que é relacionado com o método e contém o array de variáveis locais, pilha de operandos, referência para tabela de símbolos.
 * 
 * Essas instruções fornecem "back doors" e "traps" para funcionalidades específicas da implementação do software e hardware
 */
void manipulador_impdep_2 (Frame *frame){
    //RESERVADO DO JAVA
    frame->pc += bytecodes[255].bytes + 1;
}
