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
#define QNT_SEMENTES    1 //20
/** Máxima semente de 24-bits */
#define MAX_SEMENTE     0x00FFFFFF


u4 gerar_sementes();
void limpar_freq (u4 *freq);
void calc_lsfr_c (u4 *freq, u4 semente);
void PRE_CDECL calc_lsfr_asm (u4 *freq, u4 semente) POST_CDECL;
double chi_quadrado (u4 *freq_obs, u4 freq_esp, u1 n);
void interface_lsfr(void (*calc_lsfr) (u4 *, u4), u4 *freq, u4 semente, char *identificador);


int main(){
    u4 freq_obs[QNT_GRUPOS];

    srand(time(0));

    for (u1 cnt = 0; cnt < QNT_SEMENTES; cnt++){
        u4 semente = gerar_sementes();
        printf("Processando LSFR de 24-bits para a %dº semente: 0x%08X (0x%08X)\n", cnt + 1, 0x00E00001, 1 >> 2);

        // interface_lsfr(calc_lsfr_c, freq_obs, semente, "C");

        interface_lsfr(calc_lsfr_asm, freq_obs, semente, "ASM");

        printf("------------------------------------\n");
    }

    return 0;
}

u4 gerar_sementes(){
    return rand() % MAX_SEMENTE;
}

void limpar_freq (u4 *freq){
    for (u1 cnt = 0; cnt < QNT_GRUPOS; cnt ++)
        freq[cnt] = 0;
}

void calc_lsfr_c(u4 *freq, u4 semente){
    u4 lsfr = semente, resultado = 0, periodo = 0;
    u1 cnt = 0;

    do {
        u1 bit;
        bit = (lsfr >> 0) & 0x01;
        bit ^= (lsfr >> 19) & 0x01;
        bit ^= (lsfr >> 20) & 0x01;
        bit ^= (lsfr >> 22) & 0x01;
        bit ^= (lsfr >> 23) & 0x01;
        // printf("LSFR: 0x%08X, 0x%02X\n", lsfr, bit);

        resultado |= ((lsfr >> 0) & 0x01) << (N_BITS - cnt);

        lsfr = (lsfr >> 1) | (bit << 23);

        if (cnt == N_BITS){
            // printf("[%u] Gerou o número: 0x%08X -> 0x%08X\n", periodo, resultado, lsfr);
            // printf("[%u]\r", periodo);
            freq[resultado / FREQ_ESP]++;
            // getchar();
            cnt = resultado = 0;
            periodo++;
        } else
            cnt++;

    } while (periodo < MAX_PERIODO);
}

double chi_quadrado(u4 *freq_obs, u4 freq_esp, u1 n){
    double chi_quadrado = 0;

    for (u1 cnt = 0; cnt < n; cnt++){
        // printf("Freq. observada para o grupo [%d]: %u\n", cnt, freq_obs[cnt]);
        // printf("\tDiff: %d -> %d\n", freq_obs[cnt] - FREQ_ESP, abs(freq_obs[cnt] - FREQ_ESP));
        // printf("\tQuad: %.2lf\n", pow(abs(freq_obs[cnt] - FREQ_ESP), 2));
        // printf("\tParcela: %.2lf\n", pow(abs(freq_obs[cnt] - FREQ_ESP), 2) / FREQ_ESP);
        chi_quadrado += pow(abs(freq_obs[cnt] - freq_esp), 2) / freq_esp;
    }

    return chi_quadrado;
}

void interface_lsfr(void (*calc_lsfr) (u4 *, u4), u4 *freq, u4 semente, char *identificador){
    clock_t duracao;

    limpar_freq(freq);

    printf("\nLinguagem: %s\n", identificador);

    duracao = clock();
    calc_lsfr(freq, semente);
    duracao = clock() - duracao;

    printf("\tDuração: %.2f seg\n", ((double) duracao) / CLOCKS_PER_SEC);
    printf("\tChi-quadrado: %.2lf\n", chi_quadrado(freq, FREQ_ESP, QNT_GRUPOS));
}


