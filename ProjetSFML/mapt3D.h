#ifndef __MAPT3D_H__
#define __MAPT3D_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////
#include <SFML/Graphics.h>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
//#include"Utils.h"


///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////

#define  TOTVECTORCASE 5
///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////
enum STATECASE
{
	NonValideCase,
	ValideCase
};
typedef enum STATECASE E_StateCase;



enum PLACEMENTSTATE
{
	NullPlace,
	Perso1,
	Perso2,
	Perso3,
	Perso4,
	EnemyTypeA,
	enemyTypeB,
	enemyTypeC,
	enemyTypeD
};
typedef enum PLACEMENTSTATE E_PlacementState;



enum VALIDCASE
{
	NullCase,
	InvalidCase,
	ValidCase
};
//////////////////////////////
//STATUS OF LOADING MAP AFTER SELECT IN WORLD
//////////////////////////////
//-->Unload, "map is Unload all Data is Free"
//-->Loading 
//-->Load, "map Loading is end and DATA is Give to MapCombat"

/////////////////////////////
typedef enum VALIDCASE D_ValidCase;
///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////

struct SFVECTOR3IDATA
{
	int x;
	int y;
	int z;
};
typedef struct SFVECTOR3IDATA sfVector3i;




struct DATACASE
{
	int AxeZ;
	sfVector2f VectorPos[5];
	int ID;
	int IDDecorts;
	E_StateCase StateCase;
	E_PlacementState PlacementState;
	int IDShadow;
	int OpacityShadow;
};
/////////////////////////////////////
//MapT3D Data
//////////////////////////////////////
//->int AxeZ;
//->sfVector2f CasePos;
//->sfVector2f VectorPos[5];
//->sfVector2f Normal[4];
//->sfVector2f Center[4];
//->int ID;
//->int IDDecorts;
//->DATACASE*Next;
//->enum STATECASE StateCase;
//->enum PLACEMENTSTATE PlacementState;
//->int IDShadow;
//->int OpacityShadow;
///////////////////////////////////////////
typedef struct DATACASE D_DataCase;



struct MAP
{
	sfVector3i Size;
	D_DataCase ***DataCase;
	sfVector2i CellSize;
	int CurrentLVlBloc;

};


typedef struct MAP D_MapG;




///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////
void INITMap(D_MapG * Map);
void Create_Empty_MapCombat_From_Data_Lvl(D_MapG* Map);
void VectorCase(D_MapG* Map, sfVector2f Camera);
void CurrentCaseSelect(D_MapG* Map, sfVector2i Mouse, sfVector3i * caseSelect);
void MapDisplay(D_MapG* Map, sfVector3i CurrentSelect, struct GAMEDATA* GameData, sfRenderWindow* window);
#endif // !__MAPT3D_H__



