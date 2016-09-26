/******************** Interface do Elemento da CAM ********************/
/***** Nome: elemento_cam.h *****/

#ifndef _ELEMENTO_CAM
#define _ELEMENTO_CAM

/********* Constantes de Parametriza��o da Estrutura de Dados *********/

#define MAX_CHAVE 20	/* n�mero de caracteres da chave */

/********************* Defini��o do Tipo Elemento *********************/

typedef struct elemento	/* defini��o do elemento */	
{
  char Chave[MAX_CHAVE+1];  /* campo da chave alfanum�rica do elemento */
  ...  /* restantes campos da estrutura */
} TELEM;

/******** Defini��o do Tipo Ponteiro para Fun��es de Compara��o ********/

typedef int (*TPFC) (TELEM *, TELEM *);

/********************* Prot�tipos dos Subprogramas ********************/

int CompararChaveElementos (TELEM *pelema, TELEM *pelemb);
/* Compara��o da chave dos elementos, para permitir a ordena��o crescente (ascendente) ou decrescente (descendente) dos elementos. Devolve 1, -1 ou 0, caso a chave de pelema seja, respectivamente, maior do que, menor do que, ou igual a, a chave de pelemb. */

void LerElemento (TELEM *pelem);
/* L� do teclado a informa��o para o elemento. */

void EscreverElemento (TELEM *pelem);
/* Escreve no monitor a informa��o armazenada no elemento. */

#endif
