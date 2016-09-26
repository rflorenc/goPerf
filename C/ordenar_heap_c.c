/*******************************************************************************

 Algoritmo Heap Sort para fazer a ordenação crescente de números inteiros.


*******************************************************************************/

void HeapSort (int pseq[], unsigned int pnelem)
{
  int Ind;

  /* criar o amontoado */
  for (Ind = pnelem/2-1; Ind >= 0; Ind--) FixHeap (pseq, pnelem, Ind);

  for (Ind = pnelem-1; Ind > 0; Ind--)
  {
    Swap (&pseq[Ind], &pseq[0]);  /* extrair o maior elemento */
    FixHeap (pseq, Ind, 0);  /* reconstruir o amontoado */
  }
}

/******************************************************************************/

void FixHeap (int pseq[], unsigned int pnelem, unsigned int ppos)
{
  unsigned int Filho; int Temp;

  if (pnelem <= 1) return;  /* amontoado vazio ou só com um elemento */

  Temp = pseq[ppos];  /* copiar o elemento */

  for ( ; ppos*2+1 < pnelem; ppos = Filho)
  {
    /* subir os filhos maiores do que ele */
    Filho = 2*ppos+1;  /* primeiro filho */

    /* determinar o maior dos filhos */
    if (Filho < pnelem-1 && pseq[Filho] < pseq[Filho+1]) Filho++;

    /* deslocar o maior dos filhos */
    if (pseq[Filho] > Temp) pseq[ppos] = pseq[Filho];
    else break;
  }

  pseq[ppos] = Temp;  /* recolocar o elemento */
}

/******************************************************************************/
