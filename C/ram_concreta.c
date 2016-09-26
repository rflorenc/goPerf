/********************** Interface da RAM Concreta **********************/
/***** Nome: ram_concreta.h *****/

#ifndef _RAM_CONCRETA
#define _RAM_CONCRETA

/************** Definição do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Definição de Códigos de Erro ********************/

#define	OK         0  /* operação realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* memória esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  6  /* posição inexistente na RAM */

/********************* Protótipos dos Subprogramas ********************/

PtRAM RAMCreate (unsigned int pdim);
/* Cria uma RAM com capacidade para armazenar pdim elementos inteiros. Devolve a referência da RAM criada ou NULL em caso de inexistência de memória ou se pdim for nulo. */

int RAMDestroy (PtRAM *pram);
/* Destrói a RAM referenciada por pram e coloca a referência a NULL. Valores de retorno: OK ou NO_RAM. */

int RAMSize (PtRAM pram, unsigned int *pnelem);
/* Determina o número de elementos efectivamente armazenados na RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMWrite (PtRAM pram, int pelem, unsigned int ppos);
/* Escreve o elemento na posição ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou BAD_INDEX. */

int RAMRead (PtRAM ram, int *pelem, unsigned int pos);
/* Lê o elemento da posição ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR, ou BAD_INDEX. */

int RAMSearch (PtRAM pram, int pelem, int *ppos);
/* Procura o elemento na RAM referenciada por pram. Coloca em ppos a posição onde se encontra o elemento procurado ou -1 caso ele não exista. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSort (PtRAM pram);
/* Faz a ordenação crescente dos elementos da RAM referenciada por pram. Valores de retorno: OK ou NO_RAM. */

#endif
