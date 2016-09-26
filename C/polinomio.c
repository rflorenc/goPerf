/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados POLINOMIO (polinomio.h).
 O polin�mio � composto pelo seu grau e pelos seus coeficientes reais, sendo
 que um polin�mio com grau n tem n+1 coeficientes. A implementa��o providencia
 um construtor para criar um polin�mio nulo com o grau pretendido. � da
 responsabilidade da aplica��o, invocar o destrutor, para libertar a mem�ria
 atribu�da ao objecto. O m�dulo providencia um controlo centralizado de erro,
 disponibilizando uma fun��o para obter o �ltimo erro ocorrido, uma fun��o para
 obter uma mensagem de erro elucidativa e uma fun��o para limpar o erro.
 Providencia tamb�m opera��es para armazenar e recuperar polin�mios para ficheiros.
 


*******************************************************************************/

#ifndef _POLINOMIO
#define _POLINOMIO

/**************** Defini��o do Tipo Ponteiro para um POLINOMIO ****************/

typedef struct polinomio *PtPolinomio;

/************************ Defini��o de C�digos de Erro ************************/


#define  OK         0  /* opera��o realizada com sucesso */
#define  NO_MEM     1  /* mem�ria esgotada */
#define  NO_POLY    2  /* o(s) polin�mio(s) n�o existe(m) */
#define  NO_FILE    3  /* o ficheiro n�o existe */
#define  BAD_SIZE   4  /* grau do polin�mio errada */
#define  BAD_INDEX  5  /* coeficiente inexistente no polin�mio */

/*************************** Prot�tipos das Fun��es ***************************/

void InicializarErroPolinomio (void);
/*******************************************************************************
 Inicializa��o do erro.
*******************************************************************************/

int ErroPolinomio (void);
/*******************************************************************************
 Fun��o que devolve o c�digo do �ltimo erro ocorrido.
*******************************************************************************/

char *MensagemErroPolinomio (void);
/*******************************************************************************
 Fun��o que devolve uma mensagem esclarecedora da causa do �ltimo erro ocorrido.
*******************************************************************************/

PtPolinomio CriarPolinomioNulo (unsigned int pgrau);
/*******************************************************************************
 Cria um polin�mio nulo, de coeficientes reais, com o grau indicado por pgrau.
 Devolve a refer�ncia do polin�mio criado ou NULL, caso n�o consiga criar o
 polin�mio, por falta de mem�ria. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarPolinomio (PtPolinomio *ppol);
/*******************************************************************************
 Destr�i o polin�mio referenciado por ppol, caso ele exista, e coloca a sua
 refer�ncia a NULL. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

PtPolinomio CopiarPolinomio (PtPolinomio ppol);
/*******************************************************************************
 Copia do polin�mio referenciado por ppol, caso ele exista. Devolve a refer�ncia
 do polin�mio c�pia ou NULL, caso n�o consiga fazer a c�pia.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

int GrauPolinomio (PtPolinomio ppol);
/*******************************************************************************
 Devolve o grau do polin�mio referenciado por ppol. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

void EscreverCoefPolinomio (PtPolinomio ppol, unsigned int ppos, double pval);
/*******************************************************************************
 Armazena pval no �ndice ppos, do polin�mio referenciado por ppol.
 Valores de erro: OK, NO_POLY ou BAD_INDEX.
*******************************************************************************/

double LerCoefPolinomio (PtPolinomio ppol, unsigned int ppos);
/*******************************************************************************
 Devolve o valor armazenado no �ndice ppos do polin�mio referenciado por ppol.
 Valores de erro: OK, NO_POLY ou BAD_INDEX.
*******************************************************************************/

int PolinomioNulo (PtPolinomio ppol);
/*******************************************************************************
 Verifica se o polin�mio referenciado por ppol � um polin�mio nulo. Devolve 1
 em caso afirmativo e 0 em caso contr�rio. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

PtPolinomio  SomarPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Soma os dois polin�mios referenciados por ppol1 e ppol2. Devolve a refer�ncia
 do polin�mio soma ou NULL, caso n�o consiga fazer a adi��o.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

PtPolinomio  SubtrairPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Subtrai os dois polin�mios referenciados por ppol1 e ppol2. Devolve a refer�ncia
 do polin�mio diferen�a ou NULL, caso n�o consiga fazer a subtrac��o.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

PtPolinomio  MultiplicarPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Multiplica os dois polin�mios referenciados por ppol1 e ppol2. Devolve a
 refer�ncia do polin�mio produto ou NULL, caso n�o consiga fazer a multiplica��o.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

int  CompararPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Compara se os dois polin�mios referenciados por ppol1 e ppol2 s�o id�nticos.
 Devolve 1 em caso afirmativo e 0 em caso contr�rio. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

void ArmazenarPolinomioFicheiro (PtPolinomio ppol, char *pnomef);
/*******************************************************************************
 Armazena o polin�mio referenciado por ppol, caso ele exista, no ficheiro pnomef.
 O ficheiro tem na primeira linha o grau do polin�mio, seguido dos coeficientes,
 um por linha. Valores de erro: OK, NO_POLY ou NO_FILE.
*******************************************************************************/

PtPolinomio CriarPolinomioFicheiro (char *pnomef);
/*******************************************************************************
 Cria um polin�mio a partir de informacao lida do ficheiro pnomef. Devolve a
 refer�ncia do polin�mio criado ou NULL, caso n�o consiga criar o polin�mio.
 Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

#endif
