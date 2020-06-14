#include <iostream>
#include <conio.h>
#include <limits>
#include "TTT.h"
using namespace std;

TTT::TTT()
{
    //Intentionally blank
}

TTT::~TTT()
{
    cout << "GAME OVER" << endl;
}

void TTT::resetBoard()  ////Initialize a blank board
{
    for (int i = 0; i < N; i++)
    {
        board[i] = BLANK;
    }
    currentPlayer = X;
}

char TTT::getCurrentPlayer() const  ////returns current player
{
    return currentPlayer;
}

void TTT::makeMove(int move)    ////Used in playGame to fill desired location in board array
{
    board[move] = getCurrentPlayer();
}

void TTT::switchCurrentPlayer() ////Used in playGame to switch the current player
{
    (currentPlayer == X) ? currentPlayer = OH : currentPlayer = X;
}

bool TTT::isBoardFull() const   ////if any spaces in board array are blank return false
{
    for (int i = 0; i < N; i++) 
    {
        if (board[i] == BLANK) {
            return false;
        }
    }
    return true;
}

bool TTT::isSquareFree(int move) const  ////if the square user is attempting to fill is blank return true
{
    if (board[move - 1] != BLANK) 
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool TTT::hasWinner() const ////if winner exists return true
{
    for (int i = 0; i < N; i = i + 3) 
    {
        if (    board[i] == getCurrentPlayer() &&
                board[i + 1] == getCurrentPlayer() &&
                board[i + 2] == getCurrentPlayer()  ) 
        {
            return true;
        }
    }
    for (int i = 0; i < N - 6; i++) 
    {
        if (    board[i] == getCurrentPlayer() &&
                board[i + 3] == getCurrentPlayer() &&
                board[i + 6] == getCurrentPlayer()    ) 
        {
            return true;
        }
    }
    if (    board[0] == getCurrentPlayer() &&
            board[4] == getCurrentPlayer() &&
            board[8] == getCurrentPlayer()  ) 
    {
        return true;
    }
    if (    board[2] == getCurrentPlayer() &&
            board[4] == getCurrentPlayer() &&
            board[6] == getCurrentPlayer()  ) 
    {
        return true;
    }
    return false;
}

bool TTT::isMoveValid(int move) const   ////If the board is not full & desired move is legal return true
{
    if (  !isBoardFull()  &&  !hasWinner()  &&  (move <= N && move > 0)  &&  isSquareFree(move)  )
    {
        return true;
    }
    else 
    {
        return false;
    }
   
}

int TTT::displayBoard() const   ////returns a valid move as integer and displays board
{
    int move;
    do
    {
        system("cls");

        cout << "Tic Tac Toe UNLEASHED\n\n";

        for (int i = 0; i < N; i++) 
        {
            (i % 3 == 0) ? cout << '\t' : cout << "";
            cout << board[i];

            if (i == 8) break;
            (i % 3 == 2) ? cout << "\n\t_   _   _\n" : cout << " | ";
        }

        cout << "\n\nYour turn Player " << "(" << getCurrentPlayer() << ")" << endl;
        cout << "ENTER a MOVE" << endl;
        cin >> move;

        while (true) 
        {
            if (cin.fail()) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                displayBoard_VOID();
                cout << "ENTER a MOVE" << endl;
                cin >> move;
            }
            if (!cin.fail()) 
            {
                break;
            }
        }
    } while (!isMoveValid(move));
    return move;
}

void TTT::displayBoard_VOID() const ////displays board without returning anything
{
    system("cls");

    cout << "Tic Tac Toe UNLEASHED\n\n";

    for (int i = 0; i < N; i++) 
    {
        (i % 3 == 0) ? cout << '\t' : cout << "";
        cout << board[i];

        if (i == 8) break;
        (i % 3 == 2) ? cout << "\n\t_   _   _\n" : cout << " | ";
    }
    cout << "\n\nYour turn Player " << "(" << getCurrentPlayer() << ")" << endl;
}

void TTT::playGame()  ////Precondition: Char array of size 9, & initial values for char currentPlayer, X, OH & BLANK
                      ////Postcondition: Updates board after each player makes a move, and checks to see if winner or tie exists
{
    resetBoard();
    do
    {
        int move;
        move = displayBoard();
        move --;
        makeMove(move);

        if (hasWinner() || isBoardFull()) 
        {
            displayBoard_VOID();
            break;
        }
        switchCurrentPlayer();
    } while (!hasWinner() && !isBoardFull());

    if (hasWinner()) 
    {
        cout << "\nYou win! Congrats, Player " << getCurrentPlayer() << '!' << endl;
    }
    else
    {
        cout << "\nIt's a tie! What a game, Jim? This is one for the history books!" << endl;
    }
}

void TTT::welcome() const
{
    system("cls");

    cout << "Welcome To TIC-TAC-TOE Unleashed" << endl;
    cout << "PRESS ANY KEY TO START" << endl;

    while (!_kbhit());
    _getch();
}

void TTT::wait() const
{
    cout << "PRESS ANY KEY TO CONTINUE" << endl;

    while (!_kbhit());
    _getch();
}

void TTT::showScore()   ////Update score
{
    if (hasWinner()) 
    {
        (getCurrentPlayer() == X) ? xWins++ : ohWins++;
    }
    cout << "\nSCORE :\n" << endl;
    cout << "Player X: " << xWins << "\tPlayer O: " << ohWins << endl;
}

void TTT::menu()
{
    welcome();
    char choice;
    do
    {
        system("cls");

        cout << "ENTER 'P' to PLAY" << endl;
        cout << "ENTER 'Q' to QUIT" << endl;
        cin >> choice;

        system("cls");

        switch (choice) 
        {
        case QUIT:
            cout << "Thank you for playing! Goodbye." << endl;
            break;

        case PLAY:
            system("cls");
            playGame();
            showScore();
            wait();
            break;

        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    } while (choice != QUIT);
}



