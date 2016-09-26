/******************* Interface do Conjunto Disjunto *******************/
/***** Nome: disjointset.h *****/

#ifndef _DISJOINTSET
#define _DISJOINTSET

/******** Defini��o do Tipo Ponteiro para um Conjunto Disjunto ********/

typedef struct disjointset *PtDisjointSet;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK              0  /* opera��o realizada com sucesso */
#define	NO_DISJOINTSET  1  /* conjunto disjunto inexistente */
#define	NO_MEM          2  /* mem�ria esgotada */
#define	NULL_PTR        3  /* ponteiro nulo */
#define	NO_ELEM         4  /* elemento inexistente */

/********************* Prot�tipos dos Subprogramas ********************/

PtDisjointSet DisjointSetCreate (unsigned int pdim);
/* Cria um conjunto disjunto com dimens�o pdim. Devolve a refer�ncia do conjunto disjunto criado ou NULL em caso de inexist�ncia de mem�ria. */

int DisjointSetDestroy (PtDisjointSet *pdisjointset);
/* Destr�i o conjunto disjunto referenciado por pdisjointset e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_DISJOINTSET. */

int DisjointSetFind (PtDisjointSet pdisjointset, int pelem, int *praiz);
/* Pesquisa o elemento pelem no conjunto disjunto referenciado por pdisjointset e indica a sua posi��o no conjunto disjunto. Valores de retorno: OK, NO_DISJOINTSET, NO_ELEM ou NULL_PTR. */

int DisjointSetUnion (PtDisjointSet pdisjointset, int raiza, int raizb);
/* Funde as �rvores raiza e raizb do conjunto disjunto referenciado por pdisjointset. Valores de retorno: OK ou NO_DISJOINTSET. */

#endif
