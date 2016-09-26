/******* Interface da Fila com Prioridade Amontoado Configurada *******/
/***** Nome: fila_prioridade_amontoado_configurada.h *****/

#ifndef _FILA_PRIORIDADE_AMONTOADO_CONFIGURADA
#define _FILA_PRIORIDADE_AMONTOADO_CONFIGURADA

/************ Inclus�o do Ficheiro de Interface do Elemento ************/

#include "elemento_cam.h"

/******* Defini��o do Tipo Ponteiro para uma Fila com Prioridade *******/

typedef struct pqueue *PtPQueue;

/******************** Defini��o de C�digos de Erro ********************/

#define  OK        0  /* opera��o realizada com sucesso */
#define  NO_PQ     1  /* fila com prioridade inexistente */
#define  NO_MEM    2  /* mem�ria esgotada */
#define  NULL_PTR  3  /* ponteiro nulo */
#define  PQ_EMPTY  4  /* fila com prioridade vazia */
#define  PQ_FULL   5  /* fila com prioridade cheia */
#define  NO_FUNC   7  /* fun��o de compara��o n�o comunicada */

/********************* Prot�tipos dos Subprogramas ********************/

PtPQueue PQCreate (unsigned int pdim, TPFC pfcomp);
/* Cria uma fila com prioridade com capacidade para armazenar pdim elementos e armazena a fun��o de compara��o dos elementos. Devolve a refer�ncia da fila com prioridade criada ou NULL em caso de inexist�ncia de mem�ria ou da fun��o de compara��o, ou se pdim for nulo. */

int PQDestroy (PtPQueue *ppqueue);
/* Destr�i a fila com prioridade referenciada por ppqueue e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_PQ. */

int PQInsert (PtPQueue ppqueue, TELEM *pelem);
/* Insere o elemento pelem, na fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NULL_PTR, PQ_FULL ou NO_FUNC. */

 
int PQDeleteMax (PtPQueue ppqueue, TELEM *pelem);
/* Retira o elemento com a maior chave da fila com prioridade referenciada por ppqueue. Valores de retorno: OK, NO_PQ, NULL_PTR, PQ_EMPTY ou NO_FUNC. */

#endif
