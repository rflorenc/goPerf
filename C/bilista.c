
/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados Lista Biligada de inteiros
 (bilista.h). A implementação tem capacidade de múltipla instanciação, sendo
 providenciado um construtor para criar uma lista vazia. É da responsabilidade
 da aplicação, invocar o destrutor, para libertar a memória atribuída ao objecto.
 O módulo providencia um controlo centralizado de erro, disponibilizando uma
 função para obter o último erro ocorrido e uma função para obter uma mensagem
 de erro elucidativa.


*******************************************************************************/

#ifndef _BILISTA
#define _BILISTA

/**************** Definição do Tipo Ponteiro para uma BILISTA *****************/

typedef struct bilista *PtBilista;

/************************ Definição de Códigos de Erro ************************/

#define  OK             0  /* operação realizada com sucesso */
#define  NO_BILISTA     1  /* a bilista não existe */
#define  NO_MEM         2  /* memória esgotada */
#define  NULL_PTR       3  /* ponteiro nulo */
#define  BILISTA_EMPTY  4  /* bilista vazia */
#define  REP_ELEM       5  /* já existe o elemento */
#define  NO_ELEM        6  /* o elemento não existe */
#define  NO_FILE        7  /* o ficheiro não existe */

/*************************** Protótipos das Funções ***************************/

void InicializarErroBilista (void);
/*******************************************************************************
 Inicializa o erro.
*******************************************************************************/

int ErroBilista (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroBilista (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtBilista CriarBilista (void);
/*******************************************************************************
 Cria uma lista biligada vazia. Devolve a referência da lista criada ou NULL,
 caso não consiga criar a lista por falta de memória. 
*******************************************************************************/

void ApagarBilista (PtBilista *pbilista);
/*******************************************************************************
 Destrói a lista biligada referenciada por pbilista e devolve a referência a NULL.
 Valores de erro: OK ou NO_BILISTA.
*******************************************************************************/

PtBilista CopiarBilista (PtBilista pbilista);
/*******************************************************************************
 Copia a lista biligada referenciada por pbilista, caso ela exista. Devolve a
 referência da lista cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_BILISTA ou NO_MEM.
*******************************************************************************/

void InserirNaBilista (PtBilista pbilista, int pelem);
/*******************************************************************************
 Insere pelem na lista biligada referenciada por pbilista. Não insere elementos
 repetidos e mantém a lista ordenada por ordem crescente.
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
 afirmativo e 0 em caso contrário.
 Valores de erro: OK, NO_BILISTA ou BILISTA_EMPTY.
*******************************************************************************/

int CopiarElementoDaBilista (PtBilista pbilista, unsigned int ppos);
/*******************************************************************************
 Devolve o ppos elemento armazenado na lista biligada referenciada por pbilista,
 caso ele exista. Valores de erro: OK, NO_BILISTA, BILISTA_EMPTY ou NO_ELEM.
*******************************************************************************/

int NumElementosBilista (PtBilista pbilista);
/*******************************************************************************
 Determina o número de elementos da lista biligada referenciada por pbilista.
 Valores de erro: OK ou NO_BILISTA.
*******************************************************************************/

void ArmazenarBilistaFicheiro (PtBilista pbilista, char *pnomef);
/*******************************************************************************
 Armazena a lista biligada referenciada por pbilista, caso ela exista, no
 ficheiro pnomef. O ficheiro tem na primeira linha o número de elementos da
 lista, seguidos dos elementos, um por linha.
 Valores de erro: OK, NO_BILISTA, BILISTA_EMPTY ou NO_FILE.
*******************************************************************************/

PtBilista CriarBilistaFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma lista biligada a partir de informação lida do ficheiro pnomef. Devolve
 a referência da lista criada ou NULL, caso não consiga criar a lista por
 inexistência de memória ou do ficheiro. Valores de erro: OK, NO_FILE ou NO_MEM.
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
