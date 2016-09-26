/**************** Interface da CAM Estática Configurada ****************/
/***** Nome: cam_estatica.h *****/

#ifndef _CAM_ESTATICA
#define _CAM_ESTATICA

/******************** Definição da dimensão da CAM ********************/

#define MAX_ELEMENTOS 100

/******** Inclusão do Ficheiro de Interface do Elemento da CAM ********/

#include "elemento_cam.h"

/*************** Definição do Tipo Ponteiro para uma CAM **************/

typedef struct cam *PtCAM;

/******************** Definição de Códigos de Erro ********************/

#define	OK         0  /* operação realizada com sucesso */
#define	NO_CAM     1  /* CAM inexistente */
#define	NO_MEM     2  /* memória esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	CAM_EMPTY  4  /* CAM vazia */
#define	CAM_FULL   5  /* CAM cheia */
#define	NO_KEY     6  /* elemento com a chave indicada inexistente */
#define	NO_FUNC    7  /* função de comparação não comunicada */

/********************* Protótipos dos Subprogramas ********************/

PtCAM CAMCreate (TPFC pfcomp);
/* Cria uma CAM e armazena a função de comparação dos elementos. Devolve a referência da CAM criada ou NULL em caso de inexistência de memória ou da função de comparação. */

int CAMDestroy (PtCAM *pcam);
/* Destrói a CAM referenciada por pcam e coloca a referência a NULL. Valores de retorno: OK ou NO_CAM. */

int CAMPut (PtCAM pcam, TELEM *pelem);
/* Coloca o elemento pelem, na CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_FULL, NO_FUNC, NULL_PTR ou NO_MEM. */

int CAMGet (PtCAM pcam, TELEM *pelem);
/* Retira o elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

int CAMReadFirst (PtCAM pcam, TELEM *pelem);
/* Lê o conteúdo do primeiro elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

int CAMReadNext (PtCAM pcam, TELEM *pelem);
/* Lê o conteúdo do elemento seguinte com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

#endif
