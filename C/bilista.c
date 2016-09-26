
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Lista Biligada de inteiros
 (bilista.h). A implementa��o tem capacidade de m�ltipla instancia��o, sendo
 providenciado um construtor para criar uma lista vazia. � da responsabilidade
 da aplica��o, invocar o destrutor, para libertar a mem�ria atribu�da ao objecto.
 O m�dulo providencia um controlo centralizado de erro, disponibilizando uma
 fun��o para obter o �ltimo erro ocorrido e uma fun��o para obter uma mensagem
 de erro elucidativa.


*******************************************************************************/

#ifndef _BILISTA
#define _BILISTA

/**************** Defini��o do Tipo Ponteiro para uma BILISTA *****************/

typedef struct bilista *PtBilista;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK             0  /* opera��o realizada com sucesso */
#define  NO_BILISTA     1  /* a bilista n�o existe */
#define  NO_MEM         2  /* mem�ria esgotada */
#define  NULL_PTR       3  /* ponteiro nulo */
#define  BILISTA_EMPTY  4  /* bilista vazia */
#define  REP_ELEM       5  /* j� existe o elemento */
#define  NO_ELEM        6  /* o elemento n�o existe */
#define  NO_FILE        7  /* o ficheiro n�o existe */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroBilista (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroBilista (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroBilista (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtBilista CriarBilista (void);
/*******************************************************************************
 Cria uma lista biligada vazia. Devolve a refer�ncia da lista criada ou NULL,
 caso n�o consiga criar a lista por falta de mem�ria. 
*******************************************************************************/

void ApagarBilista (PtBilista *pbilista);
/*******************************************************************************
 Destr�i a lista biligada referenciada por pbilista e devolve a refer�ncia a NULL.
 Valores de erro: OK ou NO_BILISTA.
*******************************************************************************/

PtBilista CopiarBilista (PtBilista pbilista);
/*******************************************************************************
 Copia a lista biligada referenciada por pbilista, caso ela exista. Devolve a
 refer�ncia da lista c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK, NO_BILISTA ou NO_MEM.
*******************************************************************************/

void InserirNaBilista (PtBilista pbilista, int pelem);
/*******************************************************************************
 Insere pelem na lista biligada referenciada por pbilista. N�o insere elementos
 repetidos e mant�m a lista ordenada por ordem crescente.
 Valores de erro: OK, NO_BILISTA, NO_MEM ou REP_ELE.
*******************************************************************************/

void RemoverDaBilista (PtBilista pbilista, int pelem);
/*******************************************************************************
 Retira pelem da lista biligada referenciada por pbilista.
 Valores de erro: OK, NO_BILISTA ou NO_ELEM.
*******************************************************************************/

int PesquisarBilista (PtBilista pbilista, int pelem);
/*******************************************************************************
 Pesquisa pelem na lista biligada referenciada por pbilista. Devolve 1 em caso
 afirmativo e 0 em caso contr�rio.
 Valores de erro: OK, NO_BILISTA ou BILISTA_EMPTY.
*******************************************************************************/

int CopiarElementoDaBilista (PtBilista pbilista, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na lista biligada referenciada por pbilista,
 caso ele exista. Valores de erro: OK, NO_BILISTA, BILISTA_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumElementosBilista (PtBilista pbilista);
/*******************************************************************************
 Determina o n�mero de elementos da lista biligada referenciada por pbilista.
 Valores de erro: OK ou NO_BILISTA.
*******************************************************************************/

void ArmazenarBilistaFicheiro (PtBilista pbilista, char *pnomef);
/*******************************************************************************
 Armazena a lista biligada referenciada por pbilista, caso ela exista, no
 ficheiro pnomef. O ficheiro tem na primeira linha o n�mero de elementos da
 lista, seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_BILISTA, BILISTA_EMPTY ou NO_FILE.
*******************************************************************************/

PtBilista CriarBilistaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma lista biligada a partir de informa��o lida do ficheiro pnomef. Devolve
 a refer�ncia da lista criada ou NULL, caso n�o consiga criar a lista por
 inexist�ncia de mem�ria ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

int MaiorElementoDaBilista (PtBilista pbilista);
/*******************************************************************************
 Determina o maior dos elementos da lista biligada referenciada por pbilista.
 Valores de erro: OK, NO_BILISTA ou BILISTA_EMPTY.
*******************************************************************************/

int MenorElementoDaBilista (PtBilista pbilista);
/*******************************************************************************
 Determina o menor dos elementos da lista biligada referenciada por pbilista.
 Valores de erro: OK, NO_BILISTA ou BILISTA_EMPTY.
*******************************************************************************/

int SomarBilista (PtBilista pbilista);
/*******************************************************************************
 Calcula a soma dos elementos da lista biligada referenciada por pbilista.
 Valores de erro: OK, NO_BILISTA ou BILISTA_EMPTY.
*******************************************************************************/

#endif
