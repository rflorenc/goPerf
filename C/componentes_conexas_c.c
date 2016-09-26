/*******************************************************************************

 Algoritmo de detec��o de componentes fortemente conexas de um digrafo din�mico.


*******************************************************************************/

int DigraphComponents (PtDigraph pdigraph, unsigned int plistv[], unsigned int *pnv)
{
  PtStack Stack; PtDigraph DigT; PtBiNo Vert; unsigned int I = 0, NumV;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  Stack = StackCreate (sizeof (unsigned int));  /* criar a pilha */

  /* desmarcar os v�rtices do digrafo */
  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  /* colocar os v�rtices em p�s-ordem na pilha */
  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
    if (!Vert->Visit) PosOrderStack (Vert, Stack);

  DigT = DigraphTranspose (pdigraph);  /* criar o digrafo transposto */

  /* desmarcar os v�rtices do digrafo transposto */
  for (Vert = DigT->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  while (!StackEmpty (Stack))  /* processar a pilha */
  {
    /* retirar o v�rtice da pilha pesquis�-lo no digrafo transposto */
    StackPop (Stack, &NumV);  
    Vert = OutPosition (DigT->Head, NumV);

    if (!Vert->Visit)  /* o v�rtice j� foi visitado? */
    {
      /* pesquisa em profundidade recursiva para criar componente */
      DepthFirstSearchRec (Vert, plistv, &I);
      plistv[I++] = 0;  /* separar as componentes com o valor 0 */
    }
  }

  StackDestroy (&Stack);  /* destruir a pilha */
  
  *pnv = I;  /* indicar a dimens�o da sequ�ncia constru�da */

  return OK;
}

void PosOrderStack (PtBiNo pvertice, PtStack pstack)
{
  PtBiNo Edge;

  pvertice->Visit = 1;  /* marcar o v�rtice */

  /* invocar recursivamente para os v�rtices adjacentes */
  for (Edge = pvertice->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    if (!Edge->PtAdj->Visit) PosOrderStack (Edge->PtAdj, pstack);

  /* colocar os v�rtices em p�s-ordem na pilha */
  StackPush (pstack, &pvertice->Number);
}

/******************************************************************************/

