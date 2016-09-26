/********************** Interface da RAM Gen�rica **********************/
/***** Nome: ram_generica.h *****/

#ifndef _RAM_GENERICA
#define _RAM_GENERICA

/************** Defini��o do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK         0  /* opera��o realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* mem�ria esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  6  /* elemento inexistente na RAM */
#define	NO_SORT    8  /* ordena��o n�o efectuada */

/********************* Prot�tipos dos Subprogramas ********************/

PtRAM RAMCreate (unsigned int pdim, unsigned int psize);
/* Cria uma RAM com capacidade para armazenar pdim elementos inteiros com psize bytes. Devolve a refer�ncia da RAM criada ou NULL em caso de inexist�ncia de mem�ria ou se pdim for nulo ou se psize for nulo. */

int RAMDestroy (PtRAM *pram);
/* Destr�i a RAM referenciada por pram e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_RAM. */

int RAMSize (PtRAM pram, unsigned int *pnelem);
/* Determina o n�mero de elementos efectivamente armazenados na RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMWrite (PtRAM pram, void *pelem, unsigned int ppos);
/* Escreve o elemento na posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR ou BAD_INDEX. */

int RAMRead (PtRAM ram, void *pelem, unsigned int pos);
/* L� o elemento da posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR, ou BAD_INDEX. */

int RAMSearch (PtRAM pram, void *pelem, int *ppos);
/* Procura o elemento na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSort (PtRAM pram);
/* Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NO_SORT. */

#endif
