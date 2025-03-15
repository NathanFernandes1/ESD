#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Conjunto.h"

struct conj {
     int vet[80];
     int qtElem;
};

    Conjunto* conj_cria(){
	Conjunto * p = (Conjunto*) malloc(sizeof(Conjunto));
    p->qtElem=0;
	return p;
}
 Conjunto * conj_insere(Conjunto *c , int num){ //insere um novo elemento num conjunto ja criado
	
	if (conj_busca(c, num)!=1) {  
        
	if (c->qtElem <80){
		c->vet[c->qtElem]=num;
		c->qtElem++;
		printf("Valor inserido\n");
		return c;
	}

	}
	    printf("Valor não inserido\n");
		return c;
}
 int conj_busca(Conjunto *c , int num){
    int i;
    if(c->qtElem == 0){
        printf ("\n\nConjunto vazio, ensira valores.\n");
        return -1;
    }
    else{
        for(i=0; i<c->qtElem; i++){
        if(num == c->vet[i]){
            printf("Valor encontrado \n");
            return 1;
        }
    }
    printf("Valor nao encontrado ");
    return -1;
    }
    
}

void conj_exibe(Conjunto *c){
    int i;
    if(c->qtElem ==0){
        printf ("\n\nConjunto vazio, ensira valores.\n");
    }
    else{
        printf("Valores do conjundo:\n");
        for(i=0; i<c->qtElem; i++){
        
            printf("%d ",c->vet[i]);
            
        }
        
    }
    printf("\n\n");
}

Conjunto * conj_remove(Conjunto *c,int num){
    int i, aux, y;
    if(c->qtElem ==0){
        printf ("Conjunto vazio.\n");
        return c;
    }
    else {
        for(i=0; i<c->qtElem; i++){
        if(num == c->vet[i]){
            for(y=i;y<c->qtElem-1;y++){
                c->vet[y]= c->vet[y+1];
            }
            printf("\nValor removido.");
            c->qtElem--;
        }
        }
        return c;
    }
}

Conjunto *conj_intersecao(Conjunto *c, Conjunto *c2){
    Conjunto *intersecao_conj;
    intersecao_conj=conj_cria();
    int i, y, cont=0;
    
    if(c->qtElem ==0|| c2->qtElem ==0 ){
        printf ("Conjunto vazio.\n");
        return intersecao_conj;
    }
    else{
    for(i=0;i<c->qtElem;i++){
        for(y=0;y<c2->qtElem;y++){
            if(c->vet[i]==c2->vet[y]){
                intersecao_conj->vet[intersecao_conj->qtElem] = c->vet[i];
                intersecao_conj->qtElem++;
                break;
            }
        }
    }
    
    printf("\nIntersecao\n");
    conj_exibe(intersecao_conj);
    return intersecao_conj;
    }
}

Conjunto *conj_uniao(Conjunto *c, Conjunto *c2){
    Conjunto *uniao_conj;
    uniao_conj=conj_cria();
    int i, y, cont=0;
    
    if(c->qtElem == 0&& c2->qtElem ==0 ){
        printf ("Conjuntos vazios.\n");
        return uniao_conj;
    }
    else{
    for(i=0;i<c->qtElem;i++){
        conj_insere(uniao_conj,c->vet[i]);
    }
    
    for(i=0;i<c2->qtElem;i++){
       
        conj_insere(uniao_conj,c2->vet[i]);
    }
    
    printf("\nUniao:");
    conj_exibe(uniao_conj);
    return uniao_conj;
    }
}