
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados �rvore Binaria de Pesquisa de
 inteiros (abp.h). A implementa��o tem capacidade de m�ltipla instancia��o, sendo
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

#ifndef _ABP
#define _ABP

/****************** Defini��o do Tipo Ponteiro para uma ABP *******************/

typedef struct noabp *PtABP;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK         0  /* opera��o realizada com sucesso */
#define  NO_ABP     1  /* a ABP n�o existe */
#define  NO_MEM     2  /* mem�ria esgotada */
#define  NULL_PTR   3  /* ponteiro nulo */
#define  ABP_EMPTY  4  /* ABP vazia */
#define  REP_ELEM   5  /* j� existe o elemento */
#define  NO_ELEM    6  /* o elemento n�o existe */
#define  NO_FILE    7  /* o ficheiro n�o existe */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroABP (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroABP (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroABP (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtABP CriarABP (void);
/*******************************************************************************
 Cria uma �rvore vazia.
*******************************************************************************/

void ApagarABP (PtABP *pabp);
/*******************************************************************************
 Destr�i a �rvore referenciada por pabp e devolve a refer�ncia a NULL.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

PtABP CopiarABP (PtABP pabp);
/*******************************************************************************
 Copia a �rvore referenciada por pabp, caso ela exista. Devolve a refer�ncia da
 �rvore c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void InserirNaABP (PtABP *pabp, int pelem);
/*******************************************************************************
 Insere pelem na �rvore referenciada por pabp. N�o insere elementos repetidos.
 Valores de erro: OK, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaABP (PtABP *pabp, int pelem);
/*******************************************************************************
 Retira pelem da �rvore referenciada por pabp. Valores de erro: OK ou NO_ELEM.
*******************************************************************************/

int PesquisarABP (PtABP pabp, int pelem);
/*******************************************************************************
 Pesquisa pelem na �rvore referenciada por pabp. Devolve 1 em caso afirmativo e
 0 em caso contr�rio. Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int CopiarElementoDaABP (PtABP pabp, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na �rvore referenciada por pabp, caso ele
 exista. Valores de erro: OK, ABP_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumNosABP (PtABP pabp);
/*******************************************************************************
 Calcula o n�mero de n�s da �rvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

int AlturaABP (PtABP pabp);
/*******************************************************************************
 Calcula a altura da �rvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

int NumFolhasABP (PtABP pabp);
/*******************************************************************************
 Calcula o n�mero de folhas da �rvore referenciada por pabp. Valores de erro: OK.
*******************************************************************************/

void ArmazenarABPFicheiro (PtABP pabp, char *pnomef);
/*******************************************************************************
 Armazena a �rvore referenciada por pabp, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha o n�mero de n�s da �rvore, seguidos dos elementos,
 um por linha. Valores de erro: OK, ABP_EMPTY ou NO_FILE.
*******************************************************************************/

PtABP CriarABPFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma �rvore a partir de informa��o lida do ficheiro pnomef. Devolve a
 refer�ncia da �rvore criada ou NULL, caso n�o consiga criar a �rvore por
 inexist�ncia de mem�ria ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaABP (PtABP pabp);
/*******************************************************************************
 Determina o maior dos elementos da �rvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int MenorElementoDaABP (PtABP pabp);
/*******************************************************************************
 Determina o menor dos elementos da �rvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

int SomarABP (PtABP pabp);
/*******************************************************************************
 Calcula a soma dos elementos da �rvore referenciada por pabp.
 Valores de erro: OK ou ABP_EMPTY.
*******************************************************************************/

#endif
