/************* Interface da RAM para Pesquisa e Ordenação *************/
/***** Nome: ram_pesqord.h *****/

#ifndef _RAM_PESQ_ORD
#define _RAM_PESQ_ORD

/************** Definição do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Definição de Códigos de Erro ********************/

#define	OK         0  /* operação realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* memória esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  4  /* posição inexistente na RAM */

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

int RAMCount (PtRAM ram, int pval, int *pcnt);
/* Conta o número de ocorrências de pval na RAM referenciada por ram. Coloca em pcnt o número de ocorrências do elemento indicado ou 0 caso ele não exista na RAM. Valores de retorno: OK, NO_RAM ou NULL_PTR. */ 

int RAMSequentialSearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa sequencial com contagem de comparações. Procura pval na RAM referenciada por pram. Coloca em ppos a posição onde se encontra o elemento procurado ou -1 caso ele não exista. Coloca em pncomp o número de comparações efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMOrderedSequentialSearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa sequencial ordenada com contagem de comparações. Procura pval na RAM referenciada por pram. Coloca em ppos a posição onde se encontra o elemento procurado ou -1 caso ele não exista. Coloca em pncomp o número de comparações efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMBinarySearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa binária com contagem de comparações. Procura pval na RAM referenciada por pram. Coloca em ppos a posição onde se encontra o elemento procurado ou -1 caso ele não exista. Coloca em pncomp o número de comparações efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMTernarySearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa ternária com contagem de comparações. Procura pval na RAM referenciada por pram. Coloca em ppos a posição onde se encontra o elemento procurado ou -1 caso ele não exista. Coloca em pncomp o número de comparações efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSequentialSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Sequencial com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (3 vezes o número de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMSelectionSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Selecção com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (3 vezes o número de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMBubbleSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Bubble com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (3 vezes o número de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShakerSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Shaker com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (3 vezes o número de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShellTSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Shell versão trocas com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (3 vezes o número de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMInsertionSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Inserção com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShellSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Shell versão original com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMMergeSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Merge com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMInsertionRSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Inserção recursiva com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMQuickSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Quick com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMQuickOptSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordenação Quick optimizada com contagem de comparações e de atribuições. Faz a ordenação crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o número de comparações e de atribuições (número de cópias) efectuadas. Valores de retorno: OK ou NO_RAM. */

#endif
