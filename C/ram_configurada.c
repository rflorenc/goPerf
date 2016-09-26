/******************** Interface da RAM Configurada ********************/
/***** Nome: ram_configurada.h *****/

#ifndef _RAM_CONFIGURADA
#define _RAM_CONFIGURADA

/******** Inclus�o do Ficheiro de Interface do Elemento da RAM ********/

#include "elemento_ram.h"

/************** Defini��o do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK         0  /* opera��o realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* mem�ria esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  6  /* elemento inexistente na RAM */
#define	NO_FUNC    7  /* fun��o de compara��o n�o comunicada */

/********************* Prot�tipos dos Subprogramas ********************/

PtRAM RAMCreate (unsigned int pdim, TPFC pfcomp);
/* Cria uma RAM com capacidade para armazenar pdim elementos inteiros e com a fun��o de compara��o global pfcomp. Devolve a refer�ncia da RAM criada ou NULL em caso de inexist�ncia de mem�ria ou se pdim for nulo ou se pfcomp for nulo. */

int RAMDestroy (PtRAM *pram);
/* Destr�i a RAM referenciada por pram e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_RAM. */

int RAMSize (PtRAM pram, unsigned int *pnelem);
/* Determina o n�mero de elementos efectivamente armazenados na RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMWrite (PtRAM pram, TELEM pelem, unsigned int ppos);
/* Escreve o elemento na posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou BAD_INDEX. */

int RAMRead (PtRAM ram, TELEM *pelem, unsigned int pos);
/* L� o elemento da posi��o ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR, ou BAD_INDEX. */

int RAMSearch (PtRAM pram, TELEM *pelem, int *ppos);
/* Pesquisa o elemento pelem na RAM referenciada por pram. Coloca em ppos a posi��o onde ele se encontra ou -1 caso ele n�o exista. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSetFuncComp (PtRAM pram, TPFC pfcomp);
/* Atribui a fun��o de compara��o pfcomp � RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSort (PtRAM pram, int ptord);
/* Ordena por ordem crescente (ascendente) ou decrescente (descendente), quando ptord �, respectivamente, 1 ou -1, a RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NO_FUNC. */

#endif
