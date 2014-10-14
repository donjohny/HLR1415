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

// Die Funktion show_map soll das Array in Form einer 3x3-Matrix ausgeben
void show_map (void)
{
	//                                              TODOch(dir)
	int x;
	for (x = 0; x < 3; ++x)
	{
		printf("%-4d%-3d%2d\n", map[x][0], map[x][1], map[x][2]);
		switch(dir) {
			case N: 'N';break;
			case S: 'S';break;
			case W: 'W';break;
			case E: 'E';break;
			case N|W: "NW";break;
			case N|E: "NE";break;
			case S|W: "SW";break;
			case S|E: "SE";break;
			default: '0';
		}
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
