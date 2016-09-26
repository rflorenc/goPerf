#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade_amontoado_configurada.h"  /* Interface da Fila */
#include "elemento_cam.h"  /* interface do elemento */

int main (int argc, char *argv[])
{
  FILE *PtF; unsigned int Num, I; TELEM Elemento; PtPQueue PQueue;

  if (argc < 2)  /* o número de argumentos é suficiente? */
  {
    fprintf (stderr, "Uso: %s ficheiro\n", argv[0]);
    exit (EXIT_FAILURE);
  }

  if ((PtF = fopen (argv[1], "rb")) == NULL)
  {
    fprintf (stderr, "O ficheiro %s não existe\n", argv[1]);
    return EXIT_FAILURE;
  }

  /* leitura da dimensão do ficheiro e criação da Fila com Prioridade */
  fread (&Num, sizeof (unsigned int), 1, PtF);
  if ((PQueue = PQueueCreate (Num, CompararChaveElementos)) == NULL)  
  {
    fprintf (stderr, "Não foi possível criar a fila com prioridade\n");
    fclose (PtF);  /* fecho do ficheiro */
    return EXIT_FAILURE;
  }

  /* leitura do ficheiro e inserção na Fila com Prioridade */
  for (I = 0; I < Num; I++)
  {
    fread (&Elemento, sizeof (TELEM), 1, PtF);
    PQueueInsert (PQueue, &Elemento);
  }

  fclose (PtF);  /* fecho do ficheiro */

  printf ("Ficheiro por ordem decrescente\n");

  /* remoção da Fila com Prioridade e escrita no monitor */
  while (PQueueDeleteMax (PQueue, &Elemento) != PQUEUE_EMPTY)
    EscreverElemento (&Elemento);

  PQueueDestroy (&PQueue);  /* destruição da Fila com Prioridade */

  return EXIT_SUCCESS;
}
