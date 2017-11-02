#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "CarGame.h"
#include "GameView.h"
#include "GameController.h"
#include "GlobalVariables.h"

using namespace config_variables;

int main()
{
	GameView view;
	GameController controller;
	char kbh;
	do
	{
		system("cls");
		view.showMap();                
		view.gotoxy(20, 21);                
		view.showCar(0);                   
		_getch();
		kbh = controller.carFunctional();         
	} while (kbh != 'q');

	view.gotoxy(66, 27);        
	return 0;
}