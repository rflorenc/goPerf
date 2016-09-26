/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados POLINOMIO (polinomio.h).
 O polinómio é composto pelo seu grau e pelos seus coeficientes reais, sendo
 que um polinómio com grau n tem n+1 coeficientes. A implementação providencia
 um construtor para criar um polinómio nulo com o grau pretendido. É da
 responsabilidade da aplicação, invocar o destrutor, para libertar a memória
 atribuída ao objecto. O módulo providencia um controlo centralizado de erro,
 disponibilizando uma função para obter o último erro ocorrido, uma função para
 obter uma mensagem de erro elucidativa e uma função para limpar o erro.
 Providencia também operações para armazenar e recuperar polinómios para ficheiros.
 


*******************************************************************************/

#ifndef _POLINOMIO
#define _POLINOMIO

/**************** Definição do Tipo Ponteiro para um POLINOMIO ****************/

typedef struct polinomio *PtPolinomio;

/************************ Definição de Códigos de Erro ************************/


#define  OK         0  /* operação realizada com sucesso */
#define  NO_MEM     1  /* memória esgotada */
#define  NO_POLY    2  /* o(s) polinómio(s) não existe(m) */
#define  NO_FILE    3  /* o ficheiro não existe */
#define  BAD_SIZE   4  /* grau do polinómio errada */
#define  BAD_INDEX  5  /* coeficiente inexistente no polinómio */

/*************************** Protótipos das Funções ***************************/

void InicializarErroPolinomio (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroPolinomio (void);
/*******************************************************************************
 Função que devolve o código do último erro ocorrido.
*******************************************************************************/

char *MensagemErroPolinomio (void);
/*******************************************************************************
 Função que devolve uma mensagem esclarecedora da causa do último erro ocorrido.
*******************************************************************************/

PtPolinomio CriarPolinomioNulo (unsigned int pgrau);
/*******************************************************************************
 Cria um polinómio nulo, de coeficientes reais, com o grau indicado por pgrau.
 Devolve a referência do polinómio criado ou NULL, caso não consiga criar o
 polinómio, por falta de memória. Valores de erro: OK ou NO_MEM.
*******************************************************************************/

void ApagarPolinomio (PtPolinomio *ppol);
/*******************************************************************************
 Destrói o polinómio referenciado por ppol, caso ele exista, e coloca a sua
 referência a NULL. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

PtPolinomio CopiarPolinomio (PtPolinomio ppol);
/*******************************************************************************
 Copia do polinómio referenciado por ppol, caso ele exista. Devolve a referência
 do polinómio cópia ou NULL, caso não consiga fazer a cópia.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

int GrauPolinomio (PtPolinomio ppol);
/*******************************************************************************
 Devolve o grau do polinómio referenciado por ppol. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

void EscreverCoefPolinomio (PtPolinomio ppol, unsigned int ppos, double pval);
/*******************************************************************************
 Armazena pval no índice ppos, do polinómio referenciado por ppol.
 Valores de erro: OK, NO_POLY ou BAD_INDEX.
*******************************************************************************/

double LerCoefPolinomio (PtPolinomio ppol, unsigned int ppos);
/*******************************************************************************
 Devolve o valor armazenado no índice ppos do polinómio referenciado por ppol.
 Valores de erro: OK, NO_POLY ou BAD_INDEX.
*******************************************************************************/

int PolinomioNulo (PtPolinomio ppol);
/*******************************************************************************
 Verifica se o polinómio referenciado por ppol é um polinómio nulo. Devolve 1
 em caso afirmativo e 0 em caso contrário. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

PtPolinomio  SomarPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Soma os dois polinómios referenciados por ppol1 e ppol2. Devolve a referência
 do polinómio soma ou NULL, caso não consiga fazer a adição.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

PtPolinomio  SubtrairPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Subtrai os dois polinómios referenciados por ppol1 e ppol2. Devolve a referência
 do polinómio diferença ou NULL, caso não consiga fazer a subtracção.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

PtPolinomio  MultiplicarPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Multiplica os dois polinómios referenciados por ppol1 e ppol2. Devolve a
 referência do polinómio produto ou NULL, caso não consiga fazer a multiplicação.
 Valores de erro: OK, NO_POLY ou NO_MEM.
*******************************************************************************/

int  CompararPolinomios (PtPolinomio ppol1, PtPolinomio ppol2);
/*******************************************************************************
 Compara se os dois polinómios referenciados por ppol1 e ppol2 são idênticos.
 Devolve 1 em caso afirmativo e 0 em caso contrário. Valores de erro: OK ou NO_POLY.
*******************************************************************************/

void ArmazenarPolinomioFicheiro (PtPolinomio ppol, char *pnomef);
/*******************************************************************************
 Armazena o polinómio referenciado por ppol, caso ele exista, no ficheiro pnomef.
 O ficheiro tem na primeira linha o grau do polinómio, seguido dos coeficientes,
 um por linha. Valores de erro: OK, NO_POLY ou NO_FILE.
*******************************************************************************/

PtPolinomio CriarPolinomioFicheiro (char *pnomef);
/*******************************************************************************
 Cria um polinómio a partir de informacao lida do ficheiro pnomef. Devolve a
 referência do polinómio criado ou NULL, caso não consiga criar o polinómio.
 Valores de erro: OK, NO_FILE ou NO_MEM.
*******************************************************************************/

#endif
