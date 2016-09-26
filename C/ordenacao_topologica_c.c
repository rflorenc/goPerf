/*******************************************************************************

 Algoritmos de ordena��o topol�gica de um digrafo din�mico.


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
    /* p�r os v�rtices fonte na fila */
    Vertice = (PtVertice) Vert->PtElem;
    if (Vertice->InDeg == 0) QueueEnqueue (Queue, &Vert);
  }

  while (!QueueEmpty (Queue))
  {
    QueueDequeue (Queue, & Vert);  /* tirar o v�rtice da fila */
    pseqv[I++] = Vert->Number;  /* p�r o v�rtice na sequ�ncia */

    for (Edge = Vert->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    {
      /* simular a remo��o do v�rtice */
      Vertice = (PtVertice) Edge->PtAdj->PtElem;
      if (--Vertice->InDeg == 0) QueueEnqueue (Queue, &Edge->PtAdj);
    }
  }

  QueueDestroy (&Queue);  /* destruir a fila */

  if (I == pdigraph->NumVert) return OK;  
  else return NO_DAG;  /* verificar se � um diagrafo ac�clico */
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
    /* invocar apenas para os v�rtices fonte */
    Vertice = (PtVertice) Vert->PtElem;
    if (Vertice->InDeg == 0) TopOrderRec (Vert, pseqv, &I);
  }

  if (I == 0) return OK;
  else return NO_DAG;  /* verificar se � um diagrafo ac�clico */
}

void TopOrderRec (PtBiNo pvertice, unsigned int pseqv[], unsigned int *pnv)
{
  PtBiNo Edge;

  pvertice->Visit = 1;  /* marcar o v�rtice */

  /* invoca��o recursiva para os v�rtices adjacentes deste v�rtice */
  for (Edge = pvertice->PtAdj; Edge != NULL; Edge = Edge->PtSeg)
    if (!Edge->PtAdj->Visit) TopOrderRec (Edge->PtAdj, pseqv, pnv);

  pseqv[--(*pnv)] = pvertice->Number;  /* p�r o v�rtice na sequ�ncia */
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
    /* p�r os v�rtices fonte na pilha */
    Vertice = (PtVertice) Vert->PtElem;

    if (Vertice->InDeg == 0)
    {
      Vert->Visit = 1;  /* marcar o v�rtice que � colocado na piha */
      StackPush (Stack, &Vert);  /* p�r o v�rtice na pilha */
    }
    else Vert->Visit = 0;  /* desmarcar os outros v�rtices */
  }

  I = pdigraph->NumVert;
  while (!StackEmpty (Stack))
  {
    StackTop (Stack, &Vert);  /* copiar o v�rtice do topo da pilha */
 
    /* procurar o seu primeiro v�rtice adjacente ainda por visitar */
    for (Edge = Vert->PtAdj; Edge != NULL && Edge->PtAdj->Visit; Edge = Edge->PtSeg) ;

    if (Edge == NULL)  /* n�o existe v�rtice adjacente para visitar? */
    {
      StackPop (Stack, &Vert);  /* ent�o, tirar o v�rtice da pilha */
      pseqv[--I] = Vert->Number;  /* p�-lo na sequ�ncia */
    }
    else  /* sen�o, processar a pr�xima adjac�ncia */
    {
      Edge->PtAdj->Visit = 1;  /* marcar o v�rtice */
      StackPush (Stack, &Edge->PtAdj);  /* p�r o v�rtice na pilha */
    }
  }

  StackDestroy (&Stack);  /* destruir a pilha */

  if (I == 0) return OK;
  else return NO_DAG;  /* verificar se � um diagrafo ac�clico */
}

/******************************************************************************/


