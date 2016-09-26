/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados TABELA (tabela.h). A tabela de
 dispersao � composta pela sua dimens�o, pelo n�mero de elementos armazenados e
 pelos seus elementos. A implementa��o providencia um construtor para criar uma
 tabela com a dimens�o pretendida. � da responsabilidade da aplica��o, invocar o
 destrutor, para libertar a mem�ria atribu�da ao objecto. O m�dulo providencia
 um controlo centralizado de erro, disponibilizando uma fun��o para obter o
 �ltimo erro ocorrido, uma fun��o para obter uma mensagem de erro elucidativa e
 uma fun��o para limpar o erro. Providencia tamb�m opera��es para armazenar e
 recuperar tabelas para ficheiros.


*******************************************************************************/

#ifndef _TABELA
#define _TABELA

/***************** Defini��o do Tipo Ponteiro para uma TABELA *****************/ 

typedef struct tabela *PtTabela;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK        0  /* opera��o realizada com sucesso */
#define  NO_MEM    1  /* mem�ria esgotada */
#define  NO_TABLE  2  /* a tabela n�o existe */
#define  NO_FILE   3  /* o ficheiro n�o existe */
#define  BAD_SIZE  4  /* dimens�o da tabela errada */
#define  NO_ELEM   5  /* o elemento n�o existe na tabela */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroTabela (void);
/*******************************************************************************
 Inicializa��o do erro.
*******************************************************************************/

int ErroTabela (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroTabela (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtTabela CriarTabela (unsigned int pdim);
/*******************************************************************************
 Cria uma tabela com a dimens�o indicada por pdim sem elementos. Devolve a
 refer�ncia da tabela criada ou NULL, caso n�o consiga criar a tabela, por falta
 de mem�ria. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarTabela (PtTabela *ptab);
/*******************************************************************************
 Destr�i a tabela referenciada por ptab, caso ela exista, e coloca a sua
 refer�ncia a NULL. Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

PtTabela CopiarTabela (PtTabela ptab);
/*******************************************************************************
 Copia a tabela referenciada por ptab, caso ela exista. Devolve a refer�ncia da
 tabela c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK, NO_TABLE ou NO_MEM.
*******************************************************************************/

int DimensaoTabela (PtTabela ptab);
/*******************************************************************************
 Determina a dimens�o da tabela referenciada por ptab.
 Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

int NumElementosTabela (PtTabela ptab);
/*******************************************************************************
 Determina o n�mero de elementos armazenados na tabela referenciada por ptab.
 Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

void InserirNaTabela (PtTabela ptab, int pelem);
/*******************************************************************************
 Insere pelem na tabela referenciada por ptab.
 Valores de erro: OK, NO_TABLE ou BAD_INDEX.
*******************************************************************************/

void RemoverDaTabela (PtTabela ptab, int pelem);
/*******************************************************************************
 Retira pelem da tabela referenciada por ptab. Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

int PesquisarTabela (PtTabela ptab, int pelem);
/*******************************************************************************
 Pesquisa pelem na tabela referenciada por ptab. Devolve 1 em caso afirmativo e
 0 em caso contr�rio. Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

void DuplicarTabela (PtTabela *ptab);
/*******************************************************************************
 Duplica a tabela (rehashing) referenciada por ptab, caso ela exista.
 Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

void ArmazenarTabelaFicheiro (PtTabela ptab, char *pnomef);
/*******************************************************************************
 Armazena a tabela referenciada por ptab, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha a dimens�o da tabela, na segunda linha o n�mero
 de elementos armazenados, seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_TABLE ou NO_FILE.
*******************************************************************************/

PtTabela CriarTabelaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma tabela a partir de informa��o lida do ficheiro pnomef. Devolve a
 refer�ncia da tabela criada ou NULL, caso n�o consiga criar a tabela.
 Valores de erro: OK, NO_FILE, BAD_SIZE ou NO_MEM.
*******************************************************************************/

#endif
