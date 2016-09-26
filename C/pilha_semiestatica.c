/************* Interface da Pilha Semiestática Configurada *************/
/***** Nome: pilha_semiestatica.h *****/

#ifndef _PILHA_SEMIESTATICA
#define _PILHA_SEMIESTATICA

/******* Inclusão do Ficheiro de Interface do Elemento da Pilha *******/

#include "elemento.h"

/******************* Definição da dimensão da Pilha *******************/

#define MAX_ELEMENTOS 100

 
/************** Definição do Tipo Ponteiro para uma Pilha **************/

typedef struct stack *PtStack;

/******************** Definição de Códigos de Erro ********************/

#define	OK           0  /* operação realizada com sucesso */
#define	NO_STACK     1  /* pilha inexistente */
#define	NO_MEM       2  /* memória esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	STACK_EMPTY  4  /* pilha vazia */
#define	STACK_FULL   5  /* pilha cheia */

/********************* Protótipos dos Subprogramas ********************/

PtStack StackCreate (void);
/* Cria uma pilha. Devolve a referência da pilha criada ou NULL em caso de inexistência de memória. */

int StackDestroy (PtStack *pstack);
/* Destrói a pilha referenciada por pstack e coloca a referência a NULL. Valores de retorno: OK ou NO_STACK. */

int StackPush (PtStack pstack, TELEM pelem);
/* Coloca pelem no topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_FULL ou NO_MEM. */

int StackPop (PtStack pstack, TELEM *pelem);
/* Retira o elemento do topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_EMPTY ou NULL_PTR. */

#endif
