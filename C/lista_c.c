/*******************************************************************************

 Algoritmos de manipula��o de uma lista ligada ordenada por ordem crescente. 
 Os n�s da lista s�o decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct no *PtNo;

struct no
{
  PtNo PtSeg;  /* ponteiro para o n� seguinte da lista */
  TELEM *PtEle;  /* ponteiro para o elemento da lista */
};

/******************************************************************************/

PtNo CriarNo (TELEM pelem)  /* aloca��o do n� decomposto */
{
  PtNo No;

  if ((No = (PtNo) malloc (sizeof (struct no))) == NULL) return NULL;

  if ((No ->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (No);
    return NULL;
  }

  *No->PtEle = pelem;  /* copiar a informa��o */
  No->PtSeg = NULL;  /* coloc�-lo a apontar para NULL */

  return No;
}

/******************************************************************************/

void DestruirNo (PtNo *pptelem)  /* liberta��o do n� decomposto */
{
  free ((*pptelem)->PtEle);  /* liberta��o do elemento */
  free (*pptelem);  /* liberta��o do n� */

  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

/******************************************************************************/

PtNo PesquisarLista (PtNo pcab, TELEM pelem)
{
  PtNo No;

  for (No = pcab; No != NULL; No = No->PtSeg)
    if (*No->PtEle == pelem) break;

  return No;
}

/******************************************************************************/

void ImprimirLista (PtNo pcab)
{
  PtNo No;

  printf ("Elementos da lista ");
  for (No = pcab; No != NULL; No = No->PtSeg)
    imprimir *No->PtEle;
  printf ("\n");
}

/******************************************************************************/

void InserirElementoNaLista (PtNo *pcab, TELEM pelem)
{
  PtNo NoInserir, NoAnt = NULL, NoActual = *pcab;

  if ((NoInserir = CriarNo (pelem)) == NULL) return;

  while (NoActual != NULL && pelem > *NoActual->PtEle)
  {
    NoAnt = NoActual;
    NoActual = NoActual->PtSeg;
  }

  if (NoAnt == NULL)
  {
    NoInserir->PtSeg = *pcab;
    *pcab = NoInserir;
  }
  else
  {
    NoInserir->PtSeg = NoActual;
    NoAnt->PtSeg = NoInserir;
  }
}

/******************************************************************************/

void RemoverElementoDaLista (PtNo *pcab, TELEM pelem)
{
  PtNo NoAnt = NULL, NoActual = *pcab;

  if (NoActual == NULL) return;  /* a lista est� vazia */

  if (pelem == *NoActual->PtEle)
  {
    *pcab = (*pcab)->PtSeg;
    DestruirNo (&NoActual);
  }
  else
  {
    while (NoActual != NULL && pelem != *NoActual->PtEle)
    {
      NoAnt = NoActual;
      NoActual = NoActual->PtSeg;
    }

    if (NoActual != NULL)
    {
      NoAnt->PtSeg = NoActual->PtSeg;
      DestruirNo (&NoActual);
    }
  }
}

/******************************************************************************/

void DestruirLista (PtNo *pcab)
{
  PtNo No;

  while (*pcab != NULL)
  {
    No = *pcab;  /* ponteiro a apontar para o elemento � cabe�a */
    *pcab = (*pcab)->PtSeg;  /* actualizar a cabe�a da lista */
    DestruirNo (&No);  /* destruir o elemento */
  }
}

/******************************************************************************/
