#include <iostream>
#include <string>
#include <stdlib.h> /* srand, rand */

using namespace std;

void greetings(int &x, int &y, int &nbShip)
{
    cout << "Please enter the size of the board" << endl
         << "First the width (Size_X) : " << endl;
    cin >> x;
    cout << "then the height (Size_Y)" << endl;
    cin >> y;
    cout << "And the number of ship to destroy" << endl;
    cin >> nbShip;
    cout << "The board will be " << x << "x" << y << " and there will be " << nbShip << " ship to destroy." << endl;
}

void setShip(int xlimit, int ylimit, bool **board)
{
    int ship_x = rand() % xlimit;
    int ship_y = rand() % ylimit;
    board[ship_x][ship_y] = 1;
    // spoiler
    cout << "x : " << ship_x << endl
         << "y : " << ship_y << endl;
}
void init_board(bool **board, int size_x, int size_y) // init the boolean tab with 0
{
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            board[j][i] = 0;
        }
    }
}
void draw_board(bool **board, int size_x, int size_y)
{
    for (int i = size_y; i >= 0; i--)
    {
        for (int j = 0; j < size_x; j++)
        {
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    srand((unsigned)time(0)); // srand allow to generate random number but we need to init it first
    // init var4
    int size_x, size_y, numShip;
    greetings(size_x, size_y, numShip);
    int tentative = numShip;
    bool **board = new bool *[size_x]; // we init the first row
    for (int i = 0; i < size_x; i++)
    {
        board[i] = new bool[size_y]; // then for each row we init
    }
    // init tab
    init_board(board, size_x, size_y);
    draw_board(board, size_x, size_y);
    // init ship
    while (tentative != 0)
    {
        setShip(size_x, size_y, board);
        tentative--;
    }
    draw_board(board, size_x, size_y); // spoiler
    // actual game
    int inputPlayer_x, inputPlayer_Y;
    while (numShip != 0)
    {
        cout << "Enter x : " << endl;
        cin >> inputPlayer_x;
        cout << "Enter y : " << endl;
        cin >> inputPlayer_Y;
        if (board[inputPlayer_x][inputPlayer_Y])
        {
            cout << "touché" << endl;
            board[inputPlayer_x][inputPlayer_Y] = 0;
            numShip--;
        }
        else
        {
            cout << "loupé" << endl;
        }
        tentative++;
        draw_board(board, size_x, size_y);
    }
    cout << "coulé en " << tentative << " tentatives." << endl;
}