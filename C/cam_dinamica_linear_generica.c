/************** Interface da CAM Dinâmica Linear Genérica **************/
/***** Nome: cam_dinamica_linear_generica.h *****/

#ifndef _CAM_DINAMICA_LINEAR_GENERICA
#define _CAM_DINAMICA_LINEAR_GENERICA

/*************** Definição do Tipo Ponteiro para uma CAM ***************/

typedef struct cam *PtCAM;

/******************** Definição de Códigos de Erro ********************/

#define	OK         0  /* operação realizada com sucesso */
#define	NO_CAM     1  /* CAM inexistente */
#define	NO_MEM     2  /* memória esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	CAM_EMPTY  4  /* CAM vazia */
#define	NO_KEY     6  /* elemento com a chave indicada inexistente */

/********************* Protótipos dos Subprogramas ********************/

 
PtCAM CAMCreate (unsigned int pesize, unsigned int pksize);
/* Cria uma CAM e armazena a função de comparação dos elementos. Devolve a referência da CAM criada ou NULL em caso de inexistência de memória ou se pesize for nulo ou se pksize for nulo. */

int CAMDestroy (PtCAM *pcam);
/* Destrói a CAM referenciada por pcam e coloca a referência a NULL. Valores de retorno: OK ou NO_CAM. */

int CAMPut (PtCAM pcam, void *pelem);
/* Coloca o elemento pelem, na CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, NULL_PTR ou NO_MEM. */

int CAMGet (PtCAM pcam, void *pelem);
/* Retira o elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NULL_PTR ou NO_KEY. */

int CAMReadFirst (PtCAM pcam, void *pelem);
/* Lê o conteúdo do primeiro elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NULL_PTR ou NO_KEY. */

int CAMReadNext (PtCAM pcam, void *pelem);
/* Lê o conteúdo do elemento seguinte com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NULL_PTR ou NO_KEY. */

#endif
