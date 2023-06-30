#include"Utils.h"

sfSprite* LoadSprite(char* _sNom, int _isCentered, int _oriX, int _oriY)//// fonction qui permet de charger un sprite
{
	sfTexture* tempTex = sfTexture_createFromFile(_sNom, NULL);
	sfSprite* tempSprite = sfSprite_create();
	sfSprite_setTexture(tempSprite, tempTex, sfTrue);
	if (_isCentered == 1)
	{
		sfVector2f tempOrigin = { sfTexture_getSize(tempTex).x / 2, sfTexture_getSize(tempTex).y / 2 };
		sfSprite_setOrigin(tempSprite, tempOrigin);
	}
	else
	{
		sfVector2f tempOrigin = { _oriX, _oriY };
		sfSprite_setOrigin(tempSprite, tempOrigin);
	}
	return tempSprite;
}
void blitSpriteComplex(sfSprite* _sprite, float _posX, float _posY, float _angle, float _scaleX, float _scaleY, float _R, float _G, float _B, float _alpha, sfRenderWindow* _window) ///// Fonction qui permet d'affiché et actualisé la position d'un sprite
{
	sfVector2f pos = { _posX, _posY };
	sfVector2f scale = { _scaleX ,_scaleY };
	sfColor color = { _R ,_G ,_B ,_alpha };
	sfSprite_setRotation(_sprite, _angle);
	sfSprite_setPosition(_sprite, pos);
	sfSprite_setColor(_sprite, color);
	sfSprite_setScale(_sprite, scale);
	sfRenderWindow_drawSprite(_window, _sprite, NULL);
}
void blitSprite(sfSprite* _sprite, float _posX, float _posY, float _angle, sfRenderWindow* _window) ///// Fonction qui permet d'affiché et actualisé la position d'un sprite
{
	sfVector2f pos = { _posX, _posY };
	sfSprite_setRotation(_sprite, _angle);
	sfSprite_setPosition(_sprite, pos);
	sfRenderWindow_drawSprite(_window, _sprite, NULL);
}
sfSound* LoadSound(char* _sNom)
{
	sfSoundBuffer* tempBuffer = 0;
	sfSound* tempSound = 0;
	//Initialisation et chargement du son
	tempBuffer = sfSoundBuffer_createFromFile(_sNom); //Chargement des données du son
	tempSound = sfSound_create(); //création du son
	sfSound_setBuffer(tempSound, tempBuffer); //Assignation des données du fichier au son

	return tempSound;
}
void BlitTexte(sfText*_Text,int _x,int _y,int _Size,sfFont* _Police,sfColor Color, sfRenderWindow* _window)
{
	sfVector2f tempPos = { _x,_y };
	sfText_setPosition(_Text, tempPos);
	sfText_setColor(_Text, Color);
	sfText_setCharacterSize(_Text,_Size);
	sfText_setFont(_Text,_Police);
	sfRenderWindow_drawText(_window, _Text, NULL);
};
void VectorDraw(sfVector2f _P0, sfVector2f _P1, sfColor _Color, sfRenderWindow* _Window)
{

	sfVertex VecticeTemp[2];

	VecticeTemp[0].color = _Color;
	VecticeTemp[0].position.x = _P0.x;
	VecticeTemp[0].position.y = _P0.y;

	VecticeTemp[1].color = _Color;
	VecticeTemp[1].position.x = _P1.x;
	VecticeTemp[1].position.y = _P1.y;
	sfRenderWindow_drawPrimitives(_Window, VecticeTemp, 2, sfLines, NULL);


}