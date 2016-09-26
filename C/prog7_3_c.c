#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_dinamica.h"  /* interface da pilha din�mica configurada */
int PrecOp (char);  /* alus�o ao subprograma */

int main (void)
{
  char  ExpEnt[81],  /* express�o infixo de entrada */
   ExpSai[81] = "",  /* express�o sufixo de sa�da */
          CarPilha;  /* car�cter armazenado na pilha */
  unsigned int NCE,  /* n�mero de s�mbolos da express�o infixo */
                 C,  /* contador do ciclo for */
           NCS = 0;  /* n�mero de caracteres da express�o sufixo */
  int St;            /* estado de realiza��o da opera��o da pilha */
  PtStack Pilha;     /* pilha de caracteres */

  Pilha = StackCreate ();  /* cria��o da pilha */

  printf ("Express�o alg�brica -> "); scanf ("%80s", ExpEnt);
  NCE = strlen (ExpEnt);

  for (C = 0; C < NCE; C++)
    switch (ExpEnt[C])
    {
      case '(' : StackPush (Pilha, ExpEnt[C]); break;
      case ')' : while ( StackPop (Pilha, &CarPilha) != STACK_EMPTY && CarPilha != '(' )
                   ExpSai [NCS++] = CarPilha;
                 break;
      case '*' :
      case '/' :
      case '+' :
      case '-' : while ( (St = StackPop (Pilha, &CarPilha)) != STACK_EMPTY && CarPilha != '('
                         && PrecOp (ExpEnt[C]) <= PrecOp (CarPilha) )
                   ExpSai[NCS++] = CarPilha;
                 if (St != STACK_EMPTY) StackPush (Pilha, CarPilha);
                 StackPush (Pilha, ExpEnt[C]);
                 break;
      default  : ExpSai[NCS++] = ExpEnt[C];
    }

  while (StackPop (Pilha, &CarPilha) != STACK_EMPTY) ExpSai[NCS++] = CarPilha;
  ExpSai[NCS] = '\0';  /* terminar a express�o sufixo */

  printf ("Express�o Infixo -> %s\n", ExpEnt);
  printf ("Express�o Sufixo -> %s\n", ExpSai);

  StackDestroy (&Pilha);  /* destrui��o da pilha */
  return EXIT_SUCCESS;
}

/* defini��o do subprograma */
int PrecOp (char poper)
{
  switch (poper)
  {
    case '*' :
    case '/' : return 2; break;
    case '+' :
    case '-' : return 1; break;
    default  : return 0;
  }
}
