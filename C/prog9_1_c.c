#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade_amontoado_configurada.h"  /* Interface da Fila */
#include "elemento_cam.h"  /* interface do elemento */

int main (int argc, char *argv[])
{
  FILE *PtF; unsigned int Num, I; TELEM Elemento; PtPQueue PQueue;

  if (argc < 2)  /* o n�mero de argumentos � suficiente? */
  {
    fprintf (stderr, "Uso: %s ficheiro\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  if ((PtF = fopen (argv[1], "rb")) == NULL)
  {
    fprintf (stderr, "O ficheiro %s n�o existe\n", argv[1]);
    return EXIT_FAILURE;
  }

  /* leitura da dimens�o do ficheiro e cria��o da Fila com Prioridade */
  fread (&Num, sizeof (unsigned int), 1, PtF);
  if ((PQueue = PQueueCreate (Num, CompararChaveElementos)) == NULL)  
  {
    fprintf (stderr, "N�o foi poss�vel criar a fila com prioridade\n");
    fclose (PtF);  /* fecho do ficheiro */
    return EXIT_FAILURE;
  }

  /* leitura do ficheiro e inser��o na Fila com Prioridade */
  for (I = 0; I < Num; I++)
  {
    fread (&Elemento, sizeof (TELEM), 1, PtF);
    PQueueInsert (PQueue, &Elemento);
  }

  fclose (PtF);  /* fecho do ficheiro */

  printf ("Ficheiro por ordem decrescente\n");

  /* remo��o da Fila com Prioridade e escrita no monitor */
  while (PQueueDeleteMax (PQueue, &Elemento) != PQUEUE_EMPTY)
    EscreverElemento (&Elemento);

  PQueueDestroy (&PQueue);  /* destrui��o da Fila com Prioridade */

  return EXIT_SUCCESS;
}
