/*******************************************************************************

 Algoritmos recursivos e repetitivos de travessia de um digrafo dinâmico.


*******************************************************************************/

int DigraphDepthRec (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtBiNo Vert; unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
    if (!Vert->Visit) DepthFirstSearchRec (Vert, pseqv, &I);

  return OK;
}

void DepthFirstSearchRec (PtBiNo pvertice, unsigned int pseqv[], \
                          unsigned int *pnv)
{
  PtBiNo Edge;

  pvertice->Visit = 1;  /* marcar o vértice */
  pseqv[(*pnv)++] = pvertice->Number;  /* pôr o vértice na sequência */

  for (Edge = pvertice->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    if (!Edge->PtAdj->Visit)  /* invocação recursiva */
      DepthFirstSearchRec (Edge->PtAdj, pseqv, pnv);
}

/******************************************************************************/

int DigraphDepth (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtBiNo Vert; unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
    if (!Vert->Visit) DepthFirstSearchStack (Vert, pseqv, &I);

  return OK;
}

/******************************************************************************/

/* 1ª versão do DepthFirstSearchStack */

void DepthFirstSearchStack (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtStack Stack; PtBiNo Vert = pvertice, Edge;

  Stack = StackCreate (sizeof (PtBiNo));  /* criar a pilha */

  Vert->Visit = 1;  /* marcar o vértice */
  StackPush (Stack, &Vert);  /* pôr o vértice na pilha */

  while (!StackEmpty (Stack))
  {
    StackPop (Stack, &Vert);  /* tirar o vértice da pilha */
    pseqv[(*pnv)++] = Vert->Number;  /* pôr o vértice na sequência */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
      if (!Edge->PtAdj->Visit)  /* vértice adjacente já visitado? */
      {
        Edge->PtAdj->Visit = 1;  /* marcar o vértice */
        StackPush (Stack, &Edge->PtAdj);  /* pôr o vértice na pilha */
      }
  }

  StackDestroy (&Stack);  /* destruir a pilha */
}

/******************************************************************************/

/* 2ª versão do DepthFirstSearchStack */

void DepthFirstSearchStack (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtStack Stack; PtBiNo Vert = pvertice, Edge;

  Stack = StackCreate (sizeof (PtBiNo));  /* criar a pilha */

  Vert->Visit = 1;  /* marcar o vértice */
  pseqv[(*pnv)++] = Vert->Number;  /* pôr o vértice na sequência */
  StackPush (Stack, &Vert);  /* pôr o vértice na pilha */

  while (!StackEmpty (Stack))
  {
    StackTop (Stack, &Vert);  /* copiar o vértice do topo da pilha */

    /* procurar o seu primeiro vértice adjacente ainda por visitar */
    for (Edge = Vert->PtAdj; Edge != NULL && Edge->PtAdj->Visit; Edge = Edge->PtSeg) ;

    if (Edge == NULL)  /* não existe vértice adjacente para visitar? */
      StackPop (Stack, &Vert);  /* então, tirar o vértice da pilha */
    else  /* senão, processar a próxima adjacência */
    {
      Edge->PtAdj->Visit = 1;  /* marcar o vértice */
      pseqv[(*pnv)++] = Edge->PtAdj->Number;  /* pô-lo na sequência */
      StackPush (Stack, &Edge->PtAdj);  /* pôr o vértice na pilha */
    }
  }

  StackDestroy (&Stack);  /* destruir a pilha */
}

/******************************************************************************/

int DigraphBreadth (PtDigraph pdigraph, unsigned int pseqv[])
{
  PtBiNo Vert; unsigned int I = 0;

  if (pdigraph == NULL) return NO_DIGRAPH;
  if (pdigraph->NumVert == 0) return DIGRAPH_EMPTY;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg) Vert->Visit = 0;

  for (Vert = pdigraph->Head; Vert != NULL; Vert = Vert->PtSeg)
    if (!Vert->Visit) BreadthFirstSearchQueue (Vert, pseqv, &I);

  return OK;
}

void BreadthFirstSearchQueue (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtQueue Queue; PtBiNo Vert = pvertice, Edge;

  Queue = QueueCreate (sizeof (PtBiNo));  /* criar a fila */

  Vert->Visit = 1;  /* marcar o vértice */
  QueueEnqueue (Queue, &Vert);  /* pôr o vértice na fila */

  while (!QueueEmpty (Queue))
  {
    QueueDequeue (Queue, & Vert);  /* tirar o vértice da fila */
    pseqv[(*pnv)++] = Vert->Number;  /* pôr o vértice na sequência */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
      if (!Edge->PtAdj->Visit)  /* vértice adjacente visitado? */
      {
        Edge->PtAdj->Visit = 1;  /* marcar o vértice */
        QueueEnqueue (Queue, &Edge->PtAdj);  /* pô-lo na fila */
      }
  }

  QueueDestroy (&Queue);  /* destruir a fila */
}

/******************************************************************************/

