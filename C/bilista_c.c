/*******************************************************************************

 Algoritmos de manipula��o de uma lista biligada ordenada por ordem crescente. 
 Os n�s da bilista s�o decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct bino *PtBiNo;

struct bino
{
  PtBiNo PtAnt;  /* ponteiro para o n� anterior da bilista */
  PtBiNo PtSeg;  /* ponteiro para o n� seguinte da bilista */
  TELEM *PtEle;  /* ponteiro para o elemento da bilista */
};

/******************************************************************************/

PtBiNo CriarBiNo (TELEM pelem)  /* aloca��o do n� decomposto */
{
  PtBiNo BiNo;

  if ((BiNo = (PtBiNo) malloc (sizeof (struct bino))) == NULL) return NULL;

  if ((BiNo->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (BiNo);
    return NULL;
  }

  *BiNo->PtEle = pelem;  /* copiar a informa��o */
  BiNo->PtAnt = NULL;  /* apontar para detr�s para NULL */
  BiNo->PtSeg = NULL;  /* apontar para a frente para NULL */

  return BiNo;
}

/******************************************************************************/

void DestruirBiNo (PtBiNo *pptelem)  /* liberta��o do n� decomposto */
{
  free ((*pptelem)->PtEle);  /* liberta��o do elemento */
  free (*pptelem);  /* liberta��o do n� */

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
    /* inser��o � cabe�a da lista */
    BiNoNovo->PtSeg = *pcab;
    if (BiNoNovo->PtSeg != NULL) BiNoNovo->PtSeg->PtAnt = BiNoNovo;
    *pcab = BiNoNovo;
  }
  else
  {
    /* inser��o � frente do n� de inser��o */
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
    return;  /* a lista est� vazia ou o elemento n�o existe */

  if (BiNoRem == *pcab)
  {
    /* remo��o do elemento da cabe�a da lista */
    if (BiNoRem->PtSeg != NULL) BiNoRem->PtSeg->PtAnt = NULL;
    *pcab = BiNoRem->PtSeg;
  }
  else
  {
    /* remo��o doutro elemento da lista */
    BiNoRem->PtAnt->PtSeg = BiNoRem->PtSeg;
    if (BiNoRem->PtSeg != NULL)
      BiNoRem->PtSeg->PtAnt = BiNoRem->PtAnt;
  }

  *pelem = *BiNoRem->PtEle;  /* c�pia do elemento */
  DestruirBiNo (&BiNoRem);  /* elimina��o do elemento */
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
