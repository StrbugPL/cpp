//---------------------------------------//
            //Program rysuj�cy figur� M znakiem ASCII//
//---------------------------------------//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string.h>

//--------------------------------------------------------------------------------------

void idz_do_xy(int x, int y);
int gdzieJestX();
int gdzieJestY();
void myjuMyju();
void ukryj();
void menu();
void wybierz_rozmiar(int &);
void wybierz_znak(char &);
void rysuj(char ,int ,int ,int &);
void zmien_pozycje( int &, int &, int &);

//--------------------------------------------------------------------------------------

using namespace std;

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
																//----------------------
int main()														//----------------------
{																//----------------------
	char znak;													//----------------------
	int x=0, y=0, bok=15;										//----------------------
																//----------------------
	menu();                                                     //----------------------
    wybierz_rozmiar(bok);										//----------------------
	wybierz_znak(znak);											//----------------------
	rysuj(znak,x,y,bok);										//----------------------
	do {														//----------------------
																//----------------------
		zmien_pozycje(x, y,bok);							    //----------------------
		rysuj(znak, x, y, bok);									//----------------------
		//cout << x << " " << y;								----------------------
	} while (_getch() != 27);									//----------------------
																//----------------------
																//----------------------
}																//----------------------
																//----------------------
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

void wybierz_znak(char &znak) // Funkcja wybieraj�ca znak do rysowania
{
	system("cls");
	cout << "Wybierz znak, ktorym chcesz narysowac litere : ";
	cin >> znak;

}

//--------------------------------------------------------------------------------------
void wybierz_rozmiar(int &bok) // Funkcja wybieraj�ca rozmiar
{
	system("cls");
	cout << "Wybierz rozmiar, ktorym chcesz narysowac litere : ";
	cin >> bok;


}

//--------------------------------------------------------------------------------------



	void rysuj(char znak, int x, int y, int &bok) // Funkcja rysuj�ca liter�
{
    auto x1=0, y1=0;
    auto x2=0, y2=0;


    system("cls");


        idz_do_xy(x,y);


    for(int j=0; j<bok; j++){   //lewe ramie

        cout<<znak;

        idz_do_xy(x,y+j);
    };

    idz_do_xy(x,y);


    for(int i=0; i<bok/2; i++) { //lewy skos

        idz_do_xy(x+i,y+i);
        x1=x+i;
        y1=y+i;
        cout<<znak;

    }


    for(int i=0; i<bok/2; i++) {  //prawy skos

        idz_do_xy(x1+i,y1-i);
        x2=x1+i;
        y2=y1-i;
        cout<<znak;

    }

        idz_do_xy(x2,y2);

     for(int j=0; j<bok; j++){   //prawe ramie - ramie sprawiedliwosci

        cout<<znak;

        idz_do_xy(x2,y2+j);
    };




  //  idz_do_xy(x=0,y=0);


}


//---------------------------------------------------------------------------------------

void zmien_pozycje(int &x, int &y,int &bok){ // Funkcja zmieniaj�ca pozycj� litery

	ukryj();

		char znak = _getch();
		switch (znak)
		{
            znak = _getch();
			case 'w': {y--;
				break; }

			case 's': {y++;
				break; }

			case 'a': {x--;
				break; }

			case 'd': {x++;
				break; }

            case '-': {bok--;
				break; }

			case '+': {bok++;
				break; }
 		}
 }

//---------------------------------------------------------------------------------------






void idz_do_xy(int x, int y)               //przenosi kursor do okre�lonej pozycji (x, y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//---------------------------------------------------------------------------------------

int gdzieJestX()            //zwraca pozycj� kursora w osi x
{

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

//--------------------------------------------------------------------------------------

int gdzieJestY()                //zwraca pozycj� kursora w osi y
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

//--------------------------------------------------------------------------------------

void ukryj()                       //ukrywa kursor konsoli
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

//--------------------------------------------------------------------------------------

void myjuMyju()     //usowa zawarto�ci linii, na kt�rej znajduje si� kursor
{
	int x, y;
	x = gdzieJestX();
	y = gdzieJestY();
	idz_do_xy(x, y);
	for (int i = x; i <= 79; i++)
		cout << " ";
	idz_do_xy(x, y);
}

//--------------------------------------------------------------------------------------

void menu() // menu g��wne
{

	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, 0x004);

	idz_do_xy(31, 12);
	cout << "-----------------'w','s','a','d' - klawisze kierunkowe-----------------" << endl;
	idz_do_xy(31, 13);
	cout << "--- " << "Witaj w programie rysujacym litere M znakiem ASCII!" << " ---" << endl;
	idz_do_xy(31, 14);
	cout << "---------------'+' i '-' ustalanie wielkosci figury--------------------" << endl;
	idz_do_xy(38, 15);
	cout << "Aby kontunuowac, wcisnij dowolny przycisk : ";
	_getch();
}
