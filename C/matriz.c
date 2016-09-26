/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados MATRIZ (matriz.h). A matriz é
 identificada pela sua dimensão, ou seja, pelo número de linhas NL e pelo número
 de colunas NC e armazena elementos inteiros. A implementação providencia um
 construtor para criar uma matriz nula. É da responsabilidade da aplicação,
 invocar o destrutor, para libertar a memória atribuída ao objecto. O módulo
 providencia um controlo centralizado de erro, disponibilizando uma função para
 obter o último erro ocorrido, uma função para obter uma mensagem de erro
 elucidativa e uma função para limpar o erro. Providencia também operações para
 armazenar e recuperar matrizes para ficheiros.


*******************************************************************************/

#ifndef _MATRIZ
#define _MATRIZ

/***************** Definição do Tipo Ponteiro para uma MATRIZ *****************/

typedef struct matriz *PtMatriz;

/************************ Definição de Códigos de Erro ************************/

#define  OK          0  /* operação realizada com sucesso */
#define  NO_MEM      1  /* memória esgotada */
#define  NO_MATRIX   2  /* a(s) matriz(es) não existe(m) */
#define  NO_FILE     3  /* o ficheiro não existe */
#define  BAD_SIZE    4  /* dimensão errada */
#define  BAD_INDEX   5  /* elemento inexistente na matriz */
#define  DIF_SIZE    6  /* matrizes com dimensões diferentes */
#define  NO_CHAINED  7  /* matrizes não encadeadas */

/*************************** Protótipos das Funções ***************************/

void InicializarErroMatriz (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroMatriz (void);
/*******************************************************************************
 Devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroMatriz (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtMatriz CriarMatrizNula (unsigned int pnl, unsigned int pnc);
/*******************************************************************************
 Cria uma matriz nula, com pnl linhas e pnc colunas, para armazenar elementos
 inteiros. Devolve a referência da matriz criada ou NULL, caso não consiga criar
 a matriz. Valores de erro: OK, BAD_SIZE ou NO_MEM.
*******************************************************************************/

void ApagarMatriz (PtMatriz *pmat);
/*******************************************************************************
 Destrói a matriz referenciada por pmat, caso ela exista, e coloca a sua referência
 a NULL. Valores de erro: OK ou NO_MATRIX.
*******************************************************************************/

PtMatriz CopiarMatriz (PtMatriz pmat);
/*******************************************************************************
 Copia a matriz referenciada por pmat, caso ela exista. Devolve a referência da
 matriz criada ou NULL, caso não consiga criar a matriz.
 Valores de erro: NO_MATRIX ou NO_MEM.
*******************************************************************************/

void DimensaoMatriz (PtMatriz pmat, unsigned int *pnl, unsigned int *pnc);
/*******************************************************************************
 Devolve a dimensão da matriz referenciada por pmat, caso ela exista.
 Valores de erro: OK ou NO_MATRIX.
*******************************************************************************/

void EscreverCompMatriz (PtMatriz pmat, unsigned int pl, unsigned int pc, int pval);
/*******************************************************************************
 Armazena pval na linha pl e na coluna pc da matriz referenciada por pmat.
 Valores de erro: OK, NO_MATRIX ou BAD_INDEX.
*******************************************************************************/

int LerCompMatriz (PtMatriz pmat, unsigned int pl, unsigned int pc);
/*******************************************************************************
 Devolve o valor armazenado na linha pl e na coluna pc da matriz referenciada
 por pmat. Valores de erro: OK, NO_MATRIX ou BAD_INDEX.
*******************************************************************************/

PtMatriz  MatrizTransposta (PtMatriz pmat);
/*******************************************************************************
 Calcula a matriz transposta da matriz referenciadas por pmat. Devolve a
 referência da matriz transposta ou NULL, caso não consiga fazer a operação.
 Valores de erro: OK, NO_MATRIX ou NO_MEM.
*******************************************************************************/
 
PtMatriz  SomarMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Soma as duas matrizes referenciadas por pmat1 e pmat2. Devolve a referência da
 matriz soma ou NULL, caso não consiga fazer a adição.
 Valores de erro: OK, NO_MATRIX, DIF_SIZE ou NO_MEM.
*******************************************************************************/

PtMatriz  MultiplicarMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Multiplica as duas matrizes referenciadas por pmat1 e pmat2. Devolve a
 referência da matriz produto ou NULL, caso não consiga fazer a multiplição.
 Valores de erro: OK, NO_MATRIX, NO_CHAINED ou NO_MEM.
*******************************************************************************/

int  CompararMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Compara se as duas matrizes referenciadas por pmat1 e pmat2 são idênticas.
 Devolve 1 em caso afirmativo e 0 em caso contrário.
 Valores de erro: OK, NO_MATRIX ou DIF_SIZE.
*******************************************************************************/

void ArmazenarMatrizFicheiro (PtMatriz pmat, char *pnomef);
/*******************************************************************************
 Armazena a matriz referenciada por pmat, caso ela exista, no ficheiro pnomef.
 O ficheiro tem na primeira linha o número de linhas e o número de colunas da
 matriz, seguido das linhas de elementos da matriz.
 Valores de erro: OK, NO_MATRIX ou NO_FILE.
*******************************************************************************/

PtMatriz CriarMatrizFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma matriz a partir de informação lida do ficheiro pnomef. Devolve a
 referência da matriz criada ou NULL, caso não consiga criar a matriz.
 Valores de erro: OK, NO_FILE, BAD_SIZE ou NO_MEM.
*******************************************************************************/

#endif
