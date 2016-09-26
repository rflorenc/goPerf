#include <stdio.h>

#define DIM_TAB 8  /* dimensão do tabuleiro */

typedef enum { LIVRE, RAINHA, ATACADA } TCASA;  /* casa do tabuleiro */

/* alusão aos subprogramas */
void InicializarTabuleiro (TCASA [][]);
void ImprimirConfiguracao (TCASA [][]);
void CopiarTabuleiro (TCASA [][], TCASA [][]);
void ColocarRainhas (TCASA [][], int);

int main (void)
{
  TCASA Tabuleiro[DIM_TAB][DIM_TAB];  /* tabuleiro */

  InicializarTabuleiro (Tabuleiro);

  ColocarRainhas (Tabuleiro, 0);

  return 0;
}

/* definição dos subprogramas */

void InicializarTabuleiro (TCASA ptabuleiro[][DIM_TAB])
{
  unsigned int Linha, Coluna;

  for (Linha = 0; Linha < DIM_TAB; Linha++)
    for (Coluna = 0; Coluna < DIM_TAB; Coluna++)
      ptabuleiro[Linha][Coluna] = LIVRE;
}

void ImprimirConfiguracao (TCASA ptabuleiro[][DIM_TAB])
{
  unsigned int Linha, Coluna; static unsigned int Conf = 0;

  printf ("Configuração nº %2d", ++Conf);

  for (Coluna = 0; Coluna < DIM_TAB; Coluna++)
    for (Linha = 0; Linha < DIM_TAB; Linha++)
      if (ptabuleiro[Linha][Coluna] == RAINHA)
      {
        printf (" - %d", Linha+1);
        break;
      }

  printf ("\n");
}

void CopiarTabuleiro (TCASA ptorig[][DIM_TAB], TCASA ptdest[][DIM_TAB])
{
  unsigned int Linha, Coluna;

  for (Linha = 0; Linha < DIM_TAB; Linha++)
    for (Coluna = 0; Coluna < DIM_TAB; Coluna++)
      ptdest[Linha][Coluna] = ptorig[Linha][Coluna];
}

void ColocarRainhas (TCASA ptabuleiro[][DIM_TAB], int pnrainhas)
{
  unsigned int Linha, Col; int DAsc, DDesc;
  TCASA TabAuxiliar[DIM_TAB][DIM_TAB];  /* tabuleiro auxiliar */

  if (pnrainhas == DIM_TAB)  /* condição de paragem */
    ImprimirConfiguracao (ptabuleiro);
  else
  {
    Linha = 0;
    while (Linha < DIM_TAB)
    {
      /* determinar a primeira linha livre para colocar a rainha */
      while (ptabuleiro[Linha][pnrainhas] != LIVRE && Linha < DIM_TAB) Linha++;

      if (Linha < DIM_TAB)
      {
        /* armazenar a configuração antes de colocar a rainha  */
        CopiarTabuleiro (ptabuleiro, TabAuxiliar);

        /* colocar a rainha na linha livre */
        ptabuleiro[Linha][pnrainhas] = RAINHA;

        DAsc = Linha-1; DDesc = Linha+1;
        for (Col = pnrainhas+1; Col < DIM_TAB; Col++, DAsc--, DDesc++)
        {
          /* marcar a linha atacada */
          ptabuleiro[Linha][Col] = ATACADA;
          /* marcar a diagonal ascendente atacada */
          if (DAsc >= 0) ptabuleiro[DAsc][Col] = ATACADA;
          /* marcar a diagonal descendente atacada */
          if (DDesc < DIM_TAB) ptabuleiro[DDesc][Col] = ATACADA;
        }

        /* invocação recursiva */
        ColocarRainhas (ptabuleiro, pnrainhas+1);

        /* recuperar a configuração anterior */
        CopiarTabuleiro (TabAuxiliar, ptabuleiro);

        /* marcar a linha anteriormente testada como atacada */
        ptabuleiro[Linha][pnrainhas] = ATACADA;

        /* passar à linha seguinte */
        Linha++;
      }
    }
  }
}
