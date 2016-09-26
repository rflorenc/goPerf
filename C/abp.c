
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Árvore Binaria de Pesquisa de
 inteiros (abp.h). A implementação tem capacidade de múltipla instanciação, sendo
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

#ifndef _ABP
#define _ABP

/****************** Definição do Tipo Ponteiro para uma ABP *******************/

typedef struct noabp *PtABP;

/************************ Definição de Códigos de Erro ************************/

#define  OK         0  /* operação realizada com sucesso */
#define  NO_ABP     1  /* a ABP não existe */
#define  NO_MEM     2  /* memória esgotada */
#define  NULL_PTR   3  /* ponteiro nulo */
#define  ABP_EMPTY  4  /* ABP vazia */
#define  REP_ELEM   5  /* já existe o elemento */
#define  NO_ELEM    6  /* o elemento não existe */
#define  NO_FILE    7  /* o ficheiro não existe */

/*************************** Protótipos das Funções ***************************/

void InicializarErroABP (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroABP (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroABP (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtABP CriarABP (void);
/*******************************************************************************
 Cria uma árvore vazia.
*******************************************************************************/

void ApagarABP (PtABP *pabp);
/*******************************************************************************
 Destrói a árvore referenciada por pabp e devolve a referência a NULL.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

PtABP CopiarABP (PtABP pabp);
/*******************************************************************************
 Copia a árvore referenciada por pabp, caso ela exista. Devolve a referência da
 árvore cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void InserirNaABP (PtABP *pabp, int pelem);
/*******************************************************************************
 Insere pelem na árvore referenciada por pabp. Não insere elementos repetidos.
 Valores de erro: OK, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaABP (PtABP *pabp, int pelem);
/*******************************************************************************
 Retira pelem da árvore referenciada por pabp. Valores de erro: OK ou NO_ELEM.
*******************************************************************************/

int PesquisarABP (PtABP pabp, int pelem);
/*******************************************************************************
 Pesquisa pelem na árvore referenciada por pabp. Devolve 1 em caso afirmativo e
 0 em caso contrário. Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int CopiarElementoDaABP (PtABP pabp, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na árvore referenciada por pabp, caso ele
 exista. Valores de erro: OK, ABP_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumNosABP (PtABP pabp);
/*******************************************************************************
 Calcula o número de nós da árvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

int AlturaABP (PtABP pabp);
/*******************************************************************************
 Calcula a altura da árvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

int NumFolhasABP (PtABP pabp);
/*******************************************************************************
 Calcula o número de folhas da árvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

void ArmazenarABPFicheiro (PtABP pabp, char *pnomef);
/*******************************************************************************
 Armazena a árvore referenciada por pabp, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha o número de nós da árvore, seguidos dos elementos,
 um por linha. Valores de erro: OK, ABP_EMPTY ou NO_FILE.
*******************************************************************************/

PtABP CriarABPFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma árvore a partir de informação lida do ficheiro pnomef. Devolve a
 referência da árvore criada ou NULL, caso não consiga criar a árvore por
 inexistência de memória ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaABP (PtABP pabp);
/*******************************************************************************
 Determina o maior dos elementos da árvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int MenorElementoDaABP (PtABP pabp);
/*******************************************************************************
 Determina o menor dos elementos da árvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int SomarABP (PtABP pabp);
/*******************************************************************************
 Calcula a soma dos elementos da árvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

#endif
