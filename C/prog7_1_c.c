#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_estatica.h"  /* interface da pilha est�tica configurada */

int ParentesesEquivalentes (char, char);  /* alus�o ao subprograma */

int main (void)
{
  char Exp[81],       /* express�o lida do teclado para analisar */
      CarPilha;       /* par�ntese esquerdo armazenado na pilha */
  unsigned int NCar,  /* n�mero de caracteres da express�o */
                  C;  /* contador do ciclo for */
  int Status;         /* estado de realiza��o da opera��o da pilha */
  PtStack Pilha;      /* pilha de caracteres */

  Pilha = StackCreate ();  /* cria��o da pilha */

  printf ("Express�o alg�brica -> ");
  scanf ("%80s", Exp);
  NCar = strlen (Exp);

  for (C = 0; C < NCar; C++)
    if (Exp[C] == '(' || Exp[C] == '[' || Exp[C] == '{')
         StackPush (Pilha, Exp[C]);
    else if (Exp[C] == ')' || Exp[C] == ']' || Exp[C] == '}')
         {
           Status = StackPop (Pilha, &CarPilha);

           if (Status == STACK_EMPTY)
           {
             printf ("Mais par�nteses direitos do que esquerdos\n");

             StackDestroy (&Pilha);  /* destrui��o da pilha */
             return EXIT_SUCCESS;
           }
           else if (!ParentesesEquivalentes (CarPilha, Exp[C]))
                {
                  printf ("Par�nteses %c e %c discordantes\n", CarPilha, Exp[C]);

                  StackDestroy (&Pilha);  /* destrui��o da pilha */
                  return EXIT_SUCCESS;
                }
         }

  Status = StackPop (Pilha, &CarPilha);

  if (Status == STACK_EMPTY) printf ("Express�o com par�nteses balanceados\n");
  else printf ("Mais par�nteses esquerdos do que direitos\n");

  StackDestroy (&Pilha);  /* destrui��o da pilha */
  return EXIT_SUCCESS;
}

/* defini��o do subprograma */
int ParentesesEquivalentes (char pparesq, char ppardir)
{
  switch (pparesq)
  {
    case '(' : return ppardir == ')'; break;
    case '[' : return ppardir == ']'; break;
    case '{' : return ppardir == '}'; break;
    default  : return 0;
  }
}
