#include<stdio.h>
#include "Conjunto.h"

//ALUNO: NATHAN FERNANDES DE ALMEIDA
int main(){
    
    Conjunto *jose_ferias= conj_cria();
    Conjunto *marlene_ferias= conj_cria();
    Conjunto *valeria_ferias= conj_cria();
    Conjunto *intersecao_jose_marlene= conj_cria();
    Conjunto *intersecao_final= conj_cria();

    for (int i=2; i<=28; i++) {
        conj_insere(jose_ferias, i);
    }
    for (int i=5; i<=30; i++) {
        conj_insere(marlene_ferias, i);
    }
    for (int i=1; i<=25; i++) {
        conj_insere(valeria_ferias, i);
    }

    //interseção entre José e Marlene
    intersecao_jose_marlene= conj_intersecao(jose_ferias, marlene_ferias);

    //interseção entre o resultado da primeira interseção e Valéria
   intersecao_final=conj_intersecao(intersecao_jose_marlene, valeria_ferias);

    //periodo de viagem em familia
    printf("Período comum para a família viajar: ");
    conj_exibe(intersecao_final);
    
    
    
    /*Conjunto *c1, *c2;
    
    c1=conj_cria();
    conj_insere(c1, 1);
    conj_insere(c1, 2);
    conj_insere(c1, 3);
    conj_insere(c1, 4);
    conj_insere(c1, 5);
    conj_exibe(c1);
   // conj_remove(c1, 1);
   // conj_exibe(c1);
    
    c2=conj_cria();
    conj_insere(c2, 4);
    conj_insere(c2, 5);
    conj_insere(c2, 6);
    conj_insere(c2, 4);
    conj_insere(c2, 8);
    
    conj_intersecao(c1,c2);
    
    conj_uniao(c1,c2);*/
}