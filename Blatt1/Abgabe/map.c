#include <stdio.h>

// Definieren Sie ein enum cardd
enum cardd
{
	N=12,E=10,S=3,W=5
};
typedef enum cardd cardd;

/*
1111=15=Error
1100=12=N
0011= 3=S
1010=10=E
0101= 5=W
1110=14=NE
1101=13=NW
1011=11=SE
0111= 7=SW
*/

// Definieren Sie ein 3x3-Array namens map, das Werte vom Typ cardd enthält
static enum cardd map[3][3];

// Die Funktion set_dir soll an Position x, y den Wert dir in das Array map eintragen
// Überprüfen Sie x und y um mögliche Arrayüberläufe zu verhindern
// Überprüfen Sie außerdem dir auf Gültigkeit
void set_dir (int x, int y, cardd dir)
{
	//Test auf Arrayüberläufe
	if (0 <= x && x <= 2 && 0 <= y && y <= 2)
	{
		//Test auf Gültigkeit von dir
		if (dir == 3 || dir == 5 || dir == 7 || 10 <= dir && dir < 15)
		{
			map[x][y] = dir;
		}
	} else {
		printf("Out of Bounds: [%d][%d]\n", x, y);
	}
}

char * s;

char * long_dir(cardd dir)
{
	switch(dir) {
		case N: s = "N";break;
		case S: s = "S";break;
		case W: s = "W";break;
		case E: s = "E";break;
		case N|W: s = "NW";break;
		case N|E: s = "NE";break;
		case S|W: s = "SW";break;
		case S|E: s = "SE";break;
		default: s = "0";
	}
	return s;
}

// Die Funktion show_map soll das Array in Form einer 3x3-Matrix ausgeben
void show_map (void)
{
	//                                              TODOch(dir)
	int x;
	for (x = 0; x < 3; ++x)
	{
		printf("%-4s%-3s%2s\n", long_dir(map[x][0]), long_dir(map[x][1]), long_dir(map[x][2]));
		// printf("%-4s%-3s%2s\n", "NW", "N", "NE");
		// printf("%-4s%-3s%2s\n", "W", "0", "E");
		// printf("%-4s%-3s%2s\n", "SW", "S", "SE");
		// long_dir(map[x][0]);
	}
}

int main (void)
{
	// In dieser Funktion darf nichts verändert werden!
	set_dir(0, 1, N);
	set_dir(1, 0, W);
	set_dir(1, 4, W);
	set_dir(1, 2, E);
	set_dir(2, 1, S);

	set_dir(0, 0, N|W);
	set_dir(0, 2, N|E);
	set_dir(0, 2, N|S);
	set_dir(2, 0, S|W);
	set_dir(2, 2, S|E);
	set_dir(2, 2, E|W);

	show_map();

	return 0;
}
