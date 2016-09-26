#include <stdio.h>
#include <string.h>

/* alusão aos subprogramas */
void Permutacoes (char [], unsigned int, unsigned int);

int main (void)
{
  char Lista[11];    /* sequência de caracteres */
  unsigned int N;    /* número de caracteres */

  printf ("Caracteres a permutar -> ");
  scanf ("%10s", Lista);  /* leitura da sequência de caracteres */

  N = strlen (Lista);  /* determinação do número de caracteres */

  printf ("Permutações\n\n");

  Permutacoes (Lista, 0, N-1);

  return 0;
}

/* definição dos subprogramas */

void Permutacoes (char plista[], unsigned int pi, unsigned int pn)
{
  unsigned int J;

  void Troca (char *, char *);  /* alusão ao subprograma Troca */

  if (pi == pn)  /* condição de paragem */
       printf ("%s\n", plista);  /* imprimir a permutação gerada */
  else for (J = pi; J <= pn; J++)  /* para todos os caracteres */
       {
         Troca (&plista[pi], &plista[J]);  /* carácter à direita */
         Permutacoes (plista, pi+1, pn);    /* permutar n-1 caracteres */
         Troca (&plista[J], &plista[pi]);  /* repor o carácter */
       }
}

void Troca (char *pcari, char *pcarj)
{
  char Temp;

  Temp = *pcari; *pcari = *pcarj; *pcarj = Temp;
}



