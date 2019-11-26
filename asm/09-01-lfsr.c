#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include "cdecl.h"


/** Tipo básico para 1 byte sem sinal */
typedef uint8_t u1;
/** Tipo básico para 4 bytes sem sinal */
typedef uint32_t u4;


/** Período máximo para um número de 24-bits */
#define MAX_PERIODO     16777216
/** Quantidade de grupos a serem considerados para o teste Chi-Quadrado */
#define QNT_GRUPOS      16
/** Frequência esperada em cada grupo */
#define FREQ_ESP        (MAX_PERIODO / QNT_GRUPOS)
/** Quant. de bits a serem considerados */
#define N_BITS          23
/** Quant. de semestes */
#define QNT_SEMENTES    20
/** Máxima semente de 24-bits */
#define MASK    0x00FFFFFF

u4 gerar_sementes();
void limpar_freq (u4 *freq);
u4 calc_lfsr_c(u4 semente);
u4 PRE_CDECL calc_lfsr_asm (u4 semente) POST_CDECL;
void calc_freq(u4 (*calc_lfsr) (u4), u4*, u4);
double chi_quadrado (u4 *freq_obs, u4 freq_esp, u1 n);
void interface_lfsr(u4 (*calc_lfsr) (u4), u4 *freq, u4 semente, char *identificador);

int main(){
    u4 freq_obs[QNT_GRUPOS];

    srand(time(0));

    for (u1 cnt = 0; cnt < QNT_SEMENTES; cnt++){
        u4 semente = gerar_sementes();
        printf("Processando lfsr de 24-bits para a %dº semente: 0x%08X\n", cnt + 1, semente);
        interface_lfsr(calc_lfsr_c, freq_obs, semente, "C");
        interface_lfsr(calc_lfsr_asm, freq_obs, semente, "ASM");
        printf("\n");
    }

    return 0;
}

u4 gerar_sementes(){
    return rand() % MASK;
}

void limpar_freq (u4 *freq){
    for (u1 cnt = 0; cnt < QNT_GRUPOS; cnt ++)
        freq[cnt] = 0;
}

u4 calc_lfsr_c(u4 semente) {
    // x^1 + x^17 + x^22 + x^23 + x^24
    u4 bit;

    bit = (semente >> 0);
    bit ^= (semente >> 1);
    bit ^= (semente >> 2);
    bit ^= (semente >> 3);
    bit ^= (semente >> 23);
    bit &= 0x1;

    return ((semente >> 1) | (bit << 23));
}

void calc_freq(u4 (*calc_lfsr) (u4), u4* freq, u4 init_seed) {
    u4 periodo = 0, semente = init_seed;

    do {
        u4 lfsr = calc_lfsr(semente);
        freq[lfsr / FREQ_ESP]++;
        periodo++;
        semente = lfsr;
    }while (periodo < MAX_PERIODO);
}

double chi_quadrado(u4 *freq_obs, u4 freq_esp, u1 n){
    double chi_quadrado = 0;

    for (u1 cnt = 0; cnt < n; cnt++){
        printf("\tGrupo [%d]:\n", cnt);
        printf("\t\tFreq. esperada: %u\n", freq_esp);
        printf("\t\tFreq. observada: %u\n", freq_obs[cnt]);
        chi_quadrado += pow(abs(freq_obs[cnt] - freq_esp), 2) / freq_esp;
    }

    return chi_quadrado;
}

void interface_lfsr(u4 (*calc_lfsr) (u4), u4 *freq, u4 semente, char *identificador){
    clock_t duracao;
    limpar_freq(freq);

    printf("\nLinguagem: %s\n", identificador);

    duracao = clock();
    calc_freq(calc_lfsr, freq, semente);
    duracao = clock() - duracao;

    double chi_quadrado_valor = chi_quadrado(freq, FREQ_ESP, QNT_GRUPOS);

    printf("\tDuração: %.2f seg\n", ((double) duracao) / CLOCKS_PER_SEC);
    printf("\tChi-quadrado: %.2lf\n", chi_quadrado_valor);
}


