#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>


using namespace std;

enum Direction { Top = 1, Down, Right, Left };
struct map{int map_width,map_height,fruitx,fruity;};
struct snack { int headx, heady, tail_length; Direction dir; };
struct player {int score;bool lose;};
map m; snack s; player p;

void Setup()
{
	m.map_height = 20;
	m.map_width = 45;
	
	s.headx = m.map_width/2;
	s.heady = m.map_height/2 ;
	s.tail_length = 0;

	p.score = 0;
	p.lose = false;
}

void MakeFruit()
{
	srand(time(NULL));
	m.fruitx = rand() % (m.map_width - 2) + 1;
	m.fruity = rand() % (m.map_height - 2) + 1;
}

void Drow_map()
{
	system("cls");
	for (int i = 0; i < m.map_height; i++)
	{
		for (int c = 0; c < m.map_width; c++)
		{
			if (i == 0 || i == m.map_height - 1) { cout << "."; }
			else if (c == 0 || c == m.map_width-1) { cout << "."; }
			else if (c == s.headx && i == s.heady) { cout << "^"; }
			else if (i == m.fruity && c == m.fruitx) {cout << "$"; }
			else if (s.headx == m.fruitx && s.heady == m.fruity) { MakeFruit(); p.score += 1; }
			else if (s.headx <= 0 || s.headx >= m.map_width) { p.lose = true; }
			else if (s.heady <= 0 || s.heady >= m.map_height) { p.lose = true; }

			else cout << " ";
		}
		cout << endl;

	}
	cout << "Your score =" << p.score << endl;
}

void Input() 
{
	if ( _kbhit() )
	{
		char c = _getch();
		switch (c)
		{
		case'w':s.dir = Top; break;
		case's':s.dir = Down; break;
		case'd':s.dir = Right; break;
		case'a':s.dir = Left; break;
		case'x':exit(0); break;

		}
	}
}

void Moving()
{
	switch (s.dir)
	{
	case Top:s.heady--; break;
	case Down:s.heady++; break;
	case Right:s.headx++; break;
	case Left:s.headx--; break;
			
	}
}

void sheft_right(int arr[],int size)
{
	for (int z = size - 2; z >= 0; z--)
	{
		arr[z + 1] = arr[z];
	}
}

int main()
{
   Setup();
   MakeFruit();
   while (!p.lose)
   {
	   Drow_map();
	   
	   Input();
	   Moving();
	   Sleep(100);
   }

   system("cls");
   cout <<"\t" << "Your Score = " << p.score << "\t\t" << "Game Over Dude" << endl << endl;

   system("pause");
}