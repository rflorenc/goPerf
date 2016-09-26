/******************* Interface do Conjunto Disjunto *******************/
/***** Nome: disjointset.h *****/

#ifndef _DISJOINTSET
#define _DISJOINTSET

/******** Definição do Tipo Ponteiro para um Conjunto Disjunto ********/

typedef struct disjointset *PtDisjointSet;

/******************** Definição de Códigos de Erro ********************/

#define	OK              0  /* operação realizada com sucesso */
#define	NO_DISJOINTSET  1  /* conjunto disjunto inexistente */
#define	NO_MEM          2  /* memória esgotada */
#define	NULL_PTR        3  /* ponteiro nulo */
#define	NO_ELEM         4  /* elemento inexistente */

/********************* Protótipos dos Subprogramas ********************/

PtDisjointSet DisjointSetCreate (unsigned int pdim);
/* Cria um conjunto disjunto com dimensão pdim. Devolve a referência do conjunto disjunto criado ou NULL em caso de inexistência de memória. */

int DisjointSetDestroy (PtDisjointSet *pdisjointset);
/* Destrói o conjunto disjunto referenciado por pdisjointset e coloca a referência a NULL. Valores de retorno: OK ou NO_DISJOINTSET. */

int DisjointSetFind (PtDisjointSet pdisjointset, int pelem, int *praiz);
/* Pesquisa o elemento pelem no conjunto disjunto referenciado por pdisjointset e indica a sua posição no conjunto disjunto. Valores de retorno: OK, NO_DISJOINTSET, NO_ELEM ou NULL_PTR. */

int DisjointSetUnion (PtDisjointSet pdisjointset, int raiza, int raizb);
/* Funde as árvores raiza e raizb do conjunto disjunto referenciado por pdisjointset. Valores de retorno: OK ou NO_DISJOINTSET. */

#endif
