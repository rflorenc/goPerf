#include <stdio.h>
#include <string.h>

/* alus�o aos subprogramas */
void Permutacoes (char [], unsigned int, unsigned int);

int main (void)
{
  char Lista[11];    /* sequ�ncia de caracteres */
  unsigned int N;    /* n�mero de caracteres */

  printf ("Caracteres a permutar -> ");
  scanf ("%10s", Lista);  /* leitura da sequ�ncia de caracteres */

  N = strlen (Lista);  /* determina��o do n�mero de caracteres */

  printf ("Permuta��es\n\n");

  Permutacoes (Lista, 0, N-1);

  return 0;
}

/* defini��o dos subprogramas */

void Permutacoes (char plista[], unsigned int pi, unsigned int pn)
{
  unsigned int J;

  void Troca (char *, char *);  /* alus�o ao subprograma Troca */

  if (pi == pn)  /* condi��o de paragem */
       printf ("%s\n", plista);  /* imprimir a permuta��o gerada */
  else for (J = pi; J <= pn; J++)  /* para todos os caracteres */
       {
         Troca (&plista[pi], &plista[J]);  /* car�cter � direita */
         Permutacoes (plista, pi+1, pn);    /* permutar n-1 caracteres */
         Troca (&plista[J], &plista[pi]);  /* repor o car�cter */
       }
}

void Troca (char *pcari, char *pcarj)
{
  char Temp;

  Temp = *pcari; *pcari = *pcarj; *pcarj = Temp;
}



