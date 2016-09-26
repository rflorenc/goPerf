/**** Interface da Fila com Prioridade Dinâmica Linear Configurada ****/
/***** Nome: fila_prioridade_dinamica.h *****/

#ifndef _FILA_PRIORIDADE_DINAMICA
#define _FILA_PRIORIDADE_DINAMICA

/************ Inclusão do Ficheiro de Interface do Elemento ************/

#include "elemento_cam.h"

/******* Definição do Tipo Ponteiro para uma Fila com Prioridade *******/

typedef struct pqueue *PtPQueue;

/******************** Definição de Códigos de Erro ********************/

#define  OK        0  /* operação realizada com sucesso */
#define  NO_PQ     1  /* fila com prioridade inexistente */
#define  NO_MEM    2  /* memória esgotada */
#define  NULL_PTR  3  /* ponteiro nulo */
#define  PQ_EMPTY  4  /* fila com prioridade vazia */
#define  NO_KEY    6  /* elemento com a chave indicada inexistente */
#define  NO_FUNC   7  /* função de comparação não comunicada */

/********************* Protótipos dos Subprogramas ********************/

PtPQueue PQCreate (TPFC pfcomp);
/* Cria uma fila com prioridade e armazena a função de comparação dos elementos. Devolve a referência da fila com prioridade criada ou NULL em caso de inexistência de memória ou da função de comparação. */

int PQDestroy (PtPQueue *ppqueue);
/* Destrói a fila com prioridade referenciada por ppqueue e coloca a referência a NULL. Valores de retorno: OK ou NO_PQ. */

int PQInsert (PtPQueue ppqueue, TELEM *pelem);
/* Insere o elemento pelem, na fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NO_MEM, NULL_PTR ou NO_FUNC. */

int PQDeleteMax (PtPQueue ppqueue, TELEM *pelem);
/* Retira o elemento com a maior chave da fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NULL_PTR, PQ_EMPTY ou NO_FUNC. */

#endif
