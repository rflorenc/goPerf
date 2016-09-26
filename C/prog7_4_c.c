#include <stdio.h>
#include <stdlib.h>

#include "pilha_dinamica.h"  /* interface da pilha din�mica configurada */

void DisplayPush (PtStack, double);  /* alus�o ao subprograma */

int main (void)
{
  char  Comando[21],    /* comando de entrada */
                 Op;    /* opera��o a efectuar */
  double Oper1, Oper2;  /* operandos a processar */
  PtStack Pilha;        /* pilha de caracteres */

  Pilha = StackCreate ();  /* cria��o da pilha */

  do
  {
    printf ("Comando -> "); scanf("%20s", Comando);
    scanf("%*[^\n]"); scanf("%*c");

    if (sscanf(Comando, "%1[+-*/~=]", &Op) == 1)  /* opera��o */
      switch (Op)  
      {
        case '+' : if (StackPop (Pilha, &Oper2) == OK)  /* adi��o */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 += Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '-' : if (StackPop (Pilha, &Oper2) == OK)  /* subtrac��o */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 -= Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '*' : if (StackPop (Pilha, &Oper2) == OK)  /* multipli��o */
                   if (StackPop (Pilha, &Oper1) == OK)
                   {
                     Oper1 *= Oper2; DisplayPush (Pilha, Oper1);
                   }
                   else StackPush (Pilha, Oper2);
                   break;
        case '/' : if (StackPop (Pilha, &Oper2) == OK)  /* divis�o */
                   if (StackPop (Pilha, &Oper1) == OK)
                     if (Oper2 != 0.0)
                     {
                       Oper1 /= Oper2; DisplayPush (Pilha, Oper1);
                     }
                     else ;
                   else StackPush (Pilha, Oper2);
                   break;
        case '~' : if (StackPop (Pilha, &Oper1) == OK)  /* sim�trico */
                   {
                     Oper1 = -Oper1; DisplayPush (Pilha, Oper1);
                   }
                   break;
      }
    else if (sscanf(Comando, "%lf", &Oper1) == 1) 
              StackPush (Pilha, Oper1);  /* o comando � um operando */
         else fprintf (stderr, "\nComando n�o previsto\n\n");
  } while (Op != '=');

  StackDestroy (&Pilha);  /* destrui��o da pilha */
  return EXIT_SUCCESS;
}

/* defini��o do subprograma */
void DisplayPush (PtStack pstack, double presult)
{
  printf ("\t\tResultado -> %f\n", presult);
  StackPush (pstack, presult);
}
