#include <iostream>
using namespace std;

char Matrix[3][3]{ '1','2','3','4','5','6','7','8','9'};
char player = 'X';


void Drow() 
{
    system("cls");
    cout << endl << endl;

    for (int i = 0; i < 3; i++) 
    {
        for (int c = 0; c < 3; c++)
        {
            cout << "\t" << Matrix[i][c];
        }
        cout << endl << endl << endl;
    }
}

void Input()
{
    char position;
    cout << "Player " << "<"<<player <<">" << ", Choose position to play in ";
    cin >> position;

    for (int i = 0; i < 3; i++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (position == Matrix[i][c]) { Matrix[i][c] = player; if (player == 'X') player = 'O'; else player = 'X'; break; }
        }
    }
}

char Lose()
{
    int isempty=0;
    int xc = 0, oc = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Matrix[i][c] != 'X' && Matrix[i][c] != 'O') { isempty++; }
            if (Matrix[i][c] == 'X') { xc++; }
            else if (Matrix[i][c] == 'O') { oc++; }

            if (xc == 3 ) 
            {
                return 'X';
            }

            else if (oc == 3)
            {
                return 'O';
            }
        }
        
    }
    xc = 0;
    oc = 0;


    for (int i = 0; i < 3; i++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (Matrix[c][i] == 'X') { xc++; }
            else if (Matrix[c][i] == 'O') { oc++; }

            if (xc == 3 )
            {
                return 'X' ;
            }

            if (oc == 3)
            {
                return 'O';
            }
        }

    }
    xc = 0;
    oc = 0;


     if (Matrix[0][0] == 'X' && Matrix[1][1] == 'X' && Matrix[2][2] == 'X') { return 'X'; }
     else if (Matrix[2][0] == 'X' && Matrix[1][1] == 'X' && Matrix[0][2] == 'X') { return 'X'; }

     else if (Matrix[0][0] == 'O' && Matrix[1][1] == 'O' && Matrix[2][2] == 'O') { return 'O'; }
     else if (Matrix[2][0] == 'O' && Matrix[1][1] == 'O' && Matrix[0][2] == 'O') { return 'O'; }

     if (isempty == 0) { return 'D'; }
     return '.';
}



int main()
{

    while(Lose()=='.')
    { 
        Drow();
        Input();
    }
    Drow();

    if(Lose() == 'X'){ cout << "Player <X> is Winer"; }
    else if (Lose() == 'O') { cout << "Player <O> is Winer"; }
    else if (Lose() == 'Z') { cout << "Draw"; }
}
