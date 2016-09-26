/*******************************************************************************

 Algoritmos de ordenação topológica de um digrafo dinâmico.


*******************************************************************************/

/* este algoritmo corrompe o digrafo */

int DigraphTopOrderQueue (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtQueue Queue; PtBiNo Vert, Edge; PtVertice Vertice;
  unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  Queue = QueueCreate (sizeof (PtBiNo));  /* criar a fila */
  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
  {
    /* pôr os vértices fonte na fila */
    Vertice = (PtVertice) Vert->PtElem;
    if (Vertice->InDeg == 0) QueueEnqueue (Queue, &Vert);
  }

  while (!QueueEmpty (Queue))
  {
    QueueDequeue (Queue, & Vert);  /* tirar o vértice da fila */
    pseqv[I++] = Vert->Number;  /* pôr o vértice na sequência */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    {
      /* simular a remoção do vértice */
      Vertice = (PtVertice) Edge->PtAdj->PtElem;
      if (--Vertice->InDeg == 0) QueueEnqueue (Queue, &Edge->PtAdj);
    }
  }

  QueueDestroy (&Queue);  /* destruir a fila */

  if (I == pdigraph->NumVert) return OK;  
  else return NO_DAG;  /* verificar se é um diagrafo acíclico */
}

/******************************************************************************/

int DigraphTopOrderRec (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtBiNo Vert; PtVertice Vertice; unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  I = pdigraph->NumVert;
  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
  {
    /* invocar apenas para os vértices fonte */
    Vertice = (PtVertice) Vert->PtElem;
    if (Vertice->InDeg == 0) TopOrderRec (Vert, pseqv, &I);
  }

  if (I == 0) return OK;
  else return NO_DAG;  /* verificar se é um diagrafo acíclico */
}

void TopOrderRec (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtBiNo Edge;

  pvertice->Visit = 1;  /* marcar o vértice */

  /* invocação recursiva para os vértices adjacentes deste vértice */
  for (Edge = pvertice->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    if (!Edge->PtAdj->Visit) TopOrderRec (Edge->PtAdj, pseqv, pnv);

  pseqv[--(*pnv)] = pvertice->Number;  /* pôr o vértice na sequência */
}

/******************************************************************************/

int DigraphTopOrderStack (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtStack Stack; PtBiNo Vert, Edge; PtVertice Vertice;
  unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  Stack = StackCreate (sizeof (PtBiNo));  /* criar a pilha */

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
  {
    /* pôr os vértices fonte na pilha */
    Vertice = (PtVertice) Vert->PtElem;

    if (Vertice->InDeg == 0)
    {
      Vert->Visit = 1;  /* marcar o vértice que é colocado na piha */
      StackPush (Stack, &Vert);  /* pôr o vértice na pilha */
    }
    else Vert->Visit = 0;  /* desmarcar os outros vértices */
  }

  I = pdigraph->NumVert;
  while (!StackEmpty (Stack))
  {
    StackTop (Stack, &Vert);  /* copiar o vértice do topo da pilha */
 
    /* procurar o seu primeiro vértice adjacente ainda por visitar */
    for (Edge = Vert->PtAdj; Edge != NULL && Edge->PtAdj->Visit; Edge = Edge->PtSeg) ;

    if (Edge == NULL)  /* não existe vértice adjacente para visitar? */
    {
      StackPop (Stack, &Vert);  /* então, tirar o vértice da pilha */
      pseqv[--I] = Vert->Number;  /* pô-lo na sequência */
    }
    else  /* senão, processar a próxima adjacência */
    {
      Edge->PtAdj->Visit = 1;  /* marcar o vértice */
      StackPush (Stack, &Edge->PtAdj);  /* pôr o vértice na pilha */
    }
  }

  StackDestroy (&Stack);  /* destruir a pilha */

  if (I == 0) return OK;
  else return NO_DAG;  /* verificar se é um diagrafo acíclico */
}

/******************************************************************************/


