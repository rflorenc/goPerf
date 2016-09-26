#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elemento_cam.h"  /* interface do elemento da CAM */

#include "cam_dinamica_linear.h"  /* interface da CAM dinâmica linear */

/* alusão aos subprogramas */
void LimparRegisto (TELEM *);
void LerCodigo (char *);
void EscreverMensagemErro (int);

int main (void)
{
  int Opcao,        /* opção do utilizador */
      Erro;         /* erro da operação da CAM */
  TELEM Registo;    /* registo para processar */
  PtCAM BaseDados;  /* CAM de elementos TELEM */

  /* criação da CAM */
  if ((BaseDados = CAMCreate (CompararChaveElementos)) == NULL)
  {
    printf ("A base de dados não foi criada!!!\n");
    return EXIT_FAILURE;
  }

  do    /* escrever o menu e ler a opção */
  {
    system ("clear");
    do
    {
      printf ("Aplicação\n\n");
      printf ("1 - Introduzir um registo novo\n");
      printf ("2 - Eliminar um registo existente\n");
      printf ("3 - Listar os registos existentes\n");
      printf ("4 - Saída do programa\n");
      printf ("\nQual é a sua escolha? ");

      scanf ("%1d", &Opcao);  /* ler a opção */
      scanf ("%*[^\n]"); scanf ("%*c");
    } while (Opcao < 1 || Opcao > 4);

    LimparRegisto (&Registo);
    switch (Opcao)
    {
      case 1: LerElemento (&Registo);
              Erro = CAMPut (BaseDados, &Registo);
              if (Erro != OK) EscreverMensagemErro (Erro);
              break;
      case 2: LerCodigo (Registo.Chave);
              Erro = CAMGet (BaseDados, &Registo);
              if (Erro != OK) EscreverMensagemErro (Erro);
              else
              {
                printf ("Eliminado o seguinte registo \n");
                EscreverElemento (&Registo);
                printf ("Tecle return para continuar");
                scanf ("%*[^\n]"); scanf ("%*c");
              }
              break;
      case 3: LerCodigo (Registo.Chave);
              Erro = CAMReadFirst (BaseDados, &Registo);
              if (Erro != OK) { EscreverMensagemErro (Erro); break; }
              printf ("Registos %s\n\n", Registo.Chave);
              EscreverElemento (&Registo);
              printf ("\n");
              while (CAMReadNext (BaseDados, &Registo) == OK)
              {
                EscreverElemento (&Registo); printf ("\n");
              }
              printf ("Tecle return para continuar");
              scanf ("%*[^\n]"); scanf ("%*c");
    }
  } while (Opcao != 4);

  CAMDestroy (&BaseDados);  /* destruição da CAM */
  return EXIT_SUCCESS;
}

/* definição dos subprogramas */

void LimparRegisto (TELEM *pregisto)
{
  strcpy (pregisto->Chave, "");  /* limpar a chave */
  ...;  /* limpar os restantes campos */
}

void LerCodigo (char *pcodigo)
{
  char Formato[30]; int Status;

  sprintf (Formato, "%%%ds", MAX_CHAVE);
  do
  {
    printf ("Código? ");
    Status = scanf (Formato, pcodigo);
    scanf ("%*[^\n]"); scanf ("%*c");
  } while (!Status);
}

void EscreverMensagemErro (int perro)
{
  switch (perro)
  {
    case NO_CAM    : printf ("CAM inexistente\n"); break;
    case NO_MEM    : printf ("Não há memória\n"); break;
    case NULL_PTR  : printf ("Ponteiro nulo\n"); break;
    case CAM_EMPTY : printf ("Base de dados vazia\n"); break;
    case NO_KEY    : printf ("Registo inexistente\n"); break;
    case NO_FUNC   : printf ("Não há função de comparação\n");
  }

  printf ("Tecle return para continuar");
  scanf ("%*[^\n]"); scanf ("%*c");
}

