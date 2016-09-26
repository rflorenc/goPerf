#include <stdio.h>

#define DMAX 10  /* n�mero m�ximo de discos */

/* sequ�ncias para as torres A, B e C */
static int TorreA[DMAX], TorreB[DMAX], TorreC[DMAX];
static int NdA, NdB, NdC;  /* n�mero de discos de cada torre */

/* alus�o aos subprogramas */
void Inicializar (int, int [], int *, int [], int *, int [], int *);
void ImprimirDiscos (void);
void MudarDiscos (int, int [], int *, int [], int *, int [], int *);

int main (void)
{
  unsigned int NDiscos = 0;  /* n�mero de discos a colocar na Torre A */

  do
  {
    printf ("Numero de discos = "); scanf ("%d", &NDiscos);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (NDiscos <= 0 || NDiscos > DMAX);

  Inicializar (NDiscos, TorreA, &NdA, TorreB, &NdB, TorreC, &NdC);

  printf ("---------------------------------\n");
  printf ("|        Torres de Han�i        |\n");
  printf ("|     N�mero de discos = %2d     |\n", NDiscos);
  printf ("---------------------------------\n");
  printf ("|  Torre A   Torre B   Torre C  |\n");
  printf ("---------------------------------\n");

  ImprimirDiscos ();  /* imprimir configura��o inicial */

  MudarDiscos (NDiscos, TorreA, &NdA, TorreB, &NdB, TorreC, &NdC);

  return 0;
}

/* defini��o dos subprogramas */

void Inicializar (int pnd, int pta[], int *pnda, int ptb[], int *pndb, int ptc[], int *pndc)
{
  unsigned int I;

  for (I = 0; I < DMAX; I++)    /* inicializar as sequ�ncias */
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
  if (pnd == 1)  /* condi��o de paragem */
  {
    /* mudar o disco da torre A para a torre B */
    (*pndb)++; ptb[*pndb-1] = pta[*pnda-1]; (*pnda)--;

    ImprimirDiscos ();  /* imprimir configura��o ap�s mudar o disco */
  }
  else
  {
    /* mudar os N-1 discos de cima da torre A para a torre C */
    MudarDiscos (pnd-1, pta, pnda, ptc, pndc, ptb, pndb);
  
    /* mudar o �ltimo disco da torre A para a torre B */
    (*pndb)++; ptb[*pndb-1] = pta[*pnda-1]; (*pnda)--;

    ImprimirDiscos ();  /* imprimir configura��o ap�s mudar o disco */

    /* mudar os N-1 discos da torre C para a torre B */
    MudarDiscos (pnd-1, ptc,pndc, ptb, pndb, pta, pnda);
  }
}
