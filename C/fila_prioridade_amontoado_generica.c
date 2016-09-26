/********* Interface da Fila com Prioridade Amontoado Genérica *********/
/***** Nome: fila_prioridade_amontoado_generica.h *****/

#ifndef _FILA_PRIORIDADE_AMONTOADO_GENERICA
#define _FILA_PRIORIDADE_AMONTOADO_GENERICA

/******* Definição do Tipo Ponteiro para uma Fila com Prioridade *******/

typedef struct pqueue *PtPQueue;

/******************** Definição de Códigos de Erro ********************/

#define  OK        0  /* operação realizada com sucesso */
#define  NO_PQ     1  /* fila com prioridade inexistente */
#define  NO_MEM    2  /* memória esgotada */
#define  NULL_PTR  3  /* ponteiro nulo */
#define  PQ_EMPTY  4  /* fila com prioridade vazia */
#define  PQ_FULL   5  /* fila com prioridade cheia */
#define  NO_KEY    6  /* elemento com a chave indicada inexistente */

/********************* Protótipos dos Subprogramas ********************/

PtPQueue PQCreate (unsigned int pdim, unsigned int pesize, unsigned int pksize);
/* Cria uma fila com prioridade com capacidade para armazenar pdim elementos com pesize bytes, sendo que a chave do elemento ocupa pksize bytes. Devolve a referência da fila com prioridade criada ou NULL em caso de inexistência de memória, se pdim for nulo, se pesize for nulo ou se pksize for nulo. */

int PQDestroy (PtPQueue *ppqueue);
/* Destrói a fila com prioridade referenciada por ppqueue e coloca a referência a NULL. Valores de retorno: OK ou NO_PQ. */

int PQInsert (PtPQueue ppqueue, void *pelem);
/* Insere o elemento pelem, na fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NULL_PTR ou PQ_FULL. */

int PQDeleteMax (PtPQueue ppqueue, void *pelem);
/* Retira o elemento com a maior chave da fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NULL_PTR ou PQ_EMPTY. */

#endif
