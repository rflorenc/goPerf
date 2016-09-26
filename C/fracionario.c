/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados FRACIONARIO (fracionario.h).
 O n�mero fracion�rio � composto pelo numerador e pelo denominador. No caso de
 um fracion�rio negativo, o sinal deve estar associado ao numerador, sendo que o
 denominador deve ser sempre positivo. A implementa��o providencia um construtor
 para criar e inicializar um fracion�rio. � da responsabilidade da aplica��o,
 invocar o destrutor, para libertar a mem�ria atribu�da ao objecto. O m�dulo
 providencia um controlo centralizado de erro, disponibilizando uma fun��o para
 obter o �ltimo erro ocorrido, uma fun��o para obter uma mensagem de erro
 elucidativa e uma fun��o para limpar o erro.


*******************************************************************************/

#ifndef _FRACIONARIO
#define _FRACIONARIO

/*************** Defini��o do Tipo Ponteiro para um Fracion�rio ***************/

typedef struct fracionario *PtFracionario;

/************************ Defini��o de C�digos de Erro ************************/

#define	OK		0	/* opera��o realizada com sucesso */
#define	NO_MEM		1	/* mem�ria esgotada */
#define	NO_FRAC		2	/* o(s) fracion�rio(s) n�o existe(m) */

/************************* Prot�tipos dos Subprogramas ************************/

void InicializarErroFracionario (void);
/*******************************************************************************
 Inicializa��o do erro.
*******************************************************************************/

int ErroFracionario (void);
/*******************************************************************************
 Indica��o do c�digo de erro ocorrido na �ltima opera��o.
*******************************************************************************/

char *MensagemErroFracionario (void);
/*******************************************************************************
 Obten��o da mensagem esclarecedora da causa do erro ocorrido.
*******************************************************************************/

PtFracionario InicializarFracionario (int pnum, int pden);
/*******************************************************************************
 Cria��o e inicializa��o de um fracion�rio na forma Numerador/Denominador. O
 denominador n�o pode ser nulo e o sinal negativo deve ser associado ao numerador.
 Valores de erro: NO_MEM ou NO_FRAC.
*******************************************************************************/

PtFracionario CopiarFracionario (PtFracionario pnf);
/*******************************************************************************
 C�pia de um fracion�rio. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario SomarFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Adi��o de dois fracion�rios. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario SubtrairFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Subtrac��o de dois fracion�rios. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario MultiplicarFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Multiplica��o de dois fracion�rios. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario DividirFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Divis�o de dois fracion�rios. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

int Numerador (PtFracionario pnf);
/*******************************************************************************
 Numerador do fracion�rio. Valores de erro: NO_FRAC.
*******************************************************************************/

int Denominador (PtFracionario pnf);
/*******************************************************************************
 Denominador do fracion�rio. Valores de erro: NO_FRAC.
*******************************************************************************/

int CompararFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Compara��o de dois fracion�rios. Devolve 1 em caso afirmativo e 0 em caso
 contr�rio. Valores de erro: NO_FRAC.
*******************************************************************************/

void ApagarFracionario (PtFracionario *pnf);
/*******************************************************************************
 Destrui��o de um fracion�rio. Valores de erro: NO_FRAC.
*******************************************************************************/

#endif
