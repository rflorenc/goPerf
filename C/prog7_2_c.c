#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila_estatica.h"  /* interface da fila estática configurada */
#include "pilha_estatica.h"  /* interface da pilha estática configurada */

int main (void)
{
  char Palavra[81],   /* palavra lida do teclado */
           CarFila,   /* carácter armazenado na fila */
          CarPilha;   /* carácter armazenado na pilha */
  unsigned int NCar,  /* número de caracteres da palavra */
                  C;  /* contador do ciclo for */
  PtStack Pilha;      /* pilha de caracteres */
  PtQueue Fila;       /* fila de caracteres */

  Fila = QueueCreate ();  /* criação da fila */
  Pilha = StackCreate ();  /* criação da pilha */

  printf ("Palavra -> ");
  scanf ("%80s", Palavra);
  NCar = strlen (Palavra);

  for (C = 0; C < NCar; C++)
  {
    QueueEnqueue (Fila, Palavra[C]);  /* colocação do carácter na fila */
    StackPush (Pilha, Palavra[C]);  /* colocação do carácter na pilha */
  }

  for (C = 0; C < NCar; C++)
  {
    QueueDequeue (Fila, &CarFila);  /* retirada do carácter da fila */
    StackPop (Pilha, &CarPilha);  /* retirada do carácter da pilha */

    if (CarFila != CarPilha)  /* comparar os caracteres */
    {
      printf ("A palavra não é uma capicua\n");

      QueueDestroy (&Fila);  /* destruição da fila */
      StackDestroy (&Pilha);  /* destruição da pilha */
      return EXIT_SUCCESS;
    }
  }

  printf ("A palavra é uma capicua\n");

  QueueDestroy (&Fila);  /* destruição da fila */
  StackDestroy (&Pilha);  /* destruição da pilha */
  return EXIT_SUCCESS;
}
