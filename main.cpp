#include <iostream>
#include <time.h>
#include <conio.h>

using namespace std;

//prototypy
char** create_area(int x, int y, int z, int c);
char** action(char** plansza, int& z, int& c, int& n, int& m, int& ilosc);
void show_area(char** plansza, int x, int y, int& n, int& m);
void create_item(int& n, int& m, int& ilosc);

//Mapa
const int x = 10;
const int y = 10;

//Pozycja postaci
static int z = 4;
static int c = 4;

//Pozycja itemu
static int n;
static int m;
static int ilosc;

//Cele gry
static int pkt = 0;

int main()
{
	char** plansza = create_area(x, y, z, c);
	if (ilosc == 0)
		create_item(n, m, ilosc);
	do
	{
		system("cls");
		cout << "Item:  x- " << m << " " << "y- " << n << endl;
		cout << "Postac x- " << c << " " << "y- " << z << endl;
		cout << "Punkty: " << pkt << endl;
		show_area(plansza, x, y, n, m);
		action(plansza, z, c, n, m, ilosc);
	} while (true);
	return 0;
}


//ruszanie sie
char** action(char** plansza, int& z, int& c, int& n, int& m, int& ilosc)
{
	int klawisz;
	klawisz = _getch();
	switch (klawisz)
	{
	case 72:	//gora
	{
		plansza[z][c] = '.';
		plansza[z - 1][c] = '@';
		z -= 1;
		if (z == n && c == m)
		{
			pkt += 1;
			plansza[z][c] = '@';
			plansza[z - 1][c] = '.';
			create_item(n, m, ilosc);
		}
		break;
	}
	case 80:	//dol
	{
		plansza[z][c] = '.';
		plansza[z + 1][c] = '@';
		z += 1;
		if (z == n && c == m)
		{
			pkt += 1;
			plansza[z][c] = '@';
			plansza[z + 1][c] = '.';
			create_item(n, m, ilosc);
		}
		break;
	}
	case 75:	//lewo
	{
		plansza[z][c] = '.';
		plansza[z][c - 1] = '@';
		c -= 1;
		if (z == n && c == m)
		{
			pkt += 1;
			plansza[z][c] = '@';
			plansza[z][c - 1] = '.';
			create_item(n, m, ilosc);
		}
		break;
	}
	case 77:	//prawo
	{
		plansza[z][c] = '.';
		plansza[z][c + 1] = '@';
		c += 1;
		if (z == n && c == m)
		{
			pkt += 1;
			plansza[z][c] = '@';
			plansza[z][c + 1] = '.';
			create_item(n, m, ilosc);
		}
		break;
	}
	}

	return plansza;
}


//Stworzenia Planszy
char** create_area(int x, int y, int z, int c)
{
	char** tablica = new char* [x];

	for (int i = 0; i < x; i++)
	{
		tablica[i] = new char[y];
		for (int j = 0; j < y; j++)
			tablica[i][j] = '.';
	}

	tablica[z][c] = '@';

	return tablica;
}


//Wyswietlenie obrazu
void show_area(char** plansza, int x, int y, int& n, int& m)
{
	plansza[n][m] = '$';
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cout << plansza[i][j] << " ";
		cout << endl;
	}

}

//Stworzenie Itemu
void create_item(int& n, int& m, int& ilosc)
{
	srand(time(NULL));
	n = rand() % 7 + 1;
	m = rand() % 7 + 1;
	ilosc += 1;
}
