/*******************************************************************************

 Algoritmo de Warshall para executar o fecho transitivo de um digrafo din�mico.


*******************************************************************************/

int DigraphWarshall (PtDigraph pdigraph, unsigned int **pmat)
{
  unsigned int I, J, K;

  /* verifica��o */
  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  /* inicializa��o */
  for (I = 0; I < pdigraph->NumVert; I++)
    for (J = 0; J < pdigraph->NumVert; J++)
      pmat[I][J] = pdigraph->MatAdj[I][J];

  /* processamento */
  for (K = 0; K < pdigraph->NumVert; K++)
    for (I = 0; I < pdigraph->NumVert; I++)
      for (J = 0; J < pdigraph->NumVert; J++)
        if (I != J && !pmat[I][J])
          pmat[I][J] = pmat[I][K] && pmat[K][J];

  return OK;
}

/******************************************************************************/
