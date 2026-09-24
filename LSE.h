#ifndef LSE_H
#define LSE_H

//Declaração de funções da Lista Sequencial Estática.

typedef int LSE_Tipo;

//tipo opaco da LSE
typedef struct lse LSE;

//Cria uma lista vazia
LSE *lse_cria(void);
//destroi a lista
int lse_destroi(LSE **l);
//Verifica se a lista está vaiza
int lse_vazia(const LSE *l);
//Verifica se a a lista esta cheia
int lse_cheia(const LSE *l);
//Retorna o tamanho da lista
int lse_tamanho(const LSE *l);
//insere um elemento no final
int lse_insere_final(LSE *l, LSE_Tipo elem);
//insere um elemento em uma posição
int lse_insere_pos(LSE *l,int pos, LSE_Tipo elem);
//remove o elemento de uma posição
int lse_remove_pos(LSE *l,int pos,LSE_Tipo *removido);
//consulta o elemento de uma posição 
int lse_consulta_pos(const LSE *l, int pos, LSE_Tipo *elem);
//busca um elemento na lista
int lse_busca(const LSE *l, LSE_Tipo elem, int *pos);
//remove todos os elementos da lista
int lse_limpa(LSE *l);
//imprime todos os elementos da lista
int lse_imprime(const LSE *l);
#endif