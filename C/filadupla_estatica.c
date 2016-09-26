/************ Interface da Fila Dupla Estática Configurada ************/
/***** Nome: filadupla_estatica.h *****/

#ifndef _FILADUPLA_ESTATICA
#define _FILADUPLA_ESTATICA

/***** Inclusão do Ficheiro de Interface do Elemento da Fila Dupla ****/

#include "elemento.h"

/***************** Definição da dimensão da Fila Dupla ****************/

#define MAX_ELEMENTOS 100

/*********** Definição do Tipo Ponteiro para uma Fila Dupla ***********/

typedef struct deque *PtDeque;

/******************** Definição de Códigos de Erro ********************/

#define	OK           0  /* operação realizada com sucesso */
#define	NO_DEQUE     1  /* Fila dupla inexistente */
#define	NO_MEM       2  /* memória esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	DEQUE_EMPTY  4  /* Fila dupla vazia */
#define	DEQUE_FULL   5  /* Fila dupla cheia */

/********************* Protótipos dos Subprogramas ********************/

PtDeque DequeCreate (void);
/* Cria uma fila dupla. Devolve a referência da fila dupla criada ou NULL em caso de inexistência de memória. */

int DequeDestroy (PtDeque *pdeque);
/* Destrói a fila dupla referenciada por pdeque e coloca a referência a NULL. Valores de retorno: OK ou NO_DEQUE. */

int DequePush (PtDeque pdeque, TELEM pelem);
/* Coloca pelem na cabeça da fila dupla referenciada por pdeque. Valores de retorno: OK, NO_DEQUE, NULL_PTR ou NO_MEM. */

int DequePop (PtDeque pdeque, TELEM *pelem);
/* Retira o elemento da cabeça da fila dupla referenciada por pdeque. Valores de retorno: OK, NO_DEQUE, NULL_PTR ou DEQUE_EMPTY. */

int DequeInject (PtDeque pdeque, TELEM pelem);
/* Coloca pelem na cauda da fila dupla referenciada por pdeque. Valores de retorno: OK, NO_DEQUE, NULL_PTR ou NO_MEM. */

int DequeEject (PtDeque pdeque, TELEM *pelem);
/* Retira o elemento da cauda da fila dupla referenciada por pdeque. Valores de retorno: OK, NO_DEQUE, NULL_PTR ou DEQUE_EMPTY. */

int DequeEmpty (PtDeque pdeque);
/* Verifica se a fila dupla referenciada por pdeque esta vazia. Devolve 1 em caso afirmativo e 0 caso contrario. */

#endif
