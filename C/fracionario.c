/*******************************************************************************

 Ficheiro de interface do Tipo Abstracto de Dados FRACIONARIO (fracionario.h).
 O número fracionário é composto pelo numerador e pelo denominador. No caso de
 um fracionário negativo, o sinal deve estar associado ao numerador, sendo que o
 denominador deve ser sempre positivo. A implementação providencia um construtor
 para criar e inicializar um fracionário. É da responsabilidade da aplicação,
 invocar o destrutor, para libertar a memória atribuída ao objecto. O módulo
 providencia um controlo centralizado de erro, disponibilizando uma função para
 obter o último erro ocorrido, uma função para obter uma mensagem de erro
 elucidativa e uma função para limpar o erro.


*******************************************************************************/

#ifndef _FRACIONARIO
#define _FRACIONARIO

/*************** Definição do Tipo Ponteiro para um Fracionário ***************/

typedef struct fracionario *PtFracionario;

/************************ Definição de Códigos de Erro ************************/

#define	OK		0	/* operação realizada com sucesso */
#define	NO_MEM		1	/* memória esgotada */
#define	NO_FRAC		2	/* o(s) fracionário(s) não existe(m) */

/************************* Protótipos dos Subprogramas ************************/

void InicializarErroFracionario (void);
/*******************************************************************************
 Inicialização do erro.
*******************************************************************************/

int ErroFracionario (void);
/*******************************************************************************
 Indicação do código de erro ocorrido na última operação.
*******************************************************************************/

char *MensagemErroFracionario (void);
/*******************************************************************************
 Obtenção da mensagem esclarecedora da causa do erro ocorrido.
*******************************************************************************/

PtFracionario InicializarFracionario (int pnum, int pden);
/*******************************************************************************
 Criação e inicialização de um fracionário na forma Numerador/Denominador. O
 denominador não pode ser nulo e o sinal negativo deve ser associado ao numerador.
 Valores de erro: NO_MEM ou NO_FRAC.
*******************************************************************************/

PtFracionario CopiarFracionario (PtFracionario pnf);
/*******************************************************************************
 Cópia de um fracionário. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario SomarFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Adição de dois fracionários. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario SubtrairFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Subtracção de dois fracionários. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario MultiplicarFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Multiplicação de dois fracionários. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

PtFracionario DividirFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Divisão de dois fracionários. Valores de erro: NO_FRAC ou NO_MEM.
*******************************************************************************/

int Numerador (PtFracionario pnf);
/*******************************************************************************
 Numerador do fracionário. Valores de erro: NO_FRAC.
*******************************************************************************/

int Denominador (PtFracionario pnf);
/*******************************************************************************
 Denominador do fracionário. Valores de erro: NO_FRAC.
*******************************************************************************/

int CompararFracionarios (PtFracionario pnf1, PtFracionario pnf2);
/*******************************************************************************
 Comparação de dois fracionários. Devolve 1 em caso afirmativo e 0 em caso
 contrário. Valores de erro: NO_FRAC.
*******************************************************************************/

void ApagarFracionario (PtFracionario *pnf);
/*******************************************************************************
 Destruição de um fracionário. Valores de erro: NO_FRAC.
*******************************************************************************/

#endif
