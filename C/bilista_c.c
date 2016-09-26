/*******************************************************************************

 Algoritmos de manipulação de uma lista biligada ordenada por ordem crescente. 
 Os nós da bilista são decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct bino *PtBiNo;

struct bino
{
  PtBiNo PtAnt;  /* ponteiro para o nó anterior da bilista */
  PtBiNo PtSeg;  /* ponteiro para o nó seguinte da bilista */
  TELEM *PtEle;  /* ponteiro para o elemento da bilista */
};

/******************************************************************************/

PtBiNo CriarBiNo (TELEM pelem)  /* alocação do nó decomposto */
{
  PtBiNo BiNo;

  if ((BiNo = (PtBiNo) malloc (sizeof (struct bino))) == NULL) return NULL;

  if ((BiNo->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (BiNo);
    return NULL;
  }

  *BiNo->PtEle = pelem;  /* copiar a informação */
  BiNo->PtAnt = NULL;  /* apontar para detrás para NULL */
  BiNo->PtSeg = NULL;  /* apontar para a frente para NULL */

  return BiNo;
}

/******************************************************************************/

void DestruirBiNo (PtBiNo *pptelem)  /* libertação do nó decomposto */
{
  free ((*pptelem)->PtEle);  /* libertação do elemento */
  free (*pptelem);  /* libertação do nó */

  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

/******************************************************************************/

PtBiNo PesquisarBiLista (PtBiNo pcab, TELEM pelem)
{
}

/******************************************************************************/

void InserirElementoNaBilista (PtBiNo *pcab, TELEM pelem)
{
  PtBiNo BiNoNovo, BiNoIns;

  if ((BiNoNovo = CriarBiNo (pelem)) == NULL) return;

  if (*pcab == NULL || *((*pcab)->PtEle) > pelem)
  {
    /* inserção à cabeça da lista */
    BiNoNovo->PtSeg = *pcab;
    if (BiNoNovo->PtSeg != NULL) BiNoNovo->PtSeg->PtAnt = BiNoNovo;
    *pcab = BiNoNovo;
  }
  else
  {
    /* inserção à frente do nó de inserção */
    BiNoIns = PosInserir (*pcab, pelem);

    if (BiNoIns != NULL)
    {
      BiNoNovo->PtAnt = BiNoIns;
      BiNoNovo->PtSeg = BiNoIns->PtSeg;
      BiNoIns->PtSeg = BiNoNovo;
      if (BiNoNovo->PtSeg != NULL) BiNoNovo->PtSeg->PtAnt = BiNoNovo;
    }
    else DestruirBiNo (&BiNoNovo);  /* destruir o elemento */
  }
}

PtBiNo PosInserir (PtBiNo pcab, TELEM pelem)
{
  PtBiNo BiNoAnt = NULL, BiNoActual = pcab;

  while (BiNoActual != NULL && *BiNoActual->PtEle <= pelem)
  {
    BiNoAnt = BiNoActual;
    BiNoActual = BiNoActual->PtSeg;
  }

  return BiNoAnt;
}

/******************************************************************************/

void RemoverElementoDaBilista (PtBiNo *pcab, TELEM *pelem)
{
  PtBiNo BiNoRem;

  if (*pcab == NULL || (BiNoRem = PosRemover (*pcab, *pelem)) == NULL)
    return;  /* a lista está vazia ou o elemento não existe */

  if (BiNoRem == *pcab)
  {
    /* remoção do elemento da cabeça da lista */
    if (BiNoRem->PtSeg != NULL) BiNoRem->PtSeg->PtAnt = NULL;
    *pcab = BiNoRem->PtSeg;
  }
  else
  {
    /* remoção doutro elemento da lista */
    BiNoRem->PtAnt->PtSeg = BiNoRem->PtSeg;
    if (BiNoRem->PtSeg != NULL)
      BiNoRem->PtSeg->PtAnt = BiNoRem->PtAnt;
  }

  *pelem = *BiNoRem->PtEle;  /* cópia do elemento */
  DestruirBiNo (&BiNoRem);  /* eliminação do elemento */
}

PtBiNo PosRemover (PtBiNo pcab, TELEM pelem)
{
  PtBiNo BiNo;

  for (BiNo = pcab; BiNo!= NULL; BiNo = BiNo->PtSeg)
    if (*BiNo->PtEle == pelem) break;

  return BiNo;
}

/******************************************************************************/

void DestruirBiLista (PtBiNo *pcab)
{
}

/******************************************************************************/
