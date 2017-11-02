#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H
#include <Windows.h>

#define CarCoordinates (x1==n && i==21) || (x1==n && i==22) || (x1==n && i==23) || (x1==n+1 && i==21) || (x1==n+1 && i==22) || (x1==n+1 && i==23) || (x1==n+2 && i==21) || (x1==n+2 && i==22) || (x1==n+2 && i==23) || (x1==n+3 && i==21) || (x1==n+3 && i==22) || (x1==n+3 && i==23) || (x1==n+4 && i==21) || (x1==n+4 && i==22) || (x1==n+4 && i==23)
#define road_border char(178)
#define part_of_obstacle char(219)
#define  cash  '$'
#define wheel  '@'
#define car_board  '|'
#define car_body  'X'
#define moveValue  2
#define maxLeftBoard  17
#define maxRightBoard  42
#define increase_point_value  5

COORD coord = { 0,0 };

namespace config_variables {

	extern int keypressed;
	int sleep = 175;
    int points = 0;
	int  n = 27;
	int n1 = 0;
}

#endif //!GLOBALVARIABLES_H

