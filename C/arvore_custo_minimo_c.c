/*******************************************************************************

 Algoritmos de cria��o da �rvore abrangente de custo m�nimo de um grafo din�mico.


*******************************************************************************/

/* implementa��o simplificada que n�o detecta se o grafo � conexo */

int GraphPrim (PtGraph pgraph, unsigned int pvadj[], int pcost[])
{
  PtPQueue PQueue; PtBiNo Vert, PEdge; PtEdge Edge; VERTICE Elem;

  if (pgraph == NULL) return NO_GRAPH;
  if (pgraph->NumVert == 0) return GRAPH_EMPTY;

  PQueue = PQueueCreate ();  /* criar a fila com prioridade */

  for (Vert = pgraph->Head; Vert != NULL; Vert = Vert->PtSeg)
  {
    Vert->Visit = 0;  /* desmarcar o v�rtice */
    pvadj[Vert->Number-1] = 0;  /* inicializar o predecessor */
    pcost[Vert->Number-1] = INT_MAX;  /* inicializar o custo */

    /* construir o elemento e p�-lo na fila com prioridade */
    Elem.Vertice = Vert->Number; Elem.TCost = pcost[Vert->Number-1];
    PQueueInsert (PQueue, &Elem);
  }

  /* inicializar o primeiro v�rtice e actualiz�-lo na fila */
  Elem.Vertice = pgraph->Head->Number;
  Elem.TCost = pcost[Elem.Vertice-1] = 0;
  PQueueDecrease (PQueue, &Elem);

  while (!PQueueEmpty (PQueue))
  {
    /* retirar o elemento da fila e pesquisar o v�rtice no grafo */
    PQueueDeleteMin (PQueue, &Elem);
    Vert = OutPosition (pgraph->Head, Elem.Vertice);
    Vert->Visit = 1;  /* marcar o v�rtice como conhecido */

    for (PEdge = Vert->PtAdj; PEdge != NULL; PEdge = PEdge->PtSeg)
      if (!PEdge->PtAdj->Visit) /* n�o processar v�rtices conhecidos */
      {
        /* comparar esta aresta com a anteriormente considerada */
        Edge = (PtEdge) PEdge->PtElem;
        if (Edge->Cost < pcost[PEdge->Number-1])
        {
          /* actualizar o v�rtice adjacente e a aresta */  
          pvadj[PEdge->Number-1] = Vert->Number;
          pcost[PEdge->Number-1] = Edge->Cost;

          /* actualizar o elemento na fila com prioridade */
          Elem.Vertice = PEdge->Number; Elem.TCost = Edge->Cost;
          PQueueDecrease (PQueue, &Elem);
        }
      }
  }

  PQueueDestroy (&PQueue);  /* destruir a fila com prioridade */

  return OK;
}

/******************************************************************************/

void ACM_Prim (unsigned int pvadj[], int pcost[], unsigned int pnv)
{
  unsigned int I;

  printf ("�rvore abrangente de custo m�nimo\n");
  
  for (I = 0; I < pnv; I++)
    if (pcost[I] != 0 && pcost[I] != INT_MAX)
      printf ("Vertice %d\tVertice %d\t Aresta = %d\n", I+1, pvadj[I], pcost[I]);
}

/******************************************************************************/

/* implementa��o simplificada que n�o detecta se o grafo � conexo */

int GraphKruskal (PtGraph pgraph, int pedge[], unsigned int pverte[], unsigned int pverti[])
{
  PtPQueue PQueue; PtDisjointSet VSet; PtBiNo Vert, PEdge;
  PtEdge Edge; EDGE Elem; int RVertE, RVertI, NEdges = 0;

  if (pgraph == NULL) return NO_GRAPH;
  if (pgraph->NumVert == 0) return GRAPH_EMPTY;

  PQueue = PQueueCreate ();  /* criar a fila com prioridade */
  VSet = DisjointSetCreate (pgraph->NumVert);  /* criar o conjunto */

  for (Vert = pgraph->Head; Vert != NULL; Vert = Vert->PtSeg)
    for (PEdge = Vert->PtAdj; PEdge != NULL; PEdge = PEdge->PtSeg)
    {
      /* construir as arestas e p�-las na fila com prioridade */
      Edge = (PtEdge) PEdge->PtElem;
      Elem.Edge = Edge->Cost;
      Elem.VOut = Vert->Number; Elem.VIn = PEdge->PtAdj->Number;
      PQueueInsert (PQueue, &Elem);
    }

  while (!PQueueEmpty (PQueue) && NEdges < pgraph->NumVert-1)
  {
    PQueueDeleteMin (PQueue, &Elem);  /* obter a menor aresta */

    /* determinar em que conjunto se encontra o v�rtice emergente */
    DisjointSetFind (VSet, Elem.VOut, &RVertE);

    /* determinar em que conjunto se encontra o v�rtice incidente */
    DisjointSetFind (VSet, Elem.VIn, &RVertI);

    if (RVertE != RVertI)
    {
      /* aceitar a aresta e inseri-la na �rvore de custo m�nimo */
      pedge[NEdges] = Elem.Edge;  /* armazenar a aresta */
      pverte[NEdges] = Elem.VOut;  /* armazenar o v�rtice emergente */
      pverti[NEdges] = Elem.VIn;  /* armazenar o v�rtice incidente */
      NEdges++;  /* incrementar o n�mero de arestas */

      /* juntar os dois conjuntos dos v�rtices emergente e incidente */
      DisjointSetUnion (VSet, RVertE, RVertI);
    }
  }

  PQueueDestroy (&PQueue);  /* destruir a fila com prioridade */

  DisjointSetDestroy (&VSet);  /* destruir o conjunto disjunto */

  return OK;
}

/******************************************************************************/

void ACM_Kruskal (unsigned int pverte[], unsigned int pverti[], \
                  int pedge[], unsigned int pnv)
{
  unsigned int I;

  printf ("�rvore abrangente de custo m�nimo\n");

  for (I = 0; I < pnv-1; I++)
    if (pedge[I] != 0)
      printf ("Vertice %d\tVertice %d\t Aresta = %d\n", pverte[I], pverti[I], pedge[I]);
}

/******************************************************************************/
