#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"  /* ficheiro de interface do TAD COMPLEXO */

void LerComplexo (PtComplexo *);
void EscreverComplexo (PtComplexo, char *);

int main (void)
{
  PtComplexo Comp1 = NULL, Comp2 = NULL, CompR = NULL; int Opcao;
  PtComplexo (*APtFunc[4]) (PtComplexo, PtComplexo) = \
        { SomarComplexos, SubtrairComplexos, MultiplicarComplexos, DividirComplexos };

  Comp1 = InicializarComplexo (0.0, 0.0);
  Comp2 = InicializarComplexo (0.0, 0.0);

  do
  {
    system ("clear");
    printf ("\t1 - Ler o primeiro complexo\n");
    printf ("\t2 - Ler o segundo complexo\n");
    printf ("\t3 - Somar os complexos\n");
    printf ("\t4 - Subtrair os complexos\n");
    printf ("\t5 - Multiplicar os complexos\n");
    printf ("\t6 - Dividir os complexos\n");
    printf ("\t7 - Terminar o programa\n");

    do
    {  
      printf ("\n\tOpção -> "); scanf ("%d", &Opcao);
      scanf ("%*[^\n]"); scanf ("%*c");
    } while (Opcao < 1 || Opcao > 7);

    InicializarErroComplexo ();

    switch (Opcao)
    {
      case 1 : LerComplexo (&Comp1); break;
      case 2 : LerComplexo (&Comp2); break;
      case 3 :
      case 4 :
      case 5 :
      case 6 : CompR = (*APtFunc[Opcao-3]) (Comp1, Comp2); break;
    }

    if (Opcao > 2 && Opcao < 7)
    {
      if (!ErroComplexo ())
      {
        EscreverComplexo (CompR, "Resultado Complexo");
        ApagarComplexo (&CompR);
      }
      else printf ("Erro -> %s\n", MensagemErroComplexo ());
    }
      
    if (Opcao != 7)
    {
      printf ("Carregue em Enter para continuar ");
      scanf ("%*[^\n]"); scanf ("%*c");
    }

  } while (Opcao != 7);

  ApagarComplexo (&Comp1);
  ApagarComplexo (&Comp2);

  return EXIT_SUCCESS;
}

/* definição dos subprogramas */

void LerComplexo (PtComplexo *pnc)
{
  double VReal, VImag; int Status;

  do
  {
    printf ("Parte Real? ");
    Status = scanf ("%lf", &VReal);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (!Status);

  do
  {
    printf ("Parte Imaginária? ");
    Status = scanf ("%lf", &VImag);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (!Status);

  if (*pnc != NULL) ApagarComplexo (pnc);

  *pnc = InicializarComplexo (VReal, VImag);
}

void EscreverComplexo (PtComplexo pnc, char *pmsg)
{
  if (pnc != NULL)
    printf ("%s %f +j %f\n", pmsg, ParteReal (pnc), ParteImaginaria (pnc));
}  
