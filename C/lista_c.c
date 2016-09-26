/*******************************************************************************

 Algoritmos de manipulação de uma lista ligada ordenada por ordem crescente. 
 Os nós da lista são decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct no *PtNo;

struct no
{
  PtNo PtSeg;  /* ponteiro para o nó seguinte da lista */
  TELEM *PtEle;  /* ponteiro para o elemento da lista */
};

/******************************************************************************/

PtNo CriarNo (TELEM pelem)  /* alocação do nó decomposto */
{
  PtNo No;

  if ((No = (PtNo) malloc (sizeof (struct no))) == NULL) return NULL;

  if ((No ->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (No);
    return NULL;
  }

  *No->PtEle = pelem;  /* copiar a informação */
  No->PtSeg = NULL;  /* colocá-lo a apontar para NULL */

  return No;
}

/******************************************************************************/

void DestruirNo (PtNo *pptelem)  /* libertação do nó decomposto */
{
  free ((*pptelem)->PtEle);  /* libertação do elemento */
  free (*pptelem);  /* libertação do nó */

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

  if (NoActual == NULL) return;  /* a lista está vazia */

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
    No = *pcab;  /* ponteiro a apontar para o elemento à cabeça */
    *pcab = (*pcab)->PtSeg;  /* actualizar a cabeça da lista */
    DestruirNo (&No);  /* destruir o elemento */
  }
}

/******************************************************************************/
