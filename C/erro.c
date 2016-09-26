/********************* Interface do M�dulo de Erro *********************/
/***** Nome: erro.h *****/

#ifndef _ERRO
#define _ERRO

/******************** Defini��o de C�digos de Erro ********************/

#define	OK      0  /* opera��o realizada com sucesso */
#define	NO_MEM  1  /* mem�ria esgotada */

/* restantes c�digos de erro da aplica��o */

/********************* Prot�tipos dos Subprogramas ********************/

void ClearError (void);
/* Inicializa��o do erro. */

void SetError (unsigned int perro);
/* Armazenamento do erro ocorrido indicado por perro. */

int GetError (void);
/* Obten��o do erro ocorrido. */

char *GetErrorMessage (void);
/* Obten��o da mensagem esclarecedora da causa do erro ocorrido. */

#endif
