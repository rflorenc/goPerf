/*******************************************************************************

 Algoritmo de ordenação sequencial (SequentialSort) com contagem de comparações
 (CmpCount) e com contagem de trocas (SwapCount). 
 

*******************************************************************************/

void SequentialSort (TELEM pseq[], unsigned int pnelem, TPFC pfcomp, \
                     int ptord, unsigned int *pnc, unsigned int *pna)
{
  unsigned int Indi, Indj;

  /* inicialização das variáveis contadoras */
  CmpCount ((TELEM *) NULL, (TELEM *) NULL, (TPFC) NULL, INIC);
  SwapCount ((TELEM *) NULL, (TELEM *) NULL, INIC);

  for (Indi = 0; Indi < pnelem-1; Indi++)
    for (Indj = Indi+1; Indj < pnelem; Indj++)
      if (CmpCount (&pseq[Indi], &pseq[Indj], pfcomp, NORM) == ptord)
        SwapCount (&pseq[Indi], &pseq[Indj], NORM);

  /* relatório das variáveis contadoras */
  *pnc = CmpCount ((TELEM *) NULL, (TELEM *) NULL, (TPFC) NULL, REP);
  *pna = SwapCount ((TELEM *) NULL, (TELEM *) NULL, REP);
}

unsigned int CmpCount (TELEM *pelemx, TELEM *pelemy, TPFC pfcomp, unsigned int pmodo)
{
  static unsigned int Cont;

  if (pmodo == INIC) Cont = 0;
  else if (pmodo == NORM)
       {
         Cont++;  /* contar a comparação */
         return pfcomp (pelemx, pelemy);  /* efectuar a comparação */
       }

  return Cont;  /* devolver a contagem */
}

unsigned int SwapCount (TELEM *pelemx, TELEM *pelemy, unsigned int pmodo)
{
  TELEM Temp; static unsigned int Cont;

  if (pmodo == INIC) Cont = 0; 
  else if (pmodo == NORM)
       {
         Temp = *pelemx; *pelemx = *pelemy; *pelemy = Temp;  /* efectuar a troca */
         Cont += 3;  /* contar as 3 instruções de atribuição */
       }

  return Cont;    /* devolver a contagem */
}
