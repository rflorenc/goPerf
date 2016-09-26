/*******************************************************************************

 Algoritmos b�sicos de manipula��o de uma �rvore de Adelson-Velskii Landis. 
 Os n�s da �rvore s�o decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct noavl *PtNoAVL;

struct noavl
{
  PtNoAVL PtEsq;  /* ponteiro para o n� esquerdo da �rvore AVL */
  PtNoAVL PtDir;  /* ponteiro para o n� direito da �rvore AVL */
  TELEM *PtEle;  /* ponteiro para o elemento da �rvore AVL */
  unsigned int Altura;  /* altura do n� */
};

/******************************************************************************/

PtNoAVL CriarNoAVL (TELEM pelem)  /* aloca��o do n� decomposto */
{
  PtNoAVL NoAVL;

  ...

  return NoAVL;
}

/******************************************************************************/

void DestruirNoAVL (PtNoAVL *pptelem)  /* liberta��o do n� decomposto */
{
  ...

  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

/******************************************************************************/

unsigned int AlturaAVL (PtNoAVL praiz)
{
  if (praiz == NULL) return 0;
  else return praiz->Altura;
}

/******************************************************************************/

void RotacaoSimplesDireita (PtNoAVL *pno)
{
  unsigned int AltEsq, AltDir;
  PtNoAVL No = (*pno)->PtEsq;

  (*pno)->PtEsq = No->PtDir; No->PtDir = *pno;

  /* actualizar a altura dos n�s envolvidos na rota��o */
  AltEsq = AlturaAVL ((*pno)->PtEsq);
  AltDir = AlturaAVL ((*pno)->PtDir);
  (*pno)->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;

  AltEsq = AlturaAVL (No->PtEsq);
  AltDir = (*pno)->Alt;
  No->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;

  *pno = No;
}

/******************************************************************************/

void RotacaoSimplesEsquerda (PtNoAVL *pno)
{
  unsigned int AltEsq, AltDir;
  PtNoAVL No = (*pno)->PtDir;

  (*pno)->PtDir = No->PtEsq; No->PtEsq = *pno;

  /* actualizar a altura dos n�s envolvidos na rota��o */
  AltEsq = AlturaAVL ((*pno)->PtEsq);
  AltDir = AlturaAVL ((*pno)->PtDir);
  (*pno)->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;

  AltEsq = (*pno)->Alt;
  AltDir = AlturaAVL (No->PtDir);
  No->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;

  *pno = No;
}

/******************************************************************************/

void RotacaoDuplaDireitaEsquerda (PtNoAVL *pno)
{
  RotacaoSimplesDireita (&(*pno)->PtDir);
  RotacaoSimplesEsquerda (pno);
}

/******************************************************************************/

void RotacaoDuplaEsquerdaDireita (PtNoAVL *pno)
{
  RotacaoSimplesEsquerda (&(*pno)->PtEsq);
  RotacaoSimplesDireita (pno);
}

/******************************************************************************/

void EquilibrarAVL (PtNoAVL *praiz)
{
  unsigned int AltEsq, AltDir;

  if (*praiz == NULL) return;

  /* c�lculo da altura das sub�rvores esquerda e direita */
  AltEsq = AlturaAVL ((*praiz)->PtEsq);
  AltDir = AlturaAVL ((*praiz)->PtDir);

  if (AltEsq - AltDir == 2)  /* sub�rvore esquerda desiquilibrada? */
  {
    AltEsq = AlturaAVL ((*praiz)->PtEsq->PtEsq);
    AltDir = AlturaAVL ((*praiz)->PtEsq->PtDir);

    if (AltEsq >= AltDir) RotacaoSimplesDireita (praiz);
    else RotacaoDuplaEsquerdaDireita (praiz);
  }
  else if (AltDir - AltEsq == 2)  /* sub�rvore direita desiquilibrada? */
       {
         AltDir = AlturaAVL ((*praiz)->PtDir->PtDir);
         AltEsq = AlturaAVL ((*praiz)->PtDir->PtEsq);

         if (AltDir >= AltEsq) RotacaoSimplesEsquerda (praiz);
         else RotacaoDuplaDireitaEsquerda (praiz);
       }
       else (*praiz)->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;
            /* actualizar a altura do n� */
}

/******************************************************************************/

void InserirElementoNaAVL (PtNoAVL *praiz, TELEM pelem)
{
  if (*praiz == NULL)
  {      /* inserir o elemento - cria��o do elemento com altura 1 */
    if ((*praiz = CriarNoAVL (pelem)) == NULL) return;
  }
  else if (*(*praiz)->PtEle > pelem) /* inserir na sub�rvore esquerda */
         InserirElementoNaAVL (&(*praiz)->PtEsq, pelem);
       else if (*(*praiz)->PtEle < pelem) /* inserir na sub�rvore direita */
              InserirElementoNaAVL (&(*praiz)->PtDir, pelem);
            else return;  /* o elemento j� existe */

  EquilibrarAVL (praiz);  /* reequilibrar a �rvore */
}

/******************************************************************************/

void RemoverElementoDaAVL (PtNoAVL *praiz, TELEM *pelem)
{
  /* a �rvore est� vazia ou o elemento n�o existe */
  if (*praiz == NULL) return;

  if (*(*praiz)->PtEle > *pelem)
    RemoverElementoDaAVL (&(*praiz)->PtEsq, pelem);
  else if (*(*praiz)->PtEle < *pelem)
         RemoverElementoDaAVL (&(*praiz)->PtDir, pelem);
       else
       {
         *pelem = *(*praiz)->PtEle;  /* copiar o elemento */
         RemoverNoAVL (praiz);  /* eliminar o elemento */
       }

  EquilibrarAVL (praiz);  /* reequilibrar a �rvore */
}

void RemoverNoAVL (PtNoAVL *praiz)
{
  PtNoAVL NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL && (*praiz)->PtDir == NULL)
    DestruirNoAVL (praiz);  /* n� folha - eliminar o elemento */
  else if ((*praiz)->PtEsq == NULL)  /* com sub�rvore direita */
       {
         *praiz = (*praiz)->PtDir;  /* ligar � direita */
         DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
       }
       else if ((*praiz)->PtDir == NULL)  /* com sub�rvore esquerda */
            {
              *praiz = (*praiz)->PtEsq;  /* ligar � esquerda */
              DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
            }
            else SubstituirNoMinAVL (&(*praiz)->PtDir, (*praiz)->PtEle);
            /* com sub�rvores direita e esquerda, substituir pelo menor elemento da sub�rvore direita */
}

void SubstituirNoMinAVL (PtNoAVL *praiz, TELEM *pelem)
{
  PtNoAVL NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL)
  {
    *pelem = *(*praiz)->PtEle;  /* copiar o elemento */
    *praiz = (*praiz)->PtDir;  /* ajustar a sub�rvore direita */
    DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
  }
  else SubstituirNoMinAVL (&(*praiz)->PtEsq, pelem);

  EquilibrarAVL (praiz);  /* reequilibrar a �rvore */
}

/******************************************************************************/
