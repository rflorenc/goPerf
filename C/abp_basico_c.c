/*******************************************************************************

 Algoritmos b�sicos de manipula��o de uma �rvore bin�ria de pesquisa. 
 Os n�s da �rvore s�o decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct noabp *PtNoABP;

struct noabp
{
  PtNoABP PtEsq;  /* ponteiro para o n� esquerdo da �rvore bin�ria de pesquisa*/
  PtNoABP PtDir;  /* ponteiro para o n� direito da �rvore bin�ria de pesquisa */
  TELEM *PtEle;  /* ponteiro para o elemento da �rvore bin�ria de pesquisa */
};

/******************************************************************************/

PtNoABP CriarNoABP (TELEM pelem)  /* aloca��o do n� decomposto */
{
  PtNoABP NoABP;

  if ((NoABP = (PtNoABP) malloc (sizeof (struct noabp))) == NULL)
    return NULL;

  if ((NoABP->PtEle = (TELEM *) malloc (sizeof (TELEM))) == NULL)
  {
    free (NoABP);
    return NULL;
  }

  *NoABP->PtEle = pelem;  /* copiar a informa��o */
  NoABP->PtEsq = NULL;  /* apontar para a esquerda para NULL */
  NoABP->PtDir = NULL;  /* apontar para a direita para NULL */

  return NoABP;
}

/******************************************************************************/

void DestruirNoABP (PtNoABP *pptelem)  /* liberta��o do n� decomposto */
{
  free ((*pptelem)->PtEle);  /* liberta��o do elemento */
  free (*pptelem);  /* liberta��o do n� */
  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

/******************************************************************************/

unsigned int NumNosABP (PtNoABP praiz)
{
  if (praiz == NULL) return 0;  /* �rvore vazia */
  else return 1 + NumNosABP (praiz->PtEsq) + NumNosABP (praiz->PtDir);
}

/******************************************************************************/

unsigned int AlturaABP (PtNoABP praiz)
{
  unsigned int AltEsq, AltDir;

  if (praiz == NULL) return 0;  /* n� externo no n�vel 0 */
  else
  {
    AltEsq = AlturaABP (praiz->PtEsq);  /* sub�rvore esquerda */
    AltDir = AlturaABP (praiz->PtDir);  /* sub�rvore direita */

    if (AltEsq > AltDir) return AltEsq + 1;
    else return AltDir + 1;
  }
}

/******************************************************************************/

PtNoABP PesquisarABPRec (PtNoABP praiz, TELEM pelem)
{
  if (praiz == NULL) return NULL;  /* pesquisa sem sucesso */

  if (*praiz->PtEle == pelem) return praiz;  /* pesquisa com sucesso */
  else if (*praiz->PtEle > pelem)
            return PesquisarABPRec (praiz->PtEsq, pelem);
       else return PesquisarABPRec (praiz->PtDir, pelem);
}

/******************************************************************************/

PtNoABP PesquisarABPRep (PtNoABP praiz, TELEM pelem)
{
  while (praiz != NULL && *praiz->PtEle != pelem)
    if (*praiz->PtEle > pelem) praiz = praiz->PtEsq; 
    else praiz = praiz->PtDir;

  return praiz;  /* devolver o resultado da pesquisa */
}

/******************************************************************************/

PtNoABP MinimoABPRec (PtNoABP praiz)
{
  if (praiz == NULL) return NULL;
  else if (praiz->PtEsq == NULL) return praiz;
       else return MinimoABPRec (praiz->PtEsq);
}

/******************************************************************************/

PtNoABP MaximoABPRec (PtNoABP praiz)
{
  if (praiz == NULL) return NULL;
  else if (praiz->PtDir == NULL) return praiz;
       else return MaximoABPRec (praiz->PtDir);
}

/******************************************************************************/

PtNoABP MinimoABPRep (PtNoABP praiz)
{
  if (praiz == NULL) return NULL;

  while (praiz->PtEsq != NULL) praiz = praiz->PtEsq;

  return praiz;
}

/******************************************************************************/

PtNoABP MaximoABPRep (PtNoABP praiz)
{
}

/******************************************************************************/

void InserirElementoNaABP (PtNoABP *praiz, TELEM pelem)
{
  if (*praiz == NULL)
  {
     if ((*praiz = CriarNoABP (pelem)) == NULL) return;   /* inserir o elemento */
  }
  else if (*(*praiz)->PtEle > pelem) /* inserir na sub�rvore esquerda */
            InserirElementoNaABP (&(*praiz)->PtEsq, pelem);
       else if (*(*praiz)->PtEle < pelem) /* inserir na sub�rvore direita */
                 InserirElementoNaABP (&(*praiz)->PtDir, pelem);
            else return;  /* o elemento j� existe */
}

/******************************************************************************/

void RemoverElementoDaABP (PtNoABP *praiz, TELEM *pelem)
{
  /* a �rvore est� vazia ou o elemento n�o existe */
  if (*praiz == NULL) return;

  if (*(*praiz)->PtEle > *pelem)
       RemoverElementoDaABP (&(*praiz)->PtEsq, pelem);
  else if (*(*praiz)->PtEle < *pelem)
         RemoverElementoDaABP (&(*praiz)->PtDir, pelem);
       else
       {
         *pelem = *(*praiz)->PtEle;  /* copiar o elemento */
         RemoverNoABP (praiz);  /* eliminar o elemento */
       }
}

void RemoverNoABP (PtNoABP *praiz)
{
  PtNoABP NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL && (*praiz)->PtDir == NULL)
       DestruirNoABP (praiz);  /* n� folha - eliminar o elemento */
  else if ((*praiz)->PtEsq == NULL)  /* com sub�rvore direita */
       {
         *praiz = (*praiz)->PtDir;  /* ligar � direita */
         DestruirNoABP (&NoTmp);  /* eliminar o elemento */
       }
       else if ((*praiz)->PtDir == NULL)  /* com sub�rvore esquerda */
            {
              *praiz = (*praiz)->PtEsq;  /* ligar � esquerda */
              DestruirNoABP (&NoTmp);  /* eliminar o elemento */
            }
            else SubstituirNoMinABP (&(*praiz)->PtDir, (*praiz)->PtEle);
            /* com sub�rvores direita e esquerda, substituir pelo menor elemento da sub�rvore direita */
}

void SubstituirNoMinABP (PtNoABP *praiz, TELEM *pelem)
{
  PtNoABP NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL)
  {
    *pelem = *(*praiz)->PtEle;  /* copiar o elemento */
    *praiz = (*praiz)->PtDir;  /* ajustar a sub�rvore direita */
    DestruirNoABP (&NoTmp);  /* eliminar o elemento */
  }
  else SubstituirNoMinABP (&(*praiz)->PtEsq, pelem);
}

/******************************************************************************/

void DestruirABP (PtNoABP *praiz)
{
  if (*praiz != NULL)
  {
    DestruirABP (&(*praiz)->PtEsq);  /* destruir sub�rvore esquerda */
    DestruirABP (&(*praiz)->PtDir);  /* destruir sub�rvore direita */
    DestruirNoABP (praiz);  /* eliminar o elemento */
  }
}

/******************************************************************************/
