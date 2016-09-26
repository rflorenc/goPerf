/*******************************************************************************

 Algoritmos de pesquisa por dispers�o. 
 

*******************************************************************************/

#include <stdlib.h>
#include <string.h>

#define MAX_TAB 11  /* dimens�o �mpar */

/******************************************************************************/

int Hash (int pval)
{
  return pval % MAX_TAB;
}

int HashTwo (int pval)
{
  return 7 - pval % 7;
}

/******************************************************************************/

void InserirNaTabelaSL (int pseq[], int pval)
{
  unsigned int PosH, Pos;

  PosH = Hash (pval);  /* determina��o da posi��o de coloca��o */

  if (pseq[PosH] == 0) pseq[PosH] = pval;
  /* colocado com sucesso na posi��o dada pela fun��o de dispers�o */
  else
  {
    /* aplica��o da sondagem linear */
    Pos = (PosH + 1) % MAX_TAB;
    while (pseq[Pos] != 0 && Pos != PosH) Pos = ++Pos % MAX_TAB;

    if (Pos != PosH) pseq[Pos] = pval;
        /* colocado com sucesso noutra posi��o livre da tabela */
  }      /* sen�o a tabela de dispers�o est� cheia */
}

/******************************************************************************/

int PesquisarTabelaSL (int pseq[], int pval)
{
  unsigned int PosH, Pos;

  PosH = Hash (pval);  /* determina��o da posi��o de coloca��o */

  if (pseq[PosH] == pval) return PosH;  /* pesquisa com sucesso */
  else if (pseq[PosH] == 0) return -1;  /* pesquisa sem sucesso */
       else
       {
         /* aplica��o da sondagem linear */
         Pos = (PosH + 1) % MAX_TAB;
         while (pseq[Pos] != pval && pseq[Pos] != 0 && Pos != PosH)
           Pos = ++Pos % MAX_TAB;

         if (pseq[Pos] == pval) return Pos;  /* pesquisa com sucesso */
         else return -1;  /* pesquisa sem sucesso */
       }
}

/******************************************************************************/

void InserirNaTabelaSQ (int pseq[], int pval)
{
  unsigned int PosH, Pos, Tentativa = 1;

  PosH = Hash (pval);  /* determina��o da posi��o de coloca��o */

  if (pseq[PosH] == 0) pseq[PosH] = pval;
  /* colocado com sucesso na posi��o dada pela fun��o de dispers�o */
  else
  {
    /* aplica��o da sondagem quadr�tica */
    do
    {
      Pos = (PosH + Tentativa * Tentativa) % MAX_TAB; Tentativa++;
    } while (pseq[Pos] != 0 && Pos != PosH);

    if (Pos != PosH) pseq[Pos] = pval;
        /* colocado com sucesso noutra posi��o livre da tabela */
  }      /* sen�o a tabela de dispers�o est� cheia */
}

/******************************************************************************/

int PesquisarTabelaSQ (int pseq[], int pval)
{
  unsigned int PosH, Pos, Tentativa = 1;

  PosH = Hash (pval);  /* determina��o da posi��o de coloca��o */

  if (pseq[PosH] == pval) return PosH;  /* pesquisa com sucesso */
  else if (pseq[PosH] == 0) return -1;  /* pesquisa sem sucesso */
       else
       {
         /* aplica��o da sondagem quadr�tica */
         do
         {
           Pos = (PosH + Tentativa * Tentativa) % MAX_TAB;
           Tentativa++;
         } while (pseq[Pos] != pval && pseq[Pos] != 0 && Pos != PosH);

         if (pseq[Pos] == pval) return Pos;  /* pesquisa com sucesso */
         else return -1;  /* pesquisa sem sucesso */
       }
}

/******************************************************************************/

/* lista ligada com n�s compactos e suas opera��es de manipula��o */

typedef struct no *PtNo;

struct no
{
  PtNo PtSeg;
  int Elem;
};

PtNo CriarNo (int pelem)  /* aloca��o de um n� compacto */
{
  PtNo No;

  if ((No = (PtNo) malloc (sizeof (struct no))) == NULL) return NULL;

  No->Elem = pelem;  /* copiar a informa��o */
  No->PtSeg = NULL;  /* coloc�-lo a apontar para NULL */

  return No;
}

void DestruirNo (PtNo *pptelem)  /* liberta��o do n� compacto */
{
  free (*pptelem);  /* liberta��o do n� */

  *pptelem = NULL;  /* colocar o ponteiro a nulo */
}

PtNo PesquisarLista (PtNo pcab, int pelem)
{
  PtNo No;

  for (No = pcab; No != NULL; No = No->PtSeg)
    if (No->Elem == pelem) break;

  return No;
}

void RemoverElementoDaLista (PtNo *pcab, int pelem)
{
  PtNo NoAnt = NULL, NoActual = *pcab;

  if (NoActual == NULL) return;  /* a lista est� vazia */

  if (NoActual->Elem == pelem)
  {
    *pcab = (*pcab)->PtSeg;
    DestruirNo (&NoActual);
  }
  else
  {
    while (NoActual != NULL && NoActual->Elem != pelem)
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

void InserirNaTabelaEnc (PtNo pseq[], int pval)
{
  unsigned int PosH; PtNo NoInserir, NoActual;

  if ((NoInserir = CriarNo (pval)) == NULL) return;

  PosH = Hash (pval);  /* determina��o da posi��o de coloca��o */

  NoActual = pseq[PosH];  /* obten��o da cabe�a da respectiva lista */    
  if (NoActual == NULL) pseq[PosH] = NoInserir;  /* no in�cio da lista */
  else
  {
    while (NoActual->PtSeg != NULL)  /* atravessamento da lista */
      NoActual = NoActual->PtSeg;

    NoActual->PtSeg = NoInserir;  /* coloca��o no fim da lista */
  }
}

/******************************************************************************/

PtNo PesquisarTabelaEnc (PtNo pseq[], int pval)
{
  /* pesquisar a lista pendurada na posi��o de dispers�o */
  return PesquisarLista (pseq[Hash (pval)], pval);
}

/******************************************************************************/

void RemoverDaTabelaEnc (PtNo pseq[], int pval)
{
  /* remover o elemento da lista pendurada na posi��o de dispers�o */    
  RemoverElementoDaLista (&pseq[Hash (pval)], pval);
}

/******************************************************************************/

int HashStr (char pstr[])
{
  unsigned int I, N = strlen (pstr), Total = 0;

  for (I = 0; I < N; I++) Total = Total * 8 + pstr[I];

  return Total % MAX_TAB;
}

/******************************************************************************/

int HashU (char pstr[])
{
  unsigned int I, N = strlen (pstr), A = 31415, B = 27183, Total = 0;

  for (I = 0; I < N; I++, A = A * B % (MAX_TAB - 1))
    Total = (Total * A + pstr[I]) % MAX_TAB;

  return Total;
}

/******************************************************************************/
