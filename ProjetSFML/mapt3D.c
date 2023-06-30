#include"mapt3D.h"
#include"Utils.h"
void INITMap(D_MapG * Map)
{

	Map->CellSize.x = 128;
	Map->CellSize.y = 64;
	Map->CurrentLVlBloc = 0;

	printf("ENTRER LE NOMBRE DE LIGNE :");
	scanf("%d", &Map->Size.y);
	printf("\n");
	printf("ENTRER LE NOMBRE DE COLONE :");
	scanf("%d", &Map->Size.x);
	printf("\n");
	printf("ENTRER LA HAUTEUR DE LA MAP :");
	scanf("%d", &Map->Size.z);


	//Put_Data_On_MapCombat(Map, _saveName);
}

void Create_Empty_MapCombat_From_Data_Lvl(D_MapG* Map)
{
	Map->DataCase = 0;
	Map->DataCase = calloc(Map->Size.y, sizeof(D_DataCase**));

	for (int i = 0; i < Map->Size.y; i++)
	{
		Map->DataCase[i] = calloc(Map->Size.x, sizeof(D_DataCase*));
		for (int j = 0; j < Map->Size.x; j++)
		{
			Map->DataCase[i][j] = calloc(Map->Size.z, sizeof(D_DataCase));
		}
	}

	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			for (int k = 0; k < Map->Size.z; k++)
			{


				Map->DataCase[i][j][k].ID = 0 ;
				Map->DataCase[i][j][k].IDDecorts = 999;
				Map->DataCase[i][j][k].OpacityShadow = 255;
				Map->DataCase[i][j][k].IDShadow = 999;
				Map->DataCase[i][j][k].StateCase = NonValideCase;
			}
		}
	}
}



void VectorCase(D_MapG* Map, sfVector2f Camera)
{
	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			for (int k = 0; k < Map->Size.z; k++)
			{

				Map->DataCase[i][j][k].VectorPos[0].x = (Map->CellSize.x / 2) + Map->CellSize.x / 2 * (j - i) + Camera.x;

				Map->DataCase[i][j][k].VectorPos[0].y = (Map->CellSize.y / 2 * (j + i)) - (Map->CellSize.y / 2 * k) + Camera.y;


				Map->DataCase[i][j][k].VectorPos[1].x = Map->DataCase[i][j][k].VectorPos[0].x + Map->CellSize.x / 2;
				Map->DataCase[i][j][k].VectorPos[1].y = Map->DataCase[i][j][k].VectorPos[0].y + Map->CellSize.y / 2;

				Map->DataCase[i][j][k].VectorPos[2].x = Map->DataCase[i][j][k].VectorPos[0].x;
				Map->DataCase[i][j][k].VectorPos[2].y = Map->DataCase[i][j][k].VectorPos[0].y + Map->CellSize.y;

				Map->DataCase[i][j][k].VectorPos[3].x = Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2;
				Map->DataCase[i][j][k].VectorPos[3].y = Map->DataCase[i][j][k].VectorPos[0].y + Map->CellSize.y / 2;

				Map->DataCase[i][j][k].VectorPos[4].x = Map->DataCase[i][j][k].VectorPos[0].x;
				Map->DataCase[i][j][k].VectorPos[4].y = Map->DataCase[i][j][k].VectorPos[0].y;
			}
		}
	}
}
int CalculScalaire(sfVector2i Mouse, D_DataCase * _case)
{
	int total = 0;
	for (int k = 0; k < TOTVECTORCASE - 1; k++)
	{
		sfVector2f temp1 = { -(_case->VectorPos[k + 1].y - _case->VectorPos[k].y)  , _case->VectorPos[k + 1].x - _case->VectorPos[k].x };


		sfVector2f temp2 = { Mouse.x - _case->VectorPos[k].x, Mouse.y - _case->VectorPos[k].y };

		int result;
		result = (temp2.x*temp1.x) + (temp2.y*temp1.y);

		if (result >= 0)
		{
			total++;
		}

	}
	if (total == TOTVECTORCASE - 1)
	{
		return 1;
	}

	return 0;
}


void CurrentCaseSelect(D_MapG* Map, sfVector2i Mouse, sfVector3i * caseSelect)
{
	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{
			
				if (CalculScalaire(Mouse, &Map->DataCase[i][j][Map->CurrentLVlBloc]))
				{
					caseSelect->y = i;
					caseSelect->x = j;
					caseSelect->z = Map->CurrentLVlBloc;
				}
			
		}
	}
}
struct DECORSTRCUT DecorsD;

void MapDisplay(D_MapG* Map, sfVector3i CurrentSelect,  struct GAMEDATA* GameData, sfRenderWindow* window)
{

	


	for (int i = 0; i < Map->Size.y; i++)
	{
		for (int j = 0; j < Map->Size.x; j++)
		{

			for (int k = 0; k < Map->Size.z; k++)
			{




					
					if (Map->DataCase[i][j][k].ID != 0)
					{
						for (int s = 0; s < 100; s++)
						{
							if (GameData->AllSprite[s].ID == Map->DataCase[i][j][k].ID)
							{
								sfColor tempOp = { 255,255,255,255 };
								if (k > Map->CurrentLVlBloc)
								{
									tempOp.a = 40;
								}

							
								sfSprite_setColor(GameData->AllSprite[s].sprite, tempOp);
								blitSprite(GameData->AllSprite[s].sprite, Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->DataCase[i][j][k].VectorPos[0].y, 0, window);
							}

						}
					}
					if (Map->DataCase[i][j][k].IDShadow != 999)
					{

						sfColor tempShadow = { 255,255,255,Map->DataCase[i][j][k].OpacityShadow };

						sfSprite_setColor(GameData->ShadowMask[0], tempShadow);
						blitSprite(GameData->ShadowMask[0], Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->DataCase[i][j][k].VectorPos[0].y, 0, window);


					}

					if (Map->DataCase[i][j][k].PlacementState != 0)
					{
						blitSprite(GameData->SpritesPlacement.PlaceSprite[Map->DataCase[i][j][k].PlacementState-1], Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->DataCase[i][j][k].VectorPos[0].y, 0, window);


					}

					if (Map->DataCase[i][j][k].StateCase == ValideCase)
					{
						blitSprite(GameData->GreenCase, Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->DataCase[i][j][k].VectorPos[0].y, 0, window);


					}
					if (i == CurrentSelect.y && j == CurrentSelect.x && k == CurrentSelect.z && GameData->ScreenShot == 0)
					{
						blitSprite(
							GameData->CaseSelect,
							Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2,
							Map->DataCase[i][j][k].VectorPos[0].y,
							0,
							window
						);
					}
					

						


					for (int v = 0; v < 4; v++)
					{

						VectorDraw(Map->DataCase[i][j][Map->CurrentLVlBloc].VectorPos[v], Map->DataCase[i][j][Map->CurrentLVlBloc].VectorPos[v + 1], sfRed, window);

					}


					
					if (Map->DataCase[i][j][k].IDDecorts != 999)
					{
						blitSprite(GameData->DecorsD.SDecors[Map->DataCase[i][j][k].IDDecorts], Map->DataCase[i][j][k].VectorPos[0].x - Map->CellSize.x / 2, Map->DataCase[i][j][k].VectorPos[0].y, 0, window);
					}

				


			}
		}
	}
}