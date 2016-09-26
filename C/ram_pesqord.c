/************* Interface da RAM para Pesquisa e Ordena��o *************/
/***** Nome: ram_pesqord.h *****/

#ifndef _RAM_PESQ_ORD
#define _RAM_PESQ_ORD

/************** Defini��o do Tipo Ponteiro para uma RAM **************/

typedef struct ram *PtRAM;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK         0  /* opera��o realizada com sucesso */
#define	NO_RAM     1  /* RAM inexistente */
#define	NO_MEM     2  /* mem�ria esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	BAD_INDEX  4  /* posi��o inexistente na RAM */

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

int RAMCount (PtRAM ram, int pval, int *pcnt);
/* Conta o n�mero de ocorr�ncias de pval na RAM referenciada por ram. Coloca em pcnt o n�mero de ocorr�ncias do elemento indicado ou 0 caso ele n�o exista na RAM. Valores de retorno: OK, NO_RAM ou NULL_PTR. */ 

int RAMSequentialSearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa sequencial com contagem de compara��es. Procura pval na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Coloca em pncomp o n�mero de compara��es efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMOrderedSequentialSearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa sequencial ordenada com contagem de compara��es. Procura pval na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Coloca em pncomp o n�mero de compara��es efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMBinarySearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa bin�ria com contagem de compara��es. Procura pval na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Coloca em pncomp o n�mero de compara��es efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMTernarySearch (PtRAM ram, int pval, int *ppos, int *pncomp);
/* Pesquisa tern�ria com contagem de compara��es. Procura pval na RAM referenciada por pram. Coloca em ppos a posi��o onde se encontra o elemento procurado ou -1 caso ele n�o exista. Coloca em pncomp o n�mero de compara��es efectuadas. Valores de retorno: OK, NO_RAM ou NULL_PTR. */

int RAMSequentialSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Sequencial com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (3 vezes o n�mero de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMSelectionSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Selec��o com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (3 vezes o n�mero de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMBubbleSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Bubble com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (3 vezes o n�mero de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShakerSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Shaker com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (3 vezes o n�mero de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShellTSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Shell vers�o trocas com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (3 vezes o n�mero de trocas) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMInsertionSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Inser��o com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMShellSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Shell vers�o original com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMMergeSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Merge com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMInsertionRSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Inser��o recursiva com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMQuickSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Quick com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

int RAMQuickOptSort (PtRAM pram, int *pncomp, int *pnatri);
/* Ordena��o Quick optimizada com contagem de compara��es e de atribui��es. Faz a ordena��o crescente dos elementos da RAM referenciada por pram. Coloca em pncomp e em pnatri, respectivamente o n�mero de compara��es e de atribui��es (n�mero de c�pias) efectuadas. Valores de retorno: OK ou NO_RAM. */

#endif
