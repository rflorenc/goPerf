#include <stdio.h>
#include <stdlib.h>

#include "pilha_generica.h"  /* interface da pilha dinâmica genérica */

#define DMAX 10  /* número máximo de discos */

static PtStack TorreA, TorreB, TorreC;  /* pilhas para as torres */
static int NDA, NDB, NDC;  /* número de discos de cada torre */

/* alusão aos subprogramas */
void Inicializar (int, PtStack, int *, int *, int *);
void ImprimirDiscos (void);
void MudarDiscos (int, PtStack, int *, PtStack, int *, PtStack, int *);

int main (void)
{
  int NDiscos;  /* número de discos a colocar na Torre A */

  TorreA = StackCreate (sizeof (int));  /* criação da pilha A */
  TorreB = StackCreate (sizeof (int));  /* criação da pilha B */
  TorreC = StackCreate (sizeof (int));  /* criação da pilha C */

  do
  {
    printf ("Numero de discos = ");
    scanf ("%d", &NDiscos);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (NDiscos <= 0 || NDiscos > DMAX);

  Inicializar (NDiscos, TorreA, &NDA, &NDB, &NDC);
  printf ("---------------------------------\n");
  printf ("|        Torres de Hanoi        |\n");
  printf ("|     Numero de discos = %2d     |\n", NDiscos);
  printf ("---------------------------------\n");
  printf ("|  Torre A   Torre B   Torre C  |\n");
  printf ("---------------------------------\n");
  ImprimirDiscos ();  /* apresentar as torres inicialmente */

  MudarDiscos (NDiscos, TorreA, &NDA, TorreB, &NDB, TorreC, &NDC);

  StackDestroy (&TorreA);  /* destruição da pilha A */
  StackDestroy (&TorreB);  /* destruição da pilha B */
  StackDestroy (&TorreC);  /* destruição da pilha C */

  return EXIT_SUCCESS;
}

/* definição dos subprogramas */

void Inicializar (int pnd, PtStack pta, int *pnda, int *pndb, int *pndc)
{
  unsigned int I;

  /* colocar os discos na Torre A */
  for (I = pnd; I > 0; I--) StackPush (pta, &I);

  *pnda = pnd; *pndb = 0; *pndc = 0;
}

void ImprimirDiscos (void)
{
  unsigned int L,  /* contador do ciclo for */
           Disco,  /* disco mostrado no monitor */
            CMax;  /* torre com mais discos que condiciona a impressão */

  /* construir as torres auxiliares */
  PtStack TauxA = StackCreate (sizeof (int));
  PtStack TauxB = StackCreate (sizeof (int));
  PtStack TauxC = StackCreate (sizeof (int));

  CMax = NDA;  /* calcular a torre com mais discos */
  if (NDB > CMax) CMax = NDB;
  if (NDC > CMax) CMax = NDC;

  for (L = CMax; L > 0; L--)  /* mostrar o conteúdo das torres */
  {
    if (NDA >= L) 
    {
      StackPop (TorreA, &Disco); StackPush (TauxA, &Disco);
      printf ("%10d", Disco);
    }
    else printf ("%10c", ' ');

    if (NDB >= L)
    {
      StackPop (TorreB, &Disco); StackPush (TauxB, &Disco);
      printf ("%10d", Disco);
    }
    else printf ("%10c", ' ');

    if (NDC >= L)
    {
      StackPop (TorreC, &Disco); StackPush (TauxC, &Disco);
      printf ("%10d", Disco);
    }
    else printf ("%10c", ' ');

    printf ("\n");
  }

  printf ("---------------------------------\n");
  scanf ("%*[^\n]"); scanf ("%*c");

  /* repor o conteúdo das torres e destruir as torres auxiliares */
  while (StackPop (TauxA, &Disco) != STACK_EMPTY) StackPush (TorreA, &Disco); 
  while (StackPop (TauxB, &Disco) != STACK_EMPTY) StackPush (TorreB, &Disco); 
  while (StackPop (TauxC, &Disco) != STACK_EMPTY) StackPush (TorreC, &Disco);

  StackDestroy (&TauxA);
  StackDestroy (&TauxB);
  StackDestroy (&TauxC);
}

void MudarDiscos (int pnd, PtStack pta, int *pnda, PtStack ptb, int *pndb, PtStack ptc, int *pndc)
{
  unsigned int Disco;  /* disco movimentado entre duas torres */

  if (pnd == 1)  /* condição de paragem */
  {
    /* mudar o disco da Torre A para a Torre B */
    StackPop (pta, &Disco); (*pnda)--;
    StackPush (ptb, &Disco); (*pndb)++;

    ImprimirDiscos ();  /* imprimir configuração após mudar o disco */
  }
  else
  {
    /* mudar os N-1 discos de cima da Torre A para a Torre C */
    MudarDiscos (pnd-1, pta, pnda, ptc, pndc, ptb, pndb);

    /* mudar o disco de baixo da Torre A para a Torre B */
    StackPop (pta, &Disco); (*pnda)--;
    StackPush (ptb, &Disco); (*pndb)++;

    ImprimirDiscos ();  /* imprimir configuração após mudar o disco */

    /* mudar os N-1 discos da Torre C para a Torre B */
    MudarDiscos (pnd-1, ptc, pndc, ptb, pndb, pta, pnda);
  }
}
