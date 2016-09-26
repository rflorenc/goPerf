#define NMAX 10

double CalcDeterminante (double pmatriz[][NMAX], unsigned int pn)
{
  unsigned int ColAux, NC, NL, UC = pn-1; double Elemento;

  if (pn == 1) return pmatriz[0][0];  /* condi��o de paragem */
  else
  {
    ColAux = UC;  /* procurar coluna com �ltimo elemento ? 0 */

    while (ColAux >= 0 && pmatriz[UC][ColAux] == 0) ColAux--;

    if (ColAux >= 0)  /* se existir tal coluna */
    {
      if (ColAux != UC)  /* se n�o for a �ltima coluna */
        for (NL = 0; NL < pn; NL++)  /* trocar as colunas */
        {
          Elemento = pmatriz[NL][UC];
          pmatriz[NL][UC] = pmatriz[NL][ColAux];
          pmatriz[NL][ColAux] = -Elemento;
        }

      /* dividir a �ltima coluna pelo �ltimo elemento */
      for (NL = 0; NL < UC; NL++) pmatriz[NL][UC] /= pmatriz[UC][UC];

      /* subtrair todas as colunas menos a �ltima pela �ltima coluna */
      /* multiplicada pelo �ltimo elemento da coluna a processar */
      for (NC = 0; NC < UC; NC++)
        for (NL = 0; NL < UC; NL++)
          pmatriz[NL][NC] -= pmatriz[NL][UC] * pmatriz[UC][NC];

      /* invoca��o recursiva para a matriz de dimens�o N-1 */
      return pmatriz[UC][UC] * CalcDeterminante (pmatriz, pn-1);
    }
    else return 0;
  }
}

