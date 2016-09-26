/************* Interface da Pilha Semiest�tica Configurada *************/
/***** Nome: pilha_semiestatica.h *****/

#ifndef _PILHA_SEMIESTATICA
#define _PILHA_SEMIESTATICA

/******* Inclus�o do Ficheiro de Interface do Elemento da Pilha *******/

#include "elemento.h"

/******************* Defini��o da dimens�o da Pilha *******************/

#define MAX_ELEMENTOS 100

 
/************** Defini��o do Tipo Ponteiro para uma Pilha **************/

typedef struct stack *PtStack;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK           0  /* opera��o realizada com sucesso */
#define	NO_STACK     1  /* pilha inexistente */
#define	NO_MEM       2  /* mem�ria esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	STACK_EMPTY  4  /* pilha vazia */
#define	STACK_FULL   5  /* pilha cheia */

/********************* Prot�tipos dos Subprogramas ********************/

PtStack StackCreate (void);
/* Cria uma pilha. Devolve a refer�ncia da pilha criada ou NULL em caso de inexist�ncia de mem�ria. */

int StackDestroy (PtStack *pstack);
/* Destr�i a pilha referenciada por pstack e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_STACK. */

int StackPush (PtStack pstack, TELEM pelem);
/* Coloca pelem no topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_FULL ou NO_MEM. */

int StackPop (PtStack pstack, TELEM *pelem);
/* Retira o elemento do topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_EMPTY ou NULL_PTR. */

#endif
