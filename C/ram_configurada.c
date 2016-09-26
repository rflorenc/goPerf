/******************** Interface da RAM Configurada ********************/
/***** Nome: ram_configurada.h *****/

#ifndef _RAM_CONFIGURADA
#define _RAM_CONFIGURADA

/******** Inclusão do Ficheiro de Interface do Elemento da RAM ********/

#include "elemento_ram.h"

/************** Definição do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Definição de Códigos de Erro ********************/

#define	OK         0  /* operação realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* memória esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  6  /* elemento inexistente na RAM */
#define	NO_FUNC    7  /* função de comparação não comunicada */

/********************* Protótipos dos Subprogramas ********************/

PtRAM RAMCreate (unsigned int pdim, TPFC pfcomp);
/* Cria uma RAM com capacidade para armazenar pdim elementos inteiros e com a função de comparação global pfcomp. Devolve a referência da RAM criada ou NULL em caso de inexistência de memória ou se pdim for nulo ou se pfcomp for nulo. */

int RAMDestroy (PtRAM *pram);
/* Destrói a RAM referenciada por pram e coloca a referência a NULL. Valores de retorno: OK ou NO_RAM. */

int RAMSize (PtRAM pram, unsigned int *pnelem);
/* Determina o número de elementos efectivamente armazenados na RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMWrite (PtRAM pram, TELEM pelem, unsigned int ppos);
/* Escreve o elemento na posição ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou BAD_INDEX. */

int RAMRead (PtRAM ram, TELEM *pelem, unsigned int pos);
/* Lê o elemento da posição ppos da RAM referenciada por pram. Valores de retorno: OK, NO_RAM, NULL_PTR, ou BAD_INDEX. */

int RAMSearch (PtRAM pram, TELEM *pelem, int *ppos);
/* Pesquisa o elemento pelem na RAM referenciada por pram. Coloca em ppos a posição onde ele se encontra ou -1 caso ele não exista. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSetFuncComp (PtRAM pram, TPFC pfcomp);
/* Atribui a função de comparação pfcomp à RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSort (PtRAM pram, int ptord);
/* Ordena por ordem crescente (ascendente) ou decrescente (descendente), quando ptord é, respectivamente, 1 ou -1, a RAM referenciada por pram. Valores de retorno: OK, NO_RAM ou NO_FUNC. */

#endif
