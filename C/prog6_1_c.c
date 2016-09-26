#include <stdio.h>
#include <stdlib.h>
#include "elemento_ram.h"  /* interface do elemento */

#define CRESCENTE 1  /* ordenação crescente */
#define DECRESCENTE -1  /* ordenação decrescente */

/* alusão aos subprogramas */
void SwapElementos (TELEM *, TELEM *);
void SequentialSort (TELEM [], unsigned int, TPFC, int);
void Display (TELEM [], unsigned int);

int main (void)
{
  int NElem; TPFC PtFComp = NULL;

  TELEM Agenda[] = {
                     { 1, "Antonio", {30, 3, 1983}, "123456789" },
                     { 2, "Manuel", {30, 2, 1973}, "456789123" },
                     { 3, "Vieira", {3, 1, 1933}, "789123456" },
                     { 4, "Zulmira", {3, 12, 1953}, "912783456" },
                     { 5, "Maria", {3, 11, 1953}, "918345627" },
                   };

  NElem = sizeof (Agenda) / sizeof (TELEM);

  /* ordenação alfabética descendente */
  PtFComp = CompararAlfabElementos;
  SequentialSort (Agenda, NElem, PtFComp, DECRESCENTE);
  printf ("Ordenação Alfabética Descendente\n");
  Display (Agenda, NElem);

  /* ordenação cronológica crescente */
  PtFComp = CompararCronoElementos;
  SequentialSort (Agenda, NElem, PtFComp, CRESCENTE);
  printf ("Ordenação Cronológica Crescente\n");
  Display (Agenda, NElem);
  
  /* ordenação numérica crescente */
  PtFComp = CompararNumerElementos;  /* ordenação numérica */
  SequentialSort (Agenda, NElem, PtFComp, CRESCENTE);
  printf ("Ordenação Numérica Crescente\n");
  Display (Agenda, NElem);

  return EXIT_SUCCESS;
}

/* definição dos subprogramas */

void Display (TELEM pseq[], unsigned int pnelem)
{
  unsigned int I;

  for (I = 0; I < pnelem; I++)
    EscreverElemento (&pseq[I]);
}

void SwapElementos (TELEM *pelemx, TELEM *pelemy)
{
  TELEM Temp;

  Temp = *pelemx; *pelemx = *pelemy; *pelemy = Temp;
}

void SequentialSort (TELEM pseq[], unsigned int pnelem, TPFC pfcomp, int ptord)
{
  unsigned int Indi, Indj;

  for (Indi = 0; Indi < pnelem-1; Indi++)
    for (Indj = Indi+1; Indj < pnelem; Indj++)
      if (pfcomp (&pseq[Indi], &pseq[Indj]) == ptord)
        SwapElementos (&pseq[Indi], &pseq[Indj]);  /* trocar os elementos */
}

