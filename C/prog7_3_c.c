#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha_dinamica.h"  /* interface da pilha dinâmica configurada */
int PrecOp (char);  /* alusão ao subprograma */

int main (void)
{
  char  ExpEnt[81],  /* expressão infixo de entrada */
   ExpSai[81] = "",  /* expressão sufixo de saída */
          CarPilha;  /* carácter armazenado na pilha */
  unsigned int NCE,  /* número de símbolos da expressão infixo */
                 C,  /* contador do ciclo for */
           NCS = 0;  /* número de caracteres da expressão sufixo */
  int St;            /* estado de realização da operação da pilha */
  PtStack Pilha;     /* pilha de caracteres */

  Pilha = StackCreate ();  /* criação da pilha */

  printf ("Expressão algébrica -> "); scanf ("%80s", ExpEnt);
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
  ExpSai[NCS] = '\0';  /* terminar a expressão sufixo */

  printf ("Expressão Infixo -> %s\n", ExpEnt);
  printf ("Expressão Sufixo -> %s\n", ExpSai);

  StackDestroy (&Pilha);  /* destruição da pilha */
  return EXIT_SUCCESS;
}

/* definição do subprograma */
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
