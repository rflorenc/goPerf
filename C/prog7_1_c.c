#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_estatica.h"  /* interface da pilha estática configurada */

int ParentesesEquivalentes (char, char);  /* alusão ao subprograma */

int main (void)
{
  char Exp[81],       /* expressão lida do teclado para analisar */
      CarPilha;       /* parêntese esquerdo armazenado na pilha */
  unsigned int NCar,  /* número de caracteres da expressão */
                  C;  /* contador do ciclo for */
  int Status;         /* estado de realização da operação da pilha */
  PtStack Pilha;      /* pilha de caracteres */

  Pilha = StackCreate ();  /* criação da pilha */

  printf ("Expressão algébrica -> ");
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
             printf ("Mais parênteses direitos do que esquerdos\n");

             StackDestroy (&Pilha);  /* destruição da pilha */
             return EXIT_SUCCESS;
           }
           else if (!ParentesesEquivalentes (CarPilha, Exp[C]))
                {
                  printf ("Parênteses %c e %c discordantes\n", CarPilha, Exp[C]);

                  StackDestroy (&Pilha);  /* destruição da pilha */
                  return EXIT_SUCCESS;
                }
         }

  Status = StackPop (Pilha, &CarPilha);

  if (Status == STACK_EMPTY) printf ("Expressão com parênteses balanceados\n");
  else printf ("Mais parênteses esquerdos do que direitos\n");

  StackDestroy (&Pilha);  /* destruição da pilha */
  return EXIT_SUCCESS;
}

/* definição do subprograma */
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
