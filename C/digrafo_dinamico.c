/******************** Interface do Digrafo Din�mico ********************/
/***** Nome: digrafo_dinamico.h *****/

#ifndef _DIGRAFO_DINAMICO
#define _DIGRAFO_DINAMICO

/************* Defini��o do Tipo Ponteiro para um Digrafo *************/

typedef struct digraph *PtDigraph;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK             0  /* opera��o realizada com sucesso */
#define	NO_DIGRAPH     1  /* digrafo inexistente */
#define	NO_MEM         2  /* mem�ria esgotada */
#define	NULL_PTR       3  /* ponteiro nulo */
#define	DIGRAPH_EMPTY  4  /* digrafo vazio */
#define	NO_VERT        6  /* v�rtice inexistente */
#define	REP_VERT       7  /* v�rtice repetido */
#define	NO_EDGE        8  /* aresta inexistente */
#define	REP_EDGE       9  /* aresta repetida */
#define	NO_FILE       10  /* ficheiro inexistente */
#define	NO_DAG        11  /* digrafo c�clico */
#define	DIG_NEG       12  /* digrafo com ciclo negativo */

/********************* Prot�tipos dos Subprogramas ********************/

PtDigraph DigraphCreate (void);
/* Cria um digrafo. Devolve a refer�ncia do digrafo criado ou NULL em caso de inexist�ncia de mem�ria. */

int DigraphDestroy (PtDigraph *pdigraph);
/* Destr�i o digrafo referenciado por pdigraph e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_DIGRAPH. */

PtDigraph DigraphCopy (PtDigraph pdigraph);
/* Copia o digrafo referenciado por pdigraph, caso ele exista. Devolve a refer�ncia do digrafo c�pia ou NULL, caso n�o consiga fazer a c�pia. Valores de retorno: OK, NO_DIGRAPH ou NO_MEM. */

int DigraphInVertice (PtDigraph pdigraph, unsigned int pvertice);
/* Insere o v�rtice pvertice no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou REP_VERT. */

int DigraphOutVertice (PtDigraph pdigraph, unsigned int pvertice);
/* Retira o v�rtice pvertice do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, DIGRAPH_EMPTY ou NO_VERT. */

int DigraphInEdge (PtDigraph pdigraph, unsigned int pvert1, unsigned int pvert2, int pcost);
/* Insere a aresta pvert1-pvert2, com custo pcost, no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, NO_VERT ou REP_EDGE. */

int DigraphOutEdge (PtDigraph pdigraph, unsigned int pvert1, unsigned int pvert2);
/* Retira a aresta pvert1-pvert2 do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, NO_VERT ou NO_EDGE. */

int DigraphVerticeNumber (PtDigraph pdigraph, unsigned int *pnvertices);
/* Determina o n�mero de v�rtices existentes no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

int DigraphEdgeNumber (PtDigraph pdigraph, unsigned int *pnedges);
/* Determina o n�mero de arestas existentes no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

int DigraphGetNVerticeList (PtDigraph pdigraph, unsigned int ppos, char *pvertlist);
/* Cria uma sequ�ncia de caracteres com a informa��o do ppos v�rtice (com 1 <= ppos <= V), incluindo a sua lista de adjac�ncias, do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

PtDigraph DigraphCreateFile (char *pnomef);
/* Cria um digrafo com o conte�do do ficheiro pnomef. Devolve a refer�ncia do digrafo criado ou NULL em caso de inexist�ncia de mem�ria ou de inexist�ncia do ficheiro. */

int DigraphStoreFile (PtDigraph pdigraph, char *pnomef);
/* Armazena o digrafo referenciado por pdigraph no ficheiro pnomef. Valores de retorno: OK, NO_DIGRAPH, DIGRAPH_EMPTY ou NO_FILE. */

#endif
