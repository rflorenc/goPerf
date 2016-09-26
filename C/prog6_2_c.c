#include <stdio.h>
#include <stdlib.h>
#include "elemento_ram.h"  /* interface do elemento */

#define CRESCENTE 1  /* ordena��o crescente */
#define DECRESCENTE -1  /* ordena��o decrescente */

#define INIC 0   /* Inicializa��o */
#define NORM 1   /* Execu��o */
#define REP 2    /* Relat�rio */

/* alus�o aos subprogramas */
unsigned int SwapCount (TELEM *, TELEM *, unsigned int);
unsigned int CmpCount (TELEM *, TELEM *, TPFC, unsigned int);
void SequentialSort (TELEM [], unsigned int, TPFC, int, unsigned int *, unsigned int *);
void Display (TELEM [], unsigned int);

int main (void)
{
  int NElem; unsigned int NComp, NAtr; TPFC PtFComp = NULL;

  TELEM Agenda[] = {
                     { 1, "Antonio", {30, 3, 1983}, "123456789" },
                     { 2, "Manuel", {30, 2, 1973}, "456789123" },
                     { 3, "Vieira", {3, 1, 1933}, "789123456" },
                     { 4, "Zulmira", {3, 12, 1953}, "912783456" },
                     { 5, "Maria", {3, 11, 1953}, "918345627" },
                   };

  NElem = sizeof (Agenda) / sizeof (TELEM);

  /* ordena��o alfab�tica descendente */
  PtFComp = CompararAlfabElementos;

  ...  /* invocar a ordena��o */
  
  printf ("Ordena��o Alfab�tica Descendente\n");
  Display (Agenda, NElem);

  ...  /* imprimir o n� de compara��es e o n� de trocas */

  /* ordena��o cronol�gica crescente */
  PtFComp = CompararCronoElementos;

  ...  /* invocar a ordena��o */

  printf ("Ordena��o Cronol�gica Crescente\n");
  Display (Agenda, NElem);
  
  ...  /* imprimir o n� de compara��es e o n� de trocas */

  /* ordena��o num�rica crescente */
  PtFComp = CompararNumerElementos;

  ...  /* invocar a ordena��o */

  printf ("Ordena��o Num�rica Crescente\n");
  Display (Agenda, NElem);

  ...  /* imprimir o n� de compara��es e o n� de trocas */

  return EXIT_SUCCESS;
}

/* defini��o dos subprogramas */

void Display (TELEM pseq[], unsigned int pnelem)
{
  unsigned int I;

  for (I = 0; I < pnelem; I++)
    EscreverElemento (&pseq[I]);
}

unsigned int SwapCount (TELEM *pelemx, TELEM *pelemy, unsigned int pmodo)
{
  TELEM Temp; static unsigned int Cont;

  if (pmodo == INIC) Cont = 0; 
  else if (pmodo == NORM)
       {
         /* efectuar a troca */
         Temp = *pelemx; *pelemx = *pelemy; *pelemy = Temp;

         /* contar as 3 instru��es de atribui��o */
         Cont += 3;
       }

  return Cont;    /* devolver a contagem */
}

unsigned int CmpCount (TELEM *pelemx, TELEM *pelemy, TPFC pfcomp, unsigned int pmodo)
{
  static unsigned int Cont;

  if (pmodo == INIC) Cont = 0;
  else if (pmodo == NORM)
       {
         Cont++;  /* contar a compara��o */
         return pfcomp (pelemx, pelemy);  /* efectuar a compara��o */
       }

  return Cont;  /* devolver a contagem */
}

void SequentialSort (TELEM pseq[], unsigned int pnelem, TPFC pfcomp, \
                     int ptord, unsigned int *pnc, unsigned int *pna)
{
  unsigned int Indi, Indj;

  /* inicializa��o das vari�veis contadoras */
  CmpCount ((TELEM *) NULL, (TELEM *) NULL, (TPFC) NULL, INIC);
  SwapCount ((TELEM *) NULL, (TELEM *) NULL, INIC);

  for (Indi = 0; Indi < pnelem-1; Indi++)
    for (Indj = Indi+1; Indj < pnelem; Indj++)
      if (CmpCount (&pseq[Indi], &pseq[Indj], pfcomp, NORM) == ptord)
        SwapCount (&pseq[Indi], &pseq[Indj], NORM);

  /* relat�rio das vari�veis contadoras */
  *pnc = CmpCount ((TELEM *) NULL, (TELEM *) NULL, (TPFC) NULL, REP);
  *pna = SwapCount ((TELEM *) NULL, (TELEM *) NULL, REP);
}

