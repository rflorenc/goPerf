/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados VECTOR (vector.h). O vector é
 composto pela sua dimensão e pelas suas componentes reais. A implementação
 providencia um construtor para criar um vector nulo com a dimensão pretendida.
 É da responsabilidade da aplicação, invocar o destrutor, para libertar a
 memória atribuída ao objecto. O módulo providencia um controlo centralizado de
 erro, disponibilizando uma função para obter o último erro ocorrido, uma função
 para obter uma mensagem de erro elucidativa e uma função para limpar o erro.
 Providencia também operações para armazenar e recuperar vectores para ficheiros.


*******************************************************************************/

#ifndef _VECTOR
#define _VECTOR

/****************** Definição do Tipo Ponteiro para um VECTOR *****************/

typedef struct vector *PtVector;

/************************ Definição de Códigos de Erro ************************/

#define  OK         0  /* operação realizada com sucesso */
#define  NO_MEM     1  /* memória esgotada */
#define  NO_VECTOR  2  /* o(s) vector(es) não existe(m) */
#define  NO_FILE    3  /* o ficheiro não existe */
#define  BAD_SIZE   4  /* dimensão do vector errada */
#define  BAD_INDEX  5  /* elemento inexistente no vector */
#define  DIF_SIZE   6  /* vectores com dimensões diferentes */

/*************************** Protótipos das Funções ***************************/

void InicializarErroVector (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroVector (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroVector (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtVector CriarVectorNulo (unsigned int pdim);
/*******************************************************************************
 Cria um vector nulo, de componentes reais, com a dimensão indicada por pdim.
 Devolve a referência do vector criado ou NULL, caso não consiga criar o vector,
 por falta de memória. Valores de erro: OK, BAD_SIZE ou NO_MEM.
*******************************************************************************/

void ApagarVector (PtVector *pvec);
/*******************************************************************************
 Destrói o vector referenciado por pvec, caso ele exista, e coloca a sua
 referência a NULL. Valores de erro: OK ou NO_VECTOR.
*******************************************************************************/

PtVector CopiarVector (PtVector pvec);
/*******************************************************************************
 Copia o vector referenciado por pvec, caso ele exista. Devolve a referência do
 vector cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_VECTOR ou NO_MEM.
*******************************************************************************/

int DimensaoVector (PtVector pvec);
/*******************************************************************************
 Devolve a dimensão do vector referenciado por pvec.
 Valores de erro: OK ou NO_VECTOR.
*******************************************************************************/

void EscreverCompVector (PtVector pvec, unsigned int ppos, double pval);
/*******************************************************************************
 Armazena pval no índice ppos do vector referenciado por pvec.
 Valores de erro: OK, NO_VECTOR ou BAD_INDEX.
*******************************************************************************/

double LerCompVector (PtVector pvec, unsigned int ppos);
/*******************************************************************************
 Devolve o valor armazenado no índice ppos do vector referenciado por pvec.
 Valores de erro: OK, NO_VECTOR ou BAD_INDEX.
*******************************************************************************/

int VectorNulo (PtVector pvec);
/*******************************************************************************
 Verifica se o vector referenciado por pvec é um vector nulo. Devolve 1 em caso
 afirmativo e 0 em caso contrário. Valores de erro: OK ou NO_VECTOR.
*******************************************************************************/

PtVector SomarVectores (PtVector pvec1, PtVector pvec2);
/*******************************************************************************
 Soma os dois vectores referenciados por pvec1 e pvec2. Devolve a referência do
 vector soma ou NULL, caso não consiga fazer a adição.
 Valores de erro: OK, NO_VECTOR, DIF_SIZE ou NO_MEM.
*******************************************************************************/

PtVector SubtrairVectores (PtVector pvec1, PtVector pvec2);
/*******************************************************************************
 Subtrai os dois vectores referenciados por pvec1 e pvec2. Devolve a referência
 do vector diferença ou NULL, caso não consiga fazer a subtracção.
 Valores de erro: OK, NO_VECTOR, DIF_SIZE ou NO_MEM.
*******************************************************************************/

PtVector ProdutoVectorialVectores (PtVector pvec1, PtVector pvec2);
/*******************************************************************************
 Faz o produto vectorial dos dois vectores referenciados por pvec1 e pvec2.
 Devolve a referência do vector produto ou NULL, caso não consiga fazer a
 multiplicação. Valores de erro: OK, NO_VECTOR ou DIF_SIZE.
*******************************************************************************/

double  ProdutoEscalarVectores (PtVector pvec1, PtVector pvec2);
/*******************************************************************************
 Devolve o produto escalar dos dois vectores referenciados por pvec1 e pvec2, ou
 0, caso não possa realizar o produto. Valores de erro: OK, NO_VECTOR ou DIF_SIZE.
*******************************************************************************/

int CompararVectores (PtVector pvec1, PtVector pvec2);
/*******************************************************************************
 Compara se os dois vectores referenciados por pvec1 e pvec2 são idênticos.
 Devolve 1 em caso afirmativo e 0 em caso contrário.
 Valores de erro: OK, NO_VECTOR ou DIF_SIZE.
*******************************************************************************/

void ArmazenarVectorFicheiro (PtVector pvec, char *pnonef);
/*******************************************************************************
 Armazena o vector referenciado por pvec, caso ele exista, no ficheiro pnonef.
 O ficheiro tem na primeira linha o número de componentes do vector, seguido das
 componentes, uma por linha. Valores de erro: OK, NO_VECTOR ou NO_FILE.
*******************************************************************************/

PtVector CriarVectorFicheiro (char *pnonef);
/*******************************************************************************
 Cria um vector a partir de informação lida do ficheiro pnonef. Devolve a
 referência do vector criado ou NULL, caso não consiga criar o vector.
 Valores de erro: OK, NO_FILE, BAD_SIZE ou NO_MEM.
*******************************************************************************/

#endif
