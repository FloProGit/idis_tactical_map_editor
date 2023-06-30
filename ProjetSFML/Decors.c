#include"Decors.h"






void LoadSpriteDecor(struct DECORSTRCUT* Decors)
{
	char temp_string[50] = { 0 };
	Decors->TotDecors = 51;

	Decors->DecortList[0].Origin.x = 40;
	Decors->DecortList[0].Origin.y = 160;

	Decors->DecortList[1].Origin.x = 5;
	Decors->DecortList[1].Origin.y = 232;

	Decors->DecortList[2].Origin.x = 0;
	Decors->DecortList[2].Origin.y = 232;

	Decors->DecortList[3].Origin.x = 60;
	Decors->DecortList[3].Origin.y = 200;

	Decors->DecortList[4].Origin.x = 40;
	Decors->DecortList[4].Origin.y = 220;

	Decors->DecortList[5].Origin.x = -40;
	Decors->DecortList[5].Origin.y = 0;

	Decors->DecortList[6].Origin.x = -30;
	Decors->DecortList[6].Origin.y = 0;

	Decors->DecortList[7].Origin.x = -30;
	Decors->DecortList[7].Origin.y = 0;

	Decors->DecortList[8].Origin.x = -50;
	Decors->DecortList[8].Origin.y = 0;

	for (int i = 9; i <= 50; i++)
	{
		Decors->DecortList[i].Origin.x = 0;
		Decors->DecortList[i].Origin.y = 68;
	}

	Decors->DecortList[35].Origin.x = 60;
	Decors->DecortList[35].Origin.y = 190;
	Decors->DecortList[36].Origin.x = 60;
	Decors->DecortList[36].Origin.y = 190;

	for (int i = 0; i < Decors->TotDecors; i++)
	{
		sprintf(temp_string, "Decors/%d.png", i);
		Decors->SDecors[i] = LoadSprite(temp_string, 0, Decors->DecortList[i].Origin.x, Decors->DecortList[i].Origin.y);
	}
}






