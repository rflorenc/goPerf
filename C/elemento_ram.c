/******************** Interface do Elemento da RAM ********************/
/***** Nome: elemento_ram.h *****/

#ifndef _ELEMENTO_RAM
#define _ELEMENTO_RAM

/********************* Definição do Tipo Elemento *********************/

typedef struct	/* definição da data */
{
  unsigned int Dia; unsigned int Mes; unsigned int Ano;
} TDATA;

typedef struct elemento	/* definição do elemento */
{
  unsigned int NReg; char Nome[41]; TDATA Data; char Telefone[10];
} TELEM;

/******** Definição do Tipo Ponteiro para Funções de Comparação ********/

typedef int (*TPFC) (TELEM *, TELEM *);

/********************* Protótipos dos Subprogramas ********************/

int CompararElementos (TELEM *pelema, TELEM *pelemb);
/* Comparação global dos elementos. Devolve 0 caso eles sejam iguais e 1 em caso contrário. */

int CompararNumerElementos (TELEM *pelema, TELEM *pelemb);
/* Comparação do campo número de registo dos elementos, para permitir a ordenação numérica crescente/decrescente dos elementos. Devolve 1, -1 ou 0, caso o número de registo de pelema seja, respectivamente, maior do que, menor do que, ou igual a, o número de registo de pelemb. */

int CompararAlfabElementos (TELEM *pelema, TELEM *pelemb);
/* Comparação do campo nome dos elementos, para permitir a ordenação alfabética ascendente/descendente dos elementos. Devolve 1, -1 ou 0, caso o nome de pelema seja, respectivamente, alfabeticamente maior do que, alfabeticamente menor do que, ou igual a, o nome de pelemb. */

int CompararCronoElementos (TELEM *pelema, TELEM *pelemb);
/* Comparação do campo data dos elementos, para permitir a ordenação cronológica crescente/decrescente dos elementos. Devolve 1, -1 ou 0, caso a data de pelema seja, respectivamente, mais recente do que, menos recente do que, ou igual a, a data de pelemb. */

void EscreverElemento (TELEM *pelem);
/* Escreve no monitor a informação armazenada no elemento. */

#endif
