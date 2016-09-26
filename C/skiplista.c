
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Lista Skip de inteiros positivos
 (skiplista.h). A implementa��o tem capacidade de m�ltipla instancia��o, sendo
 providenciado um construtor para criar uma lista vazia. � da responsabilidade
 da aplica��o, invocar o destrutor, para libertar a mem�ria atribu�da ao objecto.
 O m�dulo providencia um controlo centralizado de erro, disponibilizando uma
 fun��o para obter o �ltimo erro ocorrido e uma fun��o para obter uma mensagem
 de erro elucidativa.


*******************************************************************************/

#ifndef _SKIPLISTA
#define _SKIPLISTA

/**************** Defini��o do Tipo Ponteiro para uma SKIPLISTA ***************/

typedef struct skiplista *PtSkip;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK          0  /* opera��o realizada com sucesso */
#define  NO_SKIP     1  /* a lista skip n�o existe */
#define  NO_MEM      2  /* mem�ria esgotada */
#define  NULL_PTR    3  /* ponteiro nulo */
#define  SKIP_EMPTY  4  /* lista skip vazia */
#define  REP_ELEM    5  /* j� existe o elemento */
#define  NO_ELEM     6  /* o elemento n�o existe */
#define  NO_FILE     7  /* o ficheiro n�o existe */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroSkiplista (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroSkiplista (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroSkiplista (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtSkip CriarSkiplista (void);
/*******************************************************************************
 Cria uma lista skip vazia. Devolve a refer�ncia da lista criada ou NULL,
 caso n�o consiga criar a lista por falta de mem�ria. 
*******************************************************************************/

void ApagarSkiplista (PtSkip *pskip);
/*******************************************************************************
 Destr�i a lista skip referenciada por pskip e devolve a refer�ncia a NULL.
 Valores de erro: OK ou NO_SKIP.
*******************************************************************************/

PtSkip CopiarSkiplista (PtSkip pskip);
/*******************************************************************************
 Copia a lista skip referenciada por pskip, caso ela exista. Devolve a
 refer�ncia da lista c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK, NO_SKIP ou NO_MEM.
*******************************************************************************/

void InserirNaSkiplista (PtSkip pskip, int pelem);
/*******************************************************************************
 Insere pelem na lista skip referenciada por pskip. N�o insere elementos
 repetidos e mant�m a lista ordenada por ordem crescente.
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
 afirmativo e 0 em caso contr�rio.
 Valores de erro: OK, NO_SKIP ou SKIP_EMPTY.
*******************************************************************************/

int CopiarElementoDaSkiplista (PtSkip pskip, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na lista skip referenciada por pskip,
 caso ele exista. Valores de erro: OK, NO_SKIP, SKIP_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumElementosSkiplista (PtSkip pskip);
/*******************************************************************************
 Determina o n�mero de elementos da lista skip referenciada por pskip.
 Valores de erro: OK ou NO_SKIP.
*******************************************************************************/

void ArmazenarSkiplistaFicheiro (PtSkip pskip, char *pnomef);
/*******************************************************************************
 Armazena a lista skip referenciada por pskip, caso ela exista, no ficheiro
 pnomef. O ficheiro tem na primeira linha o n�mero de elementos da lista, 
 seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_SKIP, SKIP_EMPTY ou NO_FILE.
*******************************************************************************/

PtSkip CriarSkiplistaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma lista skip a partir de informa��o lida do ficheiro pnomef. Devolve
 a refer�ncia da lista criada ou NULL, caso n�o consiga criar a lista por
 inexist�ncia de mem�ria ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
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
