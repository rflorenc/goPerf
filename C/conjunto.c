/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados CONJUNTO (conjunto.h).
 O conjunto � composto pela seu cardinal e pelos seus elementos de tipo car�cter.
 A implementa��o providencia um construtor para criar um conjunto vazio. � da
 responsabilidade da aplica��o, invocar o destrutor, para libertar a mem�ria
 atribu�da ao objecto. O m�dulo providencia um controlo centralizado de erro,
 disponibilizando uma fun��o para obter o �ltimo erro ocorrido, uma fun��o para
 obter uma mensagem de erro elucidativa e uma fun��o para limpar o erro.
 Providencia tamb�m opera��es para armazenar e recuperar conjuntos para ficheiros.


*******************************************************************************/

#ifndef _CONJUNTO
#define _CONJUNTO

/**************** Defini��o do Tipo Ponteiro para um CONJUNTO *****************/

typedef struct conjunto *PtConjunto;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK        0  /* opera��o realizada com sucesso */
#define  NO_MEM    1  /* mem�ria esgotada */
#define  NO_SET    2  /* o(s) conjunto(s) n�o existe(m) */
#define  NO_FILE   3  /* o ficheiro n�o existe */
#define  NO_ELEM   4  /* o elemento n�o existe no conjunto */
#define  REP_ELEM  5  /* o elemento j� existe no conjunto */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroConjunto (void);
/*******************************************************************************
 Inicializa��o do erro.
*******************************************************************************/

int ErroConjunto (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroConjunto (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtConjunto CriarConjuntoVazio (void);
/*******************************************************************************
 Cria um conjunto nulo. Devolve a refer�ncia do conjunto criado ou NULL, caso
 n�o consiga criar o conjunto, por falta de mem�ria. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarConjunto (PtConjunto *pconj);
/*******************************************************************************
 Destr�i o conjunto referenciado por pconj, caso ele exista, e coloca a sua
 refer�ncia a NULL. Valores de erro: OK ou NO_SET.
*******************************************************************************/

PtConjunto CopiarConjunto (PtConjunto pconj);
/*******************************************************************************
 Copia o conjunto referenciado por pconj, caso ele exista. Devolve a refer�ncia
 do conjunto c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

int CardinalConjunto (PtConjunto pconj);
/*******************************************************************************
 Determina o cardinal do conjunto referenciado por pconj.
 Valores de erro: OK ou NO_SET.
*******************************************************************************/

int InserirElemConjunto (PtConjunto pconj, char pelem);
/*******************************************************************************
 Insere pelem no conjunto referenciado por pconj, caso ele ainda n�o exista no
 conjunto. Devolve 1 no caso da inser��o ser realizada com sucesso e 0 no caso
 contr�rio. Valores de erro: OK, NO_SET, REP_ELEM ou NO_MEM.
*******************************************************************************/

int RetirarElemConjunto (PtConjunto pconj, char pelem);
/*******************************************************************************
 Remove pelem do conjunto referenciado por pconj, caso ele exista no conjunto.
 Devolve 1 no caso da remo��o ser realizada com sucesso e 0 no caso contr�rio.
 Valores de erro: OK, NO_SET ou NO_ELEM.
*******************************************************************************/

char LerElemConjunto (PtConjunto pconj, unsigned int ppos);
/*******************************************************************************
 Devolve o elemento armazenado na posi��o ppos, do conjunto referenciado por pconj.
 Valores de erro: OK, NO_SET ou NO_ELEM.
*******************************************************************************/

int ElementoConjunto (PtConjunto pconj, char elemento);
/*******************************************************************************
 Verifica se o elemento existe no conjunto referenciado por pconj. Devolve 1 em
 caso afirmativo e 0 em caso contr�rio. Valores de erro: OK ou NO_SET.
*******************************************************************************/

PtConjunto ReuniaoConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Faz a reuni�o dos dois conjuntos referenciados por pconj1 e pconj2. Devolve a
 refer�ncia do conjunto criado ou NULL, caso n�o consiga realizar a reuni�o por
 falta de mem�ria. Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

PtConjunto InterseccaoConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Faz a intersec��o dos dois conjuntos referenciados por pconj1 e pconj2. Devolve
 a refer�ncia do conjunto criado ou NULL, caso n�o consiga realizar a intersec��o
 por falta de mem�ria. Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

int CompararConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Compara se os dois conjuntos referenciados por pconj1 e pconj2 s�o id�nticos.
 Devolve 1 em caso afirmativo e 0 em caso contr�rio. Valores de erro: OK ou NO_SET.
*******************************************************************************/

void ArmazenarConjuntoFicheiro (PtConjunto pconj, char *pnomef);
/*******************************************************************************
 Armazena o conjunto referenciado por pconj, caso ele exista, no ficheiro pnonef.
 O ficheiro tem na primeira linha o cardinal do conjunto, seguido dos elementos,
 um por linha. Valores de erro: OK, NO_SET ou NO_FILE.
*******************************************************************************/

PtConjunto CriarConjuntoFicheiro (char *pnomef);
/*******************************************************************************
 Cria um conjunto a partir de informacao lida do ficheiro pnonef. Devolve a
 refer�ncia do conjunto criado ou NULL, caso n�o consiga criar o conjunto, por
 falta de mem�ria. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

#endif
