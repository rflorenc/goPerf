/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados COMPLEXO (complexo.h).
 O n�mero complexo � composto pela parte real e pela parte imagin�ria.
 A implementa��o providencia um construtor para criar e inicializar um complexo.
 � da responsabilidade da aplica��o, invocar o destrutor, para libertar a
 mem�ria atribu�da ao objecto. O m�dulo providencia um controlo centralizado de
 erro, disponibilizando uma fun��o para obter o �ltimo erro ocorrido, uma fun��o
 para obter uma mensagem de erro elucidativa e uma fun��o para limpar o erro.


*******************************************************************************/

#ifndef _COMPLEXO
#define _COMPLEXO

/************* Defini��o do Tipo Ponteiro para um N�mero Complexo *************/

typedef struct complexo *PtComplexo;

/************************ Defini��o de C�digos de Erro ************************/

#define  OK          0  /* opera��o realizada com sucesso */
#define  NO_COMPLEX  1  /* complexo inexistente */
#define  NO_MEM      2  /* mem�ria esgotada */
#define  ZERO_DIV    3  /* divis�o por zero */

/************************* Prot�tipos dos Subprogramas ************************/

void InicializarErroComplexo (void);
/* Inicializa��o do erro. */

int ErroComplexo (void);
/* Indica��o do c�digo de erro ocorrido na �ltima opera��o. */

char *MensagemErroComplexo (void);
/* Obten��o da mensagem esclarecedora da causa do erro ocorrido. */

PtComplexo InicializarComplexo (double preal, double pimag);
/* Cria��o e inicializa��o de um n�mero complexo na forma R+jI. Valores de erro: NO_MEM. */

PtComplexo CopiarComplexo (PtComplexo pnc);
/* C�pia de um n�mero complexo. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo SomarComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Adi��o de dois n�meros complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo SubtrairComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Subtrac��o de dois n�meros complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo MultiplicarComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Multiplica��o de dois n�meros complexos. Valores de erro: NO_COMPLEX ou NO_MEM. */

PtComplexo DividirComplexos (PtComplexo pnc1, PtComplexo pnc2);
/* Divis�o de dois n�meros complexos. Valores de erro: NO_COMPLEX, ZERO_DIV ou NO_MEM. */

int ComplexoNulo (PtComplexo pnc);
/* Verificar se o n�mero complexo � o complexo nulo (0+j0). Devolve 1 em caso
   afirmativo e 0 em caso contr�rio. Valores de erro: NO_COMPLEX. */

double ParteReal (PtComplexo pnc);
/* Parte real do n�mero complexo. Valores de erro: NO_COMPLEX. */

double ParteImaginaria (PtComplexo pnc);
/* Parte imagin�ria do n�mero complexo. Valores de erro: NO_COMPLEX. */

void ApagarComplexo (PtComplexo *pnc);
/* Destrui��o de um n�mero complexo. Valores de erro: NO_COMPLEX. */

PtComplexo ConjugarComplexo (PtComplexo pnc);
/* Conjugado de um n�mero complexo. Valores de erro: NO_COMPLEX ou NO_MEM. */

#endif
