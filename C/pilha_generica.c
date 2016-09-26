/**************** Interface da Pilha Din�mica Gen�rica ****************/
/***** Nome: pilha_generica.h *****/

#ifndef _PILHA_GENERICA
#define _PILHA_GENERICA

/************** Defini��o do Tipo Ponteiro para uma Pilha **************/

typedef struct stack *PtStack;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK           0  /* opera��o realizada com sucesso */
#define	NO_STACK     1  /* pilha inexistente */
#define	NO_MEM       2  /* mem�ria esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	STACK_EMPTY  4  /* pilha vazia */

/********************* Prot�tipos dos Subprogramas ********************/

PtStack StackCreate (unsigned int psize);
/* Cria uma pilha para armazenar elementos com psize bytes. Devolve a refer�ncia da pilha criada ou NULL em caso de inexist�ncia de mem�ria ou se psize for nulo. */

int StackDestroy (PtStack *pstack);
/* Destr�i a pilha referenciada por pstack e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_STACK. */

int StackPush (PtStack pstack, void *pelem);
/* Coloca pelem no topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, NULL_PTR ou NO_MEM. */

int StackPop (PtStack pstack, void *pelem);
/* Retira o elemento do topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_EMPTY ou NULL_PTR. */

#endif
