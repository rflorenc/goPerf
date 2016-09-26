/********************** Interface da RAM Concreta **********************/
/***** Nome: ram_concreta.h *****/

#ifndef _RAM_CONCRETA
#define _RAM_CONCRETA

/************** Defini��o do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK         0  /* opera��o realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* mem�ria esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  6  /* posi��o inexistente na RAM */

/********************* Prot�tipos dos Subprogramas ********************/

PtRAM RAMCreate (unsigned int pdim);
/* Cria uma RAM com capacidade para armazenar pdim elementos inteiros. Devolve a refer�ncia da RAM criada ou NULL em caso de inexist�ncia de mem�ria ou se pdim for nulo. */

int RAMDestroy (PtRAM *pram);
/* Destr�i a RAM referenciada por pram e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_RAM. */

int RAMSize (PtRAM pram, unsigned int *pnelem);
/* Determina o n�mero de elementos efectivamente armazenados na RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMWrite (PtRAM pram, int pelem, unsigned int ppos);
/* Escreve o elemento na posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou BAD_INDEX. */

int RAMRead (PtRAM ram, int *pelem, unsigned int pos);
/* L� o elemento da posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR, ou BAD_INDEX. */

int RAMSearch (PtRAM pram, int pelem, int *ppos);
/* Procura o elemento na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSort (PtRAM pram);
/* Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Valores de retorno: OK ou NO_RAM. */

#endif
