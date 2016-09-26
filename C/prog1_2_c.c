#include <stdio.h>

#define DMAX 10  /* número máximo de discos */

/* sequências para as torres A, B e C */
static int TorreA[DMAX], TorreB[DMAX], TorreC[DMAX];
static int NdA, NdB, NdC;  /* número de discos de cada torre */

/* alusão aos subprogramas */
void Inicializar (int, int [], int *, int [], int *, int [], int *);
void ImprimirDiscos (void);
void MudarDiscos (int, int [], int *, int [], int *, int [], int *);

int main (void)
{
  unsigned int NDiscos = 0;  /* número de discos a colocar na Torre A */

  do
  {
    printf ("Numero de discos = "); scanf ("%d", &NDiscos);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (NDiscos <= 0 || NDiscos > DMAX);

  Inicializar (NDiscos, TorreA, &NdA, TorreB, &NdB, TorreC, &NdC);

  printf ("---------------------------------\n");
  printf ("|        Torres de Hanói        |\n");
  printf ("|     Número de discos = %2d     |\n", NDiscos);
  printf ("---------------------------------\n");
  printf ("|  Torre A   Torre B   Torre C  |\n");
  printf ("---------------------------------\n");

  ImprimirDiscos ();  /* imprimir configuração inicial */

  MudarDiscos (NDiscos, TorreA, &NdA, TorreB, &NdB, TorreC, &NdC);

  return 0;
}

/* definição dos subprogramas */

void Inicializar (int pnd, int pta[], int *pnda, int ptb[], int *pndb, int ptc[], int *pndc)
{
  unsigned int I;

  for (I = 0; I < DMAX; I++)    /* inicializar as sequências */
    pta[I] = ptb[I] = ptc[I] = 0;

  for (I = 0; I < pnd; I++) pta[I] = pnd - I;  /* discos na torre A */  

  *pnda = pnd; *pndb = 0; *pndc = 0;  /* inicializar os contadores */  
}

void ImprimirDiscos (void)
{
  unsigned int I, CMax = NdA;

  if (NdB > CMax) CMax = NdB;
  if (NdC > CMax) CMax = NdC;

  for (I = CMax; I > 0; I--)
  {
    if (NdA >= I) printf ("%10d", TorreA[I-1]);
    else printf ("%10c", ' ');
    if (NdB >= I) printf ("%10d", TorreB[I-1]);
    else printf ("%10c", ' ');
    if (NdC >= I) printf ("%10d", TorreC[I-1]);
    else printf ("%10c", ' ');
    printf ("\n");
  }

  printf ("---------------------------------");
  scanf ("%*[^\n]"); scanf ("%*c");
}

void MudarDiscos (int pnd, int pta[], int *pnda, int ptb[], int *pndb, int ptc[], int *pndc)
{
  if (pnd == 1)  /* condição de paragem */
  {
    /* mudar o disco da torre A para a torre B */
    (*pndb)++; ptb[*pndb-1] = pta[*pnda-1]; (*pnda)--;

    ImprimirDiscos ();  /* imprimir configuração após mudar o disco */
  }
  else
  {
    /* mudar os N-1 discos de cima da torre A para a torre C */
    MudarDiscos (pnd-1, pta, pnda, ptc, pndc, ptb, pndb);
  
    /* mudar o último disco da torre A para a torre B */
    (*pndb)++; ptb[*pndb-1] = pta[*pnda-1]; (*pnda)--;

    ImprimirDiscos ();  /* imprimir configuração após mudar o disco */

    /* mudar os N-1 discos da torre C para a torre B */
    MudarDiscos (pnd-1, ptc,pndc, ptb, pndb, pta, pnda);
  }
}
