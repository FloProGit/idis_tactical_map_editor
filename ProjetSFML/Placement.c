#include"placement.h"


void loadSpritePlacement(struct GAMEDATA* GameData)
{
	GameData->SpritesPlacement.PlaceSprite[0] = LoadSprite("PERSOP/1.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[1] = LoadSprite("PERSOP/2.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[2] = LoadSprite("PERSOP/3.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[3] = LoadSprite("PERSOP/4.png", 0, 0, 0);

	GameData->SpritesPlacement.PlaceSprite[4] = LoadSprite("AIP/A.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[5] = LoadSprite("AIP/B.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[6] = LoadSprite("AIP/C.png", 0, 0, 0);
	GameData->SpritesPlacement.PlaceSprite[7] = LoadSprite("AIP/D.png", 0, 0, 0);




	GameData->ShadowMask[0] = LoadSprite("Ombre/1.png",0, 0, 0);


	GameData->GreenCase = LoadSprite("greenCase.png", 0, 0, 0);
}