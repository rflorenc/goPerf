/*******************************************************************************

 Algoritmos básicos de manipulação de uma árvore de Adelson-Velskii Landis. 
 Os nós da árvore são decompostos e armazenam elementos do tipo TELEM.


*******************************************************************************/

#include <stdlib.h>

typedef struct noavl *PtNoAVL;

struct noavl
{
  PtNoAVL PtEsq;  /* ponteiro para o nó esquerdo da árvore AVL */
  PtNoAVL PtDir;  /* ponteiro para o nó direito da árvore AVL */
  TELEM *PtEle;  /* ponteiro para o elemento da árvore AVL */
  unsigned int Altura;  /* altura do nó */
};

/******************************************************************************/

PtNoAVL CriarNoAVL (TELEM pelem)  /* alocação do nó decomposto */
{
  PtNoAVL NoAVL;

  ...

  return NoAVL;
}

/******************************************************************************/

void DestruirNoAVL (PtNoAVL *pptelem)  /* libertação do nó decomposto */
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

  /* actualizar a altura dos nós envolvidos na rotação */
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

  /* actualizar a altura dos nós envolvidos na rotação */
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

  /* cálculo da altura das subárvores esquerda e direita */
  AltEsq = AlturaAVL ((*praiz)->PtEsq);
  AltDir = AlturaAVL ((*praiz)->PtDir);

  if (AltEsq - AltDir == 2)  /* subárvore esquerda desiquilibrada? */
  {
    AltEsq = AlturaAVL ((*praiz)->PtEsq->PtEsq);
    AltDir = AlturaAVL ((*praiz)->PtEsq->PtDir);

    if (AltEsq >= AltDir) RotacaoSimplesDireita (praiz);
    else RotacaoDuplaEsquerdaDireita (praiz);
  }
  else if (AltDir - AltEsq == 2)  /* subárvore direita desiquilibrada? */
       {
         AltDir = AlturaAVL ((*praiz)->PtDir->PtDir);
         AltEsq = AlturaAVL ((*praiz)->PtDir->PtEsq);

         if (AltDir >= AltEsq) RotacaoSimplesEsquerda (praiz);
         else RotacaoDuplaDireitaEsquerda (praiz);
       }
       else (*praiz)->Alt = AltEsq > AltDir ? AltEsq + 1 : AltDir + 1;
            /* actualizar a altura do nó */
}

/******************************************************************************/

void InserirElementoNaAVL (PtNoAVL *praiz, TELEM pelem)
{
  if (*praiz == NULL)
  {      /* inserir o elemento - criação do elemento com altura 1 */
    if ((*praiz = CriarNoAVL (pelem)) == NULL) return;
  }
  else if (*(*praiz)->PtEle > pelem) /* inserir na subárvore esquerda */
         InserirElementoNaAVL (&(*praiz)->PtEsq, pelem);
       else if (*(*praiz)->PtEle < pelem) /* inserir na subárvore direita */
              InserirElementoNaAVL (&(*praiz)->PtDir, pelem);
            else return;  /* o elemento já existe */

  EquilibrarAVL (praiz);  /* reequilibrar a árvore */
}

/******************************************************************************/

void RemoverElementoDaAVL (PtNoAVL *praiz, TELEM *pelem)
{
  /* a árvore está vazia ou o elemento não existe */
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

  EquilibrarAVL (praiz);  /* reequilibrar a árvore */
}

void RemoverNoAVL (PtNoAVL *praiz)
{
  PtNoAVL NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL && (*praiz)->PtDir == NULL)
    DestruirNoAVL (praiz);  /* nó folha - eliminar o elemento */
  else if ((*praiz)->PtEsq == NULL)  /* com subárvore direita */
       {
         *praiz = (*praiz)->PtDir;  /* ligar à direita */
         DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
       }
       else if ((*praiz)->PtDir == NULL)  /* com subárvore esquerda */
            {
              *praiz = (*praiz)->PtEsq;  /* ligar à esquerda */
              DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
            }
            else SubstituirNoMinAVL (&(*praiz)->PtDir, (*praiz)->PtEle);
            /* com subárvores direita e esquerda, substituir pelo menor elemento da subárvore direita */
}

void SubstituirNoMinAVL (PtNoAVL *praiz, TELEM *pelem)
{
  PtNoAVL NoTmp = *praiz;

  if ((*praiz)->PtEsq == NULL)
  {
    *pelem = *(*praiz)->PtEle;  /* copiar o elemento */
    *praiz = (*praiz)->PtDir;  /* ajustar a subárvore direita */
    DestruirNoAVL (&NoTmp);  /* eliminar o elemento */
  }
  else SubstituirNoMinAVL (&(*praiz)->PtEsq, pelem);

  EquilibrarAVL (praiz);  /* reequilibrar a árvore */
}

/******************************************************************************/
