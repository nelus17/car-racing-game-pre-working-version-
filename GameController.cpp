#include "stdafx.h"
#include "GameController.h"
#include "GlobalVariables.h"
#include "GameView.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace config_variables;

GameController::GameController()
{
}

char GameController::carFunctional()
{
	for (;;)
	{
		int x1 = rand() % 30 + 17;
		int x2 = rand() % 28 + 17;
		if (x1 == x2)
			x1 = rand() % 31 + 17;

		for (int i = 0; i <= 23; i++)
		{
			gotoxy(x1, i);
			std::cout << ' ';
			gotoxy(x1, i + 1);
			std::cout << cash;
			if (i == 23)
			{
				gotoxy(x1, 24);
				std::cout << ' ';
			}
			obstacleFlickerDisabler(i, x2);
			Sleep(sleep);
			for (int k = -3; k <= 4; k++)
				for (int j = 0; j <= 3; j++)
					if ((x2 == n + k && i + 2 == 21 + j) || (x2 == n + k && i + 2 == 22 + j) || (x2 == n + k && i + 2 == 23 + j))
					{
						keypressed = GameOver();
						return keypressed;
					}
			obstacleFlickerDisabler(i, x2);
			if (CarCoordinates)
			{
				showCar(0);
				points = points + 5;
				break;
			}
			points++;
			displayScore();
			if (_kbhit())
			{
				keypressed = _getch();
				if (keypressed == 'a' || keypressed == 'A' || keypressed == 'D' || keypressed == 'd')
				{
					movement(keypressed);
				}
				else if (keypressed == 'Q' || keypressed == 'q')
				{
					return keypressed;
				}
				else
				{
					continue;
				}
			}
			if (points % 100 == 0)
			{
				if (sleep>25)
					sleep -= 25;
				else if (sleep>15 && sleep<25)
					sleep -= 3;
			}
		}
	}
}

void GameController::movement(char keypressed) {
	switch (keypressed)
	{
	case 'A':
	case 'a':
		moveLeft();
		break;
	case 'D':
	case 'd':
		moveRight();
		break;
	}
}

void GameController::moveLeft() {
	if (n <= maxLeftBoard);
	else
	{
		flickerDisabler();  showCar(-moveValue);
	}
}

void GameController::moveRight() {
	if (n >= maxRightBoard);
	else
	{
		flickerDisabler();  showCar(+moveValue);
	}
}

char GameController::GameOver() {
	gotoxy(26, 12);
	std::cout << "GAME OVER";
	gotoxy(23, 13);
	std::cout << "Your Score is : " << points;
	gotoxy(19, 15);
	std::cout << "Want To Play Again? Y/N: ";
	keypressed = _getche();
	if (keypressed == 'y' || keypressed == 'Y')
	{
		points;
		sleep;
		return keypressed;
	}
	else if (keypressed == 'n' || keypressed == 'N')
	{
		return 'q';
	}
	else
	{
		GameOver();
	}
}

void GameController::gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

GameController::~GameController()
{
}
