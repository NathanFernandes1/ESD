/*a. Faça a função horario que receba um parâmetro (inteiro por valor) com o total de
minutos de um evento e receba também dois parâmetros (inteiros por referência) no
qual deve preencher a quantidade de hora e de minutos equivalente. Por exemplo:
145 minutos equivale a 2 h e 25 min. Esta função deverá OBRIGATORIAMENTE chamar
a função DivisaoInteira
b. Faça um programa que leia o tempo de treino (em minutos) de 10 atletas, mostrando
a cada um, o tempo de treino no formato hh:mm. (utilize a função do item a).
No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram*/

#include <stdio.h>
#include <string.h>

#define TAM 3

struct tat {
    int tempo;
    char nome[20];
};
typedef struct tat tAtleta;

void obtemAtleta(int num, tAtleta *atleta);
int divisaoInteira(int dividendo, int divisor, int *quoc, int *resto);
void horario(int tempo, int *horas, int *minutos);
void bubbleSortTempo(tAtleta vAtletas[], int tamanho);
void exibeAtletas(tAtleta vAtletas[], int tamanho);

int main(void) {
    tAtleta vAtletas[TAM];
    int contador, opcao;

    // Coleta os dados dos atletas
    for (contador = 0; contador < TAM; contador++) {
        obtemAtleta(contador + 1, &vAtletas[contador]);
    }

    // Exibir vetor original
    printf("\n Atletas cadastrados (Ordem original):\n");
    exibeAtletas(vAtletas, TAM);

    bubbleSortTempo(vAtletas, TAM);
    printf("\n Atletas ordenados por tempo (Bubble Sort):\n");
    exibeAtletas(vAtletas, TAM);
   
}

void obtemAtleta(int num, tAtleta *atleta) {
    printf("\nDigite o nome do %dº atleta: ", num);
    scanf(" %[^\n]", atleta->nome);

    printf("Digite o tempo (minutos) do %dº atleta: ", num);
    scanf("%d", &atleta->tempo);
}

void bubbleSortTempo(tAtleta vAtletas[], int tamanho) {
    int i, j;
    tAtleta temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vAtletas[j].tempo > vAtletas[j + 1].tempo) {
                temp = vAtletas[j];
                vAtletas[j] = vAtletas[j + 1];
                vAtletas[j + 1] = temp;
            }
            	else if(vAtletas[j].tempo == vAtletas[j + 1].tempo){
            		if (strcmp(vAtletas[j].nome, vAtletas[j + 1].nome) > 0) {
                	temp = vAtletas[j];
                	vAtletas[j] = vAtletas[j + 1];
                	vAtletas[j + 1] = temp;
            }
				}
        }
    }
}


void exibeAtletas(tAtleta vAtletas[], int tamanho) {
    int i, horas, minutos;
    for (i = 0; i < tamanho; i++) {
        horario(vAtletas[i].tempo, &horas, &minutos);
        printf("Nome: %s, Tempo: %dh:%dmin\n", vAtletas[i].nome, horas, minutos);
    }
}

void horario(int tempo, int *horas, int *minutos) {
    divisaoInteira(tempo, 60, horas, minutos);
}

int divisaoInteira(int dividendo, int divisor, int *quoc, int *resto) {
    if (divisor == 0) {
        if (dividendo == 0) return -1;
        else return 0;
    } else {
        *quoc = dividendo / divisor;
        *resto = dividendo % divisor;
        return 1;
    }
}
