#ifndef GAMEDATA_H
#define GAMEDATA_H


// MY #INCLUDE ////////////////////




#include"Decors.h"
#include"placement.h"
#include"mapt3D.h"
struct DATADECORS
{
	int ID;
	sfVector2f Pos;
	sfVector2i Origin;
};


struct DECORSTRCUT
{
	sfSprite* SDecors[100];
	int TotDecors;
	int TotDonMap;
	struct DATADECORS DecortList[100];
	int CurrentSelection;
};


// STRUCT DEFINITION //////////


enum STATESELECT
{
	Biome,
	Type,
	Bloc,
	out

};

struct STATEFILE
{

	int BiomeSelect;
	int BlocSelect;
	int TypeSelect;

};

struct BLOCL
{
	char NameBloc[20];
	int nbr;
	sfSprite* Sprite;
	sfText* BlockText;

};
struct TYPEB
{
	char NameType[20];
	int totBloc;
	struct BLOCL *BlocList;
	sfText* TypeText;
};
struct BIOME
{
	char NameBiome[20];
	int totType;

	struct TYPEB *TypeList;
	sfText* BiomeText;
};

struct ALLSPRITE
{
	int ID;
	sfSprite*sprite;


};


struct SCREEN
{
	int Width;
	int Height;
};
struct PLACEMENTSPRITE
{
	sfSprite* PlaceSprite[8];
};
struct GAMEDATA
{

	//INIT SCREEN
	struct SCREEN Screen;
	sfRenderWindow* window;
	enum GAMESTATE GameState;
	//TIME
	float TimerDT;
	//ALL GAME SPRITE
	sfSprite* CaseBase;

	int Scroll;
	sfSprite* CasePATA;

	sfSprite* CaseSelect;



	enum STATESELECT StatSelect;
	struct STATEFILE StateFile;
	sfFont* Font1;
	int TotBiome;

	////MAP///

	int MapCellSizeW;
	int MapCellSizeH;
	int MapCellHeight;

	int currentSelectBloc;

	char selectOrBuild; //// 0 for Select Mode and 1 for Build Mode
	char ScreenShot;

	D_MapG MapG;
	sfVector3i CurrentSelect;
	int TotBlocByType;
	sfSprite* ShadowMask[2];
	sfVector2i MapSize;
	sfSprite* GreenCase;

	char ChangeLvl;
	sfVector2f Camera;
	sfVector2i tempCase;
	struct DECORSTRCUT DecorsD;
	int CurrentPLacement;
	struct PLACEMENTSPRITE SpritesPlacement;
	struct BIOME *BiomeList;
	struct ALLSPRITE AllSprite[100];
	int CurrentFolder;

};

#endif