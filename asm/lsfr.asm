;-------------------------------------------------------------------------------
;   Finalidade:     Geração de números pseudo-aleatórios com o algoritmo
;                   LSFR de 24-bits
;-------------------------------------------------------------------------------
%include "asm_io.inc"
;-------------------------------------------------------------------------------
; Definições, cópias do prog em C
;-------------------------------------------------------------------------------
%define MAX_PERIODO 16777216
%define QNT_GRUPOS  16
%define FREQ_ESP    (MAX_PERIODO / QNT_GRUPOS)
%define N_BITS      23
;-------------------------------------------------------------------------------
; Variáveis definidas
;-------------------------------------------------------------------------------
segment .data
;-------------------------------------------------------------------------------
; Variáveis reservadas
;-------------------------------------------------------------------------------
segment .bss
    lsfr        resd    1
    resultado   resd    1
    periodo     resd    1
    bit         resw    1
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
        ENTER   0,0
        PUSHA

        PUSH    EBP
        MOV     EBP, ESP

        ; CÓDIGO AQUI
        ; MOV     EBX, [EBP]          ; Endereço de endereço
        ; MOV     EBX, [EBX + 8]      ; A freq. está vindo como último parâmetro
        MOV     EBX, [EBP]
        MOV     EBX, [EBX + 12]     ; A semente
        MOV     [lsfr], EBX
        MOV     EDX, 0
        MOV     EDX, [lsfr]
        RCR     EDX, 1
        SALC
        AND     AL, 0x01
        MOV     CL, AL
        dump_regs 1

        MOV     EDX, [lsfr]
        RCR     EDX, 17
        SALC
        AND     AL, 0x01
        XOR     AL, CL
        MOV     CL, AL
    ;     MOV     [bit], word 0
    ;     MOV     EDX, 0
    ; .lsfr_loop:
    ;     MOV     CL, 20
    ;     MOV     EAX, [lsfr]
    ;     RCR     EAX, CL
    ;     SALC
    ;     XOR     AL, 0x01
    ;     ADD     AL, [bit]
    ;     MOV     [bit], word AL
    ;     MOV     DL, [bit]
        dump_regs 2

        ; MOV     EAX, 0
        ; SALC
        ; CALL    print_int
        ; CALL    print_nl

        POP     EBP

        POPA
        ; mov     eax, 0            ; Só se tiver retorno
        LEAVE
        RET

; 32   28   24   20   16   12   8    4
; 0000 0000 1110 0001 0000 0000 0000 0001
; 0    0    E    1    0    0    0    1
