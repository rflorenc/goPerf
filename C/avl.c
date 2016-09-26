
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados �rvore de  Adelson-Velskii Landis
 de inteiros (avl.h). A implementa��o tem capacidade de m�ltipla instancia��o, sendo
 providenciado um construtor para criar uma �rvore vazia. � da responsabilidade
 da aplica��o, invocar o destrutor, para libertar a mem�ria atribu�da ao objecto.
 O m�dulo providencia um controlo centralizado de erro, disponibilizando uma fun��o
 para obter o �ltimo erro ocorrido e uma fun��o para obter uma mensagem de erro
 elucidativa.

 A forma mais simples de criar uma �rvore vazia consiste em representar a �rvore
 atrav�s de um ponteiro para a sua raiz. Assim sendo, n�o existe uma estrutura
 que representa a �rvore, pelo que o construtor limita-se a devolver um ponteiro
 nulo. Nesta implementa��o simplificada n�o se consegue distinguir uma �rvore
 vazia de uma �rvore inexistente.


*******************************************************************************/

#ifndef _AVL
#define _AVL

/****************** Defini��o do Tipo Ponteiro para uma AVL *******************/

typedef struct noavl *PtAVL;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK         0  /* opera��o realizada com sucesso */
#define  NO_AVL     1  /* a AVL n�o existe */
#define  NO_MEM     2  /* mem�ria esgotada */
#define  NULL_PTR   3  /* ponteiro nulo */
#define  AVL_EMPTY  4  /* AVL vazia */
#define  REP_ELEM   5  /* j� existe o elemento */
#define  NO_ELEM    6  /* o elemento n�o existe */
#define  NO_FILE    7  /* o ficheiro n�o existe */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroAVL (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroAVL (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroAVL (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtAVL CriarAVL (void);
/*******************************************************************************
 Cria uma �rvore vazia.
*******************************************************************************/

void ApagarAVL (PtAVL *pavl);
/*******************************************************************************
 Destr�i a �rvore referenciada por pavl e devolve a refer�ncia a NULL.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

PtAVL CopiarAVL (PtAVL pavl);
/*******************************************************************************
 Copia a �rvore referenciada por pavl, caso ela exista. Devolve a refer�ncia da
 �rvore c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void InserirNaAVL (PtAVL *pavl, int pelem);
/*******************************************************************************
 Insere pelem na �rvore referenciada por pavl. N�o insere elementos repetidos.
 Valores de erro: OK, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaAVL (PtAVL *pavl, int pelem);
/*******************************************************************************
 Retira pelem da �rvore referenciada por pavl. Valores de erro: OK ou NO_ELEM.
*******************************************************************************/

int PesquisarAVL (PtAVL pavl, int pelem);
/*******************************************************************************
 Pesquisa pelem na �rvore referenciada por pavl. Devolve 1 em caso afirmativo e
 0 em caso contr�rio. Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int CopiarElementoDaAVL (PtAVL pavl, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na �rvore referenciada por pavl, caso ele
 exista. Valores de erro: OK, AVL_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumNosAVL (PtAVL pavl);
/*******************************************************************************
 Calcula o n�mero de n�s da �rvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

int AlturaAVL (PtAVL pavl);
/*******************************************************************************
 Calcula a altura da �rvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

int NumFolhasAVL (PtAVL pavl);
/*******************************************************************************
 Calcula o n�mero de folhas da �rvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

void ArmazenarAVLFicheiro (PtAVL pavl, char *pnomef);
/*******************************************************************************
 Armazena a �rvore referenciada por pavl, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha o n�mero de n�s da �rvore, seguidos dos elementos,
 um por linha. Valores de erro: OK, AVL_EMPTY ou NO_FILE.
*******************************************************************************/

PtAVL CriarAVLFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma �rvore a partir de informa��o lida do ficheiro pnomef. Devolve a
 refer�ncia da �rvore criada ou NULL, caso n�o consiga criar a �rvore por
 inexist�ncia de mem�ria ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaAVL (PtAVL pavl);
/*******************************************************************************
 Determina o maior dos elementos da �rvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int MenorElementoDaAVL (PtAVL pavl);
/*******************************************************************************
 Determina o menor dos elementos da �rvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int SomarAVL (PtAVL pavl);
/*******************************************************************************
 Calcula a soma dos elementos da �rvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

#endif
