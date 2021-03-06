#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define SIZE 100
#define DUVAR 0
#define YOL 1
#define YOL2 2
#define GIRIS 3
#define CIKIS 4
#define ALTIN 5
#define CANAVAR 6
#define CIKMAZ 9


using namespace std;
void degerAta( int row);
void writeMaze(int row);
void olustur(int r, int c,  int row);
void gotoXY(int x, int y);
void hareket(int);
void charyaz();
void kursoruGizle();
void Ekleme(int row);
void writeMatris( int);
void cikisBul(int x, int y, int row);


int gidilenYollarX[1000], gidilenYollarY[1000];
int adim = 0;
int m = 0, n = 0;
int matris[SIZE][SIZE];
char giris;
int puan = 0;

int main()
{
	int boyut;
	char secim;
	kursoruGizle();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


	while (1)
	{
		cout << "\n\n\t       MENU\n\t--------------------\n";
		cout << " \t1-Labirent olustur\n \t2-Oyun Hakkinda\n \t3-Exit\n\t  Seciminiz <1,2,3> ";	cin >> secim;
		if (secim == '1')
		{
			system("cls");

			cout << "\n\n\tBoyutu giriniz: ";  cin >> boyut;
			system("cls");
			
			degerAta( boyut);
			

		
			cikisBul(1, 1, boyut);
			Ekleme(boyut);
			writeMatris(boyut);

			_getch();
			system("cls;");
			
			writeMaze( boyut);
			hareket(boyut);

			/*cout << "\nGIDILEN YOLLAR\n---------------\n";
			for (int i = 0; i < adim; i++)
			{
				cout << "[" << gidilenYollarX[i] << "][" << gidilenYollarY[i] << "]  ";
			}
			m = 0; 	n = 0;
			for (int i = 0; i < adim; i++)
			{
				gidilenYollarX[i] = '\0';
				gidilenYollarY[i] = '\0';
			}
			*/


			gotoXY(0, boyut + 4);
			cout << "\tMenuye donmek icin herhangi bir tusa basiniz..." << endl;	 _getch();
			system("cls");
			adim = 0;
		}
		else if (secim == '3')
		{
			system("cls");		cout << "\n\n\tHazirlayan: Ismail KILIC - 152120171049";
			_getch();	exit(0);
		}
		else if (secim == '2')
		{
			system("cls");
			cout << "\n\n\n";
			cout << char(232) << " Labirentin boyutu tek sayi olmalidir\n";
			cout << char(232) << " w-a-s-d tuslari ile karakteri hareket ettirebilirsiniz\n";
			cout << char(232) << " Kirmizi renkli karakter canavardir, canavara yem olmamaya calisin\n";
			cout << char(232) << " Eger labirenti cozemezseniz 'q' tusuna basarak menuye donebilirsiniz\n";
			_getch();
			system("cls");
		}
		else
			system("cls");

	}
	system("pause");
}
void Ekleme(int row)
{
	int altin = row / 2;
	int canavar = row / 6;

	int altinx, altiny;
	int canavarx, canavary;

	for (int i = 0; i < altin; i++)
	{
		altinx = rand() % (row - 1) + 1;
		altiny = rand() % (row - 1) + 1;
		if (altinx % 2 == 1)
			altinx++;

		if (matris[altinx][altiny] == YOL || matris[altinx][altiny] == YOL2)
		{
			matris[altinx][altiny] = ALTIN;

		}
		else
			i--;
	}
	for (int i = 0; i < canavar; i++)
	{
		canavarx = rand() % (row - 1) + 1;
		canavary = rand() % (row - 1) + 1;
		if (canavarx % 2 == 1)
			canavarx++;

		if (matris[canavarx][canavary] == YOL)
		{
			matris[canavarx][canavary] = CANAVAR;
		}
		else
			i--;
	}
}


void degerAta( int row)
{
	srand(time(NULL));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			matris[i][j] = DUVAR;
		}
		matris[0][1] = GIRIS;

		if (row % 2 == 1)
			matris[row - 1][row - 2] = CIKIS;

		else
		{
			matris[row - 2][row - 3] = YOL;
			matris[row - 1][row - 3] = CIKIS;

		}

	}
	int r = 1;
	int c = 1;
	
	olustur(r, c,  row);
	
}
void kursoruGizle()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void charyaz()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << char(207);
	cout << char(32);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}
void hareket(int row)
{
	int x = 2, y = 1;
	int xCln = 2, yCln = 1;


	while (1)
	{
		gotoXY(row * 2 + 5, row / 2);
		cout << "Adim: " << adim;
		gotoXY(row * 2 + 5, row / 2 + 2);
		cout << "Puan: " << puan;

		gotoXY(xCln, yCln);
		cout << " ";

		gotoXY(x, y);
		charyaz();

		giris = _getch();
		xCln = x;
		yCln = y;


		if (giris == 'w' || giris == 'W')
		{
			y = y - 1;
		}
		else if (giris == 's' || giris == 'S')
		{
			y = y + 1;
		}
		else if (giris == 'a' || giris == 'A')
		{
			x = x - 2;
		}
		else if (giris == 'd' || giris == 'D')
		{
			x = x + 2;
		}
		else if (giris == 'q' || giris == 'Q')
		{
			break;
		}
		if (matris[y][x / 2] == YOL || matris[y][x / 2] == ALTIN || matris[y][x / 2] == CANAVAR || matris[y][x / 2] == YOL2)
		{
			adim++;
		}
		if (matris[y][x / 2] == DUVAR || (matris[y][x / 2] == GIRIS))
		{
			x = xCln;
			y = yCln;
		}
		else if (matris[y][x / 2] == ALTIN)
		{
			puan++;
			matris[y][x / 2] = YOL;
		}
		else if (matris[y][x / 2] == CANAVAR)
		{
			gotoXY(0, row);
			cout << "\tCanavara yem oldunuz...";				puan = 0;
		}

		else if (matris[y][x / 2] == CIKIS)
		{
			gotoXY(0, row + 2),
				cout << "\tTebrikler " << adim + 1 << " adimda cikisa ulastiniz!!!\n\tTopladiginiz Altin: " << puan << endl;					puan = 0;

		}
		if (matris[y][x / 2] == YOL || matris[y][x / 2] == ALTIN || matris[y][x / 2] == CIKIS || matris[y][x / 2] == CANAVAR)
		{
			gidilenYollarX[m] = y;
			gidilenYollarY[n] = x / 2;
			m++;	n++;

			if (matris[y][x / 2] == CANAVAR)
				break;
			else if (matris[y][x / 2] == CIKIS)
				break;
		}

	}
}
void cikisBul(int x, int y, int row)
{
	int i;
	matris[x][y] = YOL2;

	do
	{

		if (((matris[x][y - 1]) != YOL) && ((matris[x][y + 1]) != YOL) && ((matris[x - 1][y]) != YOL) && ((matris[x + 1][y]) != YOL))
		{

			matris[x][y] = 9;


			if ((matris[x][y - 1]) == YOL2)
			{
				y = y - 1;
				matris[x][y] = 9;
			}
			else if ((matris[x + 1][y]) == YOL2)
			{
				x = x + 1;
				matris[x][y] = 9;
			}
			else if ((matris[x][y + 1]) == YOL2)
			{
				y = y + 1;
				matris[x][y] = 9;
			}
			else if ((matris[x - 1][y]) == YOL2)
			{
				x = x - 1;
				matris[x][y] = 9;
			}
		}
		else
		{
			if (matris[x][y] == 9)
				matris[x][y] = YOL2;

			if ((matris[x][y - 1]) == YOL)
			{
				y = y - 1;
				matris[x][y] = YOL2;
			}
			else if ((matris[x + 1][y]) == YOL)
			{
				x = x + 1;
				matris[x][y] = YOL2;
			}
			else if ((matris[x][y + 1]) == YOL)
			{
				y = y + 1;
				matris[x][y] = YOL2;
			}
			else if ((matris[x - 1][y]) == YOL)
			{
				x = x - 1;
				matris[x][y] = YOL2;
			}

		}
	} while (x + y != ((row - 2) * 2));



}


void writeMatris( int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (matris[i][j] == YOL || matris[i][j] == CIKMAZ || matris[i][j] == YOL2)
				cout << char(32) << char(32);
			else
			cout << matris[i][j] << " ";
		}

		cout << endl;
	}
}
void writeMaze( int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (matris[i][j] == YOL || matris[i][j] == YOL2 || matris[i][j] == CIKMAZ)
				cout << char(32) << char(32);

			else if (matris[i][j] == DUVAR)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << char(219);
				cout << char(219);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


			}
			else if (matris[i][j] == GIRIS)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << char(219);

				cout << char(219);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			else if (matris[i][j] == CIKIS)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				cout << char(219);

				cout << char(219);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			else if (matris[i][j] == ALTIN)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << char(21);
				cout << char(32);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			}
			else if (matris[i][j] == CANAVAR)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << char(245);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << char(32);
			}

		}
		cout << endl;
	}
}
void olustur(int r, int c,  int row)
{
	int randYon[4], a;
	for (int i = 0; i < 4; i++)
	{
		a = rand() % 4 + 1;
		randYon[i] = a;
		if (i != 0)
		{
			for (int j = 0; j < i; j++)
			{
				if (a == randYon[j])
				{
					i = i - 1;
					break;
				}
			}
		}
	}
	for (int i = 0; i <= row; i++) {
		switch (randYon[i]) {

		case 1:
			if (r - 2 <= 0)
				continue;
			if (matris[r - 2][c] != YOL) {
				matris[r - 2][c] = YOL;
				matris[r - 1][c] = YOL;
				olustur(r - 2, c,  row);
			}
			break;
		case 2:

			if (c + 2 >= row - 1)
				continue;
			if (matris[r][c + 2] != YOL) {
				matris[r][c + 2] = YOL;
				matris[r][c + 1] = YOL;
				olustur(r, c + 2,  row);
			}
			break;
		case 3:
			if (r + 2 >= row - 1)
				continue;
			if (matris[r + 2][c] != YOL) {
				matris[r + 2][c] = YOL;
				matris[r + 1][c] = YOL;
				olustur(r + 2, c, row);
			}
			break;
		case 4:
			if (c - 2 <= 0)
				continue;
			if (matris[r][c - 2] != YOL) {
				matris[r][c - 2] = YOL;
				matris[r][c - 1] = YOL;
				olustur(r, c - 2,  row);
			}
			break;
		}
	}
}