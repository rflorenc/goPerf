/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados TABELA (tabela.h). A tabela de
 dispersao é composta pela sua dimensão, pelo número de elementos armazenados e
 pelos seus elementos. A implementação providencia um construtor para criar uma
 tabela com a dimensão pretendida. É da responsabilidade da aplicação, invocar o
 destrutor, para libertar a memória atribuída ao objecto. O módulo providencia
 um controlo centralizado de erro, disponibilizando uma função para obter o
 último erro ocorrido, uma função para obter uma mensagem de erro elucidativa e
 uma função para limpar o erro. Providencia também operações para armazenar e
 recuperar tabelas para ficheiros.


*******************************************************************************/

#ifndef _TABELA
#define _TABELA

/***************** Definição do Tipo Ponteiro para uma TABELA *****************/ 

typedef struct tabela *PtTabela;

/************************ Definição de Códigos de Erro ************************/

#define  OK        0  /* operação realizada com sucesso */
#define  NO_MEM    1  /* memória esgotada */
#define  NO_TABLE  2  /* a tabela não existe */
#define  NO_FILE   3  /* o ficheiro não existe */
#define  BAD_SIZE  4  /* dimensão da tabela errada */
#define  NO_ELEM   5  /* o elemento não existe na tabela */

/*************************** Protótipos das Funções ***************************/

void InicializarErroTabela (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroTabela (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroTabela (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtTabela CriarTabela (unsigned int pdim);
/*******************************************************************************
 Cria uma tabela com a dimensão indicada por pdim sem elementos. Devolve a
 referência da tabela criada ou NULL, caso não consiga criar a tabela, por falta
 de memória. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarTabela (PtTabela *ptab);
/*******************************************************************************
 Destrói a tabela referenciada por ptab, caso ela exista, e coloca a sua
 referência a NULL. Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

PtTabela CopiarTabela (PtTabela ptab);
/*******************************************************************************
 Copia a tabela referenciada por ptab, caso ela exista. Devolve a referência da
 tabela cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_TABLE ou NO_MEM.
*******************************************************************************/

int DimensaoTabela (PtTabela ptab);
/*******************************************************************************
 Determina a dimensão da tabela referenciada por ptab.
 Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

int NumElementosTabela (PtTabela ptab);
/*******************************************************************************
 Determina o número de elementos armazenados na tabela referenciada por ptab.
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
 0 em caso contrário. Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

void DuplicarTabela (PtTabela *ptab);
/*******************************************************************************
 Duplica a tabela (rehashing) referenciada por ptab, caso ela exista.
 Valores de erro: OK ou NO_TABLE.
*******************************************************************************/

void ArmazenarTabelaFicheiro (PtTabela ptab, char *pnomef);
/*******************************************************************************
 Armazena a tabela referenciada por ptab, caso ela exista, no ficheiro pnomef. O
 ficheiro tem na primeira linha a dimensão da tabela, na segunda linha o número
 de elementos armazenados, seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_TABLE ou NO_FILE.
*******************************************************************************/

PtTabela CriarTabelaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma tabela a partir de informação lida do ficheiro pnomef. Devolve a
 referência da tabela criada ou NULL, caso não consiga criar a tabela.
 Valores de erro: OK, NO_FILE, BAD_SIZE ou NO_MEM.
*******************************************************************************/

#endif
