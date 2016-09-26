/*************** Interface da Fila Dinâmica Configurada ***************/
/***** Nome: fila_dinamica.h *****/

#ifndef _FILA_DINAMICA
#define _FILA_DINAMICA

/******** Inclusão do Ficheiro de Interface do Elemento da Fila ********/

#include "elemento.h"

/************** Definição do Tipo Ponteiro para uma Fila **************/

typedef struct queue *PtQueue;

/******************** Definição de Códigos de Erro ********************/

#define	OK           0  /* operação realizada com sucesso */
#define	NO_QUEUE     1  /* fila inexistente */
#define	NO_MEM       2  /* memória esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	QUEUE_EMPTY  4  /* fila vazia */

/********************* Protótipos dos Subprogramas ********************/

PtQueue QueueCreate (void);
/* Cria uma fila. Devolve a referência da fila criada ou NULL em caso de inexistência de memória. */

int QueueDestroy (PtQueue *pqueue);
/* Destrói a fila referenciada por pqueue e coloca a referência a NULL. Valores de retorno: OK ou NO_QUEUE. */

int QueueEnqueue (PtQueue pqueue, TELEM pelem);
/* Coloca pelem na cauda da fila referenciada por pqueue. Valores de retorno: OK, NO_QUEUE ou NO_MEM. */

int QueueDequeue (PtQueue pqueue, TELEM *pelem);
/* Retira o elemento da cabeça da fila referenciada por pqueue. Valores de retorno: OK, NO_QUEUE, QUEUE_EMPTY ou NULL_PTR. */

#endif
