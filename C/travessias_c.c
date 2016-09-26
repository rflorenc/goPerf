/*******************************************************************************

 Algoritmos recursivos e repetitivos de travessia de um digrafo din�mico.


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

  pvertice->Visit = 1;  /* marcar o v�rtice */
  pseqv[(*pnv)++] = pvertice->Number;  /* p�r o v�rtice na sequ�ncia */

  for (Edge = pvertice->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    if (!Edge->PtAdj->Visit)  /* invoca��o recursiva */
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

/* 1� vers�o do DepthFirstSearchStack */

void DepthFirstSearchStack (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtStack Stack; PtBiNo Vert = pvertice, Edge;

  Stack = StackCreate (sizeof (PtBiNo));  /* criar a pilha */

  Vert->Visit = 1;  /* marcar o v�rtice */
  StackPush (Stack, &Vert);  /* p�r o v�rtice na pilha */

  while (!StackEmpty (Stack))
  {
    StackPop (Stack, &Vert);  /* tirar o v�rtice da pilha */
    pseqv[(*pnv)++] = Vert->Number;  /* p�r o v�rtice na sequ�ncia */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
      if (!Edge->PtAdj->Visit)  /* v�rtice adjacente j� visitado? */
      {
        Edge->PtAdj->Visit = 1;  /* marcar o v�rtice */
        StackPush (Stack, &Edge->PtAdj);  /* p�r o v�rtice na pilha */
      }
  }

  StackDestroy (&Stack);  /* destruir a pilha */
}

/******************************************************************************/

/* 2� vers�o do DepthFirstSearchStack */

void DepthFirstSearchStack (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtStack Stack; PtBiNo Vert = pvertice, Edge;

  Stack = StackCreate (sizeof (PtBiNo));  /* criar a pilha */

  Vert->Visit = 1;  /* marcar o v�rtice */
  pseqv[(*pnv)++] = Vert->Number;  /* p�r o v�rtice na sequ�ncia */
  StackPush (Stack, &Vert);  /* p�r o v�rtice na pilha */

  while (!StackEmpty (Stack))
  {
    StackTop (Stack, &Vert);  /* copiar o v�rtice do topo da pilha */

    /* procurar o seu primeiro v�rtice adjacente ainda por visitar */
    for (Edge = Vert->PtAdj; Edge != NULL && Edge->PtAdj->Visit; Edge = Edge->PtSeg) ;

    if (Edge == NULL)  /* n�o existe v�rtice adjacente para visitar? */
      StackPop (Stack, &Vert);  /* ent�o, tirar o v�rtice da pilha */
    else  /* sen�o, processar a pr�xima adjac�ncia */
    {
      Edge->PtAdj->Visit = 1;  /* marcar o v�rtice */
      pseqv[(*pnv)++] = Edge->PtAdj->Number;  /* p�-lo na sequ�ncia */
      StackPush (Stack, &Edge->PtAdj);  /* p�r o v�rtice na pilha */
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

  Vert->Visit = 1;  /* marcar o v�rtice */
  QueueEnqueue (Queue, &Vert);  /* p�r o v�rtice na fila */

  while (!QueueEmpty (Queue))
  {
    QueueDequeue (Queue, & Vert);  /* tirar o v�rtice da fila */
    pseqv[(*pnv)++] = Vert->Number;  /* p�r o v�rtice na sequ�ncia */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
      if (!Edge->PtAdj->Visit)  /* v�rtice adjacente visitado? */
      {
        Edge->PtAdj->Visit = 1;  /* marcar o v�rtice */
        QueueEnqueue (Queue, &Edge->PtAdj);  /* p�-lo na fila */
      }
  }

  QueueDestroy (&Queue);  /* destruir a fila */
}

/******************************************************************************/

