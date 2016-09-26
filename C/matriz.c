/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados MATRIZ (matriz.h). A matriz �
 identificada pela sua dimens�o, ou seja, pelo n�mero de linhas NL e pelo n�mero
 de colunas NC e armazena elementos inteiros. A implementa��o providencia um
 construtor para criar uma matriz nula. � da responsabilidade da aplica��o,
 invocar o destrutor, para libertar a mem�ria atribu�da ao objecto. O m�dulo
 providencia um controlo centralizado de erro, disponibilizando uma fun��o para
 obter o �ltimo erro ocorrido, uma fun��o para obter uma mensagem de erro
 elucidativa e uma fun��o para limpar o erro. Providencia tamb�m opera��es para
 armazenar e recuperar matrizes para ficheiros.


*******************************************************************************/

#ifndef _MATRIZ
#define _MATRIZ

/***************** Defini��o do Tipo Ponteiro para uma MATRIZ *****************/

typedef struct matriz *PtMatriz;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK          0  /* opera��o realizada com sucesso */
#define  NO_MEM      1  /* mem�ria esgotada */
#define  NO_MATRIX   2  /* a(s) matriz(es) n�o existe(m) */
#define  NO_FILE     3  /* o ficheiro n�o existe */
#define  BAD_SIZE    4  /* dimens�o errada */
#define  BAD_INDEX   5  /* elemento inexistente na matriz */
#define  DIF_SIZE    6  /* matrizes com dimens�es diferentes */
#define  NO_CHAINED  7  /* matrizes n�o encadeadas */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroMatriz (void);
/*******************************************************************************
 Inicializa��o do erro.
*******************************************************************************/

int ErroMatriz (void);
/*******************************************************************************
 Devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroMatriz (void);
/*******************************************************************************
 Devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtMatriz CriarMatrizNula (unsigned int pnl, unsigned int pnc);
/*******************************************************************************
 Cria uma matriz nula, com pnl linhas e pnc colunas, para armazenar elementos
 inteiros. Devolve a refer�ncia da matriz criada ou NULL, caso n�o consiga criar
 a matriz. Valores de erro: OK, BAD_SIZE ou NO_MEM.
*******************************************************************************/

void ApagarMatriz (PtMatriz *pmat);
/*******************************************************************************
 Destr�i a matriz referenciada por pmat, caso ela exista, e coloca a sua refer�ncia
 a NULL. Valores de erro: OK ou NO_MATRIX.
*******************************************************************************/

PtMatriz CopiarMatriz (PtMatriz pmat);
/*******************************************************************************
 Copia a matriz referenciada por pmat, caso ela exista. Devolve a refer�ncia da
 matriz criada ou NULL, caso n�o consiga criar a matriz.
 Valores de erro: NO_MATRIX ou NO_MEM.
*******************************************************************************/

void DimensaoMatriz (PtMatriz pmat, unsigned int *pnl, unsigned int *pnc);
/*******************************************************************************
 Devolve a dimens�o da matriz referenciada por pmat, caso ela exista.
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
 refer�ncia da matriz transposta ou NULL, caso n�o consiga fazer a opera��o.
 Valores de erro: OK, NO_MATRIX ou NO_MEM.
*******************************************************************************/
 
PtMatriz  SomarMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Soma as duas matrizes referenciadas por pmat1 e pmat2. Devolve a refer�ncia da
 matriz soma ou NULL, caso n�o consiga fazer a adi��o.
 Valores de erro: OK, NO_MATRIX, DIF_SIZE ou NO_MEM.
*******************************************************************************/

PtMatriz  MultiplicarMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Multiplica as duas matrizes referenciadas por pmat1 e pmat2. Devolve a
 refer�ncia da matriz produto ou NULL, caso n�o consiga fazer a multipli��o.
 Valores de erro: OK, NO_MATRIX, NO_CHAINED ou NO_MEM.
*******************************************************************************/

int  CompararMatrizes (PtMatriz pmat1, PtMatriz pmat2);
/*******************************************************************************
 Compara se as duas matrizes referenciadas por pmat1 e pmat2 s�o id�nticas.
 Devolve 1 em caso afirmativo e 0 em caso contr�rio.
 Valores de erro: OK, NO_MATRIX ou DIF_SIZE.
*******************************************************************************/

void ArmazenarMatrizFicheiro (PtMatriz pmat, char *pnomef);
/*******************************************************************************
 Armazena a matriz referenciada por pmat, caso ela exista, no ficheiro pnomef.
 O ficheiro tem na primeira linha o n�mero de linhas e o n�mero de colunas da
 matriz, seguido das linhas de elementos da matriz.
 Valores de erro: OK, NO_MATRIX ou NO_FILE.
*******************************************************************************/

PtMatriz CriarMatrizFicheiro (char *pnomef);
/*******************************************************************************
 Cria uma matriz a partir de informa��o lida do ficheiro pnomef. Devolve a
 refer�ncia da matriz criada ou NULL, caso n�o consiga criar a matriz.
 Valores de erro: OK, NO_FILE, BAD_SIZE ou NO_MEM.
*******************************************************************************/

#endif
