#include "stdafx.h"
#include "GameView.h"
#include "GlobalVariables.h"
#include <Windows.h>
#include <ctime>
#include <iostream>

using namespace config_variables;

GameView::GameView() {
	srand(time(0));
	cash;
	n;
	points;
	n1;
	sleep;
}

void GameView::gotoxy(int x, int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GameView::showCar(int r) {
	n = n + r;
	gotoxy(n, 22);
	std::cout << wheel,"   ", wheel;
	gotoxy(n, 23);
	std::cout << car_board," ",car_body," ",car_board;
	gotoxy(n, 24);
	std::cout << wheel,"   ",wheel;
}

void GameView::showMap() {
	for (int j = 1; j <= 3; j += 2)
		for (int i = 0; i <= 24; i++)
		{
			gotoxy(16 * j, i);
			std::cout << road_border;
		}
}

void GameView::showObstacles(int r, int x2) {
	gotoxy(x2, r);
	std::cout << part_of_obstacle << "  " << part_of_obstacle;
	gotoxy(x2, 1 + r);
	std::cout << part_of_obstacle << part_of_obstacle << part_of_obstacle << part_of_obstacle;
	gotoxy(x2, 2 + r);
	std::cout << part_of_obstacle << "  " << part_of_obstacle;
}

void GameView::flickerDisabler() {
	gotoxy(n, 22);
	std::cout << "     ";
	gotoxy(n, 23);
	std::cout << "     ";
	gotoxy(n, 24);
	std::cout << "     ";
}

void GameView::obstacleFlickerDisabler(int r, int x2) {
	gotoxy(x2, r + r);
	std::cout << "    ";
	gotoxy(x2, r + 1);
	std::cout << "    ";
	gotoxy(x2, r + 2);
	std::cout << "    ";
}

void GameView::displayScore() {
	gotoxy(50, 15);
	std::cout << "points = " << points;
}

GameView::~GameView()
{
}
