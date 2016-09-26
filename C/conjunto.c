/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados CONJUNTO (conjunto.h).
 O conjunto é composto pela seu cardinal e pelos seus elementos de tipo carácter.
 A implementação providencia um construtor para criar um conjunto vazio. É da
 responsabilidade da aplicação, invocar o destrutor, para libertar a memória
 atribuída ao objecto. O módulo providencia um controlo centralizado de erro,
 disponibilizando uma função para obter o último erro ocorrido, uma função para
 obter uma mensagem de erro elucidativa e uma função para limpar o erro.
 Providencia também operações para armazenar e recuperar conjuntos para ficheiros.


*******************************************************************************/

#ifndef _CONJUNTO
#define _CONJUNTO

/**************** Definição do Tipo Ponteiro para um CONJUNTO *****************/

typedef struct conjunto *PtConjunto;

/************************ Definição de Códigos de Erro ************************/

#define  OK        0  /* operação realizada com sucesso */
#define  NO_MEM    1  /* memória esgotada */
#define  NO_SET    2  /* o(s) conjunto(s) não existe(m) */
#define  NO_FILE   3  /* o ficheiro não existe */
#define  NO_ELEM   4  /* o elemento não existe no conjunto */
#define  REP_ELEM  5  /* o elemento já existe no conjunto */

/*************************** Protótipos das Funções ***************************/

void InicializarErroConjunto (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroConjunto (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroConjunto (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtConjunto CriarConjuntoVazio (void);
/*******************************************************************************
 Cria um conjunto nulo. Devolve a referência do conjunto criado ou NULL, caso
 não consiga criar o conjunto, por falta de memória. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarConjunto (PtConjunto *pconj);
/*******************************************************************************
 Destrói o conjunto referenciado por pconj, caso ele exista, e coloca a sua
 referência a NULL. Valores de erro: OK ou NO_SET.
*******************************************************************************/

PtConjunto CopiarConjunto (PtConjunto pconj);
/*******************************************************************************
 Copia o conjunto referenciado por pconj, caso ele exista. Devolve a referência
 do conjunto cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

int CardinalConjunto (PtConjunto pconj);
/*******************************************************************************
 Determina o cardinal do conjunto referenciado por pconj.
 Valores de erro: OK ou NO_SET.
*******************************************************************************/

int InserirElemConjunto (PtConjunto pconj, char pelem);
/*******************************************************************************
 Insere pelem no conjunto referenciado por pconj, caso ele ainda não exista no
 conjunto. Devolve 1 no caso da inserção ser realizada com sucesso e 0 no caso
 contrário. Valores de erro: OK, NO_SET, REP_ELEM ou NO_MEM.
*******************************************************************************/

int RetirarElemConjunto (PtConjunto pconj, char pelem);
/*******************************************************************************
 Remove pelem do conjunto referenciado por pconj, caso ele exista no conjunto.
 Devolve 1 no caso da remoção ser realizada com sucesso e 0 no caso contrário.
 Valores de erro: OK, NO_SET ou NO_ELEM.
*******************************************************************************/

char LerElemConjunto (PtConjunto pconj, unsigned int ppos);
/*******************************************************************************
 Devolve o elemento armazenado na posição ppos, do conjunto referenciado por pconj.
 Valores de erro: OK, NO_SET ou NO_ELEM.
*******************************************************************************/

int ElementoConjunto (PtConjunto pconj, char elemento);
/*******************************************************************************
 Verifica se o elemento existe no conjunto referenciado por pconj. Devolve 1 em
 caso afirmativo e 0 em caso contrário. Valores de erro: OK ou NO_SET.
*******************************************************************************/

PtConjunto ReuniaoConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Faz a reunião dos dois conjuntos referenciados por pconj1 e pconj2. Devolve a
 referência do conjunto criado ou NULL, caso não consiga realizar a reunião por
 falta de memória. Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

PtConjunto InterseccaoConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Faz a intersecção dos dois conjuntos referenciados por pconj1 e pconj2. Devolve
 a referência do conjunto criado ou NULL, caso não consiga realizar a intersecção
 por falta de memória. Valores de erro: OK, NO_SET ou NO_MEM.
*******************************************************************************/

int CompararConjuntos (PtConjunto pconj1, PtConjunto pconj2);
/*******************************************************************************
 Compara se os dois conjuntos referenciados por pconj1 e pconj2 são idênticos.
 Devolve 1 em caso afirmativo e 0 em caso contrário. Valores de erro: OK ou NO_SET.
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
 referência do conjunto criado ou NULL, caso não consiga criar o conjunto, por
 falta de memória. Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

#endif
