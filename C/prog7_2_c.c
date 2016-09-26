#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila_estatica.h"  /* interface da fila est�tica configurada */
#include "pilha_estatica.h"  /* interface da pilha est�tica configurada */

int main (void)
{
  char Palavra[81],   /* palavra lida do teclado */
           CarFila,   /* car�cter armazenado na fila */
          CarPilha;   /* car�cter armazenado na pilha */
  unsigned int NCar,  /* n�mero de caracteres da palavra */
                  C;  /* contador do ciclo for */
  PtStack Pilha;      /* pilha de caracteres */
  PtQueue Fila;       /* fila de caracteres */

  Fila = QueueCreate ();  /* cria��o da fila */
  Pilha = StackCreate ();  /* cria��o da pilha */

  printf ("Palavra -> ");
  scanf ("%80s", Palavra);
  NCar = strlen (Palavra);

  for (C = 0; C < NCar; C++)
  {
    QueueEnqueue (Fila, Palavra[C]);  /* coloca��o do car�cter na fila */
    StackPush (Pilha, Palavra[C]);  /* coloca��o do car�cter na pilha */
  }

  for (C = 0; C < NCar; C++)
  {
    QueueDequeue (Fila, &CarFila);  /* retirada do car�cter da fila */
    StackPop (Pilha, &CarPilha);  /* retirada do car�cter da pilha */

    if (CarFila != CarPilha)  /* comparar os caracteres */
    {
      printf ("A palavra n�o � uma capicua\n");

      QueueDestroy (&Fila);  /* destrui��o da fila */
      StackDestroy (&Pilha);  /* destrui��o da pilha */
      return EXIT_SUCCESS;
    }
  }

  printf ("A palavra � uma capicua\n");

  QueueDestroy (&Fila);  /* destrui��o da fila */
  StackDestroy (&Pilha);  /* destrui��o da pilha */
  return EXIT_SUCCESS;
}
