#define NMAX 10

double CalcDeterminante (double pmatriz[][NMAX], unsigned int pn)
{
  unsigned int ColAux, NC, NL, UC = pn-1; double Elemento;

  if (pn == 1) return pmatriz[0][0];  /* condição de paragem */
  else
  {
    ColAux = UC;  /* procurar coluna com último elemento ? 0 */

    while (ColAux >= 0 && pmatriz[UC][ColAux] == 0) ColAux--;

    if (ColAux >= 0)  /* se existir tal coluna */
    {
      if (ColAux != UC)  /* se não for a última coluna */
        for (NL = 0; NL < pn; NL++)  /* trocar as colunas */
        {
          Elemento = pmatriz[NL][UC];
          pmatriz[NL][UC] = pmatriz[NL][ColAux];
          pmatriz[NL][ColAux] = -Elemento;
        }

      /* dividir a última coluna pelo último elemento */
      for (NL = 0; NL < UC; NL++) pmatriz[NL][UC] /= pmatriz[UC][UC];

      /* subtrair todas as colunas menos a última pela última coluna */
      /* multiplicada pelo último elemento da coluna a processar */
      for (NC = 0; NC < UC; NC++)
        for (NL = 0; NL < UC; NL++)
          pmatriz[NL][NC] -= pmatriz[NL][UC] * pmatriz[UC][NC];

      /* invocação recursiva para a matriz de dimensão N-1 */
      return pmatriz[UC][UC] * CalcDeterminante (pmatriz, pn-1);
    }
    else return 0;
  }
}

