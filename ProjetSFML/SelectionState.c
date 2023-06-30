#include "SelectionState.h"
#include "stdio.h"


#include "string.h"

#include "stdlib.h"


void SelectionStateInit(struct GAMEDATA* GameData)
{
	for (int i = 0; i < 100; i++)
	{
		GameData->AllSprite[i].ID =  999 ;
	}
	GameData->Scroll = 0;
	GameData->TotBlocByType = 13;
	GameData->StatSelect = Biome;
	GameData->StateFile.BiomeSelect = 0;
	GameData->CaseBase = LoadSprite("CaseFile.png", 0, 0, 0);

	GameData->TotBiome = 2;

	GameData->BiomeList = calloc(GameData->TotBiome, sizeof(struct BIOME));



	////////BIOME CREATE///////



	//////Biome 1
	GameData->BiomeList[0].totType = 4;//conteur de sous dossier
	strcpy(GameData->BiomeList[0].NameBiome, "Basic");


	//////Biome 2
	GameData->BiomeList[0].totType = 4;//conteur de sous dossier
	GameData->BiomeList[1].totType = 4;
	strcpy(GameData->BiomeList[1].NameBiome, "Neige");

	




	for (int i = 0; i < GameData->TotBiome; i++)/////Creation des modulle dans les   biomes
	{
		GameData->BiomeList[i].TypeList = calloc(GameData->BiomeList[i].totType, sizeof(struct TYPEB));
		GameData->BiomeList[i].BiomeText = sfText_create();
		sfText_setString(GameData->BiomeList[i].BiomeText, GameData->BiomeList[i].NameBiome);
		
		strcpy(GameData->BiomeList[i].TypeList[3].NameType, "Terre");
		strcpy(GameData->BiomeList[i].TypeList[2].NameType, "Sol");

		strcpy(GameData->BiomeList[i].TypeList[1].NameType, "Mur");
		strcpy(GameData->BiomeList[i].TypeList[0].NameType, "Eau");
	}
	
	
	///////////TYPE CREATE///////////////

	//////Type 1
	
	
	int countS = 0;

	for (int i = 0; i < GameData->TotBiome; i++)
	{
		for (int j = 0; j < GameData->BiomeList[i].totType; j++)//// creation des sous dossier dans les modules
		{
			GameData->BiomeList[i].TypeList[j].totBloc = GameData->TotBlocByType;
			GameData->BiomeList[i].TypeList[j].BlocList = calloc(GameData->BiomeList[i].TypeList[j].totBloc, sizeof(struct TYPEB));
			GameData->BiomeList[i].TypeList[j].TypeText = sfText_create();
			sfText_setString(GameData->BiomeList[i].TypeList[j].TypeText, GameData->BiomeList[i].TypeList[j].NameType);
		}
	}

	for (int i = 0; i < GameData->TotBiome; i++)
	{


		for (int j = 0; j < GameData->BiomeList[i].totType; j++)
		{
			for (int k = 0; k < GameData->BiomeList[i].TypeList[j].totBloc; k++)
			{
				char IDRacine[5] = {0};
				char IDBiome[5] = { 0 };
				char IDType[5] = { 0 };
				char IDPng[5] = { 0 };

				char StringNbr[9] = { 0 };


				sprintf(IDRacine, "%d", 1);
				sprintf(IDBiome, "%d", i+1);
				sprintf(IDType, "%d", j+1);
				sprintf(IDPng, "%d", k+1);

				strcat(StringNbr, IDRacine);
				strcat(StringNbr, IDBiome);
				strcat(StringNbr, IDType);
				strcat(StringNbr, IDPng);

			



				countS++;
			

				char Chemin[100] = { "Biome/" };
		
				strcpy(GameData->BiomeList[i].TypeList[j].BlocList[k].NameBloc, StringNbr);
				//printf("%s\n", GameData->BiomeList[i].TypeList[j].BlocList[k].NameBloc);


				GameData->BiomeList[i].TypeList[j].BlocList[k].nbr = atoi(StringNbr);
				GameData->BiomeList[i].TypeList[j].BlocList[k].BlockText = sfText_create();
				sfText_setString(GameData->BiomeList[i].TypeList[j].BlocList[k].BlockText, StringNbr);

				////LOADING CASE map
				strcat(Chemin, GameData->BiomeList[i].NameBiome);

				strcat(Chemin, "/");

				strcat(Chemin, GameData->BiomeList[i].TypeList[j].NameType);
				strcat(Chemin, "/");

				strcat(Chemin, GameData->BiomeList[i].TypeList[j].BlocList[k].NameBloc);
				strcat(Chemin, ".png");

				printf("%s\n", Chemin);
				
				GameData->AllSprite[countS].ID = atoi(StringNbr);
				GameData->AllSprite[countS].sprite = LoadSprite(Chemin, 0, 0, 0);
				printf(" IDD ==%d\n", GameData->AllSprite[countS].ID);


				GameData->BiomeList[i].TypeList[j].BlocList[k].Sprite = LoadSprite(Chemin,0,0,0);
				
			}
		}
	}
	//system("pause");

}
int collisionFact(sfVector2i mouse, int _objX, int _objY, int _SizeX, int _SizeY)
{
	if (mouse.x > _objX && mouse.x <_objX + _SizeX && mouse.y > _objY && mouse.y < _objY + _SizeY)
	{
		return 1;
	}

	return 0;

}
void SelectionStateUpdate(struct GAMEDATA* GameData)
{
	sfVector2i mouse = { sfMouse_getPositionRenderWindow(GameData->window).x,sfMouse_getPositionRenderWindow(GameData->window).y };

	switch (GameData->StatSelect)
	{
	case 0:
		for (int i = 0; i < GameData->TotBiome; i++)
		{
			if (collisionFact(mouse, 0, 130 * i + GameData->Scroll, 130, 130))
			{

				printf("colllisionBiome %d\n ", i + 1);
				GameData->StatSelect = Type;
				GameData->StateFile.BiomeSelect = i;
			}
		}; break;
	case 1:
		for (int i = 0; i < GameData->BiomeList[GameData->StateFile.BiomeSelect].totType; i++)
		{
			if (collisionFact(mouse, 0, 130 * i + GameData->Scroll, 130, 130))
			{
				printf("colllisionType %d\n ", i + 1);
				GameData->StatSelect = Bloc;
				GameData->StateFile.TypeSelect = i;

			}
		}; break;
	case 2:
		for (int i = 0; i < GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[GameData->StateFile.TypeSelect].totBloc; i++)
		{
			if (collisionFact(mouse, 0, 130 * i + GameData->Scroll, 130, 130))
			{

				GameData->currentSelectBloc =atoi( GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[GameData->StateFile.TypeSelect].BlocList[i].NameBloc);

				printf("current select = %d\n ", GameData->currentSelectBloc);

			}
		};
		break;
	default:
		break;
	}







}

void SelectionStateDisplay(struct GAMEDATA* GameData)
{

	if (GameData->selectOrBuild == 0)
	{

		
	


		switch (GameData->StatSelect)
		{
		case 0:
			for (int i = 0; i < GameData->TotBiome; i++)
			{
				blitSprite(GameData->CaseBase, 0, i * 130+ GameData->Scroll, 0, GameData->window);
				BlitTexte(GameData->BiomeList[i].BiomeText, 0, 130 * i+ GameData->Scroll, 50, GameData->Font1,sfBlue, GameData->window);
			}; break;
		case 1:
			for (int i = 0; i < GameData->BiomeList[GameData->StateFile.BiomeSelect].totType; i++)
			{
				blitSprite(GameData->CaseBase, 0, i * 130+ GameData->Scroll, 0, GameData->window);
				BlitTexte(GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[i].TypeText, 0, 130 * i+ GameData->Scroll, 50, GameData->Font1, sfBlue, GameData->window);
			};
			break;
		case 2:
			for (int i = 0; i < GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[GameData->StateFile.TypeSelect].totBloc; i++)
			{
				blitSprite(GameData->CaseBase, 0, i * 130+ GameData->Scroll, 0, GameData->window);
				blitSprite(GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[GameData->StateFile.TypeSelect].BlocList[i].Sprite, 0, i * 130+ GameData->Scroll, 0, GameData->window);

				//BlitTexte(GameData->BiomeList[GameData->StateFile.BiomeSelect].TypeList[GameData->StateFile.TypeSelect].BlocList[i].BlockText, 10, 130 * i+ GameData->Scroll, 50, GameData->Font1, sfBlue, GameData->window);
			};
			break;
		default:
			break;
		}


	}







}

