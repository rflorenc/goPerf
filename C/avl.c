
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Árvore de  Adelson-Velskii Landis
 de inteiros (avl.h). A implementação tem capacidade de múltipla instanciação, sendo
 providenciado um construtor para criar uma árvore vazia. É da responsabilidade
 da aplicação, invocar o destrutor, para libertar a memória atribuída ao objecto.
 O módulo providencia um controlo centralizado de erro, disponibilizando uma função
 para obter o último erro ocorrido e uma função para obter uma mensagem de erro
 elucidativa.

 A forma mais simples de criar uma árvore vazia consiste em representar a árvore
 através de um ponteiro para a sua raiz. Assim sendo, não existe uma estrutura
 que representa a árvore, pelo que o construtor limita-se a devolver um ponteiro
 nulo. Nesta implementação simplificada não se consegue distinguir uma árvore
 vazia de uma árvore inexistente.


*******************************************************************************/

#ifndef _AVL
#define _AVL

/****************** Definição do Tipo Ponteiro para uma AVL *******************/

typedef struct noavl *PtAVL;

/************************ Definição de Códigos de Erro ************************/

#define  OK         0  /* operação realizada com sucesso */
#define  NO_AVL     1  /* a AVL não existe */
#define  NO_MEM     2  /* memória esgotada */
#define  NULL_PTR   3  /* ponteiro nulo */
#define  AVL_EMPTY  4  /* AVL vazia */
#define  REP_ELEM   5  /* já existe o elemento */
#define  NO_ELEM    6  /* o elemento não existe */
#define  NO_FILE    7  /* o ficheiro não existe */

/*************************** Protótipos das Funções ***************************/

void InicializarErroAVL (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroAVL (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroAVL (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtAVL CriarAVL (void);
/*******************************************************************************
 Cria uma árvore vazia.
*******************************************************************************/

void ApagarAVL (PtAVL *pavl);
/*******************************************************************************
 Destrói a árvore referenciada por pavl e devolve a referência a NULL.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

PtAVL CopiarAVL (PtAVL pavl);
/*******************************************************************************
 Copia a árvore referenciada por pavl, caso ela exista. Devolve a referência da
 árvore cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void InserirNaAVL (PtAVL *pavl, int pelem);
/*******************************************************************************
 Insere pelem na árvore referenciada por pavl. Não insere elementos repetidos.
 Valores de erro: OK, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaAVL (PtAVL *pavl, int pelem);
/*******************************************************************************
 Retira pelem da árvore referenciada por pavl. Valores de erro: OK ou NO_ELEM.
*******************************************************************************/

int PesquisarAVL (PtAVL pavl, int pelem);
/*******************************************************************************
 Pesquisa pelem na árvore referenciada por pavl. Devolve 1 em caso afirmativo e
 0 em caso contrário. Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int CopiarElementoDaAVL (PtAVL pavl, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na árvore referenciada por pavl, caso ele
 exista. Valores de erro: OK, AVL_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumNosAVL (PtAVL pavl);
/*******************************************************************************
 Calcula o número de nós da árvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

int AlturaAVL (PtAVL pavl);
/*******************************************************************************
 Calcula a altura da árvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

int NumFolhasAVL (PtAVL pavl);
/*******************************************************************************
 Calcula o número de folhas da árvore referenciada por pavl. Valores de erro: OK.
*******************************************************************************/

void ArmazenarAVLFicheiro (PtAVL pavl, char *pnomef);
/*******************************************************************************
 Armazena a árvore referenciada por pavl, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha o número de nós da árvore, seguidos dos elementos,
 um por linha. Valores de erro: OK, AVL_EMPTY ou NO_FILE.
*******************************************************************************/

PtAVL CriarAVLFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma árvore a partir de informação lida do ficheiro pnomef. Devolve a
 referência da árvore criada ou NULL, caso não consiga criar a árvore por
 inexistência de memória ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaAVL (PtAVL pavl);
/*******************************************************************************
 Determina o maior dos elementos da árvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int MenorElementoDaAVL (PtAVL pavl);
/*******************************************************************************
 Determina o menor dos elementos da árvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

int SomarAVL (PtAVL pavl);
/*******************************************************************************
 Calcula a soma dos elementos da árvore referenciada por pavl.
 Valores de erro: OK ou AVL_EMPTY.
*******************************************************************************/

#endif
