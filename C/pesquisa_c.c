/*******************************************************************************

 Algoritmos de pesquisa sequencial, bin�ria, tern�ria e por interpola��o. 
 

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

/***** 1� vers�o *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo <= Maximo)
  {
    /* c�lculo da posi��o m�dia */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    if (pseq[Medio] == pval) return Medio;  /* pesquisa com sucesso */

    /* Actualiza��o dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else Maximo = Medio - 1;
  }

   return -1;	/* pesquisa sem sucesso */
}

/******************************************************************************/

/***** vers�o recursiva *****/
int BinarySearchRec (int pseq[], int pinic, int pfim, int pval)
{
  int Medio;

  /* condi��o de paragem no caso de pesquisa sem sucesso */
  if (pinic > pfim) return -1;

  /* c�lculo da posi��o m�dia */
  Medio = ((unsigned int) pinic + (unsigned int) pfim) >> 1;

  /* condi��o de paragem no caso de pesquisa com sucesso */
  if (pseq[Medio] == pval) return Medio;	

  if (pseq[Medio] > pval)
       return BinarySearchRec (pseq, pinic, Medio-1, pval);
       /* invoca��o recursiva para a primeira metade da sequ�ncia */
  else return BinarySearchRec (pseq, Medio+1, pfim, pval);
       /* invoca��o recursiva para a segunda metade da sequ�ncia */
}

/******************************************************************************/

/***** 2� vers�o *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo <= Maximo)
  {
    /* c�lculo da posi��o m�dia */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    /* Actualiza��o dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else if (pseq[Medio] > pval) Maximo = Medio - 1;
         else return Medio;	/* pesquisa com sucesso */
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 3� vers�o *****/
int BinarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, Medio;

  while (Minimo < Maximo)
  {
    /* c�lculo da posi��o m�dia */
    Medio = ((unsigned int) Minimo + (unsigned int) Maximo) >> 1;

    /* Actualiza��o dos limites do intervalo de pesquisa */
    if (pseq[Medio] < pval) Minimo = Medio + 1;
    else Maximo = Medio;
  }

  if (pseq[Minimo] == pval) return Minimo;  /* pesquisa com sucesso */
  else return -1;                           /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 1� vers�o *****/
int TernarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, NElem, UmT, DoisT;

  while (Minimo <= Maximo)
  {
    NElem = Maximo - Minimo + 1;  /* c�lculo dos piv�s */
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
    else  if (pseq[UmT] > pval) Maximo = UmT - 1;  /* 1� ter�o */
        else  if (pseq[DoisT] == pval) return DoisT;  /* pesquisa com sucesso */
          else  if (pseq[DoisT] > pval)
            {
              Minimo = UmT + 1;
              Maximo = DoisT - 1;                  /* 2� ter�o */
            }
            else Minimo = DoisT + 1;               /* 3� ter�o */
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/

/***** 2� vers�o *****/
int TernarySearch (int pseq[], unsigned int pinic, unsigned int pfim, int pval)
{
  int Minimo = pinic, Maximo = pfim, NElem, UmT, DoisT;

  while (Minimo < Maximo)
  {
    NElem = Maximo - Minimo + 1;  /* c�lculo dos piv�s */
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

    if (pseq[UmT] > pval) Maximo = UmT - 1;   /* 1� ter�o */
    else if (pseq[DoisT] > pval)
         {
           Minimo = UmT; Maximo = DoisT - 1;  /* 2� ter�o */
         }
         else Minimo = DoisT;                 /* 3� ter�o */
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
    Dif = pseq[Maximo] - pseq[Minimo];  /* c�lculo da diferen�a */

    if (Dif == 0) Medio = Minimo;  /* c�lculo da posi��o m�dia */
    else Medio = Minimo + (pval - pseq[Minimo]) * (int) (Maximo - Minimo) / Dif;

    if (pseq[Medio] == pval) return Medio;  /* pesquisa com sucesso */

    /* Actualiza��o dos limites do intervalo de pesquisa */
    if (pseq[Medio] > pval) Maximo = Medio - 1;
    else Minimo = Medio + 1;
  }

  return -1;  /* pesquisa sem sucesso */
}

/******************************************************************************/
