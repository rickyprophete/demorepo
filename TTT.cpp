#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <ctype.h>
#include <new>
#include "TTT.h"
using namespace std;

TTT::TTT()
{
    //Intentionally blank
}

TTT::~TTT()
{
    cout << "GAME OVER" << endl;
    delete[] board;      //clearing memory from heap
    delete[] boardCopy;  //clearing memory from heap
}

void TTT::resetBoard()  ////Initialize a blank board & set currentPlayer to X
{
    for (int i = 0; i < N; i++)
    {
        board[i] = BLANK;
    }
    currentPlayer = X; //by default first player is X
}

void TTT::resetBoardCopy()  ////set boardCopy equal to board
{
    for (int i = 0; i < N; i++) {
        boardCopy[i] = board[i]; 
    }
}


char TTT::getCurrentPlayer() const  ////return current player
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

bool TTT::isSquareFree(int move) const  ////if the location to be filled is blank return true
{
    if (board[move] == BLANK) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TTT::isWinner(char p) const ////if p wins return true
{
    for (int i = 0; i < N; i = i + 3)
    {
        if (
            boardCopy[i] == p &&
            boardCopy[i + 1] == p &&
            boardCopy[i + 2] == p
           )
        {
            return true;
        }
    }
    for (int i = 0; i < N - 6; i++)
    {
        if (
            boardCopy[i] == p &&
            boardCopy[i + 3] == p &&
            boardCopy[i + 6] == p
           )
        {
            return true;
        }
    }
    if (
        boardCopy[0] == p &&
        boardCopy[4] == p &&
        boardCopy[8] == p
       )
    {
        return true;
    }
    if (
        boardCopy[2] == p &&
        boardCopy[4] == p &&
        boardCopy[6] == p
       )
    {
        return true;
    }
    return false;
}

bool TTT::isMoveValid(int move) const   ////If desired move is valid return true
{
    if (  !isBoardFull()  &&  !isWinner(X) && !isWinner(OH)  &&  (move < N && move >= 0)  &&  isSquareFree(move)  )
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

        for ( int i = 0; i < N; i++ ) 
        {
            ( i % 3 == 0 ) ? cout << '\t' : cout << "";

            cout << board[i];

            if ( i == 8 ) break;
            ( i % 3 == 2 ) ? cout << "\n\t_   _   _\n" : cout << " | ";
        }

        cout << "\n\nYour turn Player " << "(" << getCurrentPlayer() << ")" << endl;
        cout << "ENTER a MOVE between 0 - 8" << endl;
        cin  >> move;
        if ( isWinner(X) || isWinner(OH) ) break;
        while (true) 
        {
            if ( cin.fail() ) 
            {
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                displayBoard_VOID();
                cout << "ENTER a MOVE between 0 - 8" << endl;
                cin >> move;
            }
            if ( !cin.fail() ) 
            {
                break;
            }
        }
    } while ( !isMoveValid(move) );
    return move;
}

void TTT::displayBoard_VOID() const ////Only displays board
{
    system("cls");

    cout << "Tic Tac Toe UNLEASHED\n\n";

    for ( int i = 0; i < N; i++ ) 
    {
        ( i % 3 == 0 ) ? cout << '\t' : cout << "";
        cout << board[i];

        if (i == 8) break;
        ( i % 3 == 2 ) ? cout << "\n\t_   _   _\n" : cout << " | ";
    }
    cout << "\n\nYour turn Player " << "(" << getCurrentPlayer() << ")" << endl;
}

void TTT::playGame()  ////Precondition: Char array of size 9, & initial values for char currentPlayer, X, OH & BLANK
                      ////Postcondition: Updates board after each player makes a move, and checks to see if winner or tie exists
{
    do
    {
        int move;
        move = displayBoard();
        makeMove(move);
        resetBoardCopy();
        displayBoard_VOID();
        
        if ( isWinner(  getCurrentPlayer() ) )
        {
            break;
        } else if ( !isWinner ( getCurrentPlayer() ) && !isBoardFull() ) {
            switchCurrentPlayer();
        }
    } while ( !isWinner(X) && !isWinner(OH) && !isBoardFull() );

    if ( isWinner(X) || isWinner(OH) ) 
    {
        cout << "\nYou win! Congrats, Player " << getCurrentPlayer() << '!' << endl;
    }
    else
    {
        cout << "\nIt's a tie! What a game, Jim? This is one for the history books!" << endl;
    }
}

void TTT::playCompGame()
{
    do
    {
        int move;
        move = displayBoard();
        makeMove(move);
        resetBoardCopy();
        displayBoard_VOID();
        
        if ( isWinner( getCurrentPlayer() ) )
        {
            break;
        } else if ( !isWinner(getCurrentPlayer()) && !isBoardFull() ) {
            switchCurrentPlayer();
            move = cpuMove();
            makeMove(move);
            resetBoardCopy();
            displayBoard_VOID();
            if( !isWinner ( getCurrentPlayer() ) && !isBoardFull() ) switchCurrentPlayer();
        }
    } while ( !isWinner(X) && !isWinner(OH) && !isBoardFull() );

    if ( isWinner(X) || isWinner(OH) )
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
    cout << "Welcome to TIC-TAC-TOE Unleashed" << endl;
    system("pause");
}

void TTT::wait() const
{
    system("pause");
}

void TTT::showScore()   ////Update score
{
    if ( isWinner(X) || isWinner(OH) ) 
    {
        ( getCurrentPlayer() == X ) ? xWins++ : ohWins++;
    }
    else {
        ties++;
    }
    cout << "\nSCORE :\n" << endl;
    cout << "Player X: "  << xWins << "\tPlayer O: " << ohWins << endl;
    cout << "\tDraw:\t" << ties << '\n' << endl;
}

void TTT::showRules() const
{
    cout << "RULES FOR TIC-TAC-TOE\n"
         <<  "1. The game is played on a grid that's 3 squares by 3 squares.\n"
         <<  "2. You are X, your friend (or the computer) is O.\n   Players take turns putting their marks in empty squares.\n"
         <<  "3. The first player to get 3 of her marks in a row(up, down, across, or diagonally) is the winner.\n"
         <<  "4. When all 9 squares are full, the game is over.\n   If no player has 3 marks in a row, the game ends in a tie.\n";
}

int TTT::possWin(char player)
{
    int move = -1;
    for ( int i = 0; i < N; i++ ) 
    {
        resetBoardCopy();
        if ( boardCopy[i] != player && isSquareFree(i) ) 
        {
             boardCopy[i]  = player;
            if ( isWinner(player) ) {
                move = i; 
                return move;
            }else { 
                resetBoardCopy();
            }
        }
    }
    return move;
}

int TTT::cpuMove()
{   
    char cpu = getCurrentPlayer();
    int move = -1;
    if (isSquareFree(4)) {
        move = 4;        //the center square is the most valuable location
        return move;
    }

    move = possWin(cpu);

    if ( isSquareFree(move) && move != -1 ) {
        return move;
    } else if ( possWin( (cpu == X) ? OH : X ) != -1 ) {
        move  = possWin( (cpu == X) ? OH : X );
        return move;
    } else if ( isSquareFree( move = randMove() ) != -1 ) {
        return move;
    }else{
        cerr << "ERROR CODE NEEDS REFACTOR . . ."<<endl;
        system("pause");
    }
    return move;
}

int TTT::randMove()
{
    srand( time(NULL) );
    int move    = -1;
    for ( int i = 0; i < (N * N) ; i++ )
        {
        int rnum = ( rand() % (N) );
        if ( isSquareFree(rnum) ) {
            move = rnum;
            return move;
            }
        }
    return move;
}

void TTT::menu()
{
    welcome();
    resetBoard();
    char choice;
    do
    {
        system("cls");

        cout << "ENTER '" << PLAY     << "' to PLAY vs PERSON"   << endl;
        cout << "ENTER '" << PLAYCOMP << "' to PLAY vs COMPUTER" << endl;
        cout << "ENTER '" << RULES    << "' to SHOW RULES"       << endl;
        cout << "ENTER '" << QUIT     << "' to QUIT"             << endl;
        cin  >> choice;
        
        system("cls");

        switch (toupper(choice)) 
        {
        case QUIT:
            break;

        case RULES:
            system("cls");
            showRules();
            wait();
            break;

        case PLAY:
            system("cls");
            resetBoard();
            playGame();
            showScore();
            wait();
            break;

        case PLAYCOMP:
            system("cls");
            resetBoard();
            playCompGame();
            showScore();
            wait();
            break;

        default:
            cout << "INVALID INPUT" << endl;
            break;
        }
    } while (choice != QUIT);
}

