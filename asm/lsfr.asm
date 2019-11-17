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
segment .text
    %ifdef LINUX                    ; Linha 148 do Makefile
        global  calc_lsfr_asm
    calc_lsfr_asm:
    %else
        global  _calc_lsfr_asm
    _calc_lsfr_asm:
    %endif
        enter   0,0
        pusha

        push    EBP
        mov     EBP, ESP

        ; CÓDIGO AQUI
        mov     EBX, [EBP]          ; Endereço de endereço
        mov     EBX, [EBX + 8]      ; A freq. está vindo como último parâmetro
        mov     EBX, [EBP]
        mov     EAX, [EBX + 12]     ; A semente

        pop     EBP

        popa
        ; mov     eax, 0            ; Só se tiver retorno
        leave
        ret

; 32   28   24   20   16   12   8    4
; 0000 0000 1110 0001 0000 0000 0000 0001
; 0    0    E    1    0    0    0    1
