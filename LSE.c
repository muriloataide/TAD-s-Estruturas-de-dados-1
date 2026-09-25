#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

#define MAX 1000

//Implementação das funções da Lista Sequencial Estática

struct lse{
    LSE_Tipo dados[MAX];
    int qtd;
};

LSE *lse_cria(void){
    LSE *l = malloc(sizeof(LSE));
    if(!l){
        return NULL;
    }
    l->qtd = 0;
    return l;
}

int lse_destroi(LSE **l){
    if(!l){
        return -1;
    }
    free(*l);
    *l = NULL;

    return 1;
}

int lista_vazia(const LSE *l){
    if(!l){
        return -1;
    }
    if(l->qtd == 0){
        return 1;
    }
    return 0;
}

int lse_cheia(const LSE *l){
    if(!l){
        return -1;
    }
    if(l->qtd == MAX){
        return 1;
    }
    return 0;
}

int lse_tamanho(const LSE *l){
    if(!l){
        return -1;
    }
    return l->qtd;
}

int lse_insere_final(LSE *l, LSE_Tipo elem){
    if(!l){
        return -1;
    }
    if(lse_cheia(l) == 1){
        return 0;
    }
    l->dados[l->qtd] = elem;
    l->qtd++;
    return 1;
}

int lse_insere_pos(LSE *l,int pos, LSE_Tipo elem){
    if(!l){
        return -1;
    }
    if(lse_cheia(l)){
        return 0;
    }
    if(pos < 0 || pos > l->qtd){
        return 0;
    }
    for(int i = l->qtd; i > pos; i--){
        l->dados[i] = l->dados[i-1]; 
    }

    l->dados[pos] = elem;
    l->qtd++;

    return 1;
}

int lse_remove_pos(LSE *l, int pos, LSE_Tipo *removido){
    if(!l){
        return -1;
    }
    
    if(pos < 0 || pos >= l->qtd){
        return -1;
    }

    if(removido != NULL){
        *removido = l->dados[pos];
    }

    for(int i = pos; i < l->qtd - 1; i++){
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;

    return 1;
}

int lse_consulta_pos(const LSE *l, int pos, LSE_Tipo *elem){
    if(!l || !elem){
        return -1;
    }

    if(pos < 0 || pos >= l->qtd){
        return -1;
    }

    *elem = l->dados[pos];

    return 1;
}

int lse_busca(const LSE *l,LSE_Tipo elem, int *pos){
    if(!l || !pos){
        return -1;
    }

    *pos = -1;

    for(int i = 0; i < l->qtd; i++){
        if(l->dados[i] == elem){
            *pos = i;
            return 1;
        }
    }
    return 0; //caso não encontrado
}

int lse_limpa(LSE *l){
    if(!l){
        return -1;
    }

    l->qtd = 0;
    return 1;
}

int lse_imprime(const LSE *l){
    if(!l){
        return -1;
    }
    printf("["); //alteração realizada para formato esperado em exercício de sala de aula
    for(int i = 0; i < l->qtd-1; i++){
        printf("%d, ",l->dados[i]);
    }
    if(lista_vazia(l) != 1){                    //alteracoes feitas para
        printf("%d]\n",l->dados[l->qtd-1]);     //formato de exercício
    }       
    else{
        printf("]\n");
    }                               
    return 1;
}

