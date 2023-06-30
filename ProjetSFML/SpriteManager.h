#ifndef __SPRITEMANAGER_H__
#define __SPRITEMANAGER_H__




///////////////////////////////////////////////////////////
///------------------------Includes---------------------///
///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////
///------------------------Defines----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Enums-----------------------///
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
///------------------------Structures-------------------///
///////////////////////////////////////////////////////////
//struct DATADECORS
//{
//	int ID;
//	sfVector2f Pos;
//	sfVector2i Origin;
//};
//
//
//struct DECORSTRCUT
//{
//	sfSprite* SDecors[100];
//	int TotDecors;
//	int TotDonMap;
//	struct DATADECORS DecortList[100];
//	int CurrentSelection;
//};
struct ALLSPRITE
{
	int ID;
	sfSprite*sprite;


};

struct PLACEMENTSPRITE
{
	sfSprite* PlaceSprite[8];
};


struct SPRITESGENERAL
{
	struct ALLSPRITE AllSprite[100];

	struct PLACEMENTSPRITE SpritesPlacement;
	sfSprite* CaseSelect;
	sfSprite* GreenCase;
	char ScreenShot;
};



///////////////////////////////////////////////////////////
///------------------------PROTOTYPES-------------------///
///////////////////////////////////////////////////////////


#endif // !__SPRITEMANAGER_H__



