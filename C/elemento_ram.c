/******************** Interface do Elemento da RAM ********************/
/***** Nome: elemento_ram.h *****/

#ifndef _ELEMENTO_RAM
#define _ELEMENTO_RAM

/********************* Defini��o do Tipo Elemento *********************/

typedef struct	/* defini��o da data */
{
  unsigned int Dia; unsigned int Mes; unsigned int Ano;
} TDATA;

typedef struct elemento	/* defini��o do elemento */
{
  unsigned int NReg; char Nome[41]; TDATA Data; char Telefone[10];
} TELEM;

/******** Defini��o do Tipo Ponteiro para Fun��es de Compara��o ********/

typedef int (*TPFC) (TELEM *, TELEM *);

/********************* Prot�tipos dos Subprogramas ********************/

int CompararElementos (TELEM *pelema, TELEM *pelemb);
/* Compara��o global dos elementos. Devolve 0 caso eles sejam iguais e 1 em caso contr�rio. */

int CompararNumerElementos (TELEM *pelema, TELEM *pelemb);
/* Compara��o do campo n�mero de registo dos elementos, para permitir a ordena��o num�rica crescente/decrescente dos elementos. Devolve 1, -1 ou 0, caso o n�mero de registo de pelema seja, respectivamente, maior do que, menor do que, ou igual a, o n�mero de registo de pelemb. */

int CompararAlfabElementos (TELEM *pelema, TELEM *pelemb);
/* Compara��o do campo nome dos elementos, para permitir a ordena��o alfab�tica ascendente/descendente dos elementos. Devolve 1, -1 ou 0, caso o nome de pelema seja, respectivamente, alfabeticamente maior do que, alfabeticamente menor do que, ou igual a, o nome de pelemb. */

int CompararCronoElementos (TELEM *pelema, TELEM *pelemb);
/* Compara��o do campo data dos elementos, para permitir a ordena��o cronol�gica crescente/decrescente dos elementos. Devolve 1, -1 ou 0, caso a data de pelema seja, respectivamente, mais recente do que, menos recente do que, ou igual a, a data de pelemb. */

void EscreverElemento (TELEM *pelem);
/* Escreve no monitor a informa��o armazenada no elemento. */

#endif
