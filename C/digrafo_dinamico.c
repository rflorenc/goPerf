/******************** Interface do Digrafo Dinâmico ********************/
/***** Nome: digrafo_dinamico.h *****/

#ifndef _DIGRAFO_DINAMICO
#define _DIGRAFO_DINAMICO

/************* Definição do Tipo Ponteiro para um Digrafo *************/

typedef struct digraph *PtDigraph;

/******************** Definição de Códigos de Erro ********************/

#define	OK             0  /* operação realizada com sucesso */
#define	NO_DIGRAPH     1  /* digrafo inexistente */
#define	NO_MEM         2  /* memória esgotada */
#define	NULL_PTR       3  /* ponteiro nulo */
#define	DIGRAPH_EMPTY  4  /* digrafo vazio */
#define	NO_VERT        6  /* vértice inexistente */
#define	REP_VERT       7  /* vértice repetido */
#define	NO_EDGE        8  /* aresta inexistente */
#define	REP_EDGE       9  /* aresta repetida */
#define	NO_FILE       10  /* ficheiro inexistente */
#define	NO_DAG        11  /* digrafo cíclico */
#define	DIG_NEG       12  /* digrafo com ciclo negativo */

/********************* Protótipos dos Subprogramas ********************/

PtDigraph DigraphCreate (void);
/* Cria um digrafo. Devolve a referência do digrafo criado ou NULL em caso de inexistência de memória. */

int DigraphDestroy (PtDigraph *pdigraph);
/* Destrói o digrafo referenciado por pdigraph e coloca a referência a NULL. Valores de retorno: OK ou NO_DIGRAPH. */

PtDigraph DigraphCopy (PtDigraph pdigraph);
/* Copia o digrafo referenciado por pdigraph, caso ele exista. Devolve a referência do digrafo cópia ou NULL, caso não consiga fazer a cópia. Valores de retorno: OK, NO_DIGRAPH ou NO_MEM. */

int DigraphInVertice (PtDigraph pdigraph, unsigned int pvertice);
/* Insere o vértice pvertice no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou REP_VERT. */

int DigraphOutVertice (PtDigraph pdigraph, unsigned int pvertice);
/* Retira o vértice pvertice do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, DIGRAPH_EMPTY ou NO_VERT. */

int DigraphInEdge (PtDigraph pdigraph, unsigned int pvert1, unsigned int pvert2, int pcost);
/* Insere a aresta pvert1-pvert2, com custo pcost, no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, NO_VERT ou REP_EDGE. */

int DigraphOutEdge (PtDigraph pdigraph, unsigned int pvert1, unsigned int pvert2);
/* Retira a aresta pvert1-pvert2 do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH, NO_VERT ou NO_EDGE. */

int DigraphVerticeNumber (PtDigraph pdigraph, unsigned int *pnvertices);
/* Determina o número de vértices existentes no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

int DigraphEdgeNumber (PtDigraph pdigraph, unsigned int *pnedges);
/* Determina o número de arestas existentes no digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

int DigraphGetNVerticeList (PtDigraph pdigraph, unsigned int ppos, char *pvertlist);
/* Cria uma sequência de caracteres com a informação do ppos vértice (com 1 <= ppos <= V), incluindo a sua lista de adjacências, do digrafo referenciado por pdigraph. Valores de retorno: OK, NO_DIGRAPH ou NULL_PTR. */

PtDigraph DigraphCreateFile (char *pnomef);
/* Cria um digrafo com o conteúdo do ficheiro pnomef. Devolve a referência do digrafo criado ou NULL em caso de inexistência de memória ou de inexistência do ficheiro. */

int DigraphStoreFile (PtDigraph pdigraph, char *pnomef);
/* Armazena o digrafo referenciado por pdigraph no ficheiro pnomef. Valores de retorno: OK, NO_DIGRAPH, DIGRAPH_EMPTY ou NO_FILE. */

#endif
