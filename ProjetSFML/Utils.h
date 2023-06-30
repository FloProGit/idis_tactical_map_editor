#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <tchar.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/OpenGL.h>
#include <SFML/Network.h>
#include <SFML/Audio.h>
#include "time.h"
#include "windows.h"
#include "math.h"


#include"GameData.h"



sfSprite* LoadSprite(char* _sNom, int _isCentered, int _oriX, int _oriY);

void blitSpriteComplex(sfSprite* _sprite, float _posX, float _posY, float _angle, float _scaleX, float _scaleY, float _R, float _G, float _B, float _alpha, sfRenderWindow* _window);

void blitSprite(sfSprite* _sprite, float _posX, float _posY, float _angle, sfRenderWindow* _window);
sfSound* LoadSound(char* _sNom);
void BlitTexte(sfText*_Text, int _x, int _y, int _Size, sfFont* _Police, sfColor Color, sfRenderWindow* _window);
void VectorDraw(sfVector2f _P0, sfVector2f _P1, sfColor _Color, sfRenderWindow* _Window);

#endif