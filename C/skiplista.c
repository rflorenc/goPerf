
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Lista Skip de inteiros positivos
 (skiplista.h). A implementação tem capacidade de múltipla instanciação, sendo
 providenciado um construtor para criar uma lista vazia. É da responsabilidade
 da aplicação, invocar o destrutor, para libertar a memória atribuída ao objecto.
 O módulo providencia um controlo centralizado de erro, disponibilizando uma
 função para obter o último erro ocorrido e uma função para obter uma mensagem
 de erro elucidativa.


*******************************************************************************/

#ifndef _SKIPLISTA
#define _SKIPLISTA

/**************** Definição do Tipo Ponteiro para uma SKIPLISTA ***************/

typedef struct skiplista *PtSkip;

/************************ Definição de Códigos de Erro ************************/

#define  OK          0  /* operação realizada com sucesso */
#define  NO_SKIP     1  /* a lista skip não existe */
#define  NO_MEM      2  /* memória esgotada */
#define  NULL_PTR    3  /* ponteiro nulo */
#define  SKIP_EMPTY  4  /* lista skip vazia */
#define  REP_ELEM    5  /* já existe o elemento */
#define  NO_ELEM     6  /* o elemento não existe */
#define  NO_FILE     7  /* o ficheiro não existe */

/*************************** Protótipos das Funções ***************************/

void InicializarErroSkiplista (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroSkiplista (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroSkiplista (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtSkip CriarSkiplista (void);
/*******************************************************************************
 Cria uma lista skip vazia. Devolve a referência da lista criada ou NULL,
 caso não consiga criar a lista por falta de memória. 
*******************************************************************************/

void ApagarSkiplista (PtSkip *pskip);
/*******************************************************************************
 Destrói a lista skip referenciada por pskip e devolve a referência a NULL.
 Valores de erro: OK ou NO_SKIP.
*******************************************************************************/

PtSkip CopiarSkiplista (PtSkip pskip);
/*******************************************************************************
 Copia a lista skip referenciada por pskip, caso ela exista. Devolve a
 referência da lista cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_SKIP ou NO_MEM.
*******************************************************************************/

void InserirNaSkiplista (PtSkip pskip, int pelem);
/*******************************************************************************
 Insere pelem na lista skip referenciada por pskip. Não insere elementos
 repetidos e mantém a lista ordenada por ordem crescente.
 Valores de erro: OK, NO_SKIP, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaSkiplista (PtSkip pskip, int pelem);
/*******************************************************************************
 Retira pelem da lista skip referenciada por pskip.
 Valores de erro: OK, NO_SKIP ou NO_ELEM.
*******************************************************************************/

int PesquisarSkiplista (PtSkip pskip, int pelem);
/*******************************************************************************
 Pesquisa pelem na lista skip referenciada por pskip. Devolve 1 em caso
 afirmativo e 0 em caso contrário.
 Valores de erro: OK, NO_SKIP ou SKIP_EMPTY.
*******************************************************************************/

int CopiarElementoDaSkiplista (PtSkip pskip, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na lista skip referenciada por pskip,
 caso ele exista. Valores de erro: OK, NO_SKIP, SKIP_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumElementosSkiplista (PtSkip pskip);
/*******************************************************************************
 Determina o número de elementos da lista skip referenciada por pskip.
 Valores de erro: OK ou NO_SKIP.
*******************************************************************************/

void ArmazenarSkiplistaFicheiro (PtSkip pskip, char *pnomef);
/*******************************************************************************
 Armazena a lista skip referenciada por pskip, caso ela exista, no ficheiro
 pnomef. O ficheiro tem na primeira linha o número de elementos da lista, 
 seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_SKIP, SKIP_EMPTY ou NO_FILE.
*******************************************************************************/

PtSkip CriarSkiplistaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma lista skip a partir de informação lida do ficheiro pnomef. Devolve
 a referência da lista criada ou NULL, caso não consiga criar a lista por
 inexistência de memória ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaSkiplista (PtSkip pskip);
/*******************************************************************************
 Determina o maior dos elementos da lista skip referenciada por pskip.
 Valores de erro: OK, NO_SKIP ou SKIP_EMPTY.
*******************************************************************************/

int MenorElementoDaSkiplista (PtSkip pskip);
/*******************************************************************************
 Determina o menor dos elementos da lista skip referenciada por pskip.
 Valores de erro: OK, NO_SKIP ou SKIP_EMPTY.
*******************************************************************************/

int SomarSkiplista (PtSkip pskip);
/*******************************************************************************
 Calcula a soma dos elementos da lista skip referenciada por pskip.
 Valores de erro: OK, NO_SKIP ou SKIP_EMPTY.
*******************************************************************************/

#endif
