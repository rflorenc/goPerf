/*******************************************************************************

 Algoritmos de pesquisa sequencial, binária, ternária e por interpolação. 
 

*******************************************************************************/

int SequentialSearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  unsigned int IndActual;

  for (IndActual = pinic; IndActual <= pfim; IndActual++)
    if (pseq[IndActual] == pval) return IndActual;

  return -1;
}

/******************************************************************************/

int OrderedSequentialSearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  unsigned int IndActual;

  for (IndActual = pinic; IndActual <= pfim; IndActual++)
    if (pseq[IndActual] >= pval) break;

  if (IndActual != pfim && pseq[IndActual] == pval) return IndActual;
  else return -1;
}

/******************************************************************************/

/***** 1ª versão *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo <= Maximo)
  {
    /* cálculo da posição média */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    if (pseq[Medio] == pval) return Medio;  /* pesquisa com sucesso */

    /* Actualização dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else Maximo = Medio - 1;
  }

   return -1;	/* pesquisa sem sucesso */
}

/******************************************************************************/

/***** versão recursiva *****/
int BinarySearchRec (int pseq[], int pinic, int pfim, int pval)
{
  int Medio;

  /* condição de paragem no caso de pesquisa sem sucesso */
  if (pinic > pfim) return -1;

  /* cálculo da posição média */
  Medio = ((unsigned int) pinic + (unsigned int) pfim) >> 1;

  /* condição de paragem no caso de pesquisa com sucesso */
  if (pseq[Medio] == pval) return Medio;	

  if (pseq[Medio] > pval)
       return BinarySearchRec (pseq, pinic, Medio-1, pval);
       /* invocação recursiva para a primeira metade da sequência */
  else return BinarySearchRec (pseq, Medio+1, pfim, pval);
       /* invocação recursiva para a segunda metade da sequência */
}

/******************************************************************************/

/***** 2ª versão *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo <= Maximo)
  {
    /* cálculo da posição média */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    /* Actualização dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else if (pseq[Medio] > pval) Maximo = Medio - 1;
         else return Medio;	/* pesquisa com sucesso */
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 3ª versão *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo < Maximo)
  {
    /* cálculo da posição média */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    /* Actualização dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else Maximo = Medio;
  }

  if (pseq[Minimo] == pval) return Minimo;  /* pesquisa com sucesso */
  else return -1;                           /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 1ª versão *****/
int TernarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, NElem, UmT, DoisT;

  while (Minimo <= Maximo)
  {
    NElem = Maximo - Minimo + 1;  /* cálculo dos pivôs */
    if (NElem % 3 == 0) 
    {
      UmT = Minimo + (NElem / 3) - 1;
      DoisT = Minimo + (2 * NElem / 3) - 1;
    }
    else
    {
      UmT = Minimo + (NElem / 3);
      DoisT = Minimo + (2 * NElem / 3);
    }

    if (pseq[UmT] == pval) return UmT;  /* pesquisa com sucesso */
    else  if (pseq[UmT] > pval) Maximo = UmT - 1;  /* 1º terço */
        else  if (pseq[DoisT] == pval) return DoisT;  /* pesquisa com sucesso */
          else  if (pseq[DoisT] > pval)
            {
              Minimo = UmT + 1;
              Maximo = DoisT - 1;                  /* 2º terço */
            }
            else Minimo = DoisT + 1;               /* 3º terço */
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 2ª versão *****/
int TernarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, NElem, UmT, DoisT;

  while (Minimo < Maximo)
  {
    NElem = Maximo - Minimo + 1;  /* cálculo dos pivôs */
    if (NElem % 3 == 0) 
    {
      UmT = Minimo + (NElem / 3) - 1;
      DoisT = Minimo + (2 * NElem / 3) - 1;
    }
    else
    {
      UmT = Minimo + (NElem / 3);
      DoisT = Minimo + (2 * NElem / 3);
    }

    if (pseq[UmT] > pval) Maximo = UmT - 1;   /* 1º terço */
    else if (pseq[DoisT] > pval)
         {
           Minimo = UmT; Maximo = DoisT - 1;  /* 2º terço */
         }
         else Minimo = DoisT;                 /* 3º terço */
  }

  if (pseq[Minimo] == pval) return Minimo;    /* pesquisa com sucesso */
  else return -1;                             /* pesquisa sem sucesso */
}

/******************************************************************************/

int InterpolationSearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  unsigned int Minimo = pinic, Maximo = pfim, Medio; int Dif;

  if (pval < pseq[Minimo] || pval > pseq[Maximo]) return -1;

  while (Minimo <= Maximo)
  {
    Dif = pseq[Maximo] - pseq[Minimo];  /* cálculo da diferença */

    if (Dif == 0) Medio = Minimo;  /* cálculo da posição média */
    else Medio = Minimo + (pval - pseq[Minimo]) * (int) (Maximo - Minimo) / Dif;

    if (pseq[Medio] == pval) return Medio;  /* pesquisa com sucesso */

    /* Actualização dos limites do intervalo de pesquisa */
    if (pseq[Medio] > pval) Maximo = Medio - 1;
    else Minimo = Medio + 1;
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/
