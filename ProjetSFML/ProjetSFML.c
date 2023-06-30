
#include "GameData.h"
#include "DisplayState.h"
sfClock* ClockTimer;

int _tmain(int argc, _TCHAR* argv[])
{

	struct GAMEDATA GameData;
	ClockTimer = sfClock_create();

	loadSpritePlacement(&GameData);
	GameData.DecorsD.CurrentSelection = 0;
	GameData.DecorsD.TotDonMap = 0;
	GameData.ChangeLvl = 0;
	LoadSpriteDecor(&GameData.DecorsD);
	

	SelectionStateInit(&GameData);
	PutDataInMap(&GameData);
	INITMAPED(&GameData);
	GameData.CurrentPLacement = 0;
	GameData.CurrentFolder = 0;
	GameData.Screen.Height = 768;
	GameData.Screen.Width = 1024;
	GameData.TimerDT = 0;
	sfVideoMode mode = { GameData.Screen.Width, GameData.Screen.Height, 32 };
	GameData.Font1 = sfFont_createFromFile("Font.ttf");
	GameData.window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
	//LectureDossier();
	while (sfRenderWindow_isOpen(GameData.window))
	{
		//// IS A CLOCK UPDATE
		GameData.TimerDT = sfTime_asSeconds(sfClock_restart(ClockTimer));
		//UPDATE GAMEDATA
		
		UpdateMap(&GameData);


	
		DISPLAY(&GameData);
	}
	return 0;
}

