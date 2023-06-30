#include "DisplayState.h"
#include "stdio.h"



void DISPLAY(struct GAMEDATA* _GameData)
{

	sfRenderWindow_clear(_GameData->window, sfBlack);



	
	MapDisplay(&_GameData->MapG, _GameData->CurrentSelect, _GameData, _GameData->window);
	SelectionStateDisplay(_GameData);
	//DisplayDecors(_GameData->selectOrBuild, &_GameData->DecorsD, _GameData->Camera, _GameData->window);

	//printf(" X = %f", _GameData->MapG.DataCase[_GameData->CurrentSelect.y][_GameData->CurrentSelect.x][_GameData->CurrentSelect.z].VectorPos[0].x);

	sfVector2i mouse = { sfMouse_getPositionRenderWindow(_GameData->window).x,sfMouse_getPositionRenderWindow(_GameData->window).y };

	
	//printf("TATATA =  %d", _GameData->GeneralSprite.DecorsD.TotDecors);




	if (_GameData->selectOrBuild == 2)
	{
		blitSprite(_GameData->DecorsD.SDecors[_GameData->DecorsD.CurrentSelection],
			mouse.x,
			mouse.y,
			/*_GameData->MapG.DataCase[_GameData->CurrentSelect.y][_GameData->CurrentSelect.x][_GameData->CurrentSelect.z].VectorPos[0].x
			, _GameData->MapG.DataCase[_GameData->CurrentSelect.y][_GameData->CurrentSelect.x][_GameData->CurrentSelect.z].VectorPos[0].y,*/
			0, _GameData->window);
	}


	if (_GameData->selectOrBuild == 3)
	{
		if (_GameData->CurrentPLacement != 0)
		{

		blitSprite(_GameData->SpritesPlacement.PlaceSprite[_GameData->CurrentPLacement-1],
			_GameData->MapG.DataCase[_GameData->CurrentSelect.y][_GameData->CurrentSelect.x][_GameData->CurrentSelect.z].VectorPos[0].x - _GameData->MapG.CellSize.x / 2
			, _GameData->MapG.DataCase[_GameData->CurrentSelect.y][_GameData->CurrentSelect.x][_GameData->CurrentSelect.z].VectorPos[0].y,
			0, _GameData->window);
		}

	}
	sfRenderWindow_display(_GameData->window);
}