;-------------------------------------------------------------------------------
;   Finalidade:     Geração de números pseudo-aleatórios com o algoritmo
;                   LSFR de 24-bits
;-------------------------------------------------------------------------------
%include "asm_io.inc"
;-------------------------------------------------------------------------------
; Variáveis definidas
;-------------------------------------------------------------------------------
segment .data
;-------------------------------------------------------------------------------
; Variáveis reservadas
;-------------------------------------------------------------------------------
segment .bss
;-------------------------------------------------------------------------------
; Programa
;-------------------------------------------------------------------------------
        global calc_lfsr_asm
segment .text

calc_lfsr_asm:
        mov     EAX, [ESP + 4]     ; A semente

        mov     EDX, EAX
        shr     EDX, 0
        mov     ECX, EDX            ; ECX = EDX >> 0 (lfsr = seed >> 0)

        mov     EDX, EAX
        shr     EDX, 1
        xor     ECX, EDX            ; ECX ^= EDX >> 16 (lfsr ^= seed >> 16)

        mov     EDX, EAX
        shr     EDX, 2
        xor     ECX, EDX            ; ECX ^= EDX >> 21 (lfsr ^= seed >> 21)

        mov     EDX, EAX
        shr     EDX, 3
        xor     ECX, EDX            ; ECX ^= EDX >> 22 (lfsr ^= seed >> 22)

        mov     EDX, EAX
        shr     EDX, 23
        xor     ECX, EDX            ; ECX ^= EDX >> 23 (lfsr ^= seed >> 23)
        and     ECX, 0x1            ; ECX &= 0x1 (lfsr &= 0x1)

        shr     EAX, 1              ; EAX >> 1 (seed >> 1)
        shl     ECX, 23             ; ECX << 23 (lfsr << 23)
        or      EAX, ECX            ; EAX |= ECX (lsfr | seed)

        ret

; 32   28   24   20   16   12   8    4
; 0000 0000 1110 0001 0000 0000 0000 0001
; 0    0    E    1    0    0    0    1
