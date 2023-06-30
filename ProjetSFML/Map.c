#include"Map.h"
#include "direct.h"



void INITMAPED(struct GAMEDATA * GameData)
{

	INITMap(&GameData->MapG);
	Create_Empty_MapCombat_From_Data_Lvl(&GameData->MapG);
	VectorCase(&GameData->MapG, GameData->Camera);
	GameData->CurrentSelect.x = 0;
	GameData->CurrentSelect.y = 0;
	GameData->CurrentSelect.z = 0;
	GameData->CaseSelect = LoadSprite("caseSelect.png", 0, 0, 0);
}


void lectureSaveMap3D(struct GAMEDATA * GameData)
{

	for (int i = 0; i < GameData->MapG.Size.y; i++)
	{

		for (int j = 0; j < GameData->MapG.Size.x; j++)
		{
			free(GameData->MapG.DataCase[i][j]);
		}
		free(GameData->MapG.DataCase[i]);
	}
	free(GameData->MapG.DataCase);




	


	FILE* file = fopen("SAVE MAP/Map1/map.txt", "r");
	if (file == NULL)
	{
		printf("error");
		exit(0);
	}


	fscanf(file, "%d", &GameData->MapG.Size.y);


	fscanf(file, "%d", &GameData->MapG.Size.x);
	fscanf(file, "%d", &GameData->MapG.Size.z);

	Create_Empty_MapCombat_From_Data_Lvl(&GameData->MapG);


	for (int i = 0; i < GameData->MapG.Size.y; i++)
	{
		for (int j = 0; j < GameData->MapG.Size.x; j++)
		{

			for (int k = 0; k < GameData->MapG.Size.z; k++)
			{




				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].ID);
				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].StateCase);
				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].IDShadow);
				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].OpacityShadow);
				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].IDDecorts);
				fscanf(file, "%d ", &GameData->MapG.DataCase[i][j][k].PlacementState);






			}
		}
	}
	fclose(file);


}


void ConversionMap3D(struct GAMEDATA * GameData)
{
	/////////////////////////Save GENERAL
	
	int count = 0;
	int done = 1;
	char nbro[4];

	while (done)
	{
		_chdir("SAVE MAP");
		count++;

		char PathFolder[100] = { "Map" };
		char nbri[4];

		printf("COUNT = %d", count);

		sprintf(nbri, "%d", count);
		strcat(PathFolder, nbri);

		if (_chdir(PathFolder))
		{

			done = 0;

			//printf(" CREATION DE FICHIER n = %s", PathFolderFinal);


		}


		_chdir("..");

	}
	printf("TESST COUNT =%d", count);
	char PathFolderFinal[100] = { "SAVE MAP/Map" };
	GameData->CurrentFolder = count;
	sprintf(nbro, "%d", GameData->CurrentFolder);
	strcat(PathFolderFinal, nbro);
	_mkdir(PathFolderFinal);

	strcat(PathFolderFinal, "/Map.txt");



	FILE* file = fopen(PathFolderFinal, "w");
	if (file == NULL)
	{
		printf("error");
		exit(0);
	}



	fprintf(file, "%d ", GameData->MapG.Size.y);
	fprintf(file, "%d ", GameData->MapG.Size.x);
	fprintf(file, "%d ", GameData->MapG.Size.z);





	for (int i = 0; i <  GameData->MapG.Size.y; i++)
	{
		for (int j = 0; j < GameData->MapG.Size.x; j++)
		{

			for (int k = 0; k < GameData->MapG.Size.z; k++)
			{
				



				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].ID);
				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].StateCase);
				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].IDShadow);
				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].OpacityShadow);
				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].IDDecorts);
				fprintf(file, "%d ", GameData->MapG.DataCase[i][j][k].PlacementState);






			}
		}
	}
	fclose(file);

	printf("FAIT");

}


void PutDataInMap(struct GAMEDATA* GameData)
{


	GameData->ScreenShot = 1;


	GameData->MapCellSizeW = 128;
	GameData->MapCellSizeH = 64;
	GameData->MapCellHeight = 32;


	GameData->tempCase.x = 0;
	GameData->tempCase.y = 0;


	GameData->Camera.x = 200;
	GameData->Camera.y = 0;




	GameData->selectOrBuild = 0;

	GameData->CasePATA = LoadSprite("casePATA.png", 0, 0, 0);


}








void UpdateMap(struct GAMEDATA* GameData)
{
	VectorCase(&GameData->MapG, GameData->Camera);




	if (sfKeyboard_isKeyPressed(sfKeyLControl))
	{
		GameData->ChangeLvl = 1;


	}
	else
	{
		GameData->ChangeLvl = 0;
	}


	/////////////////////////////////////////////////////////////////////////////
	//---------------------------------INPUT REEL------------------------------//
	/////////////////////////////////////////////////////////////////////////////

	/////////////////////////
	////IN BUILD BLOCK 0////
	////////////////////////



	//////////////
	//          //
	//          //
	//          //
	//          //
	//          //
	//          //
	//////////////








	/////////////////////////
	////IN BUILD BLOCK 1////
	////////////////////////



	  //
	/////
	   //
	   //
	   //
	   //
	   //
	///////


	if (GameData->selectOrBuild == 1)////IN BUILD BLOCK 1
	{

		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].ID = GameData->currentSelectBloc;


		}
		if (sfMouse_isButtonPressed(sfMouseRight))
		{

			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].ID = 0;

		}
	}



	/////////////////////////
	////IN decors BLOCK 2////
	////////////////////////



	  ////
	///////
	//   //
		//
	   //
	  //
	 //
	///////






	if (GameData->selectOrBuild == 2)////IN DECORTS 2
	{

		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].IDDecorts = GameData->DecorsD.CurrentSelection;


		}
		if (sfMouse_isButtonPressed(sfMouseRight))
		{

			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].IDDecorts = 999;

		}
	}





	////////////////////////////
	////IN Placement BLOCK 3////
	////////////////////////////



	//////////
			//
			//
	//////////		
			//
			//
	//////////


	if (GameData->selectOrBuild == 3)
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{

			printf("test = %d", GameData->CurrentPLacement);
			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].PlacementState = GameData->CurrentPLacement;


		}
		if (sfMouse_isButtonPressed(sfMouseRight))
		{

			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].PlacementState = 0;

		}
	}



	/////////////////////////////
	////IN ValideCase BLOCK 4////
	/////////////////////////////



	//
	//
	//  //
	//  //
	//////////
		//
		//


	if (GameData->selectOrBuild == 4)
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{

			printf("test = %d", GameData->CurrentPLacement);
			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].StateCase = ValideCase;


		}
		if (sfMouse_isButtonPressed(sfMouseRight))
		{

			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].StateCase = NonValideCase;

		}
	}



	/////////////////////////////
	////IN Ombre BLOCK 5////
	/////////////////////////////




	/////////////
	//
	//
	//
	///////////
			  //
			  //
			  //
	///////////

	if (GameData->selectOrBuild == 5)
	{
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{

			printf("test = %d", GameData->CurrentPLacement);
			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].IDShadow = 0;


		}
		if (sfMouse_isButtonPressed(sfMouseRight))
		{

			GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].IDShadow = 999;

		}
	}





	
	sfEvent event;
	while (sfRenderWindow_pollEvent(GameData->window, &event))
	{
		if (event.type == sfEvtClosed) exit(0); //Fermeture en appuyant sur le bouton Fermer
	/////////////////////////////////////////////////////////////////////////////
	//---------------------------------INPUT EVT-------------------------------//
	/////////////////////////////////////////////////////////////////////////////

				//////////////////////////////
				///-----MOUSE RELEASED-----///
				//////////////////////////////

		if (event.type == sfEvtMouseButtonReleased)
		{
			//////// STATE 0///////////
			if (GameData->selectOrBuild == 0)
			{
				if (event.mouseButton.button == sfMouseLeft) //Clic gauche
				{
					SelectionStateUpdate(GameData);
				}
				if (event.mouseButton.button == sfMouseRight)
				{
					GameData->StatSelect--;
					if (GameData->StatSelect < 0)
					{
						GameData->StatSelect = 0;
					}
				}
			}
			//////// STATE 1///////////

		
			


			//////// STATE 2///////////


			//////// STATE 3///////////


			//////// STATE 4///////////


			//////// STATE 5///////////


		
			
		}
				//////////////////////////////
				///-----MOUSE Scrolled-----///
				//////////////////////////////
		if (event.type == sfEvtMouseWheelScrolled) //MOLETTE SOURI
		{

			//////// STATE 0///////////

			if (GameData->selectOrBuild == 0)
			{
				if (GameData->StatSelect == 2)
				{
					GameData->Scroll += event.mouseWheelScroll.delta * 130;

				}
				printf("Mouse = %d", GameData->Scroll);
				if (GameData->Scroll < 130 * -(GameData->TotBlocByType - 6))
				{
					GameData->Scroll = 130 * -(GameData->TotBlocByType - 6);
				}
				if (GameData->Scroll > 0)
				{
					GameData->Scroll = 0;
				}



			}
			//////// STATE 1///////////


			if (GameData->ChangeLvl == 1 && GameData->selectOrBuild != 0)
			{
				GameData->MapG.CurrentLVlBloc += event.mouseWheelScroll.delta;
				if (GameData->MapG.CurrentLVlBloc < 0)
				{
					GameData->MapG.CurrentLVlBloc = 0;
				}
				if (GameData->MapG.CurrentLVlBloc > GameData->MapG.Size.z)
				{
					GameData->MapG.CurrentLVlBloc = GameData->MapG.Size.z;
				}
				
			}
			//////// STATE 2///////////

			if (GameData->selectOrBuild == 2 && GameData->ChangeLvl != 1)
			{
				
					GameData->DecorsD.CurrentSelection += event.mouseWheelScroll.delta;
					if (GameData->DecorsD.CurrentSelection < 0)
					{
						GameData->DecorsD.CurrentSelection = 0;
					}
					if (GameData->DecorsD.CurrentSelection > GameData->DecorsD.TotDecors - 1)
					{
						GameData->DecorsD.CurrentSelection = GameData->DecorsD.TotDecors - 1;
					}
				
			

			}
			//////// STATE 3///////////


			//////// STATE 4///////////


			//////// STATE 5///////////


			if (GameData->selectOrBuild == 5 && GameData->ChangeLvl != 1)
			{
				GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].OpacityShadow += event.mouseWheelScroll.delta * 10;

				if (GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].OpacityShadow < 0)
				{
					GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].OpacityShadow = 0;
				}
				if (GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].OpacityShadow > 255)
				{
					GameData->MapG.DataCase[GameData->CurrentSelect.y][GameData->CurrentSelect.x][GameData->CurrentSelect.z].OpacityShadow = 255;
				}

			}

		}
		
			//////////////////////////////
			///-------KEY RELEASED-----///
			//////////////////////////////

		if (event.type == sfEvtKeyReleased)//Si l'évenement en cours est une touche relâchée..
		{
			if (event.key.code == sfKeyEscape)///////////////////TOUCHE ESCAPE
			{
				exit(0);
			}
			if (event.key.code == sfKeyT)///////////////////TOUCHE A
			{
				ConversionMap3D(GameData);

			}
			if (event.key.code == sfKeyC)///////////////////TOUCHE A
			{
				lectureSaveMap3D(GameData);

			}
			//////////////////////////////////////////////////////
			char released = 0;///SI UN DOUBLON DE TOUCHE RELEASED
			//////////////////////////////////////////////////////

			if (event.key.code == sfKeyA )///////////////////TOUCHE A
			{
				GameData->selectOrBuild = 0;///SELECT BLOCK
			}
			if (event.key.code == sfKeyE)///////////////////TOUCHE E
			{
				GameData->selectOrBuild = 1;///BUILD
			}
			if (event.key.code == sfKeyF)///////////////////TOUCHE F
			{
				GameData->selectOrBuild = 2;///DECORTS
			}
			if (event.key.code == sfKeyP)///////////////////TOUCHE P
			{
				GameData->selectOrBuild = 3;///PLACEMENT
			}
			if (event.key.code == sfKeyV)///////////////////TOUCHE V
			{
				GameData->selectOrBuild = 4;///VALIDE CASE
			}
			if (event.key.code == sfKeyO)///////////////////TOUCHE O
			{
				GameData->selectOrBuild = 5;///OMBRE
			}
			//////// STATE 0///////////
			



			//////// STATE 1///////////
			
			//////// STATE 2///////////

			//////// STATE 3///////////
			if (GameData->selectOrBuild == 3)
			{
				if (event.key.code == sfKeyNum1)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 1;///OMBRE
				}
				if (event.key.code == sfKeyNum2)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 2;///OMBRE
				}
				if (event.key.code == sfKeyNum3)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 3;///OMBRE
				}
				if (event.key.code == sfKeyNum4)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 4;///OMBRE
				}
				if (event.key.code == sfKeyNum5)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 5;///OMBRE
				}
				if (event.key.code == sfKeyNum6)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 6;///OMBRE
				}
				if (event.key.code == sfKeyNum7)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 7;///OMBRE
				}
				if (event.key.code == sfKeyNum8)///////////////////TOUCHE O
				{
					GameData->CurrentPLacement = 8;///OMBRE
				}
			}
			//////// STATE 4///////////

			//////// STATE 5///////////

			printf("STATE = %d\n", GameData->selectOrBuild);
			
			
		}

	}


	float speed = 1000 * GameData->TimerDT;

	sfVector2i mouse = { sfMouse_getPositionRenderWindow(GameData->window).x,sfMouse_getPositionRenderWindow(GameData->window).y };

	CurrentCaseSelect(&GameData->MapG, mouse, &GameData->CurrentSelect);

	if (sfKeyboard_isKeyPressed(sfKeyD))
	{
		GameData->Camera.x -= speed;
	}
	if (sfKeyboard_isKeyPressed(sfKeyQ))
	{
		GameData->Camera.x += speed;
	}
	if (sfKeyboard_isKeyPressed(sfKeyZ))
	{
		GameData->Camera.y += speed;
	}
	if (sfKeyboard_isKeyPressed(sfKeyS))
	{
		GameData->Camera.y -= speed;
	}
}


