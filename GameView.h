#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "CarGame.h"

class GameView : public CarGame
{
public:
	GameView();
	inline void gotoxy(int x, int y);
	inline void showCar(int r);
	void showMap();
	void showObstacles(int r, int x2);
	void flickerDisabler();
	void obstacleFlickerDisabler(int r, int x2);
	void displayScore();
	~GameView();
};

#endif // !GAMEVIEW_H



