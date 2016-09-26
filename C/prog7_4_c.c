#include <stdio.h>
#include <stdlib.h>

#include "pilha_dinamica.h"  /* interface da pilha dinâmica configurada */

void DisplayPush (PtStack, double);  /* alusão ao subprograma */

int main (void)
{
  char  Comando[21],    /* comando de entrada */
                 Op;    /* operação a efectuar */
  double Oper1, Oper2;  /* operandos a processar */
  PtStack Pilha;        /* pilha de caracteres */

  Pilha = StackCreate ();  /* criação da pilha */

  do
  {
    printf ("Comando -> "); scanf("%20s", Comando);
    scanf("%*[^\n]"); scanf("%*c");

    if (sscanf(Comando, "%1[+-*/~=]", &Op) == 1)  /* operação */
      switch (Op)  
      {
        case '+' : if (StackPop (Pilha, &Oper2) == OK)  /* adição */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 += Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '-' : if (StackPop (Pilha, &Oper2) == OK)  /* subtracção */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 -= Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '*' : if (StackPop (Pilha, &Oper2) == OK)  /* multiplição */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 *= Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '/' : if (StackPop (Pilha, &Oper2) == OK)  /* divisão */
                   if (StackPop (Pilha, &Oper1) == OK)
                     if (Oper2 != 0.0)
                     {
                       Oper1 /= Oper2; DisplayPush (Pilha, Oper1);
                     }
                     else ;
                   else StackPush (Pilha, Oper2);
                   break;
        case '~' : if (StackPop (Pilha, &Oper1) == OK)  /* simétrico */
                   {
                     Oper1 = -Oper1; DisplayPush (Pilha, Oper1);
                   }
                   break;
      }
    else if (sscanf(Comando, "%lf", &Oper1) == 1) 
              StackPush (Pilha, Oper1);  /* o comando é um operando */
         else fprintf (stderr, "\nComando não previsto\n\n");
  } while (Op != '=');

  StackDestroy (&Pilha);  /* destruição da pilha */
  return EXIT_SUCCESS;
}

/* definição do subprograma */
void DisplayPush (PtStack pstack, double presult)
{
  printf ("\t\tResultado -> %f\n", presult);
  StackPush (pstack, presult);
}
