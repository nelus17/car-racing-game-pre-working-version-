#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "GameView.h"
#include "GlobalVariables.h"

using namespace config_variables;

class GameController : public GameView
{
public:
	GameController();
	void movement(char keypressed);
	void moveLeft();
	void moveRight();
	char carFunctional();
	char GameOver();
	inline void gotoxy(int x, int y);
	~GameController();
};

#endif //!GAMECONTROLLER_H