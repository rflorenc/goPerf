/*************** Interface da Fila Din�mica Configurada ***************/
/***** Nome: fila_dinamica.h *****/

#ifndef _FILA_DINAMICA
#define _FILA_DINAMICA

/******** Inclus�o do Ficheiro de Interface do Elemento da Fila ********/

#include "elemento.h"

/************** Defini��o do Tipo Ponteiro para uma Fila **************/

typedef struct queue *PtQueue;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK           0  /* opera��o realizada com sucesso */
#define	NO_QUEUE     1  /* fila inexistente */
#define	NO_MEM       2  /* mem�ria esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	QUEUE_EMPTY  4  /* fila vazia */

/********************* Prot�tipos dos Subprogramas ********************/

PtQueue QueueCreate (void);
/* Cria uma fila. Devolve a refer�ncia da fila criada ou NULL em caso de inexist�ncia de mem�ria. */

int QueueDestroy (PtQueue *pqueue);
/* Destr�i a fila referenciada por pqueue e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_QUEUE. */

int QueueEnqueue (PtQueue pqueue, TELEM pelem);
/* Coloca pelem na cauda da fila referenciada por pqueue. Valores de retorno: OK, NO_QUEUE ou NO_MEM. */

int QueueDequeue (PtQueue pqueue, TELEM *pelem);
/* Retira o elemento da cabe�a da fila referenciada por pqueue. Valores de retorno: OK, NO_QUEUE, QUEUE_EMPTY ou NULL_PTR. */

#endif
