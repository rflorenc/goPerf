/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados COMPLEXO (complexo.h).
 O número complexo é composto pela parte real e pela parte imaginária.
 A implementação providencia um construtor para criar e inicializar um complexo.
 É da responsabilidade da aplicação, invocar o destrutor, para libertar a
 memória atribuída ao objecto. O módulo providencia um controlo centralizado de
 erro, disponibilizando uma função para obter o último erro ocorrido, uma função
 para obter uma mensagem de erro elucidativa e uma função para limpar o erro.


*******************************************************************************/

#ifndef _COMPLEXO
#define _COMPLEXO

/************* Definição do Tipo Ponteiro para um Número Complexo *************/

typedef struct complexo *PtComplexo;

/************************ Definição de Códigos de Erro ************************/

#define  OK          0  /* operação realizada com sucesso */
#define  NO_COMPLEX  1  /* complexo inexistente */
#define  NO_MEM      2  /* memória esgotada */
#define  ZERO_DIV    3  /* divisão por zero */

/************************* Protótipos dos Subprogramas ************************/

void InicializarErroComplexo (void);
/* Inicialização do erro. */

int ErroComplexo (void);
/* Indicação do código de erro ocorrido na última operação. */

char *MensagemErroComplexo (void);
/* Obtenção da mensagem esclarecedora da causa do erro ocorrido. */

PtComplexo InicializarComplexo (double preal, double pimag);
/* Criação e inicialização de um número complexo na forma R+jI. Valores de erro: NO_MEM. */

PtComplexo CopiarComplexo (PtComplexo pnc);
/* Cópia de um número complexo. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo SomarComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Adição de dois números complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo SubtrairComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Subtracção de dois números complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo MultiplicarComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Multiplicação de dois números complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo DividirComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Divisão de dois números complexos. Valores de erro: NO_COMPLEX, ZERO_DIV ou NO_MEM. */

int ComplexoNulo (PtComplexo pnc);
/* Verificar se o número complexo é o complexo nulo (0+j0). Devolve 1 em caso
   afirmativo e 0 em caso contrário. Valores de erro: NO_COMPLEX. */

double ParteReal (PtComplexo pnc);
/* Parte real do número complexo. Valores de erro: NO_COMPLEX. */

double ParteImaginaria (PtComplexo pnc);
/* Parte imaginária do número complexo. Valores de erro: NO_COMPLEX. */

void ApagarComplexo (PtComplexo *pnc);
/* Destruição de um número complexo. Valores de erro: NO_COMPLEX. */

PtComplexo ConjugarComplexo (PtComplexo pnc);
/* Conjugado de um número complexo. Valores de erro: NO_COMPLEX ou NO_MEM. */

#endif
