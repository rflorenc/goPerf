/********************* Interface do Módulo de Erro *********************/
/***** Nome: erro.h *****/

#ifndef _ERRO
#define _ERRO

/******************** Definição de Códigos de Erro ********************/

#define	OK      0  /* operação realizada com sucesso */
#define	NO_MEM  1  /* memória esgotada */

/* restantes códigos de erro da aplicação */

/********************* Protótipos dos Subprogramas ********************/

void ClearError (void);
/* Inicialização do erro. */

void SetError (unsigned int perro);
/* Armazenamento do erro ocorrido indicado por perro. */

int GetError (void);
/* Obtenção do erro ocorrido. */

char *GetErrorMessage (void);
/* Obtenção da mensagem esclarecedora da causa do erro ocorrido. */

#endif
