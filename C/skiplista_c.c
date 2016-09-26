/*******************************************************************************

 Algoritmos de manipula��o de uma lista skip ordenada por ordem crescente. 
 Os n�s da lista skip s�o decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct skipno *PtSkipNo; 

struct skipno
{
  unsigned int NPts;
  PtSkipNo *PtSeg;
  TELEM *PtEle;
};

/******************************************************************************/

PtSkipNo CriarSkipNo (TELEM pelem, unsigned int pniv)  /* aloca��o do n� decomposto */
{
  PtSkipNo SkipNo; unsigned int I;

  if ((SkipNo = (PtSkipNo) malloc (sizeof (struct skipno))) == NULL)
    return NULL;
  if ((SkipNo->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (SkipNo); return NULL;
  }

  /* aloca��o da sequ�ncia de ponteiros */
  SkipNo->PtSeg = (PtSkipNo *) calloc (pniv, sizeof (PtSkipNo));
  if (SkipNo->PtSeg == NULL)
  {
    free (SkipNo->PtEle); free (SkipNo); return NULL;
  }

  *SkipNo->PtEle = pelem;  /* copiar a informa��o */
  SkipNo->NPts = pniv;  /* armazenar o n�mero de n�veis do n� */
  for (I = 0; I < pniv; I++)  /* colocar todos os ponteiros */
    SkipNo->PtSeg[I] = NULL;  /* a apontar para a frente para NULL */

  return SkipNo;
}

/******************************************************************************/

void DestruirSkipNo (PtSkipNo *pptelem)  /* liberta��o do n� decomposto */
{
  free ((*pptelem)->PtSeg);  /* liberta��o da sequ�ncia de ponteiros */
  free ((*pptelem)->PtEle);  /* liberta��o do elemento */
  free (*pptelem);  /* liberta��o do n� */
  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

/******************************************************************************/

PtSkipNo PesquisarSkipLista (PtSkipNo pcab, TELEM pelem, int pniv)
{
  if (pelem == *pcab->PtEle) return pcab;

  while (pniv > 0 && pcab->PtSeg[pniv] == NULL) pniv--;
  if (pniv < 0 || pcab->PtSeg[0] == NULL) return NULL;

  if (pelem < *pcab->PtSeg[pniv]->PtEle)
  {
    if (pniv == 0) return NULL;
    return PesquisarSkipLista (pcab, pelem, pniv-1);
  }
  return PesquisarSkipLista (pcab->PtSeg[pniv], pelem, pniv);
}

/******************************************************************************/

int Rand (unsigned int pmaxniv, unsigned int *pnivact)
{
  unsigned int I, J, T = rand();

  for (I = 1, J = 2; I < pmaxniv; I++, J += J)
    if (T > RAND_MAX/J) break;

  if (I > *pnivact) *pnivact = I;

  return I;
}

/******************************************************************************/

void InserirSkipNo (PtSkipNo pcab, PtSkipNo pno, unsigned int pniv)
{
  if (pcab->PtSeg[pniv] == NULL || *pno->PtEle < *pcab->PtSeg[pniv]->PtEle)
  {
    if (pniv < pno->NPts)
    {
      pno->PtSeg[pniv] = pcab->PtSeg[pniv];
      pcab->PtSeg[pniv] = pno;
    }
    if (pniv == 0) return;
    InserirSkipNo (pcab, pno, pniv-1);
  }
  else InserirSkipNo (pcab->PtSeg[pniv], pno, pniv);
}

/******************************************************************************/

void InserirElementoNaSkipLista (PtSkipNo pcab, TELEM pelem, unsigned int pmaxniv, unsigned int *pniv)
{
  PtSkipNo SkipNo; unsigned int Nivel;

  Nivel = Rand (pmaxniv, pniv);

  if ((SkipNo = CriarSkipNo (pelem, Nivel)) == NULL) return;

  InserirSkipNo (pcab, SkipNo, *pniv-1);
}

/******************************************************************************/

void RemoverElementoDaSkipLista (PtSkipNo pcab, TELEM pelem, int pniv)
{
  PtSkipNo SkipNo;

  while (pniv > 0 && pcab->PtSeg[pniv] == NULL) pniv--;
  if (pniv < 0 || pcab->PtSeg[0] == NULL) return;

  SkipNo = pcab->PtSeg[pniv];

  if (*SkipNo->PtEle >= pelem)
  {
    if (*SkipNo->PtEle == pelem)
    {
      pcab->PtSeg[pniv] = SkipNo->PtSeg[pniv];
      if (pniv == 0) { DestruirSkipNo (&SkipNo); return; }
    }
    RemoverElementoDaSkipLista (pcab, pelem, pniv-1);
  }
  else RemoverElementoDaSkipLista (pcab->PtSeg[pniv], pelem, pniv);
}

/******************************************************************************/

void DestruirSkipLista (PtSkipNo *pcab)
{
  PtSkipNo SkipNo;

  while (*pcab != NULL)
  {
    SkipNo = *pcab;
    *pcab = (*pcab)->PtSeg[0];
    DestruirSkipNo (&SkipNo);
  }
}

/******************************************************************************/



