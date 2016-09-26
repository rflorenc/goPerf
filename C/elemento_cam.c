/******************** Interface do Elemento da CAM ********************/
/***** Nome: elemento_cam.h *****/

#ifndef _ELEMENTO_CAM
#define _ELEMENTO_CAM

/********* Constantes de Parametrização da Estrutura de Dados *********/

#define MAX_CHAVE 20	/* número de caracteres da chave */

/********************* Definição do Tipo Elemento *********************/

typedef struct elemento	/* definição do elemento */	
{
  char Chave[MAX_CHAVE+1];  /* campo da chave alfanumérica do elemento */
  ...  /* restantes campos da estrutura */
} TELEM;

/******** Definição do Tipo Ponteiro para Funções de Comparação ********/

typedef int (*TPFC) (TELEM *, TELEM *);

/********************* Protótipos dos Subprogramas ********************/

int CompararChaveElementos (TELEM *pelema, TELEM *pelemb);
/* Comparação da chave dos elementos, para permitir a ordenação crescente (ascendente) ou decrescente (descendente) dos elementos. Devolve 1, -1 ou 0, caso a chave de pelema seja, respectivamente, maior do que, menor do que, ou igual a, a chave de pelemb. */

void LerElemento (TELEM *pelem);
/* Lê do teclado a informação para o elemento. */

void EscreverElemento (TELEM *pelem);
/* Escreve no monitor a informação armazenada no elemento. */

#endif
