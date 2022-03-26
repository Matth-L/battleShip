#include <iostream>
#include <stdlib.h> /* srand, rand */
using namespace std;

void greetings(int &x, int &y, int &nbShip)
{
    cout << "Please enter the size of the board" << endl
         << "First the Width (Size_X) : ";
    cin >> x;
    cout << "then the Height (Size_Y) : ";
    cin >> y;
    cout << "And the number of ship to destroy : ";
    cin >> nbShip;
    cout << "The board will be " << x << "x" << y << " and there will be " << nbShip << " ship to destroy." << endl;
}

void setShip(int xlimit, int ylimit, bool **board)
{
    int ship_x = rand() % xlimit;
    int ship_y = rand() % ylimit;
    board[ship_x][ship_y] = 1;
    // spoiler
    cout << "x : " << ship_x + 1 << endl
         << "y : " << ship_y + 1 << endl;
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
    for (int i = size_y - 1; i >= 0; i--)
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
    // init var
    int size_x, size_y, numShip;
    greetings(size_x, size_y, numShip);
    int shipNb = numShip;
    bool **board = new bool *[size_x]; // we init the first row
    for (int i = 0; i < size_x; i++)
    {
        board[i] = new bool[size_y]; // then for each row we init
    }
    // init tab
    init_board(board, size_x, size_y);
    draw_board(board, size_x, size_y);
    // init ship
    while (shipNb != 0)
    {
        setShip(size_x, size_y, board);
        shipNb--;
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
        if (board[inputPlayer_x - 1][inputPlayer_Y - 1])
        {
            cout << "touché" << endl;
            board[inputPlayer_x - 1][inputPlayer_Y - 1] = 0;
            numShip--;
        }
        else
        {
            cout << "loupé" << endl;
        }
        shipNb++;
        draw_board(board, size_x, size_y);
    }
    cout << "coulé en " << shipNb << " tentatives." << endl;
}