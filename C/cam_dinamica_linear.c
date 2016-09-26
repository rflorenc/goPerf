/************* Interface da CAM Din�mica Linear Configurada ************/
/***** Nome: cam_dinamica_linear.h *****/

#ifndef _CAM_DINAMICA_LINEAR
#define _CAM_DINAMICA_LINEAR

/******** Inclus�o do Ficheiro de Interface do Elemento da CAM ********/

#include "elemento_cam.h"

/*************** Defini��o do Tipo Ponteiro para uma CAM ***************/

typedef struct cam *PtCAM;

/******************** Defini��o de C�digos de Erro ********************/

#define	OK         0  /* opera��o realizada com sucesso */
#define	NO_CAM     1  /* CAM inexistente */
#define	NO_MEM     2  /* mem�ria esgotada */
#define	NULL_PTR   3  /* ponteiro nulo */
#define	CAM_EMPTY  4  /* CAM vazia */
#define	NO_KEY     6  /* elemento com a chave indicada inexistente */
#define	NO_FUNC    7  /* fun��o de compara��o n�o comunicada */

/********************* Prot�tipos dos Subprogramas ********************/

PtCAM CAMCreate (TPFC pfcomp);
/* Cria uma CAM e armazena a fun��o de compara��o dos elementos. Devolve a refer�ncia da CAM criada ou NULL em caso de inexist�ncia de mem�ria ou da fun��o de compara��o. */

int CAMDestroy (PtCAM *pcam);
/* Destr�i a CAM referenciada por pcam e coloca a refer�ncia a NULL. Valores de retorno: OK ou NO_CAM. */

int CAMPut (PtCAM pcam, TELEM *pelem);
/* Coloca o elemento pelem, na CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, NO_FUNC, NULL_PTR ou NO_MEM. */

int CAMGet (PtCAM pcam, TELEM *pelem);
/* Retira o elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

int CAMReadFirst (PtCAM pcam, TELEM *pelem);
/* L� o conte�do do primeiro elemento com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

int CAMReadNext (PtCAM pcam, TELEM *pelem);
/* L� o conte�do do elemento seguinte com a chave indicada, da CAM referenciada por pcam. Valores de retorno: OK, NO_CAM, CAM_EMPTY, NO_FUNC, NULL_PTR ou NO_KEY. */

#endif
