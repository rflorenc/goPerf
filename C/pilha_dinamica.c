/*************** Interface da Pilha Dinâmica Configurada ***************/
/***** Nome: pilha_dinamica.h *****/

#ifndef _PILHA_DINAMICA
#define _PILHA_DINAMICA

/******* Inclusão do Ficheiro de Interface do Elemento da Pilha *******/

#include "elemento.h"

/************** Definição do Tipo Ponteiro para uma Pilha **************/

typedef struct stack *PtStack;

/******************** Definição de Códigos de Erro ********************/

#define	OK           0  /* operação realizada com sucesso */
#define	NO_STACK     1  /* pilha inexistente */
#define	NO_MEM       2  /* memória esgotada */
#define	NULL_PTR     3  /* ponteiro nulo */
#define	STACK_EMPTY  4  /* pilha vazia */

/********************* Protótipos dos Subprogramas ********************/

PtStack StackCreate (void);
/* Cria uma pilha. Devolve a referência da pilha criada ou NULL em caso de inexistência de memória. */

int StackDestroy (PtStack *pstack);
/* Destrói a pilha referenciada por pstack e coloca a referência a NULL. Valores de retorno: OK ou NO_STACK. */

int StackPush (PtStack pstack, TELEM pelem);
/* Coloca pelem no topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK ou NO_MEM. */

int StackPop (PtStack pstack, TELEM *pelem);
/* Retira o elemento do topo da pilha referenciada por pstack. Valores de retorno: OK, NO_STACK, STACK_EMPTY ou NULL_PTR. */

#endif
